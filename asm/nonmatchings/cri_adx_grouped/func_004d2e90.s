.section .text
.set noat
.set noreorder
glabel func_004d2e90
    /* 3D2E90 004D2E90 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3D2E94 004D2E94 0000B0FF */  sd         $16, 0x0($29)
    /* 3D2E98 004D2E98 2D808000 */  daddu      $16, $4, $0
    /* 3D2E9C 004D2E9C 0800B1FF */  sd         $17, 0x8($29)
    /* 3D2EA0 004D2EA0 1000BFFF */  sd         $31, 0x10($29)
    /* 3D2EA4 004D2EA4 3246130C */  jal        func_004d18c8
    /* 3D2EA8 004D2EA8 2D88A000 */   daddu     $17, $5, $0
    /* 3D2EAC 004D2EAC 2D200002 */  daddu      $4, $16, $0
    /* 3D2EB0 004D2EB0 B64B130C */  jal        func_004d2ed8
    /* 3D2EB4 004D2EB4 2D282002 */   daddu     $5, $17, $0
    /* 3D2EB8 004D2EB8 3446130C */  jal        func_004d18d0
    /* 3D2EBC 004D2EBC 2D804000 */   daddu     $16, $2, $0
    /* 3D2EC0 004D2EC0 0800B1DF */  ld         $17, 0x8($29)
    /* 3D2EC4 004D2EC4 2D100002 */  daddu      $2, $16, $0
    /* 3D2EC8 004D2EC8 1000BFDF */  ld         $31, 0x10($29)
    /* 3D2ECC 004D2ECC 0000B0DF */  ld         $16, 0x0($29)
    /* 3D2ED0 004D2ED0 0800E003 */  jr         $31
    /* 3D2ED4 004D2ED4 2000BD27 */   addiu     $29, $29, 0x20
.size func_004d2e90, 0x48
