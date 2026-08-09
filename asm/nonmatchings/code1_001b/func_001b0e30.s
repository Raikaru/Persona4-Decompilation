.section .text
.set noat
.set noreorder
glabel func_001b0e30
    /* B0E30 001B0E30 ACB3828F */  lw         $2, -0x4C54($28)
    /* B0E34 001B0E34 CC024524 */  addiu      $5, $2, 0x2CC
    /* B0E38 001B0E38 2D180000 */  daddu      $3, $0, $0
    /* B0E3C 001B0E3C 06000010 */  b          .L001B0E58
    /* B0E40 001B0E40 00000000 */   nop
  .L001B0E44:
    /* B0E44 001B0E44 0000A28C */  lw         $2, 0x0($5)
    /* B0E48 001B0E48 06004010 */  beqz       $2, .L001B0E64
    /* B0E4C 001B0E4C 00000000 */   nop
    /* B0E50 001B0E50 0400A524 */  addiu      $5, $5, 0x4
    /* B0E54 001B0E54 01006324 */  addiu      $3, $3, 0x1
  .L001B0E58:
    /* B0E58 001B0E58 0C00622C */  sltiu      $2, $3, 0xC
    /* B0E5C 001B0E5C F9FF4014 */  bnez       $2, .L001B0E44
    /* B0E60 001B0E60 00000000 */   nop
  .L001B0E64:
    /* B0E64 001B0E64 0C000224 */  addiu      $2, $0, 0xC
    /* B0E68 001B0E68 04006214 */  bne        $3, $2, .L001B0E7C
    /* B0E6C 001B0E6C 00000000 */   nop
    /* B0E70 001B0E70 2D100000 */  daddu      $2, $0, $0
    /* B0E74 001B0E74 03000010 */  b          .L001B0E84
    /* B0E78 001B0E78 00000000 */   nop
  .L001B0E7C:
    /* B0E7C 001B0E7C 0000A4AC */  sw         $4, 0x0($5)
    /* B0E80 001B0E80 01000224 */  addiu      $2, $0, 0x1
  .L001B0E84:
    /* B0E84 001B0E84 0800E003 */  jr         $31
    /* B0E88 001B0E88 00000000 */   nop
    /* B0E8C 001B0E8C 00000000 */  nop
.size func_001b0e30, 0x60
