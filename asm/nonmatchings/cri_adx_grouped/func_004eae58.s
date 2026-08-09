.section .text
.set noat
.set noreorder
glabel func_004eae58
    /* 3EAE58 004EAE58 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3EAE5C 004EAE5C 0000B0FF */  sd         $16, 0x0($29)
    /* 3EAE60 004EAE60 2D808000 */  daddu      $16, $4, $0
    /* 3EAE64 004EAE64 0800B1FF */  sd         $17, 0x8($29)
    /* 3EAE68 004EAE68 2D88A000 */  daddu      $17, $5, $0
    /* 3EAE6C 004EAE6C 1000B2FF */  sd         $18, 0x10($29)
    /* 3EAE70 004EAE70 1800BFFF */  sd         $31, 0x18($29)
    /* 3EAE74 004EAE74 C4A9130C */  jal        func_004ea710
    /* 3EAE78 004EAE78 2D90C000 */   daddu     $18, $6, $0
    /* 3EAE7C 004EAE7C 2D200002 */  daddu      $4, $16, $0
    /* 3EAE80 004EAE80 2D282002 */  daddu      $5, $17, $0
    /* 3EAE84 004EAE84 AAAB130C */  jal        func_004eaea8
    /* 3EAE88 004EAE88 2D304002 */   daddu     $6, $18, $0
    /* 3EAE8C 004EAE8C 0000B0DF */  ld         $16, 0x0($29)
    /* 3EAE90 004EAE90 0800B1DF */  ld         $17, 0x8($29)
    /* 3EAE94 004EAE94 1000B2DF */  ld         $18, 0x10($29)
    /* 3EAE98 004EAE98 1800BFDF */  ld         $31, 0x18($29)
    /* 3EAE9C 004EAE9C CAA91308 */  j          func_004ea728
    /* 3EAEA0 004EAEA0 2000BD27 */   addiu     $29, $29, 0x20
    /* 3EAEA4 004EAEA4 00000000 */  nop
.size func_004eae58, 0x50
