.section .text
.set noat
.set noreorder
glabel func_004c90a8
    /* 3C90A8 004C90A8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3C90AC 004C90AC 0000B0FF */  sd         $16, 0x0($29)
    /* 3C90B0 004C90B0 0800BFFF */  sd         $31, 0x8($29)
    /* 3C90B4 004C90B4 4627130C */  jal        func_004c9d18
    /* 3C90B8 004C90B8 2D808000 */   daddu     $16, $4, $0
    /* 3C90BC 004C90BC 3824130C */  jal        func_004c90e0
    /* 3C90C0 004C90C0 2D200002 */   daddu     $4, $16, $0
    /* 3C90C4 004C90C4 4C27130C */  jal        func_004c9d30
    /* 3C90C8 004C90C8 2D804000 */   daddu     $16, $2, $0
    /* 3C90CC 004C90CC 0800BFDF */  ld         $31, 0x8($29)
    /* 3C90D0 004C90D0 2D100002 */  daddu      $2, $16, $0
    /* 3C90D4 004C90D4 0000B0DF */  ld         $16, 0x0($29)
    /* 3C90D8 004C90D8 0800E003 */  jr         $31
    /* 3C90DC 004C90DC 1000BD27 */   addiu     $29, $29, 0x10
.size func_004c90a8, 0x38
