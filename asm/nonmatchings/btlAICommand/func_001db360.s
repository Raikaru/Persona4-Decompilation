.section .text
.set noat
.set noreorder
glabel func_001db360
    /* DB360 001DB360 B0FFBD27 */  addiu      $29, $29, -0x50
    /* DB364 001DB364 4000BFFF */  sd         $31, 0x40($29)
    /* DB368 001DB368 3000B37F */  sq         $19, 0x30($29)
    /* DB36C 001DB36C 2000B27F */  sq         $18, 0x20($29)
    /* DB370 001DB370 1000B17F */  sq         $17, 0x10($29)
    /* DB374 001DB374 0000B07F */  sq         $16, 0x0($29)
    /* DB378 001DB378 2D98A000 */  daddu      $19, $5, $0
    /* DB37C 001DB37C 2D90C000 */  daddu      $18, $6, $0
    /* DB380 001DB380 3000918C */  lw         $17, 0x30($4)
    /* DB384 001DB384 A2002392 */  lbu        $3, 0xA2($17)
    /* DB388 001DB388 01000224 */  addiu      $2, $0, 0x1
    /* DB38C 001DB38C 10006214 */  bne        $3, $2, .L001DB3D0
    /* DB390 001DB390 00000000 */   nop
    /* DB394 001DB394 3C2C1300 */  dsll32     $5, $19, 16
    /* DB398 001DB398 3F2C0500 */  dsra32     $5, $5, 16
    /* DB39C 001DB39C 38E7070C */  jal        func_001f9ce0
    /* DB3A0 001DB3A0 00000000 */   nop
    /* DB3A4 001DB3A4 0A004014 */  bnez       $2, .L001DB3D0
    /* DB3A8 001DB3A8 00000000 */   nop
    /* DB3AC 001DB3AC FFFF6532 */  andi       $5, $19, 0xFFFF
    /* DB3B0 001DB3B0 A4002496 */  lhu        $4, 0xA4($17)
    /* DB3B4 001DB3B4 083D040C */  jal        func_0010f420
    /* DB3B8 001DB3B8 00000000 */   nop
    /* DB3BC 001DB3BC 04004014 */  bnez       $2, .L001DB3D0
    /* DB3C0 001DB3C0 00000000 */   nop
    /* DB3C4 001DB3C4 01000224 */  addiu      $2, $0, 0x1
    /* DB3C8 001DB3C8 65000010 */  b          .L001DB560
    /* DB3CC 001DB3CC 00000000 */   nop
  .L001DB3D0:
    /* DB3D0 001DB3D0 3C241300 */  dsll32     $4, $19, 16
    /* DB3D4 001DB3D4 3F240400 */  dsra32     $4, $4, 16
    /* DB3D8 001DB3D8 B8F5080C */  jal        func_0023d6e0
    /* DB3DC 001DB3DC 00000000 */   nop
    /* DB3E0 001DB3E0 2D804000 */  daddu      $16, $2, $0
    /* DB3E4 001DB3E4 01000224 */  addiu      $2, $0, 0x1
    /* DB3E8 001DB3E8 22004216 */  bne        $18, $2, .L001DB474
    /* DB3EC 001DB3EC 00000000 */   nop
    /* DB3F0 001DB3F0 0E00023C */  lui        $2, (0xE0001 >> 16)
    /* DB3F4 001DB3F4 01004234 */  ori        $2, $2, (0xE0001 & 0xFFFF)
    /* DB3F8 001DB3F8 24100202 */  and        $2, $16, $2
    /* DB3FC 001DB3FC 1D004014 */  bnez       $2, .L001DB474
    /* DB400 001DB400 00000000 */   nop
    /* DB404 001DB404 02000232 */  andi       $2, $16, 0x2
    /* DB408 001DB408 0C004010 */  beqz       $2, .L001DB43C
    /* DB40C 001DB40C 00000000 */   nop
    /* DB410 001DB410 640A248E */  lw         $4, 0xA64($17)
    /* DB414 001DB414 10000524 */  addiu      $5, $0, 0x10
    /* DB418 001DB418 A4CE080C */  jal        func_00233a90
    /* DB41C 001DB41C 00000000 */   nop
    /* DB420 001DB420 3C160200 */  dsll32     $2, $2, 24
    /* DB424 001DB424 3F160200 */  dsra32     $2, $2, 24
    /* DB428 001DB428 12004018 */  blez       $2, .L001DB474
    /* DB42C 001DB42C 00000000 */   nop
    /* DB430 001DB430 2D100000 */  daddu      $2, $0, $0
    /* DB434 001DB434 4A000010 */  b          .L001DB560
    /* DB438 001DB438 00000000 */   nop
  .L001DB43C:
    /* DB43C 001DB43C 40000232 */  andi       $2, $16, 0x40
    /* DB440 001DB440 0C004014 */  bnez       $2, .L001DB474
    /* DB444 001DB444 00000000 */   nop
    /* DB448 001DB448 640A248E */  lw         $4, 0xA64($17)
    /* DB44C 001DB44C 11000524 */  addiu      $5, $0, 0x11
    /* DB450 001DB450 A4CE080C */  jal        func_00233a90
    /* DB454 001DB454 00000000 */   nop
    /* DB458 001DB458 3C160200 */  dsll32     $2, $2, 24
    /* DB45C 001DB45C 3F160200 */  dsra32     $2, $2, 24
    /* DB460 001DB460 04004018 */  blez       $2, .L001DB474
    /* DB464 001DB464 00000000 */   nop
    /* DB468 001DB468 2D100000 */  daddu      $2, $0, $0
    /* DB46C 001DB46C 3C000010 */  b          .L001DB560
    /* DB470 001DB470 00000000 */   nop
  .L001DB474:
    /* DB474 001DB474 02000232 */  andi       $2, $16, 0x2
    /* DB478 001DB478 30004010 */  beqz       $2, .L001DB53C
    /* DB47C 001DB47C 00000000 */   nop
    /* DB480 001DB480 A2002392 */  lbu        $3, 0xA2($17)
    /* DB484 001DB484 01000224 */  addiu      $2, $0, 0x1
    /* DB488 001DB488 09006214 */  bne        $3, $2, .L001DB4B0
    /* DB48C 001DB48C 00000000 */   nop
    /* DB490 001DB490 640A228E */  lw         $2, 0xA64($17)
    /* DB494 001DB494 00004294 */  lhu        $2, 0x0($2)
    /* DB498 001DB498 00014230 */  andi       $2, $2, 0x100
    /* DB49C 001DB49C 27004010 */  beqz       $2, .L001DB53C
    /* DB4A0 001DB4A0 00000000 */   nop
    /* DB4A4 001DB4A4 2D100000 */  daddu      $2, $0, $0
    /* DB4A8 001DB4A8 2D000010 */  b          .L001DB560
    /* DB4AC 001DB4AC 00000000 */   nop
  .L001DB4B0:
    /* DB4B0 001DB4B0 640A248E */  lw         $4, 0xA64($17)
    /* DB4B4 001DB4B4 4CF8080C */  jal        func_0023e130
    /* DB4B8 001DB4B8 00000000 */   nop
    /* DB4BC 001DB4BC FFFF5030 */  andi       $16, $2, 0xFFFF
    /* DB4C0 001DB4C0 640A248E */  lw         $4, 0xA64($17)
    /* DB4C4 001DB4C4 50F8080C */  jal        func_0023e140
    /* DB4C8 001DB4C8 00000000 */   nop
    /* DB4CC 001DB4CC 2D400000 */  daddu      $8, $0, $0
    /* DB4D0 001DB4D0 FFFF0732 */  andi       $7, $16, 0xFFFF
    /* DB4D4 001DB4D4 F8010624 */  addiu      $6, $0, 0x1F8
    /* DB4D8 001DB4D8 F7010524 */  addiu      $5, $0, 0x1F7
    /* DB4DC 001DB4DC F6010424 */  addiu      $4, $0, 0x1F6
    /* DB4E0 001DB4E0 12000010 */  b          .L001DB52C
    /* DB4E4 001DB4E4 00000000 */   nop
  .L001DB4E8:
    /* DB4E8 001DB4E8 FFFF0331 */  andi       $3, $8, 0xFFFF
    /* DB4EC 001DB4EC 40180300 */  sll        $3, $3, 1
    /* DB4F0 001DB4F0 21184300 */  addu       $3, $2, $3
    /* DB4F4 001DB4F4 00006394 */  lhu        $3, 0x0($3)
    /* DB4F8 001DB4F8 07006610 */  beq        $3, $6, .L001DB518
    /* DB4FC 001DB4FC 00000000 */   nop
    /* DB500 001DB500 05006510 */  beq        $3, $5, .L001DB518
    /* DB504 001DB504 00000000 */   nop
    /* DB508 001DB508 03006410 */  beq        $3, $4, .L001DB518
    /* DB50C 001DB50C 00000000 */   nop
    /* DB510 001DB510 04000010 */  b          .L001DB524
    /* DB514 001DB514 00000000 */   nop
  .L001DB518:
    /* DB518 001DB518 2D100000 */  daddu      $2, $0, $0
    /* DB51C 001DB51C 10000010 */  b          .L001DB560
    /* DB520 001DB520 00000000 */   nop
  .L001DB524:
    /* DB524 001DB524 01000325 */  addiu      $3, $8, 0x1
    /* DB528 001DB528 FFFF6830 */  andi       $8, $3, 0xFFFF
  .L001DB52C:
    /* DB52C 001DB52C FFFF0331 */  andi       $3, $8, 0xFFFF
    /* DB530 001DB530 2A186700 */  slt        $3, $3, $7
    /* DB534 001DB534 ECFF6014 */  bnez       $3, .L001DB4E8
    /* DB538 001DB538 00000000 */   nop
  .L001DB53C:
    /* DB53C 001DB53C 3C2C1300 */  dsll32     $5, $19, 16
    /* DB540 001DB540 3F2C0500 */  dsra32     $5, $5, 16
    /* DB544 001DB544 640A248E */  lw         $4, 0xA64($17)
    /* DB548 001DB548 000A090C */  jal        func_00242800
    /* DB54C 001DB54C 00000000 */   nop
    /* DB550 001DB550 0007033C */  lui        $3, (0x7000000 >> 16)
    /* DB554 001DB554 24104300 */  and        $2, $2, $3
    /* DB558 001DB558 2B100200 */  sltu       $2, $0, $2
    /* DB55C 001DB55C 01004238 */  xori       $2, $2, 0x1
  .L001DB560:
    /* DB560 001DB560 4000BFDF */  ld         $31, 0x40($29)
    /* DB564 001DB564 3000B37B */  lq         $19, 0x30($29)
    /* DB568 001DB568 2000B27B */  lq         $18, 0x20($29)
    /* DB56C 001DB56C 1000B17B */  lq         $17, 0x10($29)
    /* DB570 001DB570 0000B07B */  lq         $16, 0x0($29)
    /* DB574 001DB574 5000BD27 */  addiu      $29, $29, 0x50
    /* DB578 001DB578 0800E003 */  jr         $31
    /* DB57C 001DB57C 00000000 */   nop
.size func_001db360, 0x220
