.section .text
.set noat
.set noreorder
glabel func_004ef160
    /* 3EF160 004EF160 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 3EF164 004EF164 0000B0FF */  sd         $16, 0x0($29)
    /* 3EF168 004EF168 2D808000 */  daddu      $16, $4, $0
    /* 3EF16C 004EF16C 0800B1FF */  sd         $17, 0x8($29)
    /* 3EF170 004EF170 2D88A000 */  daddu      $17, $5, $0
    /* 3EF174 004EF174 1000B2FF */  sd         $18, 0x10($29)
    /* 3EF178 004EF178 2D90C000 */  daddu      $18, $6, $0
    /* 3EF17C 004EF17C 1800B3FF */  sd         $19, 0x18($29)
    /* 3EF180 004EF180 2000BFFF */  sd         $31, 0x20($29)
    /* 3EF184 004EF184 14B5130C */  jal        func_004ed450
    /* 3EF188 004EF188 2D98E000 */   daddu     $19, $7, $0
    /* 3EF18C 004EF18C 2D200002 */  daddu      $4, $16, $0
    /* 3EF190 004EF190 2D282002 */  daddu      $5, $17, $0
    /* 3EF194 004EF194 2D304002 */  daddu      $6, $18, $0
    /* 3EF198 004EF198 70BC130C */  jal        func_004ef1c0
    /* 3EF19C 004EF19C 2D386002 */   daddu     $7, $19, $0
    /* 3EF1A0 004EF1A0 0000B0DF */  ld         $16, 0x0($29)
    /* 3EF1A4 004EF1A4 0800B1DF */  ld         $17, 0x8($29)
    /* 3EF1A8 004EF1A8 1000B2DF */  ld         $18, 0x10($29)
    /* 3EF1AC 004EF1AC 1800B3DF */  ld         $19, 0x18($29)
    /* 3EF1B0 004EF1B0 2000BFDF */  ld         $31, 0x20($29)
    /* 3EF1B4 004EF1B4 1AB51308 */  j          func_004ed468
    /* 3EF1B8 004EF1B8 3000BD27 */   addiu     $29, $29, 0x30
    /* 3EF1BC 004EF1BC 00000000 */  nop
.size func_004ef160, 0x60
