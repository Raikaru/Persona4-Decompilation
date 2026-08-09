.section .text
.set noat
.set noreorder
glabel func_0052c790
    /* 42C790 0052C790 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 42C794 0052C794 0000B0FF */  sd         $16, 0x0($29)
    /* 42C798 0052C798 2D808000 */  daddu      $16, $4, $0
    /* 42C79C 0052C79C 1800B5E7 */  swc1       $f21, 0x18($29)
    /* 42C7A0 0052C7A0 46650046 */  mov.s      $f21, $f12
    /* 42C7A4 0052C7A4 1000B4E7 */  swc1       $f20, 0x10($29)
    /* 42C7A8 0052C7A8 0800BFFF */  sd         $31, 0x8($29)
    /* 42C7AC 0052C7AC FEB1140C */  jal        func_0052c7f8
    /* 42C7B0 0052C7B0 066D0046 */   mov.s     $f20, $f13
    /* 42C7B4 0052C7B4 7600063C */  lui        $6, %hi(D_00760EC0)
    /* 42C7B8 0052C7B8 01000324 */  addiu      $3, $0, 0x1
    /* 42C7BC 0052C7BC 2D200000 */  daddu      $4, $0, $0
    /* 42C7C0 0052C7C0 C00EC624 */  addiu      $6, $6, %lo(D_00760EC0)
    /* 42C7C4 0052C7C4 03004310 */  beq        $2, $3, .L0052C7D4
    /* 42C7C8 0052C7C8 2D280000 */   daddu     $5, $0, $0
    /* 42C7CC 0052C7CC 68AE140C */  jal        func_0052b9a0
    /* 42C7D0 0052C7D0 00000000 */   nop
  .L0052C7D4:
    /* 42C7D4 0052C7D4 400014E6 */  swc1       $f20, 0x40($16)
    /* 42C7D8 0052C7D8 3C0015E6 */  swc1       $f21, 0x3C($16)
    /* 42C7DC 0052C7DC 0800BFDF */  ld         $31, 0x8($29)
    /* 42C7E0 0052C7E0 0000B0DF */  ld         $16, 0x0($29)
    /* 42C7E4 0052C7E4 1800B5C7 */  lwc1       $f21, 0x18($29)
    /* 42C7E8 0052C7E8 1000B4C7 */  lwc1       $f20, 0x10($29)
    /* 42C7EC 0052C7EC 0800E003 */  jr         $31
    /* 42C7F0 0052C7F0 2000BD27 */   addiu     $29, $29, 0x20
    /* 42C7F4 0052C7F4 00000000 */  nop
.size func_0052c790, 0x68
