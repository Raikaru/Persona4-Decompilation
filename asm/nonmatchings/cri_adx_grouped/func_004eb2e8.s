.section .text
.set noat
.set noreorder
glabel func_004eb2e8
    /* 3EB2E8 004EB2E8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3EB2EC 004EB2EC 0000BFFF */  sd         $31, 0x0($29)
    /* 3EB2F0 004EB2F0 E800848C */  lw         $4, 0xE8($4)
    /* 3EB2F4 004EB2F4 0000BFDF */  ld         $31, 0x0($29)
    /* 3EB2F8 004EB2F8 D6AB1308 */  j          func_004eaf58
    /* 3EB2FC 004EB2FC 1000BD27 */   addiu     $29, $29, 0x10
.size func_004eb2e8, 0x18
