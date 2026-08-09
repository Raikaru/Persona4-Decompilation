.section .text
.set noat
.set noreorder
glabel func_004d3228
    /* 3D3228 004D3228 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D322C 004D322C 0000B0FF */  sd         $16, 0x0($29)
    /* 3D3230 004D3230 0800BFFF */  sd         $31, 0x8($29)
    /* 3D3234 004D3234 3246130C */  jal        func_004d18c8
    /* 3D3238 004D3238 2D808000 */   daddu     $16, $4, $0
    /* 3D323C 004D323C 964C130C */  jal        func_004d3258
    /* 3D3240 004D3240 2D200002 */   daddu     $4, $16, $0
    /* 3D3244 004D3244 0000B0DF */  ld         $16, 0x0($29)
    /* 3D3248 004D3248 0800BFDF */  ld         $31, 0x8($29)
    /* 3D324C 004D324C 34461308 */  j          func_004d18d0
    /* 3D3250 004D3250 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D3254 004D3254 00000000 */  nop
.size func_004d3228, 0x30
