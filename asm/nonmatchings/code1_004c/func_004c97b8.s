.section .text
.set noat
.set noreorder
glabel func_004c97b8
    /* 3C97B8 004C97B8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3C97BC 004C97BC 0000B0FF */  sd         $16, 0x0($29)
    /* 3C97C0 004C97C0 0800BFFF */  sd         $31, 0x8($29)
    /* 3C97C4 004C97C4 4627130C */  jal        func_004c9d18
    /* 3C97C8 004C97C8 2D808000 */   daddu     $16, $4, $0
    /* 3C97CC 004C97CC FC25130C */  jal        func_004c97f0
    /* 3C97D0 004C97D0 2D200002 */   daddu     $4, $16, $0
    /* 3C97D4 004C97D4 4C27130C */  jal        func_004c9d30
    /* 3C97D8 004C97D8 2D804000 */   daddu     $16, $2, $0
    /* 3C97DC 004C97DC 0800BFDF */  ld         $31, 0x8($29)
    /* 3C97E0 004C97E0 2D100002 */  daddu      $2, $16, $0
    /* 3C97E4 004C97E4 0000B0DF */  ld         $16, 0x0($29)
    /* 3C97E8 004C97E8 0800E003 */  jr         $31
    /* 3C97EC 004C97EC 1000BD27 */   addiu     $29, $29, 0x10
.size func_004c97b8, 0x38
