.section .text
.set noat
.set noreorder
glabel func_0015cbe0
    /* 5CBE0 0015CBE0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 5CBE4 0015CBE4 1000BFFF */  sd         $31, 0x10($29)
    /* 5CBE8 0015CBE8 0000B07F */  sq         $16, 0x0($29)
    /* 5CBEC 0015CBEC 2D808000 */  daddu      $16, $4, $0
    /* 5CBF0 0015CBF0 A054050C */  jal        func_00155280
    /* 5CBF4 0015CBF4 00000000 */   nop
    /* 5CBF8 0015CBF8 F418428C */  lw         $2, 0x18F4($2)
    /* 5CBFC 0015CBFC 2D280000 */  daddu      $5, $0, $0
    /* 5CC00 0015CC00 FFFF0334 */  ori        $3, $0, 0xFFFF
  .L0015CC04:
    /* 5CC04 0015CC04 0800B010 */  beq        $5, $16, .L0015CC28
    /* 5CC08 0015CC08 00000000 */   nop
    /* 5CC0C 0015CC0C 00004494 */  lhu        $4, 0x0($2)
    /* 5CC10 0015CC10 02008314 */  bne        $4, $3, .L0015CC1C
    /* 5CC14 0015CC14 00000000 */   nop
    /* 5CC18 0015CC18 0100A524 */  addiu      $5, $5, 0x1
  .L0015CC1C:
    /* 5CC1C 0015CC1C 20004224 */  addiu      $2, $2, 0x20
    /* 5CC20 0015CC20 F8FF0010 */  b          .L0015CC04
    /* 5CC24 0015CC24 00000000 */   nop
  .L0015CC28:
    /* 5CC28 0015CC28 1000BFDF */  ld         $31, 0x10($29)
    /* 5CC2C 0015CC2C 0000B07B */  lq         $16, 0x0($29)
    /* 5CC30 0015CC30 2000BD27 */  addiu      $29, $29, 0x20
    /* 5CC34 0015CC34 0800E003 */  jr         $31
    /* 5CC38 0015CC38 00000000 */   nop
    /* 5CC3C 0015CC3C 00000000 */  nop
.size func_0015cbe0, 0x60
