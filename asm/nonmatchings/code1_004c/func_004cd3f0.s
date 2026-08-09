.section .text
.set noat
.set noreorder
glabel func_004cd3f0
    /* 3CD3F0 004CD3F0 7200023C */  lui        $2, %hi(D_007212D0)
    /* 3CD3F4 004CD3F4 10FFBD27 */  addiu      $29, $29, -0xF0
    /* 3CD3F8 004CD3F8 D0124C8C */  lw         $12, %lo(D_007212D0)($2)
    /* 3CD3FC 004CD3FC 2D188000 */  daddu      $3, $4, $0
    /* 3CD400 004CD400 02000D24 */  addiu      $13, $0, 0x2
    /* 3CD404 004CD404 B800A5FF */  sd         $5, 0xB8($29)
    /* 3CD408 004CD408 C000A6FF */  sd         $6, 0xC0($29)
    /* 3CD40C 004CD40C B800A627 */  addiu      $6, $29, 0xB8
    /* 3CD410 004CD410 8000BFFF */  sd         $31, 0x80($29)
    /* 3CD414 004CD414 2D20A003 */  daddu      $4, $29, $0
    /* 3CD418 004CD418 2D286000 */  daddu      $5, $3, $0
    /* 3CD41C 004CD41C C800A7FF */  sd         $7, 0xC8($29)
    /* 3CD420 004CD420 D000A8FF */  sd         $8, 0xD0($29)
    /* 3CD424 004CD424 D800A9FF */  sd         $9, 0xD8($29)
    /* 3CD428 004CD428 E000AAFF */  sd         $10, 0xE0($29)
    /* 3CD42C 004CD42C E800ABFF */  sd         $11, 0xE8($29)
    /* 3CD430 004CD430 9800ACE7 */  swc1       $f12, 0x98($29)
    /* 3CD434 004CD434 9C00ADE7 */  swc1       $f13, 0x9C($29)
    /* 3CD438 004CD438 A000AEE7 */  swc1       $f14, 0xA0($29)
    /* 3CD43C 004CD43C A400AFE7 */  swc1       $f15, 0xA4($29)
    /* 3CD440 004CD440 A800B0E7 */  swc1       $f16, 0xA8($29)
    /* 3CD444 004CD444 AC00B1E7 */  swc1       $f17, 0xAC($29)
    /* 3CD448 004CD448 B000B2E7 */  swc1       $f18, 0xB0($29)
    /* 3CD44C 004CD44C 05008D11 */  beq        $12, $13, .L004CD464
    /* 3CD450 004CD450 B400B3E7 */   swc1      $f19, 0xB4($29)
    /* 3CD454 004CD454 B61B110C */  jal        func_00446ed8
    /* 3CD458 004CD458 00000000 */   nop
    /* 3CD45C 004CD45C 3291100C */  jal        func_004244c8
    /* 3CD460 004CD460 2D20A003 */   daddu     $4, $29, $0
  .L004CD464:
    /* 3CD464 004CD464 8000BFDF */  ld         $31, 0x80($29)
    /* 3CD468 004CD468 0800E003 */  jr         $31
    /* 3CD46C 004CD46C F000BD27 */   addiu     $29, $29, 0xF0
.size func_004cd3f0, 0x80
