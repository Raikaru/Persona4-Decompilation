.section .text
.set noat
.set noreorder
glabel func_0044ba98
    /* 34BA98 0044BA98 00F80F24 */  addiu      $15, $0, -0x800
    /* 34BA9C 0044BA9C E0FFBD27 */  addiu      $29, $29, -0x20
    /* 34BAA0 0044BAA0 FA7A0F00 */  dsrl       $15, $15, 11
    /* 34BAA4 0044BAA4 1000B2FF */  sd         $18, 0x10($29)
    /* 34BAA8 0044BAA8 00F80E24 */  addiu      $14, $0, -0x800
    /* 34BAAC 0044BAAC 0000B0FF */  sd         $16, 0x0($29)
    /* 34BAB0 0044BAB0 2D788F00 */  daddu      $15, $4, $15
    /* 34BAB4 0044BAB4 0800B1FF */  sd         $17, 0x8($29)
    /* 34BAB8 0044BAB8 BA720E00 */  dsrl       $14, $14, 10
    /* 34BABC 0044BABC 1800BFFF */  sd         $31, 0x18($29)
    /* 34BAC0 0044BAC0 2B70CF01 */  sltu       $14, $14, $15
    /* 34BAC4 0044BAC4 2D908000 */  daddu      $18, $4, $0
    /* 34BAC8 0044BAC8 FF078D30 */  andi       $13, $4, 0x7FF
    /* 34BACC 0044BACC 0200C011 */  beqz       $14, .L0044BAD8
    /* 34BAD0 0044BAD0 00088F34 */   ori       $15, $4, 0x800
    /* 34BAD4 0044BAD4 0B90ED01 */  movn       $18, $15, $13
  .L0044BAD8:
    /* 34BAD8 0044BAD8 3F201200 */  dsra32     $4, $18, 0
    /* 34BADC 0044BADC 0F041024 */  addiu      $16, $0, 0x40F
    /* 34BAE0 0044BAE0 9639110C */  jal        func_0044e658
    /* 34BAE4 0044BAE4 3C851000 */   dsll32    $16, $16, 20
    /* 34BAE8 0044BAE8 2D280002 */  daddu      $5, $16, $0
    /* 34BAEC 0044BAEC 5A38110C */  jal        func_0044e168
    /* 34BAF0 0044BAF0 2D204000 */   daddu     $4, $2, $0
    /* 34BAF4 0044BAF4 2D280002 */  daddu      $5, $16, $0
    /* 34BAF8 0044BAF8 2D204000 */  daddu      $4, $2, $0
    /* 34BAFC 0044BAFC 5A38110C */  jal        func_0044e168
    /* 34BB00 0044BB00 3C801200 */   dsll32    $16, $18, 0
    /* 34BB04 0044BB04 3E801000 */  dsrl32     $16, $16, 0
    /* 34BB08 0044BB08 2D884000 */  daddu      $17, $2, $0
    /* 34BB0C 0044BB0C 3C801000 */  dsll32     $16, $16, 0
    /* 34BB10 0044BB10 3F801000 */  dsra32     $16, $16, 0
    /* 34BB14 0044BB14 9639110C */  jal        func_0044e658
    /* 34BB18 0044BB18 2D200002 */   daddu     $4, $16, $0
    /* 34BB1C 0044BB1C 1F040524 */  addiu      $5, $0, 0x41F
    /* 34BB20 0044BB20 2D204000 */  daddu      $4, $2, $0
    /* 34BB24 0044BB24 03000106 */  bgez       $16, .L0044BB34
    /* 34BB28 0044BB28 3C2D0500 */   dsll32    $5, $5, 20
    /* 34BB2C 0044BB2C 2A38110C */  jal        func_0044e0a8
    /* 34BB30 0044BB30 00000000 */   nop
  .L0044BB34:
    /* 34BB34 0044BB34 2D284000 */  daddu      $5, $2, $0
    /* 34BB38 0044BB38 2A38110C */  jal        func_0044e0a8
    /* 34BB3C 0044BB3C 2D202002 */   daddu     $4, $17, $0
    /* 34BB40 0044BB40 F639110C */  jal        func_0044e7d8
    /* 34BB44 0044BB44 2D204000 */   daddu     $4, $2, $0
    /* 34BB48 0044BB48 0000B0DF */  ld         $16, 0x0($29)
    /* 34BB4C 0044BB4C 0800B1DF */  ld         $17, 0x8($29)
    /* 34BB50 0044BB50 1000B2DF */  ld         $18, 0x10($29)
    /* 34BB54 0044BB54 1800BFDF */  ld         $31, 0x18($29)
    /* 34BB58 0044BB58 0800E003 */  jr         $31
    /* 34BB5C 0044BB5C 2000BD27 */   addiu     $29, $29, 0x20
.size func_0044ba98, 0xc8
