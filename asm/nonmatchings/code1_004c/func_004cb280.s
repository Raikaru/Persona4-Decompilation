.section .text
.set noat
.set noreorder
glabel func_004cb280
    /* 3CB280 004CB280 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CB284 004CB284 0000BFFF */  sd         $31, 0x0($29)
    /* 3CB288 004CB288 3615130C */  jal        func_004c54d8
    /* 3CB28C 004CB28C 00000000 */   nop
    /* 3CB290 004CB290 AA2C130C */  jal        func_004cb2a8
    /* 3CB294 004CB294 00000000 */   nop
    /* 3CB298 004CB298 0000BFDF */  ld         $31, 0x0($29)
    /* 3CB29C 004CB29C 38151308 */  j          func_004c54e0
    /* 3CB2A0 004CB2A0 1000BD27 */   addiu     $29, $29, 0x10
    /* 3CB2A4 004CB2A4 00000000 */  nop
.size func_004cb280, 0x28
