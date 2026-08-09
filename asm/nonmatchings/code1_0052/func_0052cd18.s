.section .text
.set noat
.set noreorder
glabel func_0052cd18
    /* 42CD18 0052CD18 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 42CD1C 0052CD1C 10000224 */  addiu      $2, $0, 0x10
    /* 42CD20 0052CD20 0000BFFF */  sd         $31, 0x0($29)
    /* 42CD24 0052CD24 1100852C */  sltiu      $5, $4, 0x11
    /* 42CD28 0052CD28 0F008210 */  beq        $4, $2, .L0052CD68
    /* 42CD2C 0052CD2C 01000324 */   addiu     $3, $0, 0x1
    /* 42CD30 0052CD30 0800A014 */  bnez       $5, .L0052CD54
    /* 42CD34 0052CD34 7600063C */   lui       $6, %hi(D_00760F60)
    /* 42CD38 0052CD38 18000224 */  addiu      $2, $0, 0x18
    /* 42CD3C 0052CD3C 0A008210 */  beq        $4, $2, .L0052CD68
    /* 42CD40 0052CD40 02000324 */   addiu     $3, $0, 0x2
    /* 42CD44 0052CD44 20000224 */  addiu      $2, $0, 0x20
    /* 42CD48 0052CD48 07008210 */  beq        $4, $2, .L0052CD68
    /* 42CD4C 0052CD4C 03000324 */   addiu     $3, $0, 0x3
    /* 42CD50 0052CD50 7600063C */  lui        $6, %hi(D_00760F60)
  .L0052CD54:
    /* 42CD54 0052CD54 2D200000 */  daddu      $4, $0, $0
    /* 42CD58 0052CD58 600FC624 */  addiu      $6, $6, %lo(D_00760F60)
    /* 42CD5C 0052CD5C 68AE140C */  jal        func_0052b9a0
    /* 42CD60 0052CD60 2D280000 */   daddu     $5, $0, $0
    /* 42CD64 0052CD64 2D180000 */  daddu      $3, $0, $0
  .L0052CD68:
    /* 42CD68 0052CD68 0000BFDF */  ld         $31, 0x0($29)
    /* 42CD6C 0052CD6C 2D106000 */  daddu      $2, $3, $0
    /* 42CD70 0052CD70 0800E003 */  jr         $31
    /* 42CD74 0052CD74 1000BD27 */   addiu     $29, $29, 0x10
.size func_0052cd18, 0x60
