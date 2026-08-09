.section .text
.set noat
.set noreorder
glabel func_004eec20
    /* 3EEC20 004EEC20 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3EEC24 004EEC24 0000B0FF */  sd         $16, 0x0($29)
    /* 3EEC28 004EEC28 2D808000 */  daddu      $16, $4, $0
    /* 3EEC2C 004EEC2C 0800B1FF */  sd         $17, 0x8($29)
    /* 3EEC30 004EEC30 2D88A000 */  daddu      $17, $5, $0
    /* 3EEC34 004EEC34 1000B2FF */  sd         $18, 0x10($29)
    /* 3EEC38 004EEC38 1800BFFF */  sd         $31, 0x18($29)
    /* 3EEC3C 004EEC3C 14B5130C */  jal        func_004ed450
    /* 3EEC40 004EEC40 2D90C000 */   daddu     $18, $6, $0
    /* 3EEC44 004EEC44 2D200002 */  daddu      $4, $16, $0
    /* 3EEC48 004EEC48 2D282002 */  daddu      $5, $17, $0
    /* 3EEC4C 004EEC4C 1EBB130C */  jal        func_004eec78
    /* 3EEC50 004EEC50 2D304002 */   daddu     $6, $18, $0
    /* 3EEC54 004EEC54 1AB5130C */  jal        func_004ed468
    /* 3EEC58 004EEC58 2D804000 */   daddu     $16, $2, $0
    /* 3EEC5C 004EEC5C 0800B1DF */  ld         $17, 0x8($29)
    /* 3EEC60 004EEC60 2D100002 */  daddu      $2, $16, $0
    /* 3EEC64 004EEC64 1000B2DF */  ld         $18, 0x10($29)
    /* 3EEC68 004EEC68 0000B0DF */  ld         $16, 0x0($29)
    /* 3EEC6C 004EEC6C 1800BFDF */  ld         $31, 0x18($29)
    /* 3EEC70 004EEC70 0800E003 */  jr         $31
    /* 3EEC74 004EEC74 2000BD27 */   addiu     $29, $29, 0x20
.size func_004eec20, 0x58
