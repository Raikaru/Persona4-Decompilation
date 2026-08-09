.section .text
.set noat
.set noreorder
glabel func_004c6f30
    /* 3C6F30 004C6F30 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3C6F34 004C6F34 7500043C */  lui        $4, %hi(D_00757EF8)
    /* 3C6F38 004C6F38 0000BFFF */  sd         $31, 0x0($29)
    /* 3C6F3C 004C6F3C F87E8424 */  addiu      $4, $4, %lo(D_00757EF8)
    /* 3C6F40 004C6F40 0000BFDF */  ld         $31, 0x0($29)
    /* 3C6F44 004C6F44 80861308 */  j          func_004e1a00
    /* 3C6F48 004C6F48 1000BD27 */   addiu     $29, $29, 0x10
    /* 3C6F4C 004C6F4C 00000000 */  nop
.size func_004c6f30, 0x20
