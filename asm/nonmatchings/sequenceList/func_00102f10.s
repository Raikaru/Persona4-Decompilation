.section .text
.set noat
.set noreorder
glabel func_00102f10
    /* 2F10 00102F10 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 2F14 00102F14 0000BFFF */  sd         $31, 0x0($29)
    /* 2F18 00102F18 5E00043C */  lui        $4, %hi(D_005DCBB0)
    /* 2F1C 00102F1C B0CB8424 */  addiu      $4, $4, %lo(D_005DCBB0)
    /* 2F20 00102F20 E048110C */  jal        func_00452380
    /* 2F24 00102F24 00000000 */   nop
    /* 2F28 00102F28 04004014 */  bnez       $2, .L00102F3C
    /* 2F2C 00102F2C 00000000 */   nop
    /* 2F30 00102F30 2D200000 */  daddu      $4, $0, $0
    /* 2F34 00102F34 347A0A0C */  jal        func_0029e8d0
    /* 2F38 00102F38 00000000 */   nop
  .L00102F3C:
    /* 2F3C 00102F3C 0000BFDF */  ld         $31, 0x0($29)
    /* 2F40 00102F40 1000BD27 */  addiu      $29, $29, 0x10
    /* 2F44 00102F44 0800E003 */  jr         $31
    /* 2F48 00102F48 00000000 */   nop
    /* 2F4C 00102F4C 00000000 */  nop
.size func_00102f10, 0x40
