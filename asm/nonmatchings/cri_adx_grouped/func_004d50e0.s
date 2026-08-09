.section .text
.set noat
.set noreorder
glabel func_004d50e0
    /* 3D50E0 004D50E0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D50E4 004D50E4 06008014 */  bnez       $4, .L004D5100
    /* 3D50E8 004D50E8 0000BFFF */   sd        $31, 0x0($29)
    /* 3D50EC 004D50EC 7600043C */  lui        $4, %hi(D_00758E58)
    /* 3D50F0 004D50F0 A61A130C */  jal        func_004c6a98
    /* 3D50F4 004D50F4 588E8424 */   addiu     $4, $4, %lo(D_00758E58)
    /* 3D50F8 004D50F8 02000010 */  b          .L004D5104
    /* 3D50FC 004D50FC 2D100000 */   daddu     $2, $0, $0
  .L004D5100:
    /* 3D5100 004D5100 46008284 */  lh         $2, 0x46($4)
  .L004D5104:
    /* 3D5104 004D5104 0000BFDF */  ld         $31, 0x0($29)
    /* 3D5108 004D5108 0800E003 */  jr         $31
    /* 3D510C 004D510C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004d50e0, 0x30
