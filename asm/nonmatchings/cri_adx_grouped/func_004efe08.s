.section .text
.set noat
.set noreorder
glabel func_004efe08
    /* 3EFE08 004EFE08 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3EFE0C 004EFE0C 2D48C000 */  daddu      $9, $6, $0
    /* 3EFE10 004EFE10 0000BFFF */  sd         $31, 0x0($29)
    /* 3EFE14 004EFE14 9200023C */  lui        $2, %hi(D_009259C0)
    /* 3EFE18 004EFE18 C0594224 */  addiu      $2, $2, %lo(D_009259C0)
    /* 3EFE1C 004EFE1C 04000624 */  addiu      $6, $0, 0x4
    /* 3EFE20 004EFE20 0000238D */  lw         $3, 0x0($9)
    /* 3EFE24 004EFE24 2D380000 */  daddu      $7, $0, $0
    /* 3EFE28 004EFE28 000044AC */  sw         $4, 0x0($2)
    /* 3EFE2C 004EFE2C 27000424 */  addiu      $4, $0, 0x27
    /* 3EFE30 004EFE30 040045AC */  sw         $5, 0x4($2)
    /* 3EFE34 004EFE34 2D284000 */  daddu      $5, $2, $0
    /* 3EFE38 004EFE38 080043AC */  sw         $3, 0x8($2)
    /* 3EFE3C 004EFE3C 2D400000 */  daddu      $8, $0, $0
    /* 3EFE40 004EFE40 0000BFDF */  ld         $31, 0x0($29)
    /* 3EFE44 004EFE44 0400238D */  lw         $3, 0x4($9)
    /* 3EFE48 004EFE48 0C0043AC */  sw         $3, 0xC($2)
    /* 3EFE4C 004EFE4C 28961308 */  j          func_004e58a0
    /* 3EFE50 004EFE50 1000BD27 */   addiu     $29, $29, 0x10
    /* 3EFE54 004EFE54 00000000 */  nop
.size func_004efe08, 0x50
