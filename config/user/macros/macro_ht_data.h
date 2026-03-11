// === HOLD-TAP MACRO DATA ===
// X-macro table: HT_MACRO_ENTRY(NAME, <&kp ...>, ...)
// Included twice:
//   - in macros {}   (via MACRO_KPS alias)  → generates m_NAME zmk macro nodes
//   - in behaviors{} (via HT_FROM_MACRO alias) → generates ht_NAME hold-tap nodes
// To add/change an entry: edit only this file.

//                   NAME          key sequence (hold output)
HT_MACRO_ENTRY(1st,        <&kp S>, <&kp T>)                          // st
HT_MACRO_ENTRY(2nd,        <&kp N>, <&kp D>)                          // nd
HT_MACRO_ENTRY(3rd,        <&kp R>, <&kp D>)                          // rd
HT_MACRO_ENTRY(4th,        <&kp T>, <&kp H>)                          // th
HT_MACRO_ENTRY(am_lc,      <&kp A>, <&kp DOT>, <&kp M>, <&kp DOT>)    // a.m.
HT_MACRO_ENTRY(pm_lc,      <&kp P>, <&kp DOT>, <&kp M>, <&kp DOT>)    // p.m.
HT_MACRO_ENTRY(hr_abbrev,  <&kp H>, <&kp R>)                          // hr
HT_MACRO_ENTRY(min_abbrev, <&kp M>, <&kp I>, <&kp N>)                 // min
