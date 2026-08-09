.section .text
.set noat
.set noreorder
glabel func_004d5f10
    /* 3D5F10 004D5F10 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D5F14 004D5F14 0000B0FF */  sd         $16, 0x0($29)
    /* 3D5F18 004D5F18 0800BFFF */  sd         $31, 0x8($29)
    /* 3D5F1C 004D5F1C 3615130C */  jal        func_004c54d8
    /* 3D5F20 004D5F20 2D808000 */   daddu     $16, $4, $0
    /* 3D5F24 004D5F24 D257130C */  jal        func_004d5f48
    /* 3D5F28 004D5F28 2D200002 */   daddu     $4, $16, $0
    /* 3D5F2C 004D5F2C 3815130C */  jal        func_004c54e0
    /* 3D5F30 004D5F30 2D804000 */   daddu     $16, $2, $0
    /* 3D5F34 004D5F34 0800BFDF */  ld         $31, 0x8($29)
    /* 3D5F38 004D5F38 2D100002 */  daddu      $2, $16, $0
    /* 3D5F3C 004D5F3C 0000B0DF */  ld         $16, 0x0($29)
    /* 3D5F40 004D5F40 0800E003 */  jr         $31
    /* 3D5F44 004D5F44 1000BD27 */   addiu     $29, $29, 0x10
.size func_004d5f10, 0x38
