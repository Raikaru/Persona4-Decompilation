.section .text
.set noat
.set noreorder
glabel func_004ed600
    /* 3ED600 004ED600 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3ED604 004ED604 0000B0FF */  sd         $16, 0x0($29)
    /* 3ED608 004ED608 2D808000 */  daddu      $16, $4, $0
    /* 3ED60C 004ED60C 0800B1FF */  sd         $17, 0x8($29)
    /* 3ED610 004ED610 1000BFFF */  sd         $31, 0x10($29)
    /* 3ED614 004ED614 14B5130C */  jal        func_004ed450
    /* 3ED618 004ED618 2D88A000 */   daddu     $17, $5, $0
    /* 3ED61C 004ED61C 2D200002 */  daddu      $4, $16, $0
    /* 3ED620 004ED620 92B5130C */  jal        func_004ed648
    /* 3ED624 004ED624 2D282002 */   daddu     $5, $17, $0
    /* 3ED628 004ED628 1AB5130C */  jal        func_004ed468
    /* 3ED62C 004ED62C 2D804000 */   daddu     $16, $2, $0
    /* 3ED630 004ED630 0800B1DF */  ld         $17, 0x8($29)
    /* 3ED634 004ED634 2D100002 */  daddu      $2, $16, $0
    /* 3ED638 004ED638 1000BFDF */  ld         $31, 0x10($29)
    /* 3ED63C 004ED63C 0000B0DF */  ld         $16, 0x0($29)
    /* 3ED640 004ED640 0800E003 */  jr         $31
    /* 3ED644 004ED644 2000BD27 */   addiu     $29, $29, 0x20
.size func_004ed600, 0x48
