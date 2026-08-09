.section .text
.set noat
.set noreorder
glabel func_004ee310
    /* 3EE310 004EE310 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 3EE314 004EE314 0000B0FF */  sd         $16, 0x0($29)
    /* 3EE318 004EE318 2D808000 */  daddu      $16, $4, $0
    /* 3EE31C 004EE31C 0800B1FF */  sd         $17, 0x8($29)
    /* 3EE320 004EE320 2D88A000 */  daddu      $17, $5, $0
    /* 3EE324 004EE324 1000B2FF */  sd         $18, 0x10($29)
    /* 3EE328 004EE328 2D90C000 */  daddu      $18, $6, $0
    /* 3EE32C 004EE32C 1800B3FF */  sd         $19, 0x18($29)
    /* 3EE330 004EE330 2000BFFF */  sd         $31, 0x20($29)
    /* 3EE334 004EE334 14B5130C */  jal        func_004ed450
    /* 3EE338 004EE338 2D98E000 */   daddu     $19, $7, $0
    /* 3EE33C 004EE33C 2D200002 */  daddu      $4, $16, $0
    /* 3EE340 004EE340 2D282002 */  daddu      $5, $17, $0
    /* 3EE344 004EE344 2D304002 */  daddu      $6, $18, $0
    /* 3EE348 004EE348 DCB8130C */  jal        func_004ee370
    /* 3EE34C 004EE34C 2D386002 */   daddu     $7, $19, $0
    /* 3EE350 004EE350 0000B0DF */  ld         $16, 0x0($29)
    /* 3EE354 004EE354 0800B1DF */  ld         $17, 0x8($29)
    /* 3EE358 004EE358 1000B2DF */  ld         $18, 0x10($29)
    /* 3EE35C 004EE35C 1800B3DF */  ld         $19, 0x18($29)
    /* 3EE360 004EE360 2000BFDF */  ld         $31, 0x20($29)
    /* 3EE364 004EE364 1AB51308 */  j          func_004ed468
    /* 3EE368 004EE368 3000BD27 */   addiu     $29, $29, 0x30
    /* 3EE36C 004EE36C 00000000 */  nop
.size func_004ee310, 0x60
