.section .text
.set noat
.set noreorder
glabel func_001b5d30
    /* B5D30 001B5D30 F0FFBD27 */  addiu      $29, $29, -0x10
    /* B5D34 001B5D34 0000BFFF */  sd         $31, 0x0($29)
    /* B5D38 001B5D38 ACB3828F */  lw         $2, -0x4C54($28)
    /* B5D3C 001B5D3C 7401428C */  lw         $2, 0x174($2)
    /* B5D40 001B5D40 04004010 */  beqz       $2, .L001B5D54
    /* B5D44 001B5D44 00000000 */   nop
    /* B5D48 001B5D48 2D100000 */  daddu      $2, $0, $0
    /* B5D4C 001B5D4C 10000010 */  b          .L001B5D90
    /* B5D50 001B5D50 00000000 */   nop
  .L001B5D54:
    /* B5D54 001B5D54 70DA060C */  jal        func_001b69c0
    /* B5D58 001B5D58 00000000 */   nop
    /* B5D5C 001B5D5C ACB3838F */  lw         $3, -0x4C54($28)
    /* B5D60 001B5D60 0C00628C */  lw         $2, 0xC($3)
    /* B5D64 001B5D64 00044230 */  andi       $2, $2, 0x400
    /* B5D68 001B5D68 08004010 */  beqz       $2, .L001B5D8C
    /* B5D6C 001B5D6C 00000000 */   nop
    /* B5D70 001B5D70 1C006394 */  lhu        $3, 0x1C($3)
    /* B5D74 001B5D74 02000224 */  addiu      $2, $0, 0x2
    /* B5D78 001B5D78 04006210 */  beq        $3, $2, .L001B5D8C
    /* B5D7C 001B5D7C 00000000 */   nop
    /* B5D80 001B5D80 10000224 */  addiu      $2, $0, 0x10
    /* B5D84 001B5D84 02000010 */  b          .L001B5D90
    /* B5D88 001B5D88 00000000 */   nop
  .L001B5D8C:
    /* B5D8C 001B5D8C 11000224 */  addiu      $2, $0, 0x11
  .L001B5D90:
    /* B5D90 001B5D90 0000BFDF */  ld         $31, 0x0($29)
    /* B5D94 001B5D94 1000BD27 */  addiu      $29, $29, 0x10
    /* B5D98 001B5D98 0800E003 */  jr         $31
    /* B5D9C 001B5D9C 00000000 */   nop
    /* B5DA0 001B5DA0 0800E003 */  jr         $31
    /* B5DA4 001B5DA4 00000000 */   nop
    /* B5DA8 001B5DA8 00000000 */  nop
    /* B5DAC 001B5DAC 00000000 */  nop
.size func_001b5d30, 0x80
