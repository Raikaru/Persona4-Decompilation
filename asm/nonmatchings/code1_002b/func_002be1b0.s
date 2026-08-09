.section .text
.set noat
.set noreorder
glabel func_002be1b0
    /* 1BE1B0 002BE1B0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 1BE1B4 002BE1B4 0000BFFF */  sd         $31, 0x0($29)
    /* 1BE1B8 002BE1B8 201A040C */  jal        func_00106880
    /* 1BE1BC 002BE1BC 00000000 */   nop
    /* 1BE1C0 002BE1C0 2D204000 */  daddu      $4, $2, $0
    /* 1BE1C4 002BE1C4 78F80A0C */  jal        func_002be1e0
    /* 1BE1C8 002BE1C8 00000000 */   nop
    /* 1BE1CC 002BE1CC 0000BFDF */  ld         $31, 0x0($29)
    /* 1BE1D0 002BE1D0 1000BD27 */  addiu      $29, $29, 0x10
    /* 1BE1D4 002BE1D4 0800E003 */  jr         $31
    /* 1BE1D8 002BE1D8 00000000 */   nop
    /* 1BE1DC 002BE1DC 00000000 */  nop
.size func_002be1b0, 0x30
