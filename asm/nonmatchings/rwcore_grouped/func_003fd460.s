.section .text
.set noat
.set noreorder
glabel func_003fd460
    /* 2FD460 003FD460 B0FFBD27 */  addiu      $29, $29, -0x50
    /* 2FD464 003FD464 4000BFFF */  sd         $31, 0x40($29)
    /* 2FD468 003FD468 3000B37F */  sq         $19, 0x30($29)
    /* 2FD46C 003FD46C 2000B27F */  sq         $18, 0x20($29)
    /* 2FD470 003FD470 1000B17F */  sq         $17, 0x10($29)
    /* 2FD474 003FD474 2D908000 */  daddu      $18, $4, $0
    /* 2FD478 003FD478 0000B07F */  sq         $16, 0x0($29)
    /* 2FD47C 003FD47C 2D88C000 */  daddu      $17, $6, $0
    /* 2FD480 003FD480 2300A290 */  lbu        $2, 0x23($5)
    /* 2FD484 003FD484 60004230 */  andi       $2, $2, 0x60
    /* 2FD488 003FD488 1D004010 */  beqz       $2, .L003FD500
    /* 2FD48C 003FD48C 2D80A000 */   daddu     $16, $5, $0
    /* 2FD490 003FD490 21000392 */  lbu        $3, 0x21($16)
    /* 2FD494 003FD494 80006230 */  andi       $2, $3, 0x80
    /* 2FD498 003FD498 19004014 */  bnez       $2, .L003FD500
    /* 2FD49C 003FD49C 00000000 */   nop
    /* 2FD4A0 003FD4A0 01003332 */  andi       $19, $17, 0x1
    /* 2FD4A4 003FD4A4 06006012 */  beqz       $19, .L003FD4C0
    /* 2FD4A8 003FD4A8 00000000 */   nop
    /* 2FD4AC 003FD4AC 40006230 */  andi       $2, $3, 0x40
    /* 2FD4B0 003FD4B0 03004014 */  bnez       $2, .L003FD4C0
    /* 2FD4B4 003FD4B4 00000000 */   nop
    /* 2FD4B8 003FD4B8 A43E100C */  jal        func_0040fa90
    /* 2FD4BC 003FD4BC 2D200002 */   daddu     $4, $16, $0
  .L003FD4C0:
    /* 2FD4C0 003FD4C0 0800028E */  lw         $2, 0x8($16)
    /* 2FD4C4 003FD4C4 06006016 */  bnez       $19, .L003FD4E0
    /* 2FD4C8 003FD4C8 000042AE */   sw        $2, 0x0($18)
  .L003FD4CC:
    /* 2FD4CC 003FD4CC 02002232 */  andi       $2, $17, 0x2
    /* 2FD4D0 003FD4D0 07004014 */  bnez       $2, .L003FD4F0
    /* 2FD4D4 003FD4D4 00000000 */   nop
  .L003FD4D8:
    /* 2FD4D8 003FD4D8 0A000010 */  b          .L003FD504
    /* 2FD4DC 003FD4DC 01000224 */   addiu     $2, $0, 0x1
  .L003FD4E0:
    /* 2FD4E0 003FD4E0 22000292 */  lbu        $2, 0x22($16)
    /* 2FD4E4 003FD4E4 10004234 */  ori        $2, $2, 0x10
    /* 2FD4E8 003FD4E8 F8FF0010 */  b          .L003FD4CC
    /* 2FD4EC 003FD4EC 220002A2 */   sb        $2, 0x22($16)
  .L003FD4F0:
    /* 2FD4F0 003FD4F0 22000292 */  lbu        $2, 0x22($16)
    /* 2FD4F4 003FD4F4 08004234 */  ori        $2, $2, 0x8
    /* 2FD4F8 003FD4F8 F7FF0010 */  b          .L003FD4D8
    /* 2FD4FC 003FD4FC 220002A2 */   sb        $2, 0x22($16)
  .L003FD500:
    /* 2FD500 003FD500 2D100000 */  daddu      $2, $0, $0
  .L003FD504:
    /* 2FD504 003FD504 4000BFDF */  ld         $31, 0x40($29)
    /* 2FD508 003FD508 3000B37B */  lq         $19, 0x30($29)
    /* 2FD50C 003FD50C 2000B27B */  lq         $18, 0x20($29)
    /* 2FD510 003FD510 1000B17B */  lq         $17, 0x10($29)
    /* 2FD514 003FD514 0000B07B */  lq         $16, 0x0($29)
    /* 2FD518 003FD518 0800E003 */  jr         $31
    /* 2FD51C 003FD51C 5000BD27 */   addiu     $29, $29, 0x50
.size func_003fd460, 0xc0
