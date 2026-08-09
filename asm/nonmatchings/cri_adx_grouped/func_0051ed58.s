.section .text
.set noat
.set noreorder
glabel func_0051ed58
    /* 41ED58 0051ED58 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 41ED5C 0051ED5C 0000BFFF */  sd         $31, 0x0($29)
    /* 41ED60 0051ED60 0000BFDF */  ld         $31, 0x0($29)
    /* 41ED64 0051ED64 961C1408 */  j          func_00507258
    /* 41ED68 0051ED68 1000BD27 */   addiu     $29, $29, 0x10
    /* 41ED6C 0051ED6C 00000000 */  nop
.size func_0051ed58, 0x18
