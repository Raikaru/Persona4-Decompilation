.section .text
.set noat
.set noreorder
glabel func_004d4b48
    /* 3D4B48 004D4B48 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D4B4C 004D4B4C 0000B0FF */  sd         $16, 0x0($29)
    /* 3D4B50 004D4B50 0800BFFF */  sd         $31, 0x8($29)
    /* 3D4B54 004D4B54 3615130C */  jal        func_004c54d8
    /* 3D4B58 004D4B58 2D808000 */   daddu     $16, $4, $0
    /* 3D4B5C 004D4B5C E052130C */  jal        func_004d4b80
    /* 3D4B60 004D4B60 2D200002 */   daddu     $4, $16, $0
    /* 3D4B64 004D4B64 3815130C */  jal        func_004c54e0
    /* 3D4B68 004D4B68 2D804000 */   daddu     $16, $2, $0
    /* 3D4B6C 004D4B6C 0800BFDF */  ld         $31, 0x8($29)
    /* 3D4B70 004D4B70 2D100002 */  daddu      $2, $16, $0
    /* 3D4B74 004D4B74 0000B0DF */  ld         $16, 0x0($29)
    /* 3D4B78 004D4B78 0800E003 */  jr         $31
    /* 3D4B7C 004D4B7C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004d4b48, 0x38
