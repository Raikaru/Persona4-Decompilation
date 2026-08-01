.section .text
.set noat
.set noreorder
glabel func_004460f0
    /* 3460F0 004460F0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3460F4 004460F4 0000BFFF */  sd         $31, 0x0($29)
    /* 3460F8 004460F8 0000BFDF */  ld         $31, 0x0($29)
    /* 3460FC 004460FC 42181108 */  j          func_00446108
    /* 346100 00446100 1000BD27 */   addiu     $29, $29, 0x10
    /* 346104 00446104 00000000 */  nop
.size func_004460f0, 0x18
