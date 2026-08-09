.section .text
.set noat
.set noreorder
glabel func_004d6780
    /* 3D6780 004D6780 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D6784 004D6784 08008014 */  bnez       $4, .L004D67A8
    /* 3D6788 004D6788 0000BFFF */   sd        $31, 0x0($29)
    /* 3D678C 004D678C 7600043C */  lui        $4, %hi(D_00759288)
    /* 3D6790 004D6790 A61A130C */  jal        func_004c6a98
    /* 3D6794 004D6794 88928424 */   addiu     $4, $4, %lo(D_00759288)
    /* 3D6798 004D6798 FFFF0224 */  addiu      $2, $0, -0x1
    /* 3D679C 004D679C 0000BFDF */  ld         $31, 0x0($29)
    /* 3D67A0 004D67A0 0800E003 */  jr         $31
    /* 3D67A4 004D67A4 1000BD27 */   addiu     $29, $29, 0x10
  .L004D67A8:
    /* 3D67A8 004D67A8 0400848C */  lw         $4, 0x4($4)
    /* 3D67AC 004D67AC 0000BFDF */  ld         $31, 0x0($29)
    /* 3D67B0 004D67B0 FC3A1308 */  j          func_004cebf0
    /* 3D67B4 004D67B4 1000BD27 */   addiu     $29, $29, 0x10
.size func_004d6780, 0x38
