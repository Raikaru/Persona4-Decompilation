.section .text
.set noat
.set noreorder
glabel func_00511a98
    /* 411A98 00511A98 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 411A9C 00511A9C 0000B0FF */  sd         $16, 0x0($29)
    /* 411AA0 00511AA0 2D80A000 */  daddu      $16, $5, $0
    /* 411AA4 00511AA4 0800B1FF */  sd         $17, 0x8($29)
    /* 411AA8 00511AA8 1000BFFF */  sd         $31, 0x10($29)
    /* 411AAC 00511AAC F42C140C */  jal        func_0050b3d0
    /* 411AB0 00511AB0 2D888000 */   daddu     $17, $4, $0
    /* 411AB4 00511AB4 540050AC */  sw         $16, 0x54($2)
    /* 411AB8 00511AB8 500051AC */  sw         $17, 0x50($2)
    /* 411ABC 00511ABC 0000B0DF */  ld         $16, 0x0($29)
    /* 411AC0 00511AC0 0800B1DF */  ld         $17, 0x8($29)
    /* 411AC4 00511AC4 1000BFDF */  ld         $31, 0x10($29)
    /* 411AC8 00511AC8 0800E003 */  jr         $31
    /* 411ACC 00511ACC 2000BD27 */   addiu     $29, $29, 0x20
.size func_00511a98, 0x38
