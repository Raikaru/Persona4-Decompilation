.section .text
.set noat
.set noreorder
glabel func_004a5a60
    /* 3A5A60 004A5A60 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3A5A64 004A5A64 0000BFFF */  sd         $31, 0x0($29)
    /* 3A5A68 004A5A68 3400838C */  lw         $3, 0x34($4)
    /* 3A5A6C 004A5A6C 0B006018 */  blez       $3, .L004A5A9C
    /* 3A5A70 004A5A70 00000000 */   nop
    /* 3A5A74 004A5A74 3800838C */  lw         $3, 0x38($4)
    /* 3A5A78 004A5A78 C0100300 */  sll        $2, $3, 3
    /* 3A5A7C 004A5A7C 23104300 */  subu       $2, $2, $3
    /* 3A5A80 004A5A80 80180200 */  sll        $3, $2, 2
    /* 3A5A84 004A5A84 7100023C */  lui        $2, %hi(D_00714144)
    /* 3A5A88 004A5A88 44414224 */  addiu      $2, $2, %lo(D_00714144)
    /* 3A5A8C 004A5A8C 21104300 */  addu       $2, $2, $3
    /* 3A5A90 004A5A90 0000428C */  lw         $2, 0x0($2)
    /* 3A5A94 004A5A94 09F84000 */  jalr       $2
    /* 3A5A98 004A5A98 00000000 */   nop
  .L004A5A9C:
    /* 3A5A9C 004A5A9C 0000BFDF */  ld         $31, 0x0($29)
    /* 3A5AA0 004A5AA0 1000BD27 */  addiu      $29, $29, 0x10
    /* 3A5AA4 004A5AA4 0800E003 */  jr         $31
    /* 3A5AA8 004A5AA8 00000000 */   nop
    /* 3A5AAC 004A5AAC 00000000 */  nop
.size func_004a5a60, 0x50
