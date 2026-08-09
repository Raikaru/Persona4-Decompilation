.section .text
.set noat
.set noreorder
glabel func_00513278
    /* 413278 00513278 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 41327C 0051327C 0000BFFF */  sd         $31, 0x0($29)
    /* 413280 00513280 0C20858C */  lw         $5, 0x200C($4)
    /* 413284 00513284 0000BFDF */  ld         $31, 0x0($29)
    /* 413288 00513288 68561408 */  j          func_005159a0
    /* 41328C 0051328C 1000BD27 */   addiu     $29, $29, 0x10
.size func_00513278, 0x18
