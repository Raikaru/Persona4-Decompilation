.section .text
.set noat
.set noreorder
glabel func_0050fca8
    /* 40FCA8 0050FCA8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40FCAC 0050FCAC 0000BFFF */  sd         $31, 0x0($29)
    /* 40FCB0 0050FCB0 A800848C */  lw         $4, 0xA8($4)
    /* 40FCB4 0050FCB4 0000BFDF */  ld         $31, 0x0($29)
    /* 40FCB8 0050FCB8 54AB1408 */  j          func_0052ad50
    /* 40FCBC 0050FCBC 1000BD27 */   addiu     $29, $29, 0x10
.size func_0050fca8, 0x18
