.section .text
.set noat
.set noreorder
glabel func_004d4d68
    /* 3D4D68 004D4D68 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D4D6C 004D4D6C 0000B0FF */  sd         $16, 0x0($29)
    /* 3D4D70 004D4D70 0800BFFF */  sd         $31, 0x8($29)
    /* 3D4D74 004D4D74 3615130C */  jal        func_004c54d8
    /* 3D4D78 004D4D78 2D808000 */   daddu     $16, $4, $0
    /* 3D4D7C 004D4D7C 6853130C */  jal        func_004d4da0
    /* 3D4D80 004D4D80 2D200002 */   daddu     $4, $16, $0
    /* 3D4D84 004D4D84 3815130C */  jal        func_004c54e0
    /* 3D4D88 004D4D88 2D804000 */   daddu     $16, $2, $0
    /* 3D4D8C 004D4D8C 0800BFDF */  ld         $31, 0x8($29)
    /* 3D4D90 004D4D90 2D100002 */  daddu      $2, $16, $0
    /* 3D4D94 004D4D94 0000B0DF */  ld         $16, 0x0($29)
    /* 3D4D98 004D4D98 0800E003 */  jr         $31
    /* 3D4D9C 004D4D9C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004d4d68, 0x38
