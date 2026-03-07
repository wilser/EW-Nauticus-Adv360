# Keymap Cleanup — To Check & Do

Organized by priority. File paths are relative to `config/`. Line numbers are approximate (files change).
Mark with `[x]` when done, `[-]` if decided not to do.

## 🟡 MEDIUM - things to much better factor the code

- [ ] better C-style macros and more unified cases
    - [ ] todo: which cases?


## 🟡 MEDIUM — Stale TODO/WIP Markers to Resolve

### Needs investigation, research, or better testing

- [TODO] **[adv360.keymap ~L7]** `TODO: much of this overridden... UNSURE WHAT NEEDED (2024-04-13)` — 2+ years old. Remove note or convert to 1 line. ⇒ need help analysis

- [ ] **[user/behaviors/custom_behaviors.dtsi ~L107]** `// [.] 2025-01-12 broken?` on `lt_fst`. Test: does `lt_fst` actually work? If yes, remove comment. If no, open specific issue.
- [ ] **[user/combos.dtsi ~L71]** `slow-release; // TBD - will help prevent stuck mods?` (2025-03-27). Test whether `slow-release` helps. Remove TBD when decided.
- [ ] **[user/layers/layer_4_UTL.dtsi ~L10]** `[ ] is BT4 'off'? - seems like (light goes off)` — test or remove.
- [ ] **[user/layers/layer_4_UTL.dtsi ~L11]** `[.] DISC explicitly disconnects one? 2024-09-19 trying` — 6+ months old. Does it work? Remove or document finding.

