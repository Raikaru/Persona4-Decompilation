.section .text
.set noat
.set noreorder
glabel func_00511180
    /* 411180 00511180 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 411184 00511184 0000BFFF */  sd         $31, 0x0($29)
    /* 411188 00511188 0000BFDF */  ld         $31, 0x0($29)
    /* 41118C 0051118C B2C11308 */  j          func_004f06c8
    /* 411190 00511190 1000BD27 */   addiu     $29, $29, 0x10
    /* 411194 00511194 00000000 */  nop
.size func_00511180, 0x18
