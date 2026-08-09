.section .text
.set noat
.set noreorder
glabel func_004d8dd8
    /* 3D8DD8 004D8DD8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D8DDC 004D8DDC 0000BFFF */  sd         $31, 0x0($29)
    /* 3D8DE0 004D8DE0 0000BFDF */  ld         $31, 0x0($29)
    /* 3D8DE4 004D8DE4 8EFB1208 */  j          func_004bee38
    /* 3D8DE8 004D8DE8 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D8DEC 004D8DEC 00000000 */  nop
.size func_004d8dd8, 0x18
