.section .text
.set noat
.set noreorder
glabel func_004ee018
    /* 3EE018 004EE018 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3EE01C 004EE01C 0000B0FF */  sd         $16, 0x0($29)
    /* 3EE020 004EE020 2D808000 */  daddu      $16, $4, $0
    /* 3EE024 004EE024 0800B1FF */  sd         $17, 0x8($29)
    /* 3EE028 004EE028 2D88A000 */  daddu      $17, $5, $0
    /* 3EE02C 004EE02C 1000B2FF */  sd         $18, 0x10($29)
    /* 3EE030 004EE030 1800BFFF */  sd         $31, 0x18($29)
    /* 3EE034 004EE034 14B5130C */  jal        func_004ed450
    /* 3EE038 004EE038 2D90C000 */   daddu     $18, $6, $0
    /* 3EE03C 004EE03C 2D200002 */  daddu      $4, $16, $0
    /* 3EE040 004EE040 2D282002 */  daddu      $5, $17, $0
    /* 3EE044 004EE044 1CB8130C */  jal        func_004ee070
    /* 3EE048 004EE048 2D304002 */   daddu     $6, $18, $0
    /* 3EE04C 004EE04C 1AB5130C */  jal        func_004ed468
    /* 3EE050 004EE050 2D804000 */   daddu     $16, $2, $0
    /* 3EE054 004EE054 0800B1DF */  ld         $17, 0x8($29)
    /* 3EE058 004EE058 2D100002 */  daddu      $2, $16, $0
    /* 3EE05C 004EE05C 1000B2DF */  ld         $18, 0x10($29)
    /* 3EE060 004EE060 0000B0DF */  ld         $16, 0x0($29)
    /* 3EE064 004EE064 1800BFDF */  ld         $31, 0x18($29)
    /* 3EE068 004EE068 0800E003 */  jr         $31
    /* 3EE06C 004EE06C 2000BD27 */   addiu     $29, $29, 0x20
.size func_004ee018, 0x58
