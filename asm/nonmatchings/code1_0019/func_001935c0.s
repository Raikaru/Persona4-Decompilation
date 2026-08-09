.section .text
.set noat
.set noreorder
glabel func_001935c0
    /* 935C0 001935C0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 935C4 001935C4 0000BFFF */  sd         $31, 0x0($29)
    /* 935C8 001935C8 01000424 */  addiu      $4, $0, 0x1
    /* 935CC 001935CC 6CF0070C */  jal        func_001fc1b0
    /* 935D0 001935D0 00000000 */   nop
    /* 935D4 001935D4 01000224 */  addiu      $2, $0, 0x1
    /* 935D8 001935D8 0000BFDF */  ld         $31, 0x0($29)
    /* 935DC 001935DC 1000BD27 */  addiu      $29, $29, 0x10
    /* 935E0 001935E0 0800E003 */  jr         $31
    /* 935E4 001935E4 00000000 */   nop
    /* 935E8 001935E8 00000000 */  nop
    /* 935EC 001935EC 00000000 */  nop
.size func_001935c0, 0x30
