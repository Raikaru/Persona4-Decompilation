.section .text
.set noat
.set noreorder
glabel func_004c9d30
    /* 3C9D30 004C9D30 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3C9D34 004C9D34 0000BFFF */  sd         $31, 0x0($29)
    /* 3C9D38 004C9D38 0000BFDF */  ld         $31, 0x0($29)
    /* 3C9D3C 004C9D3C 38151308 */  j          func_004c54e0
    /* 3C9D40 004C9D40 1000BD27 */   addiu     $29, $29, 0x10
    /* 3C9D44 004C9D44 00000000 */  nop
.size func_004c9d30, 0x18
