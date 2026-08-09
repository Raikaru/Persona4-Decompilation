.section .text
.set noat
.set noreorder
glabel func_004f10e0
    /* 3F10E0 004F10E0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3F10E4 004F10E4 06000424 */  addiu      $4, $0, 0x6
    /* 3F10E8 004F10E8 0000BFFF */  sd         $31, 0x0($29)
    /* 3F10EC 004F10EC 0000BFDF */  ld         $31, 0x0($29)
    /* 3F10F0 004F10F0 BCC31308 */  j          func_004f0ef0
    /* 3F10F4 004F10F4 1000BD27 */   addiu     $29, $29, 0x10
.size func_004f10e0, 0x18
