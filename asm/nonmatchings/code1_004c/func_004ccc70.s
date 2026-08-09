.section .text
.set noat
.set noreorder
glabel func_004ccc70
    /* 3CCC70 004CCC70 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CCC74 004CCC74 7200023C */  lui        $2, %hi(D_007199EC)
    /* 3CCC78 004CCC78 0000BFFF */  sd         $31, 0x0($29)
    /* 3CCC7C 004CCC7C 01000324 */  addiu      $3, $0, 0x1
    /* 3CCC80 004CCC80 EC994224 */  addiu      $2, $2, %lo(D_007199EC)
    /* 3CCC84 004CCC84 0000BFDF */  ld         $31, 0x0($29)
    /* 3CCC88 004CCC88 000043AC */  sw         $3, 0x0($2)
    /* 3CCC8C 004CCC8C 4A2F1308 */  j          func_004cbd28
    /* 3CCC90 004CCC90 1000BD27 */   addiu     $29, $29, 0x10
    /* 3CCC94 004CCC94 00000000 */  nop
.size func_004ccc70, 0x28
