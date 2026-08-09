.section .text
.set noat
.set noreorder
glabel func_004d2e10
    /* 3D2E10 004D2E10 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D2E14 004D2E14 0000B0FF */  sd         $16, 0x0($29)
    /* 3D2E18 004D2E18 0800BFFF */  sd         $31, 0x8($29)
    /* 3D2E1C 004D2E1C 3246130C */  jal        func_004d18c8
    /* 3D2E20 004D2E20 2D808000 */   daddu     $16, $4, $0
    /* 3D2E24 004D2E24 924B130C */  jal        func_004d2e48
    /* 3D2E28 004D2E28 2D200002 */   daddu     $4, $16, $0
    /* 3D2E2C 004D2E2C 3446130C */  jal        func_004d18d0
    /* 3D2E30 004D2E30 2D804000 */   daddu     $16, $2, $0
    /* 3D2E34 004D2E34 0800BFDF */  ld         $31, 0x8($29)
    /* 3D2E38 004D2E38 2D100002 */  daddu      $2, $16, $0
    /* 3D2E3C 004D2E3C 0000B0DF */  ld         $16, 0x0($29)
    /* 3D2E40 004D2E40 0800E003 */  jr         $31
    /* 3D2E44 004D2E44 1000BD27 */   addiu     $29, $29, 0x10
.size func_004d2e10, 0x38
