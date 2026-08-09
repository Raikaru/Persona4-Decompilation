.section .text
.set noat
.set noreorder
glabel func_004fb850
    /* 3FB850 004FB850 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3FB854 004FB854 0000B0FF */  sd         $16, 0x0($29)
    /* 3FB858 004FB858 60019024 */  addiu      $16, $4, 0x160
    /* 3FB85C 004FB85C 0800B1FF */  sd         $17, 0x8($29)
    /* 3FB860 004FB860 1000BFFF */  sd         $31, 0x10($29)
    /* 3FB864 004FB864 1E04140C */  jal        func_00501078
    /* 3FB868 004FB868 2D88A000 */   daddu     $17, $5, $0
    /* 3FB86C 004FB86C 03FF053C */  lui        $5, (0xFF03020D >> 16)
    /* 3FB870 004FB870 07004010 */  beqz       $2, .L004FB890
    /* 3FB874 004FB874 2D200000 */   daddu     $4, $0, $0
    /* 3FB878 004FB878 0000B0DF */  ld         $16, 0x0($29)
    /* 3FB87C 004FB87C 0D02A534 */  ori        $5, $5, (0xFF03020D & 0xFFFF)
    /* 3FB880 004FB880 0800B1DF */  ld         $17, 0x8($29)
    /* 3FB884 004FB884 1000BFDF */  ld         $31, 0x10($29)
    /* 3FB888 004FB888 82ED1308 */  j          func_004fb608
    /* 3FB88C 004FB88C 2000BD27 */   addiu     $29, $29, 0x20
  .L004FB890:
    /* 3FB890 004FB890 D402028E */  lw         $2, 0x2D4($16)
    /* 3FB894 004FB894 1000BFDF */  ld         $31, 0x10($29)
    /* 3FB898 004FB898 000022AE */  sw         $2, 0x0($17)
    /* 3FB89C 004FB89C 0000B0DF */  ld         $16, 0x0($29)
    /* 3FB8A0 004FB8A0 0800B1DF */  ld         $17, 0x8($29)
    /* 3FB8A4 004FB8A4 0800E003 */  jr         $31
    /* 3FB8A8 004FB8A8 2000BD27 */   addiu     $29, $29, 0x20
    /* 3FB8AC 004FB8AC 00000000 */  nop
.size func_004fb850, 0x60
