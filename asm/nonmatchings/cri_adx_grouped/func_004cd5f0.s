.section .text
.set noat
.set noreorder
glabel func_004cd5f0
    /* 3CD5F0 004CD5F0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CD5F4 004CD5F4 0000BFFF */  sd         $31, 0x0($29)
    /* 3CD5F8 004CD5F8 0C00848C */  lw         $4, 0xC($4)
    /* 3CD5FC 004CD5FC 0000BFDF */  ld         $31, 0x0($29)
    /* 3CD600 004CD600 78B01308 */  j          func_004ec1e0
    /* 3CD604 004CD604 1000BD27 */   addiu     $29, $29, 0x10
.size func_004cd5f0, 0x18
