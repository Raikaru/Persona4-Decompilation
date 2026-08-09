.section .text
.set noat
.set noreorder
glabel func_004d5fe8
    /* 3D5FE8 004D5FE8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D5FEC 004D5FEC 0000B0FF */  sd         $16, 0x0($29)
    /* 3D5FF0 004D5FF0 0800BFFF */  sd         $31, 0x8($29)
    /* 3D5FF4 004D5FF4 3615130C */  jal        func_004c54d8
    /* 3D5FF8 004D5FF8 2D808000 */   daddu     $16, $4, $0
    /* 3D5FFC 004D5FFC 0858130C */  jal        func_004d6020
    /* 3D6000 004D6000 2D200002 */   daddu     $4, $16, $0
    /* 3D6004 004D6004 3815130C */  jal        func_004c54e0
    /* 3D6008 004D6008 2D804000 */   daddu     $16, $2, $0
    /* 3D600C 004D600C 0800BFDF */  ld         $31, 0x8($29)
    /* 3D6010 004D6010 2D100002 */  daddu      $2, $16, $0
    /* 3D6014 004D6014 0000B0DF */  ld         $16, 0x0($29)
    /* 3D6018 004D6018 0800E003 */  jr         $31
    /* 3D601C 004D601C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004d5fe8, 0x38
