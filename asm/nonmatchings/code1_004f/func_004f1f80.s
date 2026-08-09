.section .text
.set noat
.set noreorder
glabel func_004f1f80
    /* 3F1F80 004F1F80 7600033C */  lui        $3, %hi(D_0075D650)
    /* 3F1F84 004F1F84 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3F1F88 004F1F88 50D66324 */  addiu      $3, $3, %lo(D_0075D650)
    /* 3F1F8C 004F1F8C 7400023C */  lui        $2, %hi(D_00743A48)
    /* 3F1F90 004F1F90 0000BFFF */  sd         $31, 0x0($29)
    /* 3F1F94 004F1F94 483A43AC */  sw         $3, %lo(D_00743A48)($2)
    /* 3F1F98 004F1F98 0C00628C */  lw         $2, 0xC($3)
    /* 3F1F9C 004F1F9C 09F84000 */  jalr       $2
    /* 3F1FA0 004F1FA0 2D286000 */   daddu     $5, $3, $0
    /* 3F1FA4 004F1FA4 0000BFDF */  ld         $31, 0x0($29)
    /* 3F1FA8 004F1FA8 0800E003 */  jr         $31
    /* 3F1FAC 004F1FAC 1000BD27 */   addiu     $29, $29, 0x10
.size func_004f1f80, 0x30
