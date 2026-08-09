.section .text
.set noat
.set noreorder
glabel func_004d5b30
    /* 3D5B30 004D5B30 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D5B34 004D5B34 0000BFFF */  sd         $31, 0x0($29)
    /* 3D5B38 004D5B38 3615130C */  jal        func_004c54d8
    /* 3D5B3C 004D5B3C 00000000 */   nop
    /* 3D5B40 004D5B40 D656130C */  jal        func_004d5b58
    /* 3D5B44 004D5B44 00000000 */   nop
    /* 3D5B48 004D5B48 0000BFDF */  ld         $31, 0x0($29)
    /* 3D5B4C 004D5B4C 38151308 */  j          func_004c54e0
    /* 3D5B50 004D5B50 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D5B54 004D5B54 00000000 */  nop
.size func_004d5b30, 0x28
