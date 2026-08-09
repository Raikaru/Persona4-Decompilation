.section .text
.set noat
.set noreorder
glabel func_00527218
    /* 427218 00527218 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 42721C 0052721C 01000524 */  addiu      $5, $0, 0x1
    /* 427220 00527220 0000BFFF */  sd         $31, 0x0($29)
    /* 427224 00527224 0000BFDF */  ld         $31, 0x0($29)
    /* 427228 00527228 8C9C1408 */  j          func_00527230
    /* 42722C 0052722C 1000BD27 */   addiu     $29, $29, 0x10
.size func_00527218, 0x18
