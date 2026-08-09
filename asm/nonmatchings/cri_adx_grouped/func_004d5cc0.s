.section .text
.set noat
.set noreorder
glabel func_004d5cc0
    /* 3D5CC0 004D5CC0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D5CC4 004D5CC4 06008014 */  bnez       $4, .L004D5CE0
    /* 3D5CC8 004D5CC8 0000BFFF */   sd        $31, 0x0($29)
    /* 3D5CCC 004D5CCC 7600043C */  lui        $4, %hi(D_007590A0)
    /* 3D5CD0 004D5CD0 A61A130C */  jal        func_004c6a98
    /* 3D5CD4 004D5CD4 A0908424 */   addiu     $4, $4, %lo(D_007590A0)
    /* 3D5CD8 004D5CD8 02000010 */  b          .L004D5CE4
    /* 3D5CDC 004D5CDC FFFF0224 */   addiu     $2, $0, -0x1
  .L004D5CE0:
    /* 3D5CE0 004D5CE0 60008284 */  lh         $2, 0x60($4)
  .L004D5CE4:
    /* 3D5CE4 004D5CE4 0000BFDF */  ld         $31, 0x0($29)
    /* 3D5CE8 004D5CE8 0800E003 */  jr         $31
    /* 3D5CEC 004D5CEC 1000BD27 */   addiu     $29, $29, 0x10
.size func_004d5cc0, 0x30
