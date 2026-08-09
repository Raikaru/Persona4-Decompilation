.section .text
.set noat
.set noreorder
glabel func_004f10c8
    /* 3F10C8 004F10C8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3F10CC 004F10CC 05000424 */  addiu      $4, $0, 0x5
    /* 3F10D0 004F10D0 0000BFFF */  sd         $31, 0x0($29)
    /* 3F10D4 004F10D4 0000BFDF */  ld         $31, 0x0($29)
    /* 3F10D8 004F10D8 BCC31308 */  j          func_004f0ef0
    /* 3F10DC 004F10DC 1000BD27 */   addiu     $29, $29, 0x10
.size func_004f10c8, 0x18
