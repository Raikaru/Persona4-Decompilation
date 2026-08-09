.section .text
.set noat
.set noreorder
glabel func_004c8e28
    /* 3C8E28 004C8E28 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3C8E2C 004C8E2C 0000B0FF */  sd         $16, 0x0($29)
    /* 3C8E30 004C8E30 2D808000 */  daddu      $16, $4, $0
    /* 3C8E34 004C8E34 0800B1FF */  sd         $17, 0x8($29)
    /* 3C8E38 004C8E38 2D88A000 */  daddu      $17, $5, $0
    /* 3C8E3C 004C8E3C 1000B2FF */  sd         $18, 0x10($29)
    /* 3C8E40 004C8E40 1800BFFF */  sd         $31, 0x18($29)
    /* 3C8E44 004C8E44 4627130C */  jal        func_004c9d18
    /* 3C8E48 004C8E48 2D90C000 */   daddu     $18, $6, $0
    /* 3C8E4C 004C8E4C 2D200002 */  daddu      $4, $16, $0
    /* 3C8E50 004C8E50 2D282002 */  daddu      $5, $17, $0
    /* 3C8E54 004C8E54 A023130C */  jal        func_004c8e80
    /* 3C8E58 004C8E58 2D304002 */   daddu     $6, $18, $0
    /* 3C8E5C 004C8E5C 4C27130C */  jal        func_004c9d30
    /* 3C8E60 004C8E60 2D804000 */   daddu     $16, $2, $0
    /* 3C8E64 004C8E64 0800B1DF */  ld         $17, 0x8($29)
    /* 3C8E68 004C8E68 2D100002 */  daddu      $2, $16, $0
    /* 3C8E6C 004C8E6C 1000B2DF */  ld         $18, 0x10($29)
    /* 3C8E70 004C8E70 0000B0DF */  ld         $16, 0x0($29)
    /* 3C8E74 004C8E74 1800BFDF */  ld         $31, 0x18($29)
    /* 3C8E78 004C8E78 0800E003 */  jr         $31
    /* 3C8E7C 004C8E7C 2000BD27 */   addiu     $29, $29, 0x20
.size func_004c8e28, 0x58
