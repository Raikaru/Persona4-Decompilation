.section .text
.set noat
.set noreorder
glabel func_004fc948
    /* 3FC948 004FC948 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3FC94C 004FC94C 2D508000 */  daddu      $10, $4, $0
    /* 3FC950 004FC950 1000B2FF */  sd         $18, 0x10($29)
    /* 3FC954 004FC954 2D90A000 */  daddu      $18, $5, $0
    /* 3FC958 004FC958 0000B0FF */  sd         $16, 0x0($29)
    /* 3FC95C 004FC95C 60014925 */  addiu      $9, $10, 0x160
    /* 3FC960 004FC960 0800B1FF */  sd         $17, 0x8($29)
    /* 3FC964 004FC964 1800BFFF */  sd         $31, 0x18($29)
    /* 3FC968 004FC968 9804228D */  lw         $2, 0x498($9)
    /* 3FC96C 004FC96C 0803238D */  lw         $3, 0x308($9)
    /* 3FC970 004FC970 01004224 */  addiu      $2, $2, 0x1
    /* 3FC974 004FC974 04006010 */  beqz       $3, .L004FC988
    /* 3FC978 004FC978 980422AD */   sw        $2, 0x498($9)
    /* 3FC97C 004FC97C 20000224 */  addiu      $2, $0, 0x20
    /* 3FC980 004FC980 05006254 */  bnel       $3, $2, .L004FC998
    /* 3FC984 004FC984 F804228D */   lw        $2, 0x4F8($9)
  .L004FC988:
    /* 3FC988 004FC988 0C03228D */  lw         $2, 0x30C($9)
    /* 3FC98C 004FC98C 05004010 */  beqz       $2, .L004FC9A4
    /* 3FC990 004FC990 FCFF0224 */   addiu     $2, $0, -0x4
    /* 3FC994 004FC994 F804228D */  lw         $2, 0x4F8($9)
  .L004FC998:
    /* 3FC998 004FC998 01004224 */  addiu      $2, $2, 0x1
    /* 3FC99C 004FC99C F80422AD */  sw         $2, 0x4F8($9)
    /* 3FC9A0 004FC9A0 FCFF0224 */  addiu      $2, $0, -0x4
  .L004FC9A4:
    /* 3FC9A4 004FC9A4 24804202 */  and        $16, $18, $2
    /* 3FC9A8 004FC9A8 23185002 */  subu       $3, $18, $16
    /* 3FC9AC 004FC9AC 00000882 */  lb         $8, 0x0($16)
    /* 3FC9B0 004FC9B0 01001026 */  addiu      $16, $16, 0x1
    /* 3FC9B4 004FC9B4 C0880300 */  sll        $17, $3, 3
    /* 3FC9B8 004FC9B8 00000492 */  lbu        $4, 0x0($16)
    /* 3FC9BC 004FC9BC 01001026 */  addiu      $16, $16, 0x1
    /* 3FC9C0 004FC9C0 00000592 */  lbu        $5, 0x0($16)
    /* 3FC9C4 004FC9C4 01001026 */  addiu      $16, $16, 0x1
    /* 3FC9C8 004FC9C8 00000692 */  lbu        $6, 0x0($16)
    /* 3FC9CC 004FC9CC 01001026 */  addiu      $16, $16, 0x1
    /* 3FC9D0 004FC9D0 00000782 */  lb         $7, 0x0($16)
    /* 3FC9D4 004FC9D4 01001026 */  addiu      $16, $16, 0x1
    /* 3FC9D8 004FC9D8 00000292 */  lbu        $2, 0x0($16)
    /* 3FC9DC 004FC9DC 01001026 */  addiu      $16, $16, 0x1
    /* 3FC9E0 004FC9E0 00420800 */  sll        $8, $8, 8
    /* 3FC9E4 004FC9E4 003A0700 */  sll        $7, $7, 8
    /* 3FC9E8 004FC9E8 25400401 */  or         $8, $8, $4
    /* 3FC9EC 004FC9EC 2538E200 */  or         $7, $7, $2
    /* 3FC9F0 004FC9F0 00000392 */  lbu        $3, 0x0($16)
    /* 3FC9F4 004FC9F4 01001026 */  addiu      $16, $16, 0x1
    /* 3FC9F8 004FC9F8 00420800 */  sll        $8, $8, 8
    /* 3FC9FC 004FC9FC 003A0700 */  sll        $7, $7, 8
    /* 3FCA00 004FCA00 25400501 */  or         $8, $8, $5
    /* 3FCA04 004FCA04 00000292 */  lbu        $2, 0x0($16)
    /* 3FCA08 004FCA08 2538E300 */  or         $7, $7, $3
    /* 3FCA0C 004FCA0C 00420800 */  sll        $8, $8, 8
    /* 3FCA10 004FCA10 003A0700 */  sll        $7, $7, 8
    /* 3FCA14 004FCA14 25400601 */  or         $8, $8, $6
    /* 3FCA18 004FCA18 01001026 */  addiu      $16, $16, 0x1
    /* 3FCA1C 004FCA1C 2538E200 */  or         $7, $7, $2
    /* 3FCA20 004FCA20 07002012 */  beqz       $17, .L004FCA40
    /* 3FCA24 004FCA24 04402802 */   sllv      $8, $8, $17
    /* 3FCA28 004FCA28 23101100 */  negu       $2, $17
    /* 3FCA2C 004FCA2C 06104700 */  srlv       $2, $7, $2
    /* 3FCA30 004FCA30 25100201 */  or         $2, $8, $2
    /* 3FCA34 004FCA34 04402702 */  sllv       $8, $7, $17
    /* 3FCA38 004FCA38 03000010 */  b          .L004FCA48
    /* 3FCA3C 004FCA3C 300022AD */   sw        $2, 0x30($9)
  .L004FCA40:
    /* 3FCA40 004FCA40 300028AD */  sw         $8, 0x30($9)
    /* 3FCA44 004FCA44 2D40E000 */  daddu      $8, $7, $0
  .L004FCA48:
    /* 3FCA48 004FCA48 00000782 */  lb         $7, 0x0($16)
    /* 3FCA4C 004FCA4C 01001026 */  addiu      $16, $16, 0x1
    /* 3FCA50 004FCA50 00000292 */  lbu        $2, 0x0($16)
    /* 3FCA54 004FCA54 01001026 */  addiu      $16, $16, 0x1
    /* 3FCA58 004FCA58 003A0700 */  sll        $7, $7, 8
    /* 3FCA5C 004FCA5C 00000392 */  lbu        $3, 0x0($16)
    /* 3FCA60 004FCA60 2538E200 */  or         $7, $7, $2
    /* 3FCA64 004FCA64 01001026 */  addiu      $16, $16, 0x1
    /* 3FCA68 004FCA68 003A0700 */  sll        $7, $7, 8
    /* 3FCA6C 004FCA6C 00000292 */  lbu        $2, 0x0($16)
    /* 3FCA70 004FCA70 2538E300 */  or         $7, $7, $3
    /* 3FCA74 004FCA74 0F00043C */  lui        $4, (0xFFFFF >> 16)
    /* 3FCA78 004FCA78 003A0700 */  sll        $7, $7, 8
    /* 3FCA7C 004FCA7C 01001026 */  addiu      $16, $16, 0x1
    /* 3FCA80 004FCA80 2538E200 */  or         $7, $7, $2
    /* 3FCA84 004FCA84 2D300000 */  daddu      $6, $0, $0
    /* 3FCA88 004FCA88 FFFF8434 */  ori        $4, $4, (0xFFFFF & 0xFFFF)
    /* 3FCA8C 004FCA8C 28000924 */  addiu      $9, $0, 0x28
    /* 3FCA90 004FCA90 14000010 */  b          .L004FCAE4
    /* 3FCA94 004FCA94 01000524 */   addiu     $5, $0, 0x1
  .L004FCA98:
    /* 3FCA98 004FCA98 2000222A */  slti       $2, $17, 0x20
    /* 3FCA9C 004FCA9C 11004014 */  bnez       $2, .L004FCAE4
    /* 3FCAA0 004FCAA0 0100C624 */   addiu     $6, $6, 0x1
    /* 3FCAA4 004FCAA4 E0FF3126 */  addiu      $17, $17, -0x20
    /* 3FCAA8 004FCAA8 04402702 */  sllv       $8, $7, $17
    /* 3FCAAC 004FCAAC 00000782 */  lb         $7, 0x0($16)
    /* 3FCAB0 004FCAB0 01001026 */  addiu      $16, $16, 0x1
    /* 3FCAB4 004FCAB4 00000292 */  lbu        $2, 0x0($16)
    /* 3FCAB8 004FCAB8 01001026 */  addiu      $16, $16, 0x1
    /* 3FCABC 004FCABC 003A0700 */  sll        $7, $7, 8
    /* 3FCAC0 004FCAC0 00000392 */  lbu        $3, 0x0($16)
    /* 3FCAC4 004FCAC4 2538E200 */  or         $7, $7, $2
    /* 3FCAC8 004FCAC8 01001026 */  addiu      $16, $16, 0x1
    /* 3FCACC 004FCACC 003A0700 */  sll        $7, $7, 8
    /* 3FCAD0 004FCAD0 00000292 */  lbu        $2, 0x0($16)
    /* 3FCAD4 004FCAD4 2538E300 */  or         $7, $7, $3
    /* 3FCAD8 004FCAD8 01001026 */  addiu      $16, $16, 0x1
    /* 3FCADC 004FCADC 003A0700 */  sll        $7, $7, 8
    /* 3FCAE0 004FCAE0 2538E200 */  or         $7, $7, $2
  .L004FCAE4:
    /* 3FCAE4 004FCAE4 2A108600 */  slt        $2, $4, $6
    /* 3FCAE8 004FCAE8 0B004054 */  bnel       $2, $0, .L004FCB18
    /* 3FCAEC 004FCAEC 2D204001 */   daddu     $4, $10, $0
    /* 3FCAF0 004FCAF0 0900222A */  slti       $2, $17, 0x9
    /* 3FCAF4 004FCAF4 021A0800 */  srl        $3, $8, 8
    /* 3FCAF8 004FCAF8 04004014 */  bnez       $2, .L004FCB0C
    /* 3FCAFC 004FCAFC 00420800 */   sll       $8, $8, 8
    /* 3FCB00 004FCB00 23103101 */  subu       $2, $9, $17
    /* 3FCB04 004FCB04 06104700 */  srlv       $2, $7, $2
    /* 3FCB08 004FCB08 25186200 */  or         $3, $3, $2
  .L004FCB0C:
    /* 3FCB0C 004FCB0C E2FF6554 */  bnel       $3, $5, .L004FCA98
    /* 3FCB10 004FCB10 08003126 */   addiu     $17, $17, 0x8
    /* 3FCB14 004FCB14 2D204001 */  daddu      $4, $10, $0
  .L004FCB18:
    /* 3FCB18 004FCB18 2D284002 */  daddu      $5, $18, $0
    /* 3FCB1C 004FCB1C D8F2130C */  jal        func_004fcb60
    /* 3FCB20 004FCB20 0400C624 */   addiu     $6, $6, 0x4
    /* 3FCB24 004FCB24 23181202 */  subu       $3, $16, $18
    /* 3FCB28 004FCB28 C0180300 */  sll        $3, $3, 3
    /* 3FCB2C 004FCB2C 1800BFDF */  ld         $31, 0x18($29)
    /* 3FCB30 004FCB30 21182302 */  addu       $3, $17, $3
    /* 3FCB34 004FCB34 0800B1DF */  ld         $17, 0x8($29)
    /* 3FCB38 004FCB38 C7FF6224 */  addiu      $2, $3, -0x39
    /* 3FCB3C 004FCB3C CEFF6324 */  addiu      $3, $3, -0x32
    /* 3FCB40 004FCB40 00004428 */  slti       $4, $2, 0x0
    /* 3FCB44 004FCB44 0000B0DF */  ld         $16, 0x0($29)
    /* 3FCB48 004FCB48 0B106400 */  movn       $2, $3, $4
    /* 3FCB4C 004FCB4C C3100200 */  sra        $2, $2, 3
    /* 3FCB50 004FCB50 21104202 */  addu       $2, $18, $2
    /* 3FCB54 004FCB54 1000B2DF */  ld         $18, 0x10($29)
    /* 3FCB58 004FCB58 0800E003 */  jr         $31
    /* 3FCB5C 004FCB5C 2000BD27 */   addiu     $29, $29, 0x20
.size func_004fc948, 0x218
