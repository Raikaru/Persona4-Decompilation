.section .text
.set noat
.set noreorder
glabel func_0051a8b0
    /* 41A8B0 0051A8B0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 41A8B4 0051A8B4 0000BFFF */  sd         $31, 0x0($29)
    /* 41A8B8 0051A8B8 CC1F858C */  lw         $5, 0x1FCC($4)
    /* 41A8BC 0051A8BC 0000BFDF */  ld         $31, 0x0($29)
    /* 41A8C0 0051A8C0 68561408 */  j          func_005159a0
    /* 41A8C4 0051A8C4 1000BD27 */   addiu     $29, $29, 0x10
.size func_0051a8b0, 0x18
