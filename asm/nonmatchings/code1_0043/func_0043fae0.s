.section .text
.set noat
.set noreorder
glabel func_0043fae0
    /* 33FAE0 0043FAE0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 33FAE4 0043FAE4 0000BFFF */  sd         $31, 0x0($29)
    /* 33FAE8 0043FAE8 AC88100C */  jal        QueryIntrContext
    /* 33FAEC 0043FAEC 00000000 */   nop
    /* 33FAF0 0043FAF0 01000F24 */  addiu      $15, $0, 0x1
    /* 33FAF4 0043FAF4 0C004F10 */  beq        $2, $15, .L0043FB28
    /* 33FAF8 0043FAF8 71000E3C */   lui       $14, %hi(D_007104D8)
    /* 33FAFC 0043FAFC D804CF8D */  lw         $15, %lo(D_007104D8)($14)
    /* 33FB00 0043FB00 FFFFEF25 */  addiu      $15, $15, -0x1
    /* 33FB04 0043FB04 0800E015 */  bnez       $15, .L0043FB28
    /* 33FB08 0043FB08 D804CFAD */   sw        $15, %lo(D_007104D8)($14)
    /* 33FB0C 0043FB0C 71000E3C */  lui        $14, %hi(D_007104DC)
    /* 33FB10 0043FB10 DC04CF8D */  lw         $15, %lo(D_007104DC)($14)
    /* 33FB14 0043FB14 0500E011 */  beqz       $15, .L0043FB2C
    /* 33FB18 0043FB18 0000BFDF */   ld        $31, 0x0($29)
    /* 33FB1C 0043FB1C DC04C0AD */  sw         $0, %lo(D_007104DC)($14)
    /* 33FB20 0043FB20 9CAE1008 */  j          func_0042ba70
    /* 33FB24 0043FB24 1000BD27 */   addiu     $29, $29, 0x10
  .L0043FB28:
    /* 33FB28 0043FB28 0000BFDF */  ld         $31, 0x0($29)
  .L0043FB2C:
    /* 33FB2C 0043FB2C 0800E003 */  jr         $31
    /* 33FB30 0043FB30 1000BD27 */   addiu     $29, $29, 0x10
    /* 33FB34 0043FB34 00000000 */  nop
.size func_0043fae0, 0x58
