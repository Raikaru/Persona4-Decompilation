.section .text
.set noat
.set noreorder
glabel func_0042f6d0
    /* 32F6D0 0042F6D0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 32F6D4 0042F6D4 7500043C */  lui        $4, %hi(D_007546F0)
    /* 32F6D8 0042F6D8 0000BFFF */  sd         $31, 0x0($29)
    /* 32F6DC 0042F6DC 3291100C */  jal        func_004244c8
    /* 32F6E0 0042F6E0 F0468424 */   addiu     $4, $4, %lo(D_007546F0)
    /* 32F6E4 0042F6E4 0000BFDF */  ld         $31, 0x0($29)
    /* 32F6E8 0042F6E8 02000224 */  addiu      $2, $0, 0x2
    /* 32F6EC 0042F6EC 0800E003 */  jr         $31
    /* 32F6F0 0042F6F0 1000BD27 */   addiu     $29, $29, 0x10
    /* 32F6F4 0042F6F4 00000000 */  nop
.size func_0042f6d0, 0x28
