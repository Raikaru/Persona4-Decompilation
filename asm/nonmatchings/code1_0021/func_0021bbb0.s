.section .text
.set noat
.set noreorder
glabel func_0021bbb0
    /* 11BBB0 0021BBB0 B0FFBD27 */  addiu      $29, $29, -0x50
    /* 11BBB4 0021BBB4 2000BFFF */  sd         $31, 0x20($29)
    /* 11BBB8 0021BBB8 1000B07F */  sq         $16, 0x10($29)
    /* 11BBBC 0021BBBC 0000B4E7 */  swc1       $f20, 0x0($29)
    /* 11BBC0 0021BBC0 3400A4AF */  sw         $4, 0x34($29)
    /* 11BBC4 0021BBC4 2D80A000 */  daddu      $16, $5, $0
    /* 11BBC8 0021BBC8 A043023C */  lui        $2, (0x43A00000 >> 16)
    /* 11BBCC 0021BBCC 3800A2AF */  sw         $2, 0x38($29)
    /* 11BBD0 0021BBD0 6443023C */  lui        $2, (0x43640000 >> 16)
    /* 11BBD4 0021BBD4 3C00A2AF */  sw         $2, 0x3C($29)
    /* 11BBD8 0021BBD8 01000424 */  addiu      $4, $0, 0x1
    /* 11BBDC 0021BBDC 2D280000 */  daddu      $5, $0, $0
    /* 11BBE0 0021BBE0 8800023C */  lui        $2, %hi(D_00887300)
    /* 11BBE4 0021BBE4 0073428C */  lw         $2, %lo(D_00887300)($2)
    /* 11BBE8 0021BBE8 09F84000 */  jalr       $2
    /* 11BBEC 0021BBEC 00000000 */   nop
    /* 11BBF0 0021BBF0 FFFF1032 */  andi       $16, $16, 0xFFFF
    /* 11BBF4 0021BBF4 2100032A */  slti       $3, $16, 0x21
    /* 11BBF8 0021BBF8 40006014 */  bnez       $3, .L0021BCFC
    /* 11BBFC 0021BBFC 00000000 */   nop
    /* 11BC00 0021BC00 3000012A */  slti       $1, $16, 0x30
    /* 11BC04 0021BC04 3D002010 */  beqz       $1, .L0021BCFC
    /* 11BC08 0021BC08 00000000 */   nop
    /* 11BC0C 0021BC0C 4C00A0A3 */  sb         $0, 0x4C($29)
    /* 11BC10 0021BC10 4D00A0A3 */  sb         $0, 0x4D($29)
    /* 11BC14 0021BC14 4E00A0A3 */  sb         $0, 0x4E($29)
    /* 11BC18 0021BC18 DFFF0226 */  addiu      $2, $16, -0x21
    /* 11BC1C 0021BC1C 00008244 */  mtc1       $2, $f0
    /* 11BC20 0021BC20 00000000 */  nop
    /* 11BC24 0021BC24 60008046 */  cvt.s.w    $f1, $f0
    /* 11BC28 0021BC28 7041023C */  lui        $2, (0x41700000 >> 16)
    /* 11BC2C 0021BC2C 00008244 */  mtc1       $2, $f0
    /* 11BC30 0021BC30 00000000 */  nop
    /* 11BC34 0021BC34 43080046 */  div.s      $f1, $f1, $f0
    /* 11BC38 0021BC38 00000000 */  nop
    /* 11BC3C 0021BC3C A48480C7 */  lwc1       $f0, -0x7B5C($28)
    /* 11BC40 0021BC40 02030146 */  mul.s      $f12, $f0, $f1
    /* 11BC44 0021BC44 842D110C */  jal        func_0044b610
    /* 11BC48 0021BC48 00000000 */   nop
    /* 11BC4C 0021BC4C 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 11BC50 0021BC50 00088244 */  mtc1       $2, $f1
    /* 11BC54 0021BC54 00000000 */  nop
    /* 11BC58 0021BC58 41080046 */  sub.s      $f1, $f1, $f0
    /* 11BC5C 0021BC5C C843023C */  lui        $2, (0x43C80000 >> 16)
    /* 11BC60 0021BC60 00008244 */  mtc1       $2, $f0
    /* 11BC64 0021BC64 00000000 */  nop
    /* 11BC68 0021BC68 02050146 */  mul.s      $f20, $f0, $f1
    /* 11BC6C 0021BC6C E027120C */  jal        func_00489f80
    /* 11BC70 0021BC70 00000000 */   nop
    /* 11BC74 0021BC74 03000424 */  addiu      $4, $0, 0x3
    /* 11BC78 0021BC78 0300023C */  lui        $2, (0x31801 >> 16)
    /* 11BC7C 0021BC7C 01184534 */  ori        $5, $2, (0x31801 & 0xFFFF)
    /* 11BC80 0021BC80 10D90F0C */  jal        func_003f6440
    /* 11BC84 0021BC84 00000000 */   nop
    /* 11BC88 0021BC88 4F00A0A3 */  sb         $0, 0x4F($29)
    /* 11BC8C 0021BC8C 4C00A427 */  addiu      $4, $29, 0x4C
    /* 11BC90 0021BC90 2D280000 */  daddu      $5, $0, $0
    /* 11BC94 0021BC94 1C72110C */  jal        func_0045c870
    /* 11BC98 0021BC98 00000000 */   nop
    /* 11BC9C 0021BC9C FF000224 */  addiu      $2, $0, 0xFF
    /* 11BCA0 0021BCA0 4F00A2A3 */  sb         $2, 0x4F($29)
    /* 11BCA4 0021BCA4 4C00A0C7 */  lwc1       $f0, 0x4C($29)
    /* 11BCA8 0021BCA8 4800A0E7 */  swc1       $f0, 0x48($29)
    /* 11BCAC 0021BCAC 00608044 */  mtc1       $0, $f12
    /* 11BCB0 0021BCB0 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 11BCB4 0021BCB4 00808244 */  mtc1       $2, $f16
    /* 11BCB8 0021BCB8 3800A4DF */  ld         $4, 0x38($29)
    /* 11BCBC 0021BCBC 4800A58F */  lw         $5, 0x48($29)
    /* 11BCC0 0021BCC0 2D30A000 */  daddu      $6, $5, $0
    /* 11BCC4 0021BCC4 46A30046 */  mov.s      $f13, $f20
    /* 11BCC8 0021BCC8 86630046 */  mov.s      $f14, $f12
    /* 11BCCC 0021BCCC 24000724 */  addiu      $7, $0, 0x24
    /* 11BCD0 0021BCD0 CC848FC7 */  lwc1       $f15, -0x7B34($28)
    /* 11BCD4 0021BCD4 2D400000 */  daddu      $8, $0, $0
    /* 11BCD8 0021BCD8 C0970D0C */  jal        func_00365f00
    /* 11BCDC 0021BCDC 00000000 */   nop
    /* 11BCE0 0021BCE0 0028120C */  jal        func_0048a000
    /* 11BCE4 0021BCE4 00000000 */   nop
    /* 11BCE8 0021BCE8 03000424 */  addiu      $4, $0, 0x3
    /* 11BCEC 0021BCEC 0300023C */  lui        $2, (0x37801 >> 16)
    /* 11BCF0 0021BCF0 01784534 */  ori        $5, $2, (0x37801 & 0xFFFF)
    /* 11BCF4 0021BCF4 10D90F0C */  jal        func_003f6440
    /* 11BCF8 0021BCF8 00000000 */   nop
  .L0021BCFC:
    /* 11BCFC 0021BCFC 0300032A */  slti       $3, $16, 0x3
    /* 11BD00 0021BD00 3C006014 */  bnez       $3, .L0021BDF4
    /* 11BD04 0021BD04 00000000 */   nop
    /* 11BD08 0021BD08 2100012A */  slti       $1, $16, 0x21
    /* 11BD0C 0021BD0C 2A002010 */  beqz       $1, .L0021BDB8
    /* 11BD10 0021BD10 00000000 */   nop
    /* 11BD14 0021BD14 02000424 */  addiu      $4, $0, 0x2
    /* 11BD18 0021BD18 48000524 */  addiu      $5, $0, 0x48
    /* 11BD1C 0021BD1C 10D90F0C */  jal        func_003f6440
    /* 11BD20 0021BD20 00000000 */   nop
    /* 11BD24 0021BD24 FDFF0226 */  addiu      $2, $16, -0x3
    /* 11BD28 0021BD28 00008244 */  mtc1       $2, $f0
    /* 11BD2C 0021BD2C 00000000 */  nop
    /* 11BD30 0021BD30 60008046 */  cvt.s.w    $f1, $f0
    /* 11BD34 0021BD34 F041023C */  lui        $2, (0x41F00000 >> 16)
    /* 11BD38 0021BD38 00008244 */  mtc1       $2, $f0
    /* 11BD3C 0021BD3C 00000000 */  nop
    /* 11BD40 0021BD40 43080046 */  div.s      $f1, $f1, $f0
    /* 11BD44 0021BD44 00000000 */  nop
    /* 11BD48 0021BD48 A48480C7 */  lwc1       $f0, -0x7B5C($28)
    /* 11BD4C 0021BD4C 02030146 */  mul.s      $f12, $f0, $f1
    /* 11BD50 0021BD50 EC2D110C */  jal        func_0044b7b0
    /* 11BD54 0021BD54 00000000 */   nop
    /* 11BD58 0021BD58 C843023C */  lui        $2, (0x43C80000 >> 16)
    /* 11BD5C 0021BD5C 00088244 */  mtc1       $2, $f1
    /* 11BD60 0021BD60 00000000 */  nop
    /* 11BD64 0021BD64 420B0046 */  mul.s      $f13, $f1, $f0
    /* 11BD68 0021BD68 3400A0C7 */  lwc1       $f0, 0x34($29)
    /* 11BD6C 0021BD6C 4400A0E7 */  swc1       $f0, 0x44($29)
    /* 11BD70 0021BD70 00608044 */  mtc1       $0, $f12
    /* 11BD74 0021BD74 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 11BD78 0021BD78 00808244 */  mtc1       $2, $f16
    /* 11BD7C 0021BD7C 3800A4DF */  ld         $4, 0x38($29)
    /* 11BD80 0021BD80 4400A58F */  lw         $5, 0x44($29)
    /* 11BD84 0021BD84 2D30A000 */  daddu      $6, $5, $0
    /* 11BD88 0021BD88 86630046 */  mov.s      $f14, $f12
    /* 11BD8C 0021BD8C 24000724 */  addiu      $7, $0, 0x24
    /* 11BD90 0021BD90 CC848FC7 */  lwc1       $f15, -0x7B34($28)
    /* 11BD94 0021BD94 2D400000 */  daddu      $8, $0, $0
    /* 11BD98 0021BD98 C0970D0C */  jal        func_00365f00
    /* 11BD9C 0021BD9C 00000000 */   nop
    /* 11BDA0 0021BDA0 02000424 */  addiu      $4, $0, 0x2
    /* 11BDA4 0021BDA4 44000524 */  addiu      $5, $0, 0x44
    /* 11BDA8 0021BDA8 10D90F0C */  jal        func_003f6440
    /* 11BDAC 0021BDAC 00000000 */   nop
    /* 11BDB0 0021BDB0 10000010 */  b          .L0021BDF4
    /* 11BDB4 0021BDB4 00000000 */   nop
  .L0021BDB8:
    /* 11BDB8 0021BDB8 3000012A */  slti       $1, $16, 0x30
    /* 11BDBC 0021BDBC 0D002010 */  beqz       $1, .L0021BDF4
    /* 11BDC0 0021BDC0 00000000 */   nop
    /* 11BDC4 0021BDC4 02000424 */  addiu      $4, $0, 0x2
    /* 11BDC8 0021BDC8 48000524 */  addiu      $5, $0, 0x48
    /* 11BDCC 0021BDCC 10D90F0C */  jal        func_003f6440
    /* 11BDD0 0021BDD0 00000000 */   nop
    /* 11BDD4 0021BDD4 3400A427 */  addiu      $4, $29, 0x34
    /* 11BDD8 0021BDD8 2D280000 */  daddu      $5, $0, $0
    /* 11BDDC 0021BDDC 1C72110C */  jal        func_0045c870
    /* 11BDE0 0021BDE0 00000000 */   nop
    /* 11BDE4 0021BDE4 02000424 */  addiu      $4, $0, 0x2
    /* 11BDE8 0021BDE8 44000524 */  addiu      $5, $0, 0x44
    /* 11BDEC 0021BDEC 10D90F0C */  jal        func_003f6440
    /* 11BDF0 0021BDF0 00000000 */   nop
  .L0021BDF4:
    /* 11BDF4 0021BDF4 2000BFDF */  ld         $31, 0x20($29)
    /* 11BDF8 0021BDF8 1000B07B */  lq         $16, 0x10($29)
    /* 11BDFC 0021BDFC 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* 11BE00 0021BE00 5000BD27 */  addiu      $29, $29, 0x50
    /* 11BE04 0021BE04 0800E003 */  jr         $31
    /* 11BE08 0021BE08 00000000 */   nop
    /* 11BE0C 0021BE0C 00000000 */  nop
.size func_0021bbb0, 0x260
