.section .text
.set noat
.set noreorder
glabel func_0050cf00
    /* 40CF00 0050CF00 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 40CF04 0050CF04 0800B1FF */  sd         $17, 0x8($29)
    /* 40CF08 0050CF08 0000B0FF */  sd         $16, 0x0($29)
    /* 40CF0C 0050CF0C 1000BFFF */  sd         $31, 0x10($29)
    /* 40CF10 0050CF10 0A35140C */  jal        func_0050d428
    /* 40CF14 0050CF14 2D888000 */   daddu     $17, $4, $0
    /* 40CF18 0050CF18 01000324 */  addiu      $3, $0, 0x1
    /* 40CF1C 0050CF1C 06004310 */  beq        $2, $3, .L0050CF38
    /* 40CF20 0050CF20 2D202002 */   daddu     $4, $17, $0
    /* 40CF24 0050CF24 7600043C */  lui        $4, %hi(D_0075F0C8)
    /* 40CF28 0050CF28 8844140C */  jal        func_00511220
    /* 40CF2C 0050CF2C C8F08424 */   addiu     $4, $4, %lo(D_0075F0C8)
    /* 40CF30 0050CF30 07000010 */  b          .L0050CF50
    /* 40CF34 0050CF34 2D100000 */   daddu     $2, $0, $0
  .L0050CF38:
    /* 40CF38 0050CF38 DA33140C */  jal        func_0050cf68
    /* 40CF3C 0050CF3C 00000000 */   nop
    /* 40CF40 0050CF40 2D202002 */  daddu      $4, $17, $0
    /* 40CF44 0050CF44 3A2B140C */  jal        func_0050ace8
    /* 40CF48 0050CF48 2D804000 */   daddu     $16, $2, $0
    /* 40CF4C 0050CF4C 21100202 */  addu       $2, $16, $2
  .L0050CF50:
    /* 40CF50 0050CF50 0000B0DF */  ld         $16, 0x0($29)
    /* 40CF54 0050CF54 0800B1DF */  ld         $17, 0x8($29)
    /* 40CF58 0050CF58 1000BFDF */  ld         $31, 0x10($29)
    /* 40CF5C 0050CF5C 0800E003 */  jr         $31
    /* 40CF60 0050CF60 2000BD27 */   addiu     $29, $29, 0x20
    /* 40CF64 0050CF64 00000000 */  nop
.size func_0050cf00, 0x68
