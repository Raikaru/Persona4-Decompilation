.section .text
.set noat
.set noreorder
glabel func_0014a2a0
    /* 4A2A0 0014A2A0 FFFF8330 */  andi       $3, $4, 0xFFFF
    /* 4A2A4 0014A2A4 3C006228 */  slti       $2, $3, 0x3C
    /* 4A2A8 0014A2A8 07004014 */  bnez       $2, .L0014A2C8
    /* 4A2AC 0014A2AC 00000000 */   nop
    /* 4A2B0 0014A2B0 50006128 */  slti       $1, $3, 0x50
    /* 4A2B4 0014A2B4 04002010 */  beqz       $1, .L0014A2C8
    /* 4A2B8 0014A2B8 00000000 */   nop
    /* 4A2BC 0014A2BC 01000224 */  addiu      $2, $0, 0x1
    /* 4A2C0 0014A2C0 02000010 */  b          .L0014A2CC
    /* 4A2C4 0014A2C4 00000000 */   nop
  .L0014A2C8:
    /* 4A2C8 0014A2C8 2D100000 */  daddu      $2, $0, $0
  .L0014A2CC:
    /* 4A2CC 0014A2CC 0800E003 */  jr         $31
    /* 4A2D0 0014A2D0 00000000 */   nop
    /* 4A2D4 0014A2D4 00000000 */  nop
    /* 4A2D8 0014A2D8 00000000 */  nop
    /* 4A2DC 0014A2DC 00000000 */  nop
.size func_0014a2a0, 0x40
