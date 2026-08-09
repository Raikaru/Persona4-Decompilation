.section .text
.set noat
.set noreorder
glabel func_004eb2d0
    /* 3EB2D0 004EB2D0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3EB2D4 004EB2D4 0000BFFF */  sd         $31, 0x0($29)
    /* 3EB2D8 004EB2D8 E800848C */  lw         $4, 0xE8($4)
    /* 3EB2DC 004EB2DC 0000BFDF */  ld         $31, 0x0($29)
    /* 3EB2E0 004EB2E0 96AB1308 */  j          func_004eae58
    /* 3EB2E4 004EB2E4 1000BD27 */   addiu     $29, $29, 0x10
.size func_004eb2d0, 0x18
