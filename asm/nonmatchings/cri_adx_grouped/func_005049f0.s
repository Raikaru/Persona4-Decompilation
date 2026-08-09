.section .text
.set noat
.set noreorder
glabel func_005049f0
    /* 4049F0 005049F0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 4049F4 005049F4 7400043C */  lui        $4, %hi(D_00743D38)
    /* 4049F8 005049F8 0000BFFF */  sd         $31, 0x0($29)
    /* 4049FC 005049FC 383D8424 */  addiu      $4, $4, %lo(D_00743D38)
    /* 404A00 00504A00 0000BFDF */  ld         $31, 0x0($29)
    /* 404A04 00504A04 84121408 */  j          func_00504a10
    /* 404A08 00504A08 1000BD27 */   addiu     $29, $29, 0x10
    /* 404A0C 00504A0C 00000000 */  nop
.size func_005049f0, 0x20
