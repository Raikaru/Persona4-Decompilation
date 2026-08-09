.section .text
.set noat
.set noreorder
glabel func_004c7ef8
    /* 3C7EF8 004C7EF8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3C7EFC 004C7EFC 0000B0FF */  sd         $16, 0x0($29)
    /* 3C7F00 004C7F00 0800BFFF */  sd         $31, 0x8($29)
    /* 3C7F04 004C7F04 4627130C */  jal        func_004c9d18
    /* 3C7F08 004C7F08 2D808000 */   daddu     $16, $4, $0
    /* 3C7F0C 004C7F0C CC1F130C */  jal        func_004c7f30
    /* 3C7F10 004C7F10 2D200002 */   daddu     $4, $16, $0
    /* 3C7F14 004C7F14 4C27130C */  jal        func_004c9d30
    /* 3C7F18 004C7F18 2D804000 */   daddu     $16, $2, $0
    /* 3C7F1C 004C7F1C 0800BFDF */  ld         $31, 0x8($29)
    /* 3C7F20 004C7F20 2D100002 */  daddu      $2, $16, $0
    /* 3C7F24 004C7F24 0000B0DF */  ld         $16, 0x0($29)
    /* 3C7F28 004C7F28 0800E003 */  jr         $31
    /* 3C7F2C 004C7F2C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004c7ef8, 0x38
