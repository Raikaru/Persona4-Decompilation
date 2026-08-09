.section .text
.set noat
.set noreorder
glabel func_003e3e60
    /* 2E3E60 003E3E60 FFFFC624 */  addiu      $6, $6, -0x1
    /* 2E3E64 003E3E64 2400C004 */  bltz       $6, .L003E3EF8
    /* 2E3E68 003E3E68 2D108000 */   daddu     $2, $4, $0
    /* 2E3E6C 003E3E6C 0000EEC4 */  lwc1       $f14, 0x0($7)
    /* 2E3E70 003E3E70 0400EDC4 */  lwc1       $f13, 0x4($7)
    /* 2E3E74 003E3E74 0800ECC4 */  lwc1       $f12, 0x8($7)
    /* 2E3E78 003E3E78 1000EAC4 */  lwc1       $f10, 0x10($7)
    /* 2E3E7C 003E3E7C 1400E8C4 */  lwc1       $f8, 0x14($7)
    /* 2E3E80 003E3E80 1800E6C4 */  lwc1       $f6, 0x18($7)
    /* 2E3E84 003E3E84 2000E3C4 */  lwc1       $f3, 0x20($7)
    /* 2E3E88 003E3E88 2400E2C4 */  lwc1       $f2, 0x24($7)
    /* 2E3E8C 003E3E8C 2800E1C4 */  lwc1       $f1, 0x28($7)
    /* 2E3E90 003E3E90 00488044 */  mtc1       $0, $f9
  .L003E3E94:
    /* 2E3E94 003E3E94 0000A0C4 */  lwc1       $f0, 0x0($5)
    /* 2E3E98 003E3E98 FFFFC624 */  addiu      $6, $6, -0x1
    /* 2E3E9C 003E3E9C 0400A5C4 */  lwc1       $f5, 0x4($5)
    /* 2E3EA0 003E3EA0 0800A4C4 */  lwc1       $f4, 0x8($5)
    /* 2E3EA4 003E3EA4 C2010D46 */  mul.s      $f7, $f0, $f13
    /* 2E3EA8 003E3EA8 0C00A524 */  addiu      $5, $5, 0xC
    /* 2E3EAC 003E3EAC C2020C46 */  mul.s      $f11, $f0, $f12
    /* 2E3EB0 003E3EB0 1A000E46 */  mula.s     $f0, $f14
    /* 2E3EB4 003E3EB4 1C280A46 */  madd.s     $f0, $f5, $f10
    /* 2E3EB8 003E3EB8 18480746 */  adda.s     $f9, $f7
    /* 2E3EBC 003E3EBC DC290846 */  madd.s     $f7, $f5, $f8
    /* 2E3EC0 003E3EC0 18480B46 */  adda.s     $f9, $f11
    /* 2E3EC4 003E3EC4 5C290646 */  madd.s     $f5, $f5, $f6
    /* 2E3EC8 003E3EC8 18480046 */  adda.s     $f9, $f0
    /* 2E3ECC 003E3ECC 1C200346 */  madd.s     $f0, $f4, $f3
    /* 2E3ED0 003E3ED0 000080E4 */  swc1       $f0, 0x0($4)
    /* 2E3ED4 003E3ED4 18480746 */  adda.s     $f9, $f7
    /* 2E3ED8 003E3ED8 1C200246 */  madd.s     $f0, $f4, $f2
    /* 2E3EDC 003E3EDC 040080E4 */  swc1       $f0, 0x4($4)
    /* 2E3EE0 003E3EE0 18480546 */  adda.s     $f9, $f5
    /* 2E3EE4 003E3EE4 1C200146 */  madd.s     $f0, $f4, $f1
    /* 2E3EE8 003E3EE8 080080E4 */  swc1       $f0, 0x8($4)
    /* 2E3EEC 003E3EEC E9FFC104 */  bgez       $6, .L003E3E94
    /* 2E3EF0 003E3EF0 0C008424 */   addiu     $4, $4, 0xC
    /* 2E3EF4 003E3EF4 00000000 */  nop
  .L003E3EF8:
    /* 2E3EF8 003E3EF8 0800E003 */  jr         $31
    /* 2E3EFC 003E3EFC 00000000 */   nop
.size func_003e3e60, 0xa0
