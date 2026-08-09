.section .text
.set noat
.set noreorder
glabel func_004dd718
    /* 3DD718 004DD718 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3DD71C 004DD71C 7300033C */  lui        $3, %hi(D_00729990)
    /* 3DD720 004DD720 0000BFFF */  sd         $31, 0x0($29)
    /* 3DD724 004DD724 90996324 */  addiu      $3, $3, %lo(D_00729990)
    /* 3DD728 004DD728 0000628C */  lw         $2, 0x0($3)
    /* 3DD72C 004DD72C FFFF4224 */  addiu      $2, $2, -0x1
    /* 3DD730 004DD730 09004014 */  bnez       $2, .L004DD758
    /* 3DD734 004DD734 000062AC */   sw        $2, 0x0($3)
    /* 3DD738 004DD738 7300043C */  lui        $4, %hi(D_00729998)
    /* 3DD73C 004DD73C 0000BFDF */  ld         $31, 0x0($29)
    /* 3DD740 004DD740 2D280000 */  daddu      $5, $0, $0
    /* 3DD744 004DD744 98998424 */  addiu      $4, $4, %lo(D_00729998)
    /* 3DD748 004DD748 40000624 */  addiu      $6, $0, 0x40
    /* 3DD74C 004DD74C 72FE1008 */  j          func_0043f9c8
    /* 3DD750 004DD750 1000BD27 */   addiu     $29, $29, 0x10
    /* 3DD754 004DD754 00000000 */  nop
  .L004DD758:
    /* 3DD758 004DD758 0000BFDF */  ld         $31, 0x0($29)
    /* 3DD75C 004DD75C 0800E003 */  jr         $31
    /* 3DD760 004DD760 1000BD27 */   addiu     $29, $29, 0x10
    /* 3DD764 004DD764 00000000 */  nop
.size func_004dd718, 0x50
