.section .text
.set noat
.set noreorder
glabel func_004fbad0
    /* 3FBAD0 004FBAD0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3FBAD4 004FBAD4 0000B0FF */  sd         $16, 0x0($29)
    /* 3FBAD8 004FBAD8 2D80A000 */  daddu      $16, $5, $0
    /* 3FBADC 004FBADC 0800B1FF */  sd         $17, 0x8($29)
    /* 3FBAE0 004FBAE0 1000BFFF */  sd         $31, 0x10($29)
    /* 3FBAE4 004FBAE4 1E04140C */  jal        func_00501078
    /* 3FBAE8 004FBAE8 2D888000 */   daddu     $17, $4, $0
    /* 3FBAEC 004FBAEC 2D200000 */  daddu      $4, $0, $0
    /* 3FBAF0 004FBAF0 09004010 */  beqz       $2, .L004FBB18
    /* 3FBAF4 004FBAF4 2D280002 */   daddu     $5, $16, $0
    /* 3FBAF8 004FBAF8 03FF053C */  lui        $5, (0xFF03020C >> 16)
    /* 3FBAFC 004FBAFC 0000B0DF */  ld         $16, 0x0($29)
    /* 3FBB00 004FBB00 0800B1DF */  ld         $17, 0x8($29)
    /* 3FBB04 004FBB04 0C02A534 */  ori        $5, $5, (0xFF03020C & 0xFFFF)
    /* 3FBB08 004FBB08 1000BFDF */  ld         $31, 0x10($29)
    /* 3FBB0C 004FBB0C 82ED1308 */  j          func_004fb608
    /* 3FBB10 004FBB10 2000BD27 */   addiu     $29, $29, 0x20
    /* 3FBB14 004FBB14 00000000 */  nop
  .L004FBB18:
    /* 3FBB18 004FBB18 30EF130C */  jal        func_004fbcc0
    /* 3FBB1C 004FBB1C 2D202002 */   daddu     $4, $17, $0
    /* 3FBB20 004FBB20 2D804000 */  daddu      $16, $2, $0
    /* 3FBB24 004FBB24 03000016 */  bnez       $16, .L004FBB34
    /* 3FBB28 004FBB28 2D202002 */   daddu     $4, $17, $0
    /* 3FBB2C 004FBB2C D4EE130C */  jal        func_004fbb50
    /* 3FBB30 004FBB30 00000000 */   nop
  .L004FBB34:
    /* 3FBB34 004FBB34 2D100002 */  daddu      $2, $16, $0
    /* 3FBB38 004FBB38 0000B0DF */  ld         $16, 0x0($29)
    /* 3FBB3C 004FBB3C 0800B1DF */  ld         $17, 0x8($29)
    /* 3FBB40 004FBB40 1000BFDF */  ld         $31, 0x10($29)
    /* 3FBB44 004FBB44 0800E003 */  jr         $31
    /* 3FBB48 004FBB48 2000BD27 */   addiu     $29, $29, 0x20
    /* 3FBB4C 004FBB4C 00000000 */  nop
.size func_004fbad0, 0x80
