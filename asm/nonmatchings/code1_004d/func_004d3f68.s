.section .text
.set noat
.set noreorder
glabel func_004d3f68
    /* 3D3F68 004D3F68 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D3F6C 004D3F6C 0000BFFF */  sd         $31, 0x0($29)
    /* 3D3F70 004D3F70 3615130C */  jal        func_004c54d8
    /* 3D3F74 004D3F74 00000000 */   nop
    /* 3D3F78 004D3F78 E44F130C */  jal        func_004d3f90
    /* 3D3F7C 004D3F7C 00000000 */   nop
    /* 3D3F80 004D3F80 0000BFDF */  ld         $31, 0x0($29)
    /* 3D3F84 004D3F84 38151308 */  j          func_004c54e0
    /* 3D3F88 004D3F88 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D3F8C 004D3F8C 00000000 */  nop
.size func_004d3f68, 0x28
