.section .text
.set noat
.set noreorder
glabel func_004d9218
    /* 3D9218 004D9218 7200023C */  lui        $2, %hi(D_00725294)
    /* 3D921C 004D921C F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D9220 004D9220 9452448C */  lw         $4, %lo(D_00725294)($2)
    /* 3D9224 004D9224 0000BFFF */  sd         $31, 0x0($29)
    /* 3D9228 004D9228 8003130C */  jal        func_004c0e00
    /* 3D922C 004D922C 00000000 */   nop
    /* 3D9230 004D9230 0000BFDF */  ld         $31, 0x0($29)
    /* 3D9234 004D9234 2D204000 */  daddu      $4, $2, $0
    /* 3D9238 004D9238 08041308 */  j          func_004c1020
    /* 3D923C 004D923C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004d9218, 0x28
