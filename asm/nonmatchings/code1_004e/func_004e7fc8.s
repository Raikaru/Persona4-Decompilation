.section .text
.set noat
.set noreorder
glabel func_004e7fc8
    /* 3E7FC8 004E7FC8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3E7FCC 004E7FCC 2D108000 */  daddu      $2, $4, $0
    /* 3E7FD0 004E7FD0 07004014 */  bnez       $2, .L004E7FF0
    /* 3E7FD4 004E7FD4 0000BFFF */   sd        $31, 0x0($29)
    /* 3E7FD8 004E7FD8 7600053C */  lui        $5, %hi(D_0075B6D0)
    /* 3E7FDC 004E7FDC 169D130C */  jal        func_004e7458
    /* 3E7FE0 004E7FE0 D0B6A524 */   addiu     $5, $5, %lo(D_0075B6D0)
    /* 3E7FE4 004E7FE4 03000010 */  b          .L004E7FF4
    /* 3E7FE8 004E7FE8 2D100000 */   daddu     $2, $0, $0
    /* 3E7FEC 004E7FEC 00000000 */  nop
  .L004E7FF0:
    /* 3E7FF0 004E7FF0 02004280 */  lb         $2, 0x2($2)
  .L004E7FF4:
    /* 3E7FF4 004E7FF4 0000BFDF */  ld         $31, 0x0($29)
    /* 3E7FF8 004E7FF8 0800E003 */  jr         $31
    /* 3E7FFC 004E7FFC 1000BD27 */   addiu     $29, $29, 0x10
.size func_004e7fc8, 0x38
