.section .text
.set noat
.set noreorder
glabel func_004d2b80
    /* 3D2B80 004D2B80 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3D2B84 004D2B84 0000B0FF */  sd         $16, 0x0($29)
    /* 3D2B88 004D2B88 2D808000 */  daddu      $16, $4, $0
    /* 3D2B8C 004D2B8C 0800B1FF */  sd         $17, 0x8($29)
    /* 3D2B90 004D2B90 2D88A000 */  daddu      $17, $5, $0
    /* 3D2B94 004D2B94 1000B2FF */  sd         $18, 0x10($29)
    /* 3D2B98 004D2B98 1800BFFF */  sd         $31, 0x18($29)
    /* 3D2B9C 004D2B9C 3246130C */  jal        func_004d18c8
    /* 3D2BA0 004D2BA0 2D90C000 */   daddu     $18, $6, $0
    /* 3D2BA4 004D2BA4 2D200002 */  daddu      $4, $16, $0
    /* 3D2BA8 004D2BA8 2D282002 */  daddu      $5, $17, $0
    /* 3D2BAC 004D2BAC F64A130C */  jal        func_004d2bd8
    /* 3D2BB0 004D2BB0 2D304002 */   daddu     $6, $18, $0
    /* 3D2BB4 004D2BB4 3446130C */  jal        func_004d18d0
    /* 3D2BB8 004D2BB8 2D804000 */   daddu     $16, $2, $0
    /* 3D2BBC 004D2BBC 0800B1DF */  ld         $17, 0x8($29)
    /* 3D2BC0 004D2BC0 2D100002 */  daddu      $2, $16, $0
    /* 3D2BC4 004D2BC4 1000B2DF */  ld         $18, 0x10($29)
    /* 3D2BC8 004D2BC8 0000B0DF */  ld         $16, 0x0($29)
    /* 3D2BCC 004D2BCC 1800BFDF */  ld         $31, 0x18($29)
    /* 3D2BD0 004D2BD0 0800E003 */  jr         $31
    /* 3D2BD4 004D2BD4 2000BD27 */   addiu     $29, $29, 0x20
.size func_004d2b80, 0x58
