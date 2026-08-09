.section .text
.set noat
.set noreorder
glabel func_003dcb40
    /* 2DCB40 003DCB40 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 2DCB44 003DCB44 2A080600 */  slt        $1, $0, $6
    /* 2DCB48 003DCB48 0C00E4C4 */  lwc1       $f4, 0xC($7)
    /* 2DCB4C 003DCB4C 2D488000 */  daddu      $9, $4, $0
    /* 2DCB50 003DCB50 0400EDC4 */  lwc1       $f13, 0x4($7)
    /* 2DCB54 003DCB54 2D400000 */  daddu      $8, $0, $0
    /* 2DCB58 003DCB58 0000ECC4 */  lwc1       $f12, 0x0($7)
    /* 2DCB5C 003DCB5C 0800EBC4 */  lwc1       $f11, 0x8($7)
    /* 2DCB60 003DCB60 02200446 */  mul.s      $f0, $f4, $f4
    /* 2DCB64 003DCB64 1A680D46 */  mula.s     $f13, $f13
    /* 2DCB68 003DCB68 1E600C46 */  madda.s    $f12, $f12
    /* 2DCB6C 003DCB6C 5C580B46 */  madd.s     $f1, $f11, $f11
    /* 2DCB70 003DCB70 C1000146 */  sub.s      $f3, $f0, $f1
    /* 2DCB74 003DCB74 00600C46 */  add.s      $f0, $f12, $f12
    /* 2DCB78 003DCB78 40680D46 */  add.s      $f1, $f13, $f13
    /* 2DCB7C 003DCB7C 80580B46 */  add.s      $f2, $f11, $f11
    /* 2DCB80 003DCB80 82030446 */  mul.s      $f14, $f0, $f4
    /* 2DCB84 003DCB84 C20B0446 */  mul.s      $f15, $f1, $f4
    /* 2DCB88 003DCB88 35002010 */  beqz       $1, .L003DCC60
    /* 2DCB8C 003DCB8C 02140446 */   mul.s     $f16, $f2, $f4
    /* 2DCB90 003DCB90 00388044 */  mtc1       $0, $f7
    /* 2DCB94 003DCB94 0400A727 */  addiu      $7, $29, 0x4
    /* 2DCB98 003DCB98 0800A327 */  addiu      $3, $29, 0x8
  .L003DCB9C:
    /* 2DCB9C 003DCB9C 0400AAC4 */  lwc1       $f10, 0x4($5)
    /* 2DCBA0 003DCBA0 01000825 */  addiu      $8, $8, 0x1
    /* 2DCBA4 003DCBA4 0000A8C4 */  lwc1       $f8, 0x0($5)
    /* 2DCBA8 003DCBA8 2A100601 */  slt        $2, $8, $6
    /* 2DCBAC 003DCBAC 0800A9C4 */  lwc1       $f9, 0x8($5)
    /* 2DCBB0 003DCBB0 1A080A46 */  mula.s     $f1, $f10
    /* 2DCBB4 003DCBB4 1E000846 */  madda.s    $f0, $f8
    /* 2DCBB8 003DCBB8 9C110946 */  madd.s     $f6, $f2, $f9
    /* 2DCBBC 003DCBBC 0C00A524 */  addiu      $5, $5, 0xC
    /* 2DCBC0 003DCBC0 1A780946 */  mula.s     $f15, $f9
    /* 2DCBC4 003DCBC4 1D810A46 */  msub.s     $f4, $f16, $f10
    /* 2DCBC8 003DCBC8 0000A4E7 */  swc1       $f4, 0x0($29)
    /* 2DCBCC 003DCBCC 000024E5 */  swc1       $f4, 0x0($9)
    /* 2DCBD0 003DCBD0 1A800846 */  mula.s     $f16, $f8
    /* 2DCBD4 003DCBD4 1D710946 */  msub.s     $f4, $f14, $f9
    /* 2DCBD8 003DCBD8 0000E4E4 */  swc1       $f4, 0x0($7)
    /* 2DCBDC 003DCBDC 1A700A46 */  mula.s     $f14, $f10
    /* 2DCBE0 003DCBE0 1D790846 */  msub.s     $f4, $f15, $f8
    /* 2DCBE4 003DCBE4 0400A5C7 */  lwc1       $f5, 0x4($29)
    /* 2DCBE8 003DCBE8 000064E4 */  swc1       $f4, 0x0($3)
    /* 2DCBEC 003DCBEC 0800A4C7 */  lwc1       $f4, 0x8($29)
    /* 2DCBF0 003DCBF0 040025E5 */  swc1       $f5, 0x4($9)
    /* 2DCBF4 003DCBF4 080024E5 */  swc1       $f4, 0x8($9)
    /* 2DCBF8 003DCBF8 000024C5 */  lwc1       $f4, 0x0($9)
    /* 2DCBFC 003DCBFC 18380446 */  adda.s     $f7, $f4
    /* 2DCC00 003DCC00 1C610646 */  madd.s     $f4, $f12, $f6
    /* 2DCC04 003DCC04 000024E5 */  swc1       $f4, 0x0($9)
    /* 2DCC08 003DCC08 040024C5 */  lwc1       $f4, 0x4($9)
    /* 2DCC0C 003DCC0C 18380446 */  adda.s     $f7, $f4
    /* 2DCC10 003DCC10 1C690646 */  madd.s     $f4, $f13, $f6
    /* 2DCC14 003DCC14 040024E5 */  swc1       $f4, 0x4($9)
    /* 2DCC18 003DCC18 080024C5 */  lwc1       $f4, 0x8($9)
    /* 2DCC1C 003DCC1C 18380446 */  adda.s     $f7, $f4
    /* 2DCC20 003DCC20 1C590646 */  madd.s     $f4, $f11, $f6
    /* 2DCC24 003DCC24 080024E5 */  swc1       $f4, 0x8($9)
    /* 2DCC28 003DCC28 000024C5 */  lwc1       $f4, 0x0($9)
    /* 2DCC2C 003DCC2C 18380446 */  adda.s     $f7, $f4
    /* 2DCC30 003DCC30 1C410346 */  madd.s     $f4, $f8, $f3
    /* 2DCC34 003DCC34 000024E5 */  swc1       $f4, 0x0($9)
    /* 2DCC38 003DCC38 040024C5 */  lwc1       $f4, 0x4($9)
    /* 2DCC3C 003DCC3C 18380446 */  adda.s     $f7, $f4
    /* 2DCC40 003DCC40 1C510346 */  madd.s     $f4, $f10, $f3
    /* 2DCC44 003DCC44 040024E5 */  swc1       $f4, 0x4($9)
    /* 2DCC48 003DCC48 080024C5 */  lwc1       $f4, 0x8($9)
    /* 2DCC4C 003DCC4C 18380446 */  adda.s     $f7, $f4
    /* 2DCC50 003DCC50 1C490346 */  madd.s     $f4, $f9, $f3
    /* 2DCC54 003DCC54 080024E5 */  swc1       $f4, 0x8($9)
    /* 2DCC58 003DCC58 D0FF4014 */  bnez       $2, .L003DCB9C
    /* 2DCC5C 003DCC5C 0C002925 */   addiu     $9, $9, 0xC
  .L003DCC60:
    /* 2DCC60 003DCC60 2D108000 */  daddu      $2, $4, $0
    /* 2DCC64 003DCC64 0800E003 */  jr         $31
    /* 2DCC68 003DCC68 1000BD27 */   addiu     $29, $29, 0x10
    /* 2DCC6C 003DCC6C 00000000 */  nop
.size func_003dcb40, 0x130
