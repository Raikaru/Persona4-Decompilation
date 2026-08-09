.section .text
.set noat
.set noreorder
glabel func_005159e8
    /* 4159E8 005159E8 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 4159EC 005159EC 2000BFFF */  sd         $31, 0x20($29)
    /* 4159F0 005159F0 2453140C */  jal        func_00514c90
    /* 4159F4 005159F4 2D30A003 */   daddu     $6, $29, $0
    /* 4159F8 005159F8 0400A38F */  lw         $3, 0x4($29)
    /* 4159FC 005159FC 0C00A28F */  lw         $2, 0xC($29)
    /* 415A00 00515A00 2000BFDF */  ld         $31, 0x20($29)
    /* 415A04 00515A04 21106200 */  addu       $2, $3, $2
    /* 415A08 00515A08 0800E003 */  jr         $31
    /* 415A0C 00515A0C 3000BD27 */   addiu     $29, $29, 0x30
.size func_005159e8, 0x28
