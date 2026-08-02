.section .text
.set noat
.set noreorder
glabel func_0011cb70
    /* 1CB70 0011CB70 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 1CB74 0011CB74 2000BFFF */  sd         $31, 0x20($29)
    /* 1CB78 0011CB78 1000B17F */  sq         $17, 0x10($29)
    /* 1CB7C 0011CB7C 0000B07F */  sq         $16, 0x0($29)
    /* 1CB80 0011CB80 2D88A000 */  daddu      $17, $5, $0
    /* 1CB84 0011CB84 3800908C */  lw         $16, 0x38($4)
    /* 1CB88 0011CB88 0000028E */  lw         $2, 0x0($16)
    /* 1CB8C 0011CB8C 06004014 */  bnez       $2, .L0011CBA8
    /* 1CB90 0011CB90 00000000 */   nop
    /* 1CB94 0011CB94 5E00043C */  lui        $4, %hi(D_005E4868)
    /* 1CB98 0011CB98 68488424 */  addiu      $4, $4, %lo(D_005E4868)
    /* 1CB9C 0011CB9C 210E0524 */  addiu      $5, $0, 0xE21
    /* 1CBA0 0011CBA0 CCB5110C */  jal        func_0046d730
    /* 1CBA4 0011CBA4 00000000 */   nop
  .L0011CBA8:
    /* 1CBA8 0011CBA8 0000048E */  lw         $4, 0x0($16)
    /* 1CBAC 0011CBAC 2D282002 */  daddu      $5, $17, $0
    /* 1CBB0 0011CBB0 0833040C */  jal        func_0010cc20
    /* 1CBB4 0011CBB4 00000000 */   nop
    /* 1CBB8 0011CBB8 08004010 */  beqz       $2, .L0011CBDC
    /* 1CBBC 0011CBBC 00000000 */   nop
    /* 1CBC0 0011CBC0 2D202002 */  daddu      $4, $17, $0
    /* 1CBC4 0011CBC4 8C000526 */  addiu      $5, $16, 0x8C
    /* 1CBC8 0011CBC8 0855040C */  jal        func_00115420
    /* 1CBCC 0011CBCC 00000000 */   nop
    /* 1CBD0 0011CBD0 01000224 */  addiu      $2, $0, 0x1
    /* 1CBD4 0011CBD4 02000010 */  b          .L0011CBE0
    /* 1CBD8 0011CBD8 00000000 */   nop
  .L0011CBDC:
    /* 1CBDC 0011CBDC 2D100000 */  daddu      $2, $0, $0
  .L0011CBE0:
    /* 1CBE0 0011CBE0 2000BFDF */  ld         $31, 0x20($29)
    /* 1CBE4 0011CBE4 1000B17B */  lq         $17, 0x10($29)
    /* 1CBE8 0011CBE8 0000B07B */  lq         $16, 0x0($29)
    /* 1CBEC 0011CBEC 3000BD27 */  addiu      $29, $29, 0x30
    /* 1CBF0 0011CBF0 0800E003 */  jr         $31
    /* 1CBF4 0011CBF4 00000000 */   nop
    /* 1CBF8 0011CBF8 00000000 */  nop
    /* 1CBFC 0011CBFC 00000000 */  nop
.size func_0011cb70, 0x90
