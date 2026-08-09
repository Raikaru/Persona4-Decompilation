.section .text
.set noat
.set noreorder
glabel func_004ed710
    /* 3ED710 004ED710 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3ED714 004ED714 0000B0FF */  sd         $16, 0x0($29)
    /* 3ED718 004ED718 0800BFFF */  sd         $31, 0x8($29)
    /* 3ED71C 004ED71C 14B5130C */  jal        func_004ed450
    /* 3ED720 004ED720 2D808000 */   daddu     $16, $4, $0
    /* 3ED724 004ED724 D0B5130C */  jal        func_004ed740
    /* 3ED728 004ED728 2D200002 */   daddu     $4, $16, $0
    /* 3ED72C 004ED72C 0000B0DF */  ld         $16, 0x0($29)
    /* 3ED730 004ED730 0800BFDF */  ld         $31, 0x8($29)
    /* 3ED734 004ED734 1AB51308 */  j          func_004ed468
    /* 3ED738 004ED738 1000BD27 */   addiu     $29, $29, 0x10
    /* 3ED73C 004ED73C 00000000 */  nop
.size func_004ed710, 0x30
