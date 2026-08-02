.section .text
.set noat
.set noreorder
glabel func_004abe60
    /* 3ABE60 004ABE60 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3ABE64 004ABE64 0000BFFF */  sd         $31, 0x0($29)
    /* 3ABE68 004ABE68 FC04120C */  jal        func_004813f0
    /* 3ABE6C 004ABE6C 00000000 */   nop
    /* 3ABE70 004ABE70 0000BFDF */  ld         $31, 0x0($29)
    /* 3ABE74 004ABE74 1000BD27 */  addiu      $29, $29, 0x10
    /* 3ABE78 004ABE78 0800E003 */  jr         $31
    /* 3ABE7C 004ABE7C 00000000 */   nop
.size func_004abe60, 0x20
