.section .text
.set noat
.set noreorder
glabel func_004d5d98
    /* 3D5D98 004D5D98 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D5D9C 004D5D9C 06008014 */  bnez       $4, .L004D5DB8
    /* 3D5DA0 004D5DA0 0000BFFF */   sd        $31, 0x0($29)
    /* 3D5DA4 004D5DA4 7600043C */  lui        $4, %hi(D_00759100)
    /* 3D5DA8 004D5DA8 A61A130C */  jal        func_004c6a98
    /* 3D5DAC 004D5DAC 00918424 */   addiu     $4, $4, %lo(D_00759100)
    /* 3D5DB0 004D5DB0 02000010 */  b          .L004D5DBC
    /* 3D5DB4 004D5DB4 FFFF0224 */   addiu     $2, $0, -0x1
  .L004D5DB8:
    /* 3D5DB8 004D5DB8 4C00828C */  lw         $2, 0x4C($4)
  .L004D5DBC:
    /* 3D5DBC 004D5DBC 0000BFDF */  ld         $31, 0x0($29)
    /* 3D5DC0 004D5DC0 0800E003 */  jr         $31
    /* 3D5DC4 004D5DC4 1000BD27 */   addiu     $29, $29, 0x10
.size func_004d5d98, 0x30
