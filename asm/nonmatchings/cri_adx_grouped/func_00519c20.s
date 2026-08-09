.section .text
.set noat
.set noreorder
glabel func_00519c20
    /* 419C20 00519C20 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 419C24 00519C24 0000BFFF */  sd         $31, 0x0($29)
    /* 419C28 00519C28 0000BFDF */  ld         $31, 0x0($29)
    /* 419C2C 00519C2C B45E1408 */  j          func_00517ad0
    /* 419C30 00519C30 1000BD27 */   addiu     $29, $29, 0x10
    /* 419C34 00519C34 00000000 */  nop
.size func_00519c20, 0x18
