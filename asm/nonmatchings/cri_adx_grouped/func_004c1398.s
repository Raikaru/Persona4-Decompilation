.section .text
.set noat
.set noreorder
glabel func_004c1398
    /* 3C1398 004C1398 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3C139C 004C139C 7100033C */  lui        $3, %hi(D_007146F0)
    /* 3C13A0 004C13A0 0000BFFF */  sd         $31, 0x0($29)
    /* 3C13A4 004C13A4 F0466324 */  addiu      $3, $3, %lo(D_007146F0)
    /* 3C13A8 004C13A8 0000628C */  lw         $2, 0x0($3)
    /* 3C13AC 004C13AC FFFF4224 */  addiu      $2, $2, -0x1
    /* 3C13B0 004C13B0 09004014 */  bnez       $2, .L004C13D8
    /* 3C13B4 004C13B4 000062AC */   sw        $2, 0x0($3)
    /* 3C13B8 004C13B8 7100043C */  lui        $4, %hi(D_007146F8)
    /* 3C13BC 004C13BC 0000BFDF */  ld         $31, 0x0($29)
    /* 3C13C0 004C13C0 2D280000 */  daddu      $5, $0, $0
    /* 3C13C4 004C13C4 F8468424 */  addiu      $4, $4, %lo(D_007146F8)
    /* 3C13C8 004C13C8 00030624 */  addiu      $6, $0, 0x300
    /* 3C13CC 004C13CC 72FE1008 */  j          func_0043f9c8
    /* 3C13D0 004C13D0 1000BD27 */   addiu     $29, $29, 0x10
    /* 3C13D4 004C13D4 00000000 */  nop
  .L004C13D8:
    /* 3C13D8 004C13D8 0000BFDF */  ld         $31, 0x0($29)
    /* 3C13DC 004C13DC 0800E003 */  jr         $31
    /* 3C13E0 004C13E0 1000BD27 */   addiu     $29, $29, 0x10
    /* 3C13E4 004C13E4 00000000 */  nop
.size func_004c1398, 0x50
