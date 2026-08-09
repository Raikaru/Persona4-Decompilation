.section .text
.set noat
.set noreorder
glabel func_004c83b0
    /* 3C83B0 004C83B0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3C83B4 004C83B4 0000B0FF */  sd         $16, 0x0($29)
    /* 3C83B8 004C83B8 0800BFFF */  sd         $31, 0x8($29)
    /* 3C83BC 004C83BC 4627130C */  jal        func_004c9d18
    /* 3C83C0 004C83C0 2D808000 */   daddu     $16, $4, $0
    /* 3C83C4 004C83C4 FA20130C */  jal        func_004c83e8
    /* 3C83C8 004C83C8 2D200002 */   daddu     $4, $16, $0
    /* 3C83CC 004C83CC 4C27130C */  jal        func_004c9d30
    /* 3C83D0 004C83D0 2D804000 */   daddu     $16, $2, $0
    /* 3C83D4 004C83D4 0800BFDF */  ld         $31, 0x8($29)
    /* 3C83D8 004C83D8 2D100002 */  daddu      $2, $16, $0
    /* 3C83DC 004C83DC 0000B0DF */  ld         $16, 0x0($29)
    /* 3C83E0 004C83E0 0800E003 */  jr         $31
    /* 3C83E4 004C83E4 1000BD27 */   addiu     $29, $29, 0x10
.size func_004c83b0, 0x38
