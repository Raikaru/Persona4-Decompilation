.section .text
.set noat
.set noreorder
glabel func_004e9e20
    /* 3E9E20 004E9E20 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3E9E24 004E9E24 0000BFFF */  sd         $31, 0x0($29)
    /* 3E9E28 004E9E28 0000BFDF */  ld         $31, 0x0($29)
    /* 3E9E2C 004E9E2C 82C11308 */  j          func_004f0608
    /* 3E9E30 004E9E30 1000BD27 */   addiu     $29, $29, 0x10
    /* 3E9E34 004E9E34 00000000 */  nop
.size func_004e9e20, 0x18
