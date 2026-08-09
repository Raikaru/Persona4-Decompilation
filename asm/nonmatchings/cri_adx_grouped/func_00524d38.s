.section .text
.set noat
.set noreorder
glabel func_00524d38
    /* 424D38 00524D38 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 424D3C 00524D3C 0000BFFF */  sd         $31, 0x0($29)
    /* 424D40 00524D40 0000BFDF */  ld         $31, 0x0($29)
    /* 424D44 00524D44 FE891408 */  j          func_005227f8
    /* 424D48 00524D48 1000BD27 */   addiu     $29, $29, 0x10
    /* 424D4C 00524D4C 00000000 */  nop
.size func_00524d38, 0x18
