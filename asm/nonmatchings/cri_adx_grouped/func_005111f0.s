.section .text
.set noat
.set noreorder
glabel func_005111f0
    /* 4111F0 005111F0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 4111F4 005111F4 0000BFFF */  sd         $31, 0x0($29)
    /* 4111F8 005111F8 0000BFDF */  ld         $31, 0x0($29)
    /* 4111FC 005111FC BEC11308 */  j          func_004f06f8
    /* 411200 00511200 1000BD27 */   addiu     $29, $29, 0x10
    /* 411204 00511204 00000000 */  nop
.size func_005111f0, 0x18
