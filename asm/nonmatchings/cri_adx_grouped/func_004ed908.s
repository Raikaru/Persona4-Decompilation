.section .text
.set noat
.set noreorder
glabel func_004ed908
    /* 3ED908 004ED908 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3ED90C 004ED90C 0000B0FF */  sd         $16, 0x0($29)
    /* 3ED910 004ED910 0800BFFF */  sd         $31, 0x8($29)
    /* 3ED914 004ED914 14B5130C */  jal        func_004ed450
    /* 3ED918 004ED918 2D808000 */   daddu     $16, $4, $0
    /* 3ED91C 004ED91C 4EB6130C */  jal        func_004ed938
    /* 3ED920 004ED920 2D200002 */   daddu     $4, $16, $0
    /* 3ED924 004ED924 0000B0DF */  ld         $16, 0x0($29)
    /* 3ED928 004ED928 0800BFDF */  ld         $31, 0x8($29)
    /* 3ED92C 004ED92C 1AB51308 */  j          func_004ed468
    /* 3ED930 004ED930 1000BD27 */   addiu     $29, $29, 0x10
    /* 3ED934 004ED934 00000000 */  nop
.size func_004ed908, 0x30
