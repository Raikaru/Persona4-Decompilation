.section .text
.set noat
.set noreorder
glabel func_00511ed8
    /* 411ED8 00511ED8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 411EDC 00511EDC 0000B0FF */  sd         $16, 0x0($29)
    /* 411EE0 00511EE0 0800BFFF */  sd         $31, 0x8($29)
    /* 411EE4 00511EE4 6633140C */  jal        func_0050cd98
    /* 411EE8 00511EE8 2D808000 */   daddu     $16, $4, $0
    /* 411EEC 00511EEC 2D200002 */  daddu      $4, $16, $0
    /* 411EF0 00511EF0 9247140C */  jal        func_00511e48
    /* 411EF4 00511EF4 01000524 */   addiu     $5, $0, 0x1
    /* 411EF8 00511EF8 AE44140C */  jal        func_005112b8
    /* 411EFC 00511EFC 00000000 */   nop
    /* 411F00 00511F00 2D200002 */  daddu      $4, $16, $0
    /* 411F04 00511F04 9247140C */  jal        func_00511e48
    /* 411F08 00511F08 2D280000 */   daddu     $5, $0, $0
    /* 411F0C 00511F0C 6C33140C */  jal        func_0050cdb0
    /* 411F10 00511F10 00000000 */   nop
    /* 411F14 00511F14 0800BFDF */  ld         $31, 0x8($29)
    /* 411F18 00511F18 2D200002 */  daddu      $4, $16, $0
    /* 411F1C 00511F1C 0000B0DF */  ld         $16, 0x0($29)
    /* 411F20 00511F20 CA441408 */  j          func_00511328
    /* 411F24 00511F24 1000BD27 */   addiu     $29, $29, 0x10
.size func_00511ed8, 0x50
