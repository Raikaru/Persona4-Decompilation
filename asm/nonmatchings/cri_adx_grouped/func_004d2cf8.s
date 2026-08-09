.section .text
.set noat
.set noreorder
glabel func_004d2cf8
    /* 3D2CF8 004D2CF8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D2CFC 004D2CFC 0000B0FF */  sd         $16, 0x0($29)
    /* 3D2D00 004D2D00 0800BFFF */  sd         $31, 0x8($29)
    /* 3D2D04 004D2D04 3246130C */  jal        func_004d18c8
    /* 3D2D08 004D2D08 2D808000 */   daddu     $16, $4, $0
    /* 3D2D0C 004D2D0C 4C4B130C */  jal        func_004d2d30
    /* 3D2D10 004D2D10 2D200002 */   daddu     $4, $16, $0
    /* 3D2D14 004D2D14 3446130C */  jal        func_004d18d0
    /* 3D2D18 004D2D18 2D804000 */   daddu     $16, $2, $0
    /* 3D2D1C 004D2D1C 0800BFDF */  ld         $31, 0x8($29)
    /* 3D2D20 004D2D20 2D100002 */  daddu      $2, $16, $0
    /* 3D2D24 004D2D24 0000B0DF */  ld         $16, 0x0($29)
    /* 3D2D28 004D2D28 0800E003 */  jr         $31
    /* 3D2D2C 004D2D2C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004d2cf8, 0x38
