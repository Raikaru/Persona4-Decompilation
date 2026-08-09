.section .text
.set noat
.set noreorder
glabel func_004d2b50
    /* 3D2B50 004D2B50 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D2B54 004D2B54 0000B0FF */  sd         $16, 0x0($29)
    /* 3D2B58 004D2B58 0800BFFF */  sd         $31, 0x8($29)
    /* 3D2B5C 004D2B5C 2848130C */  jal        func_004d20a0
    /* 3D2B60 004D2B60 2D80A000 */   daddu     $16, $5, $0
    /* 3D2B64 004D2B64 000002AE */  sw         $2, 0x0($16)
    /* 3D2B68 004D2B68 01000224 */  addiu      $2, $0, 0x1
    /* 3D2B6C 004D2B6C 0000B0DF */  ld         $16, 0x0($29)
    /* 3D2B70 004D2B70 0800BFDF */  ld         $31, 0x8($29)
    /* 3D2B74 004D2B74 0800E003 */  jr         $31
    /* 3D2B78 004D2B78 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D2B7C 004D2B7C 00000000 */  nop
.size func_004d2b50, 0x30
