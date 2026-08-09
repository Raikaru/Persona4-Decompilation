.section .text
.set noat
.set noreorder
glabel func_004d8830
    /* 3D8830 004D8830 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D8834 004D8834 7200043C */  lui        $4, %hi(D_00724ED0)
    /* 3D8838 004D8838 0000BFFF */  sd         $31, 0x0($29)
    /* 3D883C 004D883C 2D280000 */  daddu      $5, $0, $0
    /* 3D8840 004D8840 D04E8424 */  addiu      $4, $4, %lo(D_00724ED0)
    /* 3D8844 004D8844 C0030624 */  addiu      $6, $0, 0x3C0
    /* 3D8848 004D8848 0000BFDF */  ld         $31, 0x0($29)
    /* 3D884C 004D884C 72FE1008 */  j          func_0043f9c8
    /* 3D8850 004D8850 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D8854 004D8854 00000000 */  nop
.size func_004d8830, 0x28
