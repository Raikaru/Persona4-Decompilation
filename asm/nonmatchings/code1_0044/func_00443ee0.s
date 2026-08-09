.section .text
.set noat
.set noreorder
glabel func_00443ee0
    /* 343EE0 00443EE0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 343EE4 00443EE4 2D708000 */  daddu      $14, $4, $0
    /* 343EE8 00443EE8 71000F3C */  lui        $15, %hi(D_00710070)
    /* 343EEC 00443EEC 0000BFFF */  sd         $31, 0x0($29)
    /* 343EF0 00443EF0 2D30A000 */  daddu      $6, $5, $0
    /* 343EF4 00443EF4 7000E48D */  lw         $4, %lo(D_00710070)($15)
    /* 343EF8 00443EF8 1A0C110C */  jal        func_00443068
    /* 343EFC 00443EFC 2D28C001 */   daddu     $5, $14, $0
    /* 343F00 00443F00 F639110C */  jal        func_0044e7d8
    /* 343F04 00443F04 2D204000 */   daddu     $4, $2, $0
    /* 343F08 00443F08 0000BFDF */  ld         $31, 0x0($29)
    /* 343F0C 00443F0C 0800E003 */  jr         $31
    /* 343F10 00443F10 1000BD27 */   addiu     $29, $29, 0x10
    /* 343F14 00443F14 00000000 */  nop
.size func_00443ee0, 0x38
