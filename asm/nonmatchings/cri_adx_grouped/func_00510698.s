.section .text
.set noat
.set noreorder
glabel func_00510698
    /* 410698 00510698 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 41069C 0051069C 0000BFFF */  sd         $31, 0x0($29)
    /* 4106A0 005106A0 0000BFDF */  ld         $31, 0x0($29)
    /* 4106A4 005106A4 AC411408 */  j          func_005106b0
    /* 4106A8 005106A8 1000BD27 */   addiu     $29, $29, 0x10
    /* 4106AC 005106AC 00000000 */  nop
.size func_00510698, 0x18
