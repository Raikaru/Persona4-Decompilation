.section .text
.set noat
.set noreorder
glabel func_004ee510
    /* 3EE510 004EE510 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3EE514 004EE514 0000B0FF */  sd         $16, 0x0($29)
    /* 3EE518 004EE518 2D808000 */  daddu      $16, $4, $0
    /* 3EE51C 004EE51C 0800B1FF */  sd         $17, 0x8($29)
    /* 3EE520 004EE520 2D88A000 */  daddu      $17, $5, $0
    /* 3EE524 004EE524 1000B2FF */  sd         $18, 0x10($29)
    /* 3EE528 004EE528 1800BFFF */  sd         $31, 0x18($29)
    /* 3EE52C 004EE52C 14B5130C */  jal        func_004ed450
    /* 3EE530 004EE530 2D90C000 */   daddu     $18, $6, $0
    /* 3EE534 004EE534 2D200002 */  daddu      $4, $16, $0
    /* 3EE538 004EE538 2D282002 */  daddu      $5, $17, $0
    /* 3EE53C 004EE53C 58B9130C */  jal        func_004ee560
    /* 3EE540 004EE540 2D304002 */   daddu     $6, $18, $0
    /* 3EE544 004EE544 0000B0DF */  ld         $16, 0x0($29)
    /* 3EE548 004EE548 0800B1DF */  ld         $17, 0x8($29)
    /* 3EE54C 004EE54C 1000B2DF */  ld         $18, 0x10($29)
    /* 3EE550 004EE550 1800BFDF */  ld         $31, 0x18($29)
    /* 3EE554 004EE554 1AB51308 */  j          func_004ed468
    /* 3EE558 004EE558 2000BD27 */   addiu     $29, $29, 0x20
    /* 3EE55C 004EE55C 00000000 */  nop
.size func_004ee510, 0x50
