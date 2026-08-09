.section .text
.set noat
.set noreorder
glabel func_004f0668
    /* 3F0668 004F0668 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3F066C 004F066C 04000424 */  addiu      $4, $0, 0x4
    /* 3F0670 004F0670 0000BFFF */  sd         $31, 0x0($29)
    /* 3F0674 004F0674 0000BFDF */  ld         $31, 0x0($29)
    /* 3F0678 004F0678 46C11308 */  j          func_004f0518
    /* 3F067C 004F067C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004f0668, 0x18
