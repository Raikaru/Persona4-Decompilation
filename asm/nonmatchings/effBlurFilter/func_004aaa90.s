.section .text
.set noat
.set noreorder
glabel func_004aaa90
    /* 3AAA90 004AAA90 D0FEBD27 */  addiu      $29, $29, -0x130
    /* 3AAA94 004AAA94 1000BFFF */  sd         $31, 0x10($29)
    /* 3AAA98 004AAA98 0000B07F */  sq         $16, 0x0($29)
    /* 3AAA9C 004AAA9C 2400838C */  lw         $3, 0x24($4)
    /* 3AAAA0 004AAAA0 C0007024 */  addiu      $16, $3, 0xC0
    /* 3AAAA4 004AAAA4 C3006390 */  lbu        $3, 0xC3($3)
    /* 3AAAA8 004AAAA8 22006018 */  blez       $3, .L004AAB34
    /* 3AAAAC 004AAAAC 00000000 */   nop
    /* 3AAAB0 004AAAB0 03000424 */  addiu      $4, $0, 0x3
    /* 3AAAB4 004AAAB4 2C01A527 */  addiu      $5, $29, 0x12C
    /* 3AAAB8 004AAAB8 A4D90F0C */  jal        func_003f6690
    /* 3AAABC 004AAABC 00000000 */   nop
    /* 3AAAC0 004AAAC0 2D200002 */  daddu      $4, $16, $0
    /* 3AAAC4 004AAAC4 2000A527 */  addiu      $5, $29, 0x20
    /* 3AAAC8 004AAAC8 B0A1120C */  jal        func_004a86c0
    /* 3AAACC 004AAACC 00000000 */   nop
    /* 3AAAD0 004AAAD0 01000424 */  addiu      $4, $0, 0x1
    /* 3AAAD4 004AAAD4 2D280000 */  daddu      $5, $0, $0
    /* 3AAAD8 004AAAD8 8800023C */  lui        $2, %hi(D_00887300)
    /* 3AAADC 004AAADC 0073428C */  lw         $2, %lo(D_00887300)($2)
    /* 3AAAE0 004AAAE0 09F84000 */  jalr       $2
    /* 3AAAE4 004AAAE4 00000000 */   nop
    /* 3AAAE8 004AAAE8 03000424 */  addiu      $4, $0, 0x3
    /* 3AAAEC 004AAAEC 0300023C */  lui        $2, (0x31001 >> 16)
    /* 3AAAF0 004AAAF0 01104534 */  ori        $5, $2, (0x31001 & 0xFFFF)
    /* 3AAAF4 004AAAF4 10D90F0C */  jal        func_003f6440
    /* 3AAAF8 004AAAF8 00000000 */   nop
    /* 3AAAFC 004AAAFC 03000424 */  addiu      $4, $0, 0x3
    /* 3AAB00 004AAB00 2000A527 */  addiu      $5, $29, 0x20
    /* 3AAB04 004AAB04 04000624 */  addiu      $6, $0, 0x4
    /* 3AAB08 004AAB08 7100073C */  lui        $7, %hi(D_00714368)
    /* 3AAB0C 004AAB0C 6843E724 */  addiu      $7, $7, %lo(D_00714368)
    /* 3AAB10 004AAB10 06000824 */  addiu      $8, $0, 0x6
    /* 3AAB14 004AAB14 8800023C */  lui        $2, %hi(D_00887314)
    /* 3AAB18 004AAB18 1473428C */  lw         $2, %lo(D_00887314)($2)
    /* 3AAB1C 004AAB1C 09F84000 */  jalr       $2
    /* 3AAB20 004AAB20 00000000 */   nop
    /* 3AAB24 004AAB24 03000424 */  addiu      $4, $0, 0x3
    /* 3AAB28 004AAB28 2C01A58F */  lw         $5, 0x12C($29)
    /* 3AAB2C 004AAB2C 10D90F0C */  jal        func_003f6440
    /* 3AAB30 004AAB30 00000000 */   nop
  .L004AAB34:
    /* 3AAB34 004AAB34 1000BFDF */  ld         $31, 0x10($29)
    /* 3AAB38 004AAB38 0000B07B */  lq         $16, 0x0($29)
    /* 3AAB3C 004AAB3C 3001BD27 */  addiu      $29, $29, 0x130
    /* 3AAB40 004AAB40 0800E003 */  jr         $31
    /* 3AAB44 004AAB44 00000000 */   nop
    /* 3AAB48 004AAB48 00000000 */  nop
    /* 3AAB4C 004AAB4C 00000000 */  nop
.size func_004aaa90, 0xc0
