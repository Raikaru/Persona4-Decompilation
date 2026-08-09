.section .text
.set noat
.set noreorder
glabel func_00149ce0
    /* 49CE0 00149CE0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 49CE4 00149CE4 0000BFFF */  sd         $31, 0x0($29)
    /* 49CE8 00149CE8 0C000424 */  addiu      $4, $0, 0xC
    /* 49CEC 00149CEC AC14050C */  jal        func_001452b0
    /* 49CF0 00149CF0 00000000 */   nop
    /* 49CF4 00149CF4 04004014 */  bnez       $2, .L00149D08
    /* 49CF8 00149CF8 00000000 */   nop
    /* 49CFC 00149CFC 2D100000 */  daddu      $2, $0, $0
    /* 49D00 00149D00 02000010 */  b          .L00149D0C
    /* 49D04 00149D04 00000000 */   nop
  .L00149D08:
    /* 49D08 00149D08 50014224 */  addiu      $2, $2, 0x150
  .L00149D0C:
    /* 49D0C 00149D0C 0000BFDF */  ld         $31, 0x0($29)
    /* 49D10 00149D10 1000BD27 */  addiu      $29, $29, 0x10
    /* 49D14 00149D14 0800E003 */  jr         $31
    /* 49D18 00149D18 00000000 */   nop
    /* 49D1C 00149D1C 00000000 */  nop
.size func_00149ce0, 0x40
