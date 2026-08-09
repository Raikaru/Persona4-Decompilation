.section .text
.set noat
.set noreorder
glabel func_0052a3b0
    /* 42A3B0 0052A3B0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 42A3B4 0052A3B4 0000B0FF */  sd         $16, 0x0($29)
    /* 42A3B8 0052A3B8 0800BFFF */  sd         $31, 0x8($29)
    /* 42A3BC 0052A3BC FCA8140C */  jal        func_0052a3f0
    /* 42A3C0 0052A3C0 2D80A000 */   daddu     $16, $5, $0
    /* 42A3C4 0052A3C4 E0000324 */  addiu      $3, $0, 0xE0
    /* 42A3C8 0052A3C8 05004314 */  bne        $2, $3, .L0052A3E0
    /* 42A3CC 0052A3CC 2D100000 */   daddu     $2, $0, $0
    /* 42A3D0 0052A3D0 20000392 */  lbu        $3, 0x20($16)
    /* 42A3D4 0052A3D4 2B100300 */  sltu       $2, $0, $3
    /* 42A3D8 0052A3D8 0200632C */  sltiu      $3, $3, 0x2
    /* 42A3DC 0052A3DC 0A100300 */  movz       $2, $0, $3
  .L0052A3E0:
    /* 42A3E0 0052A3E0 0000B0DF */  ld         $16, 0x0($29)
    /* 42A3E4 0052A3E4 0800BFDF */  ld         $31, 0x8($29)
    /* 42A3E8 0052A3E8 0800E003 */  jr         $31
    /* 42A3EC 0052A3EC 1000BD27 */   addiu     $29, $29, 0x10
.size func_0052a3b0, 0x40
