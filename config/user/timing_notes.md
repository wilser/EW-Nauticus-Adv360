# Tap-Hold Timing Notes
#claude summary & how make some "faster"
as of 2026-03-14

## How ZMK tap-hold timings work

In ZMK, **each hold-tap behavior is its own independent node** — there is no global TTM setting that cascades down. Every `hm_l`, `lt_fst`, `as_slw`, etc. is a fully self-contained DTS node with its own `tapping-term-ms`, `quick-tap-ms`, and `flavor`. The CPP macros in `def_macros.dtsi` are just stamping-factory syntax — they don't create inheritance, just reduce repetition.

---

## Where the settings live (the chain)

```
def_macros.dtsi          ← CPP macro templates (HT_KP, HT_KP_POS, HT_BINDS, HT_HRM)
    ↓ used by
holdtaps_for_layers.dtsi ← instantiates all named behavior nodes (hm_l, hm_med_l, lt_fst, etc.)
holdtaps_special_and_combos.dtsi  ← a few more (ht_cap_cw)
def_macros.dtsi (inline) ← MOD_MORPH_SHIFT hardcodes TTM=150 — not a parameter
combos_macros_for_holds.dtsi ← TAPPING_TERM_HT_MACRO 225 — all ht_NAME nodes share this one constant
    ↓ referenced by
Layer .dtsi files         ← &hm_l, &lt_fst, &as, etc. at specific key positions
```

---

## The current "speed tiers" you already have

| Behavior | TTM | QTM | Flavor | Use |
|---|---|---|---|---|
| `hm_l`/`hm_r` | 150 | 125 | balanced | SHIFT homerow |
| `hm_med_l`/`hm_med_r` | 200 | 150 | balanced | Ctrl/Alt homerow |
| `hm_slw` | 320 | 200 | tap-preferred | GUI/Win |
| `as` | 150 | 0 | tap-preferred | auto-shift fast |
| `as_slw` | 230 | 0 | tap-preferred | auto-shift slow |
| `lt_fst` | 150 | 0 | tap-preferred | layer-tap fast |
| `lt_slw` | 230 | 0 | tap-preferred | layer-tap slow |
| `mms_*` (all) | 150 | 0 | tap-preferred | hardcoded in MOD_MORPH_SHIFT macro |
| `ht_NAME` (hold=macro) | 225 | — | — | all share TAPPING_TERM_HT_MACRO |

---

## Plan for making specific tap-holds faster

**Option A — use an existing faster behavior** (zero effort)
If a key currently uses `as_slw` but you want it snappier, just point it at `as` (150ms) in the layer file instead.

**Option B — add a new named behavior node**
In `holdtaps_for_layers.dtsi`, add e.g.:
```
HT_KP(as_xfast, 100, 0, "tap-preferred")
```
Then use `&as_xfast` on specific keys. One line, no template changes needed.

**Option C — parameterize MOD_MORPH_SHIFT**
Right now the `mms_*` wrapper inside that macro has TTM hardcoded at 150. You could add a TTM argument to the macro if you wanted different auto-shift speeds for different keys. Currently all `mms_*` behaviors are identical except for which key they wrap.

**Option D — per-key hold-tap override** (ZMK doesn't support this natively)
ZMK doesn't allow setting TTM per-binding in the layer — it's always per-behavior-*node*. So "faster for this one key" always means "create a distinct behavior node."

---

## The key insight for "percolation"

There's no cascade. The closest thing to a shared global is:
- **`TAPPING_TERM_HT_MACRO`** in `combos_macros_for_holds.dtsi` — changing it affects all `ht_*` hold=macro behaviors at once
- **The `150` hardcoded in `MOD_MORPH_SHIFT`** — affects all `mms_*` wrappers
- **Individual `HT_*` calls** in `holdtaps_for_layers.dtsi` — each is independent, but you could extract a `#define TTM_FAST 150` at the top of that file to make them easier to tune in concert

If you wanted a "master TTM knob," you'd define a `#define TTM_BASE 150` (or similar) at the top of `holdtaps_for_layers.dtsi` and reference it in the `HT_*` calls — that would be the closest thing to a global that percolates down.
