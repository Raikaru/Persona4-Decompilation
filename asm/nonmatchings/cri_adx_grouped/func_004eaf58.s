.section .text
.set noat
.set noreorder
glabel func_004eaf58
    /* 3EAF58 004EAF58 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3EAF5C 004EAF5C 0000B0FF */  sd         $16, 0x0($29)
    /* 3EAF60 004EAF60 2D808000 */  daddu      $16, $4, $0
    /* 3EAF64 004EAF64 0800B1FF */  sd         $17, 0x8($29)
    /* 3EAF68 004EAF68 1000BFFF */  sd         $31, 0x10($29)
    /* 3EAF6C 004EAF6C C4A9130C */  jal        func_004ea710
    /* 3EAF70 004EAF70 2D88A000 */   daddu     $17, $5, $0
    /* 3EAF74 004EAF74 2D200002 */  daddu      $4, $16, $0
    /* 3EAF78 004EAF78 E6AB130C */  jal        func_004eaf98
    /* 3EAF7C 004EAF7C 2D282002 */   daddu     $5, $17, $0
    /* 3EAF80 004EAF80 0000B0DF */  ld         $16, 0x0($29)
    /* 3EAF84 004EAF84 0800B1DF */  ld         $17, 0x8($29)
    /* 3EAF88 004EAF88 1000BFDF */  ld         $31, 0x10($29)
    /* 3EAF8C 004EAF8C CAA91308 */  j          func_004ea728
    /* 3EAF90 004EAF90 2000BD27 */   addiu     $29, $29, 0x20
    /* 3EAF94 004EAF94 00000000 */  nop
.size func_004eaf58, 0x40
