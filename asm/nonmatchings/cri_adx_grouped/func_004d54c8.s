.section .text
.set noat
.set noreorder
glabel func_004d54c8
    /* 3D54C8 004D54C8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D54CC 004D54CC 06008014 */  bnez       $4, .L004D54E8
    /* 3D54D0 004D54D0 0000BFFF */   sd        $31, 0x0($29)
    /* 3D54D4 004D54D4 7600043C */  lui        $4, %hi(D_00758EE8)
    /* 3D54D8 004D54D8 0000BFDF */  ld         $31, 0x0($29)
    /* 3D54DC 004D54DC E88E8424 */  addiu      $4, $4, %lo(D_00758EE8)
    /* 3D54E0 004D54E0 A61A1308 */  j          func_004c6a98
    /* 3D54E4 004D54E4 1000BD27 */   addiu     $29, $29, 0x10
  .L004D54E8:
    /* 3D54E8 004D54E8 0000BFDF */  ld         $31, 0x0($29)
    /* 3D54EC 004D54EC 7200023C */  lui        $2, %hi(D_00724E70)
    /* 3D54F0 004D54F0 380085AC */  sw         $5, 0x38($4)
    /* 3D54F4 004D54F4 704E45AC */  sw         $5, %lo(D_00724E70)($2)
    /* 3D54F8 004D54F8 0800E003 */  jr         $31
    /* 3D54FC 004D54FC 1000BD27 */   addiu     $29, $29, 0x10
.size func_004d54c8, 0x38
