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
| Mod-morphs (layout) | `mm_` | `mm_<layout>_<key>` | `mm_ng_tild`, `mm_ng_cmma`, `mm_num_apos` |
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
| Layer-local aliases | `_<NAME>` (with `#undef`) | `_HYPER`, `_MEH`, `_B_GUI` |
| Key shorthands (global) | all underscores; lowercase exceptions | `___`, `_x_`, `_tbd_` |

### When to Use `#define`

**DO use `#define` for:**
- Layer number constants (`L_NGM 0`, `L_LR 1`, ...)
- Key-position arrays (`KEYS_LEFT`, `THUMBS_LEFT`, ...)
- Frequently-used shorthand aliases (`___`, `_x_`)
- Layer-local key combinations — always pair with `#undef` after the layer
- Cases where the proper syntax would be very long and make the key-map hard to read

**DON'T use `#define` for:**
- Single-use values that can be written inline (unless very long)
- DTS property values (those belong as DTS node properties)

---

## Current Inconsistencies (to fix gradually)

The following use older naming that pre-dates these conventions.
Rename when touching the file; don't rename proactively unless doing a full pass.

| Current name | Should become |
|---|---|
| `mmNG2_Tild`, `mmNG2_Cmma`, ... | `mm_ng_tild`, `mm_ng_cmma`, ... |
| `mmNUM_Apos`, `mmNUM_Mult`, ... | `mm_num_apos`, `mm_num_mult`, ... |
| `mmsNG2_*` (MOD_MORPH_SHIFT macro output) | `mm_ng_s_*` (update macro prefix) |
| `TD_Emj_WinDsk`, `TD_LR_1`, ... | `td_emj_wdsk`, `td_lr_1`, ... |
| `as_1st`, `as_am_lc`, `as_hr_abbrev`, ... | `m_1st`, `m_am_lc`, `m_hr_abbrev`, ... (these are hold-taps wrapping macros, not auto-shift behaviors — rename to `ht_1st`, `ht_am_lc`, etc. or keep `as_` if the distinction is deliberate) |

---

## Comment Conventions

| Marker | Meaning |
|---|---|
| `// TODO:` | Needs implementation or decision |
| `// [.]` | In-progress / uncertain |
| `// [v]` | DONE |
| `// ▢` | TODO |
| `// ▣` | WIP marker |
