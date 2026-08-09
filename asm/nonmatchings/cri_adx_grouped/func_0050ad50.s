.section .text
.set noat
.set noreorder
glabel func_0050ad50
    /* 40AD50 0050AD50 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 40AD54 0050AD54 1000BFFF */  sd         $31, 0x10($29)
    /* 40AD58 0050AD58 52A6140C */  jal        func_00529948
    /* 40AD5C 0050AD5C 2D28A003 */   daddu     $5, $29, $0
    /* 40AD60 0050AD60 01000324 */  addiu      $3, $0, 0x1
    /* 40AD64 0050AD64 0000A58F */  lw         $5, 0x0($29)
    /* 40AD68 0050AD68 26204300 */  xor        $4, $2, $3
    /* 40AD6C 0050AD6C 1000BFDF */  ld         $31, 0x10($29)
    /* 40AD70 0050AD70 FFFF0224 */  addiu      $2, $0, -0x1
    /* 40AD74 0050AD74 0A10A400 */  movz       $2, $5, $4
    /* 40AD78 0050AD78 0800E003 */  jr         $31
    /* 40AD7C 0050AD7C 2000BD27 */   addiu     $29, $29, 0x20
.size func_0050ad50, 0x30
