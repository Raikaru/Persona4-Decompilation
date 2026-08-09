.section .text
.set noat
.set noreorder
glabel func_004d2bf0
    /* 3D2BF0 004D2BF0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D2BF4 004D2BF4 0000B0FF */  sd         $16, 0x0($29)
    /* 3D2BF8 004D2BF8 0800BFFF */  sd         $31, 0x8($29)
    /* 3D2BFC 004D2BFC 3246130C */  jal        func_004d18c8
    /* 3D2C00 004D2C00 2D808000 */   daddu     $16, $4, $0
    /* 3D2C04 004D2C04 0A4B130C */  jal        func_004d2c28
    /* 3D2C08 004D2C08 2D200002 */   daddu     $4, $16, $0
    /* 3D2C0C 004D2C0C 3446130C */  jal        func_004d18d0
    /* 3D2C10 004D2C10 2D804000 */   daddu     $16, $2, $0
    /* 3D2C14 004D2C14 0800BFDF */  ld         $31, 0x8($29)
    /* 3D2C18 004D2C18 2D100002 */  daddu      $2, $16, $0
    /* 3D2C1C 004D2C1C 0000B0DF */  ld         $16, 0x0($29)
    /* 3D2C20 004D2C20 0800E003 */  jr         $31
    /* 3D2C24 004D2C24 1000BD27 */   addiu     $29, $29, 0x10
.size func_004d2bf0, 0x38
