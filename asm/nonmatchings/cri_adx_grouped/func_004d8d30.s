.section .text
.set noat
.set noreorder
glabel func_004d8d30
    /* 3D8D30 004D8D30 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D8D34 004D8D34 0000BFFF */  sd         $31, 0x0($29)
    /* 3D8D38 004D8D38 0000BFDF */  ld         $31, 0x0($29)
    /* 3D8D3C 004D8D3C A8FA1208 */  j          func_004beaa0
    /* 3D8D40 004D8D40 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D8D44 004D8D44 00000000 */  nop
.size func_004d8d30, 0x18
