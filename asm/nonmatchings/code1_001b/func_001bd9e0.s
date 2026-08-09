.section .text
.set noat
.set noreorder
glabel func_001bd9e0
    /* BD9E0 001BD9E0 A0FFBD27 */  addiu      $29, $29, -0x60
    /* BD9E4 001BD9E4 0000BFFF */  sd         $31, 0x0($29)
    /* BD9E8 001BD9E8 ACB3858F */  lw         $5, -0x4C54($28)
    /* BD9EC 001BD9EC 0C00A38C */  lw         $3, 0xC($5)
    /* BD9F0 001BD9F0 04006330 */  andi       $3, $3, 0x4
    /* BD9F4 001BD9F4 55006014 */  bnez       $3, .L001BDB4C
    /* BD9F8 001BD9F8 00000000 */   nop
    /* BD9FC 001BD9FC 1400A48C */  lw         $4, 0x14($5)
    /* BDA00 001BDA00 04008330 */  andi       $3, $4, 0x4
    /* BDA04 001BDA04 51006014 */  bnez       $3, .L001BDB4C
    /* BDA08 001BDA08 00000000 */   nop
    /* BDA0C 001BDA0C 08008330 */  andi       $3, $4, 0x8
    /* BDA10 001BDA10 4E006010 */  beqz       $3, .L001BDB4C
    /* BDA14 001BDA14 00000000 */   nop
    /* BDA18 001BDA18 FF000224 */  addiu      $2, $0, 0xFF
    /* BDA1C 001BDA1C 5C00A2A3 */  sb         $2, 0x5C($29)
    /* BDA20 001BDA20 5D00A2A3 */  sb         $2, 0x5D($29)
    /* BDA24 001BDA24 5E00A0A3 */  sb         $0, 0x5E($29)
    /* BDA28 001BDA28 5F00A2A3 */  sb         $2, 0x5F($29)
    /* BDA2C 001BDA2C D000A4C4 */  lwc1       $f4, 0xD0($5)
    /* BDA30 001BDA30 CC00ACC4 */  lwc1       $f12, 0xCC($5)
    /* BDA34 001BDA34 D400ABC4 */  lwc1       $f11, 0xD4($5)
    /* BDA38 001BDA38 D800A3C4 */  lwc1       $f3, 0xD8($5)
    /* BDA3C 001BDA3C 1A200446 */  mula.s     $f4, $f4
    /* BDA40 001BDA40 1E600C46 */  madda.s    $f12, $f12
    /* BDA44 001BDA44 1E580B46 */  madda.s    $f11, $f11
    /* BDA48 001BDA48 5C180346 */  madd.s     $f1, $f3, $f3
    /* BDA4C 001BDA4C 0040023C */  lui        $2, (0x40000000 >> 16)
    /* BDA50 001BDA50 00008244 */  mtc1       $2, $f0
    /* BDA54 001BDA54 00000000 */  nop
    /* BDA58 001BDA58 03000146 */  div.s      $f0, $f0, $f1
    /* BDA5C 001BDA5C 82600046 */  mul.s      $f2, $f12, $f0
    /* BDA60 001BDA60 42200046 */  mul.s      $f1, $f4, $f0
    /* BDA64 001BDA64 02580046 */  mul.s      $f0, $f11, $f0
    /* BDA68 001BDA68 82120346 */  mul.s      $f10, $f2, $f3
    /* BDA6C 001BDA6C 420A0346 */  mul.s      $f9, $f1, $f3
    /* BDA70 001BDA70 02020346 */  mul.s      $f8, $f0, $f3
    /* BDA74 001BDA74 C2610246 */  mul.s      $f7, $f12, $f2
    /* BDA78 001BDA78 82210146 */  mul.s      $f6, $f4, $f1
    /* BDA7C 001BDA7C 42590046 */  mul.s      $f5, $f11, $f0
    /* BDA80 001BDA80 02210046 */  mul.s      $f4, $f4, $f0
    /* BDA84 001BDA84 C2580246 */  mul.s      $f3, $f11, $f2
    /* BDA88 001BDA88 82600146 */  mul.s      $f2, $f12, $f1
    /* BDA8C 001BDA8C 00300546 */  add.s      $f0, $f6, $f5
    /* BDA90 001BDA90 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* BDA94 001BDA94 00088244 */  mtc1       $2, $f1
    /* BDA98 001BDA98 00000000 */  nop
    /* BDA9C 001BDA9C 01080046 */  sub.s      $f0, $f1, $f0
    /* BDAA0 001BDAA0 1000A0E7 */  swc1       $f0, 0x10($29)
    /* BDAA4 001BDAA4 00100846 */  add.s      $f0, $f2, $f8
    /* BDAA8 001BDAA8 1400A0E7 */  swc1       $f0, 0x14($29)
    /* BDAAC 001BDAAC 01180946 */  sub.s      $f0, $f3, $f9
    /* BDAB0 001BDAB0 1800A0E7 */  swc1       $f0, 0x18($29)
    /* BDAB4 001BDAB4 01100846 */  sub.s      $f0, $f2, $f8
    /* BDAB8 001BDAB8 2000A0E7 */  swc1       $f0, 0x20($29)
    /* BDABC 001BDABC 00280746 */  add.s      $f0, $f5, $f7
    /* BDAC0 001BDAC0 01080046 */  sub.s      $f0, $f1, $f0
    /* BDAC4 001BDAC4 2400A0E7 */  swc1       $f0, 0x24($29)
    /* BDAC8 001BDAC8 00200A46 */  add.s      $f0, $f4, $f10
    /* BDACC 001BDACC 2800A0E7 */  swc1       $f0, 0x28($29)
    /* BDAD0 001BDAD0 00180946 */  add.s      $f0, $f3, $f9
    /* BDAD4 001BDAD4 3000A0E7 */  swc1       $f0, 0x30($29)
    /* BDAD8 001BDAD8 01200A46 */  sub.s      $f0, $f4, $f10
    /* BDADC 001BDADC 3400A0E7 */  swc1       $f0, 0x34($29)
    /* BDAE0 001BDAE0 00380646 */  add.s      $f0, $f7, $f6
    /* BDAE4 001BDAE4 01080046 */  sub.s      $f0, $f1, $f0
    /* BDAE8 001BDAE8 3800A0E7 */  swc1       $f0, 0x38($29)
    /* BDAEC 001BDAEC 4000A0AF */  sw         $0, 0x40($29)
    /* BDAF0 001BDAF0 4400A0AF */  sw         $0, 0x44($29)
    /* BDAF4 001BDAF4 4800A0AF */  sw         $0, 0x48($29)
    /* BDAF8 001BDAF8 03000224 */  addiu      $2, $0, 0x3
    /* BDAFC 001BDAFC 1C00A2AF */  sw         $2, 0x1C($29)
    /* BDB00 001BDB00 C000A424 */  addiu      $4, $5, 0xC0
    /* BDB04 001BDB04 C000A2C4 */  lwc1       $f2, 0xC0($5)
    /* BDB08 001BDB08 C400A1C4 */  lwc1       $f1, 0xC4($5)
    /* BDB0C 001BDB0C C800A0C4 */  lwc1       $f0, 0xC8($5)
    /* BDB10 001BDB10 4000A2E7 */  swc1       $f2, 0x40($29)
    /* BDB14 001BDB14 4400A1E7 */  swc1       $f1, 0x44($29)
    /* BDB18 001BDB18 4800A0E7 */  swc1       $f0, 0x48($29)
    /* BDB1C 001BDB1C C040023C */  lui        $2, (0x40C00000 >> 16)
    /* BDB20 001BDB20 00608244 */  mtc1       $2, $f12
    /* BDB24 001BDB24 5C00A527 */  addiu      $5, $29, 0x5C
    /* BDB28 001BDB28 01000624 */  addiu      $6, $0, 0x1
    /* BDB2C 001BDB2C 2C7C110C */  jal        func_0045f0b0
    /* BDB30 001BDB30 00000000 */   nop
    /* BDB34 001BDB34 1643023C */  lui        $2, (0x43160000 >> 16)
    /* BDB38 001BDB38 00608244 */  mtc1       $2, $f12
    /* BDB3C 001BDB3C 1000A427 */  addiu      $4, $29, 0x10
    /* BDB40 001BDB40 01000524 */  addiu      $5, $0, 0x1
    /* BDB44 001BDB44 807E110C */  jal        func_0045fa00
    /* BDB48 001BDB48 00000000 */   nop
  .L001BDB4C:
    /* BDB4C 001BDB4C 0000BFDF */  ld         $31, 0x0($29)
    /* BDB50 001BDB50 6000BD27 */  addiu      $29, $29, 0x60
    /* BDB54 001BDB54 0800E003 */  jr         $31
    /* BDB58 001BDB58 00000000 */   nop
    /* BDB5C 001BDB5C 00000000 */  nop
.size func_001bd9e0, 0x180
