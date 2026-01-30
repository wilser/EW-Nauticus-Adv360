# Dead Code Analysis Report - ADV360 Nauticus Keyboard Firmware

## Overview
This ZMK (Zephyr Mechanical Keyboard) firmware project for the Kinesis Advantage 360 Pro keyboard contains several categories of dead code accumulated during development. This report identifies all unused files, macros, behaviors, and commented-out code.

---

## Category 1: Unused Directories (Safe to Delete)

### 1.1 Example Files Directory
**Path:** `config/_examples/`
- `adv360.keymap.original` - Original factory keymap from Kinesis
- `keymap-example.dtsi` - Example keymap snippet
- `layers.dtsi.thinkunneeded` - Old layer definitions (8 lines)
- `macros_examples.dtsi` - Example macros

**Status:** Reference/example files only, never included in builds

### 1.2 Notes and Reference Directory
**Path:** `notes_and_ref/`
- `old_Colemak.keymap` - Old Colemak layout (replaced by Engram)
- `old_Dvorak.keymap` - Old Dvorak layout
- `old_MTGAP.keymap` - Old MTGAP layout
- `old_UCIEA.keymap` - Old UCIEA layout
- `mod_morphs_engram_BEF_ShiftNumbers.dtsi` - Archived version before refactoring
- `mod_morphs_special-unused-good-notes.dtsi` - Special case notes, marked as unused
- `EW Notes.txt`, `EW TODO.txt`, `Keymap ref.txt` - Personal notes

**Status:** All historical/archive material

---

## Category 2: Unused Include Files (Safe to Delete)

### 2.1 Commented Out Include
**File:** `config/macros/tap_hold_macros.dtsi`
- **Location in keymap:** Line 101 of [adv360.keymap](config/adv360.keymap#L101) (commented: `//#include "macros/tap_hold_macros.dtsi"`)
- **Last modified:** Apr 16, 2024
- **Status:** Alternative tap-hold implementation, intentionally disabled
- **Contains:** 1 unused macro (`m_1TAP_EW_N6`)

### 2.2 Never Referenced Files
**File:** `config/macros/hold_mods_delays m_gen not working.dtsi`
- **Status:** Problematic filename with spaces, clearly broken/experimental
- **Content:** Incomplete macros for Ctrl+Shift+Alt combinations

**File:** `config/behaviors/mod_morphs_colemak.dtsi`
- **Status:** Colemak layout support, not included in active builds
- **Content:** MOD_MORPH_SHIFT macro definitions

**File:** `config/tapdance/templated_hold_onetap.dtsi`
- **Status:** Experimental template for hold-on-tap behavior
- **Content:** Commented-out experimental auto-shift behaviors

**File:** `config/boards/arm/adv360/macros.dtsi`
- **Status:** Legacy macro definitions (quotes, braces, parens)
- **Note:** Only referenced in old example file, superseded by newer macro system

---

## Category 3: Unused Macros Within Active Files

### 3.1 Unused in `config/macros/hold_mods_delays.dtsi`
**Lines 38-64:**
- `m_WC_C` - Win+Ctrl+C macro (unformatted copy via AHK)
- `m_WC_V` - Win+Ctrl+V macro (unformatted paste via AHK)

**Status:** Defined but never referenced in any keymap layer

### 3.2 Unused in `config/macros/shortcuts_macros.dtsi`
**Lines 94-100:**
- `m_ion` - Simple 3-letter macro (I-O-N)

**Status:** Appears to be leftover test/example

### 3.3 Unused in `config/macros/combos_macros_for_holds.dtsi`

**Commented Out (Lines 291-325):**
- `m_2brackets_left`, `as_2brackets_left`
- `m_2brackets_right`, `as_2brackets_right`
- **Note:** "2026-01-23 don't really like; prefer hold ⇒ { } better"

**Q-macro Alternatives (Lines 30-134):**
- `m_lcase_qu` - Never used
- `m_mixcase_Qu` - Never used
- `as_Qu` - Commented as "2025-03-27 NOT USED NOW"
- `mm_qu_Qu`, `ht_q_qu`, `ht_Q_Qu`, `mm_ht_qqu_QQu` - Alternative implementations not in use

**Time/AM-PM Macros (Lines 355-410) - UNUSED 2025-04-18:**
- `m_am_uc`, `as_am_uc` - Uppercase " AM"
- `m_pm_uc`, `as_pm_uc` - Uppercase " PM"
- `m_minutes`, `as_minutes` - " minutes" text
- **Note:** Only lowercase versions are used

**Template (Lines 328-346):**
- `m_TBD`, `as_TBD` - Template/placeholder, never used

### 3.4 Unused in `config/tapdance/lightroom_tapdance.dtsi`
**Lines 19-29:**
- `TD_LR_U` - Lightroom U tapdance
- **Note:** "▢ 2024-09-09 unused / see the ...D one"

**Lines 75-83:**
- `TD_LR_Q_TO` - Lightroom Q-to-layer tapdance
- **Note:** "CURRENTLY unused"

### 3.5 Unused in `config/behaviors/mod_morphs_general.dtsi`
**Lines 61-68:**
- `mm_LthGth_Bksp` - Less-than/Greater-than with backspace
- **Status:** Commented out, marked "WIP"

**Lines 71-76:**
- `mm_Bslh_Bksp` - Backslash/pipe with backspace
- **Status:** Defined but not referenced in keymap

---

## Category 4: Commented-Out Keymap Definitions

**File:** [config/adv360.keymap](config/adv360.keymap)

**Lines with commented #define statements:**
- Line 295: `//#define _SHF_BSLH_BKSP`
- Line 296: `//#define _SHF_BSP_R`
- Line 298: `//#define _MDSH_BSLH`
- Line 299: `//#define _SHF_LTGT_BK`
- Lines 311-312: `//#define AS_2BKT_L` and `//#define AS_2BKT_R` (reverted 2026-01-23)
- Lines 601-602: `//#define _CAP_Q` (appears twice with different implementations)

---

## Category 5: TODO/FIXME/WIP Markers (Potential Technical Debt)

**In [config/adv360.keymap](config/adv360.keymap):**
- Line 6: `// TODO: much of this overridden (I think) or bypassed...` - Uncertainty about behaviors.dtsi
- Line 167: `// [.] TBD: still don't get the tap-term vs quick-tap nuances...` (2024-12-21)
- Line 209: `// TBD layer Hold for 1, Tap for 2`
- Line 219: `// [.] 2025-01-12 broken?` - Reference to broken layer_tap_faster behavior
- Line 270-272: Multiple TODO items in layer comments
- Line 307: `//#define M_DASH F18 // ▢ 2024-09-20 NOT working reliably`
- Line 308: `#define BUL_AR_tbd &as F17 F15 // WIP`

**In [config/combos.dtsi](config/combos.dtsi):**
- Line 66: `// [F] RESET MODs when stuck / ▣ 2025-02-09 / WIP / NOT WORKING WELL`
- Line 106: `// WIP seems 33+ # not working, trying other pair?`

**In [config/macros/general_macros.dtsi](config/macros/general_macros.dtsi):**
- Lines 4-8: TODO about omitting `macro_tap` when not needed

---

## Summary Statistics

| Category | Count |
|----------|-------|
| **Unused Directories** | 2 (13 files total) |
| **Unused Include Files** | 5 files |
| **Unused Macros/Behaviors** | ~25+ definitions |
| **Commented-Out Definitions** | 8+ lines |
| **TODO/WIP Markers** | 10+ instances |

---

## Recommendations

### High Priority (Safe to Delete)
1. **Delete entire directories:**
   - `config/_examples/` (4 files)
   - `notes_and_ref/` (9 files)

2. **Delete unused include files:**
   - `config/macros/tap_hold_macros.dtsi`
   - `config/macros/hold_mods_delays m_gen not working.dtsi`
   - `config/behaviors/mod_morphs_colemak.dtsi`
   - `config/tapdance/templated_hold_onetap.dtsi`
   - `config/boards/arm/adv360/macros.dtsi`

### Medium Priority (Code Cleanup)
3. **Remove unused macro definitions from active files:**
   - Clean up `combos_macros_for_holds.dtsi` (remove Q-macro alternatives, unused time macros, template placeholders)
   - Clean up `hold_mods_delays.dtsi` (remove m_WC_C, m_WC_V)
   - Clean up `shortcuts_macros.dtsi` (remove m_ion)
   - Clean up `lightroom_tapdance.dtsi` (remove TD_LR_U, TD_LR_Q_TO)
   - Clean up `mod_morphs_general.dtsi` (remove commented WIP code)

4. **Remove commented-out #define statements:**
   - Clean up lines 295-299, 311-312, 601-602 in adv360.keymap

### Low Priority (Documentation)
5. **Resolve TODO/WIP markers:**
   - Review and either implement or remove experimental features
   - Document or fix broken behaviors (line 219, line 307)
   - Address uncertainty comments (line 6, line 167)

---

## Notes
- This is an actively maintained keyboard firmware with ongoing development
- Most dead code is clearly marked with dates and notes
- No critical issues found - just accumulated technical debt from experimentation
- Total potential cleanup: ~13 files + ~25 macro definitions
