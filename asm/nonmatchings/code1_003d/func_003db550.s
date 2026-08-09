.section .text
.set noat
.set noreorder
glabel func_003db550
    /* 2DB550 003DB550 90FFBD27 */  addiu      $29, $29, -0x70
    /* 2DB554 003DB554 2000BFFF */  sd         $31, 0x20($29)
    /* 2DB558 003DB558 1000B17F */  sq         $17, 0x10($29)
    /* 2DB55C 003DB55C 0000B07F */  sq         $16, 0x0($29)
    /* 2DB560 003DB560 2D888000 */  daddu      $17, $4, $0
    /* 2DB564 003DB564 2D80A000 */  daddu      $16, $5, $0
    /* 2DB568 003DB568 0800858C */  lw         $5, 0x8($4)
    /* 2DB56C 003DB56C 0001043C */  lui        $4, (0x1000000 >> 16)
    /* 2DB570 003DB570 2418A400 */  and        $3, $5, $4
    /* 2DB574 003DB574 26006410 */  beq        $3, $4, .L003DB610
    /* 2DB578 003DB578 00000000 */   nop
    /* 2DB57C 003DB57C 8400A330 */  andi       $3, $5, 0x84
    /* 2DB580 003DB580 23006010 */  beqz       $3, .L003DB610
    /* 2DB584 003DB584 00000000 */   nop
    /* 2DB588 003DB588 70A20F0C */  jal        func_003e89c0
    /* 2DB58C 003DB58C 00000000 */   nop
    /* 2DB590 003DB590 2D284000 */  daddu      $5, $2, $0
    /* 2DB594 003DB594 5CA20F0C */  jal        func_003e8970
    /* 2DB598 003DB598 3000A427 */   addiu     $4, $29, 0x30
    /* 2DB59C 003DB59C 680001C6 */  lwc1       $f1, 0x68($16)
    /* 2DB5A0 003DB5A0 0040023C */  lui        $2, (0x40000000 >> 16)
    /* 2DB5A4 003DB5A4 6C0000C6 */  lwc1       $f0, 0x6C($16)
    /* 2DB5A8 003DB5A8 3000A38F */  lw         $3, 0x30($29)
    /* 2DB5AC 003DB5AC 00108244 */  mtc1       $2, $f2
    /* 2DB5B0 003DB5B0 3400A28F */  lw         $2, 0x34($29)
    /* 2DB5B4 003DB5B4 42100146 */  mul.s      $f1, $f2, $f1
    /* 2DB5B8 003DB5B8 02100046 */  mul.s      $f0, $f2, $f0
    /* 2DB5BC 003DB5BC 42080046 */  mul.s      $f1, $f1, $f0
    /* 2DB5C0 003DB5C0 18106200 */  mult       $2, $3, $2
    /* 2DB5C4 003DB5C4 5400B1AF */  sw         $17, 0x54($29)
    /* 2DB5C8 003DB5C8 5000A0AF */  sw         $0, 0x50($29)
    /* 2DB5CC 003DB5CC 00008244 */  mtc1       $2, $f0
    /* 2DB5D0 003DB5D0 00000000 */  nop
    /* 2DB5D4 003DB5D4 20008046 */  cvt.s.w    $f0, $f0
    /* 2DB5D8 003DB5D8 03000146 */  div.s      $f0, $f0, $f1
    /* 2DB5DC 003DB5DC 00000000 */  nop
    /* 2DB5E0 003DB5E0 00000000 */  nop
    /* 2DB5E4 003DB5E4 B4BD0F0C */  jal        func_003ef6d0
    /* 2DB5E8 003DB5E8 6400A0E7 */   swc1      $f0, 0x64($29)
    /* 2DB5EC 003DB5EC 08004010 */  beqz       $2, .L003DB610
    /* 2DB5F0 003DB5F0 00000000 */   nop
    /* 2DB5F4 003DB5F4 B4BD0F0C */  jal        func_003ef6d0
    /* 2DB5F8 003DB5F8 00000000 */   nop
    /* 2DB5FC 003DB5FC 3E00053C */  lui        $5, %hi(func_003db490)
    /* 2DB600 003DB600 2D204000 */  daddu      $4, $2, $0
    /* 2DB604 003DB604 90B4A524 */  addiu      $5, $5, %lo(func_003db490)
    /* 2DB608 003DB608 98BC0F0C */  jal        func_003ef260
    /* 2DB60C 003DB60C 5000A627 */   addiu     $6, $29, 0x50
  .L003DB610:
    /* 2DB610 003DB610 2000BFDF */  ld         $31, 0x20($29)
    /* 2DB614 003DB614 1000B17B */  lq         $17, 0x10($29)
    /* 2DB618 003DB618 0000B07B */  lq         $16, 0x0($29)
    /* 2DB61C 003DB61C 0800E003 */  jr         $31
    /* 2DB620 003DB620 7000BD27 */   addiu     $29, $29, 0x70
    /* 2DB624 003DB624 00000000 */  nop
    /* 2DB628 003DB628 00000000 */  nop
    /* 2DB62C 003DB62C 00000000 */  nop
.size func_003db550, 0xe0
