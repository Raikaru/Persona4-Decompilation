.section .text
.set noat
.set noreorder
glabel func_005097e8
    /* 4097E8 005097E8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 4097EC 005097EC 0000BFFF */  sd         $31, 0x0($29)
    /* 4097F0 005097F0 0000BFDF */  ld         $31, 0x0($29)
    /* 4097F4 005097F4 00261408 */  j          func_00509800
    /* 4097F8 005097F8 1000BD27 */   addiu     $29, $29, 0x10
    /* 4097FC 005097FC 00000000 */  nop
.size func_005097e8, 0x18
