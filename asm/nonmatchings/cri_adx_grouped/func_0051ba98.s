.section .text
.set noat
.set noreorder
glabel func_0051ba98
    /* 41BA98 0051BA98 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 41BA9C 0051BA9C 1000B0FF */  sd         $16, 0x10($29)
    /* 41BAA0 0051BAA0 2D80A000 */  daddu      $16, $5, $0
    /* 41BAA4 0051BAA4 1800B1FF */  sd         $17, 0x18($29)
    /* 41BAA8 0051BAA8 2D888000 */  daddu      $17, $4, $0
    /* 41BAAC 0051BAAC 2000B2FF */  sd         $18, 0x20($29)
    /* 41BAB0 0051BAB0 80001224 */  addiu      $18, $0, 0x80
    /* 41BAB4 0051BAB4 2800B3FF */  sd         $19, 0x28($29)
    /* 41BAB8 0051BAB8 04001324 */  addiu      $19, $0, 0x4
    /* 41BABC 0051BABC 0A000010 */  b          .L0051BAE8
    /* 41BAC0 0051BAC0 3000BFFF */   sd        $31, 0x30($29)
    /* 41BAC4 0051BAC4 00000000 */  nop
  .L0051BAC8:
    /* 41BAC8 0051BAC8 0000038E */  lw         $3, 0x0($16)
    /* 41BACC 0051BACC 2D280000 */  daddu      $5, $0, $0
    /* 41BAD0 0051BAD0 2000628C */  lw         $2, 0x20($3)
    /* 41BAD4 0051BAD4 09F84000 */  jalr       $2
    /* 41BAD8 0051BAD8 2D30A003 */   daddu     $6, $29, $0
    /* 41BADC 0051BADC 2D202002 */  daddu      $4, $17, $0
    /* 41BAE0 0051BAE0 D66E140C */  jal        func_0051bb58
    /* 41BAE4 0051BAE4 04000524 */   addiu     $5, $0, 0x4
  .L0051BAE8:
    /* 41BAE8 0051BAE8 0000028E */  lw         $2, 0x0($16)
    /* 41BAEC 0051BAEC 2D200002 */  daddu      $4, $16, $0
    /* 41BAF0 0051BAF0 01000524 */  addiu      $5, $0, 0x1
    /* 41BAF4 0051BAF4 04000624 */  addiu      $6, $0, 0x4
    /* 41BAF8 0051BAF8 1800438C */  lw         $3, 0x18($2)
    /* 41BAFC 0051BAFC 09F86000 */  jalr       $3
    /* 41BB00 0051BB00 2D38A003 */   daddu     $7, $29, $0
    /* 41BB04 0051BB04 0400A28F */  lw         $2, 0x4($29)
    /* 41BB08 0051BB08 06005354 */  bnel       $2, $19, .L0051BB24
    /* 41BB0C 0051BB0C 0000038E */   lw        $3, 0x0($16)
    /* 41BB10 0051BB10 160F140C */  jal        func_00503c58
    /* 41BB14 0051BB14 0000A48F */   lw        $4, 0x0($29)
    /* 41BB18 0051BB18 EBFF5210 */  beq        $2, $18, .L0051BAC8
    /* 41BB1C 0051BB1C 2D200002 */   daddu     $4, $16, $0
    /* 41BB20 0051BB20 0000038E */  lw         $3, 0x0($16)
  .L0051BB24:
    /* 41BB24 0051BB24 2D200002 */  daddu      $4, $16, $0
    /* 41BB28 0051BB28 01000524 */  addiu      $5, $0, 0x1
    /* 41BB2C 0051BB2C 1C00628C */  lw         $2, 0x1C($3)
    /* 41BB30 0051BB30 09F84000 */  jalr       $2
    /* 41BB34 0051BB34 2D30A003 */   daddu     $6, $29, $0
    /* 41BB38 0051BB38 1000B0DF */  ld         $16, 0x10($29)
    /* 41BB3C 0051BB3C 1800B1DF */  ld         $17, 0x18($29)
    /* 41BB40 0051BB40 2000B2DF */  ld         $18, 0x20($29)
    /* 41BB44 0051BB44 2800B3DF */  ld         $19, 0x28($29)
    /* 41BB48 0051BB48 3000BFDF */  ld         $31, 0x30($29)
    /* 41BB4C 0051BB4C 0800E003 */  jr         $31
    /* 41BB50 0051BB50 4000BD27 */   addiu     $29, $29, 0x40
    /* 41BB54 0051BB54 00000000 */  nop
.size func_0051ba98, 0xc0
