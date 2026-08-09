.section .text
.set noat
.set noreorder
glabel func_004eff60
    /* 3EFF60 004EFF60 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3EFF64 004EFF64 7400023C */  lui        $2, %hi(D_00742E04)
    /* 3EFF68 004EFF68 0000B0FF */  sd         $16, 0x0($29)
    /* 3EFF6C 004EFF6C 042E5024 */  addiu      $16, $2, %lo(D_00742E04)
    /* 3EFF70 004EFF70 0800BFFF */  sd         $31, 0x8($29)
    /* 3EFF74 004EFF74 7400033C */  lui        $3, %hi(D_00742E00)
    /* 3EFF78 004EFF78 0000048E */  lw         $4, 0x0($16)
    /* 3EFF7C 004EFF7C 002E6324 */  addiu      $3, $3, %lo(D_00742E00)
    /* 3EFF80 004EFF80 0000628C */  lw         $2, 0x0($3)
    /* 3EFF84 004EFF84 05008014 */  bnez       $4, .L004EFF9C
    /* 3EFF88 004EFF88 01008224 */   addiu     $2, $4, 0x1
    /* 3EFF8C 004EFF8C CE95130C */  jal        func_004e5738
    /* 3EFF90 004EFF90 00000000 */   nop
    /* 3EFF94 004EFF94 0000048E */  lw         $4, 0x0($16)
    /* 3EFF98 004EFF98 01008224 */  addiu      $2, $4, 0x1
  .L004EFF9C:
    /* 3EFF9C 004EFF9C 0800BFDF */  ld         $31, 0x8($29)
    /* 3EFFA0 004EFFA0 000002AE */  sw         $2, 0x0($16)
    /* 3EFFA4 004EFFA4 0000B0DF */  ld         $16, 0x0($29)
    /* 3EFFA8 004EFFA8 0800E003 */  jr         $31
    /* 3EFFAC 004EFFAC 1000BD27 */   addiu     $29, $29, 0x10
.size func_004eff60, 0x50
