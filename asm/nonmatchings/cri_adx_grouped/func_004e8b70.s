.section .text
.set noat
.set noreorder
glabel func_004e8b70
    /* 3E8B70 004E8B70 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3E8B74 004E8B74 7300043C */  lui        $4, %hi(D_00734370)
    /* 3E8B78 004E8B78 0000BFFF */  sd         $31, 0x0($29)
    /* 3E8B7C 004E8B7C 2D280000 */  daddu      $5, $0, $0
    /* 3E8B80 004E8B80 70438424 */  addiu      $4, $4, %lo(D_00734370)
    /* 3E8B84 004E8B84 10000624 */  addiu      $6, $0, 0x10
    /* 3E8B88 004E8B88 0000BFDF */  ld         $31, 0x0($29)
    /* 3E8B8C 004E8B8C 72FE1008 */  j          func_0043f9c8
    /* 3E8B90 004E8B90 1000BD27 */   addiu     $29, $29, 0x10
    /* 3E8B94 004E8B94 00000000 */  nop
.size func_004e8b70, 0x28
