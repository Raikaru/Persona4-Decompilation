.section .text
.set noat
.set noreorder
glabel func_003cbde0
    /* 2CBDE0 003CBDE0 A0FFBD27 */  addiu      $29, $29, -0x60
    /* 2CBDE4 003CBDE4 5000BFFF */  sd         $31, 0x50($29)
    /* 2CBDE8 003CBDE8 4000B47F */  sq         $20, 0x40($29)
    /* 2CBDEC 003CBDEC 3000B37F */  sq         $19, 0x30($29)
    /* 2CBDF0 003CBDF0 2000B27F */  sq         $18, 0x20($29)
    /* 2CBDF4 003CBDF4 1000B17F */  sq         $17, 0x10($29)
    /* 2CBDF8 003CBDF8 2D908000 */  daddu      $18, $4, $0
    /* 2CBDFC 003CBDFC 0000B07F */  sq         $16, 0x0($29)
    /* 2CBE00 003CBE00 2D88A000 */  daddu      $17, $5, $0
    /* 2CBE04 003CBE04 08B7828F */  lw         $2, -0x48F8($28)
    /* 2CBE08 003CBE08 21104202 */  addu       $2, $18, $2
    /* 2CBE0C 003CBE0C 0800538C */  lw         $19, 0x8($2)
    /* 2CBE10 003CBE10 0000548C */  lw         $20, 0x0($2)
    /* 2CBE14 003CBE14 03006016 */  bnez       $19, .L003CBE24
    /* 2CBE18 003CBE18 2D80C000 */   daddu     $16, $6, $0
  .L003CBE1C:
    /* 2CBE1C 003CBE1C 0D000010 */  b          .L003CBE54
    /* 2CBE20 003CBE20 2D104002 */   daddu     $2, $18, $0
  .L003CBE24:
    /* 2CBE24 003CBE24 0000848E */  lw         $4, 0x0($20)
    /* 2CBE28 003CBE28 09F82002 */  jalr       $17
    /* 2CBE2C 003CBE2C 2D280002 */   daddu     $5, $16, $0
    /* 2CBE30 003CBE30 03004014 */  bnez       $2, .L003CBE40
    /* 2CBE34 003CBE34 00000000 */   nop
    /* 2CBE38 003CBE38 06000010 */  b          .L003CBE54
    /* 2CBE3C 003CBE3C 2D104002 */   daddu     $2, $18, $0
  .L003CBE40:
    /* 2CBE40 003CBE40 FFFF7326 */  addiu      $19, $19, -0x1
    /* 2CBE44 003CBE44 F7FF6016 */  bnez       $19, .L003CBE24
    /* 2CBE48 003CBE48 04009426 */   addiu     $20, $20, 0x4
    /* 2CBE4C 003CBE4C F3FF0010 */  b          .L003CBE1C
    /* 2CBE50 003CBE50 00000000 */   nop
  .L003CBE54:
    /* 2CBE54 003CBE54 5000BFDF */  ld         $31, 0x50($29)
    /* 2CBE58 003CBE58 4000B47B */  lq         $20, 0x40($29)
    /* 2CBE5C 003CBE5C 3000B37B */  lq         $19, 0x30($29)
    /* 2CBE60 003CBE60 2000B27B */  lq         $18, 0x20($29)
    /* 2CBE64 003CBE64 1000B17B */  lq         $17, 0x10($29)
    /* 2CBE68 003CBE68 0000B07B */  lq         $16, 0x0($29)
    /* 2CBE6C 003CBE6C 0800E003 */  jr         $31
    /* 2CBE70 003CBE70 6000BD27 */   addiu     $29, $29, 0x60
    /* 2CBE74 003CBE74 00000000 */  nop
    /* 2CBE78 003CBE78 00000000 */  nop
    /* 2CBE7C 003CBE7C 00000000 */  nop
.size func_003cbde0, 0xa0
