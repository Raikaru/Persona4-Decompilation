.section .text
.set noat
.set noreorder
glabel func_00509cb8
    /* 409CB8 00509CB8 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 409CBC 00509CBC 0000B0FF */  sd         $16, 0x0($29)
    /* 409CC0 00509CC0 2D80C000 */  daddu      $16, $6, $0
    /* 409CC4 00509CC4 0800B1FF */  sd         $17, 0x8($29)
    /* 409CC8 00509CC8 2D888000 */  daddu      $17, $4, $0
    /* 409CCC 00509CCC 1000B2FF */  sd         $18, 0x10($29)
    /* 409CD0 00509CD0 1800BFFF */  sd         $31, 0x18($29)
    /* 409CD4 00509CD4 F42C140C */  jal        func_0050b3d0
    /* 409CD8 00509CD8 2D90A000 */   daddu     $18, $5, $0
    /* 409CDC 00509CDC 300050AC */  sw         $16, 0x30($2)
    /* 409CE0 00509CE0 280051AC */  sw         $17, 0x28($2)
    /* 409CE4 00509CE4 2C0052AC */  sw         $18, 0x2C($2)
    /* 409CE8 00509CE8 0000B0DF */  ld         $16, 0x0($29)
    /* 409CEC 00509CEC 0800B1DF */  ld         $17, 0x8($29)
    /* 409CF0 00509CF0 1000B2DF */  ld         $18, 0x10($29)
    /* 409CF4 00509CF4 1800BFDF */  ld         $31, 0x18($29)
    /* 409CF8 00509CF8 0800E003 */  jr         $31
    /* 409CFC 00509CFC 2000BD27 */   addiu     $29, $29, 0x20
.size func_00509cb8, 0x48
