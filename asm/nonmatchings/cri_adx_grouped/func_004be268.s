.section .text
.set noat
.set noreorder
glabel func_004be268
    /* 3BE268 004BE268 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3BE26C 004BE26C 0000BFFF */  sd         $31, 0x0($29)
    /* 3BE270 004BE270 0400848C */  lw         $4, 0x4($4)
    /* 3BE274 004BE274 0000BFDF */  ld         $31, 0x0($29)
    /* 3BE278 004BE278 D67A1308 */  j          func_004deb58
    /* 3BE27C 004BE27C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004be268, 0x18
