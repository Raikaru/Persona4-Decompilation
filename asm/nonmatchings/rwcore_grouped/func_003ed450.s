.section .text
.set noat
.set noreorder
glabel func_003ed450
    /* 2ED450 003ED450 90FFBD27 */  addiu      $29, $29, -0x70
    /* 2ED454 003ED454 6000BFFF */  sd         $31, 0x60($29)
    /* 2ED458 003ED458 5000B57F */  sq         $21, 0x50($29)
    /* 2ED45C 003ED45C 4000B47F */  sq         $20, 0x40($29)
    /* 2ED460 003ED460 2DA88000 */  daddu      $21, $4, $0
    /* 2ED464 003ED464 3000B37F */  sq         $19, 0x30($29)
    /* 2ED468 003ED468 2DA0A000 */  daddu      $20, $5, $0
    /* 2ED46C 003ED46C 2000B27F */  sq         $18, 0x20($29)
    /* 2ED470 003ED470 1000B17F */  sq         $17, 0x10($29)
    /* 2ED474 003ED474 1E00A012 */  beqz       $21, .L003ED4F0
    /* 2ED478 003ED478 0000B07F */   sq        $16, 0x0($29)
  .L003ED47C:
    /* 2ED47C 003ED47C 0300A292 */  lbu        $2, 0x3($21)
    /* 2ED480 003ED480 25988202 */  or         $19, $20, $2
    /* 2ED484 003ED484 04006232 */  andi       $2, $19, 0x4
    /* 2ED488 003ED488 1B004014 */  bnez       $2, .L003ED4F8
    /* 2ED48C 003ED48C 0300B126 */   addiu     $17, $21, 0x3
  .L003ED490:
    /* 2ED490 003ED490 9000B28E */  lw         $18, 0x90($21)
    /* 2ED494 003ED494 9000B026 */  addiu      $16, $21, 0x90
    /* 2ED498 003ED498 0B005012 */  beq        $18, $16, .L003ED4C8
    /* 2ED49C 003ED49C 00000000 */   nop
    /* 2ED4A0 003ED4A0 09005012 */  beq        $18, $16, .L003ED4C8
    /* 2ED4A4 003ED4A4 00000000 */   nop
  .L003ED4A8:
    /* 2ED4A8 003ED4A8 0800428E */  lw         $2, 0x8($18)
    /* 2ED4AC 003ED4AC 09F84000 */  jalr       $2
    /* 2ED4B0 003ED4B0 F8FF4426 */   addiu     $4, $18, -0x8
    /* 2ED4B4 003ED4B4 0000528E */  lw         $18, 0x0($18)
    /* 2ED4B8 003ED4B8 00000000 */  nop
    /* 2ED4BC 003ED4BC FAFF5016 */  bne        $18, $16, .L003ED4A8
    /* 2ED4C0 003ED4C0 00000000 */   nop
    /* 2ED4C4 003ED4C4 00000000 */  nop
  .L003ED4C8:
    /* 2ED4C8 003ED4C8 00002392 */  lbu        $3, 0x0($17)
    /* 2ED4CC 003ED4CC F3FF0224 */  addiu      $2, $0, -0xD
    /* 2ED4D0 003ED4D0 24106200 */  and        $2, $3, $2
    /* 2ED4D4 003ED4D4 0300A2A2 */  sb         $2, 0x3($21)
    /* 2ED4D8 003ED4D8 9800A48E */  lw         $4, 0x98($21)
    /* 2ED4DC 003ED4DC 14B50F0C */  jal        func_003ed450
    /* 2ED4E0 003ED4E0 2D286002 */   daddu     $5, $19, $0
    /* 2ED4E4 003ED4E4 9C00B58E */  lw         $21, 0x9C($21)
    /* 2ED4E8 003ED4E8 E4FFA016 */  bnez       $21, .L003ED47C
    /* 2ED4EC 003ED4EC 00000000 */   nop
  .L003ED4F0:
    /* 2ED4F0 003ED4F0 09000010 */  b          .L003ED518
    /* 2ED4F4 003ED4F4 00000000 */   nop
  .L003ED4F8:
    /* 2ED4F8 003ED4F8 0400A28E */  lw         $2, 0x4($21)
    /* 2ED4FC 003ED4FC 5000A426 */  addiu      $4, $21, 0x50
    /* 2ED500 003ED500 1000A526 */  addiu      $5, $21, 0x10
    /* 2ED504 003ED504 7C810F0C */  jal        func_003e05f0
    /* 2ED508 003ED508 50004624 */   addiu     $6, $2, 0x50
    /* 2ED50C 003ED50C E0FF0010 */  b          .L003ED490
    /* 2ED510 003ED510 00000000 */   nop
    /* 2ED514 003ED514 00000000 */  nop
  .L003ED518:
    /* 2ED518 003ED518 6000BFDF */  ld         $31, 0x60($29)
    /* 2ED51C 003ED51C 5000B57B */  lq         $21, 0x50($29)
    /* 2ED520 003ED520 4000B47B */  lq         $20, 0x40($29)
    /* 2ED524 003ED524 3000B37B */  lq         $19, 0x30($29)
    /* 2ED528 003ED528 2000B27B */  lq         $18, 0x20($29)
    /* 2ED52C 003ED52C 1000B17B */  lq         $17, 0x10($29)
    /* 2ED530 003ED530 0000B07B */  lq         $16, 0x0($29)
    /* 2ED534 003ED534 0800E003 */  jr         $31
    /* 2ED538 003ED538 7000BD27 */   addiu     $29, $29, 0x70
    /* 2ED53C 003ED53C 00000000 */  nop
.size func_003ed450, 0xf0
