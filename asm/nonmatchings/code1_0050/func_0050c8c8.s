.section .text
.set noat
.set noreorder
glabel func_0050c8c8
    /* 40C8C8 0050C8C8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40C8CC 0050C8CC 0000BFFF */  sd         $31, 0x0($29)
    /* 40C8D0 0050C8D0 3C00848C */  lw         $4, 0x3C($4)
    /* 40C8D4 0050C8D4 0000BFDF */  ld         $31, 0x0($29)
    /* 40C8D8 0050C8D8 E04F1408 */  j          func_00513f80
    /* 40C8DC 0050C8DC 1000BD27 */   addiu     $29, $29, 0x10
.size func_0050c8c8, 0x18
