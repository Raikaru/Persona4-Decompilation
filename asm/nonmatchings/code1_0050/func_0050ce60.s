.section .text
.set noat
.set noreorder
glabel func_0050ce60
    /* 40CE60 0050CE60 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40CE64 0050CE64 0000B0FF */  sd         $16, 0x0($29)
    /* 40CE68 0050CE68 0800BFFF */  sd         $31, 0x8($29)
    /* 40CE6C 0050CE6C 0A35140C */  jal        func_0050d428
    /* 40CE70 0050CE70 2D808000 */   daddu     $16, $4, $0
    /* 40CE74 0050CE74 7600043C */  lui        $4, %hi(D_0075F068)
    /* 40CE78 0050CE78 01000324 */  addiu      $3, $0, 0x1
    /* 40CE7C 0050CE7C 06004310 */  beq        $2, $3, .L0050CE98
    /* 40CE80 0050CE80 68F08424 */   addiu     $4, $4, %lo(D_0075F068)
    /* 40CE84 0050CE84 8844140C */  jal        func_00511220
    /* 40CE88 0050CE88 00000000 */   nop
    /* 40CE8C 0050CE8C 03000010 */  b          .L0050CE9C
    /* 40CE90 0050CE90 2D100000 */   daddu     $2, $0, $0
    /* 40CE94 0050CE94 00000000 */  nop
  .L0050CE98:
    /* 40CE98 0050CE98 3C00028E */  lw         $2, 0x3C($16)
  .L0050CE9C:
    /* 40CE9C 0050CE9C 0000B0DF */  ld         $16, 0x0($29)
    /* 40CEA0 0050CEA0 0800BFDF */  ld         $31, 0x8($29)
    /* 40CEA4 0050CEA4 0800E003 */  jr         $31
    /* 40CEA8 0050CEA8 1000BD27 */   addiu     $29, $29, 0x10
    /* 40CEAC 0050CEAC 00000000 */  nop
.size func_0050ce60, 0x50
