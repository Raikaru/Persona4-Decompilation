.section .text
.set noat
.set noreorder
glabel func_0050ea40
    /* 40EA40 0050EA40 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40EA44 0050EA44 0000BFFF */  sd         $31, 0x0($29)
    /* 40EA48 0050EA48 A800848C */  lw         $4, 0xA8($4)
    /* 40EA4C 0050EA4C 0000BFDF */  ld         $31, 0x0($29)
    /* 40EA50 0050EA50 B4AE1408 */  j          func_0052bad0
    /* 40EA54 0050EA54 1000BD27 */   addiu     $29, $29, 0x10
.size func_0050ea40, 0x18
