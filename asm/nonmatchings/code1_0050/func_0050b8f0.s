.section .text
.set noat
.set noreorder
glabel func_0050b8f0
    /* 40B8F0 0050B8F0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40B8F4 0050B8F4 0000B0FF */  sd         $16, 0x0($29)
    /* 40B8F8 0050B8F8 0800BFFF */  sd         $31, 0x8($29)
    /* 40B8FC 0050B8FC F42C140C */  jal        func_0050b3d0
    /* 40B900 0050B900 2D808000 */   daddu     $16, $4, $0
    /* 40B904 0050B904 680050AC */  sw         $16, 0x68($2)
    /* 40B908 0050B908 2D100002 */  daddu      $2, $16, $0
    /* 40B90C 0050B90C 0800BFDF */  ld         $31, 0x8($29)
    /* 40B910 0050B910 0000B0DF */  ld         $16, 0x0($29)
    /* 40B914 0050B914 0800E003 */  jr         $31
    /* 40B918 0050B918 1000BD27 */   addiu     $29, $29, 0x10
    /* 40B91C 0050B91C 00000000 */  nop
.size func_0050b8f0, 0x30
