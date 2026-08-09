.section .text
.set noat
.set noreorder
glabel func_004f10b0
    /* 3F10B0 004F10B0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3F10B4 004F10B4 04000424 */  addiu      $4, $0, 0x4
    /* 3F10B8 004F10B8 0000BFFF */  sd         $31, 0x0($29)
    /* 3F10BC 004F10BC 0000BFDF */  ld         $31, 0x0($29)
    /* 3F10C0 004F10C0 BCC31308 */  j          func_004f0ef0
    /* 3F10C4 004F10C4 1000BD27 */   addiu     $29, $29, 0x10
.size func_004f10b0, 0x18
