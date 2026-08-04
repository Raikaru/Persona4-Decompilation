.section .text
.set noat
.set noreorder
glabel func_0017ccc0
    /* 7CCC0 0017CCC0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 7CCC4 0017CCC4 1000BFFF */  sd         $31, 0x10($29)
    /* 7CCC8 0017CCC8 0000B07F */  sq         $16, 0x0($29)
    /* 7CCCC 0017CCCC 2D808000 */  daddu      $16, $4, $0
    /* 7CCD0 0017CCD0 5F00043C */  lui        $4, %hi(D_005F18C0)
    /* 7CCD4 0017CCD4 C0188424 */  addiu      $4, $4, %lo(D_005F18C0)
    /* 7CCD8 0017CCD8 E5080524 */  addiu      $5, $0, 0x8E5
    /* 7CCDC 0017CCDC A43A110C */  jal        func_0044ea90
    /* 7CCE0 0017CCE0 00000000 */   nop
    /* 7CCE4 0017CCE4 01000424 */  addiu      $4, $0, 0x1
    /* 7CCE8 0017CCE8 40000524 */  addiu      $5, $0, 0x40
    /* 7CCEC 0017CCEC 0400063C */  lui        $6, (0x40000 >> 16)
    /* 7CCF0 0017CCF0 8800023C */  lui        $2, %hi(D_008873F4)
    /* 7CCF4 0017CCF4 F473428C */  lw         $2, %lo(D_008873F4)($2)
    /* 7CCF8 0017CCF8 09F84000 */  jalr       $2
    /* 7CCFC 0017CCFC 00000000 */   nop
    /* 7CD00 0017CD00 04004014 */  bnez       $2, .L0017CD14
    /* 7CD04 0017CD04 00000000 */   nop
    /* 7CD08 0017CD08 2D100000 */  daddu      $2, $0, $0
    /* 7CD0C 0017CD0C 0E000010 */  b          .L0017CD48
    /* 7CD10 0017CD10 00000000 */   nop
  .L0017CD14:
    /* 7CD14 0017CD14 2D200002 */  daddu      $4, $16, $0
    /* 7CD18 0017CD18 5F00053C */  lui        $5, %hi(D_005F1910)
    /* 7CD1C 0017CD1C 1019A524 */  addiu      $5, $5, %lo(D_005F1910)
    /* 7CD20 0017CD20 08000624 */  addiu      $6, $0, 0x8
    /* 7CD24 0017CD24 2D380000 */  daddu      $7, $0, $0
    /* 7CD28 0017CD28 2D400000 */  daddu      $8, $0, $0
    /* 7CD2C 0017CD2C 1800093C */  lui        $9, %hi(func_0017c930)
    /* 7CD30 0017CD30 30C92925 */  addiu      $9, $9, %lo(func_0017c930)
    /* 7CD34 0017CD34 18000A3C */  lui        $10, %hi(func_0017cc90)
    /* 7CD38 0017CD38 90CC4A25 */  addiu      $10, $10, %lo(func_0017cc90)
    /* 7CD3C 0017CD3C 2D584000 */  daddu      $11, $2, $0
    /* 7CD40 0017CD40 F047110C */  jal        func_00451fc0
    /* 7CD44 0017CD44 00000000 */   nop
  .L0017CD48:
    /* 7CD48 0017CD48 1000BFDF */  ld         $31, 0x10($29)
    /* 7CD4C 0017CD4C 0000B07B */  lq         $16, 0x0($29)
    /* 7CD50 0017CD50 2000BD27 */  addiu      $29, $29, 0x20
    /* 7CD54 0017CD54 0800E003 */  jr         $31
    /* 7CD58 0017CD58 00000000 */   nop
    /* 7CD5C 0017CD5C 00000000 */  nop
.size func_0017ccc0, 0xa0
