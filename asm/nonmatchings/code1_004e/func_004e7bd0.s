.section .text
.set noat
.set noreorder
glabel func_004e7bd0
    /* 3E7BD0 004E7BD0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3E7BD4 004E7BD4 0800B1FF */  sd         $17, 0x8($29)
    /* 3E7BD8 004E7BD8 2D888000 */  daddu      $17, $4, $0
    /* 3E7BDC 004E7BDC 0000B0FF */  sd         $16, 0x0($29)
    /* 3E7BE0 004E7BE0 1D002012 */  beqz       $17, .L004E7C58
    /* 3E7BE4 004E7BE4 1000BFFF */   sd        $31, 0x10($29)
    /* 3E7BE8 004E7BE8 02002292 */  lbu        $2, 0x2($17)
    /* 3E7BEC 004E7BEC 0200422C */  sltiu      $2, $2, 0x2
    /* 3E7BF0 004E7BF0 04004054 */  bnel       $2, $0, .L004E7C04
    /* 3E7BF4 004E7BF4 01002282 */   lb        $2, 0x1($17)
    /* 3E7BF8 004E7BF8 B49F130C */  jal        func_004e7ed0
    /* 3E7BFC 004E7BFC 00000000 */   nop
    /* 3E7C00 004E7C00 01002282 */  lb         $2, 0x1($17)
  .L004E7C04:
    /* 3E7C04 004E7C04 0E004054 */  bnel       $2, $0, .L004E7C40
    /* 3E7C08 004E7C08 000020A2 */   sb        $0, 0x0($17)
    /* 3E7C0C 004E7C0C 8691130C */  jal        func_004e4618
    /* 3E7C10 004E7C10 00500424 */   addiu     $4, $0, 0x5000
    /* 3E7C14 004E7C14 6492130C */  jal        func_004e4990
    /* 3E7C18 004E7C18 1800248E */   lw        $4, 0x18($17)
    /* 3E7C1C 004E7C1C 01500424 */  addiu      $4, $0, 0x5001
    /* 3E7C20 004E7C20 8691130C */  jal        func_004e4618
    /* 3E7C24 004E7C24 2D804000 */   daddu     $16, $2, $0
    /* 3E7C28 004E7C28 7600043C */  lui        $4, %hi(D_0075B6B8)
    /* 3E7C2C 004E7C2C 03000106 */  bgez       $16, .L004E7C3C
    /* 3E7C30 004E7C30 B8B68424 */   addiu     $4, $4, %lo(D_0075B6B8)
    /* 3E7C34 004E7C34 DE34130C */  jal        func_004cd378
    /* 3E7C38 004E7C38 00000000 */   nop
  .L004E7C3C:
    /* 3E7C3C 004E7C3C 000020A2 */  sb         $0, 0x0($17)
  .L004E7C40:
    /* 3E7C40 004E7C40 2D202002 */  daddu      $4, $17, $0
    /* 3E7C44 004E7C44 0000B0DF */  ld         $16, 0x0($29)
    /* 3E7C48 004E7C48 0800B1DF */  ld         $17, 0x8($29)
    /* 3E7C4C 004E7C4C 1000BFDF */  ld         $31, 0x10($29)
    /* 3E7C50 004E7C50 8E9E1308 */  j          func_004e7a38
    /* 3E7C54 004E7C54 2000BD27 */   addiu     $29, $29, 0x20
  .L004E7C58:
    /* 3E7C58 004E7C58 0000B0DF */  ld         $16, 0x0($29)
    /* 3E7C5C 004E7C5C 0800B1DF */  ld         $17, 0x8($29)
    /* 3E7C60 004E7C60 1000BFDF */  ld         $31, 0x10($29)
    /* 3E7C64 004E7C64 0800E003 */  jr         $31
    /* 3E7C68 004E7C68 2000BD27 */   addiu     $29, $29, 0x20
    /* 3E7C6C 004E7C6C 00000000 */  nop
.size func_004e7bd0, 0xa0
