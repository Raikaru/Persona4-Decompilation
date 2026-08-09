.section .text
.set noat
.set noreorder
glabel func_0014ad50
    /* 4AD50 0014AD50 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 4AD54 0014AD54 0000BFFF */  sd         $31, 0x0($29)
    /* 4AD58 0014AD58 04000424 */  addiu      $4, $0, 0x4
    /* 4AD5C 0014AD5C AC14050C */  jal        func_001452b0
    /* 4AD60 0014AD60 00000000 */   nop
    /* 4AD64 0014AD64 04004010 */  beqz       $2, .L0014AD78
    /* 4AD68 0014AD68 00000000 */   nop
    /* 4AD6C 0014AD6C 60014224 */  addiu      $2, $2, 0x160
    /* 4AD70 0014AD70 02000010 */  b          .L0014AD7C
    /* 4AD74 0014AD74 00000000 */   nop
  .L0014AD78:
    /* 4AD78 0014AD78 2D100000 */  daddu      $2, $0, $0
  .L0014AD7C:
    /* 4AD7C 0014AD7C 0000BFDF */  ld         $31, 0x0($29)
    /* 4AD80 0014AD80 1000BD27 */  addiu      $29, $29, 0x10
    /* 4AD84 0014AD84 0800E003 */  jr         $31
    /* 4AD88 0014AD88 00000000 */   nop
    /* 4AD8C 0014AD8C 00000000 */  nop
.size func_0014ad50, 0x40
