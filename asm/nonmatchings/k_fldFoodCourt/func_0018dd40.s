.section .text
.set noat
.set noreorder
glabel func_0018dd40
    /* 8DD40 0018DD40 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 8DD44 0018DD44 1000BFFF */  sd         $31, 0x10($29)
    /* 8DD48 0018DD48 0000B07F */  sq         $16, 0x0($29)
    /* 8DD4C 0018DD4C 2D808000 */  daddu      $16, $4, $0
    /* 8DD50 0018DD50 5F00043C */  lui        $4, %hi(D_005F5450)
    /* 8DD54 0018DD54 50548424 */  addiu      $4, $4, %lo(D_005F5450)
    /* 8DD58 0018DD58 BF000524 */  addiu      $5, $0, 0xBF
    /* 8DD5C 0018DD5C A43A110C */  jal        func_0044ea90
    /* 8DD60 0018DD60 00000000 */   nop
    /* 8DD64 0018DD64 01000424 */  addiu      $4, $0, 0x1
    /* 8DD68 0018DD68 10000524 */  addiu      $5, $0, 0x10
    /* 8DD6C 0018DD6C 0400063C */  lui        $6, (0x40000 >> 16)
    /* 8DD70 0018DD70 8800023C */  lui        $2, %hi(D_008873F4)
    /* 8DD74 0018DD74 F473428C */  lw         $2, %lo(D_008873F4)($2)
    /* 8DD78 0018DD78 09F84000 */  jalr       $2
    /* 8DD7C 0018DD7C 00000000 */   nop
    /* 8DD80 0018DD80 04004014 */  bnez       $2, .L0018DD94
    /* 8DD84 0018DD84 00000000 */   nop
    /* 8DD88 0018DD88 2D100000 */  daddu      $2, $0, $0
    /* 8DD8C 0018DD8C 0E000010 */  b          .L0018DDC8
    /* 8DD90 0018DD90 00000000 */   nop
  .L0018DD94:
    /* 8DD94 0018DD94 2D200002 */  daddu      $4, $16, $0
    /* 8DD98 0018DD98 5F00053C */  lui        $5, %hi(D_005F54C8)
    /* 8DD9C 0018DD9C C854A524 */  addiu      $5, $5, %lo(D_005F54C8)
    /* 8DDA0 0018DDA0 0F000624 */  addiu      $6, $0, 0xF
    /* 8DDA4 0018DDA4 2D380000 */  daddu      $7, $0, $0
    /* 8DDA8 0018DDA8 2D400000 */  daddu      $8, $0, $0
    /* 8DDAC 0018DDAC 1900093C */  lui        $9, %hi(func_0018d950)
    /* 8DDB0 0018DDB0 50D92925 */  addiu      $9, $9, %lo(func_0018d950)
    /* 8DDB4 0018DDB4 19000A3C */  lui        $10, %hi(func_0018dcd0)
    /* 8DDB8 0018DDB8 D0DC4A25 */  addiu      $10, $10, %lo(func_0018dcd0)
    /* 8DDBC 0018DDBC 2D584000 */  daddu      $11, $2, $0
    /* 8DDC0 0018DDC0 F047110C */  jal        func_00451fc0
    /* 8DDC4 0018DDC4 00000000 */   nop
  .L0018DDC8:
    /* 8DDC8 0018DDC8 1000BFDF */  ld         $31, 0x10($29)
    /* 8DDCC 0018DDCC 0000B07B */  lq         $16, 0x0($29)
    /* 8DDD0 0018DDD0 2000BD27 */  addiu      $29, $29, 0x20
    /* 8DDD4 0018DDD4 0800E003 */  jr         $31
    /* 8DDD8 0018DDD8 00000000 */   nop
    /* 8DDDC 0018DDDC 00000000 */  nop
.size func_0018dd40, 0xa0
