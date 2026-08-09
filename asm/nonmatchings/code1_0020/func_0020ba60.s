.section .text
.set noat
.set noreorder
glabel func_0020ba60
    /* 10BA60 0020BA60 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 10BA64 0020BA64 0000BFFF */  sd         $31, 0x0($29)
    /* 10BA68 0020BA68 5849110C */  jal        func_00452560
    /* 10BA6C 0020BA6C 00000000 */   nop
    /* 10BA70 0020BA70 2007448C */  lw         $4, 0x720($2)
    /* 10BA74 0020BA74 F062070C */  jal        func_001d8bc0
    /* 10BA78 0020BA78 00000000 */   nop
    /* 10BA7C 0020BA7C 0000BFDF */  ld         $31, 0x0($29)
    /* 10BA80 0020BA80 1000BD27 */  addiu      $29, $29, 0x10
    /* 10BA84 0020BA84 0800E003 */  jr         $31
    /* 10BA88 0020BA88 00000000 */   nop
    /* 10BA8C 0020BA8C 00000000 */  nop
.size func_0020ba60, 0x30
