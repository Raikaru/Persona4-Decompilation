.section .text
.set noat
.set noreorder
glabel func_0050c8b0
    /* 40C8B0 0050C8B0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40C8B4 0050C8B4 0000BFFF */  sd         $31, 0x0($29)
    /* 40C8B8 0050C8B8 3C00848C */  lw         $4, 0x3C($4)
    /* 40C8BC 0050C8BC 0000BFDF */  ld         $31, 0x0($29)
    /* 40C8C0 0050C8C0 C04F1408 */  j          func_00513f00
    /* 40C8C4 0050C8C4 1000BD27 */   addiu     $29, $29, 0x10
.size func_0050c8b0, 0x18
