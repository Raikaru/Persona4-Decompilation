.section .text
.set noat
.set noreorder
glabel func_004cf050
    /* 3CF050 004CF050 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CF054 004CF054 0000BFFF */  sd         $31, 0x0($29)
    /* 3CF058 004CF058 0400848C */  lw         $4, 0x4($4)
    /* 3CF05C 004CF05C 0000BFDF */  ld         $31, 0x0($29)
    /* 3CF060 004CF060 4C0F1308 */  j          func_004c3d30
    /* 3CF064 004CF064 1000BD27 */   addiu     $29, $29, 0x10
.size func_004cf050, 0x18
