.section .text
.set noat
.set noreorder
glabel func_004d4c58
    /* 3D4C58 004D4C58 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D4C5C 004D4C5C 0000B0FF */  sd         $16, 0x0($29)
    /* 3D4C60 004D4C60 0800BFFF */  sd         $31, 0x8($29)
    /* 3D4C64 004D4C64 3615130C */  jal        func_004c54d8
    /* 3D4C68 004D4C68 2D808000 */   daddu     $16, $4, $0
    /* 3D4C6C 004D4C6C 2453130C */  jal        func_004d4c90
    /* 3D4C70 004D4C70 2D200002 */   daddu     $4, $16, $0
    /* 3D4C74 004D4C74 3815130C */  jal        func_004c54e0
    /* 3D4C78 004D4C78 2D804000 */   daddu     $16, $2, $0
    /* 3D4C7C 004D4C7C 0800BFDF */  ld         $31, 0x8($29)
    /* 3D4C80 004D4C80 2D100002 */  daddu      $2, $16, $0
    /* 3D4C84 004D4C84 0000B0DF */  ld         $16, 0x0($29)
    /* 3D4C88 004D4C88 0800E003 */  jr         $31
    /* 3D4C8C 004D4C8C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004d4c58, 0x38
