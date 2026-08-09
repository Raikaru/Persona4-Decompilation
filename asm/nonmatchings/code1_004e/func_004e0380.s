.section .text
.set noat
.set noreorder
glabel func_004e0380
    /* 3E0380 004E0380 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3E0384 004E0384 0000BFFF */  sd         $31, 0x0($29)
    /* 3E0388 004E0388 0000BFDF */  ld         $31, 0x0($29)
    /* 3E038C 004E038C 82C11308 */  j          func_004f0608
    /* 3E0390 004E0390 1000BD27 */   addiu     $29, $29, 0x10
    /* 3E0394 004E0394 00000000 */  nop
.size func_004e0380, 0x18
