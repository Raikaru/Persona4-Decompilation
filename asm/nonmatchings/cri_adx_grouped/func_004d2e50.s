.section .text
.set noat
.set noreorder
glabel func_004d2e50
    /* 3D2E50 004D2E50 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D2E54 004D2E54 0000B0FF */  sd         $16, 0x0($29)
    /* 3D2E58 004D2E58 2D80A000 */  daddu      $16, $5, $0
    /* 3D2E5C 004D2E5C 0800BFFF */  sd         $31, 0x8($29)
    /* 3D2E60 004D2E60 BE88130C */  jal        func_004e22f8
    /* 3D2E64 004D2E64 0800848C */   lw        $4, 0x8($4)
    /* 3D2E68 004D2E68 000002AE */  sw         $2, 0x0($16)
    /* 3D2E6C 004D2E6C 0800BFDF */  ld         $31, 0x8($29)
    /* 3D2E70 004D2E70 0000B0DF */  ld         $16, 0x0($29)
    /* 3D2E74 004D2E74 0800E003 */  jr         $31
    /* 3D2E78 004D2E78 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D2E7C 004D2E7C 00000000 */  nop
.size func_004d2e50, 0x30
