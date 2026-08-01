.section .text
.set noat
.set noreorder
glabel func_0044b8f0
    /* 34B8F0 0044B8F0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 34B8F4 0044B8F4 0000BFFF */  sd         $31, 0x0($29)
    /* 34B8F8 0044B8F8 0000BFDF */  ld         $31, 0x0($29)
    /* 34B8FC 0044B8FC E21E1108 */  j          func_00447b88
    /* 34B900 0044B900 1000BD27 */   addiu     $29, $29, 0x10
    /* 34B904 0044B904 00000000 */  nop
.size func_0044b8f0, 0x18
