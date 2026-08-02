.section .text
.set noat
.set noreorder
glabel func_0034db60
    /* 24DB60 0034DB60 A0FFBD27 */  addiu      $29, $29, -0x60
    /* 24DB64 0034DB64 5000BFFF */  sd         $31, 0x50($29)
    /* 24DB68 0034DB68 4000B17F */  sq         $17, 0x40($29)
    /* 24DB6C 0034DB6C 3000B07F */  sq         $16, 0x30($29)
    /* 24DB70 0034DB70 2400BDE7 */  swc1       $f29, 0x24($29)
    /* 24DB74 0034DB74 2000BCE7 */  swc1       $f28, 0x20($29)
    /* 24DB78 0034DB78 1C00BBE7 */  swc1       $f27, 0x1C($29)
    /* 24DB7C 0034DB7C 1800BAE7 */  swc1       $f26, 0x18($29)
    /* 24DB80 0034DB80 1400B9E7 */  swc1       $f25, 0x14($29)
    /* 24DB84 0034DB84 1000B8E7 */  swc1       $f24, 0x10($29)
    /* 24DB88 0034DB88 0C00B7E7 */  swc1       $f23, 0xC($29)
    /* 24DB8C 0034DB8C 0800B6E7 */  swc1       $f22, 0x8($29)
    /* 24DB90 0034DB90 0400B5E7 */  swc1       $f21, 0x4($29)
    /* 24DB94 0034DB94 0000B4E7 */  swc1       $f20, 0x0($29)
    /* 24DB98 0034DB98 2D888000 */  daddu      $17, $4, $0
    /* 24DB9C 0034DB9C 2D80A000 */  daddu      $16, $5, $0
    /* 24DBA0 0034DBA0 881680C4 */  lwc1       $f0, 0x1688($4)
    /* 24DBA4 0034DBA4 82000C46 */  mul.s      $f2, $f0, $f12
    /* 24DBA8 0034DBA8 9016828C */  lw         $2, 0x1690($4)
    /* 24DBAC 0034DBAC 17004014 */  bnez       $2, .L0034DC0C
    /* 24DBB0 0034DBB0 00000000 */   nop
    /* 24DBB4 0034DBB4 84162286 */  lh         $2, 0x1684($17)
    /* 24DBB8 0034DBB8 00008244 */  mtc1       $2, $f0
    /* 24DBBC 0034DBBC 00000000 */  nop
    /* 24DBC0 0034DBC0 60008046 */  cvt.s.w    $f1, $f0
    /* 24DBC4 0034DBC4 34080246 */  c.lt.s     $f1, $f2
    /* 24DBC8 0034DBC8 0C000045 */  bc1f       .L0034DBFC
    /* 24DBCC 0034DBCC 00000000 */   nop
    /* 24DBD0 0034DBD0 948080C7 */  lwc1       $f0, -0x7F6C($28)
    /* 24DBD4 0034DBD4 02000146 */  mul.s      $f0, $f0, $f1
    /* 24DBD8 0034DBD8 03030246 */  div.s      $f12, $f0, $f2
    /* 24DBDC 0034DBDC 00000000 */  nop
    /* 24DBE0 0034DBE0 00000000 */  nop
    /* 24DBE4 0034DBE4 00000000 */  nop
    /* 24DBE8 0034DBE8 EC2D110C */  jal        func_0044b7b0
    /* 24DBEC 0034DBEC 00000000 */   nop
    /* 24DBF0 0034DBF0 46060046 */  mov.s      $f25, $f0
    /* 24DBF4 0034DBF4 07000010 */  b          .L0034DC14
    /* 24DBF8 0034DBF8 00000000 */   nop
  .L0034DBFC:
    /* 24DBFC 0034DBFC 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 24DC00 0034DC00 00C88244 */  mtc1       $2, $f25
    /* 24DC04 0034DC04 03000010 */  b          .L0034DC14
    /* 24DC08 0034DC08 00000000 */   nop
  .L0034DC0C:
    /* 24DC0C 0034DC0C 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 24DC10 0034DC10 00C88244 */  mtc1       $2, $f25
  .L0034DC14:
    /* 24DC14 0034DC14 05000016 */  bnez       $16, .L0034DC2C
    /* 24DC18 0034DC18 00000000 */   nop
    /* 24DC1C 0034DC1C 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 24DC20 0034DC20 00008244 */  mtc1       $2, $f0
    /* 24DC24 0034DC24 00000000 */  nop
    /* 24DC28 0034DC28 41061946 */  sub.s      $f25, $f0, $f25
  .L0034DC2C:
    /* 24DC2C 0034DC2C 2044023C */  lui        $2, (0x44200000 >> 16)
    /* 24DC30 0034DC30 00008244 */  mtc1       $2, $f0
    /* 24DC34 0034DC34 00000000 */  nop
    /* 24DC38 0034DC38 42051946 */  mul.s      $f21, $f0, $f25
    /* 24DC3C 0034DC3C 01001546 */  sub.s      $f0, $f0, $f21
    /* 24DC40 0034DC40 0040023C */  lui        $2, (0x40000000 >> 16)
    /* 24DC44 0034DC44 00088244 */  mtc1       $2, $f1
    /* 24DC48 0034DC48 00000000 */  nop
    /* 24DC4C 0034DC4C C3060146 */  div.s      $f27, $f0, $f1
    /* 24DC50 0034DC50 F043023C */  lui        $2, (0x43F00000 >> 16)
    /* 24DC54 0034DC54 00008244 */  mtc1       $2, $f0
    /* 24DC58 0034DC58 00000000 */  nop
    /* 24DC5C 0034DC5C 02051946 */  mul.s      $f20, $f0, $f25
    /* 24DC60 0034DC60 E043023C */  lui        $2, (0x43E00000 >> 16)
    /* 24DC64 0034DC64 00008244 */  mtc1       $2, $f0
    /* 24DC68 0034DC68 00000000 */  nop
    /* 24DC6C 0034DC6C 01001446 */  sub.s      $f0, $f0, $f20
    /* 24DC70 0034DC70 83060146 */  div.s      $f26, $f0, $f1
    /* 24DC74 0034DC74 900920AE */  sw         $0, 0x990($17)
    /* 24DC78 0034DC78 A00920C6 */  lwc1       $f0, 0x9A0($17)
    /* 24DC7C 0034DC7C C0D50046 */  add.s      $f23, $f26, $f0
    /* 24DC80 0034DC80 9C0920C6 */  lwc1       $f0, 0x99C($17)
    /* 24DC84 0034DC84 00DE0046 */  add.s      $f24, $f27, $f0
    /* 24DC88 0034DC88 8800023C */  lui        $2, %hi(D_008872F8)
    /* 24DC8C 0034DC8C F87241C4 */  lwc1       $f1, %lo(D_008872F8)($2)
    /* 24DC90 0034DC90 8800023C */  lui        $2, %hi(D_0088467C)
    /* 24DC94 0034DC94 7C4640C4 */  lwc1       $f0, %lo(D_0088467C)($2)
    /* 24DC98 0034DC98 810D0046 */  sub.s      $f22, $f1, $f0
    /* 24DC9C 0034DC9C 485C110C */  jal        func_00457120
    /* 24DCA0 0034DCA0 00000000 */   nop
    /* 24DCA4 0034DCA4 803F033C */  lui        $3, (0x3F800000 >> 16)
    /* 24DCA8 0034DCA8 00088344 */  mtc1       $3, $f1
    /* 24DCAC 0034DCAC 800040C4 */  lwc1       $f0, 0x80($2)
    /* 24DCB0 0034DCB0 430F0046 */  div.s      $f29, $f1, $f0
    /* 24DCB4 0034DCB4 90062426 */  addiu      $4, $17, 0x690
    /* 24DCB8 0034DCB8 06C30046 */  mov.s      $f12, $f24
    /* 24DCBC 0034DCBC 46BB0046 */  mov.s      $f13, $f23
    /* 24DCC0 0034DCC0 86B30046 */  mov.s      $f14, $f22
    /* 24DCC4 0034DCC4 C6EB0046 */  mov.s      $f15, $f29
    /* 24DCC8 0034DCC8 FF000524 */  addiu      $5, $0, 0xFF
    /* 24DCCC 0034DCCC E9000624 */  addiu      $6, $0, 0xE9
    /* 24DCD0 0034DCD0 2C000724 */  addiu      $7, $0, 0x2C
    /* 24DCD4 0034DCD4 2D40A000 */  daddu      $8, $5, $0
    /* 24DCD8 0034DCD8 343C0D0C */  jal        func_0034f0d0
    /* 24DCDC 0034DCDC 00000000 */   nop
    /* 24DCE0 0034DCE0 00BF1446 */  add.s      $f28, $f23, $f20
    /* 24DCE4 0034DCE4 D0062426 */  addiu      $4, $17, 0x6D0
    /* 24DCE8 0034DCE8 06C30046 */  mov.s      $f12, $f24
    /* 24DCEC 0034DCEC 46E30046 */  mov.s      $f13, $f28
    /* 24DCF0 0034DCF0 86B30046 */  mov.s      $f14, $f22
    /* 24DCF4 0034DCF4 C6EB0046 */  mov.s      $f15, $f29
    /* 24DCF8 0034DCF8 FF000524 */  addiu      $5, $0, 0xFF
    /* 24DCFC 0034DCFC E9000624 */  addiu      $6, $0, 0xE9
    /* 24DD00 0034DD00 2C000724 */  addiu      $7, $0, 0x2C
    /* 24DD04 0034DD04 2D40A000 */  daddu      $8, $5, $0
    /* 24DD08 0034DD08 343C0D0C */  jal        func_0034f0d0
    /* 24DD0C 0034DD0C 00000000 */   nop
    /* 24DD10 0034DD10 00C61546 */  add.s      $f24, $f24, $f21
    /* 24DD14 0034DD14 10072426 */  addiu      $4, $17, 0x710
    /* 24DD18 0034DD18 06C30046 */  mov.s      $f12, $f24
    /* 24DD1C 0034DD1C 46E30046 */  mov.s      $f13, $f28
    /* 24DD20 0034DD20 86B30046 */  mov.s      $f14, $f22
    /* 24DD24 0034DD24 C6EB0046 */  mov.s      $f15, $f29
    /* 24DD28 0034DD28 FF000524 */  addiu      $5, $0, 0xFF
    /* 24DD2C 0034DD2C E9000624 */  addiu      $6, $0, 0xE9
    /* 24DD30 0034DD30 2C000724 */  addiu      $7, $0, 0x2C
    /* 24DD34 0034DD34 2D40A000 */  daddu      $8, $5, $0
    /* 24DD38 0034DD38 343C0D0C */  jal        func_0034f0d0
    /* 24DD3C 0034DD3C 00000000 */   nop
    /* 24DD40 0034DD40 50072426 */  addiu      $4, $17, 0x750
    /* 24DD44 0034DD44 06C30046 */  mov.s      $f12, $f24
    /* 24DD48 0034DD48 46BB0046 */  mov.s      $f13, $f23
    /* 24DD4C 0034DD4C 86B30046 */  mov.s      $f14, $f22
    /* 24DD50 0034DD50 C6EB0046 */  mov.s      $f15, $f29
    /* 24DD54 0034DD54 FF000524 */  addiu      $5, $0, 0xFF
    /* 24DD58 0034DD58 E9000624 */  addiu      $6, $0, 0xE9
    /* 24DD5C 0034DD5C 2C000724 */  addiu      $7, $0, 0x2C
    /* 24DD60 0034DD60 2D40A000 */  daddu      $8, $5, $0
    /* 24DD64 0034DD64 343C0D0C */  jal        func_0034f0d0
    /* 24DD68 0034DD68 00000000 */   nop
    /* 24DD6C 0034DD6C 9C0920C6 */  lwc1       $f0, 0x99C($17)
    /* 24DD70 0034DD70 00DB0046 */  add.s      $f12, $f27, $f0
    /* 24DD74 0034DD74 A00920C6 */  lwc1       $f0, 0x9A0($17)
    /* 24DD78 0034DD78 40D30046 */  add.s      $f13, $f26, $f0
    /* 24DD7C 0034DD7C 2D202002 */  daddu      $4, $17, $0
    /* 24DD80 0034DD80 86AB0046 */  mov.s      $f14, $f21
    /* 24DD84 0034DD84 C6A30046 */  mov.s      $f15, $f20
    /* 24DD88 0034DD88 D8380D0C */  jal        func_0034e360
    /* 24DD8C 0034DD8C 00000000 */   nop
    /* 24DD90 0034DD90 701622A6 */  sh         $2, 0x1670($17)
    /* 24DD94 0034DD94 00608044 */  mtc1       $0, $f12
    /* 24DD98 0034DD98 2D202002 */  daddu      $4, $17, $0
    /* 24DD9C 0034DD9C 46630046 */  mov.s      $f13, $f12
    /* 24DDA0 0034DDA0 86CB0046 */  mov.s      $f14, $f25
    /* 24DDA4 0034DDA4 A43B0D0C */  jal        func_0034ee90
    /* 24DDA8 0034DDA8 00000000 */   nop
    /* 24DDAC 0034DDAC 5000BFDF */  ld         $31, 0x50($29)
    /* 24DDB0 0034DDB0 4000B17B */  lq         $17, 0x40($29)
    /* 24DDB4 0034DDB4 3000B07B */  lq         $16, 0x30($29)
    /* 24DDB8 0034DDB8 2400BDC7 */  lwc1       $f29, 0x24($29)
    /* 24DDBC 0034DDBC 2000BCC7 */  lwc1       $f28, 0x20($29)
    /* 24DDC0 0034DDC0 1C00BBC7 */  lwc1       $f27, 0x1C($29)
    /* 24DDC4 0034DDC4 1800BAC7 */  lwc1       $f26, 0x18($29)
    /* 24DDC8 0034DDC8 1400B9C7 */  lwc1       $f25, 0x14($29)
    /* 24DDCC 0034DDCC 1000B8C7 */  lwc1       $f24, 0x10($29)
    /* 24DDD0 0034DDD0 0C00B7C7 */  lwc1       $f23, 0xC($29)
    /* 24DDD4 0034DDD4 0800B6C7 */  lwc1       $f22, 0x8($29)
    /* 24DDD8 0034DDD8 0400B5C7 */  lwc1       $f21, 0x4($29)
    /* 24DDDC 0034DDDC 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* 24DDE0 0034DDE0 6000BD27 */  addiu      $29, $29, 0x60
    /* 24DDE4 0034DDE4 0800E003 */  jr         $31
    /* 24DDE8 0034DDE8 00000000 */   nop
    /* 24DDEC 0034DDEC 00000000 */  nop
.size func_0034db60, 0x290
