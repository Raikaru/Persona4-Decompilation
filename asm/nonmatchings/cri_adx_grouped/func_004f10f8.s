.section .text
.set noat
.set noreorder
glabel func_004f10f8
    /* 3F10F8 004F10F8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3F10FC 004F10FC 07000424 */  addiu      $4, $0, 0x7
    /* 3F1100 004F1100 0000BFFF */  sd         $31, 0x0($29)
    /* 3F1104 004F1104 0000BFDF */  ld         $31, 0x0($29)
    /* 3F1108 004F1108 BCC31308 */  j          func_004f0ef0
    /* 3F110C 004F110C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004f10f8, 0x18
