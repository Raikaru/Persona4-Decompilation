.section .text
.set noat
.set noreorder
glabel func_004d2c30
    /* 3D2C30 004D2C30 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3D2C34 004D2C34 0000B0FF */  sd         $16, 0x0($29)
    /* 3D2C38 004D2C38 2D808000 */  daddu      $16, $4, $0
    /* 3D2C3C 004D2C3C 0800B1FF */  sd         $17, 0x8($29)
    /* 3D2C40 004D2C40 2D88A000 */  daddu      $17, $5, $0
    /* 3D2C44 004D2C44 1000B2FF */  sd         $18, 0x10($29)
    /* 3D2C48 004D2C48 1800BFFF */  sd         $31, 0x18($29)
    /* 3D2C4C 004D2C4C 3246130C */  jal        func_004d18c8
    /* 3D2C50 004D2C50 2D90C000 */   daddu     $18, $6, $0
    /* 3D2C54 004D2C54 2D200002 */  daddu      $4, $16, $0
    /* 3D2C58 004D2C58 2D282002 */  daddu      $5, $17, $0
    /* 3D2C5C 004D2C5C 224B130C */  jal        func_004d2c88
    /* 3D2C60 004D2C60 2D304002 */   daddu     $6, $18, $0
    /* 3D2C64 004D2C64 3446130C */  jal        func_004d18d0
    /* 3D2C68 004D2C68 2D804000 */   daddu     $16, $2, $0
    /* 3D2C6C 004D2C6C 0800B1DF */  ld         $17, 0x8($29)
    /* 3D2C70 004D2C70 2D100002 */  daddu      $2, $16, $0
    /* 3D2C74 004D2C74 1000B2DF */  ld         $18, 0x10($29)
    /* 3D2C78 004D2C78 0000B0DF */  ld         $16, 0x0($29)
    /* 3D2C7C 004D2C7C 1800BFDF */  ld         $31, 0x18($29)
    /* 3D2C80 004D2C80 0800E003 */  jr         $31
    /* 3D2C84 004D2C84 2000BD27 */   addiu     $29, $29, 0x20
.size func_004d2c30, 0x58
