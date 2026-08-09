.section .text
.set noat
.set noreorder
glabel func_004d2b08
    /* 3D2B08 004D2B08 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3D2B0C 004D2B0C 0000B0FF */  sd         $16, 0x0($29)
    /* 3D2B10 004D2B10 2D808000 */  daddu      $16, $4, $0
    /* 3D2B14 004D2B14 0800B1FF */  sd         $17, 0x8($29)
    /* 3D2B18 004D2B18 1000BFFF */  sd         $31, 0x10($29)
    /* 3D2B1C 004D2B1C 3246130C */  jal        func_004d18c8
    /* 3D2B20 004D2B20 2D88A000 */   daddu     $17, $5, $0
    /* 3D2B24 004D2B24 2D200002 */  daddu      $4, $16, $0
    /* 3D2B28 004D2B28 D44A130C */  jal        func_004d2b50
    /* 3D2B2C 004D2B2C 2D282002 */   daddu     $5, $17, $0
    /* 3D2B30 004D2B30 3446130C */  jal        func_004d18d0
    /* 3D2B34 004D2B34 2D804000 */   daddu     $16, $2, $0
    /* 3D2B38 004D2B38 0800B1DF */  ld         $17, 0x8($29)
    /* 3D2B3C 004D2B3C 2D100002 */  daddu      $2, $16, $0
    /* 3D2B40 004D2B40 1000BFDF */  ld         $31, 0x10($29)
    /* 3D2B44 004D2B44 0000B0DF */  ld         $16, 0x0($29)
    /* 3D2B48 004D2B48 0800E003 */  jr         $31
    /* 3D2B4C 004D2B4C 2000BD27 */   addiu     $29, $29, 0x20
.size func_004d2b08, 0x48
