.section .text
.set noat
.set noreorder
glabel func_0044d4b0
    /* 34D4B0 0044D4B0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 34D4B4 0044D4B4 1000BFFF */  sd         $31, 0x10($29)
    /* 34D4B8 0044D4B8 3435110C */  jal        func_0044d4d0
    /* 34D4BC 0044D4BC 2D30A003 */   daddu     $6, $29, $0
    /* 34D4C0 0044D4C0 0000A2DF */  ld         $2, 0x0($29)
    /* 34D4C4 0044D4C4 1000BFDF */  ld         $31, 0x10($29)
    /* 34D4C8 0044D4C8 0800E003 */  jr         $31
    /* 34D4CC 0044D4CC 2000BD27 */   addiu     $29, $29, 0x20
.size func_0044d4b0, 0x20
