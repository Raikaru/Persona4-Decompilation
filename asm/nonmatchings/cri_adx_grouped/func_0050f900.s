.section .text
.set noat
.set noreorder
glabel func_0050f900
    /* 40F900 0050F900 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40F904 0050F904 0000BFFF */  sd         $31, 0x0($29)
    /* 40F908 0050F908 A800848C */  lw         $4, 0xA8($4)
    /* 40F90C 0050F90C 0000BFDF */  ld         $31, 0x0($29)
    /* 40F910 0050F910 2EAF1408 */  j          func_0052bcb8
    /* 40F914 0050F914 1000BD27 */   addiu     $29, $29, 0x10
.size func_0050f900, 0x18
