.section .text
.set noat
.set noreorder
glabel func_003db490
    /* 2DB490 003DB490 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 2DB494 003DB494 3000BFFF */  sd         $31, 0x30($29)
    /* 2DB498 003DB498 2000B17F */  sq         $17, 0x20($29)
    /* 2DB49C 003DB49C 1000B07F */  sq         $16, 0x10($29)
    /* 2DB4A0 003DB4A0 2D888000 */  daddu      $17, $4, $0
    /* 2DB4A4 003DB4A4 0000B4E7 */  swc1       $f20, 0x0($29)
    /* 2DB4A8 003DB4A8 2D80A000 */  daddu      $16, $5, $0
    /* 2DB4AC 003DB4AC 0800B1AC */  sw         $17, 0x8($5)
    /* 2DB4B0 003DB4B0 2D300002 */  daddu      $6, $16, $0
    /* 2DB4B4 003DB4B4 0C00A0AC */  sw         $0, 0xC($5)
    /* 2DB4B8 003DB4B8 1000A0AC */  sw         $0, 0x10($5)
    /* 2DB4BC 003DB4BC 0400A48C */  lw         $4, 0x4($5)
    /* 2DB4C0 003DB4C0 3E00053C */  lui        $5, %hi(func_003db440)
    /* 2DB4C4 003DB4C4 C8280F0C */  jal        func_003ca320
    /* 2DB4C8 003DB4C8 40B4A524 */   addiu     $5, $5, %lo(func_003db440)
    /* 2DB4CC 003DB4CC 1000028E */  lw         $2, 0x10($16)
    /* 2DB4D0 003DB4D0 0300401C */  bgtz       $2, .L003DB4E0
    /* 2DB4D4 003DB4D4 00000000 */   nop
  .L003DB4D8:
    /* 2DB4D8 003DB4D8 16000010 */  b          .L003DB534
    /* 2DB4DC 003DB4DC 2D102002 */   daddu     $2, $17, $0
  .L003DB4E0:
    /* 2DB4E0 003DB4E0 00088244 */  mtc1       $2, $f1
    /* 2DB4E4 003DB4E4 0C0000C6 */  lwc1       $f0, 0xC($16)
    /* 2DB4E8 003DB4E8 60088046 */  cvt.s.w    $f1, $f1
    /* 2DB4EC 003DB4EC 03030146 */  div.s      $f12, $f0, $f1
    /* 2DB4F0 003DB4F0 00000000 */  nop
    /* 2DB4F4 003DB4F4 00000000 */  nop
    /* 2DB4F8 003DB4F8 5A2E110C */  jal        func_0044b968
    /* 2DB4FC 003DB4FC 00000000 */   nop
    /* 2DB500 003DB500 0040023C */  lui        $2, (0x40000000 >> 16)
    /* 2DB504 003DB504 00608244 */  mtc1       $2, $f12
    /* 2DB508 003DB508 5A2E110C */  jal        func_0044b968
    /* 2DB50C 003DB50C 06050046 */   mov.s     $f20, $f0
    /* 2DB510 003DB510 00000000 */  nop
    /* 2DB514 003DB514 00000000 */  nop
    /* 2DB518 003DB518 03A00046 */  div.s      $f0, $f20, $f0
    /* 2DB51C 003DB51C 00000000 */  nop
    /* 2DB520 003DB520 2D202002 */  daddu      $4, $17, $0
    /* 2DB524 003DB524 00DA0F0C */  jal        func_003f6800
    /* 2DB528 003DB528 07030046 */   neg.s     $f12, $f0
    /* 2DB52C 003DB52C EAFF0010 */  b          .L003DB4D8
    /* 2DB530 003DB530 00000000 */   nop
  .L003DB534:
    /* 2DB534 003DB534 3000BFDF */  ld         $31, 0x30($29)
    /* 2DB538 003DB538 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* 2DB53C 003DB53C 2000B17B */  lq         $17, 0x20($29)
    /* 2DB540 003DB540 1000B07B */  lq         $16, 0x10($29)
    /* 2DB544 003DB544 0800E003 */  jr         $31
    /* 2DB548 003DB548 4000BD27 */   addiu     $29, $29, 0x40
    /* 2DB54C 003DB54C 00000000 */  nop
.size func_003db490, 0xc0
