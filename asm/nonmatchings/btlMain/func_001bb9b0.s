.section .text
.set noat
.set noreorder
glabel func_001bb9b0
    /* BB9B0 001BB9B0 80FFBD27 */  addiu      $29, $29, -0x80
    /* BB9B4 001BB9B4 4000BFFF */  sd         $31, 0x40($29)
    /* BB9B8 001BB9B8 3000B27F */  sq         $18, 0x30($29)
    /* BB9BC 001BB9BC 2000B17F */  sq         $17, 0x20($29)
    /* BB9C0 001BB9C0 1000B07F */  sq         $16, 0x10($29)
    /* BB9C4 001BB9C4 0000B4E7 */  swc1       $f20, 0x0($29)
    /* BB9C8 001BB9C8 2D88A000 */  daddu      $17, $5, $0
    /* BB9CC 001BB9CC 06650046 */  mov.s      $f20, $f12
    /* BB9D0 001BB9D0 74008594 */  lhu        $5, 0x74($4)
    /* BB9D4 001BB9D4 348480C7 */  lwc1       $f0, -0x7BCC($28)
    /* BB9D8 001BB9D8 04000010 */  b          .L001BB9EC
    /* BB9DC 001BB9DC 00000000 */   nop
  .L001BB9E0:
    /* BB9E0 001BB9E0 0100A224 */  addiu      $2, $5, 0x1
    /* BB9E4 001BB9E4 FFFF4530 */  andi       $5, $2, 0xFFFF
    /* BB9E8 001BB9E8 01A50046 */  sub.s      $f20, $f20, $f0
  .L001BB9EC:
    /* BB9EC 001BB9EC 34A00046 */  c.lt.s     $f20, $f0
    /* BB9F0 001BB9F0 00000000 */  nop
    /* BB9F4 001BB9F4 FAFF0045 */  bc1f       .L001BB9E0
    /* BB9F8 001BB9F8 00000000 */   nop
    /* BB9FC 001BB9FC 00000000 */  nop
    /* BBA00 001BBA00 00000000 */  nop
    /* BBA04 001BBA04 03A50046 */  div.s      $f20, $f20, $f0
    /* BBA08 001BBA08 00000000 */  nop
    /* BBA0C 001BBA0C FFFFA230 */  andi       $2, $5, 0xFFFF
    /* BBA10 001BBA10 04004228 */  slti       $2, $2, 0x4
    /* BBA14 001BBA14 02004014 */  bnez       $2, .L001BBA20
    /* BBA18 001BBA18 00000000 */   nop
    /* BBA1C 001BBA1C 0300A530 */  andi       $5, $5, 0x3
  .L001BBA20:
    /* BBA20 001BBA20 FFFFA230 */  andi       $2, $5, 0xFFFF
    /* BBA24 001BBA24 01004224 */  addiu      $2, $2, 0x1
    /* BBA28 001BBA28 FFFF4330 */  andi       $3, $2, 0xFFFF
    /* BBA2C 001BBA2C 04006228 */  slti       $2, $3, 0x4
    /* BBA30 001BBA30 02004014 */  bnez       $2, .L001BBA3C
    /* BBA34 001BBA34 00000000 */   nop
    /* BBA38 001BBA38 03006330 */  andi       $3, $3, 0x3
  .L001BBA3C:
    /* BBA3C 001BBA3C FFFF6330 */  andi       $3, $3, 0xFFFF
    /* BBA40 001BBA40 C0100300 */  sll        $2, $3, 3
    /* BBA44 001BBA44 23104300 */  subu       $2, $2, $3
    /* BBA48 001BBA48 80100200 */  sll        $2, $2, 2
    /* BBA4C 001BBA4C 21108200 */  addu       $2, $4, $2
    /* BBA50 001BBA50 10005024 */  addiu      $16, $2, 0x10
    /* BBA54 001BBA54 FFFFA330 */  andi       $3, $5, 0xFFFF
    /* BBA58 001BBA58 C0100300 */  sll        $2, $3, 3
    /* BBA5C 001BBA5C 23104300 */  subu       $2, $2, $3
    /* BBA60 001BBA60 80100200 */  sll        $2, $2, 2
    /* BBA64 001BBA64 21108200 */  addu       $2, $4, $2
    /* BBA68 001BBA68 10005224 */  addiu      $18, $2, 0x10
    /* BBA6C 001BBA6C 2D204002 */  daddu      $4, $18, $0
    /* BBA70 001BBA70 2D280002 */  daddu      $5, $16, $0
    /* BBA74 001BBA74 5000A627 */  addiu      $6, $29, 0x50
    /* BBA78 001BBA78 1C730F0C */  jal        func_003dcc70
    /* BBA7C 001BBA7C 00000000 */   nop
    /* BBA80 001BBA80 00588044 */  mtc1       $0, $f11
    /* BBA84 001BBA84 00000000 */  nop
    /* BBA88 001BBA88 36A00B46 */  c.le.s     $f20, $f11
    /* BBA8C 001BBA8C 0B000045 */  bc1f       .L001BBABC
    /* BBA90 001BBA90 00000000 */   nop
    /* BBA94 001BBA94 000043C6 */  lwc1       $f3, 0x0($18)
    /* BBA98 001BBA98 040042C6 */  lwc1       $f2, 0x4($18)
    /* BBA9C 001BBA9C 080041C6 */  lwc1       $f1, 0x8($18)
    /* BBAA0 001BBAA0 0C0040C6 */  lwc1       $f0, 0xC($18)
    /* BBAA4 001BBAA4 000023E6 */  swc1       $f3, 0x0($17)
    /* BBAA8 001BBAA8 040022E6 */  swc1       $f2, 0x4($17)
    /* BBAAC 001BBAAC 080021E6 */  swc1       $f1, 0x8($17)
    /* BBAB0 001BBAB0 0C0020E6 */  swc1       $f0, 0xC($17)
    /* BBAB4 001BBAB4 59000010 */  b          .L001BBC1C
    /* BBAB8 001BBAB8 00000000 */   nop
  .L001BBABC:
    /* BBABC 001BBABC 803F033C */  lui        $3, (0x3F800000 >> 16)
    /* BBAC0 001BBAC0 00008344 */  mtc1       $3, $f0
    /* BBAC4 001BBAC4 00000000 */  nop
    /* BBAC8 001BBAC8 36001446 */  c.le.s     $f0, $f20
    /* BBACC 001BBACC 0B000045 */  bc1f       .L001BBAFC
    /* BBAD0 001BBAD0 00000000 */   nop
    /* BBAD4 001BBAD4 000003C6 */  lwc1       $f3, 0x0($16)
    /* BBAD8 001BBAD8 040002C6 */  lwc1       $f2, 0x4($16)
    /* BBADC 001BBADC 080001C6 */  lwc1       $f1, 0x8($16)
    /* BBAE0 001BBAE0 0C0000C6 */  lwc1       $f0, 0xC($16)
    /* BBAE4 001BBAE4 000023E6 */  swc1       $f3, 0x0($17)
    /* BBAE8 001BBAE8 040022E6 */  swc1       $f2, 0x4($17)
    /* BBAEC 001BBAEC 080021E6 */  swc1       $f1, 0x8($17)
    /* BBAF0 001BBAF0 0C0020E6 */  swc1       $f0, 0xC($17)
    /* BBAF4 001BBAF4 49000010 */  b          .L001BBC1C
    /* BBAF8 001BBAF8 00000000 */   nop
  .L001BBAFC:
    /* BBAFC 001BBAFC 01001446 */  sub.s      $f0, $f0, $f20
    /* BBB00 001BBB00 7400A38F */  lw         $3, 0x74($29)
    /* BBB04 001BBB04 26006014 */  bnez       $3, .L001BBBA0
    /* BBB08 001BBB08 00000000 */   nop
    /* BBB0C 001BBB0C 7000AAC7 */  lwc1       $f10, 0x70($29)
    /* BBB10 001BBB10 02010A46 */  mul.s      $f4, $f0, $f10
    /* BBB14 001BBB14 C2200446 */  mul.s      $f3, $f4, $f4
    /* BBB18 001BBB18 F88389C7 */  lwc1       $f9, -0x7C08($28)
    /* BBB1C 001BBB1C 548088C7 */  lwc1       $f8, -0x7FAC($28)
    /* BBB20 001BBB20 18580846 */  adda.s     $f11, $f8
    /* BBB24 001BBB24 1C480346 */  madd.s     $f0, $f9, $f3
    /* BBB28 001BBB28 588087C7 */  lwc1       $f7, -0x7FA8($28)
    /* BBB2C 001BBB2C 18580746 */  adda.s     $f11, $f7
    /* BBB30 001BBB30 1C180046 */  madd.s     $f0, $f3, $f0
    /* BBB34 001BBB34 448386C7 */  lwc1       $f6, -0x7CBC($28)
    /* BBB38 001BBB38 18580646 */  adda.s     $f11, $f6
    /* BBB3C 001BBB3C 1C180046 */  madd.s     $f0, $f3, $f0
    /* BBB40 001BBB40 3C8485C7 */  lwc1       $f5, -0x7BC4($28)
    /* BBB44 001BBB44 18580546 */  adda.s     $f11, $f5
    /* BBB48 001BBB48 1C180046 */  madd.s     $f0, $f3, $f0
    /* BBB4C 001BBB4C 408482C7 */  lwc1       $f2, -0x7BC0($28)
    /* BBB50 001BBB50 18580246 */  adda.s     $f11, $f2
    /* BBB54 001BBB54 5C180046 */  madd.s     $f1, $f3, $f0
    /* BBB58 001BBB58 02180446 */  mul.s      $f0, $f3, $f4
    /* BBB5C 001BBB5C 18580446 */  adda.s     $f11, $f4
    /* BBB60 001BBB60 1C000146 */  madd.s     $f0, $f0, $f1
    /* BBB64 001BBB64 02A10A46 */  mul.s      $f4, $f20, $f10
    /* BBB68 001BBB68 C2200446 */  mul.s      $f3, $f4, $f4
    /* BBB6C 001BBB6C 18580846 */  adda.s     $f11, $f8
    /* BBB70 001BBB70 5C480346 */  madd.s     $f1, $f9, $f3
    /* BBB74 001BBB74 18580746 */  adda.s     $f11, $f7
    /* BBB78 001BBB78 5C180146 */  madd.s     $f1, $f3, $f1
    /* BBB7C 001BBB7C 18580646 */  adda.s     $f11, $f6
    /* BBB80 001BBB80 5C180146 */  madd.s     $f1, $f3, $f1
    /* BBB84 001BBB84 18580546 */  adda.s     $f11, $f5
    /* BBB88 001BBB88 5C180146 */  madd.s     $f1, $f3, $f1
    /* BBB8C 001BBB8C 18580246 */  adda.s     $f11, $f2
    /* BBB90 001BBB90 9C180146 */  madd.s     $f2, $f3, $f1
    /* BBB94 001BBB94 42180446 */  mul.s      $f1, $f3, $f4
    /* BBB98 001BBB98 18580446 */  adda.s     $f11, $f4
    /* BBB9C 001BBB9C 1C0D0246 */  madd.s     $f20, $f1, $f2
  .L001BBBA0:
    /* BBBA0 001BBBA0 5000A1C7 */  lwc1       $f1, 0x50($29)
    /* BBBA4 001BBBA4 42080046 */  mul.s      $f1, $f1, $f0
    /* BBBA8 001BBBA8 000021E6 */  swc1       $f1, 0x0($17)
    /* BBBAC 001BBBAC 5400A1C7 */  lwc1       $f1, 0x54($29)
    /* BBBB0 001BBBB0 42080046 */  mul.s      $f1, $f1, $f0
    /* BBBB4 001BBBB4 040021E6 */  swc1       $f1, 0x4($17)
    /* BBBB8 001BBBB8 5800A1C7 */  lwc1       $f1, 0x58($29)
    /* BBBBC 001BBBBC 42080046 */  mul.s      $f1, $f1, $f0
    /* BBBC0 001BBBC0 080021E6 */  swc1       $f1, 0x8($17)
    /* BBBC4 001BBBC4 6000A2C7 */  lwc1       $f2, 0x60($29)
    /* BBBC8 001BBBC8 000021C6 */  lwc1       $f1, 0x0($17)
    /* BBBCC 001BBBCC 00188044 */  mtc1       $0, $f3
    /* BBBD0 001BBBD0 00000000 */  nop
    /* BBBD4 001BBBD4 18180146 */  adda.s     $f3, $f1
    /* BBBD8 001BBBD8 5C101446 */  madd.s     $f1, $f2, $f20
    /* BBBDC 001BBBDC 000021E6 */  swc1       $f1, 0x0($17)
    /* BBBE0 001BBBE0 6400A2C7 */  lwc1       $f2, 0x64($29)
    /* BBBE4 001BBBE4 040021C6 */  lwc1       $f1, 0x4($17)
    /* BBBE8 001BBBE8 18180146 */  adda.s     $f3, $f1
    /* BBBEC 001BBBEC 5C101446 */  madd.s     $f1, $f2, $f20
    /* BBBF0 001BBBF0 040021E6 */  swc1       $f1, 0x4($17)
    /* BBBF4 001BBBF4 6800A2C7 */  lwc1       $f2, 0x68($29)
    /* BBBF8 001BBBF8 080021C6 */  lwc1       $f1, 0x8($17)
    /* BBBFC 001BBBFC 18180146 */  adda.s     $f3, $f1
    /* BBC00 001BBC00 5C101446 */  madd.s     $f1, $f2, $f20
    /* BBC04 001BBC04 080021E6 */  swc1       $f1, 0x8($17)
    /* BBC08 001BBC08 5C00A2C7 */  lwc1       $f2, 0x5C($29)
    /* BBC0C 001BBC0C 6C00A1C7 */  lwc1       $f1, 0x6C($29)
    /* BBC10 001BBC10 1A081446 */  mula.s     $f1, $f20
    /* BBC14 001BBC14 1C100046 */  madd.s     $f0, $f2, $f0
    /* BBC18 001BBC18 0C0020E6 */  swc1       $f0, 0xC($17)
  .L001BBC1C:
    /* BBC1C 001BBC1C 4000BFDF */  ld         $31, 0x40($29)
    /* BBC20 001BBC20 3000B27B */  lq         $18, 0x30($29)
    /* BBC24 001BBC24 2000B17B */  lq         $17, 0x20($29)
    /* BBC28 001BBC28 1000B07B */  lq         $16, 0x10($29)
    /* BBC2C 001BBC2C 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* BBC30 001BBC30 8000BD27 */  addiu      $29, $29, 0x80
    /* BBC34 001BBC34 0800E003 */  jr         $31
    /* BBC38 001BBC38 00000000 */   nop
    /* BBC3C 001BBC3C 00000000 */  nop
.size func_001bb9b0, 0x290
