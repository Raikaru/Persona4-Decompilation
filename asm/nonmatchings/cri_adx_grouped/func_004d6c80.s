.section .text
.set noat
.set noreorder
glabel func_004d6c80
    /* 3D6C80 004D6C80 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D6C84 004D6C84 0000B0FF */  sd         $16, 0x0($29)
    /* 3D6C88 004D6C88 0800BFFF */  sd         $31, 0x8($29)
    /* 3D6C8C 004D6C8C 3615130C */  jal        func_004c54d8
    /* 3D6C90 004D6C90 2D808000 */   daddu     $16, $4, $0
    /* 3D6C94 004D6C94 2E5B130C */  jal        func_004d6cb8
    /* 3D6C98 004D6C98 2D200002 */   daddu     $4, $16, $0
    /* 3D6C9C 004D6C9C 3815130C */  jal        func_004c54e0
    /* 3D6CA0 004D6CA0 2D804000 */   daddu     $16, $2, $0
    /* 3D6CA4 004D6CA4 0800BFDF */  ld         $31, 0x8($29)
    /* 3D6CA8 004D6CA8 2D100002 */  daddu      $2, $16, $0
    /* 3D6CAC 004D6CAC 0000B0DF */  ld         $16, 0x0($29)
    /* 3D6CB0 004D6CB0 0800E003 */  jr         $31
    /* 3D6CB4 004D6CB4 1000BD27 */   addiu     $29, $29, 0x10
.size func_004d6c80, 0x38
