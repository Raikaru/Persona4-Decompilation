.section .text
.set noat
.set noreorder
glabel func_00528df0
    /* 428DF0 00528DF0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 428DF4 00528DF4 0000BFFF */  sd         $31, 0x0($29)
    /* 428DF8 00528DF8 90A3140C */  jal        func_00528e40
    /* 428DFC 00528DFC 00000000 */   nop
    /* 428E00 00528E00 9400033C */  lui        $3, %hi(D_00938998)
    /* 428E04 00528E04 0000BFDF */  ld         $31, 0x0($29)
    /* 428E08 00528E08 98896324 */  addiu      $3, $3, %lo(D_00938998)
    /* 428E0C 00528E0C 0400628C */  lw         $2, 0x4($3)
    /* 428E10 00528E10 FFFF4224 */  addiu      $2, $2, -0x1
    /* 428E14 00528E14 040062AC */  sw         $2, 0x4($3)
    /* 428E18 00528E18 0800E003 */  jr         $31
    /* 428E1C 00528E1C 1000BD27 */   addiu     $29, $29, 0x10
.size func_00528df0, 0x30
