.section .text
.set noat
.set noreorder
glabel func_004ef5f8
    /* 3EF5F8 004EF5F8 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 3EF5FC 004EF5FC 0000B0FF */  sd         $16, 0x0($29)
    /* 3EF600 004EF600 2D808000 */  daddu      $16, $4, $0
    /* 3EF604 004EF604 0800B1FF */  sd         $17, 0x8($29)
    /* 3EF608 004EF608 2D88A000 */  daddu      $17, $5, $0
    /* 3EF60C 004EF60C 1000B2FF */  sd         $18, 0x10($29)
    /* 3EF610 004EF610 2D90C000 */  daddu      $18, $6, $0
    /* 3EF614 004EF614 1800B3FF */  sd         $19, 0x18($29)
    /* 3EF618 004EF618 2000BFFF */  sd         $31, 0x20($29)
    /* 3EF61C 004EF61C 14B5130C */  jal        func_004ed450
    /* 3EF620 004EF620 2D98E000 */   daddu     $19, $7, $0
    /* 3EF624 004EF624 2D200002 */  daddu      $4, $16, $0
    /* 3EF628 004EF628 2D282002 */  daddu      $5, $17, $0
    /* 3EF62C 004EF62C 2D304002 */  daddu      $6, $18, $0
    /* 3EF630 004EF630 98BD130C */  jal        func_004ef660
    /* 3EF634 004EF634 2D386002 */   daddu     $7, $19, $0
    /* 3EF638 004EF638 1AB5130C */  jal        func_004ed468
    /* 3EF63C 004EF63C 2D804000 */   daddu     $16, $2, $0
    /* 3EF640 004EF640 0800B1DF */  ld         $17, 0x8($29)
    /* 3EF644 004EF644 2D100002 */  daddu      $2, $16, $0
    /* 3EF648 004EF648 1000B2DF */  ld         $18, 0x10($29)
    /* 3EF64C 004EF64C 0000B0DF */  ld         $16, 0x0($29)
    /* 3EF650 004EF650 1800B3DF */  ld         $19, 0x18($29)
    /* 3EF654 004EF654 2000BFDF */  ld         $31, 0x20($29)
    /* 3EF658 004EF658 0800E003 */  jr         $31
    /* 3EF65C 004EF65C 3000BD27 */   addiu     $29, $29, 0x30
.size func_004ef5f8, 0x68
