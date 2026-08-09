.section .text
.set noat
.set noreorder
glabel func_004c7f48
    /* 3C7F48 004C7F48 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3C7F4C 004C7F4C 0000B0FF */  sd         $16, 0x0($29)
    /* 3C7F50 004C7F50 0800BFFF */  sd         $31, 0x8($29)
    /* 3C7F54 004C7F54 4627130C */  jal        func_004c9d18
    /* 3C7F58 004C7F58 2D808000 */   daddu     $16, $4, $0
    /* 3C7F5C 004C7F5C E01F130C */  jal        func_004c7f80
    /* 3C7F60 004C7F60 2D200002 */   daddu     $4, $16, $0
    /* 3C7F64 004C7F64 4C27130C */  jal        func_004c9d30
    /* 3C7F68 004C7F68 2D804000 */   daddu     $16, $2, $0
    /* 3C7F6C 004C7F6C 0800BFDF */  ld         $31, 0x8($29)
    /* 3C7F70 004C7F70 2D100002 */  daddu      $2, $16, $0
    /* 3C7F74 004C7F74 0000B0DF */  ld         $16, 0x0($29)
    /* 3C7F78 004C7F78 0800E003 */  jr         $31
    /* 3C7F7C 004C7F7C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004c7f48, 0x38
