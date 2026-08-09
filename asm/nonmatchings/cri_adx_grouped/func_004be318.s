.section .text
.set noat
.set noreorder
glabel func_004be318
    /* 3BE318 004BE318 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3BE31C 004BE31C 0000B0FF */  sd         $16, 0x0($29)
    /* 3BE320 004BE320 2D800000 */  daddu      $16, $0, $0
    /* 3BE324 004BE324 0800B1FF */  sd         $17, 0x8($29)
    /* 3BE328 004BE328 2D888000 */  daddu      $17, $4, $0
    /* 3BE32C 004BE32C 1000B2FF */  sd         $18, 0x10($29)
    /* 3BE330 004BE330 1800BFFF */  sd         $31, 0x18($29)
    /* 3BE334 004BE334 0C00228E */  lw         $2, 0xC($17)
    /* 3BE338 004BE338 0B004018 */  blez       $2, .L004BE368
    /* 3BE33C 004BE33C 2D90A000 */   daddu     $18, $5, $0
    /* 3BE340 004BE340 2D280002 */  daddu      $5, $16, $0
    /* 3BE344 004BE344 00000000 */  nop
  .L004BE348:
    /* 3BE348 004BE348 01001026 */  addiu      $16, $16, 0x1
    /* 3BE34C 004BE34C 2D202002 */  daddu      $4, $17, $0
    /* 3BE350 004BE350 EAF8120C */  jal        func_004be3a8
    /* 3BE354 004BE354 2D304002 */   daddu     $6, $18, $0
    /* 3BE358 004BE358 0C00228E */  lw         $2, 0xC($17)
    /* 3BE35C 004BE35C 2A100202 */  slt        $2, $16, $2
    /* 3BE360 004BE360 F9FF4014 */  bnez       $2, .L004BE348
    /* 3BE364 004BE364 2D280002 */   daddu     $5, $16, $0
  .L004BE368:
    /* 3BE368 004BE368 0000B0DF */  ld         $16, 0x0($29)
    /* 3BE36C 004BE36C 0800B1DF */  ld         $17, 0x8($29)
    /* 3BE370 004BE370 1000B2DF */  ld         $18, 0x10($29)
    /* 3BE374 004BE374 1800BFDF */  ld         $31, 0x18($29)
    /* 3BE378 004BE378 0800E003 */  jr         $31
    /* 3BE37C 004BE37C 2000BD27 */   addiu     $29, $29, 0x20
.size func_004be318, 0x68
