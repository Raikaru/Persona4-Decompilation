.section .text
.set noat
.set noreorder
glabel func_00312b90
    /* 212B90 00312B90 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 212B94 00312B94 0000BFFF */  sd         $31, 0x0($29)
    /* 212B98 00312B98 F8490C0C */  jal        func_003127e0
    /* 212B9C 00312B9C 00000000 */   nop
    /* 212BA0 00312BA0 FF004230 */  andi       $2, $2, 0xFF
    /* 212BA4 00312BA4 0000BFDF */  ld         $31, 0x0($29)
    /* 212BA8 00312BA8 1000BD27 */  addiu      $29, $29, 0x10
    /* 212BAC 00312BAC 0800E003 */  jr         $31
    /* 212BB0 00312BB0 00000000 */   nop
    /* 212BB4 00312BB4 00000000 */  nop
    /* 212BB8 00312BB8 00000000 */  nop
    /* 212BBC 00312BBC 00000000 */  nop
.size func_00312b90, 0x30
