.section .text
.set noat
.set noreorder
glabel func_004eee18
    /* 3EEE18 004EEE18 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3EEE1C 004EEE1C 0000B0FF */  sd         $16, 0x0($29)
    /* 3EEE20 004EEE20 0800BFFF */  sd         $31, 0x8($29)
    /* 3EEE24 004EEE24 14B5130C */  jal        func_004ed450
    /* 3EEE28 004EEE28 2D808000 */   daddu     $16, $4, $0
    /* 3EEE2C 004EEE2C 94BB130C */  jal        func_004eee50
    /* 3EEE30 004EEE30 2D200002 */   daddu     $4, $16, $0
    /* 3EEE34 004EEE34 1AB5130C */  jal        func_004ed468
    /* 3EEE38 004EEE38 2D804000 */   daddu     $16, $2, $0
    /* 3EEE3C 004EEE3C 0800BFDF */  ld         $31, 0x8($29)
    /* 3EEE40 004EEE40 2D100002 */  daddu      $2, $16, $0
    /* 3EEE44 004EEE44 0000B0DF */  ld         $16, 0x0($29)
    /* 3EEE48 004EEE48 0800E003 */  jr         $31
    /* 3EEE4C 004EEE4C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004eee18, 0x38
