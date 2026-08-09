.section .text
.set noat
.set noreorder
glabel func_004e7d08
    /* 3E7D08 004E7D08 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3E7D0C 004E7D0C 2D108000 */  daddu      $2, $4, $0
    /* 3E7D10 004E7D10 07004014 */  bnez       $2, .L004E7D30
    /* 3E7D14 004E7D14 0000BFFF */   sd        $31, 0x0($29)
    /* 3E7D18 004E7D18 7600053C */  lui        $5, %hi(D_0075B6D0)
    /* 3E7D1C 004E7D1C 169D130C */  jal        func_004e7458
    /* 3E7D20 004E7D20 D0B6A524 */   addiu     $5, $5, %lo(D_0075B6D0)
    /* 3E7D24 004E7D24 03000010 */  b          .L004E7D34
    /* 3E7D28 004E7D28 2D100000 */   daddu     $2, $0, $0
    /* 3E7D2C 004E7D2C 00000000 */  nop
  .L004E7D30:
    /* 3E7D30 004E7D30 1C00428C */  lw         $2, 0x1C($2)
  .L004E7D34:
    /* 3E7D34 004E7D34 0000BFDF */  ld         $31, 0x0($29)
    /* 3E7D38 004E7D38 0800E003 */  jr         $31
    /* 3E7D3C 004E7D3C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004e7d08, 0x38
