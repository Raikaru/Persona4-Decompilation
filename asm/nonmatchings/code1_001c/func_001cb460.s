.section .text
.set noat
.set noreorder
glabel func_001cb460
    /* CB460 001CB460 D0FFBD27 */  addiu      $29, $29, -0x30
    /* CB464 001CB464 2000BFFF */  sd         $31, 0x20($29)
    /* CB468 001CB468 1000B17F */  sq         $17, 0x10($29)
    /* CB46C 001CB46C 0000B07F */  sq         $16, 0x0($29)
    /* CB470 001CB470 2D888000 */  daddu      $17, $4, $0
    /* CB474 001CB474 E000848C */  lw         $4, 0xE0($4)
    /* CB478 001CB478 3000828C */  lw         $2, 0x30($4)
    /* CB47C 001CB47C A4005094 */  lhu        $16, 0xA4($2)
    /* CB480 001CB480 FCC3070C */  jal        func_001f0ff0
    /* CB484 001CB484 00000000 */   nop
    /* CB488 001CB488 22004010 */  beqz       $2, .L001CB514
    /* CB48C 001CB48C 00000000 */   nop
    /* CB490 001CB490 2D200000 */  daddu      $4, $0, $0
    /* CB494 001CB494 14F4120C */  jal        func_004bd050
    /* CB498 001CB498 00000000 */   nop
    /* CB49C 001CB49C 01004330 */  andi       $3, $2, 0x1
    /* CB4A0 001CB4A0 00110300 */  sll        $2, $3, 4
    /* CB4A4 001CB4A4 23104300 */  subu       $2, $2, $3
    /* CB4A8 001CB4A8 80100200 */  sll        $2, $2, 2
    /* CB4AC 001CB4AC 21104300 */  addu       $2, $2, $3
    /* CB4B0 001CB4B0 80200200 */  sll        $4, $2, 2
    /* CB4B4 001CB4B4 FFFF0232 */  andi       $2, $16, 0xFFFF
    /* CB4B8 001CB4B8 FEFF4324 */  addiu      $3, $2, -0x2
    /* CB4BC 001CB4BC 00110300 */  sll        $2, $3, 4
    /* CB4C0 001CB4C0 23104300 */  subu       $2, $2, $3
    /* CB4C4 001CB4C4 80100200 */  sll        $2, $2, 2
    /* CB4C8 001CB4C8 21104300 */  addu       $2, $2, $3
    /* CB4CC 001CB4CC C0180200 */  sll        $3, $2, 3
    /* CB4D0 001CB4D0 6000023C */  lui        $2, %hi(D_005FA2D0)
    /* CB4D4 001CB4D4 D0A24224 */  addiu      $2, $2, %lo(D_005FA2D0)
    /* CB4D8 001CB4D8 21104300 */  addu       $2, $2, $3
    /* CB4DC 001CB4DC 21288200 */  addu       $5, $4, $2
    /* CB4E0 001CB4E0 2D202002 */  daddu      $4, $17, $0
    /* CB4E4 001CB4E4 02000624 */  addiu      $6, $0, 0x2
    /* CB4E8 001CB4E8 60F7060C */  jal        func_001bdd80
    /* CB4EC 001CB4EC 00000000 */   nop
    /* CB4F0 001CB4F0 00608044 */  mtc1       $0, $f12
    /* CB4F4 001CB4F4 E000248E */  lw         $4, 0xE0($17)
    /* CB4F8 001CB4F8 2D280000 */  daddu      $5, $0, $0
    /* CB4FC 001CB4FC 2D300000 */  daddu      $6, $0, $0
    /* CB500 001CB500 03000724 */  addiu      $7, $0, 0x3
    /* CB504 001CB504 50F3060C */  jal        func_001bcd40
    /* CB508 001CB508 00000000 */   nop
    /* CB50C 001CB50C 06000010 */  b          .L001CB528
    /* CB510 001CB510 00000000 */   nop
  .L001CB514:
    /* CB514 001CB514 2D202002 */  daddu      $4, $17, $0
    /* CB518 001CB518 2D280000 */  daddu      $5, $0, $0
    /* CB51C 001CB51C 01000624 */  addiu      $6, $0, 0x1
    /* CB520 001CB520 B80B070C */  jal        func_001c2ee0
    /* CB524 001CB524 00000000 */   nop
  .L001CB528:
    /* CB528 001CB528 2000BFDF */  ld         $31, 0x20($29)
    /* CB52C 001CB52C 1000B17B */  lq         $17, 0x10($29)
    /* CB530 001CB530 0000B07B */  lq         $16, 0x0($29)
    /* CB534 001CB534 3000BD27 */  addiu      $29, $29, 0x30
    /* CB538 001CB538 0800E003 */  jr         $31
    /* CB53C 001CB53C 00000000 */   nop
.size func_001cb460, 0xe0
