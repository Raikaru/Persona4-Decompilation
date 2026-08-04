.section .text
.set noat
.set noreorder
glabel func_003bd4f0
    /* 2BD4F0 003BD4F0 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 2BD4F4 003BD4F4 6C00C28C */  lw         $2, 0x6C($6)
    /* 2BD4F8 003BD4F8 2000BFFF */  sd         $31, 0x20($29)
    /* 2BD4FC 003BD4FC 1000B17F */  sq         $17, 0x10($29)
    /* 2BD500 003BD500 0000B07F */  sq         $16, 0x0($29)
    /* 2BD504 003BD504 2D888000 */  daddu      $17, $4, $0
    /* 2BD508 003BD508 2D80C000 */  daddu      $16, $6, $0
    /* 2BD50C 003BD50C 2C004524 */  addiu      $5, $2, 0x2C
    /* 2BD510 003BD510 907C0F0C */  jal        func_003df240
    /* 2BD514 003BD514 04000624 */   addiu     $6, $0, 0x4
    /* 2BD518 003BD518 03004014 */  bnez       $2, .L003BD528
    /* 2BD51C 003BD51C 00000000 */   nop
    /* 2BD520 003BD520 08000010 */  b          .L003BD544
    /* 2BD524 003BD524 2D100000 */   daddu     $2, $0, $0
  .L003BD528:
    /* 2BD528 003BD528 6C00028E */  lw         $2, 0x6C($16)
    /* 2BD52C 003BD52C 2D202002 */  daddu      $4, $17, $0
    /* 2BD530 003BD530 04000624 */  addiu      $6, $0, 0x4
    /* 2BD534 003BD534 907C0F0C */  jal        func_003df240
    /* 2BD538 003BD538 30004524 */   addiu     $5, $2, 0x30
    /* 2BD53C 003BD53C 0A880200 */  movz       $17, $0, $2
    /* 2BD540 003BD540 2D102002 */  daddu      $2, $17, $0
  .L003BD544:
    /* 2BD544 003BD544 2000BFDF */  ld         $31, 0x20($29)
    /* 2BD548 003BD548 1000B17B */  lq         $17, 0x10($29)
    /* 2BD54C 003BD54C 0000B07B */  lq         $16, 0x0($29)
    /* 2BD550 003BD550 0800E003 */  jr         $31
    /* 2BD554 003BD554 3000BD27 */   addiu     $29, $29, 0x30
    /* 2BD558 003BD558 00000000 */  nop
    /* 2BD55C 003BD55C 00000000 */  nop
.size func_003bd4f0, 0x70
