.section .text
.set noat
.set noreorder
glabel func_005103d8
    /* 4103D8 005103D8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 4103DC 005103DC 0000BFFF */  sd         $31, 0x0($29)
    /* 4103E0 005103E0 4800848C */  lw         $4, 0x48($4)
    /* 4103E4 005103E4 0000BFDF */  ld         $31, 0x0($29)
    /* 4103E8 005103E8 20A51308 */  j          func_004e9480
    /* 4103EC 005103EC 1000BD27 */   addiu     $29, $29, 0x10
.size func_005103d8, 0x18
