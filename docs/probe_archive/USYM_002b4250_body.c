/* object/window/nd: 12/1936/10; differing offsets: 0x0, 0x4, 0x8 (12-byte stub prefix); deficit: 1924 B / 481 instructions; prologue: frame 0x80, saves $s0/$s1/$s2 and $f20; args: (u8 *arg0); classification: reconstruction-scale with COP1 accumulator-chain floor at 0x002B452C adda.s and 0x002B4530 madd.s; ruled out: movz/movn, standalone MMI, framed tail-jump; ordinary rd-form mult is not a floor; no live C body. */
/*
Retail facts:
- $s2 is *(u8 **)(arg0 + 0x38); $s1/$s0 hold signed coordinate deltas;
  the narrow state/table index is the s8 field at offset 1, while byte fields at
  offsets 0x18/0x19 feed the u8 coordinate values. $f20 remains live across
  coordinate helper calls.
- Both state branches contain duplicated table lookup, visibility checks,
  coordinate math, and callback setup; the 12-byte return-0 result is a severe
  size deficit, not a useful C near miss.
- More COP1 accumulator proofs occur at 0x002B45B4/0x002B45B8,
  0x002B4858/0x002B485C, and 0x002B48F4/0x002B48F8. Do not classify the
  three-operand rd-form mult at 0x002B4398 or 0x002B456C as a floor.
*/
