.section .text
.set noat
.set noreorder
glabel func_004c9b80
    /* 3C9B80 004C9B80 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3C9B84 004C9B84 0000B0FF */  sd         $16, 0x0($29)
    /* 3C9B88 004C9B88 0800BFFF */  sd         $31, 0x8($29)
    /* 3C9B8C 004C9B8C 4627130C */  jal        func_004c9d18
    /* 3C9B90 004C9B90 2D808000 */   daddu     $16, $4, $0
    /* 3C9B94 004C9B94 EE26130C */  jal        func_004c9bb8
    /* 3C9B98 004C9B98 2D200002 */   daddu     $4, $16, $0
    /* 3C9B9C 004C9B9C 4C27130C */  jal        func_004c9d30
    /* 3C9BA0 004C9BA0 2D804000 */   daddu     $16, $2, $0
    /* 3C9BA4 004C9BA4 0800BFDF */  ld         $31, 0x8($29)
    /* 3C9BA8 004C9BA8 2D100002 */  daddu      $2, $16, $0
    /* 3C9BAC 004C9BAC 0000B0DF */  ld         $16, 0x0($29)
    /* 3C9BB0 004C9BB0 0800E003 */  jr         $31
    /* 3C9BB4 004C9BB4 1000BD27 */   addiu     $29, $29, 0x10
.size func_004c9b80, 0x38
