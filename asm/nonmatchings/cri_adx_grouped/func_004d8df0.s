.section .text
.set noat
.set noreorder
glabel func_004d8df0
    /* 3D8DF0 004D8DF0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D8DF4 004D8DF4 0000BFFF */  sd         $31, 0x0($29)
    /* 3D8DF8 004D8DF8 0000BFDF */  ld         $31, 0x0($29)
    /* 3D8DFC 004D8DFC A0FB1208 */  j          func_004bee80
    /* 3D8E00 004D8E00 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D8E04 004D8E04 00000000 */  nop
.size func_004d8df0, 0x18
