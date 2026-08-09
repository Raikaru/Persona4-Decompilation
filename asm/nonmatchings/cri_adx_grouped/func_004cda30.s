.section .text
.set noat
.set noreorder
glabel func_004cda30
    /* 3CDA30 004CDA30 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CDA34 004CDA34 7200023C */  lui        $2, %hi(D_007212E0)
    /* 3CDA38 004CDA38 0000BFFF */  sd         $31, 0x0($29)
    /* 3CDA3C 004CDA3C E0124224 */  addiu      $2, $2, %lo(D_007212E0)
    /* 3CDA40 004CDA40 0000438C */  lw         $3, 0x0($2)
    /* 3CDA44 004CDA44 FFFF6324 */  addiu      $3, $3, -0x1
    /* 3CDA48 004CDA48 000043AC */  sw         $3, 0x0($2)
    /* 3CDA4C 004CDA4C 0000448C */  lw         $4, 0x0($2)
    /* 3CDA50 004CDA50 07008014 */  bnez       $4, .L004CDA70
    /* 3CDA54 004CDA54 0000BFDF */   ld        $31, 0x0($29)
    /* 3CDA58 004CDA58 7200043C */  lui        $4, %hi(D_007212E8)
    /* 3CDA5C 004CDA5C 2D280000 */  daddu      $5, $0, $0
    /* 3CDA60 004CDA60 E8128424 */  addiu      $4, $4, %lo(D_007212E8)
    /* 3CDA64 004CDA64 800A0624 */  addiu      $6, $0, 0xA80
    /* 3CDA68 004CDA68 72FE1008 */  j          func_0043f9c8
    /* 3CDA6C 004CDA6C 1000BD27 */   addiu     $29, $29, 0x10
  .L004CDA70:
    /* 3CDA70 004CDA70 0800E003 */  jr         $31
    /* 3CDA74 004CDA74 1000BD27 */   addiu     $29, $29, 0x10
.size func_004cda30, 0x48
