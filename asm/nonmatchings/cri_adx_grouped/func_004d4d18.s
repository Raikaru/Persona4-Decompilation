.section .text
.set noat
.set noreorder
glabel func_004d4d18
    /* 3D4D18 004D4D18 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D4D1C 004D4D1C 06008014 */  bnez       $4, .L004D4D38
    /* 3D4D20 004D4D20 0000BFFF */   sd        $31, 0x0($29)
    /* 3D4D24 004D4D24 7600043C */  lui        $4, %hi(D_00758D38)
    /* 3D4D28 004D4D28 A61A130C */  jal        func_004c6a98
    /* 3D4D2C 004D4D2C 388D8424 */   addiu     $4, $4, %lo(D_00758D38)
    /* 3D4D30 004D4D30 09000010 */  b          .L004D4D58
    /* 3D4D34 004D4D34 FFFF0224 */   addiu     $2, $0, -0x1
  .L004D4D38:
    /* 3D4D38 004D4D38 01008280 */  lb         $2, 0x1($4)
    /* 3D4D3C 004D4D3C 02004228 */  slti       $2, $2, 0x2
    /* 3D4D40 004D4D40 05004054 */  bnel       $2, $0, .L004D4D58
    /* 3D4D44 004D4D44 2D100000 */   daddu     $2, $0, $0
    /* 3D4D48 004D4D48 0400848C */  lw         $4, 0x4($4)
    /* 3D4D4C 004D4D4C 0000BFDF */  ld         $31, 0x0($29)
    /* 3D4D50 004D4D50 043C1308 */  j          func_004cf010
    /* 3D4D54 004D4D54 1000BD27 */   addiu     $29, $29, 0x10
  .L004D4D58:
    /* 3D4D58 004D4D58 0000BFDF */  ld         $31, 0x0($29)
    /* 3D4D5C 004D4D5C 0800E003 */  jr         $31
    /* 3D4D60 004D4D60 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D4D64 004D4D64 00000000 */  nop
.size func_004d4d18, 0x50
