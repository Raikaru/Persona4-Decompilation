/* object/window/nd: 12/1184/10; differing offsets: 0x0, 0x4, 0x8 (12-byte stub prefix); deficit: 1172 B / 293 instructions; prologue: frame 0x80, saves $s0/$s1/$s2 and $f20; args: (u8 *arg0); classification: reconstruction-scale with COP1 accumulator-chain floor at 0x002B3E04 adda.s and 0x002B3E08 madd.s; ruled out: movz/movn, standalone MMI, framed tail-jump; no live C body. */
/*
Retail facts:
- $s2 is *(u8 **)(arg0 + 0x38); $s1/$s0 are signed coordinate deltas derived from
  narrow fields at offsets 0x18/0x19; $f20 is live across each coordinate helper.
- The body has both large branches (field 0 and field 0x20 state paths), two
  coordinate transforms, callback setup, and two COP1 accumulator chains per
  path. An empty return-0 stub cannot be treated as a near miss.
- Additional accumulator-chain proofs occur at 0x002B3E70/0x002B3E74,
  0x002B3FC8/0x002B3FCC, and 0x002B4048/0x002B404C. The ordinary narrow-byte
  conversions and pointer/table arithmetic are not compiler floors.
*/
