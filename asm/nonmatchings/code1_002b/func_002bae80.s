.section .text
.set noat
.set noreorder
glabel func_002bae80
    /* 1BAE80 002BAE80 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 1BAE84 002BAE84 2000BFFF */  sd         $31, 0x20($29)
    /* 1BAE88 002BAE88 1000B17F */  sq         $17, 0x10($29)
    /* 1BAE8C 002BAE8C 0000B07F */  sq         $16, 0x0($29)
    /* 1BAE90 002BAE90 2D80A000 */  daddu      $16, $5, $0
    /* 1BAE94 002BAE94 3C160400 */  dsll32     $2, $4, 24
    /* 1BAE98 002BAE98 3F160200 */  dsra32     $2, $2, 24
    /* 1BAE9C 002BAE9C 80180200 */  sll        $3, $2, 2
    /* 1BAEA0 002BAEA0 8800023C */  lui        $2, %hi(D_00882F40)
    /* 1BAEA4 002BAEA4 402F4224 */  addiu      $2, $2, %lo(D_00882F40)
    /* 1BAEA8 002BAEA8 21884300 */  addu       $17, $2, $3
    /* 1BAEAC 002BAEAC 0000228E */  lw         $2, 0x0($17)
    /* 1BAEB0 002BAEB0 0000448C */  lw         $4, 0x0($2)
    /* 1BAEB4 002BAEB4 04008104 */  bgez       $4, .L002BAEC8
    /* 1BAEB8 002BAEB8 00000000 */   nop
    /* 1BAEBC 002BAEBC 2D100000 */  daddu      $2, $0, $0
    /* 1BAEC0 002BAEC0 17000010 */  b          .L002BAF20
    /* 1BAEC4 002BAEC4 00000000 */   nop
  .L002BAEC8:
    /* 1BAEC8 002BAEC8 01000524 */  addiu      $5, $0, 0x1
    /* 1BAECC 002BAECC 84E1090C */  jal        func_00278610
    /* 1BAED0 002BAED0 00000000 */   nop
    /* 1BAED4 002BAED4 0000228E */  lw         $2, 0x0($17)
    /* 1BAED8 002BAED8 0000448C */  lw         $4, 0x0($2)
    /* 1BAEDC 002BAEDC 2000053C */  lui        $5, (0x200000 >> 16)
    /* 1BAEE0 002BAEE0 5CE0090C */  jal        func_00278170
    /* 1BAEE4 002BAEE4 00000000 */   nop
    /* 1BAEE8 002BAEE8 0000228E */  lw         $2, 0x0($17)
    /* 1BAEEC 002BAEEC 0000448C */  lw         $4, 0x0($2)
    /* 1BAEF0 002BAEF0 2D280002 */  daddu      $5, $16, $0
    /* 1BAEF4 002BAEF4 2D300000 */  daddu      $6, $0, $0
    /* 1BAEF8 002BAEF8 30DE090C */  jal        func_002778c0
    /* 1BAEFC 002BAEFC 00000000 */   nop
    /* 1BAF00 002BAF00 0000228E */  lw         $2, 0x0($17)
    /* 1BAF04 002BAF04 0000448C */  lw         $4, 0x0($2)
    /* 1BAF08 002BAF08 FFFF0524 */  addiu      $5, $0, -0x1
    /* 1BAF0C 002BAF0C 04DC090C */  jal        func_00277010
    /* 1BAF10 002BAF10 00000000 */   nop
    /* 1BAF14 002BAF14 01000224 */  addiu      $2, $0, 0x1
    /* 1BAF18 002BAF18 0000238E */  lw         $3, 0x0($17)
    /* 1BAF1C 002BAF1C 040062A0 */  sb         $2, 0x4($3)
  .L002BAF20:
    /* 1BAF20 002BAF20 2000BFDF */  ld         $31, 0x20($29)
    /* 1BAF24 002BAF24 1000B17B */  lq         $17, 0x10($29)
    /* 1BAF28 002BAF28 0000B07B */  lq         $16, 0x0($29)
    /* 1BAF2C 002BAF2C 3000BD27 */  addiu      $29, $29, 0x30
    /* 1BAF30 002BAF30 0800E003 */  jr         $31
    /* 1BAF34 002BAF34 00000000 */   nop
    /* 1BAF38 002BAF38 00000000 */  nop
    /* 1BAF3C 002BAF3C 00000000 */  nop
.size func_002bae80, 0xc0
