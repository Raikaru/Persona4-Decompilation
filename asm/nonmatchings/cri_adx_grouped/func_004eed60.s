.section .text
.set noat
.set noreorder
glabel func_004eed60
    /* 3EED60 004EED60 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3EED64 004EED64 0000B0FF */  sd         $16, 0x0($29)
    /* 3EED68 004EED68 0800BFFF */  sd         $31, 0x8($29)
    /* 3EED6C 004EED6C 14B5130C */  jal        func_004ed450
    /* 3EED70 004EED70 2D808000 */   daddu     $16, $4, $0
    /* 3EED74 004EED74 64BB130C */  jal        func_004eed90
    /* 3EED78 004EED78 2D200002 */   daddu     $4, $16, $0
    /* 3EED7C 004EED7C 0000B0DF */  ld         $16, 0x0($29)
    /* 3EED80 004EED80 0800BFDF */  ld         $31, 0x8($29)
    /* 3EED84 004EED84 1AB51308 */  j          func_004ed468
    /* 3EED88 004EED88 1000BD27 */   addiu     $29, $29, 0x10
    /* 3EED8C 004EED8C 00000000 */  nop
.size func_004eed60, 0x30
