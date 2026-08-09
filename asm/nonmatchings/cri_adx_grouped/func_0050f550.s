.section .text
.set noat
.set noreorder
glabel func_0050f550
    /* 40F550 0050F550 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40F554 0050F554 0000BFFF */  sd         $31, 0x0($29)
    /* 40F558 0050F558 A800848C */  lw         $4, 0xA8($4)
    /* 40F55C 0050F55C 0000BFDF */  ld         $31, 0x0($29)
    /* 40F560 0050F560 FCAE1408 */  j          func_0052bbf0
    /* 40F564 0050F564 1000BD27 */   addiu     $29, $29, 0x10
.size func_0050f550, 0x18
