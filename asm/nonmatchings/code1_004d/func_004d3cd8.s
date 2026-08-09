.section .text
.set noat
.set noreorder
glabel func_004d3cd8
    /* 3D3CD8 004D3CD8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D3CDC 004D3CDC 0000B0FF */  sd         $16, 0x0($29)
    /* 3D3CE0 004D3CE0 0800BFFF */  sd         $31, 0x8($29)
    /* 3D3CE4 004D3CE4 3615130C */  jal        func_004c54d8
    /* 3D3CE8 004D3CE8 2D808000 */   daddu     $16, $4, $0
    /* 3D3CEC 004D3CEC 424F130C */  jal        func_004d3d08
    /* 3D3CF0 004D3CF0 2D200002 */   daddu     $4, $16, $0
    /* 3D3CF4 004D3CF4 0000B0DF */  ld         $16, 0x0($29)
    /* 3D3CF8 004D3CF8 0800BFDF */  ld         $31, 0x8($29)
    /* 3D3CFC 004D3CFC 38151308 */  j          func_004c54e0
    /* 3D3D00 004D3D00 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D3D04 004D3D04 00000000 */  nop
.size func_004d3cd8, 0x30
