.section .text
.set noat
.set noreorder
glabel func_00178ba0
    /* 78BA0 00178BA0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 78BA4 00178BA4 0000BFFF */  sd         $31, 0x0($29)
    /* 78BA8 00178BA8 E0B2828F */  lw         $2, -0x4D20($28)
    /* 78BAC 00178BAC 6001428C */  lw         $2, 0x160($2)
    /* 78BB0 00178BB0 06004490 */  lbu        $4, 0x6($2)
    /* 78BB4 00178BB4 D4730A0C */  jal        func_0029cf50
    /* 78BB8 00178BB8 00000000 */   nop
    /* 78BBC 00178BBC 01000224 */  addiu      $2, $0, 0x1
    /* 78BC0 00178BC0 0000BFDF */  ld         $31, 0x0($29)
    /* 78BC4 00178BC4 1000BD27 */  addiu      $29, $29, 0x10
    /* 78BC8 00178BC8 0800E003 */  jr         $31
    /* 78BCC 00178BCC 00000000 */   nop
.size func_00178ba0, 0x30
