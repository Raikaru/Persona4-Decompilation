.section .text
.set noat
.set noreorder
glabel func_004ccd90
    /* 3CCD90 004CCD90 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CCD94 004CCD94 0000BFFF */  sd         $31, 0x0($29)
    /* 3CCD98 004CCD98 0000BFDF */  ld         $31, 0x0($29)
    /* 3CCD9C 004CCD9C FE301308 */  j          func_004cc3f8
    /* 3CCDA0 004CCDA0 1000BD27 */   addiu     $29, $29, 0x10
    /* 3CCDA4 004CCDA4 00000000 */  nop
.size func_004ccd90, 0x18
