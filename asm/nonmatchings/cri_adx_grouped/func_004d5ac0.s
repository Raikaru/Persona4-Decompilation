.section .text
.set noat
.set noreorder
glabel func_004d5ac0
    /* 3D5AC0 004D5AC0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D5AC4 004D5AC4 0000B0FF */  sd         $16, 0x0($29)
    /* 3D5AC8 004D5AC8 0800BFFF */  sd         $31, 0x8($29)
    /* 3D5ACC 004D5ACC 3615130C */  jal        func_004c54d8
    /* 3D5AD0 004D5AD0 2D808000 */   daddu     $16, $4, $0
    /* 3D5AD4 004D5AD4 BE56130C */  jal        func_004d5af8
    /* 3D5AD8 004D5AD8 2D200002 */   daddu     $4, $16, $0
    /* 3D5ADC 004D5ADC 3815130C */  jal        func_004c54e0
    /* 3D5AE0 004D5AE0 2D804000 */   daddu     $16, $2, $0
    /* 3D5AE4 004D5AE4 0800BFDF */  ld         $31, 0x8($29)
    /* 3D5AE8 004D5AE8 2D100002 */  daddu      $2, $16, $0
    /* 3D5AEC 004D5AEC 0000B0DF */  ld         $16, 0x0($29)
    /* 3D5AF0 004D5AF0 0800E003 */  jr         $31
    /* 3D5AF4 004D5AF4 1000BD27 */   addiu     $29, $29, 0x10
.size func_004d5ac0, 0x38
