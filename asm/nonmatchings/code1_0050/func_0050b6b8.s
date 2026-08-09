.section .text
.set noat
.set noreorder
glabel func_0050b6b8
    /* 40B6B8 0050B6B8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40B6BC 0050B6BC 0000B0FF */  sd         $16, 0x0($29)
    /* 40B6C0 0050B6C0 0800BFFF */  sd         $31, 0x8($29)
    /* 40B6C4 0050B6C4 F42C140C */  jal        func_0050b3d0
    /* 40B6C8 0050B6C8 2D808000 */   daddu     $16, $4, $0
    /* 40B6CC 0050B6CC 380050AC */  sw         $16, 0x38($2)
    /* 40B6D0 0050B6D0 0800BFDF */  ld         $31, 0x8($29)
    /* 40B6D4 0050B6D4 0000B0DF */  ld         $16, 0x0($29)
    /* 40B6D8 0050B6D8 0800E003 */  jr         $31
    /* 40B6DC 0050B6DC 1000BD27 */   addiu     $29, $29, 0x10
.size func_0050b6b8, 0x28
