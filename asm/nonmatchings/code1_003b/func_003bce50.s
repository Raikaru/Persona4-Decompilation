.section .text
.set noat
.set noreorder
glabel func_003bce50
    /* 2BCE50 003BCE50 A0FFBD27 */  addiu      $29, $29, -0x60
    /* 2BCE54 003BCE54 5000BFFF */  sd         $31, 0x50($29)
    /* 2BCE58 003BCE58 4000B47F */  sq         $20, 0x40($29)
    /* 2BCE5C 003BCE5C 3000B37F */  sq         $19, 0x30($29)
    /* 2BCE60 003BCE60 2DA00000 */  daddu      $20, $0, $0
    /* 2BCE64 003BCE64 2000B27F */  sq         $18, 0x20($29)
    /* 2BCE68 003BCE68 1000B17F */  sq         $17, 0x10($29)
    /* 2BCE6C 003BCE6C 0000B07F */  sq         $16, 0x0($29)
    /* 2BCE70 003BCE70 21808500 */  addu       $16, $4, $5
    /* 2BCE74 003BCE74 17000012 */  beqz       $16, .L003BCED4
    /* 2BCE78 003BCE78 2D900000 */   daddu     $18, $0, $0
    /* 2BCE7C 003BCE7C 0000028E */  lw         $2, 0x0($16)
    /* 2BCE80 003BCE80 14004018 */  blez       $2, .L003BCED4
    /* 2BCE84 003BCE84 00000000 */   nop
    /* 2BCE88 003BCE88 2A080200 */  slt        $1, $0, $2
    /* 2BCE8C 003BCE8C 0E002010 */  beqz       $1, .L003BCEC8
    /* 2BCE90 003BCE90 2D980000 */   daddu     $19, $0, $0
    /* 2BCE94 003BCE94 2D880000 */  daddu      $17, $0, $0
  .L003BCE98:
    /* 2BCE98 003BCE98 0400028E */  lw         $2, 0x4($16)
    /* 2BCE9C 003BCE9C 21205100 */  addu       $4, $2, $17
    /* 2BCEA0 003BCEA0 0400828C */  lw         $2, 0x4($4)
    /* 2BCEA4 003BCEA4 0D004014 */  bnez       $2, .L003BCEDC
    /* 2BCEA8 003BCEA8 00000000 */   nop
    /* 2BCEAC 003BCEAC 00000000 */  nop
  .L003BCEB0:
    /* 2BCEB0 003BCEB0 0000028E */  lw         $2, 0x0($16)
    /* 2BCEB4 003BCEB4 01007326 */  addiu      $19, $19, 0x1
    /* 2BCEB8 003BCEB8 2A106202 */  slt        $2, $19, $2
    /* 2BCEBC 003BCEBC F6FF4014 */  bnez       $2, .L003BCE98
    /* 2BCEC0 003BCEC0 10003126 */   addiu     $17, $17, 0x10
    /* 2BCEC4 003BCEC4 00000000 */  nop
  .L003BCEC8:
    /* 2BCEC8 003BCEC8 0200401A */  blez       $18, .L003BCED4
    /* 2BCECC 003BCECC 00000000 */   nop
    /* 2BCED0 003BCED0 04005226 */  addiu      $18, $18, 0x4
  .L003BCED4:
    /* 2BCED4 003BCED4 06000010 */  b          .L003BCEF0
    /* 2BCED8 003BCED8 21109202 */   addu      $2, $20, $18
  .L003BCEDC:
    /* 2BCEDC 003BCEDC 88F10E0C */  jal        func_003bc620
    /* 2BCEE0 003BCEE0 00000000 */   nop
    /* 2BCEE4 003BCEE4 F2FF0010 */  b          .L003BCEB0
    /* 2BCEE8 003BCEE8 21904202 */   addu      $18, $18, $2
    /* 2BCEEC 003BCEEC 00000000 */  nop
  .L003BCEF0:
    /* 2BCEF0 003BCEF0 5000BFDF */  ld         $31, 0x50($29)
    /* 2BCEF4 003BCEF4 4000B47B */  lq         $20, 0x40($29)
    /* 2BCEF8 003BCEF8 3000B37B */  lq         $19, 0x30($29)
    /* 2BCEFC 003BCEFC 2000B27B */  lq         $18, 0x20($29)
    /* 2BCF00 003BCF00 1000B17B */  lq         $17, 0x10($29)
    /* 2BCF04 003BCF04 0000B07B */  lq         $16, 0x0($29)
    /* 2BCF08 003BCF08 0800E003 */  jr         $31
    /* 2BCF0C 003BCF0C 6000BD27 */   addiu     $29, $29, 0x60
.size func_003bce50, 0xc0
