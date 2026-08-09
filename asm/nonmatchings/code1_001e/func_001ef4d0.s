.section .text
.set noat
.set noreorder
glabel func_001ef4d0
    /* EF4D0 001EF4D0 90FFBD27 */  addiu      $29, $29, -0x70
    /* EF4D4 001EF4D4 6000BFFF */  sd         $31, 0x60($29)
    /* EF4D8 001EF4D8 5000B57F */  sq         $21, 0x50($29)
    /* EF4DC 001EF4DC 4000B47F */  sq         $20, 0x40($29)
    /* EF4E0 001EF4E0 3000B37F */  sq         $19, 0x30($29)
    /* EF4E4 001EF4E4 2000B27F */  sq         $18, 0x20($29)
    /* EF4E8 001EF4E8 1000B17F */  sq         $17, 0x10($29)
    /* EF4EC 001EF4EC 0000B07F */  sq         $16, 0x0($29)
    /* EF4F0 001EF4F0 2D80A000 */  daddu      $16, $5, $0
    /* EF4F4 001EF4F4 2DA00000 */  daddu      $20, $0, $0
    /* EF4F8 001EF4F8 2D980000 */  daddu      $19, $0, $0
    /* EF4FC 001EF4FC ACB3828F */  lw         $2, -0x4C54($28)
    /* EF500 001EF500 7401558C */  lw         $21, 0x174($2)
    /* EF504 001EF504 FFFF9230 */  andi       $18, $4, 0xFFFF
    /* EF508 001EF508 1D000010 */  b          .L001EF580
    /* EF50C 001EF50C 00000000 */   nop
  .L001EF510:
    /* EF510 001EF510 1A00A296 */  lhu        $2, 0x1A($21)
    /* EF514 001EF514 01004230 */  andi       $2, $2, 0x1
    /* EF518 001EF518 18004010 */  beqz       $2, .L001EF57C
    /* EF51C 001EF51C 00000000 */   nop
    /* EF520 001EF520 3000B18E */  lw         $17, 0x30($21)
    /* EF524 001EF524 A2002392 */  lbu        $3, 0xA2($17)
    /* EF528 001EF528 01000224 */  addiu      $2, $0, 0x1
    /* EF52C 001EF52C 04106200 */  sllv       $2, $2, $3
    /* EF530 001EF530 24104202 */  and        $2, $18, $2
    /* EF534 001EF534 11004010 */  beqz       $2, .L001EF57C
    /* EF538 001EF538 00000000 */   nop
    /* EF53C 001EF53C 07000012 */  beqz       $16, .L001EF55C
    /* EF540 001EF540 00000000 */   nop
    /* EF544 001EF544 640A248E */  lw         $4, 0xA64($17)
    /* EF548 001EF548 2D280002 */  daddu      $5, $16, $0
    /* EF54C 001EF54C C4C9080C */  jal        func_00232710
    /* EF550 001EF550 00000000 */   nop
    /* EF554 001EF554 09004014 */  bnez       $2, .L001EF57C
    /* EF558 001EF558 00000000 */   nop
  .L001EF55C:
    /* EF55C 001EF55C 640A248E */  lw         $4, 0xA64($17)
    /* EF560 001EF560 88C7080C */  jal        func_00231e20
    /* EF564 001EF564 00000000 */   nop
    /* EF568 001EF568 FF004230 */  andi       $2, $2, 0xFF
    /* EF56C 001EF56C 21108202 */  addu       $2, $20, $2
    /* EF570 001EF570 FFFF5430 */  andi       $20, $2, 0xFFFF
    /* EF574 001EF574 01006226 */  addiu      $2, $19, 0x1
    /* EF578 001EF578 FFFF5330 */  andi       $19, $2, 0xFFFF
  .L001EF57C:
    /* EF57C 001EF57C 5004B58E */  lw         $21, 0x450($21)
  .L001EF580:
    /* EF580 001EF580 E3FFA016 */  bnez       $21, .L001EF510
    /* EF584 001EF584 00000000 */   nop
    /* EF588 001EF588 FFFF6332 */  andi       $3, $19, 0xFFFF
    /* EF58C 001EF58C 04006014 */  bnez       $3, .L001EF5A0
    /* EF590 001EF590 00000000 */   nop
    /* EF594 001EF594 01000224 */  addiu      $2, $0, 0x1
    /* EF598 001EF598 0A000010 */  b          .L001EF5C4
    /* EF59C 001EF59C 00000000 */   nop
  .L001EF5A0:
    /* EF5A0 001EF5A0 FFFF8232 */  andi       $2, $20, 0xFFFF
    /* EF5A4 001EF5A4 1A004300 */  div        $0, $2, $3
    /* EF5A8 001EF5A8 12100000 */  mflo       $2
    /* EF5AC 001EF5AC FFFF4230 */  andi       $2, $2, 0xFFFF
    /* EF5B0 001EF5B0 04004014 */  bnez       $2, .L001EF5C4
    /* EF5B4 001EF5B4 00000000 */   nop
    /* EF5B8 001EF5B8 01000224 */  addiu      $2, $0, 0x1
    /* EF5BC 001EF5BC 01000010 */  b          .L001EF5C4
    /* EF5C0 001EF5C0 00000000 */   nop
  .L001EF5C4:
    /* EF5C4 001EF5C4 6000BFDF */  ld         $31, 0x60($29)
    /* EF5C8 001EF5C8 5000B57B */  lq         $21, 0x50($29)
    /* EF5CC 001EF5CC 4000B47B */  lq         $20, 0x40($29)
    /* EF5D0 001EF5D0 3000B37B */  lq         $19, 0x30($29)
    /* EF5D4 001EF5D4 2000B27B */  lq         $18, 0x20($29)
    /* EF5D8 001EF5D8 1000B17B */  lq         $17, 0x10($29)
    /* EF5DC 001EF5DC 0000B07B */  lq         $16, 0x0($29)
    /* EF5E0 001EF5E0 7000BD27 */  addiu      $29, $29, 0x70
    /* EF5E4 001EF5E4 0800E003 */  jr         $31
    /* EF5E8 001EF5E8 00000000 */   nop
    /* EF5EC 001EF5EC 00000000 */  nop
.size func_001ef4d0, 0x120
