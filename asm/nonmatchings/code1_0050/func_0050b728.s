.section .text
.set noat
.set noreorder
glabel func_0050b728
    /* 40B728 0050B728 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40B72C 0050B72C 0000BFFF */  sd         $31, 0x0($29)
    /* 40B730 0050B730 F42C140C */  jal        func_0050b3d0
    /* 40B734 0050B734 00000000 */   nop
    /* 40B738 0050B738 3C00428C */  lw         $2, 0x3C($2)
    /* 40B73C 0050B73C 0000BFDF */  ld         $31, 0x0($29)
    /* 40B740 0050B740 0800E003 */  jr         $31
    /* 40B744 0050B744 1000BD27 */   addiu     $29, $29, 0x10
.size func_0050b728, 0x20
