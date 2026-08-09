.section .text
.set noat
.set noreorder
glabel func_004d8d60
    /* 3D8D60 004D8D60 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D8D64 004D8D64 0000BFFF */  sd         $31, 0x0($29)
    /* 3D8D68 004D8D68 0000BFDF */  ld         $31, 0x0($29)
    /* 3D8D6C 004D8D6C D4FA1208 */  j          func_004beb50
    /* 3D8D70 004D8D70 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D8D74 004D8D74 00000000 */  nop
.size func_004d8d60, 0x18
