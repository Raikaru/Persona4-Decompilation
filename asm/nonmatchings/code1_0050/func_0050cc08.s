.section .text
.set noat
.set noreorder
glabel func_0050cc08
    /* 40CC08 0050CC08 7400023C */  lui        $2, %hi(D_00745884)
    /* 40CC0C 0050CC0C F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40CC10 0050CC10 8458438C */  lw         $3, %lo(D_00745884)($2)
    /* 40CC14 0050CC14 06006014 */  bnez       $3, .L0050CC30
    /* 40CC18 0050CC18 0000BFFF */   sd        $31, 0x0($29)
    /* 40CC1C 0050CC1C 1E33140C */  jal        func_0050cc78
    /* 40CC20 0050CC20 00000000 */   nop
    /* 40CC24 0050CC24 05000010 */  b          .L0050CC3C
    /* 40CC28 0050CC28 0000BFDF */   ld        $31, 0x0($29)
    /* 40CC2C 0050CC2C 00000000 */  nop
  .L0050CC30:
    /* 40CC30 0050CC30 1233140C */  jal        func_0050cc48
    /* 40CC34 0050CC34 00000000 */   nop
    /* 40CC38 0050CC38 0000BFDF */  ld         $31, 0x0($29)
  .L0050CC3C:
    /* 40CC3C 0050CC3C 0800E003 */  jr         $31
    /* 40CC40 0050CC40 1000BD27 */   addiu     $29, $29, 0x10
    /* 40CC44 0050CC44 00000000 */  nop
.size func_0050cc08, 0x40
