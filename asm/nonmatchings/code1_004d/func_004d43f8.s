.section .text
.set noat
.set noreorder
glabel func_004d43f8
    /* 3D43F8 004D43F8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D43FC 004D43FC 0000B0FF */  sd         $16, 0x0($29)
    /* 3D4400 004D4400 0800BFFF */  sd         $31, 0x8($29)
    /* 3D4404 004D4404 3615130C */  jal        func_004c54d8
    /* 3D4408 004D4408 2D808000 */   daddu     $16, $4, $0
    /* 3D440C 004D440C 0C51130C */  jal        func_004d4430
    /* 3D4410 004D4410 2D200002 */   daddu     $4, $16, $0
    /* 3D4414 004D4414 3815130C */  jal        func_004c54e0
    /* 3D4418 004D4418 2D804000 */   daddu     $16, $2, $0
    /* 3D441C 004D441C 0800BFDF */  ld         $31, 0x8($29)
    /* 3D4420 004D4420 2D100002 */  daddu      $2, $16, $0
    /* 3D4424 004D4424 0000B0DF */  ld         $16, 0x0($29)
    /* 3D4428 004D4428 0800E003 */  jr         $31
    /* 3D442C 004D442C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004d43f8, 0x38
