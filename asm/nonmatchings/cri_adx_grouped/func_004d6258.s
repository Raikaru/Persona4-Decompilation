.section .text
.set noat
.set noreorder
glabel func_004d6258
    /* 3D6258 004D6258 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D625C 004D625C 0000BFFF */  sd         $31, 0x0($29)
    /* 3D6260 004D6260 0000BFDF */  ld         $31, 0x0($29)
    /* 3D6264 004D6264 46361308 */  j          func_004cd918
    /* 3D6268 004D6268 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D626C 004D626C 00000000 */  nop
.size func_004d6258, 0x18
