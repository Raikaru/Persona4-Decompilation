.section .text
.set noat
.set noreorder
glabel func_0052beb0
    /* 42BEB0 0052BEB0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 42BEB4 0052BEB4 0000BFFF */  sd         $31, 0x0($29)
    /* 42BEB8 0052BEB8 0000BFDF */  ld         $31, 0x0($29)
    /* 42BEBC 0052BEBC C2E61308 */  j          func_004f9b08
    /* 42BEC0 0052BEC0 1000BD27 */   addiu     $29, $29, 0x10
    /* 42BEC4 0052BEC4 00000000 */  nop
.size func_0052beb0, 0x18
