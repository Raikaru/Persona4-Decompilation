.section .text
.set noat
.set noreorder
glabel func_003d7ac0
    /* 2D7AC0 003D7AC0 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 2D7AC4 003D7AC4 20000624 */  addiu      $6, $0, 0x20
    /* 2D7AC8 003D7AC8 2000BFFF */  sd         $31, 0x20($29)
    /* 2D7ACC 003D7ACC 1000B17F */  sq         $17, 0x10($29)
    /* 2D7AD0 003D7AD0 0000B07F */  sq         $16, 0x0($29)
    /* 2D7AD4 003D7AD4 2D888000 */  daddu      $17, $4, $0
    /* 2D7AD8 003D7AD8 2D80A000 */  daddu      $16, $5, $0
    /* 2D7ADC 003D7ADC 2D200002 */  daddu      $4, $16, $0
    /* 2D7AE0 003D7AE0 AC8A0F0C */  jal        func_003e2ab0
    /* 2D7AE4 003D7AE4 2D282002 */   daddu     $5, $17, $0
    /* 2D7AE8 003D7AE8 03004014 */  bnez       $2, .L003D7AF8
    /* 2D7AEC 003D7AEC 00000000 */   nop
    /* 2D7AF0 003D7AF0 07000010 */  b          .L003D7B10
    /* 2D7AF4 003D7AF4 2D100000 */   daddu     $2, $0, $0
  .L003D7AF8:
    /* 2D7AF8 003D7AF8 2D200002 */  daddu      $4, $16, $0
    /* 2D7AFC 003D7AFC 20002526 */  addiu      $5, $17, 0x20
    /* 2D7B00 003D7B00 907C0F0C */  jal        func_003df240
    /* 2D7B04 003D7B04 20000624 */   addiu     $6, $0, 0x20
    /* 2D7B08 003D7B08 0A880200 */  movz       $17, $0, $2
    /* 2D7B0C 003D7B0C 2D102002 */  daddu      $2, $17, $0
  .L003D7B10:
    /* 2D7B10 003D7B10 2000BFDF */  ld         $31, 0x20($29)
    /* 2D7B14 003D7B14 1000B17B */  lq         $17, 0x10($29)
    /* 2D7B18 003D7B18 0000B07B */  lq         $16, 0x0($29)
    /* 2D7B1C 003D7B1C 0800E003 */  jr         $31
    /* 2D7B20 003D7B20 3000BD27 */   addiu     $29, $29, 0x30
    /* 2D7B24 003D7B24 00000000 */  nop
    /* 2D7B28 003D7B28 00000000 */  nop
    /* 2D7B2C 003D7B2C 00000000 */  nop
.size func_003d7ac0, 0x70
