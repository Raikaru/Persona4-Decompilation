.section .text
.set noat
.set noreorder
glabel func_004eb2b0
    /* 3EB2B0 004EB2B0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3EB2B4 004EB2B4 002C0500 */  sll        $5, $5, 16
    /* 3EB2B8 004EB2B8 0000BFFF */  sd         $31, 0x0($29)
    /* 3EB2BC 004EB2BC 032C0500 */  sra        $5, $5, 16
    /* 3EB2C0 004EB2C0 E800848C */  lw         $4, 0xE8($4)
    /* 3EB2C4 004EB2C4 0000BFDF */  ld         $31, 0x0($29)
    /* 3EB2C8 004EB2C8 A2AA1308 */  j          func_004eaa88
    /* 3EB2CC 004EB2CC 1000BD27 */   addiu     $29, $29, 0x10
.size func_004eb2b0, 0x20
