.section .text
.set noat
.set noreorder
glabel func_0014ef80
    /* 4EF80 0014EF80 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 4EF84 0014EF84 0000BFFF */  sd         $31, 0x0($29)
    /* 4EF88 0014EF88 04B2848F */  lw         $4, -0x4DFC($28)
    /* 4EF8C 0014EF8C 04008014 */  bnez       $4, .L0014EFA0
    /* 4EF90 0014EF90 00000000 */   nop
    /* 4EF94 0014EF94 01000224 */  addiu      $2, $0, 0x1
    /* 4EF98 0014EF98 04000010 */  b          .L0014EFAC
    /* 4EF9C 0014EF9C 00000000 */   nop
  .L0014EFA0:
    /* 4EFA0 0014EFA0 F054110C */  jal        func_004553c0
    /* 4EFA4 0014EFA4 00000000 */   nop
    /* 4EFA8 0014EFA8 2B100200 */  sltu       $2, $0, $2
  .L0014EFAC:
    /* 4EFAC 0014EFAC 0000BFDF */  ld         $31, 0x0($29)
    /* 4EFB0 0014EFB0 1000BD27 */  addiu      $29, $29, 0x10
    /* 4EFB4 0014EFB4 0800E003 */  jr         $31
    /* 4EFB8 0014EFB8 00000000 */   nop
    /* 4EFBC 0014EFBC 00000000 */  nop
.size func_0014ef80, 0x40
