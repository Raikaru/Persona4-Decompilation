.section .text
.set noat
.set noreorder
glabel func_004d5d60
    /* 3D5D60 004D5D60 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D5D64 004D5D64 0000B0FF */  sd         $16, 0x0($29)
    /* 3D5D68 004D5D68 0800BFFF */  sd         $31, 0x8($29)
    /* 3D5D6C 004D5D6C 3615130C */  jal        func_004c54d8
    /* 3D5D70 004D5D70 2D808000 */   daddu     $16, $4, $0
    /* 3D5D74 004D5D74 6657130C */  jal        func_004d5d98
    /* 3D5D78 004D5D78 2D200002 */   daddu     $4, $16, $0
    /* 3D5D7C 004D5D7C 3815130C */  jal        func_004c54e0
    /* 3D5D80 004D5D80 2D804000 */   daddu     $16, $2, $0
    /* 3D5D84 004D5D84 0800BFDF */  ld         $31, 0x8($29)
    /* 3D5D88 004D5D88 2D100002 */  daddu      $2, $16, $0
    /* 3D5D8C 004D5D8C 0000B0DF */  ld         $16, 0x0($29)
    /* 3D5D90 004D5D90 0800E003 */  jr         $31
    /* 3D5D94 004D5D94 1000BD27 */   addiu     $29, $29, 0x10
.size func_004d5d60, 0x38
