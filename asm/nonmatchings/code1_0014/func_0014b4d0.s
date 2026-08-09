.section .text
.set noat
.set noreorder
glabel func_0014b4d0
    /* 4B4D0 0014B4D0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 4B4D4 0014B4D4 0000BFFF */  sd         $31, 0x0($29)
    /* 4B4D8 0014B4D8 14000424 */  addiu      $4, $0, 0x14
    /* 4B4DC 0014B4DC AC14050C */  jal        func_001452b0
    /* 4B4E0 0014B4E0 00000000 */   nop
    /* 4B4E4 0014B4E4 00008044 */  mtc1       $0, $f0
    /* 4B4E8 0014B4E8 02004010 */  beqz       $2, .L0014B4F4
    /* 4B4EC 0014B4EC 00000000 */   nop
    /* 4B4F0 0014B4F0 440140C4 */  lwc1       $f0, 0x144($2)
  .L0014B4F4:
    /* 4B4F4 0014B4F4 0000BFDF */  ld         $31, 0x0($29)
    /* 4B4F8 0014B4F8 1000BD27 */  addiu      $29, $29, 0x10
    /* 4B4FC 0014B4FC 0800E003 */  jr         $31
    /* 4B500 0014B500 00000000 */   nop
    /* 4B504 0014B504 00000000 */  nop
    /* 4B508 0014B508 00000000 */  nop
    /* 4B50C 0014B50C 00000000 */  nop
.size func_0014b4d0, 0x40
