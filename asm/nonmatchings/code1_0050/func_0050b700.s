.section .text
.set noat
.set noreorder
glabel func_0050b700
    /* 40B700 0050B700 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40B704 0050B704 0000B0FF */  sd         $16, 0x0($29)
    /* 40B708 0050B708 0800BFFF */  sd         $31, 0x8($29)
    /* 40B70C 0050B70C F42C140C */  jal        func_0050b3d0
    /* 40B710 0050B710 2D808000 */   daddu     $16, $4, $0
    /* 40B714 0050B714 3C0050AC */  sw         $16, 0x3C($2)
    /* 40B718 0050B718 0800BFDF */  ld         $31, 0x8($29)
    /* 40B71C 0050B71C 0000B0DF */  ld         $16, 0x0($29)
    /* 40B720 0050B720 0800E003 */  jr         $31
    /* 40B724 0050B724 1000BD27 */   addiu     $29, $29, 0x10
.size func_0050b700, 0x28
