.section .text
.set noat
.set noreorder
glabel func_005103f0
    /* 4103F0 005103F0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 4103F4 005103F4 0000BFFF */  sd         $31, 0x0($29)
    /* 4103F8 005103F8 4800848C */  lw         $4, 0x48($4)
    /* 4103FC 005103FC 0000BFDF */  ld         $31, 0x0($29)
    /* 410400 00510400 44A51308 */  j          func_004e9510
    /* 410404 00510404 1000BD27 */   addiu     $29, $29, 0x10
.size func_005103f0, 0x18
