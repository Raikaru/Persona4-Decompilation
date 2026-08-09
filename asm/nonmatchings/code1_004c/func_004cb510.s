.section .text
.set noat
.set noreorder
glabel func_004cb510
    /* 3CB510 004CB510 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CB514 004CB514 FFFF0224 */  addiu      $2, $0, -0x1
    /* 3CB518 004CB518 07008214 */  bne        $4, $2, .L004CB538
    /* 3CB51C 004CB51C 0000BFFF */   sd        $31, 0x0($29)
    /* 3CB520 004CB520 7C30130C */  jal        func_004cc1f0
    /* 3CB524 004CB524 00000000 */   nop
    /* 3CB528 004CB528 01000324 */  addiu      $3, $0, 0x1
    /* 3CB52C 004CB52C 26104300 */  xor        $2, $2, $3
    /* 3CB530 004CB530 02000424 */  addiu      $4, $0, 0x2
    /* 3CB534 004CB534 0B206200 */  movn       $4, $3, $2
  .L004CB538:
    /* 3CB538 004CB538 0000BFDF */  ld         $31, 0x0($29)
    /* 3CB53C 004CB53C 2D108000 */  daddu      $2, $4, $0
    /* 3CB540 004CB540 0800E003 */  jr         $31
    /* 3CB544 004CB544 1000BD27 */   addiu     $29, $29, 0x10
.size func_004cb510, 0x38
