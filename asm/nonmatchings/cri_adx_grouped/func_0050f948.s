.section .text
.set noat
.set noreorder
glabel func_0050f948
    /* 40F948 0050F948 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40F94C 0050F94C 0000BFFF */  sd         $31, 0x0($29)
    /* 40F950 0050F950 0000BFDF */  ld         $31, 0x0($29)
    /* 40F954 0050F954 78AE1408 */  j          func_0052b9e0
    /* 40F958 0050F958 1000BD27 */   addiu     $29, $29, 0x10
    /* 40F95C 0050F95C 00000000 */  nop
.size func_0050f948, 0x18
