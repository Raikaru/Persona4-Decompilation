.section .text
.set noat
.set noreorder
glabel func_0043ba20
    /* 33BA20 0043BA20 80FFBD27 */  addiu      $29, $29, -0x80
    /* 33BA24 0043BA24 5000B4FF */  sd         $20, 0x50($29)
    /* 33BA28 0043BA28 2000B1FF */  sd         $17, 0x20($29)
    /* 33BA2C 0043BA2C 8C00143C */  lui        $20, %hi(D_008BE280)
    /* 33BA30 0043BA30 2D888000 */  daddu      $17, $4, $0
    /* 33BA34 0043BA34 6000B5FF */  sd         $21, 0x60($29)
    /* 33BA38 0043BA38 4000B3FF */  sd         $19, 0x40($29)
    /* 33BA3C 0043BA3C 2DA8E000 */  daddu      $21, $7, $0
    /* 33BA40 0043BA40 1000B0FF */  sd         $16, 0x10($29)
    /* 33BA44 0043BA44 2D98C000 */  daddu      $19, $6, $0
    /* 33BA48 0043BA48 80E2848E */  lw         $4, %lo(D_008BE280)($20)
    /* 33BA4C 0043BA4C 3000B2FF */  sd         $18, 0x30($29)
    /* 33BA50 0043BA50 7000BFFF */  sd         $31, 0x70($29)
    /* 33BA54 0043BA54 0886100C */  jal        func_00421820
    /* 33BA58 0043BA58 2D80A000 */   daddu     $16, $5, $0
    /* 33BA5C 0043BA5C 8C00033C */  lui        $3, %hi(D_008BDAC0)
    /* 33BA60 0043BA60 8C00043C */  lui        $4, %hi(D_008BD9C0)
    /* 33BA64 0043BA64 C0DA7224 */  addiu      $18, $3, %lo(D_008BDAC0)
    /* 33BA68 0043BA68 C0DA71AC */  sw         $17, %lo(D_008BDAC0)($3)
    /* 33BA6C 0043BA6C 040050AE */  sw         $16, 0x4($18)
    /* 33BA70 0043BA70 0080053C */  lui        $5, (0x8000131A >> 16)
    /* 33BA74 0043BA74 0000A0AF */  sw         $0, 0x0($29)
    /* 33BA78 0043BA78 C0D98424 */  addiu      $4, $4, %lo(D_008BD9C0)
    /* 33BA7C 0043BA7C 1A13A534 */  ori        $5, $5, (0x8000131A & 0xFFFF)
    /* 33BA80 0043BA80 2D300000 */  daddu      $6, $0, $0
    /* 33BA84 0043BA84 0000628E */  lw         $2, 0x0($19)
    /* 33BA88 0043BA88 2D384002 */  daddu      $7, $18, $0
    /* 33BA8C 0043BA8C 90000824 */  addiu      $8, $0, 0x90
    /* 33BA90 0043BA90 2D484002 */  daddu      $9, $18, $0
    /* 33BA94 0043BA94 080042AE */  sw         $2, 0x8($18)
    /* 33BA98 0043BA98 90000A24 */  addiu      $10, $0, 0x90
    /* 33BA9C 0043BA9C 2C96100C */  jal        func_004258b0
    /* 33BAA0 0043BAA0 2D580000 */   daddu     $11, $0, $0
    /* 33BAA4 0043BAA4 08004304 */  bgezl      $2, .L0043BAC8
    /* 33BAA8 0043BAA8 8C00508E */   lw        $16, 0x8C($18)
    /* 33BAAC 0043BAAC 7500043C */  lui        $4, %hi(D_00754CE8)
    /* 33BAB0 0043BAB0 D2EE100C */  jal        func_0043bb48
    /* 33BAB4 0043BAB4 E84C8424 */   addiu     $4, $4, %lo(D_00754CE8)
    /* 33BAB8 0043BAB8 0086100C */  jal        func_00421800
    /* 33BABC 0043BABC 80E2848E */   lw        $4, %lo(D_008BE280)($20)
    /* 33BAC0 0043BAC0 17000010 */  b          .L0043BB20
    /* 33BAC4 0043BAC4 2D100000 */   daddu     $2, $0, $0
  .L0043BAC8:
    /* 33BAC8 0043BAC8 12000006 */  bltz       $16, .L0043BB14
    /* 33BACC 0043BACC 00000000 */   nop
    /* 33BAD0 0043BAD0 0800438E */  lw         $3, 0x8($18)
    /* 33BAD4 0043BAD4 000063AE */  sw         $3, 0x0($19)
    /* 33BAD8 0043BAD8 0800428E */  lw         $2, 0x8($18)
    /* 33BADC 0043BADC 0C004018 */  blez       $2, .L0043BB10
    /* 33BAE0 0043BAE0 2D280000 */   daddu     $5, $0, $0
    /* 33BAE4 0043BAE4 0C004626 */  addiu      $6, $18, 0xC
    /* 33BAE8 0043BAE8 2110C500 */  addu       $2, $6, $5
    /* 33BAEC 0043BAEC 00000000 */  nop
  .L0043BAF0:
    /* 33BAF0 0043BAF0 2120A502 */  addu       $4, $21, $5
    /* 33BAF4 0043BAF4 00004390 */  lbu        $3, 0x0($2)
    /* 33BAF8 0043BAF8 0100A524 */  addiu      $5, $5, 0x1
    /* 33BAFC 0043BAFC 000083A0 */  sb         $3, 0x0($4)
    /* 33BB00 0043BB00 0800428E */  lw         $2, 0x8($18)
    /* 33BB04 0043BB04 2A10A200 */  slt        $2, $5, $2
    /* 33BB08 0043BB08 F9FF4014 */  bnez       $2, .L0043BAF0
    /* 33BB0C 0043BB0C 2110C500 */   addu      $2, $6, $5
  .L0043BB10:
    /* 33BB10 0043BB10 8C00508E */  lw         $16, 0x8C($18)
  .L0043BB14:
    /* 33BB14 0043BB14 0086100C */  jal        func_00421800
    /* 33BB18 0043BB18 80E2848E */   lw        $4, %lo(D_008BE280)($20)
    /* 33BB1C 0043BB1C 2D100002 */  daddu      $2, $16, $0
  .L0043BB20:
    /* 33BB20 0043BB20 7000BFDF */  ld         $31, 0x70($29)
    /* 33BB24 0043BB24 6000B5DF */  ld         $21, 0x60($29)
    /* 33BB28 0043BB28 5000B4DF */  ld         $20, 0x50($29)
    /* 33BB2C 0043BB2C 4000B3DF */  ld         $19, 0x40($29)
    /* 33BB30 0043BB30 3000B2DF */  ld         $18, 0x30($29)
    /* 33BB34 0043BB34 2000B1DF */  ld         $17, 0x20($29)
    /* 33BB38 0043BB38 1000B0DF */  ld         $16, 0x10($29)
    /* 33BB3C 0043BB3C 0800E003 */  jr         $31
    /* 33BB40 0043BB40 8000BD27 */   addiu     $29, $29, 0x80
    /* 33BB44 0043BB44 00000000 */  nop
.size func_0043ba20, 0x128
