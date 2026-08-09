.section .text
.set noat
.set noreorder
glabel func_00511d78
    /* 411D78 00511D78 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 411D7C 00511D7C 0000B0FF */  sd         $16, 0x0($29)
    /* 411D80 00511D80 0800BFFF */  sd         $31, 0x8($29)
    /* 411D84 00511D84 F42C140C */  jal        func_0050b3d0
    /* 411D88 00511D88 2D808000 */   daddu     $16, $4, $0
    /* 411D8C 00511D8C 580050AC */  sw         $16, 0x58($2)
    /* 411D90 00511D90 0800BFDF */  ld         $31, 0x8($29)
    /* 411D94 00511D94 0000B0DF */  ld         $16, 0x0($29)
    /* 411D98 00511D98 0800E003 */  jr         $31
    /* 411D9C 00511D9C 1000BD27 */   addiu     $29, $29, 0x10
.size func_00511d78, 0x28
