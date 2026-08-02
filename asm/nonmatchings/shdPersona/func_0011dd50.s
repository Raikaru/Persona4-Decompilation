.section .text
.set noat
.set noreorder
glabel func_0011dd50
    /* 1DD50 0011DD50 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 1DD54 0011DD54 0000BFFF */  sd         $31, 0x0($29)
    /* 1DD58 0011DD58 3800858C */  lw         $5, 0x38($4)
    /* 1DD5C 0011DD5C 0000A48C */  lw         $4, 0x0($5)
    /* 1DD60 0011DD60 03000324 */  addiu      $3, $0, 0x3
    /* 1DD64 0011DD64 31008314 */  bne        $4, $3, .L0011DE2C
    /* 1DD68 0011DD68 00000000 */   nop
    /* 1DD6C 0011DD6C 0400A38C */  lw         $3, 0x4($5)
    /* 1DD70 0011DD70 2E006010 */  beqz       $3, .L0011DE2C
    /* 1DD74 0011DD74 00000000 */   nop
    /* 1DD78 0011DD78 1400A38C */  lw         $3, 0x14($5)
    /* 1DD7C 0011DD7C 2B006010 */  beqz       $3, .L0011DE2C
    /* 1DD80 0011DD80 00000000 */   nop
    /* 1DD84 0011DD84 2800A0C4 */  lwc1       $f0, 0x28($5)
    /* 1DD88 0011DD88 4000A1C4 */  lwc1       $f1, 0x40($5)
    /* 1DD8C 0011DD8C 01000146 */  sub.s      $f0, $f0, $f1
    /* 1DD90 0011DD90 4040023C */  lui        $2, (0x40400000 >> 16)
    /* 1DD94 0011DD94 00108244 */  mtc1       $2, $f2
    /* 1DD98 0011DD98 00000000 */  nop
    /* 1DD9C 0011DD9C 03000246 */  div.s      $f0, $f0, $f2
    /* 1DDA0 0011DDA0 00080046 */  add.s      $f0, $f1, $f0
    /* 1DDA4 0011DDA4 4000A0E4 */  swc1       $f0, 0x40($5)
    /* 1DDA8 0011DDA8 2C00A0C4 */  lwc1       $f0, 0x2C($5)
    /* 1DDAC 0011DDAC 4400A1C4 */  lwc1       $f1, 0x44($5)
    /* 1DDB0 0011DDB0 01000146 */  sub.s      $f0, $f0, $f1
    /* 1DDB4 0011DDB4 03000246 */  div.s      $f0, $f0, $f2
    /* 1DDB8 0011DDB8 00080046 */  add.s      $f0, $f1, $f0
    /* 1DDBC 0011DDBC 4400A0E4 */  swc1       $f0, 0x44($5)
    /* 1DDC0 0011DDC0 4000A1C4 */  lwc1       $f1, 0x40($5)
    /* 1DDC4 0011DDC4 3800A0C4 */  lwc1       $f0, 0x38($5)
    /* 1DDC8 0011DDC8 400B0046 */  add.s      $f13, $f1, $f0
    /* 1DDCC 0011DDCC 4400A1C4 */  lwc1       $f1, 0x44($5)
    /* 1DDD0 0011DDD0 3C00A0C4 */  lwc1       $f0, 0x3C($5)
    /* 1DDD4 0011DDD4 800B0046 */  add.s      $f14, $f1, $f0
    /* 1DDD8 0011DDD8 0044023C */  lui        $2, (0x44000000 >> 16)
    /* 1DDDC 0011DDDC 00888244 */  mtc1       $2, $f17
    /* 1DDE0 0011DDE0 1800ACC4 */  lwc1       $f12, 0x18($5)
    /* 1DDE4 0011DDE4 0C00A48C */  lw         $4, 0xC($5)
    /* 1DDE8 0011DDE8 2800AFC4 */  lwc1       $f15, 0x28($5)
    /* 1DDEC 0011DDEC 2C00B0C4 */  lwc1       $f16, 0x2C($5)
    /* 1DDF0 0011DDF0 868C0046 */  mov.s      $f18, $f17
    /* 1DDF4 0011DDF4 5000A58C */  lw         $5, 0x50($5)
    /* 1DDF8 0011DDF8 01000624 */  addiu      $6, $0, 0x1
    /* 1DDFC 0011DDFC 2D380000 */  daddu      $7, $0, $0
    /* 1DE00 0011DE00 A0910D0C */  jal        func_00364680
    /* 1DE04 0011DE04 00000000 */   nop
    /* 1DE08 0011DE08 03000424 */  addiu      $4, $0, 0x3
    /* 1DE0C 0011DE0C 0700023C */  lui        $2, (0x717FB >> 16)
    /* 1DE10 0011DE10 FB174534 */  ori        $5, $2, (0x717FB & 0xFFFF)
    /* 1DE14 0011DE14 10D90F0C */  jal        func_003f6440
    /* 1DE18 0011DE18 00000000 */   nop
    /* 1DE1C 0011DE1C 02000424 */  addiu      $4, $0, 0x2
    /* 1DE20 0011DE20 44000524 */  addiu      $5, $0, 0x44
    /* 1DE24 0011DE24 10D90F0C */  jal        func_003f6440
    /* 1DE28 0011DE28 00000000 */   nop
  .L0011DE2C:
    /* 1DE2C 0011DE2C 0000BFDF */  ld         $31, 0x0($29)
    /* 1DE30 0011DE30 1000BD27 */  addiu      $29, $29, 0x10
    /* 1DE34 0011DE34 0800E003 */  jr         $31
    /* 1DE38 0011DE38 00000000 */   nop
    /* 1DE3C 0011DE3C 00000000 */  nop
.size func_0011dd50, 0xf0
