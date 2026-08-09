.section .text
.set noat
.set noreorder
glabel func_004e0b30
    /* 3E0B30 004E0B30 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3E0B34 004E0B34 2D280000 */  daddu      $5, $0, $0
    /* 3E0B38 004E0B38 B8180624 */  addiu      $6, $0, 0x18B8
    /* 3E0B3C 004E0B3C 0000B0FF */  sd         $16, 0x0($29)
    /* 3E0B40 004E0B40 0800BFFF */  sd         $31, 0x8($29)
    /* 3E0B44 004E0B44 72FE100C */  jal        func_0043f9c8
    /* 3E0B48 004E0B48 2D808000 */   daddu     $16, $4, $0
    /* 3E0B4C 004E0B4C 01000324 */  addiu      $3, $0, 0x1
    /* 3E0B50 004E0B50 01000224 */  addiu      $2, $0, 0x1
    /* 3E0B54 004E0B54 9A1803A6 */  sh         $3, 0x189A($16)
    /* 3E0B58 004E0B58 0C0002A2 */  sb         $2, 0xC($16)
    /* 3E0B5C 004E0B5C 100203AE */  sw         $3, 0x210($16)
    /* 3E0B60 004E0B60 941803AE */  sw         $3, 0x1894($16)
    /* 3E0B64 004E0B64 981800A6 */  sh         $0, 0x1898($16)
    /* 3E0B68 004E0B68 9C1800A6 */  sh         $0, 0x189C($16)
    /* 3E0B6C 004E0B6C 9E1800A6 */  sh         $0, 0x189E($16)
    /* 3E0B70 004E0B70 0800BFDF */  ld         $31, 0x8($29)
    /* 3E0B74 004E0B74 0000B0DF */  ld         $16, 0x0($29)
    /* 3E0B78 004E0B78 0800E003 */  jr         $31
    /* 3E0B7C 004E0B7C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004e0b30, 0x50
