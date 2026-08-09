.section .text
.set noat
.set noreorder
glabel func_001b0dd0
    /* B0DD0 001B0DD0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* B0DD4 001B0DD4 0000BFFF */  sd         $31, 0x0($29)
    /* B0DD8 001B0DD8 2D308000 */  daddu      $6, $4, $0
    /* B0DDC 001B0DDC ACB3828F */  lw         $2, -0x4C54($28)
    /* B0DE0 001B0DE0 9C024824 */  addiu      $8, $2, 0x29C
    /* B0DE4 001B0DE4 2D380000 */  daddu      $7, $0, $0
    /* B0DE8 001B0DE8 02000010 */  b          .L001B0DF4
    /* B0DEC 001B0DEC 00000000 */   nop
  .L001B0DF0:
    /* B0DF0 001B0DF0 01000724 */  addiu      $7, $0, 0x1
  .L001B0DF4:
    /* B0DF4 001B0DF4 2D200001 */  daddu      $4, $8, $0
    /* B0DF8 001B0DF8 0C000524 */  addiu      $5, $0, 0xC
    /* B0DFC 001B0DFC 40C3060C */  jal        func_001b0d00
    /* B0E00 001B0E00 00000000 */   nop
    /* B0E04 001B0E04 01000324 */  addiu      $3, $0, 0x1
    /* B0E08 001B0E08 F9FF4310 */  beq        $2, $3, .L001B0DF0
    /* B0E0C 001B0E0C 00000000 */   nop
    /* B0E10 001B0E10 2D10E000 */  daddu      $2, $7, $0
    /* B0E14 001B0E14 0000BFDF */  ld         $31, 0x0($29)
    /* B0E18 001B0E18 1000BD27 */  addiu      $29, $29, 0x10
    /* B0E1C 001B0E1C 0800E003 */  jr         $31
    /* B0E20 001B0E20 00000000 */   nop
    /* B0E24 001B0E24 00000000 */  nop
    /* B0E28 001B0E28 00000000 */  nop
    /* B0E2C 001B0E2C 00000000 */  nop
.size func_001b0dd0, 0x60
