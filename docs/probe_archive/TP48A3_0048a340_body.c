/* Archived twin-port donor body: P3 FUN_00329890 / mdlFileBuildAxisRotation.
 * Classification: banned_asm (contains inline VU assembler), so it is not portable
 * under the cross-tree twin-port policy. P4 remains a bare INCLUDE_ASM.
 */
void mdlFileBuildAxisRotation(f32 param_1)
{
  f32 square;
  f32 cosine;
  f32 sine;
  f32 oneMinusCosine;
  f32 xy;
  f32 xz;
  f32 yz;
  f32 xSine;
  f32 ySine;
  f32 zSine;
  RwMatrix matrix;
  f32 axis[4];

  cosine = FUN_0052e6d8_f32(param_1);
  sine = FUN_0052e878_f32(param_1);
  __asm__ volatile ("sqc2 vf10, 0(%0)" : : "r"(axis) : "memory");
  square = axis[0] * axis[0];
  matrix.right.x = square + (1.0f - square) * cosine;
  xy = axis[0] * axis[1];
  oneMinusCosine = 1.0f - cosine;
  zSine = axis[2] * sine;
  xy = xy * oneMinusCosine;
  matrix.right.y = zSine + xy;
  xz = axis[0] * axis[2];
  ySine = axis[1] * sine;
  xz = xz * oneMinusCosine;
  matrix.right.z = xz - ySine;
  matrix.flags = 0;
  matrix.up.x = xy - zSine;
  square = axis[1] * axis[1];
  matrix.up.y = square + (1.0f - square) * cosine;
  yz = axis[1] * axis[2];
  xSine = axis[0] * sine;
  yz = yz * oneMinusCosine;
  matrix.up.z = xSine + yz;
  matrix.pad1 = 0;
  matrix.at.x = ySine + xz;
  matrix.at.y = yz - xSine;
  square = axis[2] * axis[2];
  matrix.at.z = square + (1.0f - square) * cosine;
  matrix.pad2 = 0;
  __asm__ volatile (
      "lqc2 vf28, 0(%0)\n"
      "lqc2 vf29, 16(%0)\n"
      "lqc2 vf30, 32(%0)"
      : : "r"(&matrix) : "memory");
}
