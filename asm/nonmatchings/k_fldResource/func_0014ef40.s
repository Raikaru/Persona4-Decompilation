.section .text
.set noat
.set noreorder
glabel func_0014ef40
    /* 4EF40 0014EF40 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 4EF44 0014EF44 0000BFFF */  sd         $31, 0x0($29)
    /* 4EF48 0014EF48 00B2848F */  lw         $4, -0x4E00($28)
    /* 4EF4C 0014EF4C 04008014 */  bnez       $4, .L0014EF60
    /* 4EF50 0014EF50 00000000 */   nop
    /* 4EF54 0014EF54 01000224 */  addiu      $2, $0, 0x1
    /* 4EF58 0014EF58 04000010 */  b          .L0014EF6C
    /* 4EF5C 0014EF5C 00000000 */   nop
  .L0014EF60:
    /* 4EF60 0014EF60 F054110C */  jal        func_004553c0
    /* 4EF64 0014EF64 00000000 */   nop
    /* 4EF68 0014EF68 2B100200 */  sltu       $2, $0, $2
  .L0014EF6C:
    /* 4EF6C 0014EF6C 0000BFDF */  ld         $31, 0x0($29)
    /* 4EF70 0014EF70 1000BD27 */  addiu      $29, $29, 0x10
    /* 4EF74 0014EF74 0800E003 */  jr         $31
    /* 4EF78 0014EF78 00000000 */   nop
    /* 4EF7C 0014EF7C 00000000 */  nop
.size func_0014ef40, 0x40
