.section .text
.set noat
.set noreorder
glabel func_002cacd0
    /* 1CACD0 002CACD0 20FFBD27 */  addiu      $29, $29, -0xE0
    /* 1CACD4 002CACD4 A000BFFF */  sd         $31, 0xA0($29)
    /* 1CACD8 002CACD8 9000BE7F */  sq         $30, 0x90($29)
    /* 1CACDC 002CACDC 8000B77F */  sq         $23, 0x80($29)
    /* 1CACE0 002CACE0 7000B67F */  sq         $22, 0x70($29)
    /* 1CACE4 002CACE4 6000B57F */  sq         $21, 0x60($29)
    /* 1CACE8 002CACE8 5000B47F */  sq         $20, 0x50($29)
    /* 1CACEC 002CACEC 4000B37F */  sq         $19, 0x40($29)
    /* 1CACF0 002CACF0 3000B27F */  sq         $18, 0x30($29)
    /* 1CACF4 002CACF4 2000B17F */  sq         $17, 0x20($29)
    /* 1CACF8 002CACF8 1000B07F */  sq         $16, 0x10($29)
    /* 1CACFC 002CACFC 0800B6E7 */  swc1       $f22, 0x8($29)
    /* 1CAD00 002CAD00 0400B5E7 */  swc1       $f21, 0x4($29)
    /* 1CAD04 002CAD04 0000B4E7 */  swc1       $f20, 0x0($29)
    /* 1CAD08 002CAD08 C000A4FF */  sd         $4, 0xC0($29)
    /* 1CAD0C 002CAD0C 86650046 */  mov.s      $f22, $f12
    /* 1CAD10 002CAD10 CC00A5AF */  sw         $5, 0xCC($29)
    /* 1CAD14 002CAD14 2DA8C000 */  daddu      $21, $6, $0
    /* 1CAD18 002CAD18 BE00A7A7 */  sh         $7, 0xBE($29)
    /* 1CAD1C 002CAD1C 2D802001 */  daddu      $16, $9, $0
    /* 1CAD20 002CAD20 2DB84001 */  daddu      $23, $10, $0
    /* 1CAD24 002CAD24 B800ABAF */  sw         $11, 0xB8($29)
    /* 1CAD28 002CAD28 2DA00001 */  daddu      $20, $8, $0
    /* 1CAD2C 002CAD2C 2D980000 */  daddu      $19, $0, $0
    /* 1CAD30 002CAD30 C000B5C7 */  lwc1       $f21, 0xC0($29)
    /* 1CAD34 002CAD34 D000A427 */  addiu      $4, $29, 0xD0
    /* 1CAD38 002CAD38 2D280000 */  daddu      $5, $0, $0
    /* 1CAD3C 002CAD3C 01000624 */  addiu      $6, $0, 0x1
    /* 1CAD40 002CAD40 72FE100C */  jal        func_0043f9c8
    /* 1CAD44 002CAD44 00000000 */   nop
    /* 1CAD48 002CAD48 E800A38F */  lw         $3, 0xE8($29)
    /* 1CAD4C 002CAD4C 40100300 */  sll        $2, $3, 1
    /* 1CAD50 002CAD50 21104300 */  addu       $2, $2, $3
    /* 1CAD54 002CAD54 00190200 */  sll        $3, $2, 4
    /* 1CAD58 002CAD58 7900023C */  lui        $2, %hi(D_00793E80)
    /* 1CAD5C 002CAD5C 803E4224 */  addiu      $2, $2, %lo(D_00793E80)
    /* 1CAD60 002CAD60 21904300 */  addu       $18, $2, $3
    /* 1CAD64 002CAD64 3CF41000 */  dsll32     $30, $16, 16
    /* 1CAD68 002CAD68 3FF41E00 */  dsra32     $30, $30, 16
    /* 1CAD6C 002CAD6C CF00B193 */  lbu        $17, 0xCF($29)
    /* 1CAD70 002CAD70 CE00B093 */  lbu        $16, 0xCE($29)
    /* 1CAD74 002CAD74 CD00B693 */  lbu        $22, 0xCD($29)
    /* 1CAD78 002CAD78 C400B4C7 */  lwc1       $f20, 0xC4($29)
    /* 1CAD7C 002CAD7C 3CBC1700 */  dsll32     $23, $23, 16
    /* 1CAD80 002CAD80 3FBC1700 */  dsra32     $23, $23, 16
  .L002CAD84:
    /* 1CAD84 002CAD84 FF000424 */  addiu      $4, $0, 0xFF
    /* 1CAD88 002CAD88 CC00A593 */  lbu        $5, 0xCC($29)
    /* 1CAD8C 002CAD8C 2D30C002 */  daddu      $6, $22, $0
    /* 1CAD90 002CAD90 2D380002 */  daddu      $7, $16, $0
    /* 1CAD94 002CAD94 8CCA0A0C */  jal        func_002b2a30
    /* 1CAD98 002CAD98 00000000 */   nop
    /* 1CAD9C 002CAD9C 0A000324 */  addiu      $3, $0, 0xA
    /* 1CADA0 002CADA0 1B008302 */  divu       $0, $20, $3
    /* 1CADA4 002CADA4 10180000 */  mfhi       $3
    /* 1CADA8 002CADA8 2130C303 */  addu       $6, $30, $3
    /* 1CADAC 002CADAC 06AB0046 */  mov.s      $f12, $f21
    /* 1CADB0 002CADB0 46A30046 */  mov.s      $f13, $f20
    /* 1CADB4 002CADB4 86B30046 */  mov.s      $f14, $f22
    /* 1CADB8 002CADB8 2D204000 */  daddu      $4, $2, $0
    /* 1CADBC 002CADBC 2D282002 */  daddu      $5, $17, $0
    /* 1CADC0 002CADC0 B800A78F */  lw         $7, 0xB8($29)
    /* 1CADC4 002CADC4 01000824 */  addiu      $8, $0, 0x1
    /* 1CADC8 002CADC8 2D484002 */  daddu      $9, $18, $0
    /* 1CADCC 002CADCC 247B090C */  jal        func_0025ec90
    /* 1CADD0 002CADD0 00000000 */   nop
    /* 1CADD4 002CADD4 0A000324 */  addiu      $3, $0, 0xA
    /* 1CADD8 002CADD8 1B008302 */  divu       $0, $20, $3
    /* 1CADDC 002CADDC 12A00000 */  mflo       $20
    /* 1CADE0 002CADE0 01006326 */  addiu      $3, $19, 0x1
    /* 1CADE4 002CADE4 3C9E0300 */  dsll32     $19, $3, 24
    /* 1CADE8 002CADE8 3F9E1300 */  dsra32     $19, $19, 24
    /* 1CADEC 002CADEC 03000324 */  addiu      $3, $0, 0x3
    /* 1CADF0 002CADF0 1A006302 */  div        $0, $19, $3
    /* 1CADF4 002CADF4 10180000 */  mfhi       $3
    /* 1CADF8 002CADF8 25006014 */  bnez       $3, .L002CAE90
    /* 1CADFC 002CADFC 00000000 */   nop
    /* 1CAE00 002CAE00 1D008012 */  beqz       $20, .L002CAE78
    /* 1CAE04 002CAE04 00000000 */   nop
    /* 1CAE08 002CAE08 BE00A287 */  lh         $2, 0xBE($29)
    /* 1CAE0C 002CAE0C 00008244 */  mtc1       $2, $f0
    /* 1CAE10 002CAE10 00000000 */  nop
    /* 1CAE14 002CAE14 20008046 */  cvt.s.w    $f0, $f0
    /* 1CAE18 002CAE18 41AD0046 */  sub.s      $f21, $f21, $f0
    /* 1CAE1C 002CAE1C FF000424 */  addiu      $4, $0, 0xFF
    /* 1CAE20 002CAE20 CC00A593 */  lbu        $5, 0xCC($29)
    /* 1CAE24 002CAE24 2D30C002 */  daddu      $6, $22, $0
    /* 1CAE28 002CAE28 2D380002 */  daddu      $7, $16, $0
    /* 1CAE2C 002CAE2C 8CCA0A0C */  jal        func_002b2a30
    /* 1CAE30 002CAE30 00000000 */   nop
    /* 1CAE34 002CAE34 06AB0046 */  mov.s      $f12, $f21
    /* 1CAE38 002CAE38 46A30046 */  mov.s      $f13, $f20
    /* 1CAE3C 002CAE3C 86B30046 */  mov.s      $f14, $f22
    /* 1CAE40 002CAE40 2D204000 */  daddu      $4, $2, $0
    /* 1CAE44 002CAE44 2D282002 */  daddu      $5, $17, $0
    /* 1CAE48 002CAE48 2D30E002 */  daddu      $6, $23, $0
    /* 1CAE4C 002CAE4C E000A78F */  lw         $7, 0xE0($29)
    /* 1CAE50 002CAE50 01000824 */  addiu      $8, $0, 0x1
    /* 1CAE54 002CAE54 2D484002 */  daddu      $9, $18, $0
    /* 1CAE58 002CAE58 247B090C */  jal        func_0025ec90
    /* 1CAE5C 002CAE5C 00000000 */   nop
    /* 1CAE60 002CAE60 00009544 */  mtc1       $21, $f0
    /* 1CAE64 002CAE64 00000000 */  nop
    /* 1CAE68 002CAE68 20008046 */  cvt.s.w    $f0, $f0
    /* 1CAE6C 002CAE6C 41AD0046 */  sub.s      $f21, $f21, $f0
    /* 1CAE70 002CAE70 0B000010 */  b          .L002CAEA0
    /* 1CAE74 002CAE74 00000000 */   nop
  .L002CAE78:
    /* 1CAE78 002CAE78 00009544 */  mtc1       $21, $f0
    /* 1CAE7C 002CAE7C 00000000 */  nop
    /* 1CAE80 002CAE80 20008046 */  cvt.s.w    $f0, $f0
    /* 1CAE84 002CAE84 41AD0046 */  sub.s      $f21, $f21, $f0
    /* 1CAE88 002CAE88 05000010 */  b          .L002CAEA0
    /* 1CAE8C 002CAE8C 00000000 */   nop
  .L002CAE90:
    /* 1CAE90 002CAE90 00009544 */  mtc1       $21, $f0
    /* 1CAE94 002CAE94 00000000 */  nop
    /* 1CAE98 002CAE98 20008046 */  cvt.s.w    $f0, $f0
    /* 1CAE9C 002CAE9C 41AD0046 */  sub.s      $f21, $f21, $f0
  .L002CAEA0:
    /* 1CAEA0 002CAEA0 B8FF8016 */  bnez       $20, .L002CAD84
    /* 1CAEA4 002CAEA4 00000000 */   nop
    /* 1CAEA8 002CAEA8 A000BFDF */  ld         $31, 0xA0($29)
    /* 1CAEAC 002CAEAC 9000BE7B */  lq         $30, 0x90($29)
    /* 1CAEB0 002CAEB0 8000B77B */  lq         $23, 0x80($29)
    /* 1CAEB4 002CAEB4 7000B67B */  lq         $22, 0x70($29)
    /* 1CAEB8 002CAEB8 6000B57B */  lq         $21, 0x60($29)
    /* 1CAEBC 002CAEBC 5000B47B */  lq         $20, 0x50($29)
    /* 1CAEC0 002CAEC0 4000B37B */  lq         $19, 0x40($29)
    /* 1CAEC4 002CAEC4 3000B27B */  lq         $18, 0x30($29)
    /* 1CAEC8 002CAEC8 2000B17B */  lq         $17, 0x20($29)
    /* 1CAECC 002CAECC 1000B07B */  lq         $16, 0x10($29)
    /* 1CAED0 002CAED0 0800B6C7 */  lwc1       $f22, 0x8($29)
    /* 1CAED4 002CAED4 0400B5C7 */  lwc1       $f21, 0x4($29)
    /* 1CAED8 002CAED8 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* 1CAEDC 002CAEDC E000BD27 */  addiu      $29, $29, 0xE0
    /* 1CAEE0 002CAEE0 0800E003 */  jr         $31
    /* 1CAEE4 002CAEE4 00000000 */   nop
    /* 1CAEE8 002CAEE8 00000000 */  nop
    /* 1CAEEC 002CAEEC 00000000 */  nop
.size func_002cacd0, 0x220
