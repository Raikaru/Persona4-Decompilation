.section .text
.set noat
.set noreorder
glabel func_004f8618
    /* 3F8618 004F8618 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3F861C 004F861C 0000BFFF */  sd         $31, 0x0($29)
    /* 3F8620 004F8620 0000BFDF */  ld         $31, 0x0($29)
    /* 3F8624 004F8624 E6C81308 */  j          func_004f2398
    /* 3F8628 004F8628 1000BD27 */   addiu     $29, $29, 0x10
    /* 3F862C 004F862C 00000000 */  nop
.size func_004f8618, 0x18
