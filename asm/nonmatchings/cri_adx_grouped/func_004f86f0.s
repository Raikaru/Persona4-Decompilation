.section .text
.set noat
.set noreorder
glabel func_004f86f0
    /* 3F86F0 004F86F0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3F86F4 004F86F4 0000BFFF */  sd         $31, 0x0($29)
    /* 3F86F8 004F86F8 0000BFDF */  ld         $31, 0x0($29)
    /* 3F86FC 004F86FC 52CA1308 */  j          func_004f2948
    /* 3F8700 004F8700 1000BD27 */   addiu     $29, $29, 0x10
    /* 3F8704 004F8704 00000000 */  nop
.size func_004f86f0, 0x18
