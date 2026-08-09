.section .text
.set noat
.set noreorder
glabel func_004bdf10
    /* 3BDF10 004BDF10 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3BDF14 004BDF14 0000BFFF */  sd         $31, 0x0($29)
    /* 3BDF18 004BDF18 0400848C */  lw         $4, 0x4($4)
    /* 3BDF1C 004BDF1C 0000BFDF */  ld         $31, 0x0($29)
    /* 3BDF20 004BDF20 465B1308 */  j          func_004d6d18
    /* 3BDF24 004BDF24 1000BD27 */   addiu     $29, $29, 0x10
.size func_004bdf10, 0x18
