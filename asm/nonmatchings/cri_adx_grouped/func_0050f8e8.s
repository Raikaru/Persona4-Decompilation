.section .text
.set noat
.set noreorder
glabel func_0050f8e8
    /* 40F8E8 0050F8E8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40F8EC 0050F8EC 0000BFFF */  sd         $31, 0x0($29)
    /* 40F8F0 0050F8F0 A800848C */  lw         $4, 0xA8($4)
    /* 40F8F4 0050F8F4 0000BFDF */  ld         $31, 0x0($29)
    /* 40F8F8 0050F8F8 2CAF1408 */  j          func_0052bcb0
    /* 40F8FC 0050F8FC 1000BD27 */   addiu     $29, $29, 0x10
.size func_0050f8e8, 0x18
