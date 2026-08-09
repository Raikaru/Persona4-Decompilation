.section .text
.set noat
.set noreorder
glabel func_00503848
    /* 403848 00503848 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40384C 0050384C 0000BFFF */  sd         $31, 0x0($29)
    /* 403850 00503850 0000BFDF */  ld         $31, 0x0($29)
    /* 403854 00503854 180E1408 */  j          func_00503860
    /* 403858 00503858 1000BD27 */   addiu     $29, $29, 0x10
    /* 40385C 0050385C 00000000 */  nop
.size func_00503848, 0x18
