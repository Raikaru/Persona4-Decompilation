.section .text
.set noat
.set noreorder
glabel func_004d4c90
    /* 3D4C90 004D4C90 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D4C94 004D4C94 06008014 */  bnez       $4, .L004D4CB0
    /* 3D4C98 004D4C98 0000BFFF */   sd        $31, 0x0($29)
    /* 3D4C9C 004D4C9C 7600043C */  lui        $4, %hi(D_00758D08)
    /* 3D4CA0 004D4CA0 A61A130C */  jal        func_004c6a98
    /* 3D4CA4 004D4CA4 088D8424 */   addiu     $4, $4, %lo(D_00758D08)
    /* 3D4CA8 004D4CA8 09000010 */  b          .L004D4CD0
    /* 3D4CAC 004D4CAC FFFF0224 */   addiu     $2, $0, -0x1
  .L004D4CB0:
    /* 3D4CB0 004D4CB0 01008280 */  lb         $2, 0x1($4)
    /* 3D4CB4 004D4CB4 02004228 */  slti       $2, $2, 0x2
    /* 3D4CB8 004D4CB8 05004054 */  bnel       $2, $0, .L004D4CD0
    /* 3D4CBC 004D4CBC 2D100000 */   daddu     $2, $0, $0
    /* 3D4CC0 004D4CC0 0400848C */  lw         $4, 0x4($4)
    /* 3D4CC4 004D4CC4 0000BFDF */  ld         $31, 0x0($29)
    /* 3D4CC8 004D4CC8 6A3B1308 */  j          func_004ceda8
    /* 3D4CCC 004D4CCC 1000BD27 */   addiu     $29, $29, 0x10
  .L004D4CD0:
    /* 3D4CD0 004D4CD0 0000BFDF */  ld         $31, 0x0($29)
    /* 3D4CD4 004D4CD4 0800E003 */  jr         $31
    /* 3D4CD8 004D4CD8 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D4CDC 004D4CDC 00000000 */  nop
.size func_004d4c90, 0x50
