.section .text
.set noat
.set noreorder
glabel func_004edb28
    /* 3EDB28 004EDB28 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3EDB2C 004EDB2C 0000B0FF */  sd         $16, 0x0($29)
    /* 3EDB30 004EDB30 2D808000 */  daddu      $16, $4, $0
    /* 3EDB34 004EDB34 0800B1FF */  sd         $17, 0x8($29)
    /* 3EDB38 004EDB38 2D88A000 */  daddu      $17, $5, $0
    /* 3EDB3C 004EDB3C 1000B2FF */  sd         $18, 0x10($29)
    /* 3EDB40 004EDB40 1800BFFF */  sd         $31, 0x18($29)
    /* 3EDB44 004EDB44 14B5130C */  jal        func_004ed450
    /* 3EDB48 004EDB48 2D90C000 */   daddu     $18, $6, $0
    /* 3EDB4C 004EDB4C 2D200002 */  daddu      $4, $16, $0
    /* 3EDB50 004EDB50 2D282002 */  daddu      $5, $17, $0
    /* 3EDB54 004EDB54 DEB6130C */  jal        func_004edb78
    /* 3EDB58 004EDB58 2D304002 */   daddu     $6, $18, $0
    /* 3EDB5C 004EDB5C 0000B0DF */  ld         $16, 0x0($29)
    /* 3EDB60 004EDB60 0800B1DF */  ld         $17, 0x8($29)
    /* 3EDB64 004EDB64 1000B2DF */  ld         $18, 0x10($29)
    /* 3EDB68 004EDB68 1800BFDF */  ld         $31, 0x18($29)
    /* 3EDB6C 004EDB6C 1AB51308 */  j          func_004ed468
    /* 3EDB70 004EDB70 2000BD27 */   addiu     $29, $29, 0x20
    /* 3EDB74 004EDB74 00000000 */  nop
.size func_004edb28, 0x50
