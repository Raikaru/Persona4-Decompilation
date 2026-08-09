.section .text
.set noat
.set noreorder
glabel func_0050f930
    /* 40F930 0050F930 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40F934 0050F934 0000BFFF */  sd         $31, 0x0($29)
    /* 40F938 0050F938 A800848C */  lw         $4, 0xA8($4)
    /* 40F93C 0050F93C 0000BFDF */  ld         $31, 0x0($29)
    /* 40F940 0050F940 32AF1408 */  j          func_0052bcc8
    /* 40F944 0050F944 1000BD27 */   addiu     $29, $29, 0x10
.size func_0050f930, 0x18
