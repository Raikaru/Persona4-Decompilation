/* object/window/nd: 12/1248/10; differing offsets: 0x0, 0x4, 0x8 (12-byte stub prefix); deficit: 1236 B / 309 instructions; prologue: frame 0x80, saves $s0/$s1/$s2 and $f20; args: (u8 *arg0); classification: reconstruction-scale with COP1 accumulator-chain floor at 0x002B4CD4 adda.s and 0x002B4CD8 madd.s; ruled out: movz/movn, standalone MMI, framed tail-jump; ordinary narrow-index arithmetic is not a floor; no live C body. */
/*
Retail facts:
- $s2 is *(u8 **)(arg0 + 0x38); $s0/$s1 retain byte fields at offsets 0x0A/0x09
  and then signed coordinate deltas. The table selector at offset 0x0B is u8:
  sll/sub/sll/sub/sll expands it by the 0x150-byte record stride.
- The function has a state-0 path with visibility/threshold guards and callback
  setup plus a state-1 path that copies two input floats and performs the same
  callback. A 12-byte return-0 stub is a severe size deficit, not a near miss.
- The duplicated coordinate accumulator chain also proves at 0x002B4D64/
  0x002B4D68. The c.lt.s/c.le.s comparisons are ordinary C control flow, not
  one of the compiler floors.
*/
