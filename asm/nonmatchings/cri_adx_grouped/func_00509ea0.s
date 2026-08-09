.section .text
.set noat
.set noreorder
glabel func_00509ea0
    /* 409EA0 00509EA0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 409EA4 00509EA4 0800B1FF */  sd         $17, 0x8($29)
    /* 409EA8 00509EA8 2D888000 */  daddu      $17, $4, $0
    /* 409EAC 00509EAC 1800BFFF */  sd         $31, 0x18($29)
    /* 409EB0 00509EB0 0000B0FF */  sd         $16, 0x0($29)
    /* 409EB4 00509EB4 7C023026 */  addiu      $16, $17, 0x27C
    /* 409EB8 00509EB8 1000B2FF */  sd         $18, 0x10($29)
    /* 409EBC 00509EBC 1F001224 */  addiu      $18, $0, 0x1F
  .L00509EC0:
    /* 409EC0 00509EC0 0000058E */  lw         $5, 0x0($16)
    /* 409EC4 00509EC4 0500A050 */  beql       $5, $0, .L00509EDC
    /* 409EC8 00509EC8 FFFF5226 */   addiu     $18, $18, -0x1
    /* 409ECC 00509ECC 8427140C */  jal        func_00509e10
    /* 409ED0 00509ED0 2D202002 */   daddu     $4, $17, $0
    /* 409ED4 00509ED4 000000AE */  sw         $0, 0x0($16)
    /* 409ED8 00509ED8 FFFF5226 */  addiu      $18, $18, -0x1
  .L00509EDC:
    /* 409EDC 00509EDC F8FF4106 */  bgez       $18, .L00509EC0
    /* 409EE0 00509EE0 FCFF1026 */   addiu     $16, $16, -0x4
    /* 409EE4 00509EE4 0000B0DF */  ld         $16, 0x0($29)
    /* 409EE8 00509EE8 0800B1DF */  ld         $17, 0x8($29)
    /* 409EEC 00509EEC 1000B2DF */  ld         $18, 0x10($29)
    /* 409EF0 00509EF0 1800BFDF */  ld         $31, 0x18($29)
    /* 409EF4 00509EF4 0800E003 */  jr         $31
    /* 409EF8 00509EF8 2000BD27 */   addiu     $29, $29, 0x20
    /* 409EFC 00509EFC 00000000 */  nop
.size func_00509ea0, 0x60
