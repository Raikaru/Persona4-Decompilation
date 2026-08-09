.section .text
.set noat
.set noreorder
glabel func_0050f538
    /* 40F538 0050F538 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40F53C 0050F53C 0000BFFF */  sd         $31, 0x0($29)
    /* 40F540 0050F540 A800848C */  lw         $4, 0xA8($4)
    /* 40F544 0050F544 0000BFDF */  ld         $31, 0x0($29)
    /* 40F548 0050F548 F6AE1408 */  j          func_0052bbd8
    /* 40F54C 0050F54C 1000BD27 */   addiu     $29, $29, 0x10
.size func_0050f538, 0x18
