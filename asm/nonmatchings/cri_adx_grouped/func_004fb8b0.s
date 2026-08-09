.section .text
.set noat
.set noreorder
glabel func_004fb8b0
    /* 3FB8B0 004FB8B0 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 3FB8B4 004FB8B4 0000B0FF */  sd         $16, 0x0($29)
    /* 3FB8B8 004FB8B8 60019024 */  addiu      $16, $4, 0x160
    /* 3FB8BC 004FB8BC 0800B1FF */  sd         $17, 0x8($29)
    /* 3FB8C0 004FB8C0 2D88A000 */  daddu      $17, $5, $0
    /* 3FB8C4 004FB8C4 1000B2FF */  sd         $18, 0x10($29)
    /* 3FB8C8 004FB8C8 2D90C000 */  daddu      $18, $6, $0
    /* 3FB8CC 004FB8CC 1800B3FF */  sd         $19, 0x18($29)
    /* 3FB8D0 004FB8D0 2000BFFF */  sd         $31, 0x20($29)
    /* 3FB8D4 004FB8D4 1E04140C */  jal        func_00501078
    /* 3FB8D8 004FB8D8 2D98E000 */   daddu     $19, $7, $0
    /* 3FB8DC 004FB8DC 03FF053C */  lui        $5, (0xFF03020F >> 16)
    /* 3FB8E0 004FB8E0 2D200000 */  daddu      $4, $0, $0
    /* 3FB8E4 004FB8E4 08004010 */  beqz       $2, .L004FB908
    /* 3FB8E8 004FB8E8 0F02A534 */   ori       $5, $5, (0xFF03020F & 0xFFFF)
    /* 3FB8EC 004FB8EC 0000B0DF */  ld         $16, 0x0($29)
    /* 3FB8F0 004FB8F0 0800B1DF */  ld         $17, 0x8($29)
    /* 3FB8F4 004FB8F4 1000B2DF */  ld         $18, 0x10($29)
    /* 3FB8F8 004FB8F8 1800B3DF */  ld         $19, 0x18($29)
    /* 3FB8FC 004FB8FC 2000BFDF */  ld         $31, 0x20($29)
    /* 3FB900 004FB900 82ED1308 */  j          func_004fb608
    /* 3FB904 004FB904 3000BD27 */   addiu     $29, $29, 0x30
  .L004FB908:
    /* 3FB908 004FB908 D802028E */  lw         $2, 0x2D8($16)
    /* 3FB90C 004FB90C 2000BFDF */  ld         $31, 0x20($29)
    /* 3FB910 004FB910 C0120200 */  sll        $2, $2, 11
    /* 3FB914 004FB914 000022AE */  sw         $2, 0x0($17)
    /* 3FB918 004FB918 FFFF0224 */  addiu      $2, $0, -0x1
    /* 3FB91C 004FB91C 0800B1DF */  ld         $17, 0x8($29)
    /* 3FB920 004FB920 E400038E */  lw         $3, 0xE4($16)
    /* 3FB924 004FB924 0000B0DF */  ld         $16, 0x0($29)
    /* 3FB928 004FB928 000043AE */  sw         $3, 0x0($18)
    /* 3FB92C 004FB92C 000062AE */  sw         $2, 0x0($19)
    /* 3FB930 004FB930 1000B2DF */  ld         $18, 0x10($29)
    /* 3FB934 004FB934 1800B3DF */  ld         $19, 0x18($29)
    /* 3FB938 004FB938 0800E003 */  jr         $31
    /* 3FB93C 004FB93C 3000BD27 */   addiu     $29, $29, 0x30
.size func_004fb8b0, 0x90
