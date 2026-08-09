.section .text
.set noat
.set noreorder
glabel func_0020ba00
    /* 10BA00 0020BA00 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 10BA04 0020BA04 0000BFFF */  sd         $31, 0x0($29)
    /* 10BA08 0020BA08 5849110C */  jal        func_00452560
    /* 10BA0C 0020BA0C 00000000 */   nop
    /* 10BA10 0020BA10 12074294 */  lhu        $2, 0x712($2)
    /* 10BA14 0020BA14 0000BFDF */  ld         $31, 0x0($29)
    /* 10BA18 0020BA18 1000BD27 */  addiu      $29, $29, 0x10
    /* 10BA1C 0020BA1C 0800E003 */  jr         $31
    /* 10BA20 0020BA20 00000000 */   nop
    /* 10BA24 0020BA24 00000000 */  nop
    /* 10BA28 0020BA28 00000000 */  nop
    /* 10BA2C 0020BA2C 00000000 */  nop
.size func_0020ba00, 0x30
