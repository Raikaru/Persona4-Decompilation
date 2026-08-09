.section .text
.set noat
.set noreorder
glabel func_004d1c58
    /* 3D1C58 004D1C58 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3D1C5C 004D1C5C 0000B0FF */  sd         $16, 0x0($29)
    /* 3D1C60 004D1C60 2D808000 */  daddu      $16, $4, $0
    /* 3D1C64 004D1C64 0800B1FF */  sd         $17, 0x8($29)
    /* 3D1C68 004D1C68 1000BFFF */  sd         $31, 0x10($29)
    /* 3D1C6C 004D1C6C 3246130C */  jal        func_004d18c8
    /* 3D1C70 004D1C70 2D88A000 */   daddu     $17, $5, $0
    /* 3D1C74 004D1C74 2D200002 */  daddu      $4, $16, $0
    /* 3D1C78 004D1C78 2847130C */  jal        func_004d1ca0
    /* 3D1C7C 004D1C7C 2D282002 */   daddu     $5, $17, $0
    /* 3D1C80 004D1C80 3446130C */  jal        func_004d18d0
    /* 3D1C84 004D1C84 2D804000 */   daddu     $16, $2, $0
    /* 3D1C88 004D1C88 0800B1DF */  ld         $17, 0x8($29)
    /* 3D1C8C 004D1C8C 2D100002 */  daddu      $2, $16, $0
    /* 3D1C90 004D1C90 1000BFDF */  ld         $31, 0x10($29)
    /* 3D1C94 004D1C94 0000B0DF */  ld         $16, 0x0($29)
    /* 3D1C98 004D1C98 0800E003 */  jr         $31
    /* 3D1C9C 004D1C9C 2000BD27 */   addiu     $29, $29, 0x20
.size func_004d1c58, 0x48
