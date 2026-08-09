.section .text
.set noat
.set noreorder
glabel func_004decb8
    /* 3DECB8 004DECB8 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3DECBC 004DECBC 0000B0FF */  sd         $16, 0x0($29)
    /* 3DECC0 004DECC0 2D808000 */  daddu      $16, $4, $0
    /* 3DECC4 004DECC4 0800B1FF */  sd         $17, 0x8($29)
    /* 3DECC8 004DECC8 2D88A000 */  daddu      $17, $5, $0
    /* 3DECCC 004DECCC 1000B2FF */  sd         $18, 0x10($29)
    /* 3DECD0 004DECD0 2D90C000 */  daddu      $18, $6, $0
    /* 3DECD4 004DECD4 03000012 */  beqz       $16, .L004DECE4
    /* 3DECD8 004DECD8 1800BFFF */   sd        $31, 0x18($29)
    /* 3DECDC 004DECDC 0A002016 */  bnez       $17, .L004DED08
    /* 3DECE0 004DECE0 00000000 */   nop
  .L004DECE4:
    /* 3DECE4 004DECE4 7600043C */  lui        $4, %hi(D_00759768)
    /* 3DECE8 004DECE8 0000B0DF */  ld         $16, 0x0($29)
    /* 3DECEC 004DECEC 0800B1DF */  ld         $17, 0x8($29)
    /* 3DECF0 004DECF0 68978424 */  addiu      $4, $4, %lo(D_00759768)
    /* 3DECF4 004DECF4 1000B2DF */  ld         $18, 0x10($29)
    /* 3DECF8 004DECF8 1800BFDF */  ld         $31, 0x18($29)
    /* 3DECFC 004DECFC B0781308 */  j          func_004de2c0
    /* 3DED00 004DED00 2000BD27 */   addiu     $29, $29, 0x20
    /* 3DED04 004DED04 00000000 */  nop
  .L004DED08:
    /* 3DED08 004DED08 587B130C */  jal        func_004ded60
    /* 3DED0C 004DED0C 00000000 */   nop
    /* 3DED10 004DED10 E080130C */  jal        func_004e0380
    /* 3DED14 004DED14 00000000 */   nop
    /* 3DED18 004DED18 2D202002 */  daddu      $4, $17, $0
    /* 3DED1C 004DED1C 80B5130C */  jal        func_004ed600
    /* 3DED20 004DED20 2D284002 */   daddu     $5, $18, $0
    /* 3DED24 004DED24 0400048E */  lw         $4, 0x4($16)
    /* 3DED28 004DED28 900002AE */  sw         $2, 0x90($16)
    /* 3DED2C 004DED2C 7681130C */  jal        func_004e05d8
    /* 3DED30 004DED30 2D284000 */   daddu     $5, $2, $0
    /* 3DED34 004DED34 02000224 */  addiu      $2, $0, 0x2
    /* 3DED38 004DED38 01000324 */  addiu      $3, $0, 0x1
    /* 3DED3C 004DED3C DC0102AE */  sw         $2, 0x1DC($16)
    /* 3DED40 004DED40 010003A2 */  sb         $3, 0x1($16)
    /* 3DED44 004DED44 0800B1DF */  ld         $17, 0x8($29)
    /* 3DED48 004DED48 0000B0DF */  ld         $16, 0x0($29)
    /* 3DED4C 004DED4C 1000B2DF */  ld         $18, 0x10($29)
    /* 3DED50 004DED50 1800BFDF */  ld         $31, 0x18($29)
    /* 3DED54 004DED54 E6801308 */  j          func_004e0398
    /* 3DED58 004DED58 2000BD27 */   addiu     $29, $29, 0x20
    /* 3DED5C 004DED5C 00000000 */  nop
.size func_004decb8, 0xa8
