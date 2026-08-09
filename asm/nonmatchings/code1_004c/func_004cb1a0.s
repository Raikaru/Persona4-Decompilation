.section .text
.set noat
.set noreorder
glabel func_004cb1a0
    /* 3CB1A0 004CB1A0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CB1A4 004CB1A4 0000B0FF */  sd         $16, 0x0($29)
    /* 3CB1A8 004CB1A8 0800BFFF */  sd         $31, 0x8($29)
    /* 3CB1AC 004CB1AC 3615130C */  jal        func_004c54d8
    /* 3CB1B0 004CB1B0 2D808000 */   daddu     $16, $4, $0
    /* 3CB1B4 004CB1B4 762C130C */  jal        func_004cb1d8
    /* 3CB1B8 004CB1B8 2D200002 */   daddu     $4, $16, $0
    /* 3CB1BC 004CB1BC 3815130C */  jal        func_004c54e0
    /* 3CB1C0 004CB1C0 2D804000 */   daddu     $16, $2, $0
    /* 3CB1C4 004CB1C4 0800BFDF */  ld         $31, 0x8($29)
    /* 3CB1C8 004CB1C8 2D100002 */  daddu      $2, $16, $0
    /* 3CB1CC 004CB1CC 0000B0DF */  ld         $16, 0x0($29)
    /* 3CB1D0 004CB1D0 0800E003 */  jr         $31
    /* 3CB1D4 004CB1D4 1000BD27 */   addiu     $29, $29, 0x10
.size func_004cb1a0, 0x38
