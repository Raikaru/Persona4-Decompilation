.section .text
.set noat
.set noreorder
glabel func_001ef5f0
    /* EF5F0 001EF5F0 80FFBD27 */  addiu      $29, $29, -0x80
    /* EF5F4 001EF5F4 7000BFFF */  sd         $31, 0x70($29)
    /* EF5F8 001EF5F8 6000B67F */  sq         $22, 0x60($29)
    /* EF5FC 001EF5FC 5000B57F */  sq         $21, 0x50($29)
    /* EF600 001EF600 4000B47F */  sq         $20, 0x40($29)
    /* EF604 001EF604 3000B37F */  sq         $19, 0x30($29)
    /* EF608 001EF608 2000B27F */  sq         $18, 0x20($29)
    /* EF60C 001EF60C 1000B17F */  sq         $17, 0x10($29)
    /* EF610 001EF610 0000B07F */  sq         $16, 0x0($29)
    /* EF614 001EF614 2DB0A000 */  daddu      $22, $5, $0
    /* EF618 001EF618 2D80C000 */  daddu      $16, $6, $0
    /* EF61C 001EF61C 2DA00000 */  daddu      $20, $0, $0
    /* EF620 001EF620 2D980000 */  daddu      $19, $0, $0
    /* EF624 001EF624 ACB3828F */  lw         $2, -0x4C54($28)
    /* EF628 001EF628 7401558C */  lw         $21, 0x174($2)
    /* EF62C 001EF62C FFFF9230 */  andi       $18, $4, 0xFFFF
    /* EF630 001EF630 1E000010 */  b          .L001EF6AC
    /* EF634 001EF634 00000000 */   nop
  .L001EF638:
    /* EF638 001EF638 1A00A296 */  lhu        $2, 0x1A($21)
    /* EF63C 001EF63C 01004230 */  andi       $2, $2, 0x1
    /* EF640 001EF640 19004010 */  beqz       $2, .L001EF6A8
    /* EF644 001EF644 00000000 */   nop
    /* EF648 001EF648 3000B18E */  lw         $17, 0x30($21)
    /* EF64C 001EF64C A2002392 */  lbu        $3, 0xA2($17)
    /* EF650 001EF650 01000224 */  addiu      $2, $0, 0x1
    /* EF654 001EF654 04106200 */  sllv       $2, $2, $3
    /* EF658 001EF658 24104202 */  and        $2, $18, $2
    /* EF65C 001EF65C 12004010 */  beqz       $2, .L001EF6A8
    /* EF660 001EF660 00000000 */   nop
    /* EF664 001EF664 07000012 */  beqz       $16, .L001EF684
    /* EF668 001EF668 00000000 */   nop
    /* EF66C 001EF66C 640A248E */  lw         $4, 0xA64($17)
    /* EF670 001EF670 2D280002 */  daddu      $5, $16, $0
    /* EF674 001EF674 C4C9080C */  jal        func_00232710
    /* EF678 001EF678 00000000 */   nop
    /* EF67C 001EF67C 0A004014 */  bnez       $2, .L001EF6A8
    /* EF680 001EF680 00000000 */   nop
  .L001EF684:
    /* EF684 001EF684 640A248E */  lw         $4, 0xA64($17)
    /* EF688 001EF688 2D28C002 */  daddu      $5, $22, $0
    /* EF68C 001EF68C 1CCB080C */  jal        func_00232c70
    /* EF690 001EF690 00000000 */   nop
    /* EF694 001EF694 FF004230 */  andi       $2, $2, 0xFF
    /* EF698 001EF698 21108202 */  addu       $2, $20, $2
    /* EF69C 001EF69C FFFF5430 */  andi       $20, $2, 0xFFFF
    /* EF6A0 001EF6A0 01006226 */  addiu      $2, $19, 0x1
    /* EF6A4 001EF6A4 FFFF5330 */  andi       $19, $2, 0xFFFF
  .L001EF6A8:
    /* EF6A8 001EF6A8 5004B58E */  lw         $21, 0x450($21)
  .L001EF6AC:
    /* EF6AC 001EF6AC E2FFA016 */  bnez       $21, .L001EF638
    /* EF6B0 001EF6B0 00000000 */   nop
    /* EF6B4 001EF6B4 FFFF6332 */  andi       $3, $19, 0xFFFF
    /* EF6B8 001EF6B8 04006014 */  bnez       $3, .L001EF6CC
    /* EF6BC 001EF6BC 00000000 */   nop
    /* EF6C0 001EF6C0 01000224 */  addiu      $2, $0, 0x1
    /* EF6C4 001EF6C4 0A000010 */  b          .L001EF6F0
    /* EF6C8 001EF6C8 00000000 */   nop
  .L001EF6CC:
    /* EF6CC 001EF6CC FFFF8232 */  andi       $2, $20, 0xFFFF
    /* EF6D0 001EF6D0 1A004300 */  div        $0, $2, $3
    /* EF6D4 001EF6D4 12100000 */  mflo       $2
    /* EF6D8 001EF6D8 FFFF4230 */  andi       $2, $2, 0xFFFF
    /* EF6DC 001EF6DC 04004014 */  bnez       $2, .L001EF6F0
    /* EF6E0 001EF6E0 00000000 */   nop
    /* EF6E4 001EF6E4 01000224 */  addiu      $2, $0, 0x1
    /* EF6E8 001EF6E8 01000010 */  b          .L001EF6F0
    /* EF6EC 001EF6EC 00000000 */   nop
  .L001EF6F0:
    /* EF6F0 001EF6F0 7000BFDF */  ld         $31, 0x70($29)
    /* EF6F4 001EF6F4 6000B67B */  lq         $22, 0x60($29)
    /* EF6F8 001EF6F8 5000B57B */  lq         $21, 0x50($29)
    /* EF6FC 001EF6FC 4000B47B */  lq         $20, 0x40($29)
    /* EF700 001EF700 3000B37B */  lq         $19, 0x30($29)
    /* EF704 001EF704 2000B27B */  lq         $18, 0x20($29)
    /* EF708 001EF708 1000B17B */  lq         $17, 0x10($29)
    /* EF70C 001EF70C 0000B07B */  lq         $16, 0x0($29)
    /* EF710 001EF710 8000BD27 */  addiu      $29, $29, 0x80
    /* EF714 001EF714 0800E003 */  jr         $31
    /* EF718 001EF718 00000000 */   nop
    /* EF71C 001EF71C 00000000 */  nop
.size func_001ef5f0, 0x130
