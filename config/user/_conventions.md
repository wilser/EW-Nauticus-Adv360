# ADV360 Keymap Naming Conventions

## Directory Structure

```
config/
├── adv360.keymap          ← main entry point (ZMK requires at root)
├── behaviors.dtsi         ← ZMK behaviors overlay (ZMK requires at root)
├── version.dtsi           ← build version
├── boards/arm/adv360/     ← ZMK hardware — do not edit
├── user/                  ← ALL user customizations
│   ├── behaviors/         ← mod_morphs_*.dtsi
│   ├── macros/            ← *_macros.dtsi, combos_macros_for_holds.dtsi
│   ├── tapdance/          ← *_tapdance.dtsi
│   └── combos.dtsi
└── _unused/               ← inactive code kept for reference
archive/                   ← historical reference: old layouts, notes, originals
```

---

## Naming Rules

### DTS Node Labels — `lower_snake_case`

| Category | Prefix | Pattern | Examples |
|---|---|---|---|
| Macros | `m_` | `m_<description>` | `m_sleep`, `m_csa_r`, `m_kvm_pgup` |
| Text/abbrev macros | `m_` | `m_<name>` | `m_m1`, `m_am_lc`, `m_1st` |
| Mod-morphs (general) | `mm_` | `mm_<base>_<shifted>` | `mm_bksp_pipe`, `mm_shift_bksp_l` |
| Mod-morphs (layout) | `mm_` | `mm_<layout>_<key-or-description>` | `mm_ngm_tild`, `mm_ngm_cmma`, `mm_num_apos` |
| Mod-morphs (with auto-shift) | `mms_` | `mms_<layout>_<key-or-description>` | `mms_ngm_tild`, `mm_ngm_cmma`, `mm_num_apos` |
| Tap-dance | `td_` | `td_<description>` | `td_emj_wdsk`, `td_cpwrd_cplock` |
| Hold-tap variants | — | `<type>_<variant>` | `hm_l`, `hm_slw`, `as_slw`, `lt_fst` |
| Named hold-tap | `ht_` | `ht_<description>` | `ht_cap_cw`, `ht_qu_q` |

**Layout abbreviations for `mm_<layout-abbrev>_` prefix:**
- `mm_ngm_*` — Engram ("NGM" abbrev) layout morphs
- `mm_num_*` — Numpad layer morphs
- `mm_gen_*` — General / cross-layout morphs (alternative to `mm_<base>_<shifted>`)

### `#define` Constants — `UPPER_SNAKE_CASE`

| Category | Pattern | Examples |
|---|---|---|
| Layer numbers | `L_<NAME>` | `L_NGM`, `L_LR`, `L_EDT` |
| Key position arrays | `<NAME>_<SIDE>` | `KEYS_LEFT`, `THUMBS_RIGHT` |
| Layer-local aliases (dual-function) | `_A_B` (with `#undef`) | `_B_GUI`, `_TILD_PIPE`, `_R_CTLR` |
| Layer-local aliases (single-concept) | `_MULTI-WORD` UPPER-KEBAB (with `#undef`) | `_VW-LIB`, `_ZOOM-IN`, `_VRT-CPY` |
| Key shorthands (global) | all underscores; lowercase exceptions | `___`, `_x_`, `_tbd_` |

### Layer-local `#define` Naming Pattern

Layer-local aliases follow `_TAP_HOLD` order — **primary (tap) key first, secondary (hold/shifted) second**:

| Behavior | Example define | Value |
|---|---|---|
| mod-morph hold-tap | `_TILD_PIPE` | `&mms_ngm_tild PIPE 0` |
| auto-shift | `_I_RSI` | `&as_slw RS(I) I` |
| mod-tap | `_TAB_SHTAB` | `&mt LS(TAB) TAB` |
| homerow mod | `_B_GUI` | `&hm_slw LGUI B` |
| layer-tap (if long) | `_BSLH_LET` | `&lt L_LET BSLH` |

Defines are ordered in the file to match layout position: **across rows, then down** (row 1 left→right, row 2 left→right, etc.). `#undef` block follows in the same order.

#### Dual-function vs. single-concept names

`_` between words = key performs **two distinct functions** (tap vs. hold/shift):

| Example | Meaning |
|---|---|
| `_B_GUI` | B tap, GUI hold |
| `_TILD_PIPE` | TILDE tap, PIPE shifted |
| `_R_CTLR` | R tap, Ctrl+R hold |

`-` within a name = **one function** described with multiple words (UPPER-KEBAB-CASE):

| Example | Meaning |
|---|---|
| `_VW-LIB` | view Library (one action) |
| `_ZOOM-IN` | zoom in (one action) |
| `_VRT-CPY` | virtual copy (one action) |

Rule: `_` separates functions; `-` joins words within one concept.

### When to Use `#define`

**DO use `#define` for:**
- Layer number constants (`L_NGM 0`, `L_LR 1`, ...)
- Key-position arrays (`KEYS_LEFT`, `THUMBS_LEFT`, ...)
- Frequently-used shorthand aliases (`___`, `_x_`)
- Layer-local key combinations — always pair with `#undef` after the layer
- **All** `as_*` (auto-shift), `mt` (mod-tap), and `hm_*` (homerow mod) bindings — these always take 2 args and deserve a readable alias
- `kp` with complex modifier chords, if too long to read inline (e.g. `_HYPER`, `_MEH`)

**DON'T use `#define` for:**
- Plain `&kp X` — write inline
- Simple `&lt L_X Y` or `&sl L_X` — write inline unless appears many times
- DTS property values (those belong as DTS node properties)

### ZMK Key Code Abbreviation Preference

Always prefer the **shorter** ZMK alias where one exists:

| Prefer | Over |
|---|---|
| `PRCNT` | `PERCENT` |
| `UNDER` | `UNDERSCORE` |
| `BSLH` | `BACKSLASH` |
| `BSPC` | `BACKSPACE` |
| `LBRC` | `LS(LBKT)` (when naming only; keep full form in code if clearer) |

---

## Current Inconsistencies (to fix gradually)

The following use older naming that pre-dates these conventions.
Rename when touching the file; don't rename proactively unless doing a full pass.

| Current name | Should become |
|---|---|
| `mmNG2_Tild`, `mmNG2_Cmma`, ... | `mm_ngm_tild`, `mm_ngm_cmma`, ... |
| `mmNUM_Apos`, `mmNUM_Mult`, ... | `mm_num_apos`, `mm_num_mult`, ... |
| `mmsNG2_*` (MOD_MORPH_SHIFT macro output) | `mm_ngm_s_*` (update macro prefix) |
| `TD_Emj_WinDsk`, `TD_LR_1`, ... | `td_emoj_wdsk`, `td_lr_1`, ... |
| `as_1st`, `as_am_lc`, `as_hr_abbrev`, ... | `ht_m_1st`, `ht_m_am_lc`, `ht_m_hr_abbrev`, ... (these are hold-taps wrapping macros, not auto-shift behaviors — rename to `ht_1st`, `ht_am_lc`, etc. or keep `as_` if the distinction is deliberate) |

---

## Comment Conventions

| Marker | Meaning |
|---|---|
| `// TODO:` | TODO - Needs implementation or decision |
| `// ▢` | TODO |
| `// [.]` | In-progress |
| `// ▣` | In-progress |
| `// [v]` | DONE |
| `// 🗹` | DONE |

---

## Runbooks

### Runbook: Pretty-printing a layer file

#### DEFs section — 3-column alignment

Treat the defines as a table with three fixed-width columns:

```
    #define _NAME           &behavior args            // comment
    ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
    col 1: fixed width      col 2: fixed width        col 3: flush-left
```

Steps:
1. Find the longest `_NAME` in the block → that sets col 1 width (name + 2 spaces minimum after)
2. Find the longest `&behavior args` value → that sets col 2 width (value + 2 spaces minimum after)
3. All `// comments` start at the same column (col 3)
4. Defines with no comment just end after the value — no trailing spaces needed

Use one global set of column stops for the whole DEFs section (not per row-group).

#### Layout grid — per-keyboard-column alignment

The keyboard has fixed physical columns. Each one maps to a text column whose width = widest token in that column + 2 spaces. **Do not use any one row as the reference** — the widest token in a column can be in any row.

Key structural zones (from `Keymap ref.txt` STARTER template):
```
Row 1:  [7 LH keys]  [big gap]  [7 RH keys]
Row 2:  [7 LH keys]  [big gap]  [7 RH keys]
Row 3:  [7 LH keys]  [gap]  [4 inner thumb]  [gap]  [7 RH keys]
Row 4:  [6 LH keys]  [2 inner thumb]  [6 RH keys]
Row 5:  [5 LH keys]  [gap]  [3 L-thumb]  [3 R-thumb]  [gap]  [5 RH keys]
```

Rules:
- All tokens left-aligned within their column slot
- Minimum 2 spaces between any two adjacent tokens
- The LH/RH gap in rows 1–2 is purely visual — use enough space to clearly split the halves
- The thumb cluster gaps (rows 3–5) follow the same column-width rule; they just happen to be narrower tokens
- Row 5 thumb keys naturally fan out from center due to the gap structure — this mirrors the physical layout and is intentional
