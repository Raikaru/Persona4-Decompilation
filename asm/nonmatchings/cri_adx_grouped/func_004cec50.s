.section .text
.set noat
.set noreorder
glabel func_004cec50
    /* 3CEC50 004CEC50 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CEC54 004CEC54 0000BFFF */  sd         $31, 0x0($29)
    /* 3CEC58 004CEC58 0000BFDF */  ld         $31, 0x0($29)
    /* 3CEC5C 004CEC5C 760F1308 */  j          func_004c3dd8
    /* 3CEC60 004CEC60 1000BD27 */   addiu     $29, $29, 0x10
    /* 3CEC64 004CEC64 00000000 */  nop
.size func_004cec50, 0x18
