.section .text
.set noat
.set noreorder
glabel func_004be300
    /* 3BE300 004BE300 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3BE304 004BE304 0000BFFF */  sd         $31, 0x0($29)
    /* 3BE308 004BE308 0400848C */  lw         $4, 0x4($4)
    /* 3BE30C 004BE30C 0000BFDF */  ld         $31, 0x0($29)
    /* 3BE310 004BE310 867B1308 */  j          func_004dee18
    /* 3BE314 004BE314 1000BD27 */   addiu     $29, $29, 0x10
.size func_004be300, 0x18
