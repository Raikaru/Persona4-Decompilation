.section .text
.set noat
.set noreorder
glabel func_004d8d48
    /* 3D8D48 004D8D48 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D8D4C 004D8D4C 0000BFFF */  sd         $31, 0x0($29)
    /* 3D8D50 004D8D50 0000BFDF */  ld         $31, 0x0($29)
    /* 3D8D54 004D8D54 C0FA1208 */  j          func_004beb00
    /* 3D8D58 004D8D58 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D8D5C 004D8D5C 00000000 */  nop
.size func_004d8d48, 0x18
