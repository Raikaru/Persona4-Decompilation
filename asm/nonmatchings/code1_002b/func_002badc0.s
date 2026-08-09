.section .text
.set noat
.set noreorder
glabel func_002badc0
    /* 1BADC0 002BADC0 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 1BADC4 002BADC4 2000BFFF */  sd         $31, 0x20($29)
    /* 1BADC8 002BADC8 1000B17F */  sq         $17, 0x10($29)
    /* 1BADCC 002BADCC 0000B07F */  sq         $16, 0x0($29)
    /* 1BADD0 002BADD0 2D80A000 */  daddu      $16, $5, $0
    /* 1BADD4 002BADD4 3C160400 */  dsll32     $2, $4, 24
    /* 1BADD8 002BADD8 3F160200 */  dsra32     $2, $2, 24
    /* 1BADDC 002BADDC 80180200 */  sll        $3, $2, 2
    /* 1BADE0 002BADE0 8800023C */  lui        $2, %hi(D_00882F40)
    /* 1BADE4 002BADE4 402F4224 */  addiu      $2, $2, %lo(D_00882F40)
    /* 1BADE8 002BADE8 21884300 */  addu       $17, $2, $3
    /* 1BADEC 002BADEC 0000228E */  lw         $2, 0x0($17)
    /* 1BADF0 002BADF0 0000448C */  lw         $4, 0x0($2)
    /* 1BADF4 002BADF4 04008104 */  bgez       $4, .L002BAE08
    /* 1BADF8 002BADF8 00000000 */   nop
    /* 1BADFC 002BADFC 2D100000 */  daddu      $2, $0, $0
    /* 1BAE00 002BAE00 17000010 */  b          .L002BAE60
    /* 1BAE04 002BAE04 00000000 */   nop
  .L002BAE08:
    /* 1BAE08 002BAE08 2D280000 */  daddu      $5, $0, $0
    /* 1BAE0C 002BAE0C 84E1090C */  jal        func_00278610
    /* 1BAE10 002BAE10 00000000 */   nop
    /* 1BAE14 002BAE14 0000228E */  lw         $2, 0x0($17)
    /* 1BAE18 002BAE18 0000448C */  lw         $4, 0x0($2)
    /* 1BAE1C 002BAE1C 2000053C */  lui        $5, (0x200000 >> 16)
    /* 1BAE20 002BAE20 5CE0090C */  jal        func_00278170
    /* 1BAE24 002BAE24 00000000 */   nop
    /* 1BAE28 002BAE28 0000228E */  lw         $2, 0x0($17)
    /* 1BAE2C 002BAE2C 0000448C */  lw         $4, 0x0($2)
    /* 1BAE30 002BAE30 2D280002 */  daddu      $5, $16, $0
    /* 1BAE34 002BAE34 2D300000 */  daddu      $6, $0, $0
    /* 1BAE38 002BAE38 30DE090C */  jal        func_002778c0
    /* 1BAE3C 002BAE3C 00000000 */   nop
    /* 1BAE40 002BAE40 0000228E */  lw         $2, 0x0($17)
    /* 1BAE44 002BAE44 0000448C */  lw         $4, 0x0($2)
    /* 1BAE48 002BAE48 FFFF0524 */  addiu      $5, $0, -0x1
    /* 1BAE4C 002BAE4C 04DC090C */  jal        func_00277010
    /* 1BAE50 002BAE50 00000000 */   nop
    /* 1BAE54 002BAE54 01000224 */  addiu      $2, $0, 0x1
    /* 1BAE58 002BAE58 0000238E */  lw         $3, 0x0($17)
    /* 1BAE5C 002BAE5C 040062A0 */  sb         $2, 0x4($3)
  .L002BAE60:
    /* 1BAE60 002BAE60 2000BFDF */  ld         $31, 0x20($29)
    /* 1BAE64 002BAE64 1000B17B */  lq         $17, 0x10($29)
    /* 1BAE68 002BAE68 0000B07B */  lq         $16, 0x0($29)
    /* 1BAE6C 002BAE6C 3000BD27 */  addiu      $29, $29, 0x30
    /* 1BAE70 002BAE70 0800E003 */  jr         $31
    /* 1BAE74 002BAE74 00000000 */   nop
    /* 1BAE78 002BAE78 00000000 */  nop
    /* 1BAE7C 002BAE7C 00000000 */  nop
.size func_002badc0, 0xc0
