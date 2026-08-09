.section .text
.set noat
.set noreorder
glabel func_004d9120
    /* 3D9120 004D9120 7200023C */  lui        $2, %hi(D_00725294)
    /* 3D9124 004D9124 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D9128 004D9128 9452448C */  lw         $4, %lo(D_00725294)($2)
    /* 3D912C 004D912C 0000BFFF */  sd         $31, 0x0($29)
    /* 3D9130 004D9130 8003130C */  jal        func_004c0e00
    /* 3D9134 004D9134 00000000 */   nop
    /* 3D9138 004D9138 0000BFDF */  ld         $31, 0x0($29)
    /* 3D913C 004D913C 2D204000 */  daddu      $4, $2, $0
    /* 3D9140 004D9140 F4031308 */  j          func_004c0fd0
    /* 3D9144 004D9144 1000BD27 */   addiu     $29, $29, 0x10
.size func_004d9120, 0x28
