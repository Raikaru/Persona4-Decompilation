.section .text
.set noat
.set noreorder
glabel func_00178bd0
    /* 78BD0 00178BD0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 78BD4 00178BD4 0000BFFF */  sd         $31, 0x0($29)
    /* 78BD8 00178BD8 E0B2828F */  lw         $2, -0x4D20($28)
    /* 78BDC 00178BDC 6001428C */  lw         $2, 0x160($2)
    /* 78BE0 00178BE0 04004490 */  lbu        $4, 0x4($2)
    /* 78BE4 00178BE4 D4730A0C */  jal        func_0029cf50
    /* 78BE8 00178BE8 00000000 */   nop
    /* 78BEC 00178BEC 01000224 */  addiu      $2, $0, 0x1
    /* 78BF0 00178BF0 0000BFDF */  ld         $31, 0x0($29)
    /* 78BF4 00178BF4 1000BD27 */  addiu      $29, $29, 0x10
    /* 78BF8 00178BF8 0800E003 */  jr         $31
    /* 78BFC 00178BFC 00000000 */   nop
.size func_00178bd0, 0x30
