.section .text
.set noat
.set noreorder
glabel func_004fb940
    /* 3FB940 004FB940 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3FB944 004FB944 0000B0FF */  sd         $16, 0x0($29)
    /* 3FB948 004FB948 60019024 */  addiu      $16, $4, 0x160
    /* 3FB94C 004FB94C 0800B1FF */  sd         $17, 0x8($29)
    /* 3FB950 004FB950 2D88A000 */  daddu      $17, $5, $0
    /* 3FB954 004FB954 1000B2FF */  sd         $18, 0x10($29)
    /* 3FB958 004FB958 1800BFFF */  sd         $31, 0x18($29)
    /* 3FB95C 004FB95C 1E04140C */  jal        func_00501078
    /* 3FB960 004FB960 2D90C000 */   daddu     $18, $6, $0
    /* 3FB964 004FB964 03FF053C */  lui        $5, (0xFF03020E >> 16)
    /* 3FB968 004FB968 2D200000 */  daddu      $4, $0, $0
    /* 3FB96C 004FB96C 08004010 */  beqz       $2, .L004FB990
    /* 3FB970 004FB970 0E02A534 */   ori       $5, $5, (0xFF03020E & 0xFFFF)
    /* 3FB974 004FB974 0000B0DF */  ld         $16, 0x0($29)
    /* 3FB978 004FB978 0800B1DF */  ld         $17, 0x8($29)
    /* 3FB97C 004FB97C 1000B2DF */  ld         $18, 0x10($29)
    /* 3FB980 004FB980 1800BFDF */  ld         $31, 0x18($29)
    /* 3FB984 004FB984 82ED1308 */  j          func_004fb608
    /* 3FB988 004FB988 2000BD27 */   addiu     $29, $29, 0x20
    /* 3FB98C 004FB98C 00000000 */  nop
  .L004FB990:
    /* 3FB990 004FB990 D000028E */  lw         $2, 0xD0($16)
    /* 3FB994 004FB994 1800BFDF */  ld         $31, 0x18($29)
    /* 3FB998 004FB998 000022AE */  sw         $2, 0x0($17)
    /* 3FB99C 004FB99C 0800B1DF */  ld         $17, 0x8($29)
    /* 3FB9A0 004FB9A0 D400038E */  lw         $3, 0xD4($16)
    /* 3FB9A4 004FB9A4 0000B0DF */  ld         $16, 0x0($29)
    /* 3FB9A8 004FB9A8 000043AE */  sw         $3, 0x0($18)
    /* 3FB9AC 004FB9AC 1000B2DF */  ld         $18, 0x10($29)
    /* 3FB9B0 004FB9B0 0800E003 */  jr         $31
    /* 3FB9B4 004FB9B4 2000BD27 */   addiu     $29, $29, 0x20
.size func_004fb940, 0x78
