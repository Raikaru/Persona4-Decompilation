.section .text
.set noat
.set noreorder
glabel func_004cdcf0
    /* 3CDCF0 004CDCF0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3CDCF4 004CDCF4 0000B0FF */  sd         $16, 0x0($29)
    /* 3CDCF8 004CDCF8 2D808000 */  daddu      $16, $4, $0
    /* 3CDCFC 004CDCFC 0800B1FF */  sd         $17, 0x8($29)
    /* 3CDD00 004CDD00 2D88A000 */  daddu      $17, $5, $0
    /* 3CDD04 004CDD04 1000BFFF */  sd         $31, 0x10($29)
    /* 3CDD08 004CDD08 380011AE */  sw         $17, 0x38($16)
    /* 3CDD0C 004CDD0C 2007130C */  jal        func_004c1c80
    /* 3CDD10 004CDD10 0400048E */   lw        $4, 0x4($16)
    /* 3CDD14 004CDD14 0400048E */  lw         $4, 0x4($16)
    /* 3CDD18 004CDD18 2D282002 */  daddu      $5, $17, $0
    /* 3CDD1C 004CDD1C 0800B1DF */  ld         $17, 0x8($29)
    /* 3CDD20 004CDD20 0000B0DF */  ld         $16, 0x0($29)
    /* 3CDD24 004CDD24 1000BFDF */  ld         $31, 0x10($29)
    /* 3CDD28 004CDD28 A6061308 */  j          func_004c1a98
    /* 3CDD2C 004CDD2C 2000BD27 */   addiu     $29, $29, 0x20
.size func_004cdcf0, 0x40
