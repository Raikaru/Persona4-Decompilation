.section .text
.set noat
.set noreorder
glabel func_004f6808
    /* 3F6808 004F6808 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3F680C 004F680C 0000BFFF */  sd         $31, 0x0($29)
    /* 3F6810 004F6810 0000BFDF */  ld         $31, 0x0($29)
    /* 3F6814 004F6814 A2E61308 */  j          func_004f9a88
    /* 3F6818 004F6818 1000BD27 */   addiu     $29, $29, 0x10
    /* 3F681C 004F681C 00000000 */  nop
.size func_004f6808, 0x18
