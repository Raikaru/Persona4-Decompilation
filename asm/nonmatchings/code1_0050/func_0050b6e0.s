.section .text
.set noat
.set noreorder
glabel func_0050b6e0
    /* 40B6E0 0050B6E0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40B6E4 0050B6E4 0000BFFF */  sd         $31, 0x0($29)
    /* 40B6E8 0050B6E8 F42C140C */  jal        func_0050b3d0
    /* 40B6EC 0050B6EC 00000000 */   nop
    /* 40B6F0 0050B6F0 3800428C */  lw         $2, 0x38($2)
    /* 40B6F4 0050B6F4 0000BFDF */  ld         $31, 0x0($29)
    /* 40B6F8 0050B6F8 0800E003 */  jr         $31
    /* 40B6FC 0050B6FC 1000BD27 */   addiu     $29, $29, 0x10
.size func_0050b6e0, 0x20
