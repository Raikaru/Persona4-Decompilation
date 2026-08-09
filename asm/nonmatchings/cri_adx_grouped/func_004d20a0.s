.section .text
.set noat
.set noreorder
glabel func_004d20a0
    /* 3D20A0 004D20A0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D20A4 004D20A4 0000B0FF */  sd         $16, 0x0($29)
    /* 3D20A8 004D20A8 0800BFFF */  sd         $31, 0x8($29)
    /* 3D20AC 004D20AC 3246130C */  jal        func_004d18c8
    /* 3D20B0 004D20B0 2D808000 */   daddu     $16, $4, $0
    /* 3D20B4 004D20B4 3648130C */  jal        func_004d20d8
    /* 3D20B8 004D20B8 2D200002 */   daddu     $4, $16, $0
    /* 3D20BC 004D20BC 3446130C */  jal        func_004d18d0
    /* 3D20C0 004D20C0 2D804000 */   daddu     $16, $2, $0
    /* 3D20C4 004D20C4 0800BFDF */  ld         $31, 0x8($29)
    /* 3D20C8 004D20C8 2D100002 */  daddu      $2, $16, $0
    /* 3D20CC 004D20CC 0000B0DF */  ld         $16, 0x0($29)
    /* 3D20D0 004D20D0 0800E003 */  jr         $31
    /* 3D20D4 004D20D4 1000BD27 */   addiu     $29, $29, 0x10
.size func_004d20a0, 0x38
