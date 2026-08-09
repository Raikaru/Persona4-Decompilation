.section .text
.set noat
.set noreorder
glabel func_004f99e0
    /* 3F99E0 004F99E0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3F99E4 004F99E4 0000BFFF */  sd         $31, 0x0($29)
    /* 3F99E8 004F99E8 0000BFDF */  ld         $31, 0x0($29)
    /* 3F99EC 004F99EC 82C11308 */  j          func_004f0608
    /* 3F99F0 004F99F0 1000BD27 */   addiu     $29, $29, 0x10
    /* 3F99F4 004F99F4 00000000 */  nop
.size func_004f99e0, 0x18
