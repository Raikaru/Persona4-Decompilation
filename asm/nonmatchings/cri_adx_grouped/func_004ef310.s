.section .text
.set noat
.set noreorder
glabel func_004ef310
    /* 3EF310 004EF310 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3EF314 004EF314 0000B0FF */  sd         $16, 0x0($29)
    /* 3EF318 004EF318 2D808000 */  daddu      $16, $4, $0
    /* 3EF31C 004EF31C 0800B1FF */  sd         $17, 0x8($29)
    /* 3EF320 004EF320 2D88A000 */  daddu      $17, $5, $0
    /* 3EF324 004EF324 1000B2FF */  sd         $18, 0x10($29)
    /* 3EF328 004EF328 1800BFFF */  sd         $31, 0x18($29)
    /* 3EF32C 004EF32C 14B5130C */  jal        func_004ed450
    /* 3EF330 004EF330 2D90C000 */   daddu     $18, $6, $0
    /* 3EF334 004EF334 2D200002 */  daddu      $4, $16, $0
    /* 3EF338 004EF338 2D282002 */  daddu      $5, $17, $0
    /* 3EF33C 004EF33C D8BC130C */  jal        func_004ef360
    /* 3EF340 004EF340 2D304002 */   daddu     $6, $18, $0
    /* 3EF344 004EF344 0000B0DF */  ld         $16, 0x0($29)
    /* 3EF348 004EF348 0800B1DF */  ld         $17, 0x8($29)
    /* 3EF34C 004EF34C 1000B2DF */  ld         $18, 0x10($29)
    /* 3EF350 004EF350 1800BFDF */  ld         $31, 0x18($29)
    /* 3EF354 004EF354 1AB51308 */  j          func_004ed468
    /* 3EF358 004EF358 2000BD27 */   addiu     $29, $29, 0x20
    /* 3EF35C 004EF35C 00000000 */  nop
.size func_004ef310, 0x50
