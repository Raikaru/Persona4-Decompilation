.section .text
.set noat
.set noreorder
glabel func_0042cdd0
    /* 32CDD0 0042CDD0 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 32CDD4 0042CDD4 0000B0FF */  sd         $16, 0x0($29)
    /* 32CDD8 0042CDD8 1000B1FF */  sd         $17, 0x10($29)
    /* 32CDDC 0042CDDC 2000BFFF */  sd         $31, 0x20($29)
    /* 32CDE0 0042CDE0 88AE100C */  jal        func_0042ba20
    /* 32CDE4 0042CDE4 2D808000 */   daddu     $16, $4, $0
    /* 32CDE8 0042CDE8 2D200002 */  daddu      $4, $16, $0
    /* 32CDEC 0042CDEC 44B3100C */  jal        func_0042cd10
    /* 32CDF0 0042CDF0 2D884000 */   daddu     $17, $2, $0
    /* 32CDF4 0042CDF4 03002012 */  beqz       $17, .L0042CE04
    /* 32CDF8 0042CDF8 2D804000 */   daddu     $16, $2, $0
    /* 32CDFC 0042CDFC 9CAE100C */  jal        func_0042ba70
    /* 32CE00 0042CE00 00000000 */   nop
  .L0042CE04:
    /* 32CE04 0042CE04 2D100002 */  daddu      $2, $16, $0
    /* 32CE08 0042CE08 2000BFDF */  ld         $31, 0x20($29)
    /* 32CE0C 0042CE0C 1000B1DF */  ld         $17, 0x10($29)
    /* 32CE10 0042CE10 0000B0DF */  ld         $16, 0x0($29)
    /* 32CE14 0042CE14 0800E003 */  jr         $31
    /* 32CE18 0042CE18 3000BD27 */   addiu     $29, $29, 0x30
    /* 32CE1C 0042CE1C 00000000 */  nop
.size func_0042cdd0, 0x50
