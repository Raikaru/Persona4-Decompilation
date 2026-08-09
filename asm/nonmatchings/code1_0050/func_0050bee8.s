.section .text
.set noat
.set noreorder
glabel func_0050bee8
    /* 40BEE8 0050BEE8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40BEEC 0050BEEC 0000BFFF */  sd         $31, 0x0($29)
    /* 40BEF0 0050BEF0 3C00848C */  lw         $4, 0x3C($4)
    /* 40BEF4 0050BEF4 0000BFDF */  ld         $31, 0x0($29)
    /* 40BEF8 0050BEF8 7E8D1408 */  j          func_005235f8
    /* 40BEFC 0050BEFC 1000BD27 */   addiu     $29, $29, 0x10
.size func_0050bee8, 0x18
