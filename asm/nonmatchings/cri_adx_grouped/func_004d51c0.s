.section .text
.set noat
.set noreorder
glabel func_004d51c0
    /* 3D51C0 004D51C0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D51C4 004D51C4 0000B0FF */  sd         $16, 0x0($29)
    /* 3D51C8 004D51C8 0800BFFF */  sd         $31, 0x8($29)
    /* 3D51CC 004D51CC 3615130C */  jal        func_004c54d8
    /* 3D51D0 004D51D0 2D808000 */   daddu     $16, $4, $0
    /* 3D51D4 004D51D4 7E54130C */  jal        func_004d51f8
    /* 3D51D8 004D51D8 2D200002 */   daddu     $4, $16, $0
    /* 3D51DC 004D51DC 3815130C */  jal        func_004c54e0
    /* 3D51E0 004D51E0 2D804000 */   daddu     $16, $2, $0
    /* 3D51E4 004D51E4 0800BFDF */  ld         $31, 0x8($29)
    /* 3D51E8 004D51E8 2D100002 */  daddu      $2, $16, $0
    /* 3D51EC 004D51EC 0000B0DF */  ld         $16, 0x0($29)
    /* 3D51F0 004D51F0 0800E003 */  jr         $31
    /* 3D51F4 004D51F4 1000BD27 */   addiu     $29, $29, 0x10
.size func_004d51c0, 0x38
