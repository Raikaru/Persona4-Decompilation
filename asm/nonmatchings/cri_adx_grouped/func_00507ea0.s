.section .text
.set noat
.set noreorder
glabel func_00507ea0
    /* 407EA0 00507EA0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 407EA4 00507EA4 0000B0FF */  sd         $16, 0x0($29)
    /* 407EA8 00507EA8 2D808000 */  daddu      $16, $4, $0
    /* 407EAC 00507EAC 0800B1FF */  sd         $17, 0x8($29)
    /* 407EB0 00507EB0 1000BFFF */  sd         $31, 0x10($29)
    /* 407EB4 00507EB4 721F140C */  jal        func_00507dc8
    /* 407EB8 00507EB8 2D88A000 */   daddu     $17, $5, $0
    /* 407EBC 00507EBC 2D200002 */  daddu      $4, $16, $0
    /* 407EC0 00507EC0 C01F140C */  jal        func_00507f00
    /* 407EC4 00507EC4 2D282002 */   daddu     $5, $17, $0
    /* 407EC8 00507EC8 2D200002 */  daddu      $4, $16, $0
    /* 407ECC 00507ECC 06004014 */  bnez       $2, .L00507EE8
    /* 407ED0 00507ED0 2D282002 */   daddu     $5, $17, $0
    /* 407ED4 00507ED4 0000B0DF */  ld         $16, 0x0($29)
    /* 407ED8 00507ED8 0800B1DF */  ld         $17, 0x8($29)
    /* 407EDC 00507EDC 1000BFDF */  ld         $31, 0x10($29)
    /* 407EE0 00507EE0 861F1408 */  j          func_00507e18
    /* 407EE4 00507EE4 2000BD27 */   addiu     $29, $29, 0x20
  .L00507EE8:
    /* 407EE8 00507EE8 0000B0DF */  ld         $16, 0x0($29)
    /* 407EEC 00507EEC 0800B1DF */  ld         $17, 0x8($29)
    /* 407EF0 00507EF0 1000BFDF */  ld         $31, 0x10($29)
    /* 407EF4 00507EF4 0800E003 */  jr         $31
    /* 407EF8 00507EF8 2000BD27 */   addiu     $29, $29, 0x20
    /* 407EFC 00507EFC 00000000 */  nop
.size func_00507ea0, 0x60
