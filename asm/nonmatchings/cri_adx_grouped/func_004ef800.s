.section .text
.set noat
.set noreorder
glabel func_004ef800
    /* 3EF800 004EF800 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3EF804 004EF804 0000B0FF */  sd         $16, 0x0($29)
    /* 3EF808 004EF808 0800BFFF */  sd         $31, 0x8($29)
    /* 3EF80C 004EF80C 14B5130C */  jal        func_004ed450
    /* 3EF810 004EF810 2D808000 */   daddu     $16, $4, $0
    /* 3EF814 004EF814 0EBE130C */  jal        func_004ef838
    /* 3EF818 004EF818 2D200002 */   daddu     $4, $16, $0
    /* 3EF81C 004EF81C 1AB5130C */  jal        func_004ed468
    /* 3EF820 004EF820 2D804000 */   daddu     $16, $2, $0
    /* 3EF824 004EF824 0800BFDF */  ld         $31, 0x8($29)
    /* 3EF828 004EF828 2D100002 */  daddu      $2, $16, $0
    /* 3EF82C 004EF82C 0000B0DF */  ld         $16, 0x0($29)
    /* 3EF830 004EF830 0800E003 */  jr         $31
    /* 3EF834 004EF834 1000BD27 */   addiu     $29, $29, 0x10
.size func_004ef800, 0x38
