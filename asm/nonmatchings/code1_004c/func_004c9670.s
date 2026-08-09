.section .text
.set noat
.set noreorder
glabel func_004c9670
    /* 3C9670 004C9670 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3C9674 004C9674 0000B0FF */  sd         $16, 0x0($29)
    /* 3C9678 004C9678 0800BFFF */  sd         $31, 0x8($29)
    /* 3C967C 004C967C 4627130C */  jal        func_004c9d18
    /* 3C9680 004C9680 2D808000 */   daddu     $16, $4, $0
    /* 3C9684 004C9684 AA25130C */  jal        func_004c96a8
    /* 3C9688 004C9688 2D200002 */   daddu     $4, $16, $0
    /* 3C968C 004C968C 4C27130C */  jal        func_004c9d30
    /* 3C9690 004C9690 2D804000 */   daddu     $16, $2, $0
    /* 3C9694 004C9694 0800BFDF */  ld         $31, 0x8($29)
    /* 3C9698 004C9698 2D100002 */  daddu      $2, $16, $0
    /* 3C969C 004C969C 0000B0DF */  ld         $16, 0x0($29)
    /* 3C96A0 004C96A0 0800E003 */  jr         $31
    /* 3C96A4 004C96A4 1000BD27 */   addiu     $29, $29, 0x10
.size func_004c9670, 0x38
