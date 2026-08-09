.section .text
.set noat
.set noreorder
glabel func_001ec4a0
    /* EC4A0 001EC4A0 B0FFBD27 */  addiu      $29, $29, -0x50
    /* EC4A4 001EC4A4 3000BFFF */  sd         $31, 0x30($29)
    /* EC4A8 001EC4A8 2000B17F */  sq         $17, 0x20($29)
    /* EC4AC 001EC4AC 1000B07F */  sq         $16, 0x10($29)
    /* EC4B0 001EC4B0 0000B4E7 */  swc1       $f20, 0x0($29)
    /* EC4B4 001EC4B4 2D888000 */  daddu      $17, $4, $0
    /* EC4B8 001EC4B8 2D80A000 */  daddu      $16, $5, $0
    /* EC4BC 001EC4BC 485C110C */  jal        func_00457120
    /* EC4C0 001EC4C0 00000000 */   nop
    /* EC4C4 001EC4C4 20004624 */  addiu      $6, $2, 0x20
    /* EC4C8 001EC4C8 4000A427 */  addiu      $4, $29, 0x40
    /* EC4CC 001EC4CC 2D282002 */  daddu      $5, $17, $0
    /* EC4D0 001EC4D0 A8900F0C */  jal        func_003e42a0
    /* EC4D4 001EC4D4 00000000 */   nop
    /* EC4D8 001EC4D8 485C110C */  jal        func_00457120
    /* EC4DC 001EC4DC 00000000 */   nop
    /* EC4E0 001EC4E0 800054C4 */  lwc1       $f20, 0x80($2)
    /* EC4E4 001EC4E4 485C110C */  jal        func_00457120
    /* EC4E8 001EC4E8 00000000 */   nop
    /* EC4EC 001EC4EC 840040C4 */  lwc1       $f0, 0x84($2)
    /* EC4F0 001EC4F0 4800A3C7 */  lwc1       $f3, 0x48($29)
    /* EC4F4 001EC4F4 36181446 */  c.le.s     $f3, $f20
    /* EC4F8 001EC4F8 04000145 */  bc1t       .L001EC50C
    /* EC4FC 001EC4FC 00000000 */   nop
    /* EC500 001EC500 34180046 */  c.lt.s     $f3, $f0
    /* EC504 001EC504 04000145 */  bc1t       .L001EC518
    /* EC508 001EC508 00000000 */   nop
  .L001EC50C:
    /* EC50C 001EC50C 2D100000 */  daddu      $2, $0, $0
    /* EC510 001EC510 2C000010 */  b          .L001EC5C4
    /* EC514 001EC514 00000000 */   nop
  .L001EC518:
    /* EC518 001EC518 4000A0C7 */  lwc1       $f0, 0x40($29)
    /* EC51C 001EC51C 00000000 */  nop
    /* EC520 001EC520 43000346 */  div.s      $f1, $f0, $f3
    /* EC524 001EC524 2044023C */  lui        $2, (0x44200000 >> 16)
    /* EC528 001EC528 00008244 */  mtc1       $2, $f0
    /* EC52C 001EC52C 00000000 */  nop
    /* EC530 001EC530 82000146 */  mul.s      $f2, $f0, $f1
    /* EC534 001EC534 4400A0C7 */  lwc1       $f0, 0x44($29)
    /* EC538 001EC538 43000346 */  div.s      $f1, $f0, $f3
    /* EC53C 001EC53C E043023C */  lui        $2, (0x43E00000 >> 16)
    /* EC540 001EC540 00008244 */  mtc1       $2, $f0
    /* EC544 001EC544 00000000 */  nop
    /* EC548 001EC548 42000146 */  mul.s      $f1, $f0, $f1
    /* EC54C 001EC54C 20C4023C */  lui        $2, (0xC4200000 >> 16)
    /* EC550 001EC550 00008244 */  mtc1       $2, $f0
    /* EC554 001EC554 00000000 */  nop
    /* EC558 001EC558 34100046 */  c.lt.s     $f2, $f0
    /* EC55C 001EC55C 13000145 */  bc1t       .L001EC5AC
    /* EC560 001EC560 00000000 */   nop
    /* EC564 001EC564 A044023C */  lui        $2, (0x44A00000 >> 16)
    /* EC568 001EC568 00008244 */  mtc1       $2, $f0
    /* EC56C 001EC56C 00000000 */  nop
    /* EC570 001EC570 36100046 */  c.le.s     $f2, $f0
    /* EC574 001EC574 0D000045 */  bc1f       .L001EC5AC
    /* EC578 001EC578 00000000 */   nop
    /* EC57C 001EC57C E0C3023C */  lui        $2, (0xC3E00000 >> 16)
    /* EC580 001EC580 00008244 */  mtc1       $2, $f0
    /* EC584 001EC584 00000000 */  nop
    /* EC588 001EC588 34080046 */  c.lt.s     $f1, $f0
    /* EC58C 001EC58C 07000145 */  bc1t       .L001EC5AC
    /* EC590 001EC590 00000000 */   nop
    /* EC594 001EC594 6044023C */  lui        $2, (0x44600000 >> 16)
    /* EC598 001EC598 00008244 */  mtc1       $2, $f0
    /* EC59C 001EC59C 00000000 */  nop
    /* EC5A0 001EC5A0 36080046 */  c.le.s     $f1, $f0
    /* EC5A4 001EC5A4 04000145 */  bc1t       .L001EC5B8
    /* EC5A8 001EC5A8 00000000 */   nop
  .L001EC5AC:
    /* EC5AC 001EC5AC 2D100000 */  daddu      $2, $0, $0
    /* EC5B0 001EC5B0 04000010 */  b          .L001EC5C4
    /* EC5B4 001EC5B4 00000000 */   nop
  .L001EC5B8:
    /* EC5B8 001EC5B8 000002E6 */  swc1       $f2, 0x0($16)
    /* EC5BC 001EC5BC 040001E6 */  swc1       $f1, 0x4($16)
    /* EC5C0 001EC5C0 01000224 */  addiu      $2, $0, 0x1
  .L001EC5C4:
    /* EC5C4 001EC5C4 3000BFDF */  ld         $31, 0x30($29)
    /* EC5C8 001EC5C8 2000B17B */  lq         $17, 0x20($29)
    /* EC5CC 001EC5CC 1000B07B */  lq         $16, 0x10($29)
    /* EC5D0 001EC5D0 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* EC5D4 001EC5D4 5000BD27 */  addiu      $29, $29, 0x50
    /* EC5D8 001EC5D8 0800E003 */  jr         $31
    /* EC5DC 001EC5DC 00000000 */   nop
.size func_001ec4a0, 0x140
