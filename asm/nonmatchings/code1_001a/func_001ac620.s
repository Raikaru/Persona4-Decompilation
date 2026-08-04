.section .text
.set noat
.set noreorder
glabel func_001ac620
    /* AC620 001AC620 E0FFBD27 */  addiu      $29, $29, -0x20
    /* AC624 001AC624 1000BFFF */  sd         $31, 0x10($29)
    /* AC628 001AC628 0000B07F */  sq         $16, 0x0($29)
    /* AC62C 001AC62C ACB3838F */  lw         $3, -0x4C54($28)
    /* AC630 001AC630 7401708C */  lw         $16, 0x174($3)
    /* AC634 001AC634 11000010 */  b          .L001AC67C
    /* AC638 001AC638 00000000 */   nop
  .L001AC63C:
    /* AC63C 001AC63C 2D200002 */  daddu      $4, $16, $0
    /* AC640 001AC640 7C81060C */  jal        func_001a05f0
    /* AC644 001AC644 00000000 */   nop
    /* AC648 001AC648 0B004010 */  beqz       $2, .L001AC678
    /* AC64C 001AC64C 00000000 */   nop
    /* AC650 001AC650 3000028E */  lw         $2, 0x30($16)
    /* AC654 001AC654 0C0A448C */  lw         $4, 0xA0C($2)
    /* AC658 001AC658 A86D060C */  jal        func_0019b6a0
    /* AC65C 001AC65C 00000000 */   nop
    /* AC660 001AC660 2D204000 */  daddu      $4, $2, $0
    /* AC664 001AC664 000003DE */  ld         $3, 0x0($16)
    /* AC668 001AC668 600043FC */  sd         $3, 0x60($2)
    /* AC66C 001AC66C 01000524 */  addiu      $5, $0, 0x1
    /* AC670 001AC670 6451060C */  jal        func_00194590
    /* AC674 001AC674 00000000 */   nop
  .L001AC678:
    /* AC678 001AC678 5004108E */  lw         $16, 0x450($16)
  .L001AC67C:
    /* AC67C 001AC67C EFFF0016 */  bnez       $16, .L001AC63C
    /* AC680 001AC680 00000000 */   nop
    /* AC684 001AC684 1000BFDF */  ld         $31, 0x10($29)
    /* AC688 001AC688 0000B07B */  lq         $16, 0x0($29)
    /* AC68C 001AC68C 2000BD27 */  addiu      $29, $29, 0x20
    /* AC690 001AC690 0800E003 */  jr         $31
    /* AC694 001AC694 00000000 */   nop
    /* AC698 001AC698 00000000 */  nop
    /* AC69C 001AC69C 00000000 */  nop
.size func_001ac620, 0x80
