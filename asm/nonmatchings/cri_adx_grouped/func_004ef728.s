.section .text
.set noat
.set noreorder
glabel func_004ef728
    /* 3EF728 004EF728 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3EF72C 004EF72C 0000B0FF */  sd         $16, 0x0($29)
    /* 3EF730 004EF730 2D808000 */  daddu      $16, $4, $0
    /* 3EF734 004EF734 0800B1FF */  sd         $17, 0x8($29)
    /* 3EF738 004EF738 1000BFFF */  sd         $31, 0x10($29)
    /* 3EF73C 004EF73C 14B5130C */  jal        func_004ed450
    /* 3EF740 004EF740 2D88A000 */   daddu     $17, $5, $0
    /* 3EF744 004EF744 2D200002 */  daddu      $4, $16, $0
    /* 3EF748 004EF748 DCBD130C */  jal        func_004ef770
    /* 3EF74C 004EF74C 2D282002 */   daddu     $5, $17, $0
    /* 3EF750 004EF750 1AB5130C */  jal        func_004ed468
    /* 3EF754 004EF754 2D804000 */   daddu     $16, $2, $0
    /* 3EF758 004EF758 0800B1DF */  ld         $17, 0x8($29)
    /* 3EF75C 004EF75C 2D100002 */  daddu      $2, $16, $0
    /* 3EF760 004EF760 1000BFDF */  ld         $31, 0x10($29)
    /* 3EF764 004EF764 0000B0DF */  ld         $16, 0x0($29)
    /* 3EF768 004EF768 0800E003 */  jr         $31
    /* 3EF76C 004EF76C 2000BD27 */   addiu     $29, $29, 0x20
.size func_004ef728, 0x48
