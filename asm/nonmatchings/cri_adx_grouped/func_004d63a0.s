.section .text
.set noat
.set noreorder
glabel func_004d63a0
    /* 3D63A0 004D63A0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3D63A4 004D63A4 0000B0FF */  sd         $16, 0x0($29)
    /* 3D63A8 004D63A8 2D808000 */  daddu      $16, $4, $0
    /* 3D63AC 004D63AC 0800B1FF */  sd         $17, 0x8($29)
    /* 3D63B0 004D63B0 1000BFFF */  sd         $31, 0x10($29)
    /* 3D63B4 004D63B4 3615130C */  jal        func_004c54d8
    /* 3D63B8 004D63B8 2D88A000 */   daddu     $17, $5, $0
    /* 3D63BC 004D63BC 2D200002 */  daddu      $4, $16, $0
    /* 3D63C0 004D63C0 FA58130C */  jal        func_004d63e8
    /* 3D63C4 004D63C4 2D282002 */   daddu     $5, $17, $0
    /* 3D63C8 004D63C8 3815130C */  jal        func_004c54e0
    /* 3D63CC 004D63CC 2D804000 */   daddu     $16, $2, $0
    /* 3D63D0 004D63D0 0800B1DF */  ld         $17, 0x8($29)
    /* 3D63D4 004D63D4 2D100002 */  daddu      $2, $16, $0
    /* 3D63D8 004D63D8 1000BFDF */  ld         $31, 0x10($29)
    /* 3D63DC 004D63DC 0000B0DF */  ld         $16, 0x0($29)
    /* 3D63E0 004D63E0 0800E003 */  jr         $31
    /* 3D63E4 004D63E4 2000BD27 */   addiu     $29, $29, 0x20
.size func_004d63a0, 0x48
