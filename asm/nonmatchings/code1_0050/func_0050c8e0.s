.section .text
.set noat
.set noreorder
glabel func_0050c8e0
    /* 40C8E0 0050C8E0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40C8E4 0050C8E4 0000BFFF */  sd         $31, 0x0($29)
    /* 40C8E8 0050C8E8 3C00848C */  lw         $4, 0x3C($4)
    /* 40C8EC 0050C8EC 0000BFDF */  ld         $31, 0x0($29)
    /* 40C8F0 0050C8F0 7E4F1408 */  j          func_00513df8
    /* 40C8F4 0050C8F4 1000BD27 */   addiu     $29, $29, 0x10
.size func_0050c8e0, 0x18
