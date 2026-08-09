.section .text
.set noat
.set noreorder
glabel func_00513290
    /* 413290 00513290 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 413294 00513294 0000BFFF */  sd         $31, 0x0($29)
    /* 413298 00513298 1020858C */  lw         $5, 0x2010($4)
    /* 41329C 0051329C 0000BFDF */  ld         $31, 0x0($29)
    /* 4132A0 005132A0 68561408 */  j          func_005159a0
    /* 4132A4 005132A4 1000BD27 */   addiu     $29, $29, 0x10
.size func_00513290, 0x18
