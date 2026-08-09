.section .text
.set noat
.set noreorder
glabel func_002bcbc0
    /* 1BCBC0 002BCBC0 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 1BCBC4 002BCBC4 2000BFFF */  sd         $31, 0x20($29)
    /* 1BCBC8 002BCBC8 1000B17F */  sq         $17, 0x10($29)
    /* 1BCBCC 002BCBCC 0000B07F */  sq         $16, 0x0($29)
    /* 1BCBD0 002BCBD0 2D888000 */  daddu      $17, $4, $0
    /* 1BCBD4 002BCBD4 2D80A000 */  daddu      $16, $5, $0
    /* 1BCBD8 002BCBD8 06002016 */  bnez       $17, .L002BCBF4
    /* 1BCBDC 002BCBDC 00000000 */   nop
    /* 1BCBE0 002BCBE0 6400043C */  lui        $4, %hi(D_0063F2A0)
    /* 1BCBE4 002BCBE4 A0F28424 */  addiu      $4, $4, %lo(D_0063F2A0)
    /* 1BCBE8 002BCBE8 8F050524 */  addiu      $5, $0, 0x58F
    /* 1BCBEC 002BCBEC CCB5110C */  jal        func_0046d730
    /* 1BCBF0 002BCBF0 00000000 */   nop
  .L002BCBF4:
    /* 1BCBF4 002BCBF4 04000006 */  bltz       $16, .L002BCC08
    /* 1BCBF8 002BCBF8 00000000 */   nop
    /* 1BCBFC 002BCBFC 0C00012A */  slti       $1, $16, 0xC
    /* 1BCC00 002BCC00 06002014 */  bnez       $1, .L002BCC1C
    /* 1BCC04 002BCC04 00000000 */   nop
  .L002BCC08:
    /* 1BCC08 002BCC08 6400043C */  lui        $4, %hi(D_0063F2A0)
    /* 1BCC0C 002BCC0C A0F28424 */  addiu      $4, $4, %lo(D_0063F2A0)
    /* 1BCC10 002BCC10 90050524 */  addiu      $5, $0, 0x590
    /* 1BCC14 002BCC14 CCB5110C */  jal        func_0046d730
    /* 1BCC18 002BCC18 00000000 */   nop
  .L002BCC1C:
    /* 1BCC1C 002BCC1C 40101000 */  sll        $2, $16, 1
    /* 1BCC20 002BCC20 21105000 */  addu       $2, $2, $16
    /* 1BCC24 002BCC24 80100200 */  sll        $2, $2, 2
    /* 1BCC28 002BCC28 21182202 */  addu       $3, $17, $2
    /* 1BCC2C 002BCC2C 1C00628C */  lw         $2, 0x1C($3)
    /* 1BCC30 002BCC30 04004234 */  ori        $2, $2, 0x4
    /* 1BCC34 002BCC34 1C0062AC */  sw         $2, 0x1C($3)
    /* 1BCC38 002BCC38 2D100000 */  daddu      $2, $0, $0
    /* 1BCC3C 002BCC3C 2000BFDF */  ld         $31, 0x20($29)
    /* 1BCC40 002BCC40 1000B17B */  lq         $17, 0x10($29)
    /* 1BCC44 002BCC44 0000B07B */  lq         $16, 0x0($29)
    /* 1BCC48 002BCC48 3000BD27 */  addiu      $29, $29, 0x30
    /* 1BCC4C 002BCC4C 0800E003 */  jr         $31
    /* 1BCC50 002BCC50 00000000 */   nop
    /* 1BCC54 002BCC54 00000000 */  nop
    /* 1BCC58 002BCC58 00000000 */  nop
    /* 1BCC5C 002BCC5C 00000000 */  nop
.size func_002bcbc0, 0xa0
