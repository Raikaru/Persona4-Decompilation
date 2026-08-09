.section .text
.set noat
.set noreorder
glabel func_004c6f50
    /* 3C6F50 004C6F50 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3C6F54 004C6F54 0000B0FF */  sd         $16, 0x0($29)
    /* 3C6F58 004C6F58 2D808000 */  daddu      $16, $4, $0
    /* 3C6F5C 004C6F5C 0800B1FF */  sd         $17, 0x8($29)
    /* 3C6F60 004C6F60 2D88A000 */  daddu      $17, $5, $0
    /* 3C6F64 004C6F64 1000B2FF */  sd         $18, 0x10($29)
    /* 3C6F68 004C6F68 1800BFFF */  sd         $31, 0x18($29)
    /* 3C6F6C 004C6F6C 8A1C130C */  jal        func_004c7228
    /* 3C6F70 004C6F70 2D90C000 */   daddu     $18, $6, $0
    /* 3C6F74 004C6F74 2D200002 */  daddu      $4, $16, $0
    /* 3C6F78 004C6F78 2D282002 */  daddu      $5, $17, $0
    /* 3C6F7C 004C6F7C EA1B130C */  jal        func_004c6fa8
    /* 3C6F80 004C6F80 2D304002 */   daddu     $6, $18, $0
    /* 3C6F84 004C6F84 8C1C130C */  jal        func_004c7230
    /* 3C6F88 004C6F88 2D804000 */   daddu     $16, $2, $0
    /* 3C6F8C 004C6F8C 0800B1DF */  ld         $17, 0x8($29)
    /* 3C6F90 004C6F90 2D100002 */  daddu      $2, $16, $0
    /* 3C6F94 004C6F94 1000B2DF */  ld         $18, 0x10($29)
    /* 3C6F98 004C6F98 0000B0DF */  ld         $16, 0x0($29)
    /* 3C6F9C 004C6F9C 1800BFDF */  ld         $31, 0x18($29)
    /* 3C6FA0 004C6FA0 0800E003 */  jr         $31
    /* 3C6FA4 004C6FA4 2000BD27 */   addiu     $29, $29, 0x20
.size func_004c6f50, 0x58
