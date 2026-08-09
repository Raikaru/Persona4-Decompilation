.section .text
.set noat
.set noreorder
glabel func_004cd2f8
    /* 3CD2F8 004CD2F8 7200023C */  lui        $2, %hi(D_007212D0)
    /* 3CD2FC 004CD2FC 10FFBD27 */  addiu      $29, $29, -0xF0
    /* 3CD300 004CD300 D0124C8C */  lw         $12, %lo(D_007212D0)($2)
    /* 3CD304 004CD304 2D188000 */  daddu      $3, $4, $0
    /* 3CD308 004CD308 02000D24 */  addiu      $13, $0, 0x2
    /* 3CD30C 004CD30C B800A5FF */  sd         $5, 0xB8($29)
    /* 3CD310 004CD310 C000A6FF */  sd         $6, 0xC0($29)
    /* 3CD314 004CD314 B800A627 */  addiu      $6, $29, 0xB8
    /* 3CD318 004CD318 8000BFFF */  sd         $31, 0x80($29)
    /* 3CD31C 004CD31C 2D20A003 */  daddu      $4, $29, $0
    /* 3CD320 004CD320 2D286000 */  daddu      $5, $3, $0
    /* 3CD324 004CD324 C800A7FF */  sd         $7, 0xC8($29)
    /* 3CD328 004CD328 D000A8FF */  sd         $8, 0xD0($29)
    /* 3CD32C 004CD32C D800A9FF */  sd         $9, 0xD8($29)
    /* 3CD330 004CD330 E000AAFF */  sd         $10, 0xE0($29)
    /* 3CD334 004CD334 E800ABFF */  sd         $11, 0xE8($29)
    /* 3CD338 004CD338 9800ACE7 */  swc1       $f12, 0x98($29)
    /* 3CD33C 004CD33C 9C00ADE7 */  swc1       $f13, 0x9C($29)
    /* 3CD340 004CD340 A000AEE7 */  swc1       $f14, 0xA0($29)
    /* 3CD344 004CD344 A400AFE7 */  swc1       $f15, 0xA4($29)
    /* 3CD348 004CD348 A800B0E7 */  swc1       $f16, 0xA8($29)
    /* 3CD34C 004CD34C AC00B1E7 */  swc1       $f17, 0xAC($29)
    /* 3CD350 004CD350 B000B2E7 */  swc1       $f18, 0xB0($29)
    /* 3CD354 004CD354 05008D11 */  beq        $12, $13, .L004CD36C
    /* 3CD358 004CD358 B400B3E7 */   swc1      $f19, 0xB4($29)
    /* 3CD35C 004CD35C B61B110C */  jal        func_00446ed8
    /* 3CD360 004CD360 00000000 */   nop
    /* 3CD364 004CD364 3291100C */  jal        func_004244c8
    /* 3CD368 004CD368 2D20A003 */   daddu     $4, $29, $0
  .L004CD36C:
    /* 3CD36C 004CD36C 8000BFDF */  ld         $31, 0x80($29)
    /* 3CD370 004CD370 0800E003 */  jr         $31
    /* 3CD374 004CD374 F000BD27 */   addiu     $29, $29, 0xF0
.size func_004cd2f8, 0x80
