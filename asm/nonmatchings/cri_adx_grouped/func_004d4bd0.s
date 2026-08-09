.section .text
.set noat
.set noreorder
glabel func_004d4bd0
    /* 3D4BD0 004D4BD0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D4BD4 004D4BD4 0000B0FF */  sd         $16, 0x0($29)
    /* 3D4BD8 004D4BD8 0800BFFF */  sd         $31, 0x8($29)
    /* 3D4BDC 004D4BDC 3615130C */  jal        func_004c54d8
    /* 3D4BE0 004D4BE0 2D808000 */   daddu     $16, $4, $0
    /* 3D4BE4 004D4BE4 0253130C */  jal        func_004d4c08
    /* 3D4BE8 004D4BE8 2D200002 */   daddu     $4, $16, $0
    /* 3D4BEC 004D4BEC 3815130C */  jal        func_004c54e0
    /* 3D4BF0 004D4BF0 2D804000 */   daddu     $16, $2, $0
    /* 3D4BF4 004D4BF4 0800BFDF */  ld         $31, 0x8($29)
    /* 3D4BF8 004D4BF8 2D100002 */  daddu      $2, $16, $0
    /* 3D4BFC 004D4BFC 0000B0DF */  ld         $16, 0x0($29)
    /* 3D4C00 004D4C00 0800E003 */  jr         $31
    /* 3D4C04 004D4C04 1000BD27 */   addiu     $29, $29, 0x10
.size func_004d4bd0, 0x38
