.section .text
.set noat
.set noreorder
glabel func_005103c0
    /* 4103C0 005103C0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 4103C4 005103C4 0000BFFF */  sd         $31, 0x0($29)
    /* 4103C8 005103C8 4800848C */  lw         $4, 0x48($4)
    /* 4103CC 005103CC 0000BFDF */  ld         $31, 0x0($29)
    /* 4103D0 005103D0 08A51308 */  j          func_004e9420
    /* 4103D4 005103D4 1000BD27 */   addiu     $29, $29, 0x10
.size func_005103c0, 0x18
