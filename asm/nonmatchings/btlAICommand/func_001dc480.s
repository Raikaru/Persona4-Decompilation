.section .text
.set noat
.set noreorder
glabel func_001dc480
    /* DC480 001DC480 A0FFBD27 */  addiu      $29, $29, -0x60
    /* DC484 001DC484 5000BFFF */  sd         $31, 0x50($29)
    /* DC488 001DC488 4000B47F */  sq         $20, 0x40($29)
    /* DC48C 001DC48C 3000B37F */  sq         $19, 0x30($29)
    /* DC490 001DC490 2000B27F */  sq         $18, 0x20($29)
    /* DC494 001DC494 1000B17F */  sq         $17, 0x10($29)
    /* DC498 001DC498 0000B07F */  sq         $16, 0x0($29)
    /* DC49C 001DC49C 2DA08000 */  daddu      $20, $4, $0
    /* DC4A0 001DC4A0 98008526 */  addiu      $5, $20, 0x98
    /* DC4A4 001DC4A4 6E008694 */  lhu        $6, 0x6E($4)
    /* DC4A8 001DC4A8 2D380000 */  daddu      $7, $0, $0
    /* DC4AC 001DC4AC C45F070C */  jal        func_001d7f10
    /* DC4B0 001DC4B0 00000000 */   nop
    /* DC4B4 001DC4B4 FFFF4230 */  andi       $2, $2, 0xFFFF
    /* DC4B8 001DC4B8 14004010 */  beqz       $2, .L001DC50C
    /* DC4BC 001DC4BC 00000000 */   nop
    /* DC4C0 001DC4C0 2D200000 */  daddu      $4, $0, $0
    /* DC4C4 001DC4C4 08000010 */  b          .L001DC4E8
    /* DC4C8 001DC4C8 00000000 */   nop
  .L001DC4CC:
    /* DC4CC 001DC4CC FFFF8230 */  andi       $2, $4, 0xFFFF
    /* DC4D0 001DC4D0 80100200 */  sll        $2, $2, 2
    /* DC4D4 001DC4D4 21188202 */  addu       $3, $20, $2
    /* DC4D8 001DC4D8 9800628C */  lw         $2, 0x98($3)
    /* DC4DC 001DC4DC 380062AC */  sw         $2, 0x38($3)
    /* DC4E0 001DC4E0 01008224 */  addiu      $2, $4, 0x1
    /* DC4E4 001DC4E4 FFFF4430 */  andi       $4, $2, 0xFFFF
  .L001DC4E8:
    /* DC4E8 001DC4E8 D0008396 */  lhu        $3, 0xD0($20)
    /* DC4EC 001DC4EC FFFF8230 */  andi       $2, $4, 0xFFFF
    /* DC4F0 001DC4F0 2A104300 */  slt        $2, $2, $3
    /* DC4F4 001DC4F4 F5FF4014 */  bnez       $2, .L001DC4CC
    /* DC4F8 001DC4F8 00000000 */   nop
    /* DC4FC 001DC4FC 6A0083A6 */  sh         $3, 0x6A($20)
    /* DC500 001DC500 01000224 */  addiu      $2, $0, 0x1
    /* DC504 001DC504 20000010 */  b          .L001DC588
    /* DC508 001DC508 00000000 */   nop
  .L001DC50C:
    /* DC50C 001DC50C 2D900000 */  daddu      $18, $0, $0
    /* DC510 001DC510 FFFF0234 */  ori        $2, $0, 0xFFFF
    /* DC514 001DC514 FFFF5030 */  andi       $16, $2, 0xFFFF
    /* DC518 001DC518 2D880000 */  daddu      $17, $0, $0
    /* DC51C 001DC51C 12000010 */  b          .L001DC568
    /* DC520 001DC520 00000000 */   nop
  .L001DC524:
    /* DC524 001DC524 FFFF2232 */  andi       $2, $17, 0xFFFF
    /* DC528 001DC528 80100200 */  sll        $2, $2, 2
    /* DC52C 001DC52C 21108202 */  addu       $2, $20, $2
    /* DC530 001DC530 9800538C */  lw         $19, 0x98($2)
    /* DC534 001DC534 3000628E */  lw         $2, 0x30($19)
    /* DC538 001DC538 640A448C */  lw         $4, 0xA64($2)
    /* DC53C 001DC53C 88C7080C */  jal        func_00231e20
    /* DC540 001DC540 00000000 */   nop
    /* DC544 001DC544 FF004330 */  andi       $3, $2, 0xFF
    /* DC548 001DC548 FFFF0232 */  andi       $2, $16, 0xFFFF
    /* DC54C 001DC54C 2A086200 */  slt        $1, $3, $2
    /* DC550 001DC550 03002010 */  beqz       $1, .L001DC560
    /* DC554 001DC554 00000000 */   nop
    /* DC558 001DC558 2D906002 */  daddu      $18, $19, $0
    /* DC55C 001DC55C 2D806000 */  daddu      $16, $3, $0
  .L001DC560:
    /* DC560 001DC560 01002226 */  addiu      $2, $17, 0x1
    /* DC564 001DC564 FFFF5130 */  andi       $17, $2, 0xFFFF
  .L001DC568:
    /* DC568 001DC568 FFFF2332 */  andi       $3, $17, 0xFFFF
    /* DC56C 001DC56C D0008296 */  lhu        $2, 0xD0($20)
    /* DC570 001DC570 2A106200 */  slt        $2, $3, $2
    /* DC574 001DC574 EBFF4014 */  bnez       $2, .L001DC524
    /* DC578 001DC578 00000000 */   nop
    /* DC57C 001DC57C 380092AE */  sw         $18, 0x38($20)
    /* DC580 001DC580 01000224 */  addiu      $2, $0, 0x1
    /* DC584 001DC584 6A0082A6 */  sh         $2, 0x6A($20)
  .L001DC588:
    /* DC588 001DC588 5000BFDF */  ld         $31, 0x50($29)
    /* DC58C 001DC58C 4000B47B */  lq         $20, 0x40($29)
    /* DC590 001DC590 3000B37B */  lq         $19, 0x30($29)
    /* DC594 001DC594 2000B27B */  lq         $18, 0x20($29)
    /* DC598 001DC598 1000B17B */  lq         $17, 0x10($29)
    /* DC59C 001DC59C 0000B07B */  lq         $16, 0x0($29)
    /* DC5A0 001DC5A0 6000BD27 */  addiu      $29, $29, 0x60
    /* DC5A4 001DC5A4 0800E003 */  jr         $31
    /* DC5A8 001DC5A8 00000000 */   nop
    /* DC5AC 001DC5AC 00000000 */  nop
.size func_001dc480, 0x130
