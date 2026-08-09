.section .text
.set noat
.set noreorder
glabel func_0050fc48
    /* 40FC48 0050FC48 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40FC4C 0050FC4C 0000BFFF */  sd         $31, 0x0($29)
    /* 40FC50 0050FC50 A800848C */  lw         $4, 0xA8($4)
    /* 40FC54 0050FC54 0000BFDF */  ld         $31, 0x0($29)
    /* 40FC58 0050FC58 46AB1408 */  j          func_0052ad18
    /* 40FC5C 0050FC5C 1000BD27 */   addiu     $29, $29, 0x10
.size func_0050fc48, 0x18
