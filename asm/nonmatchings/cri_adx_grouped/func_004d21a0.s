.section .text
.set noat
.set noreorder
glabel func_004d21a0
    /* 3D21A0 004D21A0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3D21A4 004D21A4 0000B0FF */  sd         $16, 0x0($29)
    /* 3D21A8 004D21A8 2D808000 */  daddu      $16, $4, $0
    /* 3D21AC 004D21AC 0800B1FF */  sd         $17, 0x8($29)
    /* 3D21B0 004D21B0 1000BFFF */  sd         $31, 0x10($29)
    /* 3D21B4 004D21B4 3246130C */  jal        func_004d18c8
    /* 3D21B8 004D21B8 2D88A000 */   daddu     $17, $5, $0
    /* 3D21BC 004D21BC 2D200002 */  daddu      $4, $16, $0
    /* 3D21C0 004D21C0 7A48130C */  jal        func_004d21e8
    /* 3D21C4 004D21C4 2D282002 */   daddu     $5, $17, $0
    /* 3D21C8 004D21C8 3446130C */  jal        func_004d18d0
    /* 3D21CC 004D21CC 2D804000 */   daddu     $16, $2, $0
    /* 3D21D0 004D21D0 0800B1DF */  ld         $17, 0x8($29)
    /* 3D21D4 004D21D4 2D100002 */  daddu      $2, $16, $0
    /* 3D21D8 004D21D8 1000BFDF */  ld         $31, 0x10($29)
    /* 3D21DC 004D21DC 0000B0DF */  ld         $16, 0x0($29)
    /* 3D21E0 004D21E0 0800E003 */  jr         $31
    /* 3D21E4 004D21E4 2000BD27 */   addiu     $29, $29, 0x20
.size func_004d21a0, 0x48
