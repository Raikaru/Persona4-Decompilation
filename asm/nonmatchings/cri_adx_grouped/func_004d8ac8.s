.section .text
.set noat
.set noreorder
glabel func_004d8ac8
    /* 3D8AC8 004D8AC8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D8ACC 004D8ACC 2D280000 */  daddu      $5, $0, $0
    /* 3D8AD0 004D8AD0 0000BFFF */  sd         $31, 0x0($29)
    /* 3D8AD4 004D8AD4 08000624 */  addiu      $6, $0, 0x8
    /* 3D8AD8 004D8AD8 0C0080AC */  sw         $0, 0xC($4)
    /* 3D8ADC 004D8ADC 28008424 */  addiu      $4, $4, 0x28
    /* 3D8AE0 004D8AE0 0000BFDF */  ld         $31, 0x0($29)
    /* 3D8AE4 004D8AE4 72FE1008 */  j          func_0043f9c8
    /* 3D8AE8 004D8AE8 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D8AEC 004D8AEC 00000000 */  nop
.size func_004d8ac8, 0x28
