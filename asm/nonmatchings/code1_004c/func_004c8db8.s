.section .text
.set noat
.set noreorder
glabel func_004c8db8
    /* 3C8DB8 004C8DB8 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3C8DBC 004C8DBC 0000B0FF */  sd         $16, 0x0($29)
    /* 3C8DC0 004C8DC0 2D808000 */  daddu      $16, $4, $0
    /* 3C8DC4 004C8DC4 0800B1FF */  sd         $17, 0x8($29)
    /* 3C8DC8 004C8DC8 2D88A000 */  daddu      $17, $5, $0
    /* 3C8DCC 004C8DCC 1000B2FF */  sd         $18, 0x10($29)
    /* 3C8DD0 004C8DD0 1800BFFF */  sd         $31, 0x18($29)
    /* 3C8DD4 004C8DD4 4627130C */  jal        func_004c9d18
    /* 3C8DD8 004C8DD8 2D90C000 */   daddu     $18, $6, $0
    /* 3C8DDC 004C8DDC 2D200002 */  daddu      $4, $16, $0
    /* 3C8DE0 004C8DE0 2D282002 */  daddu      $5, $17, $0
    /* 3C8DE4 004C8DE4 8423130C */  jal        func_004c8e10
    /* 3C8DE8 004C8DE8 2D304002 */   daddu     $6, $18, $0
    /* 3C8DEC 004C8DEC 4C27130C */  jal        func_004c9d30
    /* 3C8DF0 004C8DF0 2D804000 */   daddu     $16, $2, $0
    /* 3C8DF4 004C8DF4 0800B1DF */  ld         $17, 0x8($29)
    /* 3C8DF8 004C8DF8 2D100002 */  daddu      $2, $16, $0
    /* 3C8DFC 004C8DFC 1000B2DF */  ld         $18, 0x10($29)
    /* 3C8E00 004C8E00 0000B0DF */  ld         $16, 0x0($29)
    /* 3C8E04 004C8E04 1800BFDF */  ld         $31, 0x18($29)
    /* 3C8E08 004C8E08 0800E003 */  jr         $31
    /* 3C8E0C 004C8E0C 2000BD27 */   addiu     $29, $29, 0x20
.size func_004c8db8, 0x58
