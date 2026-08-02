.section .text
.set noat
.set noreorder
glabel func_0011e390
    /* 1E390 0011E390 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 1E394 0011E394 0800A5FF */  sd         $5, 0x8($29)
    /* 1E398 0011E398 3800838C */  lw         $3, 0x38($4)
    /* 1E39C 0011E39C 0800A0C7 */  lwc1       $f0, 0x8($29)
    /* 1E3A0 0011E3A0 380060E4 */  swc1       $f0, 0x38($3)
    /* 1E3A4 0011E3A4 0C00A0C7 */  lwc1       $f0, 0xC($29)
    /* 1E3A8 0011E3A8 3C0060E4 */  swc1       $f0, 0x3C($3)
    /* 1E3AC 0011E3AC 1000BD27 */  addiu      $29, $29, 0x10
    /* 1E3B0 0011E3B0 0800E003 */  jr         $31
    /* 1E3B4 0011E3B4 00000000 */   nop
    /* 1E3B8 0011E3B8 00000000 */  nop
    /* 1E3BC 0011E3BC 00000000 */  nop
.size func_0011e390, 0x30
