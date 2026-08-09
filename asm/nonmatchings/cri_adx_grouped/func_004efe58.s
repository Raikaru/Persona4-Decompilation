.section .text
.set noat
.set noreorder
glabel func_004efe58
    /* 3EFE58 004EFE58 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3EFE5C 004EFE5C 2D48C000 */  daddu      $9, $6, $0
    /* 3EFE60 004EFE60 0000BFFF */  sd         $31, 0x0($29)
    /* 3EFE64 004EFE64 9200023C */  lui        $2, %hi(D_009259C0)
    /* 3EFE68 004EFE68 C0594224 */  addiu      $2, $2, %lo(D_009259C0)
    /* 3EFE6C 004EFE6C 04000624 */  addiu      $6, $0, 0x4
    /* 3EFE70 004EFE70 0000238D */  lw         $3, 0x0($9)
    /* 3EFE74 004EFE74 2D380000 */  daddu      $7, $0, $0
    /* 3EFE78 004EFE78 000044AC */  sw         $4, 0x0($2)
    /* 3EFE7C 004EFE7C 28000424 */  addiu      $4, $0, 0x28
    /* 3EFE80 004EFE80 040045AC */  sw         $5, 0x4($2)
    /* 3EFE84 004EFE84 2D284000 */  daddu      $5, $2, $0
    /* 3EFE88 004EFE88 080043AC */  sw         $3, 0x8($2)
    /* 3EFE8C 004EFE8C 2D400000 */  daddu      $8, $0, $0
    /* 3EFE90 004EFE90 0000BFDF */  ld         $31, 0x0($29)
    /* 3EFE94 004EFE94 0400238D */  lw         $3, 0x4($9)
    /* 3EFE98 004EFE98 0C0043AC */  sw         $3, 0xC($2)
    /* 3EFE9C 004EFE9C 28961308 */  j          func_004e58a0
    /* 3EFEA0 004EFEA0 1000BD27 */   addiu     $29, $29, 0x10
    /* 3EFEA4 004EFEA4 00000000 */  nop
.size func_004efe58, 0x50
