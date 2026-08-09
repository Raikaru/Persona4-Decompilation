.section .text
.set noat
.set noreorder
glabel func_004eb298
    /* 3EB298 004EB298 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3EB29C 004EB29C 0000BFFF */  sd         $31, 0x0($29)
    /* 3EB2A0 004EB2A0 E800848C */  lw         $4, 0xE8($4)
    /* 3EB2A4 004EB2A4 0000BFDF */  ld         $31, 0x0($29)
    /* 3EB2A8 004EB2A8 86AA1308 */  j          func_004eaa18
    /* 3EB2AC 004EB2AC 1000BD27 */   addiu     $29, $29, 0x10
.size func_004eb298, 0x18
