.section .text
.set noat
.set noreorder
glabel func_00201ee0
    /* 101EE0 00201EE0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 101EE4 00201EE4 0000BFFF */  sd         $31, 0x0($29)
    /* 101EE8 00201EE8 ACB3828F */  lw         $2, -0x4C54($28)
    /* 101EEC 00201EEC D40D448C */  lw         $4, 0xDD4($2)
    /* 101EF0 00201EF0 FC38080C */  jal        func_0020e3f0
    /* 101EF4 00201EF4 00000000 */   nop
    /* 101EF8 00201EF8 ACB3828F */  lw         $2, -0x4C54($28)
    /* 101EFC 00201EFC D40D448C */  lw         $4, 0xDD4($2)
    /* 101F00 00201F00 E86B080C */  jal        func_0021afa0
    /* 101F04 00201F04 00000000 */   nop
    /* 101F08 00201F08 01000224 */  addiu      $2, $0, 0x1
    /* 101F0C 00201F0C 0000BFDF */  ld         $31, 0x0($29)
    /* 101F10 00201F10 1000BD27 */  addiu      $29, $29, 0x10
    /* 101F14 00201F14 0800E003 */  jr         $31
    /* 101F18 00201F18 00000000 */   nop
    /* 101F1C 00201F1C 00000000 */  nop
.size func_00201ee0, 0x40
