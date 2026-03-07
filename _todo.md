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


## 🟢 LOW — Comment Noise Cleanup

Small things that clutter without adding value.

### Comment blocks that could be condensed

- [ ] **[user/behaviors/mod_morphs_engram.dtsi ~L12-20]** AHK mapping reference block — useful, but could trim the `[.]` markers and update now that F11/F12 are confirmed. Shorten 2-3 lines.

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
