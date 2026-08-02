.section .text
.set noat
.set noreorder
glabel func_001dca60
    /* DCA60 001DCA60 D0FFBD27 */  addiu      $29, $29, -0x30
    /* DCA64 001DCA64 2000BFFF */  sd         $31, 0x20($29)
    /* DCA68 001DCA68 1000B17F */  sq         $17, 0x10($29)
    /* DCA6C 001DCA6C 0000B07F */  sq         $16, 0x0($29)
    /* DCA70 001DCA70 2D808000 */  daddu      $16, $4, $0
    /* DCA74 001DCA74 2D88A000 */  daddu      $17, $5, $0
    /* DCA78 001DCA78 98000526 */  addiu      $5, $16, 0x98
    /* DCA7C 001DCA7C 6E008694 */  lhu        $6, 0x6E($4)
    /* DCA80 001DCA80 2D380000 */  daddu      $7, $0, $0
    /* DCA84 001DCA84 C45F070C */  jal        func_001d7f10
    /* DCA88 001DCA88 00000000 */   nop
    /* DCA8C 001DCA8C FFFF4230 */  andi       $2, $2, 0xFFFF
    /* DCA90 001DCA90 14004010 */  beqz       $2, .L001DCAE4
    /* DCA94 001DCA94 00000000 */   nop
    /* DCA98 001DCA98 2D200000 */  daddu      $4, $0, $0
    /* DCA9C 001DCA9C 08000010 */  b          .L001DCAC0
    /* DCAA0 001DCAA0 00000000 */   nop
  .L001DCAA4:
    /* DCAA4 001DCAA4 FFFF8230 */  andi       $2, $4, 0xFFFF
    /* DCAA8 001DCAA8 80100200 */  sll        $2, $2, 2
    /* DCAAC 001DCAAC 21180202 */  addu       $3, $16, $2
    /* DCAB0 001DCAB0 9800628C */  lw         $2, 0x98($3)
    /* DCAB4 001DCAB4 380062AC */  sw         $2, 0x38($3)
    /* DCAB8 001DCAB8 01008224 */  addiu      $2, $4, 0x1
    /* DCABC 001DCABC FFFF4430 */  andi       $4, $2, 0xFFFF
  .L001DCAC0:
    /* DCAC0 001DCAC0 D0000396 */  lhu        $3, 0xD0($16)
    /* DCAC4 001DCAC4 FFFF8230 */  andi       $2, $4, 0xFFFF
    /* DCAC8 001DCAC8 2A104300 */  slt        $2, $2, $3
    /* DCACC 001DCACC F5FF4014 */  bnez       $2, .L001DCAA4
    /* DCAD0 001DCAD0 00000000 */   nop
    /* DCAD4 001DCAD4 6A0003A6 */  sh         $3, 0x6A($16)
    /* DCAD8 001DCAD8 01000224 */  addiu      $2, $0, 0x1
    /* DCADC 001DCADC 13000010 */  b          .L001DCB2C
    /* DCAE0 001DCAE0 00000000 */   nop
  .L001DCAE4:
    /* DCAE4 001DCAE4 2D200000 */  daddu      $4, $0, $0
    /* DCAE8 001DCAE8 98000526 */  addiu      $5, $16, 0x98
    /* DCAEC 001DCAEC 2C63070C */  jal        func_001d8cb0
    /* DCAF0 001DCAF0 00000000 */   nop
    /* DCAF4 001DCAF4 07004014 */  bnez       $2, .L001DCB14
    /* DCAF8 001DCAF8 00000000 */   nop
    /* DCAFC 001DCAFC 2D200002 */  daddu      $4, $16, $0
    /* DCB00 001DCB00 2D282002 */  daddu      $5, $17, $0
    /* DCB04 001DCB04 C86F070C */  jal        func_001dbf20
    /* DCB08 001DCB08 00000000 */   nop
    /* DCB0C 001DCB0C 07000010 */  b          .L001DCB2C
    /* DCB10 001DCB10 00000000 */   nop
  .L001DCB14:
    /* DCB14 001DCB14 98000426 */  addiu      $4, $16, 0x98
    /* DCB18 001DCB18 F062070C */  jal        func_001d8bc0
    /* DCB1C 001DCB1C 00000000 */   nop
    /* DCB20 001DCB20 380002AE */  sw         $2, 0x38($16)
    /* DCB24 001DCB24 01000224 */  addiu      $2, $0, 0x1
    /* DCB28 001DCB28 6A0002A6 */  sh         $2, 0x6A($16)
  .L001DCB2C:
    /* DCB2C 001DCB2C 2000BFDF */  ld         $31, 0x20($29)
    /* DCB30 001DCB30 1000B17B */  lq         $17, 0x10($29)
    /* DCB34 001DCB34 0000B07B */  lq         $16, 0x0($29)
    /* DCB38 001DCB38 3000BD27 */  addiu      $29, $29, 0x30
    /* DCB3C 001DCB3C 0800E003 */  jr         $31
    /* DCB40 001DCB40 00000000 */   nop
    /* DCB44 001DCB44 00000000 */  nop
    /* DCB48 001DCB48 00000000 */  nop
    /* DCB4C 001DCB4C 00000000 */  nop
.size func_001dca60, 0xf0
