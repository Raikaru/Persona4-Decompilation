.section .text
.set noat
.set noreorder
glabel func_004d4c08
    /* 3D4C08 004D4C08 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D4C0C 004D4C0C 06008014 */  bnez       $4, .L004D4C28
    /* 3D4C10 004D4C10 0000BFFF */   sd        $31, 0x0($29)
    /* 3D4C14 004D4C14 7600043C */  lui        $4, %hi(D_00758CD8)
    /* 3D4C18 004D4C18 A61A130C */  jal        func_004c6a98
    /* 3D4C1C 004D4C1C D88C8424 */   addiu     $4, $4, %lo(D_00758CD8)
    /* 3D4C20 004D4C20 09000010 */  b          .L004D4C48
    /* 3D4C24 004D4C24 FFFF0224 */   addiu     $2, $0, -0x1
  .L004D4C28:
    /* 3D4C28 004D4C28 01008280 */  lb         $2, 0x1($4)
    /* 3D4C2C 004D4C2C 02004228 */  slti       $2, $2, 0x2
    /* 3D4C30 004D4C30 05004054 */  bnel       $2, $0, .L004D4C48
    /* 3D4C34 004D4C34 2D100000 */   daddu     $2, $0, $0
    /* 3D4C38 004D4C38 0400848C */  lw         $4, 0x4($4)
    /* 3D4C3C 004D4C3C 0000BFDF */  ld         $31, 0x0($29)
    /* 3D4C40 004D4C40 643B1308 */  j          func_004ced90
    /* 3D4C44 004D4C44 1000BD27 */   addiu     $29, $29, 0x10
  .L004D4C48:
    /* 3D4C48 004D4C48 0000BFDF */  ld         $31, 0x0($29)
    /* 3D4C4C 004D4C4C 0800E003 */  jr         $31
    /* 3D4C50 004D4C50 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D4C54 004D4C54 00000000 */  nop
.size func_004d4c08, 0x50
