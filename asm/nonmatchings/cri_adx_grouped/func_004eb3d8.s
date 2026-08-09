.section .text
.set noat
.set noreorder
glabel func_004eb3d8
    /* 3EB3D8 004EB3D8 7400023C */  lui        $2, %hi(D_0073A748)
    /* 3EB3DC 004EB3DC B0FFBD27 */  addiu      $29, $29, -0x50
    /* 3EB3E0 004EB3E0 48A7438C */  lw         $3, %lo(D_0073A748)($2)
    /* 3EB3E4 004EB3E4 0000B0FF */  sd         $16, 0x0($29)
    /* 3EB3E8 004EB3E8 0800B1FF */  sd         $17, 0x8($29)
    /* 3EB3EC 004EB3EC 1000B2FF */  sd         $18, 0x10($29)
    /* 3EB3F0 004EB3F0 1800B3FF */  sd         $19, 0x18($29)
    /* 3EB3F4 004EB3F4 2000B4FF */  sd         $20, 0x20($29)
    /* 3EB3F8 004EB3F8 2800B5FF */  sd         $21, 0x28($29)
    /* 3EB3FC 004EB3FC 3000B6FF */  sd         $22, 0x30($29)
    /* 3EB400 004EB400 3800B7FF */  sd         $23, 0x38($29)
    /* 3EB404 004EB404 4000BEFF */  sd         $30, 0x40($29)
    /* 3EB408 004EB408 09006014 */  bnez       $3, .L004EB430
    /* 3EB40C 004EB40C 4800BFFF */   sd        $31, 0x48($29)
    /* 3EB410 004EB410 0400023C */  lui        $2, (0x41000 >> 16)
    /* 3EB414 004EB414 7400153C */  lui        $21, %hi(D_0073A740)
    /* 3EB418 004EB418 10000324 */  addiu      $3, $0, 0x10
    /* 3EB41C 004EB41C 7400043C */  lui        $4, %hi(D_0073A744)
    /* 3EB420 004EB420 00104234 */  ori        $2, $2, (0x41000 & 0xFFFF)
    /* 3EB424 004EB424 40A7A3AE */  sw         $3, %lo(D_0073A740)($21)
    /* 3EB428 004EB428 02000010 */  b          .L004EB434
    /* 3EB42C 004EB42C 44A782AC */   sw        $2, %lo(D_0073A744)($4)
  .L004EB430:
    /* 3EB430 004EB430 7400153C */  lui        $21, %hi(D_0073A740)
  .L004EB434:
    /* 3EB434 004EB434 7400133C */  lui        $19, %hi(D_0073A74C)
    /* 3EB438 004EB438 4CA77026 */  addiu      $16, $19, %lo(D_0073A74C)
    /* 3EB43C 004EB43C 0000028E */  lw         $2, 0x0($16)
    /* 3EB440 004EB440 25004054 */  bnel       $2, $0, .L004EB4D8
    /* 3EB444 004EB444 7400103C */   lui       $16, %hi(D_0073A750)
    /* 3EB448 004EB448 7400123C */  lui        $18, %hi(D_0073A744)
    /* 3EB44C 004EB44C 44A75126 */  addiu      $17, $18, %lo(D_0073A744)
    /* 3EB450 004EB450 0000248E */  lw         $4, 0x0($17)
    /* 3EB454 004EB454 28A7100C */  jal        func_00429ca0
    /* 3EB458 004EB458 40008424 */   addiu     $4, $4, 0x40
    /* 3EB45C 004EB45C 0E004014 */  bnez       $2, .L004EB498
    /* 3EB460 004EB460 000002AE */   sw        $2, 0x0($16)
    /* 3EB464 004EB464 0000258E */  lw         $5, 0x0($17)
    /* 3EB468 004EB468 7600043C */  lui        $4, %hi(D_0075C758)
    /* 3EB46C 004EB46C 58C78424 */  addiu      $4, $4, %lo(D_0075C758)
    /* 3EB470 004EB470 FC34130C */  jal        func_004cd3f0
    /* 3EB474 004EB474 4000A524 */   addiu     $5, $5, 0x40
  .L004EB478:
    /* 3EB478 004EB478 00000000 */  nop
    /* 3EB47C 004EB47C 00000000 */  nop
    /* 3EB480 004EB480 00000000 */  nop
    /* 3EB484 004EB484 00000000 */  nop
    /* 3EB488 004EB488 00000000 */  nop
    /* 3EB48C 004EB48C FAFF0010 */  b          .L004EB478
    /* 3EB490 004EB490 00000000 */   nop
    /* 3EB494 004EB494 00000000 */  nop
  .L004EB498:
    /* 3EB498 004EB498 4CA77026 */  addiu      $16, $19, %lo(D_0073A74C)
    /* 3EB49C 004EB49C 44A7458E */  lw         $5, %lo(D_0073A744)($18)
    /* 3EB4A0 004EB4A0 0000068E */  lw         $6, 0x0($16)
    /* 3EB4A4 004EB4A4 7600043C */  lui        $4, %hi(D_0075C7A0)
    /* 3EB4A8 004EB4A8 A0C78424 */  addiu      $4, $4, %lo(D_0075C7A0)
    /* 3EB4AC 004EB4AC FC34130C */  jal        func_004cd3f0
    /* 3EB4B0 004EB4B0 4000A524 */   addiu     $5, $5, 0x40
    /* 3EB4B4 004EB4B4 0000038E */  lw         $3, 0x0($16)
    /* 3EB4B8 004EB4B8 C0FF0524 */  addiu      $5, $0, -0x40
    /* 3EB4BC 004EB4BC 7400043C */  lui        $4, %hi(D_0073A754)
    /* 3EB4C0 004EB4C0 40006324 */  addiu      $3, $3, 0x40
    /* 3EB4C4 004EB4C4 7400103C */  lui        $16, %hi(D_0073A750)
    /* 3EB4C8 004EB4C8 24186500 */  and        $3, $3, $5
    /* 3EB4CC 004EB4CC 01000224 */  addiu      $2, $0, 0x1
    /* 3EB4D0 004EB4D0 54A782A0 */  sb         $2, %lo(D_0073A754)($4)
    /* 3EB4D4 004EB4D4 50A703AE */  sw         $3, %lo(D_0073A750)($16)
  .L004EB4D8:
    /* 3EB4D8 004EB4D8 7400143C */  lui        $20, %hi(D_0073A7A0)
    /* 3EB4DC 004EB4DC 2D280000 */  daddu      $5, $0, $0
    /* 3EB4E0 004EB4E0 A0A78426 */  addiu      $4, $20, %lo(D_0073A7A0)
    /* 3EB4E4 004EB4E4 72FE100C */  jal        func_0043f9c8
    /* 3EB4E8 004EB4E8 00030624 */   addiu     $6, $0, 0x300
    /* 3EB4EC 004EB4EC 50A7118E */  lw         $17, %lo(D_0073A750)($16)
    /* 3EB4F0 004EB4F0 40A7A28E */  lw         $2, %lo(D_0073A740)($21)
    /* 3EB4F4 004EB4F4 6A004018 */  blez       $2, .L004EB6A0
    /* 3EB4F8 004EB4F8 2D900000 */   daddu     $18, $0, $0
    /* 3EB4FC 004EB4FC 7400163C */  lui        $22, %hi(D_0073AAA0)
    /* 3EB500 004EB500 2D980000 */  daddu      $19, $0, $0
    /* 3EB504 004EB504 76001E3C */  lui        $30, %hi(D_0075C868)
    /* 3EB508 004EB508 7600173C */  lui        $23, %hi(D_0075C8A0)
    /* 3EB50C 004EB50C A0A78226 */  addiu      $2, $20, %lo(D_0073A7A0)
  .L004EB510:
    /* 3EB510 004EB510 3F002332 */  andi       $3, $17, 0x3F
    /* 3EB514 004EB514 21806202 */  addu       $16, $19, $2
    /* 3EB518 004EB518 18007326 */  addiu      $19, $19, 0x18
    /* 3EB51C 004EB51C 0C006010 */  beqz       $3, .L004EB550
    /* 3EB520 004EB520 000000A2 */   sb        $0, 0x0($16)
    /* 3EB524 004EB524 7600023C */  lui        $2, %hi(D_0075C7D0)
    /* 3EB528 004EB528 FC34130C */  jal        func_004cd3f0
    /* 3EB52C 004EB52C D0C74424 */   addiu     $4, $2, %lo(D_0075C7D0)
  .L004EB530:
    /* 3EB530 004EB530 00000000 */  nop
    /* 3EB534 004EB534 00000000 */  nop
    /* 3EB538 004EB538 00000000 */  nop
    /* 3EB53C 004EB53C 00000000 */  nop
    /* 3EB540 004EB540 00000000 */  nop
    /* 3EB544 004EB544 FAFF0010 */  b          .L004EB530
    /* 3EB548 004EB548 00000000 */   nop
    /* 3EB54C 004EB54C 00000000 */  nop
  .L004EB550:
    /* 3EB550 004EB550 2D282002 */  daddu      $5, $17, $0
    /* 3EB554 004EB554 00013126 */  addiu      $17, $17, 0x100
    /* 3EB558 004EB558 01000424 */  addiu      $4, $0, 0x1
    /* 3EB55C 004EB55C 1CBF130C */  jal        func_004efc70
    /* 3EB560 004EB560 00010624 */   addiu     $6, $0, 0x100
    /* 3EB564 004EB564 001A1200 */  sll        $3, $18, 8
    /* 3EB568 004EB568 A0AAC526 */  addiu      $5, $22, %lo(D_0073AAA0)
    /* 3EB56C 004EB56C 01000424 */  addiu      $4, $0, 0x1
    /* 3EB570 004EB570 21286500 */  addu       $5, $3, $5
    /* 3EB574 004EB574 3F002332 */  andi       $3, $17, 0x3F
    /* 3EB578 004EB578 01005226 */  addiu      $18, $18, 0x1
    /* 3EB57C 004EB57C 00010624 */  addiu      $6, $0, 0x100
    /* 3EB580 004EB580 0D004014 */  bnez       $2, .L004EB5B8
    /* 3EB584 004EB584 040002AE */   sw        $2, 0x4($16)
    /* 3EB588 004EB588 7600023C */  lui        $2, %hi(D_0075C800)
    /* 3EB58C 004EB58C FC34130C */  jal        func_004cd3f0
    /* 3EB590 004EB590 00C84424 */   addiu     $4, $2, %lo(D_0075C800)
    /* 3EB594 004EB594 00000000 */  nop
  .L004EB598:
    /* 3EB598 004EB598 00000000 */  nop
    /* 3EB59C 004EB59C 00000000 */  nop
    /* 3EB5A0 004EB5A0 00000000 */  nop
    /* 3EB5A4 004EB5A4 00000000 */  nop
    /* 3EB5A8 004EB5A8 00000000 */  nop
    /* 3EB5AC 004EB5AC FAFF0010 */  b          .L004EB598
    /* 3EB5B0 004EB5B0 00000000 */   nop
    /* 3EB5B4 004EB5B4 00000000 */  nop
  .L004EB5B8:
    /* 3EB5B8 004EB5B8 0B006010 */  beqz       $3, .L004EB5E8
    /* 3EB5BC 004EB5BC 7600023C */   lui       $2, %hi(D_0075C838)
    /* 3EB5C0 004EB5C0 FC34130C */  jal        func_004cd3f0
    /* 3EB5C4 004EB5C4 38C84424 */   addiu     $4, $2, %lo(D_0075C838)
  .L004EB5C8:
    /* 3EB5C8 004EB5C8 00000000 */  nop
    /* 3EB5CC 004EB5CC 00000000 */  nop
    /* 3EB5D0 004EB5D0 00000000 */  nop
    /* 3EB5D4 004EB5D4 00000000 */  nop
    /* 3EB5D8 004EB5D8 00000000 */  nop
    /* 3EB5DC 004EB5DC FAFF0010 */  b          .L004EB5C8
    /* 3EB5E0 004EB5E0 00000000 */   nop
    /* 3EB5E4 004EB5E4 00000000 */  nop
  .L004EB5E8:
    /* 3EB5E8 004EB5E8 08BB130C */  jal        func_004eec20
    /* 3EB5EC 004EB5EC 00000000 */   nop
    /* 3EB5F0 004EB5F0 00400324 */  addiu      $3, $0, 0x4000
    /* 3EB5F4 004EB5F4 080002AE */  sw         $2, 0x8($16)
    /* 3EB5F8 004EB5F8 2D280000 */  daddu      $5, $0, $0
    /* 3EB5FC 004EB5FC 0C004014 */  bnez       $2, .L004EB630
    /* 3EB600 004EB600 10000626 */   addiu     $6, $16, 0x10
    /* 3EB604 004EB604 FC34130C */  jal        func_004cd3f0
    /* 3EB608 004EB608 68C8C427 */   addiu     $4, $30, %lo(D_0075C868)
    /* 3EB60C 004EB60C 00000000 */  nop
  .L004EB610:
    /* 3EB610 004EB610 00000000 */  nop
    /* 3EB614 004EB614 00000000 */  nop
    /* 3EB618 004EB618 00000000 */  nop
    /* 3EB61C 004EB61C 00000000 */  nop
    /* 3EB620 004EB620 00000000 */  nop
    /* 3EB624 004EB624 FAFF0010 */  b          .L004EB610
    /* 3EB628 004EB628 00000000 */   nop
    /* 3EB62C 004EB62C 00000000 */  nop
  .L004EB630:
    /* 3EB630 004EB630 0800048E */  lw         $4, 0x8($16)
    /* 3EB634 004EB634 140003AE */  sw         $3, 0x14($16)
    /* 3EB638 004EB638 0000838C */  lw         $3, 0x0($4)
    /* 3EB63C 004EB63C 100011AE */  sw         $17, 0x10($16)
    /* 3EB640 004EB640 2000628C */  lw         $2, 0x20($3)
    /* 3EB644 004EB644 09F84000 */  jalr       $2
    /* 3EB648 004EB648 00403126 */   addiu     $17, $17, 0x4000
    /* 3EB64C 004EB64C 0800048E */  lw         $4, 0x8($16)
    /* 3EB650 004EB650 0400058E */  lw         $5, 0x4($16)
    /* 3EB654 004EB654 F2C0130C */  jal        func_004f03c8
    /* 3EB658 004EB658 01000624 */   addiu     $6, $0, 0x1
    /* 3EB65C 004EB65C 0C004014 */  bnez       $2, .L004EB690
    /* 3EB660 004EB660 0C0002AE */   sw        $2, 0xC($16)
    /* 3EB664 004EB664 FC34130C */  jal        func_004cd3f0
    /* 3EB668 004EB668 A0C8E426 */   addiu     $4, $23, %lo(D_0075C8A0)
    /* 3EB66C 004EB66C 00000000 */  nop
  .L004EB670:
    /* 3EB670 004EB670 00000000 */  nop
    /* 3EB674 004EB674 00000000 */  nop
    /* 3EB678 004EB678 00000000 */  nop
    /* 3EB67C 004EB67C 00000000 */  nop
    /* 3EB680 004EB680 00000000 */  nop
    /* 3EB684 004EB684 FAFF0010 */  b          .L004EB670
    /* 3EB688 004EB688 00000000 */   nop
    /* 3EB68C 004EB68C 00000000 */  nop
  .L004EB690:
    /* 3EB690 004EB690 40A7A28E */  lw         $2, %lo(D_0073A740)($21)
    /* 3EB694 004EB694 2A104202 */  slt        $2, $18, $2
    /* 3EB698 004EB698 9DFF4014 */  bnez       $2, .L004EB510
    /* 3EB69C 004EB69C A0A78226 */   addiu     $2, $20, %lo(D_0073A7A0)
  .L004EB6A0:
    /* 3EB6A0 004EB6A0 0000B0DF */  ld         $16, 0x0($29)
    /* 3EB6A4 004EB6A4 0800B1DF */  ld         $17, 0x8($29)
    /* 3EB6A8 004EB6A8 1000B2DF */  ld         $18, 0x10($29)
    /* 3EB6AC 004EB6AC 1800B3DF */  ld         $19, 0x18($29)
    /* 3EB6B0 004EB6B0 2000B4DF */  ld         $20, 0x20($29)
    /* 3EB6B4 004EB6B4 2800B5DF */  ld         $21, 0x28($29)
    /* 3EB6B8 004EB6B8 3000B6DF */  ld         $22, 0x30($29)
    /* 3EB6BC 004EB6BC 3800B7DF */  ld         $23, 0x38($29)
    /* 3EB6C0 004EB6C0 4000BEDF */  ld         $30, 0x40($29)
    /* 3EB6C4 004EB6C4 4800BFDF */  ld         $31, 0x48($29)
    /* 3EB6C8 004EB6C8 0800E003 */  jr         $31
    /* 3EB6CC 004EB6CC 5000BD27 */   addiu     $29, $29, 0x50
.size func_004eb3d8, 0x2f8
