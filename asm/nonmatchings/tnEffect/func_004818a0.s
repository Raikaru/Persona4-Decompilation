.section .text
.set noat
.set noreorder
glabel func_004818a0
    /* 3818A0 004818A0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3818A4 004818A4 0000BFFF */  sd         $31, 0x0($29)
    /* 3818A8 004818A8 5C23120C */  jal        func_00488d70
    /* 3818AC 004818AC 00000000 */   nop
    /* 3818B0 004818B0 0000BFDF */  ld         $31, 0x0($29)
    /* 3818B4 004818B4 1000BD27 */  addiu      $29, $29, 0x10
    /* 3818B8 004818B8 0800E003 */  jr         $31
    /* 3818BC 004818BC 00000000 */   nop
.size func_004818a0, 0x20
