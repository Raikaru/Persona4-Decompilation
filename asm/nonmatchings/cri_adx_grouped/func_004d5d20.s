.section .text
.set noat
.set noreorder
glabel func_004d5d20
    /* 3D5D20 004D5D20 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D5D24 004D5D24 06008014 */  bnez       $4, .L004D5D40
    /* 3D5D28 004D5D28 0000BFFF */   sd        $31, 0x0($29)
    /* 3D5D2C 004D5D2C 7600043C */  lui        $4, %hi(D_007590D0)
    /* 3D5D30 004D5D30 0000BFDF */  ld         $31, 0x0($29)
    /* 3D5D34 004D5D34 D0908424 */  addiu      $4, $4, %lo(D_007590D0)
    /* 3D5D38 004D5D38 A61A1308 */  j          func_004c6a98
    /* 3D5D3C 004D5D3C 1000BD27 */   addiu     $29, $29, 0x10
  .L004D5D40:
    /* 3D5D40 004D5D40 0000BFDF */  ld         $31, 0x0($29)
    /* 3D5D44 004D5D44 6A0080A4 */  sh         $0, 0x6A($4)
    /* 3D5D48 004D5D48 600080A4 */  sh         $0, 0x60($4)
    /* 3D5D4C 004D5D4C 640080AC */  sw         $0, 0x64($4)
    /* 3D5D50 004D5D50 680080A4 */  sh         $0, 0x68($4)
    /* 3D5D54 004D5D54 0800E003 */  jr         $31
    /* 3D5D58 004D5D58 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D5D5C 004D5D5C 00000000 */  nop
.size func_004d5d20, 0x40
