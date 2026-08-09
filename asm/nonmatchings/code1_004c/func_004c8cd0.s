.section .text
.set noat
.set noreorder
glabel func_004c8cd0
    /* 3C8CD0 004C8CD0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3C8CD4 004C8CD4 0000B0FF */  sd         $16, 0x0($29)
    /* 3C8CD8 004C8CD8 2D808000 */  daddu      $16, $4, $0
    /* 3C8CDC 004C8CDC 0800B1FF */  sd         $17, 0x8($29)
    /* 3C8CE0 004C8CE0 2D88A000 */  daddu      $17, $5, $0
    /* 3C8CE4 004C8CE4 1000B2FF */  sd         $18, 0x10($29)
    /* 3C8CE8 004C8CE8 1800BFFF */  sd         $31, 0x18($29)
    /* 3C8CEC 004C8CEC 4627130C */  jal        func_004c9d18
    /* 3C8CF0 004C8CF0 2D90C000 */   daddu     $18, $6, $0
    /* 3C8CF4 004C8CF4 2D200002 */  daddu      $4, $16, $0
    /* 3C8CF8 004C8CF8 2D282002 */  daddu      $5, $17, $0
    /* 3C8CFC 004C8CFC 4A23130C */  jal        func_004c8d28
    /* 3C8D00 004C8D00 2D304002 */   daddu     $6, $18, $0
    /* 3C8D04 004C8D04 4C27130C */  jal        func_004c9d30
    /* 3C8D08 004C8D08 2D804000 */   daddu     $16, $2, $0
    /* 3C8D0C 004C8D0C 0800B1DF */  ld         $17, 0x8($29)
    /* 3C8D10 004C8D10 2D100002 */  daddu      $2, $16, $0
    /* 3C8D14 004C8D14 1000B2DF */  ld         $18, 0x10($29)
    /* 3C8D18 004C8D18 0000B0DF */  ld         $16, 0x0($29)
    /* 3C8D1C 004C8D1C 1800BFDF */  ld         $31, 0x18($29)
    /* 3C8D20 004C8D20 0800E003 */  jr         $31
    /* 3C8D24 004C8D24 2000BD27 */   addiu     $29, $29, 0x20
.size func_004c8cd0, 0x58
