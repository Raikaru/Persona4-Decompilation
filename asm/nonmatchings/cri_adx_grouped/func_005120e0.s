.section .text
.set noat
.set noreorder
glabel func_005120e0
    /* 4120E0 005120E0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 4120E4 005120E4 0000BFFF */  sd         $31, 0x0($29)
    /* 4120E8 005120E8 0000BFDF */  ld         $31, 0x0($29)
    /* 4120EC 005120EC E04A1308 */  j          func_004d2b80
    /* 4120F0 005120F0 1000BD27 */   addiu     $29, $29, 0x10
    /* 4120F4 005120F4 00000000 */  nop
.size func_005120e0, 0x18
