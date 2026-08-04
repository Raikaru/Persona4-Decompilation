.section .text
.set noat
.set noreorder
glabel func_0018bad0
    /* 8BAD0 0018BAD0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 8BAD4 0018BAD4 1000BFFF */  sd         $31, 0x10($29)
    /* 8BAD8 0018BAD8 0000B07F */  sq         $16, 0x0($29)
    /* 8BADC 0018BADC 2D808000 */  daddu      $16, $4, $0
    /* 8BAE0 0018BAE0 3800828C */  lw         $2, 0x38($4)
    /* 8BAE4 0018BAE4 1400448C */  lw         $4, 0x14($2)
    /* 8BAE8 0018BAE8 03008010 */  beqz       $4, .L0018BAF8
    /* 8BAEC 0018BAEC 00000000 */   nop
    /* 8BAF0 0018BAF0 D0830F0C */  jal        func_003e0f40
    /* 8BAF4 0018BAF4 00000000 */   nop
  .L0018BAF8:
    /* 8BAF8 0018BAF8 3800048E */  lw         $4, 0x38($16)
    /* 8BAFC 0018BAFC 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 8BB00 0018BB00 EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 8BB04 0018BB04 09F84000 */  jalr       $2
    /* 8BB08 0018BB08 00000000 */   nop
    /* 8BB0C 0018BB0C 1000BFDF */  ld         $31, 0x10($29)
    /* 8BB10 0018BB10 0000B07B */  lq         $16, 0x0($29)
    /* 8BB14 0018BB14 2000BD27 */  addiu      $29, $29, 0x20
    /* 8BB18 0018BB18 0800E003 */  jr         $31
    /* 8BB1C 0018BB1C 00000000 */   nop
.size func_0018bad0, 0x50
