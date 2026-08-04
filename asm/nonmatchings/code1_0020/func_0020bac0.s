.section .text
.set noat
.set noreorder
glabel func_0020bac0
    /* 10BAC0 0020BAC0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 10BAC4 0020BAC4 0000BFFF */  sd         $31, 0x0($29)
    /* 10BAC8 0020BAC8 5849110C */  jal        func_00452560
    /* 10BACC 0020BACC 00000000 */   nop
    /* 10BAD0 0020BAD0 10074524 */  addiu      $5, $2, 0x710
    /* 10BAD4 0020BAD4 ACB3838F */  lw         $3, -0x4C54($28)
    /* 10BAD8 0020BAD8 7801668C */  lw         $6, 0x178($3)
    /* 10BADC 0020BADC FFFD0424 */  addiu      $4, $0, -0x201
    /* 10BAE0 0020BAE0 05000010 */  b          .L0020BAF8
    /* 10BAE4 0020BAE4 00000000 */   nop
  .L0020BAE8:
    /* 10BAE8 0020BAE8 100AC38C */  lw         $3, 0xA10($6)
    /* 10BAEC 0020BAEC 24186400 */  and        $3, $3, $4
    /* 10BAF0 0020BAF0 100AC3AC */  sw         $3, 0xA10($6)
    /* 10BAF4 0020BAF4 6C0AC68C */  lw         $6, 0xA6C($6)
  .L0020BAF8:
    /* 10BAF8 0020BAF8 00000000 */  nop
    /* 10BAFC 0020BAFC FAFFC014 */  bnez       $6, .L0020BAE8
    /* 10BB00 0020BB00 00000000 */   nop
    /* 10BB04 0020BB04 03000324 */  addiu      $3, $0, 0x3
    /* 10BB08 0020BB08 0200A3A4 */  sh         $3, 0x2($5)
    /* 10BB0C 0020BB0C 0000BFDF */  ld         $31, 0x0($29)
    /* 10BB10 0020BB10 1000BD27 */  addiu      $29, $29, 0x10
    /* 10BB14 0020BB14 0800E003 */  jr         $31
    /* 10BB18 0020BB18 00000000 */   nop
    /* 10BB1C 0020BB1C 00000000 */  nop
.size func_0020bac0, 0x60
