.section .text
.set noat
.set noreorder
glabel func_004c6f08
    /* 3C6F08 004C6F08 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3C6F0C 004C6F0C 0000BFFF */  sd         $31, 0x0($29)
    /* 3C6F10 004C6F10 8A1C130C */  jal        func_004c7228
    /* 3C6F14 004C6F14 00000000 */   nop
    /* 3C6F18 004C6F18 CC1B130C */  jal        func_004c6f30
    /* 3C6F1C 004C6F1C 00000000 */   nop
    /* 3C6F20 004C6F20 0000BFDF */  ld         $31, 0x0($29)
    /* 3C6F24 004C6F24 8C1C1308 */  j          func_004c7230
    /* 3C6F28 004C6F28 1000BD27 */   addiu     $29, $29, 0x10
    /* 3C6F2C 004C6F2C 00000000 */  nop
.size func_004c6f08, 0x28
