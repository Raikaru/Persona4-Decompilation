.section .text
.set noat
.set noreorder
glabel func_001032c0
    /* 32C0 001032C0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 32C4 001032C4 0000BFFF */  sd         $31, 0x0($29)
    /* 32C8 001032C8 2D200000 */  daddu      $4, $0, $0
    /* 32CC 001032CC 449D0B0C */  jal        func_002e7510
    /* 32D0 001032D0 00000000 */   nop
    /* 32D4 001032D4 0000BFDF */  ld         $31, 0x0($29)
    /* 32D8 001032D8 1000BD27 */  addiu      $29, $29, 0x10
    /* 32DC 001032DC 0800E003 */  jr         $31
    /* 32E0 001032E0 00000000 */   nop
    /* 32E4 001032E4 00000000 */  nop
    /* 32E8 001032E8 00000000 */  nop
    /* 32EC 001032EC 00000000 */  nop
.size func_001032c0, 0x30
