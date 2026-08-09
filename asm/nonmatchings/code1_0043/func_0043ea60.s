.section .text
.set noat
.set noreorder
glabel func_0043ea60
    /* 33EA60 0043EA60 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 33EA64 0043EA64 0800B1FF */  sd         $17, 0x8($29)
    /* 33EA68 0043EA68 0000B0FF */  sd         $16, 0x0($29)
    /* 33EA6C 0043EA6C 1000B2FF */  sd         $18, 0x10($29)
    /* 33EA70 0043EA70 2D888000 */  daddu      $17, $4, $0
    /* 33EA74 0043EA74 1800B3FF */  sd         $19, 0x18($29)
    /* 33EA78 0043EA78 2D80C000 */  daddu      $16, $6, $0
    /* 33EA7C 0043EA7C 2000BFFF */  sd         $31, 0x20($29)
    /* 33EA80 0043EA80 2D20C000 */  daddu      $4, $6, $0
    /* 33EA84 0043EA84 1600C010 */  beqz       $6, .L0043EAE0
    /* 33EA88 0043EA88 2D90A000 */   daddu     $18, $5, $0
    /* 33EA8C 0043EA8C 7500133C */  lui        $19, %hi(D_00754F20)
    /* 33EA90 0043EA90 BA09110C */  jal        func_004426e8
    /* 33EA94 0043EA94 204F6526 */   addiu     $5, $19, %lo(D_00754F20)
    /* 33EA98 0043EA98 06004010 */  beqz       $2, .L0043EAB4
    /* 33EA9C 0043EA9C 2D200002 */   daddu     $4, $16, $0
    /* 33EAA0 0043EAA0 7500053C */  lui        $5, %hi(D_00754EE8)
    /* 33EAA4 0043EAA4 BA09110C */  jal        func_004426e8
    /* 33EAA8 0043EAA8 E84EA524 */   addiu     $5, $5, %lo(D_00754EE8)
    /* 33EAAC 0043EAAC 04004014 */  bnez       $2, .L0043EAC0
    /* 33EAB0 0043EAB0 2D780000 */   daddu     $15, $0, $0
  .L0043EAB4:
    /* 33EAB4 0043EAB4 340030AE */  sw         $16, 0x34($17)
    /* 33EAB8 0043EAB8 300032AE */  sw         $18, 0x30($17)
  .L0043EABC:
    /* 33EABC 0043EABC 204F6F26 */  addiu      $15, $19, %lo(D_00754F20)
  .L0043EAC0:
    /* 33EAC0 0043EAC0 0000B0DF */  ld         $16, 0x0($29)
    /* 33EAC4 0043EAC4 2D10E001 */  daddu      $2, $15, $0
    /* 33EAC8 0043EAC8 0800B1DF */  ld         $17, 0x8($29)
    /* 33EACC 0043EACC 1000B2DF */  ld         $18, 0x10($29)
    /* 33EAD0 0043EAD0 1800B3DF */  ld         $19, 0x18($29)
    /* 33EAD4 0043EAD4 2000BFDF */  ld         $31, 0x20($29)
    /* 33EAD8 0043EAD8 0800E003 */  jr         $31
    /* 33EADC 0043EADC 3000BD27 */   addiu     $29, $29, 0x30
  .L0043EAE0:
    /* 33EAE0 0043EAE0 F6FF0010 */  b          .L0043EABC
    /* 33EAE4 0043EAE4 7500133C */   lui       $19, %hi(D_00754F20)
.size func_0043ea60, 0x88
