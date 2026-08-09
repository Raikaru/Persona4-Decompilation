.section .text
.set noat
.set noreorder
glabel func_004d90f8
    /* 3D90F8 004D90F8 7200023C */  lui        $2, %hi(D_00725294)
    /* 3D90FC 004D90FC F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D9100 004D9100 9452448C */  lw         $4, %lo(D_00725294)($2)
    /* 3D9104 004D9104 0000BFFF */  sd         $31, 0x0($29)
    /* 3D9108 004D9108 8003130C */  jal        func_004c0e00
    /* 3D910C 004D910C 00000000 */   nop
    /* 3D9110 004D9110 0000BFDF */  ld         $31, 0x0($29)
    /* 3D9114 004D9114 2D204000 */  daddu      $4, $2, $0
    /* 3D9118 004D9118 F0031308 */  j          func_004c0fc0
    /* 3D911C 004D911C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004d90f8, 0x28
