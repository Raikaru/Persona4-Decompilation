.section .text
.set noat
.set noreorder
glabel func_004bdf70
    /* 3BDF70 004BDF70 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3BDF74 004BDF74 0000BFFF */  sd         $31, 0x0($29)
    /* 3BDF78 004BDF78 0400848C */  lw         $4, 0x4($4)
    /* 3BDF7C 004BDF7C 0000BFDF */  ld         $31, 0x0($29)
    /* 3BDF80 004BDF80 14581308 */  j          func_004d6050
    /* 3BDF84 004BDF84 1000BD27 */   addiu     $29, $29, 0x10
.size func_004bdf70, 0x18
