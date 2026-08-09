.section .text
.set noat
.set noreorder
glabel func_003eb3b0
    /* 2EB3B0 003EB3B0 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 2EB3B4 003EB3B4 2000BFFF */  sd         $31, 0x20($29)
    /* 2EB3B8 003EB3B8 1000B17F */  sq         $17, 0x10($29)
    /* 2EB3BC 003EB3BC 2D88A000 */  daddu      $17, $5, $0
    /* 2EB3C0 003EB3C0 D8AB0F0C */  jal        func_003eaf60
    /* 2EB3C4 003EB3C4 0000B07F */   sq        $16, 0x0($29)
    /* 2EB3C8 003EB3C8 2D804000 */  daddu      $16, $2, $0
    /* 2EB3CC 003EB3CC C3000012 */  beqz       $16, .L003EB6DC
    /* 2EB3D0 003EB3D0 00000000 */   nop
    /* 2EB3D4 003EB3D4 A9002012 */  beqz       $17, .L003EB67C
    /* 2EB3D8 003EB3D8 00000000 */   nop
    /* 2EB3DC 003EB3DC 00002282 */  lb         $2, 0x0($17)
    /* 2EB3E0 003EB3E0 A6004010 */  beqz       $2, .L003EB67C
    /* 2EB3E4 003EB3E4 00000000 */   nop
    /* 2EB3E8 003EB3E8 D8AB0F0C */  jal        func_003eaf60
    /* 2EB3EC 003EB3EC 2D202002 */   daddu     $4, $17, $0
    /* 2EB3F0 003EB3F0 2D884000 */  daddu      $17, $2, $0
    /* 2EB3F4 003EB3F4 29002012 */  beqz       $17, .L003EB49C
    /* 2EB3F8 003EB3F8 00000000 */   nop
    /* 2EB3FC 003EB3FC 58A90F0C */  jal        func_003ea560
    /* 2EB400 003EB400 2D202002 */   daddu     $4, $17, $0
    /* 2EB404 003EB404 59004014 */  bnez       $2, .L003EB56C
    /* 2EB408 003EB408 00000000 */   nop
    /* 2EB40C 003EB40C 0000028E */  lw         $2, 0x0($16)
    /* 2EB410 003EB410 01004230 */  andi       $2, $2, 0x1
    /* 2EB414 003EB414 3F004014 */  bnez       $2, .L003EB514
    /* 2EB418 003EB418 00000000 */   nop
  .L003EB41C:
    /* 2EB41C 003EB41C 7100043C */  lui        $4, %hi(D_0070B7C0)
    /* 2EB420 003EB420 2D280002 */  daddu      $5, $16, $0
    /* 2EB424 003EB424 088F0F0C */  jal        func_003e3c20
    /* 2EB428 003EB428 C0B78424 */   addiu     $4, $4, %lo(D_0070B7C0)
    /* 2EB42C 003EB42C C8B7848F */  lw         $4, -0x4838($28)
    /* 2EB430 003EB430 2D280002 */  daddu      $5, $16, $0
    /* 2EB434 003EB434 8800033C */  lui        $3, %hi(D_008872E0)
    /* 2EB438 003EB438 8800103C */  lui        $16, %hi(jtbl_008873FC)
    /* 2EB43C 003EB43C E0726324 */  addiu      $3, $3, %lo(D_008872E0)
    /* 2EB440 003EB440 FC731026 */  addiu      $16, $16, %lo(jtbl_008873FC)
    /* 2EB444 003EB444 0000028E */  lw         $2, 0x0($16)
    /* 2EB448 003EB448 21186400 */  addu       $3, $3, $4
    /* 2EB44C 003EB44C 09F84000 */  jalr       $2
    /* 2EB450 003EB450 0000648C */   lw        $4, 0x0($3)
    /* 2EB454 003EB454 0000228E */  lw         $2, 0x0($17)
    /* 2EB458 003EB458 01004230 */  andi       $2, $2, 0x1
    /* 2EB45C 003EB45C 38004014 */  bnez       $2, .L003EB540
    /* 2EB460 003EB460 00000000 */   nop
  .L003EB464:
    /* 2EB464 003EB464 7100043C */  lui        $4, %hi(D_0070B7C0)
    /* 2EB468 003EB468 2D282002 */  daddu      $5, $17, $0
    /* 2EB46C 003EB46C 088F0F0C */  jal        func_003e3c20
    /* 2EB470 003EB470 C0B78424 */   addiu     $4, $4, %lo(D_0070B7C0)
    /* 2EB474 003EB474 C8B7848F */  lw         $4, -0x4838($28)
    /* 2EB478 003EB478 8800033C */  lui        $3, %hi(D_008872E0)
    /* 2EB47C 003EB47C E0726324 */  addiu      $3, $3, %lo(D_008872E0)
    /* 2EB480 003EB480 0000028E */  lw         $2, 0x0($16)
    /* 2EB484 003EB484 21186400 */  addu       $3, $3, $4
    /* 2EB488 003EB488 0000648C */  lw         $4, 0x0($3)
    /* 2EB48C 003EB48C 09F84000 */  jalr       $2
    /* 2EB490 003EB490 2D282002 */   daddu     $5, $17, $0
    /* 2EB494 003EB494 92000010 */  b          .L003EB6E0
    /* 2EB498 003EB498 2D100000 */   daddu     $2, $0, $0
  .L003EB49C:
    /* 2EB49C 003EB49C 0000028E */  lw         $2, 0x0($16)
    /* 2EB4A0 003EB4A0 01004230 */  andi       $2, $2, 0x1
    /* 2EB4A4 003EB4A4 10004014 */  bnez       $2, .L003EB4E8
    /* 2EB4A8 003EB4A8 00000000 */   nop
  .L003EB4AC:
    /* 2EB4AC 003EB4AC 7100043C */  lui        $4, %hi(D_0070B7C0)
    /* 2EB4B0 003EB4B0 2D280002 */  daddu      $5, $16, $0
    /* 2EB4B4 003EB4B4 088F0F0C */  jal        func_003e3c20
    /* 2EB4B8 003EB4B8 C0B78424 */   addiu     $4, $4, %lo(D_0070B7C0)
    /* 2EB4BC 003EB4BC C8B7848F */  lw         $4, -0x4838($28)
    /* 2EB4C0 003EB4C0 8800033C */  lui        $3, %hi(D_008872E0)
    /* 2EB4C4 003EB4C4 E0726324 */  addiu      $3, $3, %lo(D_008872E0)
    /* 2EB4C8 003EB4C8 8800023C */  lui        $2, %hi(jtbl_008873FC)
    /* 2EB4CC 003EB4CC FC73428C */  lw         $2, %lo(jtbl_008873FC)($2)
    /* 2EB4D0 003EB4D0 21186400 */  addu       $3, $3, $4
    /* 2EB4D4 003EB4D4 0000648C */  lw         $4, 0x0($3)
    /* 2EB4D8 003EB4D8 09F84000 */  jalr       $2
    /* 2EB4DC 003EB4DC 2D280002 */   daddu     $5, $16, $0
    /* 2EB4E0 003EB4E0 7F000010 */  b          .L003EB6E0
    /* 2EB4E4 003EB4E4 2D100000 */   daddu     $2, $0, $0
  .L003EB4E8:
    /* 2EB4E8 003EB4E8 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 2EB4EC 003EB4EC EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 2EB4F0 003EB4F0 09F84000 */  jalr       $2
    /* 2EB4F4 003EB4F4 1400048E */   lw        $4, 0x14($16)
    /* 2EB4F8 003EB4F8 140000AE */  sw         $0, 0x14($16)
    /* 2EB4FC 003EB4FC FEFF0224 */  addiu      $2, $0, -0x2
    /* 2EB500 003EB500 180000AE */  sw         $0, 0x18($16)
    /* 2EB504 003EB504 0000038E */  lw         $3, 0x0($16)
    /* 2EB508 003EB508 24106200 */  and        $2, $3, $2
    /* 2EB50C 003EB50C E7FF0010 */  b          .L003EB4AC
    /* 2EB510 003EB510 000002AE */   sw        $2, 0x0($16)
  .L003EB514:
    /* 2EB514 003EB514 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 2EB518 003EB518 EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 2EB51C 003EB51C 09F84000 */  jalr       $2
    /* 2EB520 003EB520 1400048E */   lw        $4, 0x14($16)
    /* 2EB524 003EB524 140000AE */  sw         $0, 0x14($16)
    /* 2EB528 003EB528 FEFF0224 */  addiu      $2, $0, -0x2
    /* 2EB52C 003EB52C 180000AE */  sw         $0, 0x18($16)
    /* 2EB530 003EB530 0000038E */  lw         $3, 0x0($16)
    /* 2EB534 003EB534 24106200 */  and        $2, $3, $2
    /* 2EB538 003EB538 B8FF0010 */  b          .L003EB41C
    /* 2EB53C 003EB53C 000002AE */   sw        $2, 0x0($16)
  .L003EB540:
    /* 2EB540 003EB540 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 2EB544 003EB544 EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 2EB548 003EB548 09F84000 */  jalr       $2
    /* 2EB54C 003EB54C 1400248E */   lw        $4, 0x14($17)
    /* 2EB550 003EB550 140020AE */  sw         $0, 0x14($17)
    /* 2EB554 003EB554 FEFF0224 */  addiu      $2, $0, -0x2
    /* 2EB558 003EB558 180020AE */  sw         $0, 0x18($17)
    /* 2EB55C 003EB55C 0000238E */  lw         $3, 0x0($17)
    /* 2EB560 003EB560 24106200 */  and        $2, $3, $2
    /* 2EB564 003EB564 BFFF0010 */  b          .L003EB464
    /* 2EB568 003EB568 000022AE */   sw        $2, 0x0($17)
  .L003EB56C:
    /* 2EB56C 003EB56C 2D200002 */  daddu      $4, $16, $0
    /* 2EB570 003EB570 A4A90F0C */  jal        func_003ea690
    /* 2EB574 003EB574 2D282002 */   daddu     $5, $17, $0
    /* 2EB578 003EB578 25004014 */  bnez       $2, .L003EB610
    /* 2EB57C 003EB57C 00000000 */   nop
    /* 2EB580 003EB580 0000028E */  lw         $2, 0x0($16)
    /* 2EB584 003EB584 01004230 */  andi       $2, $2, 0x1
    /* 2EB588 003EB588 3E004014 */  bnez       $2, .L003EB684
    /* 2EB58C 003EB58C 00000000 */   nop
  .L003EB590:
    /* 2EB590 003EB590 7100043C */  lui        $4, %hi(D_0070B7C0)
    /* 2EB594 003EB594 2D280002 */  daddu      $5, $16, $0
    /* 2EB598 003EB598 088F0F0C */  jal        func_003e3c20
    /* 2EB59C 003EB59C C0B78424 */   addiu     $4, $4, %lo(D_0070B7C0)
    /* 2EB5A0 003EB5A0 C8B7848F */  lw         $4, -0x4838($28)
    /* 2EB5A4 003EB5A4 2D280002 */  daddu      $5, $16, $0
    /* 2EB5A8 003EB5A8 8800033C */  lui        $3, %hi(D_008872E0)
    /* 2EB5AC 003EB5AC 8800103C */  lui        $16, %hi(jtbl_008873FC)
    /* 2EB5B0 003EB5B0 E0726324 */  addiu      $3, $3, %lo(D_008872E0)
    /* 2EB5B4 003EB5B4 FC731026 */  addiu      $16, $16, %lo(jtbl_008873FC)
    /* 2EB5B8 003EB5B8 0000028E */  lw         $2, 0x0($16)
    /* 2EB5BC 003EB5BC 21186400 */  addu       $3, $3, $4
    /* 2EB5C0 003EB5C0 09F84000 */  jalr       $2
    /* 2EB5C4 003EB5C4 0000648C */   lw        $4, 0x0($3)
    /* 2EB5C8 003EB5C8 0000228E */  lw         $2, 0x0($17)
    /* 2EB5CC 003EB5CC 01004230 */  andi       $2, $2, 0x1
    /* 2EB5D0 003EB5D0 37004014 */  bnez       $2, .L003EB6B0
    /* 2EB5D4 003EB5D4 00000000 */   nop
  .L003EB5D8:
    /* 2EB5D8 003EB5D8 7100043C */  lui        $4, %hi(D_0070B7C0)
    /* 2EB5DC 003EB5DC 2D282002 */  daddu      $5, $17, $0
    /* 2EB5E0 003EB5E0 088F0F0C */  jal        func_003e3c20
    /* 2EB5E4 003EB5E4 C0B78424 */   addiu     $4, $4, %lo(D_0070B7C0)
    /* 2EB5E8 003EB5E8 C8B7848F */  lw         $4, -0x4838($28)
    /* 2EB5EC 003EB5EC 8800033C */  lui        $3, %hi(D_008872E0)
    /* 2EB5F0 003EB5F0 E0726324 */  addiu      $3, $3, %lo(D_008872E0)
    /* 2EB5F4 003EB5F4 0000028E */  lw         $2, 0x0($16)
    /* 2EB5F8 003EB5F8 21186400 */  addu       $3, $3, $4
    /* 2EB5FC 003EB5FC 0000648C */  lw         $4, 0x0($3)
    /* 2EB600 003EB600 09F84000 */  jalr       $2
    /* 2EB604 003EB604 2D282002 */   daddu     $5, $17, $0
    /* 2EB608 003EB608 35000010 */  b          .L003EB6E0
    /* 2EB60C 003EB60C 2D100000 */   daddu     $2, $0, $0
  .L003EB610:
    /* 2EB610 003EB610 0000228E */  lw         $2, 0x0($17)
    /* 2EB614 003EB614 01004230 */  andi       $2, $2, 0x1
    /* 2EB618 003EB618 0B004010 */  beqz       $2, .L003EB648
    /* 2EB61C 003EB61C 00000000 */   nop
    /* 2EB620 003EB620 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 2EB624 003EB624 EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 2EB628 003EB628 09F84000 */  jalr       $2
    /* 2EB62C 003EB62C 1400248E */   lw        $4, 0x14($17)
    /* 2EB630 003EB630 140020AE */  sw         $0, 0x14($17)
    /* 2EB634 003EB634 FEFF0224 */  addiu      $2, $0, -0x2
    /* 2EB638 003EB638 180020AE */  sw         $0, 0x18($17)
    /* 2EB63C 003EB63C 0000238E */  lw         $3, 0x0($17)
    /* 2EB640 003EB640 24106200 */  and        $2, $3, $2
    /* 2EB644 003EB644 000022AE */  sw         $2, 0x0($17)
  .L003EB648:
    /* 2EB648 003EB648 7100043C */  lui        $4, %hi(D_0070B7C0)
    /* 2EB64C 003EB64C 2D282002 */  daddu      $5, $17, $0
    /* 2EB650 003EB650 088F0F0C */  jal        func_003e3c20
    /* 2EB654 003EB654 C0B78424 */   addiu     $4, $4, %lo(D_0070B7C0)
    /* 2EB658 003EB658 C8B7848F */  lw         $4, -0x4838($28)
    /* 2EB65C 003EB65C 8800033C */  lui        $3, %hi(D_008872E0)
    /* 2EB660 003EB660 E0726324 */  addiu      $3, $3, %lo(D_008872E0)
    /* 2EB664 003EB664 8800023C */  lui        $2, %hi(jtbl_008873FC)
    /* 2EB668 003EB668 FC73428C */  lw         $2, %lo(jtbl_008873FC)($2)
    /* 2EB66C 003EB66C 21186400 */  addu       $3, $3, $4
    /* 2EB670 003EB670 0000648C */  lw         $4, 0x0($3)
    /* 2EB674 003EB674 09F84000 */  jalr       $2
    /* 2EB678 003EB678 2D282002 */   daddu     $5, $17, $0
  .L003EB67C:
    /* 2EB67C 003EB67C 18000010 */  b          .L003EB6E0
    /* 2EB680 003EB680 2D100002 */   daddu     $2, $16, $0
  .L003EB684:
    /* 2EB684 003EB684 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 2EB688 003EB688 EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 2EB68C 003EB68C 09F84000 */  jalr       $2
    /* 2EB690 003EB690 1400048E */   lw        $4, 0x14($16)
    /* 2EB694 003EB694 140000AE */  sw         $0, 0x14($16)
    /* 2EB698 003EB698 FEFF0224 */  addiu      $2, $0, -0x2
    /* 2EB69C 003EB69C 180000AE */  sw         $0, 0x18($16)
    /* 2EB6A0 003EB6A0 0000038E */  lw         $3, 0x0($16)
    /* 2EB6A4 003EB6A4 24106200 */  and        $2, $3, $2
    /* 2EB6A8 003EB6A8 B9FF0010 */  b          .L003EB590
    /* 2EB6AC 003EB6AC 000002AE */   sw        $2, 0x0($16)
  .L003EB6B0:
    /* 2EB6B0 003EB6B0 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 2EB6B4 003EB6B4 EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 2EB6B8 003EB6B8 09F84000 */  jalr       $2
    /* 2EB6BC 003EB6BC 1400248E */   lw        $4, 0x14($17)
    /* 2EB6C0 003EB6C0 140020AE */  sw         $0, 0x14($17)
    /* 2EB6C4 003EB6C4 FEFF0224 */  addiu      $2, $0, -0x2
    /* 2EB6C8 003EB6C8 180020AE */  sw         $0, 0x18($17)
    /* 2EB6CC 003EB6CC 0000238E */  lw         $3, 0x0($17)
    /* 2EB6D0 003EB6D0 24106200 */  and        $2, $3, $2
    /* 2EB6D4 003EB6D4 C0FF0010 */  b          .L003EB5D8
    /* 2EB6D8 003EB6D8 000022AE */   sw        $2, 0x0($17)
  .L003EB6DC:
    /* 2EB6DC 003EB6DC 2D100000 */  daddu      $2, $0, $0
  .L003EB6E0:
    /* 2EB6E0 003EB6E0 2000BFDF */  ld         $31, 0x20($29)
    /* 2EB6E4 003EB6E4 1000B17B */  lq         $17, 0x10($29)
    /* 2EB6E8 003EB6E8 0000B07B */  lq         $16, 0x0($29)
    /* 2EB6EC 003EB6EC 0800E003 */  jr         $31
    /* 2EB6F0 003EB6F0 3000BD27 */   addiu     $29, $29, 0x30
    /* 2EB6F4 003EB6F4 00000000 */  nop
    /* 2EB6F8 003EB6F8 00000000 */  nop
    /* 2EB6FC 003EB6FC 00000000 */  nop
.size func_003eb3b0, 0x350
