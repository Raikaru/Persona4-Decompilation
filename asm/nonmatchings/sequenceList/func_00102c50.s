.section .text
.set noat
.set noreorder
glabel func_00102c50
    /* 2C50 00102C50 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 2C54 00102C54 0000BFFF */  sd         $31, 0x0($29)
    /* 2C58 00102C58 2D200000 */  daddu      $4, $0, $0
    /* 2C5C 00102C5C 18B1040C */  jal        func_0012c460
    /* 2C60 00102C60 00000000 */   nop
    /* 2C64 00102C64 0000BFDF */  ld         $31, 0x0($29)
    /* 2C68 00102C68 1000BD27 */  addiu      $29, $29, 0x10
    /* 2C6C 00102C6C 0800E003 */  jr         $31
    /* 2C70 00102C70 00000000 */   nop
    /* 2C74 00102C74 00000000 */  nop
    /* 2C78 00102C78 00000000 */  nop
    /* 2C7C 00102C7C 00000000 */  nop
.size func_00102c50, 0x30
