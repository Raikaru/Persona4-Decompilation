.section .text
.set noat
.set noreorder
glabel func_001bd390
    /* BD390 001BD390 A0FFBD27 */  addiu      $29, $29, -0x60
    /* BD394 001BD394 3000BFFF */  sd         $31, 0x30($29)
    /* BD398 001BD398 2000B27F */  sq         $18, 0x20($29)
    /* BD39C 001BD39C 1000B17F */  sq         $17, 0x10($29)
    /* BD3A0 001BD3A0 0000B07F */  sq         $16, 0x0($29)
    /* BD3A4 001BD3A4 485C110C */  jal        func_00457120
    /* BD3A8 001BD3A8 00000000 */   nop
    /* BD3AC 001BD3AC 0400438C */  lw         $3, 0x4($2)
    /* BD3B0 001BD3B0 10007024 */  addiu      $16, $3, 0x10
    /* BD3B4 001BD3B4 2D880000 */  daddu      $17, $0, $0
    /* BD3B8 001BD3B8 40000010 */  b          .L001BD4BC
    /* BD3BC 001BD3BC 00000000 */   nop
  .L001BD3C0:
    /* BD3C0 001BD3C0 FFFF2332 */  andi       $3, $17, 0xFFFF
    /* BD3C4 001BD3C4 C0200300 */  sll        $4, $3, 3
    /* BD3C8 001BD3C8 ACB3838F */  lw         $3, -0x4C54($28)
    /* BD3CC 001BD3CC 21186400 */  addu       $3, $3, $4
    /* BD3D0 001BD3D0 7801728C */  lw         $18, 0x178($3)
    /* BD3D4 001BD3D4 35000010 */  b          .L001BD4AC
    /* BD3D8 001BD3D8 00000000 */   nop
  .L001BD3DC:
    /* BD3DC 001BD3DC 640A448E */  lw         $4, 0xA64($18)
    /* BD3E0 001BD3E0 05008010 */  beqz       $4, .L001BD3F8
    /* BD3E4 001BD3E4 00000000 */   nop
    /* BD3E8 001BD3E8 600F090C */  jal        func_00243d80
    /* BD3EC 001BD3EC 00000000 */   nop
    /* BD3F0 001BD3F0 05004014 */  bnez       $2, .L001BD408
    /* BD3F4 001BD3F4 00000000 */   nop
  .L001BD3F8:
    /* BD3F8 001BD3F8 9C00438E */  lw         $3, 0x9C($18)
    /* BD3FC 001BD3FC 08006330 */  andi       $3, $3, 0x8
    /* BD400 001BD400 29006010 */  beqz       $3, .L001BD4A8
    /* BD404 001BD404 00000000 */   nop
  .L001BD408:
    /* BD408 001BD408 2D204002 */  daddu      $4, $18, $0
    /* BD40C 001BD40C 5000A527 */  addiu      $5, $29, 0x50
    /* BD410 001BD410 1456060C */  jal        func_00195850
    /* BD414 001BD414 00000000 */   nop
    /* BD418 001BD418 300001C6 */  lwc1       $f1, 0x30($16)
    /* BD41C 001BD41C 5000A0C7 */  lwc1       $f0, 0x50($29)
    /* BD420 001BD420 01080046 */  sub.s      $f0, $f1, $f0
    /* BD424 001BD424 4000A0E7 */  swc1       $f0, 0x40($29)
    /* BD428 001BD428 340001C6 */  lwc1       $f1, 0x34($16)
    /* BD42C 001BD42C 5400A0C7 */  lwc1       $f0, 0x54($29)
    /* BD430 001BD430 01080046 */  sub.s      $f0, $f1, $f0
    /* BD434 001BD434 4400A0E7 */  swc1       $f0, 0x44($29)
    /* BD438 001BD438 380001C6 */  lwc1       $f1, 0x38($16)
    /* BD43C 001BD43C 5800A0C7 */  lwc1       $f0, 0x58($29)
    /* BD440 001BD440 01080046 */  sub.s      $f0, $f1, $f0
    /* BD444 001BD444 4800A0E7 */  swc1       $f0, 0x48($29)
    /* BD448 001BD448 4000A427 */  addiu      $4, $29, 0x40
    /* BD44C 001BD44C 60900F0C */  jal        func_003e4180
    /* BD450 001BD450 00000000 */   nop
    /* BD454 001BD454 900044C6 */  lwc1       $f4, 0x90($18)
    /* BD458 001BD458 2C0043C6 */  lwc1       $f3, 0x2C($18)
    /* BD45C 001BD45C 4843023C */  lui        $2, (0x43480000 >> 16)
    /* BD460 001BD460 00108244 */  mtc1       $2, $f2
    /* BD464 001BD464 00088044 */  mtc1       $0, $f1
    /* BD468 001BD468 00000000 */  nop
    /* BD46C 001BD46C 18080246 */  adda.s     $f1, $f2
    /* BD470 001BD470 5C200346 */  madd.s     $f1, $f4, $f3
    /* BD474 001BD474 36000146 */  c.le.s     $f0, $f1
    /* BD478 001BD478 07000045 */  bc1f       .L001BD498
    /* BD47C 001BD47C 00000000 */   nop
    /* BD480 001BD480 2D204002 */  daddu      $4, $18, $0
    /* BD484 001BD484 01000524 */  addiu      $5, $0, 0x1
    /* BD488 001BD488 E853060C */  jal        func_00194fa0
    /* BD48C 001BD48C 00000000 */   nop
    /* BD490 001BD490 05000010 */  b          .L001BD4A8
    /* BD494 001BD494 00000000 */   nop
  .L001BD498:
    /* BD498 001BD498 2D204002 */  daddu      $4, $18, $0
    /* BD49C 001BD49C 01000524 */  addiu      $5, $0, 0x1
    /* BD4A0 001BD4A0 F053060C */  jal        func_00194fc0
    /* BD4A4 001BD4A4 00000000 */   nop
  .L001BD4A8:
    /* BD4A8 001BD4A8 6C0A528E */  lw         $18, 0xA6C($18)
  .L001BD4AC:
    /* BD4AC 001BD4AC CBFF4016 */  bnez       $18, .L001BD3DC
    /* BD4B0 001BD4B0 00000000 */   nop
    /* BD4B4 001BD4B4 01002326 */  addiu      $3, $17, 0x1
    /* BD4B8 001BD4B8 FFFF7130 */  andi       $17, $3, 0xFFFF
  .L001BD4BC:
    /* BD4BC 001BD4BC FFFF2332 */  andi       $3, $17, 0xFFFF
    /* BD4C0 001BD4C0 02006328 */  slti       $3, $3, 0x2
    /* BD4C4 001BD4C4 BEFF6014 */  bnez       $3, .L001BD3C0
    /* BD4C8 001BD4C8 00000000 */   nop
    /* BD4CC 001BD4CC 3000BFDF */  ld         $31, 0x30($29)
    /* BD4D0 001BD4D0 2000B27B */  lq         $18, 0x20($29)
    /* BD4D4 001BD4D4 1000B17B */  lq         $17, 0x10($29)
    /* BD4D8 001BD4D8 0000B07B */  lq         $16, 0x0($29)
    /* BD4DC 001BD4DC 6000BD27 */  addiu      $29, $29, 0x60
    /* BD4E0 001BD4E0 0800E003 */  jr         $31
    /* BD4E4 001BD4E4 00000000 */   nop
    /* BD4E8 001BD4E8 00000000 */  nop
    /* BD4EC 001BD4EC 00000000 */  nop
.size func_001bd390, 0x160
