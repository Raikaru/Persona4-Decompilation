.section .text
.set noat
.set noreorder
glabel func_0014bbe0
    /* 4BBE0 0014BBE0 80FFBD27 */  addiu      $29, $29, -0x80
    /* 4BBE4 0014BBE4 6000BFFF */  sd         $31, 0x60($29)
    /* 4BBE8 0014BBE8 5000B57F */  sq         $21, 0x50($29)
    /* 4BBEC 0014BBEC 4000B47F */  sq         $20, 0x40($29)
    /* 4BBF0 0014BBF0 3000B37F */  sq         $19, 0x30($29)
    /* 4BBF4 0014BBF4 2000B27F */  sq         $18, 0x20($29)
    /* 4BBF8 0014BBF8 1000B17F */  sq         $17, 0x10($29)
    /* 4BBFC 0014BBFC 0000B07F */  sq         $16, 0x0($29)
    /* 4BC00 0014BC00 2D888000 */  daddu      $17, $4, $0
    /* 4BC04 0014BC04 2DA8A000 */  daddu      $21, $5, $0
    /* 4BC08 0014BC08 2DA0C000 */  daddu      $20, $6, $0
    /* 4BC0C 0014BC0C 2D98E000 */  daddu      $19, $7, $0
    /* 4BC10 0014BC10 2D900001 */  daddu      $18, $8, $0
    /* 4BC14 0014BC14 2D20A002 */  daddu      $4, $21, $0
    /* 4BC18 0014BC18 94E8110C */  jal        func_0047a250
    /* 4BC1C 0014BC1C 00000000 */   nop
    /* 4BC20 0014BC20 00004590 */  lbu        $5, 0x0($2)
    /* 4BC24 0014BC24 01004490 */  lbu        $4, 0x1($2)
    /* 4BC28 0014BC28 02004390 */  lbu        $3, 0x2($2)
    /* 4BC2C 0014BC2C 03004290 */  lbu        $2, 0x3($2)
    /* 4BC30 0014BC30 7C00A5A3 */  sb         $5, 0x7C($29)
    /* 4BC34 0014BC34 7D00A4A3 */  sb         $4, 0x7D($29)
    /* 4BC38 0014BC38 7E00A3A3 */  sb         $3, 0x7E($29)
    /* 4BC3C 0014BC3C 7F00A2A3 */  sb         $2, 0x7F($29)
    /* 4BC40 0014BC40 0400A016 */  bnez       $21, .L0014BC54
    /* 4BC44 0014BC44 00000000 */   nop
    /* 4BC48 0014BC48 2D100000 */  daddu      $2, $0, $0
    /* 4BC4C 0014BC4C 46000010 */  b          .L0014BD68
    /* 4BC50 0014BC50 00000000 */   nop
  .L0014BC54:
    /* 4BC54 0014BC54 5F00043C */  lui        $4, %hi(D_005EFB28)
    /* 4BC58 0014BC58 28FB8424 */  addiu      $4, $4, %lo(D_005EFB28)
    /* 4BC5C 0014BC5C C6010524 */  addiu      $5, $0, 0x1C6
    /* 4BC60 0014BC60 A43A110C */  jal        func_0044ea90
    /* 4BC64 0014BC64 00000000 */   nop
    /* 4BC68 0014BC68 01000424 */  addiu      $4, $0, 0x1
    /* 4BC6C 0014BC6C 14000524 */  addiu      $5, $0, 0x14
    /* 4BC70 0014BC70 0400063C */  lui        $6, (0x40000 >> 16)
    /* 4BC74 0014BC74 8800023C */  lui        $2, %hi(D_008873F4)
    /* 4BC78 0014BC78 F473428C */  lw         $2, %lo(D_008873F4)($2)
    /* 4BC7C 0014BC7C 09F84000 */  jalr       $2
    /* 4BC80 0014BC80 00000000 */   nop
    /* 4BC84 0014BC84 2D804000 */  daddu      $16, $2, $0
    /* 4BC88 0014BC88 04000016 */  bnez       $16, .L0014BC9C
    /* 4BC8C 0014BC8C 00000000 */   nop
    /* 4BC90 0014BC90 2D100000 */  daddu      $2, $0, $0
    /* 4BC94 0014BC94 34000010 */  b          .L0014BD68
    /* 4BC98 0014BC98 00000000 */   nop
  .L0014BC9C:
    /* 4BC9C 0014BC9C 2D202002 */  daddu      $4, $17, $0
    /* 4BCA0 0014BCA0 5F00053C */  lui        $5, %hi(D_005EFB80)
    /* 4BCA4 0014BCA4 80FBA524 */  addiu      $5, $5, %lo(D_005EFB80)
    /* 4BCA8 0014BCA8 0F000624 */  addiu      $6, $0, 0xF
    /* 4BCAC 0014BCAC 2D380000 */  daddu      $7, $0, $0
    /* 4BCB0 0014BCB0 2D400000 */  daddu      $8, $0, $0
    /* 4BCB4 0014BCB4 1500093C */  lui        $9, %hi(func_0014ba40)
    /* 4BCB8 0014BCB8 40BA2925 */  addiu      $9, $9, %lo(func_0014ba40)
    /* 4BCBC 0014BCBC 15000A3C */  lui        $10, %hi(func_0014bbb0)
    /* 4BCC0 0014BCC0 B0BB4A25 */  addiu      $10, $10, %lo(func_0014bbb0)
    /* 4BCC4 0014BCC4 2D580002 */  daddu      $11, $16, $0
    /* 4BCC8 0014BCC8 F047110C */  jal        func_00451fc0
    /* 4BCCC 0014BCCC 00000000 */   nop
    /* 4BCD0 0014BCD0 2D884000 */  daddu      $17, $2, $0
    /* 4BCD4 0014BCD4 040015AE */  sw         $21, 0x4($16)
    /* 4BCD8 0014BCD8 06006006 */  bltz       $19, .L0014BCF4
    /* 4BCDC 0014BCDC 00000000 */   nop
    /* 4BCE0 0014BCE0 00009344 */  mtc1       $19, $f0
    /* 4BCE4 0014BCE4 00000000 */  nop
    /* 4BCE8 0014BCE8 20008046 */  cvt.s.w    $f0, $f0
    /* 4BCEC 0014BCEC 08000010 */  b          .L0014BD10
    /* 4BCF0 0014BCF0 00000000 */   nop
  .L0014BCF4:
    /* 4BCF4 0014BCF4 42181300 */  srl        $3, $19, 1
    /* 4BCF8 0014BCF8 01006232 */  andi       $2, $19, 0x1
    /* 4BCFC 0014BCFC 25186200 */  or         $3, $3, $2
    /* 4BD00 0014BD00 00008344 */  mtc1       $3, $f0
    /* 4BD04 0014BD04 00000000 */  nop
    /* 4BD08 0014BD08 20008046 */  cvt.s.w    $f0, $f0
    /* 4BD0C 0014BD0C 00000046 */  add.s      $f0, $f0, $f0
  .L0014BD10:
    /* 4BD10 0014BD10 080000E6 */  swc1       $f0, 0x8($16)
    /* 4BD14 0014BD14 100012AE */  sw         $18, 0x10($16)
    /* 4BD18 0014BD18 06008006 */  bltz       $20, .L0014BD34
    /* 4BD1C 0014BD1C 00000000 */   nop
    /* 4BD20 0014BD20 00009444 */  mtc1       $20, $f0
    /* 4BD24 0014BD24 00000000 */  nop
    /* 4BD28 0014BD28 20008046 */  cvt.s.w    $f0, $f0
    /* 4BD2C 0014BD2C 08000010 */  b          .L0014BD50
    /* 4BD30 0014BD30 00000000 */   nop
  .L0014BD34:
    /* 4BD34 0014BD34 42181400 */  srl        $3, $20, 1
    /* 4BD38 0014BD38 01008232 */  andi       $2, $20, 0x1
    /* 4BD3C 0014BD3C 25186200 */  or         $3, $3, $2
    /* 4BD40 0014BD40 00008344 */  mtc1       $3, $f0
    /* 4BD44 0014BD44 00000000 */  nop
    /* 4BD48 0014BD48 20008046 */  cvt.s.w    $f0, $f0
    /* 4BD4C 0014BD4C 00000046 */  add.s      $f0, $f0, $f0
  .L0014BD50:
    /* 4BD50 0014BD50 0C0000E6 */  swc1       $f0, 0xC($16)
    /* 4BD54 0014BD54 2D20A002 */  daddu      $4, $21, $0
    /* 4BD58 0014BD58 7C00A527 */  addiu      $5, $29, 0x7C
    /* 4BD5C 0014BD5C 88E8110C */  jal        func_0047a220
    /* 4BD60 0014BD60 00000000 */   nop
    /* 4BD64 0014BD64 2D102002 */  daddu      $2, $17, $0
  .L0014BD68:
    /* 4BD68 0014BD68 6000BFDF */  ld         $31, 0x60($29)
    /* 4BD6C 0014BD6C 5000B57B */  lq         $21, 0x50($29)
    /* 4BD70 0014BD70 4000B47B */  lq         $20, 0x40($29)
    /* 4BD74 0014BD74 3000B37B */  lq         $19, 0x30($29)
    /* 4BD78 0014BD78 2000B27B */  lq         $18, 0x20($29)
    /* 4BD7C 0014BD7C 1000B17B */  lq         $17, 0x10($29)
    /* 4BD80 0014BD80 0000B07B */  lq         $16, 0x0($29)
    /* 4BD84 0014BD84 8000BD27 */  addiu      $29, $29, 0x80
    /* 4BD88 0014BD88 0800E003 */  jr         $31
    /* 4BD8C 0014BD8C 00000000 */   nop
.size func_0014bbe0, 0x1b0
