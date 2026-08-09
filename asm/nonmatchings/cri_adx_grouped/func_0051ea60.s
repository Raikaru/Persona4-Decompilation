.section .text
.set noat
.set noreorder
glabel func_0051ea60
    /* 41EA60 0051EA60 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 41EA64 0051EA64 0000B0FF */  sd         $16, 0x0($29)
    /* 41EA68 0051EA68 2D808000 */  daddu      $16, $4, $0
    /* 41EA6C 0051EA6C 0800B1FF */  sd         $17, 0x8($29)
    /* 41EA70 0051EA70 1000B2FF */  sd         $18, 0x10($29)
    /* 41EA74 0051EA74 1800B3FF */  sd         $19, 0x18($29)
    /* 41EA78 0051EA78 2000B4FF */  sd         $20, 0x20($29)
    /* 41EA7C 0051EA7C 1C00C018 */  blez       $6, .L0051EAF0
    /* 41EA80 0051EA80 2800BFFF */   sd        $31, 0x28($29)
    /* 41EA84 0051EA84 2D90A000 */  daddu      $18, $5, $0
    /* 41EA88 0051EA88 2D88C000 */  daddu      $17, $6, $0
    /* 41EA8C 0051EA8C 01001424 */  addiu      $20, $0, 0x1
    /* 41EA90 0051EA90 FFFF1324 */  addiu      $19, $0, -0x1
    /* 41EA94 0051EA94 00000000 */  nop
  .L0051EA98:
    /* 41EA98 0051EA98 000000AE */  sw         $0, 0x0($16)
    /* 41EA9C 0051EA9C 0C000426 */  addiu      $4, $16, 0xC
    /* 41EAA0 0051EAA0 040000AE */  sw         $0, 0x4($16)
    /* 41EAA4 0051EAA4 2D280000 */  daddu      $5, $0, $0
    /* 41EAA8 0051EAA8 B095140C */  jal        func_005256c0
    /* 41EAAC 0051EAAC FFFF3126 */   addiu     $17, $17, -0x1
    /* 41EAB0 0051EAB0 0000428E */  lw         $2, 0x0($18)
    /* 41EAB4 0051EAB4 380000AE */  sw         $0, 0x38($16)
    /* 41EAB8 0051EAB8 5C000426 */  addiu      $4, $16, 0x5C
    /* 41EABC 0051EABC 080002AE */  sw         $2, 0x8($16)
    /* 41EAC0 0051EAC0 04005226 */  addiu      $18, $18, 0x4
    /* 41EAC4 0051EAC4 3C0014AE */  sw         $20, 0x3C($16)
    /* 41EAC8 0051EAC8 400000AE */  sw         $0, 0x40($16)
    /* 41EACC 0051EACC 440000AE */  sw         $0, 0x44($16)
    /* 41EAD0 0051EAD0 480000AE */  sw         $0, 0x48($16)
    /* 41EAD4 0051EAD4 4C0000AE */  sw         $0, 0x4C($16)
    /* 41EAD8 0051EAD8 500000AE */  sw         $0, 0x50($16)
    /* 41EADC 0051EADC C47A140C */  jal        func_0051eb10
    /* 41EAE0 0051EAE0 580013AE */   sw        $19, 0x58($16)
    /* 41EAE4 0051EAE4 E80000AE */  sw         $0, 0xE8($16)
    /* 41EAE8 0051EAE8 EBFF2016 */  bnez       $17, .L0051EA98
    /* 41EAEC 0051EAEC F0001026 */   addiu     $16, $16, 0xF0
  .L0051EAF0:
    /* 41EAF0 0051EAF0 0000B0DF */  ld         $16, 0x0($29)
    /* 41EAF4 0051EAF4 0800B1DF */  ld         $17, 0x8($29)
    /* 41EAF8 0051EAF8 1000B2DF */  ld         $18, 0x10($29)
    /* 41EAFC 0051EAFC 1800B3DF */  ld         $19, 0x18($29)
    /* 41EB00 0051EB00 2000B4DF */  ld         $20, 0x20($29)
    /* 41EB04 0051EB04 2800BFDF */  ld         $31, 0x28($29)
    /* 41EB08 0051EB08 0800E003 */  jr         $31
    /* 41EB0C 0051EB0C 3000BD27 */   addiu     $29, $29, 0x30
.size func_0051ea60, 0xb0
