.section .text
.set noat
.set noreorder
glabel func_00149ca0
    /* 49CA0 00149CA0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 49CA4 00149CA4 0000BFFF */  sd         $31, 0x0($29)
    /* 49CA8 00149CA8 0C000424 */  addiu      $4, $0, 0xC
    /* 49CAC 00149CAC AC14050C */  jal        func_001452b0
    /* 49CB0 00149CB0 00000000 */   nop
    /* 49CB4 00149CB4 04004014 */  bnez       $2, .L00149CC8
    /* 49CB8 00149CB8 00000000 */   nop
    /* 49CBC 00149CBC 2D100000 */  daddu      $2, $0, $0
    /* 49CC0 00149CC0 02000010 */  b          .L00149CCC
    /* 49CC4 00149CC4 00000000 */   nop
  .L00149CC8:
    /* 49CC8 00149CC8 40014224 */  addiu      $2, $2, 0x140
  .L00149CCC:
    /* 49CCC 00149CCC 0000BFDF */  ld         $31, 0x0($29)
    /* 49CD0 00149CD0 1000BD27 */  addiu      $29, $29, 0x10
    /* 49CD4 00149CD4 0800E003 */  jr         $31
    /* 49CD8 00149CD8 00000000 */   nop
    /* 49CDC 00149CDC 00000000 */  nop
.size func_00149ca0, 0x40
