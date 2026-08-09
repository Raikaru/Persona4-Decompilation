.section .text
.set noat
.set noreorder
glabel func_0019cfb0
    /* 9CFB0 0019CFB0 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 9CFB4 0019CFB4 2000BFFF */  sd         $31, 0x20($29)
    /* 9CFB8 0019CFB8 1000B17F */  sq         $17, 0x10($29)
    /* 9CFBC 0019CFBC 0000B07F */  sq         $16, 0x0($29)
    /* 9CFC0 0019CFC0 2D800000 */  daddu      $16, $0, $0
    /* 9CFC4 0019CFC4 12000010 */  b          .L0019D010
    /* 9CFC8 0019CFC8 00000000 */   nop
  .L0019CFCC:
    /* 9CFCC 0019CFCC C0201000 */  sll        $4, $16, 3
    /* 9CFD0 0019CFD0 ACB3838F */  lw         $3, -0x4C54($28)
    /* 9CFD4 0019CFD4 21186400 */  addu       $3, $3, $4
    /* 9CFD8 0019CFD8 7C01718C */  lw         $17, 0x17C($3)
    /* 9CFDC 0019CFDC 09000010 */  b          .L0019D004
    /* 9CFE0 0019CFE0 00000000 */   nop
  .L0019CFE4:
    /* 9CFE4 0019CFE4 9800238E */  lw         $3, 0x98($17)
    /* 9CFE8 0019CFE8 02006330 */  andi       $3, $3, 0x2
    /* 9CFEC 0019CFEC 04006010 */  beqz       $3, .L0019D000
    /* 9CFF0 0019CFF0 00000000 */   nop
    /* 9CFF4 0019CFF4 2D202002 */  daddu      $4, $17, $0
    /* 9CFF8 0019CFF8 D076060C */  jal        func_0019db40
    /* 9CFFC 0019CFFC 00000000 */   nop
  .L0019D000:
    /* 9D000 0019D000 680A318E */  lw         $17, 0xA68($17)
  .L0019D004:
    /* 9D004 0019D004 F7FF2016 */  bnez       $17, .L0019CFE4
    /* 9D008 0019D008 00000000 */   nop
    /* 9D00C 0019D00C 01001026 */  addiu      $16, $16, 0x1
  .L0019D010:
    /* 9D010 0019D010 0400032E */  sltiu      $3, $16, 0x4
    /* 9D014 0019D014 EDFF6014 */  bnez       $3, .L0019CFCC
    /* 9D018 0019D018 00000000 */   nop
    /* 9D01C 0019D01C 2000BFDF */  ld         $31, 0x20($29)
    /* 9D020 0019D020 1000B17B */  lq         $17, 0x10($29)
    /* 9D024 0019D024 0000B07B */  lq         $16, 0x0($29)
    /* 9D028 0019D028 3000BD27 */  addiu      $29, $29, 0x30
    /* 9D02C 0019D02C 0800E003 */  jr         $31
    /* 9D030 0019D030 00000000 */   nop
    /* 9D034 0019D034 00000000 */  nop
    /* 9D038 0019D038 00000000 */  nop
    /* 9D03C 0019D03C 00000000 */  nop
.size func_0019cfb0, 0x90
