.section .text
.set noat
.set noreorder
glabel func_004d66d8
    /* 3D66D8 004D66D8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D66DC 004D66DC 0000B0FF */  sd         $16, 0x0($29)
    /* 3D66E0 004D66E0 0800BFFF */  sd         $31, 0x8($29)
    /* 3D66E4 004D66E4 3615130C */  jal        func_004c54d8
    /* 3D66E8 004D66E8 2D808000 */   daddu     $16, $4, $0
    /* 3D66EC 004D66EC C459130C */  jal        func_004d6710
    /* 3D66F0 004D66F0 2D200002 */   daddu     $4, $16, $0
    /* 3D66F4 004D66F4 3815130C */  jal        func_004c54e0
    /* 3D66F8 004D66F8 2D804000 */   daddu     $16, $2, $0
    /* 3D66FC 004D66FC 0800BFDF */  ld         $31, 0x8($29)
    /* 3D6700 004D6700 2D100002 */  daddu      $2, $16, $0
    /* 3D6704 004D6704 0000B0DF */  ld         $16, 0x0($29)
    /* 3D6708 004D6708 0800E003 */  jr         $31
    /* 3D670C 004D670C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004d66d8, 0x38
