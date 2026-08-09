.section .text
.set noat
.set noreorder
glabel func_004d8808
    /* 3D8808 004D8808 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D880C 004D880C 7200043C */  lui        $4, %hi(D_00724ED0)
    /* 3D8810 004D8810 0000BFFF */  sd         $31, 0x0($29)
    /* 3D8814 004D8814 2D280000 */  daddu      $5, $0, $0
    /* 3D8818 004D8818 D04E8424 */  addiu      $4, $4, %lo(D_00724ED0)
    /* 3D881C 004D881C C0030624 */  addiu      $6, $0, 0x3C0
    /* 3D8820 004D8820 0000BFDF */  ld         $31, 0x0($29)
    /* 3D8824 004D8824 72FE1008 */  j          func_0043f9c8
    /* 3D8828 004D8828 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D882C 004D882C 00000000 */  nop
.size func_004d8808, 0x28
