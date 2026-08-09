.section .text
.set noat
.set noreorder
glabel func_00410ed0
    /* 310ED0 00410ED0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 310ED4 00410ED4 1000BFFF */  sd         $31, 0x10($29)
    /* 310ED8 00410ED8 0000B07F */  sq         $16, 0x0($29)
    /* 310EDC 00410EDC B8B985AF */  sw         $5, -0x4648($28)
    /* 310EE0 00410EE0 1844100C */  jal        func_00411060
    /* 310EE4 00410EE4 2D808000 */   daddu     $16, $4, $0
    /* 310EE8 00410EE8 0A800200 */  movz       $16, $0, $2
    /* 310EEC 00410EEC 2D100002 */  daddu      $2, $16, $0
    /* 310EF0 00410EF0 1000BFDF */  ld         $31, 0x10($29)
    /* 310EF4 00410EF4 0000B07B */  lq         $16, 0x0($29)
    /* 310EF8 00410EF8 0800E003 */  jr         $31
    /* 310EFC 00410EFC 2000BD27 */   addiu     $29, $29, 0x20
.size func_00410ed0, 0x30
