.section .text
.set noat
.set noreorder
glabel func_004d4da0
    /* 3D4DA0 004D4DA0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D4DA4 004D4DA4 06008014 */  bnez       $4, .L004D4DC0
    /* 3D4DA8 004D4DA8 0000BFFF */   sd        $31, 0x0($29)
    /* 3D4DAC 004D4DAC 7600043C */  lui        $4, %hi(D_00758D68)
    /* 3D4DB0 004D4DB0 A61A130C */  jal        func_004c6a98
    /* 3D4DB4 004D4DB4 688D8424 */   addiu     $4, $4, %lo(D_00758D68)
    /* 3D4DB8 004D4DB8 09000010 */  b          .L004D4DE0
    /* 3D4DBC 004D4DBC FFFF0224 */   addiu     $2, $0, -0x1
  .L004D4DC0:
    /* 3D4DC0 004D4DC0 01008280 */  lb         $2, 0x1($4)
    /* 3D4DC4 004D4DC4 02004228 */  slti       $2, $2, 0x2
    /* 3D4DC8 004D4DC8 05004054 */  bnel       $2, $0, .L004D4DE0
    /* 3D4DCC 004D4DCC 2D100000 */   daddu     $2, $0, $0
    /* 3D4DD0 004D4DD0 0400848C */  lw         $4, 0x4($4)
    /* 3D4DD4 004D4DD4 0000BFDF */  ld         $31, 0x0($29)
    /* 3D4DD8 004D4DD8 063C1308 */  j          func_004cf018
    /* 3D4DDC 004D4DDC 1000BD27 */   addiu     $29, $29, 0x10
  .L004D4DE0:
    /* 3D4DE0 004D4DE0 0000BFDF */  ld         $31, 0x0($29)
    /* 3D4DE4 004D4DE4 0800E003 */  jr         $31
    /* 3D4DE8 004D4DE8 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D4DEC 004D4DEC 00000000 */  nop
.size func_004d4da0, 0x50
