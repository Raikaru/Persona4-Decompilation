.section .text
.set noat
.set noreorder
glabel func_004eef58
    /* 3EEF58 004EEF58 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3EEF5C 004EEF5C 0000B0FF */  sd         $16, 0x0($29)
    /* 3EEF60 004EEF60 0800BFFF */  sd         $31, 0x8($29)
    /* 3EEF64 004EEF64 14B5130C */  jal        func_004ed450
    /* 3EEF68 004EEF68 2D808000 */   daddu     $16, $4, $0
    /* 3EEF6C 004EEF6C E2BB130C */  jal        func_004eef88
    /* 3EEF70 004EEF70 2D200002 */   daddu     $4, $16, $0
    /* 3EEF74 004EEF74 0000B0DF */  ld         $16, 0x0($29)
    /* 3EEF78 004EEF78 0800BFDF */  ld         $31, 0x8($29)
    /* 3EEF7C 004EEF7C 1AB51308 */  j          func_004ed468
    /* 3EEF80 004EEF80 1000BD27 */   addiu     $29, $29, 0x10
    /* 3EEF84 004EEF84 00000000 */  nop
.size func_004eef58, 0x30
