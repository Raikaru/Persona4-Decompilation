.section .text
.set noat
.set noreorder
glabel func_004be2e8
    /* 3BE2E8 004BE2E8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3BE2EC 004BE2EC 0000BFFF */  sd         $31, 0x0($29)
    /* 3BE2F0 004BE2F0 0400848C */  lw         $4, 0x4($4)
    /* 3BE2F4 004BE2F4 0000BFDF */  ld         $31, 0x0($29)
    /* 3BE2F8 004BE2F8 BA7C1308 */  j          func_004df2e8
    /* 3BE2FC 004BE2FC 1000BD27 */   addiu     $29, $29, 0x10
.size func_004be2e8, 0x18
