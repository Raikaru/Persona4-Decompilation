.section .text
.set noat
.set noreorder
glabel func_004d9268
    /* 3D9268 004D9268 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D926C 004D926C 7200023C */  lui        $2, %hi(D_00725294)
    /* 3D9270 004D9270 0000BFFF */  sd         $31, 0x0($29)
    /* 3D9274 004D9274 9452448C */  lw         $4, %lo(D_00725294)($2)
    /* 3D9278 004D9278 0000BFDF */  ld         $31, 0x0($29)
    /* 3D927C 004D927C 38031308 */  j          func_004c0ce0
    /* 3D9280 004D9280 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D9284 004D9284 00000000 */  nop
.size func_004d9268, 0x20
