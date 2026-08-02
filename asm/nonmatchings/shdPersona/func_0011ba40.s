.section .text
.set noat
.set noreorder
glabel func_0011ba40
    /* 1BA40 0011BA40 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 1BA44 0011BA44 1000BFFF */  sd         $31, 0x10($29)
    /* 1BA48 0011BA48 0000B07F */  sq         $16, 0x0($29)
    /* 1BA4C 0011BA4C 2D808000 */  daddu      $16, $4, $0
    /* 1BA50 0011BA50 3405838C */  lw         $3, 0x534($4)
    /* 1BA54 0011BA54 01006334 */  ori        $3, $3, 0x1
    /* 1BA58 0011BA58 340583AC */  sw         $3, 0x534($4)
    /* 1BA5C 0011BA5C 02006534 */  ori        $5, $3, 0x2
    /* 1BA60 0011BA60 340585AC */  sw         $5, 0x534($4)
    /* 1BA64 0011BA64 2000033C */  lui        $3, (0x200000 >> 16)
    /* 1BA68 0011BA68 2528A300 */  or         $5, $5, $3
    /* 1BA6C 0011BA6C 340585AC */  sw         $5, 0x534($4)
    /* 1BA70 0011BA70 8000033C */  lui        $3, (0x800000 >> 16)
    /* 1BA74 0011BA74 2528A300 */  or         $5, $5, $3
    /* 1BA78 0011BA78 340585AC */  sw         $5, 0x534($4)
    /* 1BA7C 0011BA7C FBFF0324 */  addiu      $3, $0, -0x5
    /* 1BA80 0011BA80 2428A300 */  and        $5, $5, $3
    /* 1BA84 0011BA84 340585AC */  sw         $5, 0x534($4)
    /* 1BA88 0011BA88 FFBF0324 */  addiu      $3, $0, -0x4001
    /* 1BA8C 0011BA8C 2428A300 */  and        $5, $5, $3
    /* 1BA90 0011BA90 340585AC */  sw         $5, 0x534($4)
    /* 1BA94 0011BA94 BFFF033C */  lui        $3, (0xFFBFFFFF >> 16)
    /* 1BA98 0011BA98 FFFF6334 */  ori        $3, $3, (0xFFBFFFFF & 0xFFFF)
    /* 1BA9C 0011BA9C 2418A300 */  and        $3, $5, $3
    /* 1BAA0 0011BAA0 340583AC */  sw         $3, 0x534($4)
    /* 1BAA4 0011BAA4 0000838C */  lw         $3, 0x0($4)
    /* 1BAA8 0011BAA8 10006010 */  beqz       $3, .L0011BAEC
    /* 1BAAC 0011BAAC 00000000 */   nop
    /* 1BAB0 0011BAB0 00006394 */  lhu        $3, 0x0($3)
    /* 1BAB4 0011BAB4 04006330 */  andi       $3, $3, 0x4
    /* 1BAB8 0011BAB8 0C006010 */  beqz       $3, .L0011BAEC
    /* 1BABC 0011BABC 00000000 */   nop
    /* 1BAC0 0011BAC0 3405038E */  lw         $3, 0x534($16)
    /* 1BAC4 0011BAC4 0800023C */  lui        $2, (0x80000 >> 16)
    /* 1BAC8 0011BAC8 25106200 */  or         $2, $3, $2
    /* 1BACC 0011BACC 340502AE */  sw         $2, 0x534($16)
    /* 1BAD0 0011BAD0 58040426 */  addiu      $4, $16, 0x458
    /* 1BAD4 0011BAD4 2D280000 */  daddu      $5, $0, $0
    /* 1BAD8 0011BAD8 68000624 */  addiu      $6, $0, 0x68
    /* 1BADC 0011BADC 72FE100C */  jal        func_0043f9c8
    /* 1BAE0 0011BAE0 00000000 */   nop
    /* 1BAE4 0011BAE4 06000010 */  b          .L0011BB00
    /* 1BAE8 0011BAE8 00000000 */   nop
  .L0011BAEC:
    /* 1BAEC 0011BAEC 3405048E */  lw         $4, 0x534($16)
    /* 1BAF0 0011BAF0 F7FF033C */  lui        $3, (0xFFF7FFFF >> 16)
    /* 1BAF4 0011BAF4 FFFF6334 */  ori        $3, $3, (0xFFF7FFFF & 0xFFFF)
    /* 1BAF8 0011BAF8 24188300 */  and        $3, $4, $3
    /* 1BAFC 0011BAFC 340503AE */  sw         $3, 0x534($16)
  .L0011BB00:
    /* 1BB00 0011BB00 2C05048E */  lw         $4, 0x52C($16)
    /* 1BB04 0011BB04 04000324 */  addiu      $3, $0, 0x4
    /* 1BB08 0011BB08 1B008310 */  beq        $4, $3, .L0011BB78
    /* 1BB0C 0011BB0C 00000000 */   nop
    /* 1BB10 0011BB10 03000324 */  addiu      $3, $0, 0x3
    /* 1BB14 0011BB14 18008310 */  beq        $4, $3, .L0011BB78
    /* 1BB18 0011BB18 00000000 */   nop
    /* 1BB1C 0011BB1C 02000224 */  addiu      $2, $0, 0x2
    /* 1BB20 0011BB20 08008210 */  beq        $4, $2, .L0011BB44
    /* 1BB24 0011BB24 00000000 */   nop
    /* 1BB28 0011BB28 01000224 */  addiu      $2, $0, 0x1
    /* 1BB2C 0011BB2C 05008210 */  beq        $4, $2, .L0011BB44
    /* 1BB30 0011BB30 00000000 */   nop
    /* 1BB34 0011BB34 03008010 */  beqz       $4, .L0011BB44
    /* 1BB38 0011BB38 00000000 */   nop
    /* 1BB3C 0011BB3C 09000010 */  b          .L0011BB64
    /* 1BB40 0011BB40 00000000 */   nop
  .L0011BB44:
    /* 1BB44 0011BB44 2D200000 */  daddu      $4, $0, $0
    /* 1BB48 0011BB48 01000524 */  addiu      $5, $0, 0x1
    /* 1BB4C 0011BB4C 2D300000 */  daddu      $6, $0, $0
    /* 1BB50 0011BB50 03000724 */  addiu      $7, $0, 0x3
    /* 1BB54 0011BB54 D86B110C */  jal        func_0045af60
    /* 1BB58 0011BB58 00000000 */   nop
    /* 1BB5C 0011BB5C 06000010 */  b          .L0011BB78
    /* 1BB60 0011BB60 00000000 */   nop
  .L0011BB64:
    /* 1BB64 0011BB64 5E00043C */  lui        $4, %hi(D_005E4868)
    /* 1BB68 0011BB68 68488424 */  addiu      $4, $4, %lo(D_005E4868)
    /* 1BB6C 0011BB6C 8F0C0524 */  addiu      $5, $0, 0xC8F
    /* 1BB70 0011BB70 CCB5110C */  jal        func_0046d730
    /* 1BB74 0011BB74 00000000 */   nop
  .L0011BB78:
    /* 1BB78 0011BB78 1000BFDF */  ld         $31, 0x10($29)
    /* 1BB7C 0011BB7C 0000B07B */  lq         $16, 0x0($29)
    /* 1BB80 0011BB80 2000BD27 */  addiu      $29, $29, 0x20
    /* 1BB84 0011BB84 0800E003 */  jr         $31
    /* 1BB88 0011BB88 00000000 */   nop
    /* 1BB8C 0011BB8C 00000000 */  nop
.size func_0011ba40, 0x150
