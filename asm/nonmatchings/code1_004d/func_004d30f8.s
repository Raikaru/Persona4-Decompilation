.section .text
.set noat
.set noreorder
glabel func_004d30f8
    /* 3D30F8 004D30F8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D30FC 004D30FC 0000BFFF */  sd         $31, 0x0($29)
    /* 3D3100 004D3100 0C0085AC */  sw         $5, 0xC($4)
    /* 3D3104 004D3104 2D280000 */  daddu      $5, $0, $0
    /* 3D3108 004D3108 0000BFDF */  ld         $31, 0x0($29)
    /* 3D310C 004D310C 0E481308 */  j          func_004d2038
    /* 3D3110 004D3110 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D3114 004D3114 00000000 */  nop
.size func_004d30f8, 0x20
