.section .text
.set noat
.set noreorder
glabel func_003e3d00
    /* 2E3D00 003E3D00 FFFFC624 */  addiu      $6, $6, -0x1
    /* 2E3D04 003E3D04 2A00C004 */  bltz       $6, .L003E3DB0
    /* 2E3D08 003E3D08 2D108000 */   daddu     $2, $4, $0
    /* 2E3D0C 003E3D0C 0000F1C4 */  lwc1       $f17, 0x0($7)
    /* 2E3D10 003E3D10 0400F0C4 */  lwc1       $f16, 0x4($7)
    /* 2E3D14 003E3D14 0800EFC4 */  lwc1       $f15, 0x8($7)
    /* 2E3D18 003E3D18 1000EDC4 */  lwc1       $f13, 0x10($7)
    /* 2E3D1C 003E3D1C 1400EBC4 */  lwc1       $f11, 0x14($7)
    /* 2E3D20 003E3D20 1800E9C4 */  lwc1       $f9, 0x18($7)
    /* 2E3D24 003E3D24 2000E7C4 */  lwc1       $f7, 0x20($7)
    /* 2E3D28 003E3D28 2400E6C4 */  lwc1       $f6, 0x24($7)
    /* 2E3D2C 003E3D2C 2800E5C4 */  lwc1       $f5, 0x28($7)
    /* 2E3D30 003E3D30 3000E3C4 */  lwc1       $f3, 0x30($7)
    /* 2E3D34 003E3D34 3400E2C4 */  lwc1       $f2, 0x34($7)
    /* 2E3D38 003E3D38 3800E1C4 */  lwc1       $f1, 0x38($7)
    /* 2E3D3C 003E3D3C 00608044 */  mtc1       $0, $f12
  .L003E3D40:
    /* 2E3D40 003E3D40 0000A0C4 */  lwc1       $f0, 0x0($5)
    /* 2E3D44 003E3D44 FFFFC624 */  addiu      $6, $6, -0x1
    /* 2E3D48 003E3D48 0400A8C4 */  lwc1       $f8, 0x4($5)
    /* 2E3D4C 003E3D4C 0800A4C4 */  lwc1       $f4, 0x8($5)
    /* 2E3D50 003E3D50 82021046 */  mul.s      $f10, $f0, $f16
    /* 2E3D54 003E3D54 0C00A524 */  addiu      $5, $5, 0xC
    /* 2E3D58 003E3D58 82030F46 */  mul.s      $f14, $f0, $f15
    /* 2E3D5C 003E3D5C 1A001146 */  mula.s     $f0, $f17
    /* 2E3D60 003E3D60 1C400D46 */  madd.s     $f0, $f8, $f13
    /* 2E3D64 003E3D64 18600A46 */  adda.s     $f12, $f10
    /* 2E3D68 003E3D68 9C420B46 */  madd.s     $f10, $f8, $f11
    /* 2E3D6C 003E3D6C 18600E46 */  adda.s     $f12, $f14
    /* 2E3D70 003E3D70 1C420946 */  madd.s     $f8, $f8, $f9
    /* 2E3D74 003E3D74 18600046 */  adda.s     $f12, $f0
    /* 2E3D78 003E3D78 1C200746 */  madd.s     $f0, $f4, $f7
    /* 2E3D7C 003E3D7C 00000346 */  add.s      $f0, $f0, $f3
    /* 2E3D80 003E3D80 18600A46 */  adda.s     $f12, $f10
    /* 2E3D84 003E3D84 000080E4 */  swc1       $f0, 0x0($4)
    /* 2E3D88 003E3D88 1C200646 */  madd.s     $f0, $f4, $f6
    /* 2E3D8C 003E3D8C 00000246 */  add.s      $f0, $f0, $f2
    /* 2E3D90 003E3D90 18600846 */  adda.s     $f12, $f8
    /* 2E3D94 003E3D94 1C210546 */  madd.s     $f4, $f4, $f5
    /* 2E3D98 003E3D98 040080E4 */  swc1       $f0, 0x4($4)
    /* 2E3D9C 003E3D9C 00200146 */  add.s      $f0, $f4, $f1
    /* 2E3DA0 003E3DA0 080080E4 */  swc1       $f0, 0x8($4)
    /* 2E3DA4 003E3DA4 E6FFC104 */  bgez       $6, .L003E3D40
    /* 2E3DA8 003E3DA8 0C008424 */   addiu     $4, $4, 0xC
    /* 2E3DAC 003E3DAC 00000000 */  nop
  .L003E3DB0:
    /* 2E3DB0 003E3DB0 0800E003 */  jr         $31
    /* 2E3DB4 003E3DB4 00000000 */   nop
    /* 2E3DB8 003E3DB8 00000000 */  nop
    /* 2E3DBC 003E3DBC 00000000 */  nop
.size func_003e3d00, 0xc0
