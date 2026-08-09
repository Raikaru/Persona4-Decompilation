.section .text
.set noat
.set noreorder
glabel func_004d6388
    /* 3D6388 004D6388 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D638C 004D638C 0000BFFF */  sd         $31, 0x0($29)
    /* 3D6390 004D6390 0000BFDF */  ld         $31, 0x0($29)
    /* 3D6394 004D6394 9C1A1308 */  j          func_004c6a70
    /* 3D6398 004D6398 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D639C 004D639C 00000000 */  nop
.size func_004d6388, 0x18
