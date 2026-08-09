.section .text
.set noat
.set noreorder
glabel func_004d32e0
    /* 3D32E0 004D32E0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D32E4 004D32E4 2D20A000 */  daddu      $4, $5, $0
    /* 3D32E8 004D32E8 0000BFFF */  sd         $31, 0x0($29)
    /* 3D32EC 004D32EC 0000BFDF */  ld         $31, 0x0($29)
    /* 3D32F0 004D32F0 A61A1308 */  j          func_004c6a98
    /* 3D32F4 004D32F4 1000BD27 */   addiu     $29, $29, 0x10
.size func_004d32e0, 0x18
