.section .text
.set noat
.set noreorder
glabel func_0050f918
    /* 40F918 0050F918 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40F91C 0050F91C 0000BFFF */  sd         $31, 0x0($29)
    /* 40F920 0050F920 A800848C */  lw         $4, 0xA8($4)
    /* 40F924 0050F924 0000BFDF */  ld         $31, 0x0($29)
    /* 40F928 0050F928 30AF1408 */  j          func_0052bcc0
    /* 40F92C 0050F92C 1000BD27 */   addiu     $29, $29, 0x10
.size func_0050f918, 0x18
