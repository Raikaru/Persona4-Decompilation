.section .text
.set noat
.set noreorder
glabel func_004ed5b0
    /* 3ED5B0 004ED5B0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3ED5B4 004ED5B4 7400033C */  lui        $3, %hi(D_0073DB00)
    /* 3ED5B8 004ED5B8 0000BFFF */  sd         $31, 0x0($29)
    /* 3ED5BC 004ED5BC 00DB6324 */  addiu      $3, $3, %lo(D_0073DB00)
    /* 3ED5C0 004ED5C0 0000628C */  lw         $2, 0x0($3)
    /* 3ED5C4 004ED5C4 FFFF4224 */  addiu      $2, $2, -0x1
    /* 3ED5C8 004ED5C8 09004014 */  bnez       $2, .L004ED5F0
    /* 3ED5CC 004ED5CC 000062AC */   sw        $2, 0x0($3)
    /* 3ED5D0 004ED5D0 7400043C */  lui        $4, %hi(D_0073DB08)
    /* 3ED5D4 004ED5D4 0000BFDF */  ld         $31, 0x0($29)
    /* 3ED5D8 004ED5D8 2D280000 */  daddu      $5, $0, $0
    /* 3ED5DC 004ED5DC 08DB8424 */  addiu      $4, $4, %lo(D_0073DB08)
    /* 3ED5E0 004ED5E0 80040624 */  addiu      $6, $0, 0x480
    /* 3ED5E4 004ED5E4 72FE1008 */  j          func_0043f9c8
    /* 3ED5E8 004ED5E8 1000BD27 */   addiu     $29, $29, 0x10
    /* 3ED5EC 004ED5EC 00000000 */  nop
  .L004ED5F0:
    /* 3ED5F0 004ED5F0 0000BFDF */  ld         $31, 0x0($29)
    /* 3ED5F4 004ED5F4 0800E003 */  jr         $31
    /* 3ED5F8 004ED5F8 1000BD27 */   addiu     $29, $29, 0x10
    /* 3ED5FC 004ED5FC 00000000 */  nop
.size func_004ed5b0, 0x50
