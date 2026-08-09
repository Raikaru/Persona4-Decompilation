.section .text
.set noat
.set noreorder
glabel func_0050bcb0
    /* 40BCB0 0050BCB0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40BCB4 0050BCB4 0000B0FF */  sd         $16, 0x0($29)
    /* 40BCB8 0050BCB8 0800BFFF */  sd         $31, 0x8($29)
    /* 40BCBC 0050BCBC F42C140C */  jal        func_0050b3d0
    /* 40BCC0 0050BCC0 2D808000 */   daddu     $16, $4, $0
    /* 40BCC4 0050BCC4 340050AC */  sw         $16, 0x34($2)
    /* 40BCC8 0050BCC8 0800BFDF */  ld         $31, 0x8($29)
    /* 40BCCC 0050BCCC 0000B0DF */  ld         $16, 0x0($29)
    /* 40BCD0 0050BCD0 0800E003 */  jr         $31
    /* 40BCD4 0050BCD4 1000BD27 */   addiu     $29, $29, 0x10
.size func_0050bcb0, 0x28
