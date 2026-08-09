.section .text
.set noat
.set noreorder
glabel func_004d31a0
    /* 3D31A0 004D31A0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D31A4 004D31A4 0000B0FF */  sd         $16, 0x0($29)
    /* 3D31A8 004D31A8 0800BFFF */  sd         $31, 0x8($29)
    /* 3D31AC 004D31AC 3615130C */  jal        func_004c54d8
    /* 3D31B0 004D31B0 2D808000 */   daddu     $16, $4, $0
    /* 3D31B4 004D31B4 764C130C */  jal        func_004d31d8
    /* 3D31B8 004D31B8 2D200002 */   daddu     $4, $16, $0
    /* 3D31BC 004D31BC 3815130C */  jal        func_004c54e0
    /* 3D31C0 004D31C0 2D804000 */   daddu     $16, $2, $0
    /* 3D31C4 004D31C4 0800BFDF */  ld         $31, 0x8($29)
    /* 3D31C8 004D31C8 2D100002 */  daddu      $2, $16, $0
    /* 3D31CC 004D31CC 0000B0DF */  ld         $16, 0x0($29)
    /* 3D31D0 004D31D0 0800E003 */  jr         $31
    /* 3D31D4 004D31D4 1000BD27 */   addiu     $29, $29, 0x10
.size func_004d31a0, 0x38
