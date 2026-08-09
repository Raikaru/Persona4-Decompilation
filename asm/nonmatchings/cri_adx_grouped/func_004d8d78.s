.section .text
.set noat
.set noreorder
glabel func_004d8d78
    /* 3D8D78 004D8D78 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D8D7C 004D8D7C 0000BFFF */  sd         $31, 0x0($29)
    /* 3D8D80 004D8D80 0000BFDF */  ld         $31, 0x0($29)
    /* 3D8D84 004D8D84 E8FA1208 */  j          func_004beba0
    /* 3D8D88 004D8D88 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D8D8C 004D8D8C 00000000 */  nop
.size func_004d8d78, 0x18
