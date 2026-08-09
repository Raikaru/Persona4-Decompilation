.section .text
.set noat
.set noreorder
glabel func_004f0a60
    /* 3F0A60 004F0A60 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 3F0A64 004F0A64 0000B0FF */  sd         $16, 0x0($29)
    /* 3F0A68 004F0A68 2D808000 */  daddu      $16, $4, $0
    /* 3F0A6C 004F0A6C 0800B1FF */  sd         $17, 0x8($29)
    /* 3F0A70 004F0A70 2D88A000 */  daddu      $17, $5, $0
    /* 3F0A74 004F0A74 1000B2FF */  sd         $18, 0x10($29)
    /* 3F0A78 004F0A78 2D90C000 */  daddu      $18, $6, $0
    /* 3F0A7C 004F0A7C 1800B3FF */  sd         $19, 0x18($29)
    /* 3F0A80 004F0A80 2000BFFF */  sd         $31, 0x20($29)
    /* 3F0A84 004F0A84 82C1130C */  jal        func_004f0608
    /* 3F0A88 004F0A88 2D98E000 */   daddu     $19, $7, $0
    /* 3F0A8C 004F0A8C 2D200002 */  daddu      $4, $16, $0
    /* 3F0A90 004F0A90 2D282002 */  daddu      $5, $17, $0
    /* 3F0A94 004F0A94 2D304002 */  daddu      $6, $18, $0
    /* 3F0A98 004F0A98 B2C2130C */  jal        func_004f0ac8
    /* 3F0A9C 004F0A9C 2D386002 */   daddu     $7, $19, $0
    /* 3F0AA0 004F0AA0 88C1130C */  jal        func_004f0620
    /* 3F0AA4 004F0AA4 2D804000 */   daddu     $16, $2, $0
    /* 3F0AA8 004F0AA8 0800B1DF */  ld         $17, 0x8($29)
    /* 3F0AAC 004F0AAC 2D100002 */  daddu      $2, $16, $0
    /* 3F0AB0 004F0AB0 1000B2DF */  ld         $18, 0x10($29)
    /* 3F0AB4 004F0AB4 0000B0DF */  ld         $16, 0x0($29)
    /* 3F0AB8 004F0AB8 1800B3DF */  ld         $19, 0x18($29)
    /* 3F0ABC 004F0ABC 2000BFDF */  ld         $31, 0x20($29)
    /* 3F0AC0 004F0AC0 0800E003 */  jr         $31
    /* 3F0AC4 004F0AC4 3000BD27 */   addiu     $29, $29, 0x30
.size func_004f0a60, 0x68
