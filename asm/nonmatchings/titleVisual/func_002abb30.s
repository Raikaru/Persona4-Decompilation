.section .text
.set noat
.set noreorder
glabel func_002abb30
    /* 1ABB30 002ABB30 30FFBD27 */  addiu      $29, $29, -0xD0
    /* 1ABB34 002ABB34 8000BFFF */  sd         $31, 0x80($29)
    /* 1ABB38 002ABB38 7000B67F */  sq         $22, 0x70($29)
    /* 1ABB3C 002ABB3C 6000B57F */  sq         $21, 0x60($29)
    /* 1ABB40 002ABB40 5000B47F */  sq         $20, 0x50($29)
    /* 1ABB44 002ABB44 4000B37F */  sq         $19, 0x40($29)
    /* 1ABB48 002ABB48 3000B27F */  sq         $18, 0x30($29)
    /* 1ABB4C 002ABB4C 2000B17F */  sq         $17, 0x20($29)
    /* 1ABB50 002ABB50 1000B07F */  sq         $16, 0x10($29)
    /* 1ABB54 002ABB54 0C00B7E7 */  swc1       $f23, 0xC($29)
    /* 1ABB58 002ABB58 0800B6E7 */  swc1       $f22, 0x8($29)
    /* 1ABB5C 002ABB5C 0400B5E7 */  swc1       $f21, 0x4($29)
    /* 1ABB60 002ABB60 0000B4E7 */  swc1       $f20, 0x0($29)
    /* 1ABB64 002ABB64 C6650046 */  mov.s      $f23, $f12
    /* 1ABB68 002ABB68 866D0046 */  mov.s      $f22, $f13
    /* 1ABB6C 002ABB6C 46750046 */  mov.s      $f21, $f14
    /* 1ABB70 002ABB70 2DA88000 */  daddu      $21, $4, $0
    /* 1ABB74 002ABB74 2DA0A000 */  daddu      $20, $5, $0
    /* 1ABB78 002ABB78 067D0046 */  mov.s      $f20, $f15
    /* 1ABB7C 002ABB7C 2D98C000 */  daddu      $19, $6, $0
    /* 1ABB80 002ABB80 2DB0E000 */  daddu      $22, $7, $0
    /* 1ABB84 002ABB84 2D900001 */  daddu      $18, $8, $0
    /* 1ABB88 002ABB88 C800A327 */  addiu      $3, $29, 0xC8
    /* 1ABB8C 002ABB8C 04000224 */  addiu      $2, $0, 0x4
    /* 1ABB90 002ABB90 08006010 */  beqz       $3, .L002ABBB4
    /* 1ABB94 002ABB94 00000000 */   nop
  .L002ABB98:
    /* 1ABB98 002ABB98 000060A0 */  sb         $0, 0x0($3)
    /* 1ABB9C 002ABB9C 01006324 */  addiu      $3, $3, 0x1
    /* 1ABBA0 002ABBA0 FFFF4224 */  addiu      $2, $2, -0x1
    /* 1ABBA4 002ABBA4 00000000 */  nop
    /* 1ABBA8 002ABBA8 00000000 */  nop
    /* 1ABBAC 002ABBAC FAFF4014 */  bnez       $2, .L002ABB98
    /* 1ABBB0 002ABBB0 00000000 */   nop
  .L002ABBB4:
    /* 1ABBB4 002ABBB4 C800A0C7 */  lwc1       $f0, 0xC8($29)
    /* 1ABBB8 002ABBB8 CC00A0E7 */  swc1       $f0, 0xCC($29)
    /* 1ABBBC 002ABBBC 6400043C */  lui        $4, %hi(D_0063EE50)
    /* 1ABBC0 002ABBC0 50EE8424 */  addiu      $4, $4, %lo(D_0063EE50)
    /* 1ABBC4 002ABBC4 91000524 */  addiu      $5, $0, 0x91
    /* 1ABBC8 002ABBC8 A43A110C */  jal        func_0044ea90
    /* 1ABBCC 002ABBCC 00000000 */   nop
    /* 1ABBD0 002ABBD0 8800103C */  lui        $16, %hi(D_008873F4)
    /* 1ABBD4 002ABBD4 F4731026 */  addiu      $16, $16, %lo(D_008873F4)
    /* 1ABBD8 002ABBD8 01000424 */  addiu      $4, $0, 0x1
    /* 1ABBDC 002ABBDC 1C000524 */  addiu      $5, $0, 0x1C
    /* 1ABBE0 002ABBE0 0400063C */  lui        $6, (0x40000 >> 16)
    /* 1ABBE4 002ABBE4 0000028E */  lw         $2, 0x0($16)
    /* 1ABBE8 002ABBE8 09F84000 */  jalr       $2
    /* 1ABBEC 002ABBEC 00000000 */   nop
    /* 1ABBF0 002ABBF0 2D884000 */  daddu      $17, $2, $0
    /* 1ABBF4 002ABBF4 B000A327 */  addiu      $3, $29, 0xB0
    /* 1ABBF8 002ABBF8 10000224 */  addiu      $2, $0, 0x10
    /* 1ABBFC 002ABBFC 08006010 */  beqz       $3, .L002ABC20
    /* 1ABC00 002ABC00 00000000 */   nop
  .L002ABC04:
    /* 1ABC04 002ABC04 000060A0 */  sb         $0, 0x0($3)
    /* 1ABC08 002ABC08 01006324 */  addiu      $3, $3, 0x1
    /* 1ABC0C 002ABC0C FFFF4224 */  addiu      $2, $2, -0x1
    /* 1ABC10 002ABC10 00000000 */  nop
    /* 1ABC14 002ABC14 00000000 */  nop
    /* 1ABC18 002ABC18 FAFF4014 */  bnez       $2, .L002ABC04
    /* 1ABC1C 002ABC1C 00000000 */   nop
  .L002ABC20:
    /* 1ABC20 002ABC20 B000A0AF */  sw         $0, 0xB0($29)
    /* 1ABC24 002ABC24 B400A0AF */  sw         $0, 0xB4($29)
    /* 1ABC28 002ABC28 80020224 */  addiu      $2, $0, 0x280
    /* 1ABC2C 002ABC2C B800A2AF */  sw         $2, 0xB8($29)
    /* 1ABC30 002ABC30 E0010224 */  addiu      $2, $0, 0x1E0
    /* 1ABC34 002ABC34 BC00A2AF */  sw         $2, 0xBC($29)
    /* 1ABC38 002ABC38 B000A3C7 */  lwc1       $f3, 0xB0($29)
    /* 1ABC3C 002ABC3C B400A2C7 */  lwc1       $f2, 0xB4($29)
    /* 1ABC40 002ABC40 B800A1C7 */  lwc1       $f1, 0xB8($29)
    /* 1ABC44 002ABC44 BC00A0C7 */  lwc1       $f0, 0xBC($29)
    /* 1ABC48 002ABC48 000023E6 */  swc1       $f3, 0x0($17)
    /* 1ABC4C 002ABC4C 040022E6 */  swc1       $f2, 0x4($17)
    /* 1ABC50 002ABC50 080021E6 */  swc1       $f1, 0x8($17)
    /* 1ABC54 002ABC54 0C0020E6 */  swc1       $f0, 0xC($17)
    /* 1ABC58 002ABC58 100020AE */  sw         $0, 0x10($17)
    /* 1ABC5C 002ABC5C CC00A593 */  lbu        $5, 0xCC($29)
    /* 1ABC60 002ABC60 CD00A493 */  lbu        $4, 0xCD($29)
    /* 1ABC64 002ABC64 CE00A393 */  lbu        $3, 0xCE($29)
    /* 1ABC68 002ABC68 CF00A293 */  lbu        $2, 0xCF($29)
    /* 1ABC6C 002ABC6C 140025A2 */  sb         $5, 0x14($17)
    /* 1ABC70 002ABC70 150024A2 */  sb         $4, 0x15($17)
    /* 1ABC74 002ABC74 160023A2 */  sb         $3, 0x16($17)
    /* 1ABC78 002ABC78 170022A2 */  sb         $2, 0x17($17)
    /* 1ABC7C 002ABC7C 12000224 */  addiu      $2, $0, 0x12
    /* 1ABC80 002ABC80 180022AE */  sw         $2, 0x18($17)
    /* 1ABC84 002ABC84 0D004012 */  beqz       $18, .L002ABCBC
    /* 1ABC88 002ABC88 00000000 */   nop
    /* 1ABC8C 002ABC8C 6482110C */  jal        func_00460990
    /* 1ABC90 002ABC90 00000000 */   nop
    /* 1ABC94 002ABC94 2D284000 */  daddu      $5, $2, $0
    /* 1ABC98 002ABC98 2B00033C */  lui        $3, %hi(func_002aabf0)
    /* 1ABC9C 002ABC9C F0AB6324 */  addiu      $3, $3, %lo(func_002aabf0)
    /* 1ABCA0 002ABCA0 080043AC */  sw         $3, 0x8($2)
    /* 1ABCA4 002ABCA4 100051AC */  sw         $17, 0x10($2)
    /* 1ABCA8 002ABCA8 2D204002 */  daddu      $4, $18, $0
    /* 1ABCAC 002ABCAC B082110C */  jal        func_00460ac0
    /* 1ABCB0 002ABCB0 00000000 */   nop
    /* 1ABCB4 002ABCB4 05000010 */  b          .L002ABCCC
    /* 1ABCB8 002ABCB8 00000000 */   nop
  .L002ABCBC:
    /* 1ABCBC 002ABCBC 2D200000 */  daddu      $4, $0, $0
    /* 1ABCC0 002ABCC0 2D282002 */  daddu      $5, $17, $0
    /* 1ABCC4 002ABCC4 FCAA0A0C */  jal        func_002aabf0
    /* 1ABCC8 002ABCC8 00000000 */   nop
  .L002ABCCC:
    /* 1ABCCC 002ABCCC 06BB0046 */  mov.s      $f12, $f23
    /* 1ABCD0 002ABCD0 46B30046 */  mov.s      $f13, $f22
    /* 1ABCD4 002ABCD4 86AB0046 */  mov.s      $f14, $f21
    /* 1ABCD8 002ABCD8 2D20A002 */  daddu      $4, $21, $0
    /* 1ABCDC 002ABCDC 2D288002 */  daddu      $5, $20, $0
    /* 1ABCE0 002ABCE0 C6A30046 */  mov.s      $f15, $f20
    /* 1ABCE4 002ABCE4 2D306002 */  daddu      $6, $19, $0
    /* 1ABCE8 002ABCE8 2D38C002 */  daddu      $7, $22, $0
    /* 1ABCEC 002ABCEC 2D404002 */  daddu      $8, $18, $0
    /* 1ABCF0 002ABCF0 E4AD0A0C */  jal        func_002ab790
    /* 1ABCF4 002ABCF4 00000000 */   nop
    /* 1ABCF8 002ABCF8 00121500 */  sll        $2, $21, 8
    /* 1ABCFC 002ABCFC 25185400 */  or         $3, $2, $20
    /* 1ABD00 002ABD00 02160300 */  srl        $2, $3, 24
    /* 1ABD04 002ABD04 CC00A2A3 */  sb         $2, 0xCC($29)
    /* 1ABD08 002ABD08 02140300 */  srl        $2, $3, 16
    /* 1ABD0C 002ABD0C CD00A2A3 */  sb         $2, 0xCD($29)
    /* 1ABD10 002ABD10 02120300 */  srl        $2, $3, 8
    /* 1ABD14 002ABD14 CE00A2A3 */  sb         $2, 0xCE($29)
    /* 1ABD18 002ABD18 CF00A3A3 */  sb         $3, 0xCF($29)
    /* 1ABD1C 002ABD1C 6400043C */  lui        $4, %hi(D_0063EE50)
    /* 1ABD20 002ABD20 50EE8424 */  addiu      $4, $4, %lo(D_0063EE50)
    /* 1ABD24 002ABD24 91000524 */  addiu      $5, $0, 0x91
    /* 1ABD28 002ABD28 A43A110C */  jal        func_0044ea90
    /* 1ABD2C 002ABD2C 00000000 */   nop
    /* 1ABD30 002ABD30 01000424 */  addiu      $4, $0, 0x1
    /* 1ABD34 002ABD34 1C000524 */  addiu      $5, $0, 0x1C
    /* 1ABD38 002ABD38 0400063C */  lui        $6, (0x40000 >> 16)
    /* 1ABD3C 002ABD3C 0000028E */  lw         $2, 0x0($16)
    /* 1ABD40 002ABD40 09F84000 */  jalr       $2
    /* 1ABD44 002ABD44 00000000 */   nop
    /* 1ABD48 002ABD48 2D884000 */  daddu      $17, $2, $0
    /* 1ABD4C 002ABD4C A000A327 */  addiu      $3, $29, 0xA0
    /* 1ABD50 002ABD50 10000224 */  addiu      $2, $0, 0x10
    /* 1ABD54 002ABD54 08006010 */  beqz       $3, .L002ABD78
    /* 1ABD58 002ABD58 00000000 */   nop
  .L002ABD5C:
    /* 1ABD5C 002ABD5C 000060A0 */  sb         $0, 0x0($3)
    /* 1ABD60 002ABD60 01006324 */  addiu      $3, $3, 0x1
    /* 1ABD64 002ABD64 FFFF4224 */  addiu      $2, $2, -0x1
    /* 1ABD68 002ABD68 00000000 */  nop
    /* 1ABD6C 002ABD6C 00000000 */  nop
    /* 1ABD70 002ABD70 FAFF4014 */  bnez       $2, .L002ABD5C
    /* 1ABD74 002ABD74 00000000 */   nop
  .L002ABD78:
    /* 1ABD78 002ABD78 A000A0AF */  sw         $0, 0xA0($29)
    /* 1ABD7C 002ABD7C A400A0AF */  sw         $0, 0xA4($29)
    /* 1ABD80 002ABD80 80020224 */  addiu      $2, $0, 0x280
    /* 1ABD84 002ABD84 A800A2AF */  sw         $2, 0xA8($29)
    /* 1ABD88 002ABD88 E0010224 */  addiu      $2, $0, 0x1E0
    /* 1ABD8C 002ABD8C AC00A2AF */  sw         $2, 0xAC($29)
    /* 1ABD90 002ABD90 A000A3C7 */  lwc1       $f3, 0xA0($29)
    /* 1ABD94 002ABD94 A400A2C7 */  lwc1       $f2, 0xA4($29)
    /* 1ABD98 002ABD98 A800A1C7 */  lwc1       $f1, 0xA8($29)
    /* 1ABD9C 002ABD9C AC00A0C7 */  lwc1       $f0, 0xAC($29)
    /* 1ABDA0 002ABDA0 000023E6 */  swc1       $f3, 0x0($17)
    /* 1ABDA4 002ABDA4 040022E6 */  swc1       $f2, 0x4($17)
    /* 1ABDA8 002ABDA8 080021E6 */  swc1       $f1, 0x8($17)
    /* 1ABDAC 002ABDAC 0C0020E6 */  swc1       $f0, 0xC($17)
    /* 1ABDB0 002ABDB0 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 1ABDB4 002ABDB4 100022AE */  sw         $2, 0x10($17)
    /* 1ABDB8 002ABDB8 CC00A593 */  lbu        $5, 0xCC($29)
    /* 1ABDBC 002ABDBC CD00A493 */  lbu        $4, 0xCD($29)
    /* 1ABDC0 002ABDC0 CE00A393 */  lbu        $3, 0xCE($29)
    /* 1ABDC4 002ABDC4 CF00A293 */  lbu        $2, 0xCF($29)
    /* 1ABDC8 002ABDC8 140025A2 */  sb         $5, 0x14($17)
    /* 1ABDCC 002ABDCC 150024A2 */  sb         $4, 0x15($17)
    /* 1ABDD0 002ABDD0 160023A2 */  sb         $3, 0x16($17)
    /* 1ABDD4 002ABDD4 170022A2 */  sb         $2, 0x17($17)
    /* 1ABDD8 002ABDD8 01000224 */  addiu      $2, $0, 0x1
    /* 1ABDDC 002ABDDC 180022AE */  sw         $2, 0x18($17)
    /* 1ABDE0 002ABDE0 0D004012 */  beqz       $18, .L002ABE18
    /* 1ABDE4 002ABDE4 00000000 */   nop
    /* 1ABDE8 002ABDE8 6482110C */  jal        func_00460990
    /* 1ABDEC 002ABDEC 00000000 */   nop
    /* 1ABDF0 002ABDF0 2D284000 */  daddu      $5, $2, $0
    /* 1ABDF4 002ABDF4 2B00033C */  lui        $3, %hi(func_002aabf0)
    /* 1ABDF8 002ABDF8 F0AB6324 */  addiu      $3, $3, %lo(func_002aabf0)
    /* 1ABDFC 002ABDFC 080043AC */  sw         $3, 0x8($2)
    /* 1ABE00 002ABE00 100051AC */  sw         $17, 0x10($2)
    /* 1ABE04 002ABE04 2D204002 */  daddu      $4, $18, $0
    /* 1ABE08 002ABE08 B082110C */  jal        func_00460ac0
    /* 1ABE0C 002ABE0C 00000000 */   nop
    /* 1ABE10 002ABE10 05000010 */  b          .L002ABE28
    /* 1ABE14 002ABE14 00000000 */   nop
  .L002ABE18:
    /* 1ABE18 002ABE18 2D200000 */  daddu      $4, $0, $0
    /* 1ABE1C 002ABE1C 2D282002 */  daddu      $5, $17, $0
    /* 1ABE20 002ABE20 FCAA0A0C */  jal        func_002aabf0
    /* 1ABE24 002ABE24 00000000 */   nop
  .L002ABE28:
    /* 1ABE28 002ABE28 6400043C */  lui        $4, %hi(D_0063EE50)
    /* 1ABE2C 002ABE2C 50EE8424 */  addiu      $4, $4, %lo(D_0063EE50)
    /* 1ABE30 002ABE30 91000524 */  addiu      $5, $0, 0x91
    /* 1ABE34 002ABE34 A43A110C */  jal        func_0044ea90
    /* 1ABE38 002ABE38 00000000 */   nop
    /* 1ABE3C 002ABE3C 01000424 */  addiu      $4, $0, 0x1
    /* 1ABE40 002ABE40 1C000524 */  addiu      $5, $0, 0x1C
    /* 1ABE44 002ABE44 0400063C */  lui        $6, (0x40000 >> 16)
    /* 1ABE48 002ABE48 0000028E */  lw         $2, 0x0($16)
    /* 1ABE4C 002ABE4C 09F84000 */  jalr       $2
    /* 1ABE50 002ABE50 00000000 */   nop
    /* 1ABE54 002ABE54 2D804000 */  daddu      $16, $2, $0
    /* 1ABE58 002ABE58 9000A327 */  addiu      $3, $29, 0x90
    /* 1ABE5C 002ABE5C 10000224 */  addiu      $2, $0, 0x10
    /* 1ABE60 002ABE60 08006010 */  beqz       $3, .L002ABE84
    /* 1ABE64 002ABE64 00000000 */   nop
  .L002ABE68:
    /* 1ABE68 002ABE68 000060A0 */  sb         $0, 0x0($3)
    /* 1ABE6C 002ABE6C 01006324 */  addiu      $3, $3, 0x1
    /* 1ABE70 002ABE70 FFFF4224 */  addiu      $2, $2, -0x1
    /* 1ABE74 002ABE74 00000000 */  nop
    /* 1ABE78 002ABE78 00000000 */  nop
    /* 1ABE7C 002ABE7C FAFF4014 */  bnez       $2, .L002ABE68
    /* 1ABE80 002ABE80 00000000 */   nop
  .L002ABE84:
    /* 1ABE84 002ABE84 9000A0AF */  sw         $0, 0x90($29)
    /* 1ABE88 002ABE88 9400A0AF */  sw         $0, 0x94($29)
    /* 1ABE8C 002ABE8C 80020224 */  addiu      $2, $0, 0x280
    /* 1ABE90 002ABE90 9800A2AF */  sw         $2, 0x98($29)
    /* 1ABE94 002ABE94 E0010224 */  addiu      $2, $0, 0x1E0
    /* 1ABE98 002ABE98 9C00A2AF */  sw         $2, 0x9C($29)
    /* 1ABE9C 002ABE9C 9000A3C7 */  lwc1       $f3, 0x90($29)
    /* 1ABEA0 002ABEA0 9400A2C7 */  lwc1       $f2, 0x94($29)
    /* 1ABEA4 002ABEA4 9800A1C7 */  lwc1       $f1, 0x98($29)
    /* 1ABEA8 002ABEA8 9C00A0C7 */  lwc1       $f0, 0x9C($29)
    /* 1ABEAC 002ABEAC 000003E6 */  swc1       $f3, 0x0($16)
    /* 1ABEB0 002ABEB0 040002E6 */  swc1       $f2, 0x4($16)
    /* 1ABEB4 002ABEB4 080001E6 */  swc1       $f1, 0x8($16)
    /* 1ABEB8 002ABEB8 0C0000E6 */  swc1       $f0, 0xC($16)
    /* 1ABEBC 002ABEBC 100000AE */  sw         $0, 0x10($16)
    /* 1ABEC0 002ABEC0 CC00A593 */  lbu        $5, 0xCC($29)
    /* 1ABEC4 002ABEC4 CD00A493 */  lbu        $4, 0xCD($29)
    /* 1ABEC8 002ABEC8 CE00A393 */  lbu        $3, 0xCE($29)
    /* 1ABECC 002ABECC CF00A293 */  lbu        $2, 0xCF($29)
    /* 1ABED0 002ABED0 140005A2 */  sb         $5, 0x14($16)
    /* 1ABED4 002ABED4 150004A2 */  sb         $4, 0x15($16)
    /* 1ABED8 002ABED8 160003A2 */  sb         $3, 0x16($16)
    /* 1ABEDC 002ABEDC 170002A2 */  sb         $2, 0x17($16)
    /* 1ABEE0 002ABEE0 08000224 */  addiu      $2, $0, 0x8
    /* 1ABEE4 002ABEE4 180002AE */  sw         $2, 0x18($16)
    /* 1ABEE8 002ABEE8 0D004012 */  beqz       $18, .L002ABF20
    /* 1ABEEC 002ABEEC 00000000 */   nop
    /* 1ABEF0 002ABEF0 6482110C */  jal        func_00460990
    /* 1ABEF4 002ABEF4 00000000 */   nop
    /* 1ABEF8 002ABEF8 2D284000 */  daddu      $5, $2, $0
    /* 1ABEFC 002ABEFC 2B00033C */  lui        $3, %hi(func_002aabf0)
    /* 1ABF00 002ABF00 F0AB6324 */  addiu      $3, $3, %lo(func_002aabf0)
    /* 1ABF04 002ABF04 080043AC */  sw         $3, 0x8($2)
    /* 1ABF08 002ABF08 100050AC */  sw         $16, 0x10($2)
    /* 1ABF0C 002ABF0C 2D204002 */  daddu      $4, $18, $0
    /* 1ABF10 002ABF10 B082110C */  jal        func_00460ac0
    /* 1ABF14 002ABF14 00000000 */   nop
    /* 1ABF18 002ABF18 05000010 */  b          .L002ABF30
    /* 1ABF1C 002ABF1C 00000000 */   nop
  .L002ABF20:
    /* 1ABF20 002ABF20 2D200000 */  daddu      $4, $0, $0
    /* 1ABF24 002ABF24 2D280002 */  daddu      $5, $16, $0
    /* 1ABF28 002ABF28 FCAA0A0C */  jal        func_002aabf0
    /* 1ABF2C 002ABF2C 00000000 */   nop
  .L002ABF30:
    /* 1ABF30 002ABF30 8000BFDF */  ld         $31, 0x80($29)
    /* 1ABF34 002ABF34 7000B67B */  lq         $22, 0x70($29)
    /* 1ABF38 002ABF38 6000B57B */  lq         $21, 0x60($29)
    /* 1ABF3C 002ABF3C 5000B47B */  lq         $20, 0x50($29)
    /* 1ABF40 002ABF40 4000B37B */  lq         $19, 0x40($29)
    /* 1ABF44 002ABF44 3000B27B */  lq         $18, 0x30($29)
    /* 1ABF48 002ABF48 2000B17B */  lq         $17, 0x20($29)
    /* 1ABF4C 002ABF4C 1000B07B */  lq         $16, 0x10($29)
    /* 1ABF50 002ABF50 0C00B7C7 */  lwc1       $f23, 0xC($29)
    /* 1ABF54 002ABF54 0800B6C7 */  lwc1       $f22, 0x8($29)
    /* 1ABF58 002ABF58 0400B5C7 */  lwc1       $f21, 0x4($29)
    /* 1ABF5C 002ABF5C 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* 1ABF60 002ABF60 D000BD27 */  addiu      $29, $29, 0xD0
    /* 1ABF64 002ABF64 0800E003 */  jr         $31
    /* 1ABF68 002ABF68 00000000 */   nop
    /* 1ABF6C 002ABF6C 00000000 */  nop
.size func_002abb30, 0x440
