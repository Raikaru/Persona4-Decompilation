.section .text
.set noat
.set noreorder
glabel func_005111d0
    /* 4111D0 005111D0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 4111D4 005111D4 0000BFFF */  sd         $31, 0x0($29)
    /* 4111D8 005111D8 A0C1130C */  jal        func_004f0680
    /* 4111DC 005111DC 00000000 */   nop
    /* 4111E0 005111E0 0000BFDF */  ld         $31, 0x0($29)
    /* 4111E4 005111E4 01000224 */  addiu      $2, $0, 0x1
    /* 4111E8 005111E8 0800E003 */  jr         $31
    /* 4111EC 005111EC 1000BD27 */   addiu     $29, $29, 0x10
.size func_005111d0, 0x20
