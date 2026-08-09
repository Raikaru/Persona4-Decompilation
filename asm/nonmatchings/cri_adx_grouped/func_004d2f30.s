.section .text
.set noat
.set noreorder
glabel func_004d2f30
    /* 3D2F30 004D2F30 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3D2F34 004D2F34 0000B0FF */  sd         $16, 0x0($29)
    /* 3D2F38 004D2F38 2D808000 */  daddu      $16, $4, $0
    /* 3D2F3C 004D2F3C 0800B1FF */  sd         $17, 0x8($29)
    /* 3D2F40 004D2F40 1000BFFF */  sd         $31, 0x10($29)
    /* 3D2F44 004D2F44 3246130C */  jal        func_004d18c8
    /* 3D2F48 004D2F48 2D88A000 */   daddu     $17, $5, $0
    /* 3D2F4C 004D2F4C 2D200002 */  daddu      $4, $16, $0
    /* 3D2F50 004D2F50 DE4B130C */  jal        func_004d2f78
    /* 3D2F54 004D2F54 2D282002 */   daddu     $5, $17, $0
    /* 3D2F58 004D2F58 3446130C */  jal        func_004d18d0
    /* 3D2F5C 004D2F5C 2D804000 */   daddu     $16, $2, $0
    /* 3D2F60 004D2F60 0800B1DF */  ld         $17, 0x8($29)
    /* 3D2F64 004D2F64 2D100002 */  daddu      $2, $16, $0
    /* 3D2F68 004D2F68 1000BFDF */  ld         $31, 0x10($29)
    /* 3D2F6C 004D2F6C 0000B0DF */  ld         $16, 0x0($29)
    /* 3D2F70 004D2F70 0800E003 */  jr         $31
    /* 3D2F74 004D2F74 2000BD27 */   addiu     $29, $29, 0x20
.size func_004d2f30, 0x48
