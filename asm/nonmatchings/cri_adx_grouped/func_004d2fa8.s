.section .text
.set noat
.set noreorder
glabel func_004d2fa8
    /* 3D2FA8 004D2FA8 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3D2FAC 004D2FAC 0000B0FF */  sd         $16, 0x0($29)
    /* 3D2FB0 004D2FB0 2D808000 */  daddu      $16, $4, $0
    /* 3D2FB4 004D2FB4 0800B1FF */  sd         $17, 0x8($29)
    /* 3D2FB8 004D2FB8 1000BFFF */  sd         $31, 0x10($29)
    /* 3D2FBC 004D2FBC 3246130C */  jal        func_004d18c8
    /* 3D2FC0 004D2FC0 2D88A000 */   daddu     $17, $5, $0
    /* 3D2FC4 004D2FC4 2D200002 */  daddu      $4, $16, $0
    /* 3D2FC8 004D2FC8 FA4B130C */  jal        func_004d2fe8
    /* 3D2FCC 004D2FCC 2D282002 */   daddu     $5, $17, $0
    /* 3D2FD0 004D2FD0 0000B0DF */  ld         $16, 0x0($29)
    /* 3D2FD4 004D2FD4 0800B1DF */  ld         $17, 0x8($29)
    /* 3D2FD8 004D2FD8 1000BFDF */  ld         $31, 0x10($29)
    /* 3D2FDC 004D2FDC 34461308 */  j          func_004d18d0
    /* 3D2FE0 004D2FE0 2000BD27 */   addiu     $29, $29, 0x20
    /* 3D2FE4 004D2FE4 00000000 */  nop
.size func_004d2fa8, 0x40
