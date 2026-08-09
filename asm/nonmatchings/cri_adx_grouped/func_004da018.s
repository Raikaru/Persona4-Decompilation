.section .text
.set noat
.set noreorder
glabel func_004da018
    /* 3DA018 004DA018 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3DA01C 004DA01C 0000B0FF */  sd         $16, 0x0($29)
    /* 3DA020 004DA020 2D808000 */  daddu      $16, $4, $0
    /* 3DA024 004DA024 0800B1FF */  sd         $17, 0x8($29)
    /* 3DA028 004DA028 1000BFFF */  sd         $31, 0x10($29)
    /* 3DA02C 004DA02C D467130C */  jal        func_004d9f50
    /* 3DA030 004DA030 2D88A000 */   daddu     $17, $5, $0
    /* 3DA034 004DA034 1000BFDF */  ld         $31, 0x10($29)
    /* 3DA038 004DA038 AC0111AE */  sw         $17, 0x1AC($16)
    /* 3DA03C 004DA03C 0000B0DF */  ld         $16, 0x0($29)
    /* 3DA040 004DA040 0800B1DF */  ld         $17, 0x8($29)
    /* 3DA044 004DA044 0800E003 */  jr         $31
    /* 3DA048 004DA048 2000BD27 */   addiu     $29, $29, 0x20
    /* 3DA04C 004DA04C 00000000 */  nop
.size func_004da018, 0x38
