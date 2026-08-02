.section .text
.set noat
.set noreorder
glabel func_00102fe0
    /* 2FE0 00102FE0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 2FE4 00102FE4 0000BFFF */  sd         $31, 0x0($29)
    /* 2FE8 00102FE8 F0140A0C */  jal        func_002853c0
    /* 2FEC 00102FEC 00000000 */   nop
    /* 2FF0 00102FF0 03004014 */  bnez       $2, .L00103000
    /* 2FF4 00102FF4 00000000 */   nop
    /* 2FF8 00102FF8 EC140A0C */  jal        func_002853b0
    /* 2FFC 00102FFC 00000000 */   nop
  .L00103000:
    /* 3000 00103000 0000BFDF */  ld         $31, 0x0($29)
    /* 3004 00103004 1000BD27 */  addiu      $29, $29, 0x10
    /* 3008 00103008 0800E003 */  jr         $31
    /* 300C 0010300C 00000000 */   nop
.size func_00102fe0, 0x30
