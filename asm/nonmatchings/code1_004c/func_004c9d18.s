.section .text
.set noat
.set noreorder
glabel func_004c9d18
    /* 3C9D18 004C9D18 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3C9D1C 004C9D1C 0000BFFF */  sd         $31, 0x0($29)
    /* 3C9D20 004C9D20 0000BFDF */  ld         $31, 0x0($29)
    /* 3C9D24 004C9D24 36151308 */  j          func_004c54d8
    /* 3C9D28 004C9D28 1000BD27 */   addiu     $29, $29, 0x10
    /* 3C9D2C 004C9D2C 00000000 */  nop
.size func_004c9d18, 0x18
