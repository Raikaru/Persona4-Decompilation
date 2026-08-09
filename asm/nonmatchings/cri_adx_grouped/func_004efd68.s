.section .text
.set noat
.set noreorder
glabel func_004efd68
    /* 3EFD68 004EFD68 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3EFD6C 004EFD6C 9200053C */  lui        $5, %hi(D_009259C0)
    /* 3EFD70 004EFD70 0000BFFF */  sd         $31, 0x0($29)
    /* 3EFD74 004EFD74 C059A524 */  addiu      $5, $5, %lo(D_009259C0)
    /* 3EFD78 004EFD78 0000A4AC */  sw         $4, 0x0($5)
    /* 3EFD7C 004EFD7C 25000424 */  addiu      $4, $0, 0x25
    /* 3EFD80 004EFD80 0000BFDF */  ld         $31, 0x0($29)
    /* 3EFD84 004EFD84 01000624 */  addiu      $6, $0, 0x1
    /* 3EFD88 004EFD88 2D380000 */  daddu      $7, $0, $0
    /* 3EFD8C 004EFD8C 2D400000 */  daddu      $8, $0, $0
    /* 3EFD90 004EFD90 28961308 */  j          func_004e58a0
    /* 3EFD94 004EFD94 1000BD27 */   addiu     $29, $29, 0x10
.size func_004efd68, 0x30
