.section .text
.set noat
.set noreorder
glabel func_004d2f78
    /* 3D2F78 004D2F78 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D2F7C 004D2F7C 0000B0FF */  sd         $16, 0x0($29)
    /* 3D2F80 004D2F80 0800BFFF */  sd         $31, 0x8($29)
    /* 3D2F84 004D2F84 D888130C */  jal        func_004e2360
    /* 3D2F88 004D2F88 2D80A000 */   daddu     $16, $5, $0
    /* 3D2F8C 004D2F8C 000002AE */  sw         $2, 0x0($16)
    /* 3D2F90 004D2F90 01000224 */  addiu      $2, $0, 0x1
    /* 3D2F94 004D2F94 0000B0DF */  ld         $16, 0x0($29)
    /* 3D2F98 004D2F98 0800BFDF */  ld         $31, 0x8($29)
    /* 3D2F9C 004D2F9C 0800E003 */  jr         $31
    /* 3D2FA0 004D2FA0 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D2FA4 004D2FA4 00000000 */  nop
.size func_004d2f78, 0x30
