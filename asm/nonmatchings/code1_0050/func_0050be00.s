.section .text
.set noat
.set noreorder
glabel func_0050be00
    /* 40BE00 0050BE00 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 40BE04 0050BE04 2000B0FF */  sd         $16, 0x20($29)
    /* 40BE08 0050BE08 2D80C000 */  daddu      $16, $6, $0
    /* 40BE0C 0050BE0C 2800B1FF */  sd         $17, 0x28($29)
    /* 40BE10 0050BE10 2D88E000 */  daddu      $17, $7, $0
    /* 40BE14 0050BE14 3000B2FF */  sd         $18, 0x30($29)
    /* 40BE18 0050BE18 2D90A000 */  daddu      $18, $5, $0
    /* 40BE1C 0050BE1C 3800BFFF */  sd         $31, 0x38($29)
    /* 40BE20 0050BE20 2D28A003 */  daddu      $5, $29, $0
    /* 40BE24 0050BE24 428D140C */  jal        func_00523508
    /* 40BE28 0050BE28 3C00848C */   lw        $4, 0x3C($4)
    /* 40BE2C 0050BE2C 0000A48F */  lw         $4, 0x0($29)
    /* 40BE30 0050BE30 0400A28F */  lw         $2, 0x4($29)
    /* 40BE34 0050BE34 1400A38F */  lw         $3, 0x14($29)
    /* 40BE38 0050BE38 000002AE */  sw         $2, 0x0($16)
    /* 40BE3C 0050BE3C 000044AE */  sw         $4, 0x0($18)
    /* 40BE40 0050BE40 000023AE */  sw         $3, 0x0($17)
    /* 40BE44 0050BE44 2000B0DF */  ld         $16, 0x20($29)
    /* 40BE48 0050BE48 2800B1DF */  ld         $17, 0x28($29)
    /* 40BE4C 0050BE4C 3000B2DF */  ld         $18, 0x30($29)
    /* 40BE50 0050BE50 3800BFDF */  ld         $31, 0x38($29)
    /* 40BE54 0050BE54 0800E003 */  jr         $31
    /* 40BE58 0050BE58 4000BD27 */   addiu     $29, $29, 0x40
    /* 40BE5C 0050BE5C 00000000 */  nop
.size func_0050be00, 0x60
