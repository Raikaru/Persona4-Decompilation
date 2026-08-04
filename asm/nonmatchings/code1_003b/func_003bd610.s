.section .text
.set noat
.set noreorder
glabel func_003bd610
    /* 2BD610 003BD610 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 2BD614 003BD614 7C00C28C */  lw         $2, 0x7C($6)
    /* 2BD618 003BD618 2000BFFF */  sd         $31, 0x20($29)
    /* 2BD61C 003BD61C 1000B17F */  sq         $17, 0x10($29)
    /* 2BD620 003BD620 0000B07F */  sq         $16, 0x0($29)
    /* 2BD624 003BD624 2D888000 */  daddu      $17, $4, $0
    /* 2BD628 003BD628 2D80C000 */  daddu      $16, $6, $0
    /* 2BD62C 003BD62C 2C004524 */  addiu      $5, $2, 0x2C
    /* 2BD630 003BD630 907C0F0C */  jal        func_003df240
    /* 2BD634 003BD634 04000624 */   addiu     $6, $0, 0x4
    /* 2BD638 003BD638 03004014 */  bnez       $2, .L003BD648
    /* 2BD63C 003BD63C 00000000 */   nop
    /* 2BD640 003BD640 08000010 */  b          .L003BD664
    /* 2BD644 003BD644 2D100000 */   daddu     $2, $0, $0
  .L003BD648:
    /* 2BD648 003BD648 7C00028E */  lw         $2, 0x7C($16)
    /* 2BD64C 003BD64C 2D202002 */  daddu      $4, $17, $0
    /* 2BD650 003BD650 04000624 */  addiu      $6, $0, 0x4
    /* 2BD654 003BD654 907C0F0C */  jal        func_003df240
    /* 2BD658 003BD658 30004524 */   addiu     $5, $2, 0x30
    /* 2BD65C 003BD65C 0A880200 */  movz       $17, $0, $2
    /* 2BD660 003BD660 2D102002 */  daddu      $2, $17, $0
  .L003BD664:
    /* 2BD664 003BD664 2000BFDF */  ld         $31, 0x20($29)
    /* 2BD668 003BD668 1000B17B */  lq         $17, 0x10($29)
    /* 2BD66C 003BD66C 0000B07B */  lq         $16, 0x0($29)
    /* 2BD670 003BD670 0800E003 */  jr         $31
    /* 2BD674 003BD674 3000BD27 */   addiu     $29, $29, 0x30
    /* 2BD678 003BD678 00000000 */  nop
    /* 2BD67C 003BD67C 00000000 */  nop
.size func_003bd610, 0x70
