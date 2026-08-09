.section .text
.set noat
.set noreorder
glabel func_0050f960
    /* 40F960 0050F960 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40F964 0050F964 0000BFFF */  sd         $31, 0x0($29)
    /* 40F968 0050F968 0000BFDF */  ld         $31, 0x0($29)
    /* 40F96C 0050F96C 7CAE1408 */  j          func_0052b9f0
    /* 40F970 0050F970 1000BD27 */   addiu     $29, $29, 0x10
    /* 40F974 0050F974 00000000 */  nop
.size func_0050f960, 0x18
