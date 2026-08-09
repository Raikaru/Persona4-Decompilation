.section .text
.set noat
.set noreorder
glabel func_004e8d40
    /* 3E8D40 004E8D40 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3E8D44 004E8D44 1000BFFF */  sd         $31, 0x10($29)
    /* 3E8D48 004E8D48 E6A2130C */  jal        func_004e8b98
    /* 3E8D4C 004E8D4C 2D28A003 */   daddu     $5, $29, $0
    /* 3E8D50 004E8D50 0400A28F */  lw         $2, 0x4($29)
    /* 3E8D54 004E8D54 1000BFDF */  ld         $31, 0x10($29)
    /* 3E8D58 004E8D58 2B100200 */  sltu       $2, $0, $2
    /* 3E8D5C 004E8D5C 0800E003 */  jr         $31
    /* 3E8D60 004E8D60 2000BD27 */   addiu     $29, $29, 0x20
    /* 3E8D64 004E8D64 00000000 */  nop
.size func_004e8d40, 0x28
