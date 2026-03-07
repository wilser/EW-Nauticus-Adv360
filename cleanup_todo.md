# Keymap Cleanup — To Check & Do

Organized by priority. File paths are relative to `config/`. Line numbers are approximate (files change).
Mark with `[x]` when done, `[-]` if decided not to do.

## 🟡 MEDIUM — Stale TODO/WIP Markers to Resolve

### Needs investigation first

- [TODO] **[adv360.keymap ~L7]** `TODO: much of this overridden... UNSURE WHAT NEEDED (2024-04-13)` — 2+ years old. Remove note or convert to 1 line. ⇒ need help analysis

### STILL to-do / revisit:

- [ ] **[user/behaviors/custom_behaviors.dtsi ~L107]** `// [.] 2025-01-12 broken?` on `lt_fst`. Test: does `lt_fst` actually work? If yes, remove comment. If no, open specific issue.
- [ ] **[user/combos.dtsi ~L71]** `slow-release; // TBD - will help prevent stuck mods?` (2025-03-27). Test whether `slow-release` helps. Remove TBD when decided.

- [ ] **[user/layers/layer_0_NGM.dtsi ~L19]** `▢ RH-thumb top-left - TBD (was \)` — is the current binding final? If yes, remove.
- [ ] **[user/layers/layer_3_NUM.dtsi ~L7]** `TODO: put back (num)Enter?` — `_KP_ENT` IS in the layer (used in row 3). Seems done — verify and remove.
- [ ] **[user/layers/layer_4_UTL.dtsi ~L10]** `[ ] is BT4 'off'? - seems like (light goes off)` — test or remove.
- [ ] **[user/layers/layer_4_UTL.dtsi ~L11]** `[.] DISC explicitly disconnects one? 2024-09-19 trying` — 6+ months old. Does it work? Remove or document finding.
- [ ] **[user/behaviors/custom_behaviors.dtsi ~L55]** `[.] TBD: still don't get the tap-term vs quick-tap nuances... 2024-12-21` — Research or remove. (Also has typo "guick".)

### Vague / probably just remove

- [ ] **[user/layers/layer_3_NUM.dtsi ~L8]** `[] TBD: PgUp / PgDn on thumb keys??` — Remove if not planned.
- [ ] **[user/layers/layer_4_UTL.dtsi ~L9]** `[ ] put back LS(N2)..N4?` — Remove if not planned.
- [ ] **[user/tapdance/general_tapdance.dtsi ~L4]** `[ ] macro-ify?` — Remove (no action for 1+ year).
- [ ] **[user/behaviors/custom_behaviors.dtsi ~L112, L121]** `▢ this also need ∆?` on `quick-tap-ms` in `lt_fst` and `lt_slw`. Unclear. Remove.

---

## 🟢 LOW — Comment Noise Cleanup

Small things that clutter without adding value.

### "was X" / historical inline notes (noise)

- [ ] **[user/behaviors/custom_behaviors.dtsi ~L17, L26, L37]** `/* was typo, and 175 */` (3 occurrences on `quick-tap-ms = <125>`). Remove all.
- [ ] **[user/behaviors/custom_behaviors.dtsi ~L30, L41]** `/* TEMP: ↑ adding MODS_LEFT/RIGHT to see if can n-hold mods */`. If still experimental, leave; if permanent, remove "TEMP" framing.
- [ ] **[user/macros/combos_macros_for_holds.dtsi]** Multiple `// was X` comments on timing values throughout the file (~16 instances). Scan and remove all. Pattern: `// was 10`, `// was 5`, `// was typo`, etc.

### Uncertainty markers that need a decision

- [ ] **[user/macros/combos_macros_for_holds.dtsi ~L27-28]** `wait-ms = <10>; // ??` and `tap-ms = <5>; // ??` — Remove `??` (current values are correct or need testing, not annotation).
- [ ] **[user/macros/combos_macros_for_holds.dtsi ~L42, L63]** `flavor = "hold-preferred"; // which?` — Remove `// which?`; flavor is set and presumably working.
- [ ] **[user/macros/combos_macros_for_holds.dtsi ~L43-44, L64-65]** `// ▢ TODO` on timing values. Remove markers; values are final.
- [ ] **[user/macros/combos_macros_for_holds.dtsi ~L56]** `// swallow the shift so Ø passed thru? (matter?)` — Test or remove question.

### Comment blocks that could be condensed

- [ ] **[adv360.keymap ~L34-39]** 6-line TAPPING comment block could be 1-2 lines: `// TAPPING: try disable global-quick-tap, quick-tap-ms ~125ms, remove hold-trigger-positions`
- [ ] **[user/behaviors/mod_morphs_engram.dtsi ~L12-20]** AHK mapping reference block — useful, but could trim the `[.]` markers and update now that F11/F12 are confirmed. Shorten 2-3 lines.
- [ ] **[user/tapdance/general_tapdance.dtsi ~L44]** `// 150 too fast, 300 too slow?` → `// Tuned: 150 too fast, 300 too slow`

### File-level header cleanup

- [ ] **[user/behaviors/mod_morphs_nums.dtsi ~L1-7]** `// ---------- NEW WIP LAYOUTS 2024-05+ ---------- //` — remove "NEW WIP" framing (2+ years old).
- [ ] **[user/behaviors/mod_morphs_engram.dtsi ~L11]** `// ---------- NEW WIP LAYOUTS 2024-02-19+ ---------- //` — same.
- [ ] **[user/macros/general_macros.dtsi ~L1-7]** TODO comment block at top — clarify or remove.
- [ ] **[user/macros/shortcuts_macros.dtsi ~L1]** `TODO: re-figure the CPP macro syntax to get these cleaner...` — either do it or remove.

---

## Notes

- **CONVENTIONS.md** already tracks the pending naming renames (mmNG2_* → mm_ng_*, etc.) — not duplicated here.
- The **`_unused/`** and **`archive/`** folders are intentionally kept; no action needed there.
- Line numbers will drift as edits are made — re-check surrounding context if off by a few lines.
