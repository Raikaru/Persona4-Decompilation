.section .text
.set noat
.set noreorder
glabel func_001b0f20
    /* B0F20 001B0F20 ACB3828F */  lw         $2, -0x4C54($28)
    /* B0F24 001B0F24 9C024524 */  addiu      $5, $2, 0x29C
    /* B0F28 001B0F28 2D180000 */  daddu      $3, $0, $0
    /* B0F2C 001B0F2C 06000010 */  b          .L001B0F48
    /* B0F30 001B0F30 00000000 */   nop
  .L001B0F34:
    /* B0F34 001B0F34 0000A28C */  lw         $2, 0x0($5)
    /* B0F38 001B0F38 06004410 */  beq        $2, $4, .L001B0F54
    /* B0F3C 001B0F3C 00000000 */   nop
    /* B0F40 001B0F40 0400A524 */  addiu      $5, $5, 0x4
    /* B0F44 001B0F44 01006324 */  addiu      $3, $3, 0x1
  .L001B0F48:
    /* B0F48 001B0F48 0C00622C */  sltiu      $2, $3, 0xC
    /* B0F4C 001B0F4C F9FF4014 */  bnez       $2, .L001B0F34
    /* B0F50 001B0F50 00000000 */   nop
  .L001B0F54:
    /* B0F54 001B0F54 0C000224 */  addiu      $2, $0, 0xC
    /* B0F58 001B0F58 08006214 */  bne        $3, $2, .L001B0F7C
    /* B0F5C 001B0F5C 00000000 */   nop
    /* B0F60 001B0F60 2D100000 */  daddu      $2, $0, $0
    /* B0F64 001B0F64 0A000010 */  b          .L001B0F90
    /* B0F68 001B0F68 00000000 */   nop
  .L001B0F6C:
    /* B0F6C 001B0F6C FCFFA28C */  lw         $2, -0x4($5)
    /* B0F70 001B0F70 0000A2AC */  sw         $2, 0x0($5)
    /* B0F74 001B0F74 FCFFA524 */  addiu      $5, $5, -0x4
    /* B0F78 001B0F78 FFFF6324 */  addiu      $3, $3, -0x1
  .L001B0F7C:
    /* B0F7C 001B0F7C 00000000 */  nop
    /* B0F80 001B0F80 FAFF601C */  bgtz       $3, .L001B0F6C
    /* B0F84 001B0F84 00000000 */   nop
    /* B0F88 001B0F88 0000A4AC */  sw         $4, 0x0($5)
    /* B0F8C 001B0F8C 01000224 */  addiu      $2, $0, 0x1
  .L001B0F90:
    /* B0F90 001B0F90 0800E003 */  jr         $31
    /* B0F94 001B0F94 00000000 */   nop
    /* B0F98 001B0F98 00000000 */  nop
    /* B0F9C 001B0F9C 00000000 */  nop
.size func_001b0f20, 0x80
