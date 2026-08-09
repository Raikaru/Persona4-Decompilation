.section .text
.set noat
.set noreorder
glabel func_0025ff60
    /* 15FF60 0025FF60 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 15FF64 0025FF64 0000BFFF */  sd         $31, 0x0($29)
    /* 15FF68 0025FF68 5849110C */  jal        func_00452560
    /* 15FF6C 0025FF6C 00000000 */   nop
    /* 15FF70 0025FF70 0000428C */  lw         $2, 0x0($2)
    /* 15FF74 0025FF74 0000BFDF */  ld         $31, 0x0($29)
    /* 15FF78 0025FF78 1000BD27 */  addiu      $29, $29, 0x10
    /* 15FF7C 0025FF7C 0800E003 */  jr         $31
    /* 15FF80 0025FF80 00000000 */   nop
    /* 15FF84 0025FF84 00000000 */  nop
    /* 15FF88 0025FF88 00000000 */  nop
    /* 15FF8C 0025FF8C 00000000 */  nop
.size func_0025ff60, 0x30
