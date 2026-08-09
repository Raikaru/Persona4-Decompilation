.section .text
.set noat
.set noreorder
glabel func_0027baa0
    /* 17BAA0 0027BAA0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 17BAA4 0027BAA4 1000BFFF */  sd         $31, 0x10($29)
    /* 17BAA8 0027BAA8 0000B07F */  sq         $16, 0x0($29)
    /* 17BAAC 0027BAAC 2D808000 */  daddu      $16, $4, $0
    /* 17BAB0 0027BAB0 10DE090C */  jal        func_00277840
    /* 17BAB4 0027BAB4 00000000 */   nop
    /* 17BAB8 0027BAB8 2D200002 */  daddu      $4, $16, $0
    /* 17BABC 0027BABC 10DE090C */  jal        func_00277840
    /* 17BAC0 0027BAC0 00000000 */   nop
    /* 17BAC4 0027BAC4 0000428C */  lw         $2, 0x0($2)
    /* 17BAC8 0027BAC8 07004010 */  beqz       $2, .L0027BAE8
    /* 17BACC 0027BACC 00000000 */   nop
    /* 17BAD0 0027BAD0 2D200002 */  daddu      $4, $16, $0
    /* 17BAD4 0027BAD4 07000524 */  addiu      $5, $0, 0x7
    /* 17BAD8 0027BAD8 09F84000 */  jalr       $2
    /* 17BADC 0027BADC 00000000 */   nop
    /* 17BAE0 0027BAE0 02000010 */  b          .L0027BAEC
    /* 17BAE4 0027BAE4 00000000 */   nop
  .L0027BAE8:
    /* 17BAE8 0027BAE8 01000224 */  addiu      $2, $0, 0x1
  .L0027BAEC:
    /* 17BAEC 0027BAEC 1000BFDF */  ld         $31, 0x10($29)
    /* 17BAF0 0027BAF0 0000B07B */  lq         $16, 0x0($29)
    /* 17BAF4 0027BAF4 2000BD27 */  addiu      $29, $29, 0x20
    /* 17BAF8 0027BAF8 0800E003 */  jr         $31
    /* 17BAFC 0027BAFC 00000000 */   nop
.size func_0027baa0, 0x60
