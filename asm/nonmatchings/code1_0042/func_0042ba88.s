.section .text
.set noat
.set noreorder
glabel func_0042ba88
    /* 32BA88 0042BA88 7500023C */  lui        $2, %hi(D_00754470)
    /* 32BA8C 0042BA8C 7500053C */  lui        $5, %hi(D_00754480)
    /* 32BA90 0042BA90 B0FFBD27 */  addiu      $29, $29, -0x50
    /* 32BA94 0042BA94 01000324 */  addiu      $3, $0, 0x1
    /* 32BA98 0042BA98 70444224 */  addiu      $2, $2, %lo(D_00754470)
    /* 32BA9C 0042BA9C 8044A524 */  addiu      $5, $5, %lo(D_00754480)
    /* 32BAA0 0042BAA0 4000BFFF */  sd         $31, 0x40($29)
    /* 32BAA4 0042BAA4 2D20A003 */  daddu      $4, $29, $0
    /* 32BAA8 0042BAA8 1400A2AF */  sw         $2, 0x14($29)
    /* 32BAAC 0042BAAC 2800A3AF */  sw         $3, 0x28($29)
    /* 32BAB0 0042BAB0 3400A5AF */  sw         $5, 0x34($29)
    /* 32BAB4 0042BAB4 0400A3AF */  sw         $3, 0x4($29)
    /* 32BAB8 0042BAB8 0800A3AF */  sw         $3, 0x8($29)
    /* 32BABC 0042BABC F885100C */  jal        func_004217e0
    /* 32BAC0 0042BAC0 2400A3AF */   sw        $3, 0x24($29)
    /* 32BAC4 0042BAC4 7100033C */  lui        $3, %hi(D_0070CD10)
    /* 32BAC8 0042BAC8 2000A427 */  addiu      $4, $29, 0x20
    /* 32BACC 0042BACC F885100C */  jal        func_004217e0
    /* 32BAD0 0042BAD0 10CD62AC */   sw        $2, %lo(D_0070CD10)($3)
    /* 32BAD4 0042BAD4 7100033C */  lui        $3, %hi(D_0070CD14)
    /* 32BAD8 0042BAD8 4000BFDF */  ld         $31, 0x40($29)
    /* 32BADC 0042BADC 14CD62AC */  sw         $2, %lo(D_0070CD14)($3)
    /* 32BAE0 0042BAE0 0800E003 */  jr         $31
    /* 32BAE4 0042BAE4 5000BD27 */   addiu     $29, $29, 0x50
.size func_0042ba88, 0x60
