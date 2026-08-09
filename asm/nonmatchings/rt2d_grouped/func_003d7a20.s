.section .text
.set noat
.set noreorder
glabel func_003d7a20
    /* 2D7A20 003D7A20 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 2D7A24 003D7A24 0300023C */  lui        $2, (0x30135 >> 16)
    /* 2D7A28 003D7A28 2000BFFF */  sd         $31, 0x20($29)
    /* 2D7A2C 003D7A2C 35014534 */  ori        $5, $2, (0x30135 & 0xFFFF)
    /* 2D7A30 003D7A30 1000B17F */  sq         $17, 0x10($29)
    /* 2D7A34 003D7A34 8800023C */  lui        $2, %hi(D_008873F8)
    /* 2D7A38 003D7A38 0000B07F */  sq         $16, 0x0($29)
    /* 2D7A3C 003D7A3C 2D888000 */  daddu      $17, $4, $0
    /* 2D7A40 003D7A40 F873428C */  lw         $2, %lo(D_008873F8)($2)
    /* 2D7A44 003D7A44 09F84000 */  jalr       $2
    /* 2D7A48 003D7A48 48B7848F */   lw        $4, -0x48B8($28)
    /* 2D7A4C 003D7A4C 2D804000 */  daddu      $16, $2, $0
    /* 2D7A50 003D7A50 09000012 */  beqz       $16, .L003D7A78
    /* 2D7A54 003D7A54 00000000 */   nop
    /* 2D7A58 003D7A58 2D202002 */  daddu      $4, $17, $0
    /* 2D7A5C 003D7A5C 2D280002 */  daddu      $5, $16, $0
    /* 2D7A60 003D7A60 448A0F0C */  jal        func_003e2910
    /* 2D7A64 003D7A64 20000624 */   addiu     $6, $0, 0x20
    /* 2D7A68 003D7A68 05004014 */  bnez       $2, .L003D7A80
    /* 2D7A6C 003D7A6C 00000000 */   nop
    /* 2D7A70 003D7A70 0E000010 */  b          .L003D7AAC
    /* 2D7A74 003D7A74 2D100000 */   daddu     $2, $0, $0
  .L003D7A78:
    /* 2D7A78 003D7A78 0C000010 */  b          .L003D7AAC
    /* 2D7A7C 003D7A7C 2D100000 */   daddu     $2, $0, $0
  .L003D7A80:
    /* 2D7A80 003D7A80 2D202002 */  daddu      $4, $17, $0
    /* 2D7A84 003D7A84 20000526 */  addiu      $5, $16, 0x20
    /* 2D7A88 003D7A88 D87C0F0C */  jal        func_003df360
    /* 2D7A8C 003D7A8C 20000624 */   addiu     $6, $0, 0x20
    /* 2D7A90 003D7A90 03004014 */  bnez       $2, .L003D7AA0
    /* 2D7A94 003D7A94 00000000 */   nop
    /* 2D7A98 003D7A98 04000010 */  b          .L003D7AAC
    /* 2D7A9C 003D7A9C 2D100000 */   daddu     $2, $0, $0
  .L003D7AA0:
    /* 2D7AA0 003D7AA0 01000324 */  addiu      $3, $0, 0x1
    /* 2D7AA4 003D7AA4 2D100002 */  daddu      $2, $16, $0
    /* 2D7AA8 003D7AA8 400003AE */  sw         $3, 0x40($16)
  .L003D7AAC:
    /* 2D7AAC 003D7AAC 2000BFDF */  ld         $31, 0x20($29)
    /* 2D7AB0 003D7AB0 1000B17B */  lq         $17, 0x10($29)
    /* 2D7AB4 003D7AB4 0000B07B */  lq         $16, 0x0($29)
    /* 2D7AB8 003D7AB8 0800E003 */  jr         $31
    /* 2D7ABC 003D7ABC 3000BD27 */   addiu     $29, $29, 0x30
.size func_003d7a20, 0xa0
