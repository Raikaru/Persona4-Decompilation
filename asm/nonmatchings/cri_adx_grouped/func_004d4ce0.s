.section .text
.set noat
.set noreorder
glabel func_004d4ce0
    /* 3D4CE0 004D4CE0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D4CE4 004D4CE4 0000B0FF */  sd         $16, 0x0($29)
    /* 3D4CE8 004D4CE8 0800BFFF */  sd         $31, 0x8($29)
    /* 3D4CEC 004D4CEC 3615130C */  jal        func_004c54d8
    /* 3D4CF0 004D4CF0 2D808000 */   daddu     $16, $4, $0
    /* 3D4CF4 004D4CF4 4653130C */  jal        func_004d4d18
    /* 3D4CF8 004D4CF8 2D200002 */   daddu     $4, $16, $0
    /* 3D4CFC 004D4CFC 3815130C */  jal        func_004c54e0
    /* 3D4D00 004D4D00 2D804000 */   daddu     $16, $2, $0
    /* 3D4D04 004D4D04 0800BFDF */  ld         $31, 0x8($29)
    /* 3D4D08 004D4D08 2D100002 */  daddu      $2, $16, $0
    /* 3D4D0C 004D4D0C 0000B0DF */  ld         $16, 0x0($29)
    /* 3D4D10 004D4D10 0800E003 */  jr         $31
    /* 3D4D14 004D4D14 1000BD27 */   addiu     $29, $29, 0x10
.size func_004d4ce0, 0x38
