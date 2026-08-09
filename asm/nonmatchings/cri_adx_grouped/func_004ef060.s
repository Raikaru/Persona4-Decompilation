.section .text
.set noat
.set noreorder
glabel func_004ef060
    /* 3EF060 004EF060 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3EF064 004EF064 0000B0FF */  sd         $16, 0x0($29)
    /* 3EF068 004EF068 2D808000 */  daddu      $16, $4, $0
    /* 3EF06C 004EF06C 0800B1FF */  sd         $17, 0x8($29)
    /* 3EF070 004EF070 1000BFFF */  sd         $31, 0x10($29)
    /* 3EF074 004EF074 14B5130C */  jal        func_004ed450
    /* 3EF078 004EF078 2D88A000 */   daddu     $17, $5, $0
    /* 3EF07C 004EF07C 2D200002 */  daddu      $4, $16, $0
    /* 3EF080 004EF080 2ABC130C */  jal        func_004ef0a8
    /* 3EF084 004EF084 2D282002 */   daddu     $5, $17, $0
    /* 3EF088 004EF088 1AB5130C */  jal        func_004ed468
    /* 3EF08C 004EF08C 2D804000 */   daddu     $16, $2, $0
    /* 3EF090 004EF090 0800B1DF */  ld         $17, 0x8($29)
    /* 3EF094 004EF094 2D100002 */  daddu      $2, $16, $0
    /* 3EF098 004EF098 1000BFDF */  ld         $31, 0x10($29)
    /* 3EF09C 004EF09C 0000B0DF */  ld         $16, 0x0($29)
    /* 3EF0A0 004EF0A0 0800E003 */  jr         $31
    /* 3EF0A4 004EF0A4 2000BD27 */   addiu     $29, $29, 0x20
.size func_004ef060, 0x48
