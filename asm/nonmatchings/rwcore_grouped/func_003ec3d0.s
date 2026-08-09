.section .text
.set noat
.set noreorder
glabel func_003ec3d0
    /* 2EC3D0 003EC3D0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2EC3D4 003EC3D4 2D108000 */  daddu      $2, $4, $0
    /* 2EC3D8 003EC3D8 2D30A000 */  daddu      $6, $5, $0
    /* 2EC3DC 003EC3DC 0000BFFF */  sd         $31, 0x0($29)
    /* 2EC3E0 003EC3E0 2D284000 */  daddu      $5, $2, $0
    /* 2EC3E4 003EC3E4 8800023C */  lui        $2, %hi(D_00887384)
    /* 2EC3E8 003EC3E8 8473428C */  lw         $2, %lo(D_00887384)($2)
    /* 2EC3EC 003EC3EC 09F84000 */  jalr       $2
    /* 2EC3F0 003EC3F0 1C00A427 */   addiu     $4, $29, 0x1C
    /* 2EC3F4 003EC3F4 03004010 */  beqz       $2, .L003EC404
    /* 2EC3F8 003EC3F8 00000000 */   nop
    /* 2EC3FC 003EC3FC 02000010 */  b          .L003EC408
    /* 2EC400 003EC400 1C00A28F */   lw        $2, 0x1C($29)
  .L003EC404:
    /* 2EC404 003EC404 2D100000 */  daddu      $2, $0, $0
  .L003EC408:
    /* 2EC408 003EC408 0000BFDF */  ld         $31, 0x0($29)
    /* 2EC40C 003EC40C 0800E003 */  jr         $31
    /* 2EC410 003EC410 2000BD27 */   addiu     $29, $29, 0x20
    /* 2EC414 003EC414 00000000 */  nop
    /* 2EC418 003EC418 00000000 */  nop
    /* 2EC41C 003EC41C 00000000 */  nop
.size func_003ec3d0, 0x50
