.section .text
.set noat
.set noreorder
glabel func_004f1098
    /* 3F1098 004F1098 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3F109C 004F109C 03000424 */  addiu      $4, $0, 0x3
    /* 3F10A0 004F10A0 0000BFFF */  sd         $31, 0x0($29)
    /* 3F10A4 004F10A4 0000BFDF */  ld         $31, 0x0($29)
    /* 3F10A8 004F10A8 BCC31308 */  j          func_004f0ef0
    /* 3F10AC 004F10AC 1000BD27 */   addiu     $29, $29, 0x10
.size func_004f1098, 0x18
