.section .text
.set noat
.set noreorder
glabel func_004d91f0
    /* 3D91F0 004D91F0 7200023C */  lui        $2, %hi(D_00725294)
    /* 3D91F4 004D91F4 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D91F8 004D91F8 9452448C */  lw         $4, %lo(D_00725294)($2)
    /* 3D91FC 004D91FC 0000BFFF */  sd         $31, 0x0($29)
    /* 3D9200 004D9200 8003130C */  jal        func_004c0e00
    /* 3D9204 004D9204 00000000 */   nop
    /* 3D9208 004D9208 0000BFDF */  ld         $31, 0x0($29)
    /* 3D920C 004D920C 2D204000 */  daddu      $4, $2, $0
    /* 3D9210 004D9210 06041308 */  j          func_004c1018
    /* 3D9214 004D9214 1000BD27 */   addiu     $29, $29, 0x10
.size func_004d91f0, 0x28
