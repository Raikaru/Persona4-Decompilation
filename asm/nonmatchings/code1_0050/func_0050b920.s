.section .text
.set noat
.set noreorder
glabel func_0050b920
    /* 40B920 0050B920 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40B924 0050B924 0000BFFF */  sd         $31, 0x0($29)
    /* 40B928 0050B928 F42C140C */  jal        func_0050b3d0
    /* 40B92C 0050B92C 00000000 */   nop
    /* 40B930 0050B930 6800428C */  lw         $2, 0x68($2)
    /* 40B934 0050B934 0000BFDF */  ld         $31, 0x0($29)
    /* 40B938 0050B938 0800E003 */  jr         $31
    /* 40B93C 0050B93C 1000BD27 */   addiu     $29, $29, 0x10
.size func_0050b920, 0x20
