.section .text
.set noat
.set noreorder
glabel func_004d61c0
    /* 3D61C0 004D61C0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D61C4 004D61C4 0000B0FF */  sd         $16, 0x0($29)
    /* 3D61C8 004D61C8 0800BFFF */  sd         $31, 0x8($29)
    /* 3D61CC 004D61CC 3615130C */  jal        func_004c54d8
    /* 3D61D0 004D61D0 2D808000 */   daddu     $16, $4, $0
    /* 3D61D4 004D61D4 7E58130C */  jal        func_004d61f8
    /* 3D61D8 004D61D8 2D200002 */   daddu     $4, $16, $0
    /* 3D61DC 004D61DC 3815130C */  jal        func_004c54e0
    /* 3D61E0 004D61E0 2D804000 */   daddu     $16, $2, $0
    /* 3D61E4 004D61E4 0800BFDF */  ld         $31, 0x8($29)
    /* 3D61E8 004D61E8 2D100002 */  daddu      $2, $16, $0
    /* 3D61EC 004D61EC 0000B0DF */  ld         $16, 0x0($29)
    /* 3D61F0 004D61F0 0800E003 */  jr         $31
    /* 3D61F4 004D61F4 1000BD27 */   addiu     $29, $29, 0x10
.size func_004d61c0, 0x38
