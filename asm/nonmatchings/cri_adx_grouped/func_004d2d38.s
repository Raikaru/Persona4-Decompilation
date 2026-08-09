.section .text
.set noat
.set noreorder
glabel func_004d2d38
    /* 3D2D38 004D2D38 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D2D3C 004D2D3C 0000B0FF */  sd         $16, 0x0($29)
    /* 3D2D40 004D2D40 0800BFFF */  sd         $31, 0x8($29)
    /* 3D2D44 004D2D44 3246130C */  jal        func_004d18c8
    /* 3D2D48 004D2D48 2D808000 */   daddu     $16, $4, $0
    /* 3D2D4C 004D2D4C 5C4B130C */  jal        func_004d2d70
    /* 3D2D50 004D2D50 2D200002 */   daddu     $4, $16, $0
    /* 3D2D54 004D2D54 3446130C */  jal        func_004d18d0
    /* 3D2D58 004D2D58 2D804000 */   daddu     $16, $2, $0
    /* 3D2D5C 004D2D5C 0800BFDF */  ld         $31, 0x8($29)
    /* 3D2D60 004D2D60 2D100002 */  daddu      $2, $16, $0
    /* 3D2D64 004D2D64 0000B0DF */  ld         $16, 0x0($29)
    /* 3D2D68 004D2D68 0800E003 */  jr         $31
    /* 3D2D6C 004D2D6C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004d2d38, 0x38
