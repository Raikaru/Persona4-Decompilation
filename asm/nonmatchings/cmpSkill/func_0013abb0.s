.section .text
.set noat
.set noreorder
glabel func_0013abb0
    /* 3ABB0 0013ABB0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3ABB4 0013ABB4 1000BFFF */  sd         $31, 0x10($29)
    /* 3ABB8 0013ABB8 0000B07F */  sq         $16, 0x0($29)
    /* 3ABBC 0013ABBC 01001024 */  addiu      $16, $0, 0x1
    /* 3ABC0 0013ABC0 2D280000 */  daddu      $5, $0, $0
    /* 3ABC4 0013ABC4 20008384 */  lh         $3, 0x20($4)
    /* 3ABC8 0013ABC8 0B000010 */  b          .L0013ABF8
    /* 3ABCC 0013ABCC 00000000 */   nop
  .L0013ABD0:
    /* 3ABD0 0013ABD0 40100500 */  sll        $2, $5, 1
    /* 3ABD4 0013ABD4 21104500 */  addu       $2, $2, $5
    /* 3ABD8 0013ABD8 00110200 */  sll        $2, $2, 4
    /* 3ABDC 0013ABDC 21108200 */  addu       $2, $4, $2
    /* 3ABE0 0013ABE0 B005428C */  lw         $2, 0x5B0($2)
    /* 3ABE4 0013ABE4 2A086200 */  slt        $1, $3, $2
    /* 3ABE8 0013ABE8 02002010 */  beqz       $1, .L0013ABF4
    /* 3ABEC 0013ABEC 00000000 */   nop
    /* 3ABF0 0013ABF0 2D800000 */  daddu      $16, $0, $0
  .L0013ABF4:
    /* 3ABF4 0013ABF4 0100A524 */  addiu      $5, $5, 0x1
  .L0013ABF8:
    /* 3ABF8 0013ABF8 2600A228 */  slti       $2, $5, 0x26
    /* 3ABFC 0013ABFC F4FF4014 */  bnez       $2, .L0013ABD0
    /* 3AC00 0013AC00 00000000 */   nop
    /* 3AC04 0013AC04 84300D0C */  jal        func_0034c210
    /* 3AC08 0013AC08 00000000 */   nop
    /* 3AC0C 0013AC0C 24100202 */  and        $2, $16, $2
    /* 3AC10 0013AC10 1000BFDF */  ld         $31, 0x10($29)
    /* 3AC14 0013AC14 0000B07B */  lq         $16, 0x0($29)
    /* 3AC18 0013AC18 2000BD27 */  addiu      $29, $29, 0x20
    /* 3AC1C 0013AC1C 0800E003 */  jr         $31
    /* 3AC20 0013AC20 00000000 */   nop
    /* 3AC24 0013AC24 00000000 */  nop
    /* 3AC28 0013AC28 00000000 */  nop
    /* 3AC2C 0013AC2C 00000000 */  nop
.size func_0013abb0, 0x80
