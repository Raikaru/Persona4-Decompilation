.section .text
.set noat
.set noreorder
glabel func_004d3ee0
    /* 3D3EE0 004D3EE0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D3EE4 004D3EE4 0000BFFF */  sd         $31, 0x0($29)
    /* 3D3EE8 004D3EE8 3615130C */  jal        func_004c54d8
    /* 3D3EEC 004D3EEC 00000000 */   nop
    /* 3D3EF0 004D3EF0 C24F130C */  jal        func_004d3f08
    /* 3D3EF4 004D3EF4 00000000 */   nop
    /* 3D3EF8 004D3EF8 0000BFDF */  ld         $31, 0x0($29)
    /* 3D3EFC 004D3EFC 38151308 */  j          func_004c54e0
    /* 3D3F00 004D3F00 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D3F04 004D3F04 00000000 */  nop
.size func_004d3ee0, 0x28
