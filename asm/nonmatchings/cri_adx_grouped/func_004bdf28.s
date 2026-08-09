.section .text
.set noat
.set noreorder
glabel func_004bdf28
    /* 3BDF28 004BDF28 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3BDF2C 004BDF2C 0000BFFF */  sd         $31, 0x0($29)
    /* 3BDF30 004BDF30 0400848C */  lw         $4, 0x4($4)
    /* 3BDF34 004BDF34 0000BFDF */  ld         $31, 0x0($29)
    /* 3BDF38 004BDF38 0C5C1308 */  j          func_004d7030
    /* 3BDF3C 004BDF3C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004bdf28, 0x18
