.section .text
.set noat
.set noreorder
glabel func_001b0d70
    /* B0D70 001B0D70 ACB3828F */  lw         $2, -0x4C54($28)
    /* B0D74 001B0D74 9C024524 */  addiu      $5, $2, 0x29C
    /* B0D78 001B0D78 2D180000 */  daddu      $3, $0, $0
    /* B0D7C 001B0D7C 06000010 */  b          .L001B0D98
    /* B0D80 001B0D80 00000000 */   nop
  .L001B0D84:
    /* B0D84 001B0D84 0000A28C */  lw         $2, 0x0($5)
    /* B0D88 001B0D88 06004010 */  beqz       $2, .L001B0DA4
    /* B0D8C 001B0D8C 00000000 */   nop
    /* B0D90 001B0D90 0400A524 */  addiu      $5, $5, 0x4
    /* B0D94 001B0D94 01006324 */  addiu      $3, $3, 0x1
  .L001B0D98:
    /* B0D98 001B0D98 0C00622C */  sltiu      $2, $3, 0xC
    /* B0D9C 001B0D9C F9FF4014 */  bnez       $2, .L001B0D84
    /* B0DA0 001B0DA0 00000000 */   nop
  .L001B0DA4:
    /* B0DA4 001B0DA4 0C000224 */  addiu      $2, $0, 0xC
    /* B0DA8 001B0DA8 04006214 */  bne        $3, $2, .L001B0DBC
    /* B0DAC 001B0DAC 00000000 */   nop
    /* B0DB0 001B0DB0 2D100000 */  daddu      $2, $0, $0
    /* B0DB4 001B0DB4 03000010 */  b          .L001B0DC4
    /* B0DB8 001B0DB8 00000000 */   nop
  .L001B0DBC:
    /* B0DBC 001B0DBC 0000A4AC */  sw         $4, 0x0($5)
    /* B0DC0 001B0DC0 01000224 */  addiu      $2, $0, 0x1
  .L001B0DC4:
    /* B0DC4 001B0DC4 0800E003 */  jr         $31
    /* B0DC8 001B0DC8 00000000 */   nop
    /* B0DCC 001B0DCC 00000000 */  nop
.size func_001b0d70, 0x60
