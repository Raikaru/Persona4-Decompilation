.section .text
.set noat
.set noreorder
glabel func_004fb518
    /* 3FB518 004FB518 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3FB51C 004FB51C 0000B0FF */  sd         $16, 0x0($29)
    /* 3FB520 004FB520 2D808000 */  daddu      $16, $4, $0
    /* 3FB524 004FB524 0800B1FF */  sd         $17, 0x8($29)
    /* 3FB528 004FB528 2D88C000 */  daddu      $17, $6, $0
    /* 3FB52C 004FB52C 1000B2FF */  sd         $18, 0x10($29)
    /* 3FB530 004FB530 1800BFFF */  sd         $31, 0x18($29)
    /* 3FB534 004FB534 1E04140C */  jal        func_00501078
    /* 3FB538 004FB538 2D90A000 */   daddu     $18, $5, $0
    /* 3FB53C 004FB53C 03FF053C */  lui        $5, (0xFF030203 >> 16)
    /* 3FB540 004FB540 04001026 */  addiu      $16, $16, 0x4
    /* 3FB544 004FB544 2D200000 */  daddu      $4, $0, $0
    /* 3FB548 004FB548 07004010 */  beqz       $2, .L004FB568
    /* 3FB54C 004FB54C 0302A534 */   ori       $5, $5, (0xFF030203 & 0xFFFF)
    /* 3FB550 004FB550 0000B0DF */  ld         $16, 0x0($29)
    /* 3FB554 004FB554 0800B1DF */  ld         $17, 0x8($29)
    /* 3FB558 004FB558 1000B2DF */  ld         $18, 0x10($29)
    /* 3FB55C 004FB55C 1800BFDF */  ld         $31, 0x18($29)
    /* 3FB560 004FB560 82ED1308 */  j          func_004fb608
    /* 3FB564 004FB564 2000BD27 */   addiu     $29, $29, 0x20
  .L004FB568:
    /* 3FB568 004FB568 040011AE */  sw         $17, 0x4($16)
    /* 3FB56C 004FB56C 000012AE */  sw         $18, 0x0($16)
    /* 3FB570 004FB570 0800B1DF */  ld         $17, 0x8($29)
    /* 3FB574 004FB574 0000B0DF */  ld         $16, 0x0($29)
    /* 3FB578 004FB578 1000B2DF */  ld         $18, 0x10($29)
    /* 3FB57C 004FB57C 1800BFDF */  ld         $31, 0x18($29)
    /* 3FB580 004FB580 0800E003 */  jr         $31
    /* 3FB584 004FB584 2000BD27 */   addiu     $29, $29, 0x20
.size func_004fb518, 0x70
