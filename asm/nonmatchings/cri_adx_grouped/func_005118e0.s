.section .text
.set noat
.set noreorder
glabel func_005118e0
    /* 4118E0 005118E0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 4118E4 005118E4 0000BFFF */  sd         $31, 0x0($29)
    /* 4118E8 005118E8 F42C140C */  jal        func_0050b3d0
    /* 4118EC 005118EC 00000000 */   nop
    /* 4118F0 005118F0 1000428C */  lw         $2, 0x10($2)
    /* 4118F4 005118F4 0000BFDF */  ld         $31, 0x0($29)
    /* 4118F8 005118F8 0800E003 */  jr         $31
    /* 4118FC 005118FC 1000BD27 */   addiu     $29, $29, 0x10
.size func_005118e0, 0x20
