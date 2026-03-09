# Keymap Cleanup — To Check & Do

Organized by priority. File paths are relative to `config/`. Line numbers are approximate (files change).
Mark with `[x]` when done, `[-]` if decided not to do.

## 🟡 MEDIUM - things to much better factor the code

- [ ] revisit the whole "urob" home-row timeless mods https://www.reddit.com/r/ErgoMechKeyboards/comments/11gejh3/lpt_try_urobs_zmk_timeless_homerow_mods_combos/ 


## 🟡 MEDIUM — Stale TODO/WIP Markers to Resolve

### Needs investigation, research, or better testing

- [ ] **[user/behaviors/custom_behaviors.dtsi ~L107]** `// [.] 2025-01-12 broken?` on `lt_fst`. Test: does `lt_fst` actually work? If yes, remove comment. If no, open specific issue.
- [ ] **[user/combos.dtsi ~L71]** `slow-release; // TBD - will help prevent stuck mods?` (2025-03-27). Test whether `slow-release` helps. Remove TBD when decided.


