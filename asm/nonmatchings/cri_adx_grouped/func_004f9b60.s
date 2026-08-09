.section .text
.set noat
.set noreorder
glabel func_004f9b60
    /* 3F9B60 004F9B60 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3F9B64 004F9B64 0000B0FF */  sd         $16, 0x0($29)
    /* 3F9B68 004F9B68 0800BFFF */  sd         $31, 0x8($29)
    /* 3F9B6C 004F9B6C D4E6130C */  jal        func_004f9b50
    /* 3F9B70 004F9B70 2D808000 */   daddu     $16, $4, $0
    /* 3F9B74 004F9B74 000050AC */  sw         $16, 0x0($2)
    /* 3F9B78 004F9B78 0800BFDF */  ld         $31, 0x8($29)
    /* 3F9B7C 004F9B7C 0000B0DF */  ld         $16, 0x0($29)
    /* 3F9B80 004F9B80 0800E003 */  jr         $31
    /* 3F9B84 004F9B84 1000BD27 */   addiu     $29, $29, 0x10
.size func_004f9b60, 0x28
