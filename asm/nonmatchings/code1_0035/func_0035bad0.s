.section .text
.set noat
.set noreorder
glabel func_0035bad0
    /* 25BAD0 0035BAD0 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 25BAD4 0035BAD4 2000BFFF */  sd         $31, 0x20($29)
    /* 25BAD8 0035BAD8 1000B07F */  sq         $16, 0x10($29)
    /* 25BADC 0035BADC 0800B6E7 */  swc1       $f22, 0x8($29)
    /* 25BAE0 0035BAE0 0400B5E7 */  swc1       $f21, 0x4($29)
    /* 25BAE4 0035BAE4 0000B4E7 */  swc1       $f20, 0x0($29)
    /* 25BAE8 0035BAE8 2D808000 */  daddu      $16, $4, $0
    /* 25BAEC 0035BAEC 24008284 */  lh         $2, 0x24($4)
    /* 25BAF0 0035BAF0 01004224 */  addiu      $2, $2, 0x1
    /* 25BAF4 0035BAF4 240082A4 */  sh         $2, 0x24($4)
    /* 25BAF8 0035BAF8 3C140200 */  dsll32     $2, $2, 16
    /* 25BAFC 0035BAFC 3F140200 */  dsra32     $2, $2, 16
    /* 25BB00 0035BB00 64004228 */  slti       $2, $2, 0x64
    /* 25BB04 0035BB04 02004014 */  bnez       $2, .L0035BB10
    /* 25BB08 0035BB08 00000000 */   nop
    /* 25BB0C 0035BB0C 240000A6 */  sh         $0, 0x24($16)
  .L0035BB10:
    /* 25BB10 0035BB10 22000286 */  lh         $2, 0x22($16)
    /* 25BB14 0035BB14 0A004128 */  slti       $1, $2, 0xA
    /* 25BB18 0035BB18 03002010 */  beqz       $1, .L0035BB28
    /* 25BB1C 0035BB1C 00000000 */   nop
    /* 25BB20 0035BB20 01004224 */  addiu      $2, $2, 0x1
    /* 25BB24 0035BB24 220002A6 */  sh         $2, 0x22($16)
  .L0035BB28:
    /* 25BB28 0035BB28 22000286 */  lh         $2, 0x22($16)
    /* 25BB2C 0035BB2C 00008244 */  mtc1       $2, $f0
    /* 25BB30 0035BB30 00000000 */  nop
    /* 25BB34 0035BB34 60008046 */  cvt.s.w    $f1, $f0
    /* 25BB38 0035BB38 2041023C */  lui        $2, (0x41200000 >> 16)
    /* 25BB3C 0035BB3C 00008244 */  mtc1       $2, $f0
    /* 25BB40 0035BB40 00000000 */  nop
    /* 25BB44 0035BB44 030D0046 */  div.s      $f20, $f1, $f0
    /* 25BB48 0035BB48 00000000 */  nop
    /* 25BB4C 0035BB4C 00008044 */  mtc1       $0, $f0
    /* 25BB50 0035BB50 00000000 */  nop
    /* 25BB54 0035BB54 34A00046 */  c.lt.s     $f20, $f0
    /* 25BB58 0035BB58 07000145 */  bc1t       .L0035BB78
    /* 25BB5C 0035BB5C 00000000 */   nop
    /* 25BB60 0035BB60 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 25BB64 0035BB64 00008244 */  mtc1       $2, $f0
    /* 25BB68 0035BB68 00000000 */  nop
    /* 25BB6C 0035BB6C 36A00046 */  c.le.s     $f20, $f0
    /* 25BB70 0035BB70 06000145 */  bc1t       .L0035BB8C
    /* 25BB74 0035BB74 00000000 */   nop
  .L0035BB78:
    /* 25BB78 0035BB78 6500043C */  lui        $4, %hi(D_0064CC98)
    /* 25BB7C 0035BB7C 98CC8424 */  addiu      $4, $4, %lo(D_0064CC98)
    /* 25BB80 0035BB80 81080524 */  addiu      $5, $0, 0x881
    /* 25BB84 0035BB84 CCB5110C */  jal        func_0046d730
    /* 25BB88 0035BB88 00000000 */   nop
  .L0035BB8C:
    /* 25BB8C 0035BB8C A48480C7 */  lwc1       $f0, -0x7B5C($28)
    /* 25BB90 0035BB90 82051446 */  mul.s      $f22, $f0, $f20
    /* 25BB94 0035BB94 180015C6 */  lwc1       $f21, 0x18($16)
    /* 25BB98 0035BB98 06B30046 */  mov.s      $f12, $f22
    /* 25BB9C 0035BB9C EC2D110C */  jal        func_0044b7b0
    /* 25BBA0 0035BBA0 00000000 */   nop
    /* 25BBA4 0035BBA4 100001C6 */  lwc1       $f1, 0x10($16)
    /* 25BBA8 0035BBA8 81081546 */  sub.s      $f2, $f1, $f21
    /* 25BBAC 0035BBAC 00088044 */  mtc1       $0, $f1
    /* 25BBB0 0035BBB0 00000000 */  nop
    /* 25BBB4 0035BBB4 18081546 */  adda.s     $f1, $f21
    /* 25BBB8 0035BBB8 1C100046 */  madd.s     $f0, $f2, $f0
    /* 25BBBC 0035BBBC 080000E6 */  swc1       $f0, 0x8($16)
    /* 25BBC0 0035BBC0 1C0015C6 */  lwc1       $f21, 0x1C($16)
    /* 25BBC4 0035BBC4 06B30046 */  mov.s      $f12, $f22
    /* 25BBC8 0035BBC8 EC2D110C */  jal        func_0044b7b0
    /* 25BBCC 0035BBCC 00000000 */   nop
    /* 25BBD0 0035BBD0 140001C6 */  lwc1       $f1, 0x14($16)
    /* 25BBD4 0035BBD4 81081546 */  sub.s      $f2, $f1, $f21
    /* 25BBD8 0035BBD8 00088044 */  mtc1       $0, $f1
    /* 25BBDC 0035BBDC 00000000 */  nop
    /* 25BBE0 0035BBE0 18081546 */  adda.s     $f1, $f21
    /* 25BBE4 0035BBE4 1C100046 */  madd.s     $f0, $f2, $f0
    /* 25BBE8 0035BBE8 0C0000E6 */  swc1       $f0, 0xC($16)
    /* 25BBEC 0035BBEC 06A00046 */  mov.s      $f0, $f20
    /* 25BBF0 0035BBF0 2000BFDF */  ld         $31, 0x20($29)
    /* 25BBF4 0035BBF4 1000B07B */  lq         $16, 0x10($29)
    /* 25BBF8 0035BBF8 0800B6C7 */  lwc1       $f22, 0x8($29)
    /* 25BBFC 0035BBFC 0400B5C7 */  lwc1       $f21, 0x4($29)
    /* 25BC00 0035BC00 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* 25BC04 0035BC04 3000BD27 */  addiu      $29, $29, 0x30
    /* 25BC08 0035BC08 0800E003 */  jr         $31
    /* 25BC0C 0035BC0C 00000000 */   nop
.size func_0035bad0, 0x140
