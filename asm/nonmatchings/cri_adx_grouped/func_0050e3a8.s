.section .text
.set noat
.set noreorder
glabel func_0050e3a8
    /* 40E3A8 0050E3A8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40E3AC 0050E3AC 0000BFFF */  sd         $31, 0x0($29)
    /* 40E3B0 0050E3B0 3C00848C */  lw         $4, 0x3C($4)
    /* 40E3B4 0050E3B4 0000BFDF */  ld         $31, 0x0($29)
    /* 40E3B8 0050E3B8 AE5F1408 */  j          func_00517eb8
    /* 40E3BC 0050E3BC 1000BD27 */   addiu     $29, $29, 0x10
.size func_0050e3a8, 0x18
