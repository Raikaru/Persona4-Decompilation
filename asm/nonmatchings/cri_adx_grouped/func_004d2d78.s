.section .text
.set noat
.set noreorder
glabel func_004d2d78
    /* 3D2D78 004D2D78 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D2D7C 004D2D7C 0000B0FF */  sd         $16, 0x0($29)
    /* 3D2D80 004D2D80 0800BFFF */  sd         $31, 0x8($29)
    /* 3D2D84 004D2D84 3246130C */  jal        func_004d18c8
    /* 3D2D88 004D2D88 2D808000 */   daddu     $16, $4, $0
    /* 3D2D8C 004D2D8C 6C4B130C */  jal        func_004d2db0
    /* 3D2D90 004D2D90 2D200002 */   daddu     $4, $16, $0
    /* 3D2D94 004D2D94 3446130C */  jal        func_004d18d0
    /* 3D2D98 004D2D98 2D804000 */   daddu     $16, $2, $0
    /* 3D2D9C 004D2D9C 0800BFDF */  ld         $31, 0x8($29)
    /* 3D2DA0 004D2DA0 2D100002 */  daddu      $2, $16, $0
    /* 3D2DA4 004D2DA4 0000B0DF */  ld         $16, 0x0($29)
    /* 3D2DA8 004D2DA8 0800E003 */  jr         $31
    /* 3D2DAC 004D2DAC 1000BD27 */   addiu     $29, $29, 0x10
.size func_004d2d78, 0x38
