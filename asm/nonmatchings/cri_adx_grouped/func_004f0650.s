.section .text
.set noat
.set noreorder
glabel func_004f0650
    /* 3F0650 004F0650 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3F0654 004F0654 03000424 */  addiu      $4, $0, 0x3
    /* 3F0658 004F0658 0000BFFF */  sd         $31, 0x0($29)
    /* 3F065C 004F065C 0000BFDF */  ld         $31, 0x0($29)
    /* 3F0660 004F0660 46C11308 */  j          func_004f0518
    /* 3F0664 004F0664 1000BD27 */   addiu     $29, $29, 0x10
.size func_004f0650, 0x18
