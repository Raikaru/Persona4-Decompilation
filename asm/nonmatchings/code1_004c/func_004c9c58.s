.section .text
.set noat
.set noreorder
glabel func_004c9c58
    /* 3C9C58 004C9C58 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3C9C5C 004C9C5C 0000B0FF */  sd         $16, 0x0($29)
    /* 3C9C60 004C9C60 0800BFFF */  sd         $31, 0x8($29)
    /* 3C9C64 004C9C64 4627130C */  jal        func_004c9d18
    /* 3C9C68 004C9C68 2D808000 */   daddu     $16, $4, $0
    /* 3C9C6C 004C9C6C 2427130C */  jal        func_004c9c90
    /* 3C9C70 004C9C70 2D200002 */   daddu     $4, $16, $0
    /* 3C9C74 004C9C74 4C27130C */  jal        func_004c9d30
    /* 3C9C78 004C9C78 2D804000 */   daddu     $16, $2, $0
    /* 3C9C7C 004C9C7C 0800BFDF */  ld         $31, 0x8($29)
    /* 3C9C80 004C9C80 2D100002 */  daddu      $2, $16, $0
    /* 3C9C84 004C9C84 0000B0DF */  ld         $16, 0x0($29)
    /* 3C9C88 004C9C88 0800E003 */  jr         $31
    /* 3C9C8C 004C9C8C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004c9c58, 0x38
