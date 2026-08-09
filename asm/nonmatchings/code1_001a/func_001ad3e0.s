.section .text
.set noat
.set noreorder
glabel func_001ad3e0
    /* AD3E0 001AD3E0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* AD3E4 001AD3E4 1000BFFF */  sd         $31, 0x10($29)
    /* AD3E8 001AD3E8 0000B07F */  sq         $16, 0x0($29)
    /* AD3EC 001AD3EC 2D808000 */  daddu      $16, $4, $0
    /* AD3F0 001AD3F0 1C04828C */  lw         $2, 0x41C($4)
    /* AD3F4 001AD3F4 1C004014 */  bnez       $2, .L001AD468
    /* AD3F8 001AD3F8 00000000 */   nop
    /* AD3FC 001AD3FC 000004DE */  ld         $4, 0x0($16)
    /* AD400 001AD400 FF3F023C */  lui        $2, (0x3FFFFFFF >> 16)
    /* AD404 001AD404 FFFF4234 */  ori        $2, $2, (0x3FFFFFFF & 0xFFFF)
    /* AD408 001AD408 3C180200 */  dsll32     $3, $2, 0
    /* AD40C 001AD40C FFFF0234 */  ori        $2, $0, 0xFFFF
    /* AD410 001AD410 38140200 */  dsll       $2, $2, 16
    /* AD414 001AD414 FFFF4234 */  ori        $2, $2, 0xFFFF
    /* AD418 001AD418 25284300 */  or         $5, $2, $3
    /* AD41C 001AD41C FC4E060C */  jal        func_00193bf0
    /* AD420 001AD420 00000000 */   nop
    /* AD424 001AD424 3F004014 */  bnez       $2, .L001AD524
    /* AD428 001AD428 00000000 */   nop
    /* AD42C 001AD42C ACB3828F */  lw         $2, -0x4C54($28)
    /* AD430 001AD430 D40D448C */  lw         $4, 0xDD4($2)
    /* AD434 001AD434 2D280002 */  daddu      $5, $16, $0
    /* AD438 001AD438 0861080C */  jal        func_00218420
    /* AD43C 001AD43C 00000000 */   nop
    /* AD440 001AD440 3CEA070C */  jal        func_001fa8f0
    /* AD444 001AD444 00000000 */   nop
    /* AD448 001AD448 2D204000 */  daddu      $4, $2, $0
    /* AD44C 001AD44C 000003DE */  ld         $3, 0x0($16)
    /* AD450 001AD450 600043FC */  sd         $3, 0x60($2)
    /* AD454 001AD454 01000524 */  addiu      $5, $0, 0x1
    /* AD458 001AD458 6451060C */  jal        func_00194590
    /* AD45C 001AD45C 00000000 */   nop
    /* AD460 001AD460 01000224 */  addiu      $2, $0, 0x1
    /* AD464 001AD464 1C0402AE */  sw         $2, 0x41C($16)
  .L001AD468:
    /* AD468 001AD468 ACB3828F */  lw         $2, -0x4C54($28)
    /* AD46C 001AD46C D40D448C */  lw         $4, 0xDD4($2)
    /* AD470 001AD470 2861080C */  jal        func_002184a0
    /* AD474 001AD474 00000000 */   nop
    /* AD478 001AD478 2A004010 */  beqz       $2, .L001AD524
    /* AD47C 001AD47C 00000000 */   nop
    /* AD480 001AD480 18AE070C */  jal        func_001eb860
    /* AD484 001AD484 00000000 */   nop
    /* AD488 001AD488 01000524 */  addiu      $5, $0, 0x1
    /* AD48C 001AD48C 09004514 */  bne        $2, $5, .L001AD4B4
    /* AD490 001AD490 00000000 */   nop
    /* AD494 001AD494 ACB3838F */  lw         $3, -0x4C54($28)
    /* AD498 001AD498 0C00628C */  lw         $2, 0xC($3)
    /* AD49C 001AD49C 00204234 */  ori        $2, $2, 0x2000
    /* AD4A0 001AD4A0 0C0062AC */  sw         $2, 0xC($3)
    /* AD4A4 001AD4A4 ACB3828F */  lw         $2, -0x4C54($28)
    /* AD4A8 001AD4A8 D40D448C */  lw         $4, 0xDD4($2)
    /* AD4AC 001AD4AC 9048080C */  jal        func_00212240
    /* AD4B0 001AD4B0 00000000 */   nop
  .L001AD4B4:
    /* AD4B4 001AD4B4 ACB3828F */  lw         $2, -0x4C54($28)
    /* AD4B8 001AD4B8 D40D448C */  lw         $4, 0xDD4($2)
    /* AD4BC 001AD4BC 3461080C */  jal        func_002184d0
    /* AD4C0 001AD4C0 00000000 */   nop
    /* AD4C4 001AD4C4 07004014 */  bnez       $2, .L001AD4E4
    /* AD4C8 001AD4C8 00000000 */   nop
    /* AD4CC 001AD4CC 2D200002 */  daddu      $4, $16, $0
    /* AD4D0 001AD4D0 1D000524 */  addiu      $5, $0, 0x1D
    /* AD4D4 001AD4D4 00C2060C */  jal        func_001b0800
    /* AD4D8 001AD4D8 00000000 */   nop
    /* AD4DC 001AD4DC 05000010 */  b          .L001AD4F4
    /* AD4E0 001AD4E0 00000000 */   nop
  .L001AD4E4:
    /* AD4E4 001AD4E4 2D200002 */  daddu      $4, $16, $0
    /* AD4E8 001AD4E8 20000524 */  addiu      $5, $0, 0x20
    /* AD4EC 001AD4EC 00C2060C */  jal        func_001b0800
    /* AD4F0 001AD4F0 00000000 */   nop
  .L001AD4F4:
    /* AD4F4 001AD4F4 98EA070C */  jal        func_001faa60
    /* AD4F8 001AD4F8 00000000 */   nop
    /* AD4FC 001AD4FC 2D204000 */  daddu      $4, $2, $0
    /* AD500 001AD500 000003DE */  ld         $3, 0x0($16)
    /* AD504 001AD504 600043FC */  sd         $3, 0x60($2)
    /* AD508 001AD508 01000524 */  addiu      $5, $0, 0x1
    /* AD50C 001AD50C 6451060C */  jal        func_00194590
    /* AD510 001AD510 00000000 */   nop
    /* AD514 001AD514 ACB3828F */  lw         $2, -0x4C54($28)
    /* AD518 001AD518 D40D448C */  lw         $4, 0xDD4($2)
    /* AD51C 001AD51C 4061080C */  jal        func_00218500
    /* AD520 001AD520 00000000 */   nop
  .L001AD524:
    /* AD524 001AD524 1000BFDF */  ld         $31, 0x10($29)
    /* AD528 001AD528 0000B07B */  lq         $16, 0x0($29)
    /* AD52C 001AD52C 2000BD27 */  addiu      $29, $29, 0x20
    /* AD530 001AD530 0800E003 */  jr         $31
    /* AD534 001AD534 00000000 */   nop
    /* AD538 001AD538 00000000 */  nop
    /* AD53C 001AD53C 00000000 */  nop
.size func_001ad3e0, 0x160
