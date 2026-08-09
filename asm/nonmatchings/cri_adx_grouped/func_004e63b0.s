.section .text
.set noat
.set noreorder
glabel func_004e63b0
    /* 3E63B0 004E63B0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3E63B4 004E63B4 2D108000 */  daddu      $2, $4, $0
    /* 3E63B8 004E63B8 07004014 */  bnez       $2, .L004E63D8
    /* 3E63BC 004E63BC 0000BFFF */   sd        $31, 0x0($29)
    /* 3E63C0 004E63C0 7600053C */  lui        $5, %hi(D_0075B1C8)
    /* 3E63C4 004E63C4 8E96130C */  jal        func_004e5a38
    /* 3E63C8 004E63C8 C8B1A524 */   addiu     $5, $5, %lo(D_0075B1C8)
    /* 3E63CC 004E63CC 03000010 */  b          .L004E63DC
    /* 3E63D0 004E63D0 2D100000 */   daddu     $2, $0, $0
    /* 3E63D4 004E63D4 00000000 */  nop
  .L004E63D8:
    /* 3E63D8 004E63D8 02004280 */  lb         $2, 0x2($2)
  .L004E63DC:
    /* 3E63DC 004E63DC 0000BFDF */  ld         $31, 0x0($29)
    /* 3E63E0 004E63E0 0800E003 */  jr         $31
    /* 3E63E4 004E63E4 1000BD27 */   addiu     $29, $29, 0x10
.size func_004e63b0, 0x38
