.section .text
.set noat
.set noreorder
glabel func_002b10a0
    /* 1B10A0 002B10A0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 1B10A4 002B10A4 0800A5FF */  sd         $5, 0x8($29)
    /* 1B10A8 002B10A8 3800848C */  lw         $4, 0x38($4)
    /* 1B10AC 002B10AC 0800A1C7 */  lwc1       $f1, 0x8($29)
    /* 1B10B0 002B10B0 0C00A0C7 */  lwc1       $f0, 0xC($29)
    /* 1B10B4 002B10B4 100081E4 */  swc1       $f1, 0x10($4)
    /* 1B10B8 002B10B8 140080E4 */  swc1       $f0, 0x14($4)
    /* 1B10BC 002B10BC 01000324 */  addiu      $3, $0, 0x1
    /* 1B10C0 002B10C0 5A0183A0 */  sb         $3, 0x15A($4)
    /* 1B10C4 002B10C4 1000BD27 */  addiu      $29, $29, 0x10
    /* 1B10C8 002B10C8 0800E003 */  jr         $31
    /* 1B10CC 002B10CC 00000000 */   nop
.size func_002b10a0, 0x30
