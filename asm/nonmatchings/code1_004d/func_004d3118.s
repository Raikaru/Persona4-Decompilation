.section .text
.set noat
.set noreorder
glabel func_004d3118
    /* 3D3118 004D3118 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D311C 004D311C 0000B0FF */  sd         $16, 0x0($29)
    /* 3D3120 004D3120 0800BFFF */  sd         $31, 0x8($29)
    /* 3D3124 004D3124 3615130C */  jal        func_004c54d8
    /* 3D3128 004D3128 2D808000 */   daddu     $16, $4, $0
    /* 3D312C 004D312C 524C130C */  jal        func_004d3148
    /* 3D3130 004D3130 2D200002 */   daddu     $4, $16, $0
    /* 3D3134 004D3134 0000B0DF */  ld         $16, 0x0($29)
    /* 3D3138 004D3138 0800BFDF */  ld         $31, 0x8($29)
    /* 3D313C 004D313C 38151308 */  j          func_004c54e0
    /* 3D3140 004D3140 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D3144 004D3144 00000000 */  nop
.size func_004d3118, 0x30
