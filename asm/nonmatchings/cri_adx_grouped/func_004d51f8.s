.section .text
.set noat
.set noreorder
glabel func_004d51f8
    /* 3D51F8 004D51F8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D51FC 004D51FC 06008014 */  bnez       $4, .L004D5218
    /* 3D5200 004D5200 0000BFFF */   sd        $31, 0x0($29)
    /* 3D5204 004D5204 7600043C */  lui        $4, %hi(D_00758EB8)
    /* 3D5208 004D5208 A61A130C */  jal        func_004c6a98
    /* 3D520C 004D520C B88E8424 */   addiu     $4, $4, %lo(D_00758EB8)
    /* 3D5210 004D5210 02000010 */  b          .L004D521C
    /* 3D5214 004D5214 2D100000 */   daddu     $2, $0, $0
  .L004D5218:
    /* 3D5218 004D5218 40008284 */  lh         $2, 0x40($4)
  .L004D521C:
    /* 3D521C 004D521C 0000BFDF */  ld         $31, 0x0($29)
    /* 3D5220 004D5220 0800E003 */  jr         $31
    /* 3D5224 004D5224 1000BD27 */   addiu     $29, $29, 0x10
.size func_004d51f8, 0x30
