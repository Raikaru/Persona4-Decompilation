.section .text
.set noat
.set noreorder
glabel func_004ef488
    /* 3EF488 004EF488 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3EF48C 004EF48C 0000B0FF */  sd         $16, 0x0($29)
    /* 3EF490 004EF490 2D808000 */  daddu      $16, $4, $0
    /* 3EF494 004EF494 0800B1FF */  sd         $17, 0x8($29)
    /* 3EF498 004EF498 2D88A000 */  daddu      $17, $5, $0
    /* 3EF49C 004EF49C 1000B2FF */  sd         $18, 0x10($29)
    /* 3EF4A0 004EF4A0 1800BFFF */  sd         $31, 0x18($29)
    /* 3EF4A4 004EF4A4 14B5130C */  jal        func_004ed450
    /* 3EF4A8 004EF4A8 2D90C000 */   daddu     $18, $6, $0
    /* 3EF4AC 004EF4AC 2D200002 */  daddu      $4, $16, $0
    /* 3EF4B0 004EF4B0 2D282002 */  daddu      $5, $17, $0
    /* 3EF4B4 004EF4B4 36BD130C */  jal        func_004ef4d8
    /* 3EF4B8 004EF4B8 2D304002 */   daddu     $6, $18, $0
    /* 3EF4BC 004EF4BC 0000B0DF */  ld         $16, 0x0($29)
    /* 3EF4C0 004EF4C0 0800B1DF */  ld         $17, 0x8($29)
    /* 3EF4C4 004EF4C4 1000B2DF */  ld         $18, 0x10($29)
    /* 3EF4C8 004EF4C8 1800BFDF */  ld         $31, 0x18($29)
    /* 3EF4CC 004EF4CC 1AB51308 */  j          func_004ed468
    /* 3EF4D0 004EF4D0 2000BD27 */   addiu     $29, $29, 0x20
    /* 3EF4D4 004EF4D4 00000000 */  nop
.size func_004ef488, 0x50
