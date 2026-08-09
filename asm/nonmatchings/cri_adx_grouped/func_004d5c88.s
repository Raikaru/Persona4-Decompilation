.section .text
.set noat
.set noreorder
glabel func_004d5c88
    /* 3D5C88 004D5C88 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D5C8C 004D5C8C 0000B0FF */  sd         $16, 0x0($29)
    /* 3D5C90 004D5C90 0800BFFF */  sd         $31, 0x8($29)
    /* 3D5C94 004D5C94 3615130C */  jal        func_004c54d8
    /* 3D5C98 004D5C98 2D808000 */   daddu     $16, $4, $0
    /* 3D5C9C 004D5C9C 3057130C */  jal        func_004d5cc0
    /* 3D5CA0 004D5CA0 2D200002 */   daddu     $4, $16, $0
    /* 3D5CA4 004D5CA4 3815130C */  jal        func_004c54e0
    /* 3D5CA8 004D5CA8 2D804000 */   daddu     $16, $2, $0
    /* 3D5CAC 004D5CAC 0800BFDF */  ld         $31, 0x8($29)
    /* 3D5CB0 004D5CB0 2D100002 */  daddu      $2, $16, $0
    /* 3D5CB4 004D5CB4 0000B0DF */  ld         $16, 0x0($29)
    /* 3D5CB8 004D5CB8 0800E003 */  jr         $31
    /* 3D5CBC 004D5CBC 1000BD27 */   addiu     $29, $29, 0x10
.size func_004d5c88, 0x38
