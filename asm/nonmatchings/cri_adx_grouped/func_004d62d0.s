.section .text
.set noat
.set noreorder
glabel func_004d62d0
    /* 3D62D0 004D62D0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D62D4 004D62D4 0000B0FF */  sd         $16, 0x0($29)
    /* 3D62D8 004D62D8 0800BFFF */  sd         $31, 0x8($29)
    /* 3D62DC 004D62DC 3615130C */  jal        func_004c54d8
    /* 3D62E0 004D62E0 2D808000 */   daddu     $16, $4, $0
    /* 3D62E4 004D62E4 C258130C */  jal        func_004d6308
    /* 3D62E8 004D62E8 2D200002 */   daddu     $4, $16, $0
    /* 3D62EC 004D62EC 3815130C */  jal        func_004c54e0
    /* 3D62F0 004D62F0 2D804000 */   daddu     $16, $2, $0
    /* 3D62F4 004D62F4 0800BFDF */  ld         $31, 0x8($29)
    /* 3D62F8 004D62F8 2D100002 */  daddu      $2, $16, $0
    /* 3D62FC 004D62FC 0000B0DF */  ld         $16, 0x0($29)
    /* 3D6300 004D6300 0800E003 */  jr         $31
    /* 3D6304 004D6304 1000BD27 */   addiu     $29, $29, 0x10
.size func_004d62d0, 0x38
