.section .text
.set noat
.set noreorder
glabel func_004d50a8
    /* 3D50A8 004D50A8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D50AC 004D50AC 0000B0FF */  sd         $16, 0x0($29)
    /* 3D50B0 004D50B0 0800BFFF */  sd         $31, 0x8($29)
    /* 3D50B4 004D50B4 3615130C */  jal        func_004c54d8
    /* 3D50B8 004D50B8 2D808000 */   daddu     $16, $4, $0
    /* 3D50BC 004D50BC 3854130C */  jal        func_004d50e0
    /* 3D50C0 004D50C0 2D200002 */   daddu     $4, $16, $0
    /* 3D50C4 004D50C4 3815130C */  jal        func_004c54e0
    /* 3D50C8 004D50C8 2D804000 */   daddu     $16, $2, $0
    /* 3D50CC 004D50CC 0800BFDF */  ld         $31, 0x8($29)
    /* 3D50D0 004D50D0 2D100002 */  daddu      $2, $16, $0
    /* 3D50D4 004D50D4 0000B0DF */  ld         $16, 0x0($29)
    /* 3D50D8 004D50D8 0800E003 */  jr         $31
    /* 3D50DC 004D50DC 1000BD27 */   addiu     $29, $29, 0x10
.size func_004d50a8, 0x38
