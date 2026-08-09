.section .text
.set noat
.set noreorder
glabel func_003e5a30
    /* 2E5A30 003E5A30 B0FFBD27 */  addiu      $29, $29, -0x50
    /* 2E5A34 003E5A34 04000524 */  addiu      $5, $0, 0x4
    /* 2E5A38 003E5A38 4000BFFF */  sd         $31, 0x40($29)
    /* 2E5A3C 003E5A3C 3000B37F */  sq         $19, 0x30($29)
    /* 2E5A40 003E5A40 2D988000 */  daddu      $19, $4, $0
    /* 2E5A44 003E5A44 2000B27F */  sq         $18, 0x20($29)
    /* 2E5A48 003E5A48 0400848C */  lw         $4, 0x4($4)
    /* 2E5A4C 003E5A4C 1000B17F */  sq         $17, 0x10($29)
    /* 2E5A50 003E5A50 0000B07F */  sq         $16, 0x0($29)
    /* 2E5A54 003E5A54 2D880000 */  daddu      $17, $0, $0
    /* 2E5A58 003E5A58 C0180400 */  sll        $3, $4, 3
    /* 2E5A5C 003E5A5C 2A100400 */  slt        $2, $0, $4
    /* 2E5A60 003E5A60 23186400 */  subu       $3, $3, $4
    /* 2E5A64 003E5A64 C0180300 */  sll        $3, $3, 3
    /* 2E5A68 003E5A68 2118A300 */  addu       $3, $5, $3
    /* 2E5A6C 003E5A6C 03004014 */  bnez       $2, .L003E5A7C
    /* 2E5A70 003E5A70 0C007224 */   addiu     $18, $3, 0xC
  .L003E5A74:
    /* 2E5A74 003E5A74 11000010 */  b          .L003E5ABC
    /* 2E5A78 003E5A78 2D104002 */   daddu     $2, $18, $0
  .L003E5A7C:
    /* 2E5A7C 003E5A7C 2D800000 */  daddu      $16, $0, $0
  .L003E5A80:
    /* 2E5A80 003E5A80 0000628E */  lw         $2, 0x0($19)
    /* 2E5A84 003E5A84 7100043C */  lui        $4, %hi(D_0070B7A0)
    /* 2E5A88 003E5A88 21105000 */  addu       $2, $2, $16
    /* 2E5A8C 003E5A8C 0000458C */  lw         $5, 0x0($2)
    /* 2E5A90 003E5A90 DC8C0F0C */  jal        func_003e3370
    /* 2E5A94 003E5A94 A0B78424 */   addiu     $4, $4, %lo(D_0070B7A0)
    /* 2E5A98 003E5A98 0C004224 */  addiu      $2, $2, 0xC
    /* 2E5A9C 003E5A9C 01003126 */  addiu      $17, $17, 0x1
    /* 2E5AA0 003E5AA0 21904202 */  addu       $18, $18, $2
    /* 2E5AA4 003E5AA4 0400628E */  lw         $2, 0x4($19)
    /* 2E5AA8 003E5AA8 2A102202 */  slt        $2, $17, $2
    /* 2E5AAC 003E5AAC F4FF4014 */  bnez       $2, .L003E5A80
    /* 2E5AB0 003E5AB0 04001026 */   addiu     $16, $16, 0x4
    /* 2E5AB4 003E5AB4 EFFF0010 */  b          .L003E5A74
    /* 2E5AB8 003E5AB8 00000000 */   nop
  .L003E5ABC:
    /* 2E5ABC 003E5ABC 4000BFDF */  ld         $31, 0x40($29)
    /* 2E5AC0 003E5AC0 3000B37B */  lq         $19, 0x30($29)
    /* 2E5AC4 003E5AC4 2000B27B */  lq         $18, 0x20($29)
    /* 2E5AC8 003E5AC8 1000B17B */  lq         $17, 0x10($29)
    /* 2E5ACC 003E5ACC 0000B07B */  lq         $16, 0x0($29)
    /* 2E5AD0 003E5AD0 0800E003 */  jr         $31
    /* 2E5AD4 003E5AD4 5000BD27 */   addiu     $29, $29, 0x50
    /* 2E5AD8 003E5AD8 00000000 */  nop
    /* 2E5ADC 003E5ADC 00000000 */  nop
.size func_003e5a30, 0xb0
