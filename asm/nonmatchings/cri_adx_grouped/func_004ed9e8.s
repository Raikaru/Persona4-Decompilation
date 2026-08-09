.section .text
.set noat
.set noreorder
glabel func_004ed9e8
    /* 3ED9E8 004ED9E8 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 3ED9EC 004ED9EC 0000B0FF */  sd         $16, 0x0($29)
    /* 3ED9F0 004ED9F0 2D808000 */  daddu      $16, $4, $0
    /* 3ED9F4 004ED9F4 0800B1FF */  sd         $17, 0x8($29)
    /* 3ED9F8 004ED9F8 2D88A000 */  daddu      $17, $5, $0
    /* 3ED9FC 004ED9FC 1000B2FF */  sd         $18, 0x10($29)
    /* 3EDA00 004EDA00 2D90C000 */  daddu      $18, $6, $0
    /* 3EDA04 004EDA04 1800B3FF */  sd         $19, 0x18($29)
    /* 3EDA08 004EDA08 2000BFFF */  sd         $31, 0x20($29)
    /* 3EDA0C 004EDA0C 14B5130C */  jal        func_004ed450
    /* 3EDA10 004EDA10 2D98E000 */   daddu     $19, $7, $0
    /* 3EDA14 004EDA14 2D200002 */  daddu      $4, $16, $0
    /* 3EDA18 004EDA18 2D282002 */  daddu      $5, $17, $0
    /* 3EDA1C 004EDA1C 2D304002 */  daddu      $6, $18, $0
    /* 3EDA20 004EDA20 92B6130C */  jal        func_004eda48
    /* 3EDA24 004EDA24 2D386002 */   daddu     $7, $19, $0
    /* 3EDA28 004EDA28 0000B0DF */  ld         $16, 0x0($29)
    /* 3EDA2C 004EDA2C 0800B1DF */  ld         $17, 0x8($29)
    /* 3EDA30 004EDA30 1000B2DF */  ld         $18, 0x10($29)
    /* 3EDA34 004EDA34 1800B3DF */  ld         $19, 0x18($29)
    /* 3EDA38 004EDA38 2000BFDF */  ld         $31, 0x20($29)
    /* 3EDA3C 004EDA3C 1AB51308 */  j          func_004ed468
    /* 3EDA40 004EDA40 3000BD27 */   addiu     $29, $29, 0x30
    /* 3EDA44 004EDA44 00000000 */  nop
.size func_004ed9e8, 0x60
