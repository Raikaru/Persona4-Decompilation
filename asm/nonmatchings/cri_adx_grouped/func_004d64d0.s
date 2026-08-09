.section .text
.set noat
.set noreorder
glabel func_004d64d0
    /* 3D64D0 004D64D0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D64D4 004D64D4 0000B0FF */  sd         $16, 0x0($29)
    /* 3D64D8 004D64D8 0800BFFF */  sd         $31, 0x8($29)
    /* 3D64DC 004D64DC 3615130C */  jal        func_004c54d8
    /* 3D64E0 004D64E0 2D808000 */   daddu     $16, $4, $0
    /* 3D64E4 004D64E4 4259130C */  jal        func_004d6508
    /* 3D64E8 004D64E8 2D200002 */   daddu     $4, $16, $0
    /* 3D64EC 004D64EC 3815130C */  jal        func_004c54e0
    /* 3D64F0 004D64F0 2D804000 */   daddu     $16, $2, $0
    /* 3D64F4 004D64F4 0800BFDF */  ld         $31, 0x8($29)
    /* 3D64F8 004D64F8 2D100002 */  daddu      $2, $16, $0
    /* 3D64FC 004D64FC 0000B0DF */  ld         $16, 0x0($29)
    /* 3D6500 004D6500 0800E003 */  jr         $31
    /* 3D6504 004D6504 1000BD27 */   addiu     $29, $29, 0x10
.size func_004d64d0, 0x38
