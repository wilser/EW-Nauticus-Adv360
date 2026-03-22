# Claude Working Notes — ZMK Dead Ends and Hard-Won Lessons

_Written to save future Claude instances from re-discovering these blind alleys._

---

## QU Key: Getting "Qu" (mixed case) on the NGM Layer

**Files:** [combos_macros_for_holds.dtsi](macros/combos_macros_for_holds.dtsi) · [layer_0_NGM.dtsi](layers/layer_0_NGM.dtsi) · [combos.dtsi](combos.dtsi)

### What works (final state)

| Gesture | Output | How |
|---|---|---|
| tap QU | "qu" | `ht_qu_QU` → `m_lcase_qu` |
| hold QU | "q" | `ht_qu_QU` hold → `kp Q` |
| shift + tap QU | "QU" | ZMK limitation — cannot suppress physical shift in a macro |
| P + QU chord | **"Qu"** ✓ | `combo_qu_mixcase` → `m_mixcase_Qu` (no shift held = works cleanly) |

### Why the combo works when shift+tap can't

The combo fires `m_mixcase_Qu` (`kp LS(Q)` + `kp U`) with **no physical shift held**.
`LS(Q)` explicitly adds shift for Q → "Q", then U fires with nothing held → "u". Done.

Shift+tap fails because the physical shift key is held by the user and ZMK provides
no reliable way to suppress it from inside a macro (see failed attempts below).

### Why the CAP layer works fine

`L_CAP` uses `ht_QU_Q` (tap = `m_ucase_QU`: `kp LS(Q)` + `kp LS(U)` → "QU").
No suppression needed — both characters are explicitly shifted. Easy.
The NGM problem is specifically needing the U to be _un_-shifted while shift is held.

---

## Failed Attempts

### Attempt 1 — mod-morph + `hold-preferred` flavor

```
ht_qu_QU (hold=kp, tap=mm_qu_Qu)
  mm_qu_Qu: no-shift→m_lcase_qu, shift→m_mixcase_Qu, keep-mods=LSFT|RSFT
  m_mixcase_Qu: kp LS(Q), macro_release LSHIFT, macro_pause_for_release, kp U
```

**Result:** shift+tap → "Q" (just Q, no u)

**Why:** `hold-preferred` flavor resolves to hold when another key is active. Holding
shift while tapping the QU key is enough to trigger the hold side (`kp Q`), which with
shift held outputs "Q". The tap path is never reached.

---

### Attempt 2a — `tap-preferred` + combined `macro_release` syntax

Changed flavor to `tap-preferred`. Changed the macro_release to:

```dts
<&macro_release &kp LSHIFT &kp RSHIFT>
```

**Result:** shift+tap → no output at all.

**Why:** Combining two `&kp` refs in a single phandle-array cell is likely invalid ZMK
syntax, or causes ZMK to return an error that aborts the remaining macro steps before
any key is sent.

---

### Attempt 2b — `tap-preferred` + no `keep-mods` + simple macro

Removed `keep-mods` from `mm_qu_Qu`. Simplified `m_mixcase_Qu` to:

```dts
bindings = <&kp LS(Q)>, <&kp U>;
```

**Result:** shift+tap → "QU" (both caps)

**Why:** ZMK macros execute **asynchronously** via a work queue. The mod-morph's
shift-masking (its "no keep-mods" suppression) is **synchronous** — the mask is set,
the macro binding is invoked (which just queues work), and the mask is immediately
cleared. By the time the macro steps actually run, physical shift is fully active
again. So `kp U` fires with shift held → "U".

---

### Attempt 3 — `keep-mods` restored + separate `macro_release` steps

```dts
bindings =
    <&kp LS(Q)>
  , <&macro_release &kp LSHIFT>
  , <&kp U>
;
```

**Result:** shift+tap → "Q" only, no u.

**Why:** `macro_release` on a **physically-held** key (one the macro did not itself press)
appears to cause ZMK to abort remaining macro steps. The `released` callback for `kp`
likely returns an error when called for a key owned by the physical keyboard behavior.
ZMK's `behavior_macro.c` stops processing on that error. Q fires (from `kp LS(Q)`
completing first), then `macro_release LSHIFT` errors → macro aborts → U never fires.

---

## Core ZMK Limitation

> **You cannot suppress a physically-held modifier from inside a ZMK macro.**

Do not re-attempt any of the above without a ZMK version that explicitly addresses this.

- `macro_release` on a physical key aborts subsequent macro steps
- mod-morph masking without `keep-mods` is synchronous; macros are async — the mask
  is gone before any steps execute
- HID has no "force lowercase" keycode; modifier state is always applied by the host OS
- There is no platform-portable "send raw ASCII value" in ZMK
- CapsWord cannot be made to exempt individual keys; it capitalizes all word characters
- `tap-dance` nested inside `hold-tap` for "Qu" on 2x-tap: theoretically workable but
  adds latency to every single "qu" tap while ZMK waits to distinguish 1 vs 2 taps —
  not worth it for a key used constantly
