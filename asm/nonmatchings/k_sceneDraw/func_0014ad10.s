.section .text
.set noat
.set noreorder
glabel func_0014ad10
    /* 4AD10 0014AD10 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 4AD14 0014AD14 0000BFFF */  sd         $31, 0x0($29)
    /* 4AD18 0014AD18 04000424 */  addiu      $4, $0, 0x4
    /* 4AD1C 0014AD1C AC14050C */  jal        func_001452b0
    /* 4AD20 0014AD20 00000000 */   nop
    /* 4AD24 0014AD24 04004010 */  beqz       $2, .L0014AD38
    /* 4AD28 0014AD28 00000000 */   nop
    /* 4AD2C 0014AD2C 50014224 */  addiu      $2, $2, 0x150
    /* 4AD30 0014AD30 02000010 */  b          .L0014AD3C
    /* 4AD34 0014AD34 00000000 */   nop
  .L0014AD38:
    /* 4AD38 0014AD38 2D100000 */  daddu      $2, $0, $0
  .L0014AD3C:
    /* 4AD3C 0014AD3C 0000BFDF */  ld         $31, 0x0($29)
    /* 4AD40 0014AD40 1000BD27 */  addiu      $29, $29, 0x10
    /* 4AD44 0014AD44 0800E003 */  jr         $31
    /* 4AD48 0014AD48 00000000 */   nop
    /* 4AD4C 0014AD4C 00000000 */  nop
.size func_0014ad10, 0x40
