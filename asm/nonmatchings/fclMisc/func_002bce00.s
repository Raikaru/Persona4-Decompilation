.section .text
.set noat
.set noreorder
glabel func_002bce00
    /* 1BCE00 002BCE00 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 1BCE04 002BCE04 2000BFFF */  sd         $31, 0x20($29)
    /* 1BCE08 002BCE08 1000B17F */  sq         $17, 0x10($29)
    /* 1BCE0C 002BCE0C 0000B07F */  sq         $16, 0x0($29)
    /* 1BCE10 002BCE10 7CB5918F */  lw         $17, -0x4A84($28)
    /* 1BCE14 002BCE14 0400238E */  lw         $3, 0x4($17)
    /* 1BCE18 002BCE18 01006230 */  andi       $2, $3, 0x1
    /* 1BCE1C 002BCE1C 41004010 */  beqz       $2, .L002BCF24
    /* 1BCE20 002BCE20 00000000 */   nop
    /* 1BCE24 002BCE24 02006230 */  andi       $2, $3, 0x2
    /* 1BCE28 002BCE28 20004010 */  beqz       $2, .L002BCEAC
    /* 1BCE2C 002BCE2C 00000000 */   nop
    /* 1BCE30 002BCE30 2D202002 */  daddu      $4, $17, $0
    /* 1BCE34 002BCE34 18F30A0C */  jal        func_002bcc60
    /* 1BCE38 002BCE38 00000000 */   nop
    /* 1BCE3C 002BCE3C 88F40A0C */  jal        func_002bd220
    /* 1BCE40 002BCE40 00000000 */   nop
    /* 1BCE44 002BCE44 37004010 */  beqz       $2, .L002BCF24
    /* 1BCE48 002BCE48 00000000 */   nop
    /* 1BCE4C 002BCE4C 0400238E */  lw         $3, 0x4($17)
    /* 1BCE50 002BCE50 FDFF0224 */  addiu      $2, $0, -0x3
    /* 1BCE54 002BCE54 24106200 */  and        $2, $3, $2
    /* 1BCE58 002BCE58 040022AE */  sw         $2, 0x4($17)
    /* 1BCE5C 002BCE5C 2D200000 */  daddu      $4, $0, $0
    /* 1BCE60 002BCE60 98F40A0C */  jal        func_002bd260
    /* 1BCE64 002BCE64 00000000 */   nop
    /* 1BCE68 002BCE68 0000248E */  lw         $4, 0x0($17)
    /* 1BCE6C 002BCE6C 04008524 */  addiu      $5, $4, 0x4
    /* 1BCE70 002BCE70 BC880B0C */  jal        func_002e22f0
    /* 1BCE74 002BCE74 00000000 */   nop
    /* 1BCE78 002BCE78 2D800000 */  daddu      $16, $0, $0
    /* 1BCE7C 002BCE7C 06000010 */  b          .L002BCE98
    /* 1BCE80 002BCE80 00000000 */   nop
  .L002BCE84:
    /* 1BCE84 002BCE84 2D202002 */  daddu      $4, $17, $0
    /* 1BCE88 002BCE88 2D280002 */  daddu      $5, $16, $0
    /* 1BCE8C 002BCE8C F0F20A0C */  jal        func_002bcbc0
    /* 1BCE90 002BCE90 00000000 */   nop
    /* 1BCE94 002BCE94 01001026 */  addiu      $16, $16, 0x1
  .L002BCE98:
    /* 1BCE98 002BCE98 0B00022A */  slti       $2, $16, 0xB
    /* 1BCE9C 002BCE9C F9FF4014 */  bnez       $2, .L002BCE84
    /* 1BCEA0 002BCEA0 00000000 */   nop
    /* 1BCEA4 002BCEA4 1F000010 */  b          .L002BCF24
    /* 1BCEA8 002BCEA8 00000000 */   nop
  .L002BCEAC:
    /* 1BCEAC 002BCEAC 0000228E */  lw         $2, 0x0($17)
    /* 1BCEB0 002BCEB0 0400428C */  lw         $2, 0x4($2)
    /* 1BCEB4 002BCEB4 04004014 */  bnez       $2, .L002BCEC8
    /* 1BCEB8 002BCEB8 00000000 */   nop
    /* 1BCEBC 002BCEBC 2D800000 */  daddu      $16, $0, $0
    /* 1BCEC0 002BCEC0 02000010 */  b          .L002BCECC
    /* 1BCEC4 002BCEC4 00000000 */   nop
  .L002BCEC8:
    /* 1BCEC8 002BCEC8 1400508C */  lw         $16, 0x14($2)
  .L002BCECC:
    /* 1BCECC 002BCECC 15000012 */  beqz       $16, .L002BCF24
    /* 1BCED0 002BCED0 00000000 */   nop
    /* 1BCED4 002BCED4 FEFF0224 */  addiu      $2, $0, -0x2
    /* 1BCED8 002BCED8 24106200 */  and        $2, $3, $2
    /* 1BCEDC 002BCEDC 040022AE */  sw         $2, 0x4($17)
    /* 1BCEE0 002BCEE0 10000426 */  addiu      $4, $16, 0x10
    /* 1BCEE4 002BCEE4 2800058E */  lw         $5, 0x28($16)
    /* 1BCEE8 002BCEE8 28F50A0C */  jal        func_002bd4a0
    /* 1BCEEC 002BCEEC 00000000 */   nop
    /* 1BCEF0 002BCEF0 2D202002 */  daddu      $4, $17, $0
    /* 1BCEF4 002BCEF4 2D280000 */  daddu      $5, $0, $0
    /* 1BCEF8 002BCEF8 24F20A0C */  jal        func_002bc890
    /* 1BCEFC 002BCEFC 00000000 */   nop
    /* 1BCF00 002BCF00 2D202002 */  daddu      $4, $17, $0
    /* 1BCF04 002BCF04 2C00058E */  lw         $5, 0x2C($16)
    /* 1BCF08 002BCF08 24F20A0C */  jal        func_002bc890
    /* 1BCF0C 002BCF0C 00000000 */   nop
    /* 1BCF10 002BCF10 0400028E */  lw         $2, 0x4($16)
    /* 1BCF14 002BCF14 02004234 */  ori        $2, $2, 0x2
    /* 1BCF18 002BCF18 040002AE */  sw         $2, 0x4($16)
    /* 1BCF1C 002BCF1C 01004234 */  ori        $2, $2, 0x1
    /* 1BCF20 002BCF20 040002AE */  sw         $2, 0x4($16)
  .L002BCF24:
    /* 1BCF24 002BCF24 0000228E */  lw         $2, 0x0($17)
    /* 1BCF28 002BCF28 0400508C */  lw         $16, 0x4($2)
    /* 1BCF2C 002BCF2C 13000012 */  beqz       $16, .L002BCF7C
    /* 1BCF30 002BCF30 00000000 */   nop
    /* 1BCF34 002BCF34 1400058E */  lw         $5, 0x14($16)
    /* 1BCF38 002BCF38 0400A28C */  lw         $2, 0x4($5)
    /* 1BCF3C 002BCF3C 02004230 */  andi       $2, $2, 0x2
    /* 1BCF40 002BCF40 0E004010 */  beqz       $2, .L002BCF7C
    /* 1BCF44 002BCF44 00000000 */   nop
    /* 1BCF48 002BCF48 2D202002 */  daddu      $4, $17, $0
    /* 1BCF4C 002BCF4C ECF30A0C */  jal        func_002bcfb0
    /* 1BCF50 002BCF50 00000000 */   nop
    /* 1BCF54 002BCF54 09004010 */  beqz       $2, .L002BCF7C
    /* 1BCF58 002BCF58 00000000 */   nop
    /* 1BCF5C 002BCF5C 0400228E */  lw         $2, 0x4($17)
    /* 1BCF60 002BCF60 01004234 */  ori        $2, $2, 0x1
    /* 1BCF64 002BCF64 040022AE */  sw         $2, 0x4($17)
    /* 1BCF68 002BCF68 0000248E */  lw         $4, 0x0($17)
    /* 1BCF6C 002BCF6C 04008524 */  addiu      $5, $4, 0x4
    /* 1BCF70 002BCF70 2D300002 */  daddu      $6, $16, $0
    /* 1BCF74 002BCF74 90880B0C */  jal        func_002e2240
    /* 1BCF78 002BCF78 00000000 */   nop
  .L002BCF7C:
    /* 1BCF7C 002BCF7C 2D202002 */  daddu      $4, $17, $0
    /* 1BCF80 002BCF80 78F20A0C */  jal        func_002bc9e0
    /* 1BCF84 002BCF84 00000000 */   nop
    /* 1BCF88 002BCF88 2D100000 */  daddu      $2, $0, $0
    /* 1BCF8C 002BCF8C 2000BFDF */  ld         $31, 0x20($29)
    /* 1BCF90 002BCF90 1000B17B */  lq         $17, 0x10($29)
    /* 1BCF94 002BCF94 0000B07B */  lq         $16, 0x0($29)
    /* 1BCF98 002BCF98 3000BD27 */  addiu      $29, $29, 0x30
    /* 1BCF9C 002BCF9C 0800E003 */  jr         $31
    /* 1BCFA0 002BCFA0 00000000 */   nop
    /* 1BCFA4 002BCFA4 00000000 */  nop
    /* 1BCFA8 002BCFA8 00000000 */  nop
    /* 1BCFAC 002BCFAC 00000000 */  nop
.size func_002bce00, 0x1b0
