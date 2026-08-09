.section .text
.set noat
.set noreorder
glabel func_004cafe8
    /* 3CAFE8 004CAFE8 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 3CAFEC 004CAFEC 0800B1FF */  sd         $17, 0x8($29)
    /* 3CAFF0 004CAFF0 2D888000 */  daddu      $17, $4, $0
    /* 3CAFF4 004CAFF4 1000B2FF */  sd         $18, 0x10($29)
    /* 3CAFF8 004CAFF8 2D90A000 */  daddu      $18, $5, $0
    /* 3CAFFC 004CAFFC 1800B3FF */  sd         $19, 0x18($29)
    /* 3CB000 004CB000 2D98C000 */  daddu      $19, $6, $0
    /* 3CB004 004CB004 2000B4FF */  sd         $20, 0x20($29)
    /* 3CB008 004CB008 2DA0E000 */  daddu      $20, $7, $0
    /* 3CB00C 004CB00C 0000B0FF */  sd         $16, 0x0($29)
    /* 3CB010 004CB010 03002012 */  beqz       $17, .L004CB020
    /* 3CB014 004CB014 2800BFFF */   sd        $31, 0x28($29)
    /* 3CB018 004CB018 0B004056 */  bnel       $18, $0, .L004CB048
    /* 3CB01C 004CB01C 9400308E */   lw        $16, 0x94($17)
  .L004CB020:
    /* 3CB020 004CB020 7600043C */  lui        $4, %hi(D_00758818)
    /* 3CB024 004CB024 0000B0DF */  ld         $16, 0x0($29)
    /* 3CB028 004CB028 0800B1DF */  ld         $17, 0x8($29)
    /* 3CB02C 004CB02C 18888424 */  addiu      $4, $4, %lo(D_00758818)
    /* 3CB030 004CB030 1000B2DF */  ld         $18, 0x10($29)
    /* 3CB034 004CB034 1800B3DF */  ld         $19, 0x18($29)
    /* 3CB038 004CB038 2000B4DF */  ld         $20, 0x20($29)
    /* 3CB03C 004CB03C 2800BFDF */  ld         $31, 0x28($29)
    /* 3CB040 004CB040 A61A1308 */  j          func_004c6a98
    /* 3CB044 004CB044 3000BD27 */   addiu     $29, $29, 0x30
  .L004CB048:
    /* 3CB048 004CB048 BEA4130C */  jal        func_004e92f8
    /* 3CB04C 004CB04C 2D200002 */   daddu     $4, $16, $0
    /* 3CB050 004CB050 2D202002 */  daddu      $4, $17, $0
    /* 3CB054 004CB054 2D306002 */  daddu      $6, $19, $0
    /* 3CB058 004CB058 2D388002 */  daddu      $7, $20, $0
    /* 3CB05C 004CB05C 142B130C */  jal        func_004cac50
    /* 3CB060 004CB060 2D284002 */   daddu     $5, $18, $0
    /* 3CB064 004CB064 2D200002 */  daddu      $4, $16, $0
    /* 3CB068 004CB068 FAA5130C */  jal        func_004e97e8
    /* 3CB06C 004CB06C 01000524 */   addiu     $5, $0, 0x1
    /* 3CB070 004CB070 2D202002 */  daddu      $4, $17, $0
    /* 3CB074 004CB074 0000B0DF */  ld         $16, 0x0($29)
    /* 3CB078 004CB078 0800B1DF */  ld         $17, 0x8($29)
    /* 3CB07C 004CB07C 1000B2DF */  ld         $18, 0x10($29)
    /* 3CB080 004CB080 1800B3DF */  ld         $19, 0x18($29)
    /* 3CB084 004CB084 2000B4DF */  ld         $20, 0x20($29)
    /* 3CB088 004CB088 2800BFDF */  ld         $31, 0x28($29)
    /* 3CB08C 004CB08C 822B1308 */  j          func_004cae08
    /* 3CB090 004CB090 3000BD27 */   addiu     $29, $29, 0x30
    /* 3CB094 004CB094 00000000 */  nop
.size func_004cafe8, 0xb0
