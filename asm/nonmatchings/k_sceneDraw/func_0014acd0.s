.section .text
.set noat
.set noreorder
glabel func_0014acd0
    /* 4ACD0 0014ACD0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 4ACD4 0014ACD4 0000BFFF */  sd         $31, 0x0($29)
    /* 4ACD8 0014ACD8 04000424 */  addiu      $4, $0, 0x4
    /* 4ACDC 0014ACDC AC14050C */  jal        func_001452b0
    /* 4ACE0 0014ACE0 00000000 */   nop
    /* 4ACE4 0014ACE4 04004010 */  beqz       $2, .L0014ACF8
    /* 4ACE8 0014ACE8 00000000 */   nop
    /* 4ACEC 0014ACEC 40014224 */  addiu      $2, $2, 0x140
    /* 4ACF0 0014ACF0 02000010 */  b          .L0014ACFC
    /* 4ACF4 0014ACF4 00000000 */   nop
  .L0014ACF8:
    /* 4ACF8 0014ACF8 2D100000 */  daddu      $2, $0, $0
  .L0014ACFC:
    /* 4ACFC 0014ACFC 0000BFDF */  ld         $31, 0x0($29)
    /* 4AD00 0014AD00 1000BD27 */  addiu      $29, $29, 0x10
    /* 4AD04 0014AD04 0800E003 */  jr         $31
    /* 4AD08 0014AD08 00000000 */   nop
    /* 4AD0C 0014AD0C 00000000 */  nop
.size func_0014acd0, 0x40
