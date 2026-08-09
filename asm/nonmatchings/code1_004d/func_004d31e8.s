.section .text
.set noat
.set noreorder
glabel func_004d31e8
    /* 3D31E8 004D31E8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D31EC 004D31EC 0000B0FF */  sd         $16, 0x0($29)
    /* 3D31F0 004D31F0 0800BFFF */  sd         $31, 0x8($29)
    /* 3D31F4 004D31F4 3246130C */  jal        func_004d18c8
    /* 3D31F8 004D31F8 2D808000 */   daddu     $16, $4, $0
    /* 3D31FC 004D31FC 884C130C */  jal        func_004d3220
    /* 3D3200 004D3200 2D200002 */   daddu     $4, $16, $0
    /* 3D3204 004D3204 3446130C */  jal        func_004d18d0
    /* 3D3208 004D3208 2D804000 */   daddu     $16, $2, $0
    /* 3D320C 004D320C 0800BFDF */  ld         $31, 0x8($29)
    /* 3D3210 004D3210 2D100002 */  daddu      $2, $16, $0
    /* 3D3214 004D3214 0000B0DF */  ld         $16, 0x0($29)
    /* 3D3218 004D3218 0800E003 */  jr         $31
    /* 3D321C 004D321C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004d31e8, 0x38
