.section .text
.set noat
.set noreorder
glabel func_001bf3a0
    /* BF3A0 001BF3A0 C0FFBD27 */  addiu      $29, $29, -0x40
    /* BF3A4 001BF3A4 3000BFFF */  sd         $31, 0x30($29)
    /* BF3A8 001BF3A8 2000B27F */  sq         $18, 0x20($29)
    /* BF3AC 001BF3AC 1000B17F */  sq         $17, 0x10($29)
    /* BF3B0 001BF3B0 0000B07F */  sq         $16, 0x0($29)
    /* BF3B4 001BF3B4 2D908000 */  daddu      $18, $4, $0
    /* BF3B8 001BF3B8 ACB3838F */  lw         $3, -0x4C54($28)
    /* BF3BC 001BF3BC 08016494 */  lhu        $4, 0x108($3)
    /* BF3C0 001BF3C0 22000324 */  addiu      $3, $0, 0x22
    /* BF3C4 001BF3C4 03008310 */  beq        $4, $3, .L001BF3D4
    /* BF3C8 001BF3C8 00000000 */   nop
    /* BF3CC 001BF3CC 04000010 */  b          .L001BF3E0
    /* BF3D0 001BF3D0 00000000 */   nop
  .L001BF3D4:
    /* BF3D4 001BF3D4 2D180000 */  daddu      $3, $0, $0
    /* BF3D8 001BF3D8 11000010 */  b          .L001BF420
    /* BF3DC 001BF3DC 00000000 */   nop
  .L001BF3E0:
    /* BF3E0 001BF3E0 64000424 */  addiu      $4, $0, 0x64
    /* BF3E4 001BF3E4 5CC7080C */  jal        func_00231d70
    /* BF3E8 001BF3E8 00000000 */   nop
    /* BF3EC 001BF3EC 1A00412C */  sltiu      $1, $2, 0x1A
    /* BF3F0 001BF3F0 0A002014 */  bnez       $1, .L001BF41C
    /* BF3F4 001BF3F4 00000000 */   nop
    /* BF3F8 001BF3F8 2D204002 */  daddu      $4, $18, $0
    /* BF3FC 001BF3FC 2D280000 */  daddu      $5, $0, $0
    /* BF400 001BF400 23000624 */  addiu      $6, $0, 0x23
    /* BF404 001BF404 3C000724 */  addiu      $7, $0, 0x3C
    /* BF408 001BF408 64FA060C */  jal        func_001be990
    /* BF40C 001BF40C 00000000 */   nop
    /* BF410 001BF410 2D184000 */  daddu      $3, $2, $0
    /* BF414 001BF414 02000010 */  b          .L001BF420
    /* BF418 001BF418 00000000 */   nop
  .L001BF41C:
    /* BF41C 001BF41C 2D180000 */  daddu      $3, $0, $0
  .L001BF420:
    /* BF420 001BF420 3B006014 */  bnez       $3, .L001BF510
    /* BF424 001BF424 00000000 */   nop
    /* BF428 001BF428 64000424 */  addiu      $4, $0, 0x64
    /* BF42C 001BF42C 5CC7080C */  jal        func_00231d70
    /* BF430 001BF430 00000000 */   nop
    /* BF434 001BF434 1A00412C */  sltiu      $1, $2, 0x1A
    /* BF438 001BF438 2C002014 */  bnez       $1, .L001BF4EC
    /* BF43C 001BF43C 00000000 */   nop
    /* BF440 001BF440 E000428E */  lw         $2, 0xE0($18)
    /* BF444 001BF444 3000518C */  lw         $17, 0x30($2)
    /* BF448 001BF448 A4003096 */  lhu        $16, 0xA4($17)
    /* BF44C 001BF44C 2D202002 */  daddu      $4, $17, $0
    /* BF450 001BF450 FCDC060C */  jal        func_001b73f0
    /* BF454 001BF454 00000000 */   nop
    /* BF458 001BF458 2D200000 */  daddu      $4, $0, $0
    /* BF45C 001BF45C 14F4120C */  jal        func_004bd050
    /* BF460 001BF460 00000000 */   nop
    /* BF464 001BF464 01004330 */  andi       $3, $2, 0x1
    /* BF468 001BF468 00110300 */  sll        $2, $3, 4
    /* BF46C 001BF46C 23104300 */  subu       $2, $2, $3
    /* BF470 001BF470 80100200 */  sll        $2, $2, 2
    /* BF474 001BF474 21104300 */  addu       $2, $2, $3
    /* BF478 001BF478 80200200 */  sll        $4, $2, 2
    /* BF47C 001BF47C FFFF0332 */  andi       $3, $16, 0xFFFF
    /* BF480 001BF480 00110300 */  sll        $2, $3, 4
    /* BF484 001BF484 23104300 */  subu       $2, $2, $3
    /* BF488 001BF488 80100200 */  sll        $2, $2, 2
    /* BF48C 001BF48C 21104300 */  addu       $2, $2, $3
    /* BF490 001BF490 C0180200 */  sll        $3, $2, 3
    /* BF494 001BF494 6000023C */  lui        $2, %hi(D_005FB400)
    /* BF498 001BF498 00B44224 */  addiu      $2, $2, %lo(D_005FB400)
    /* BF49C 001BF49C 21104300 */  addu       $2, $2, $3
    /* BF4A0 001BF4A0 21288200 */  addu       $5, $4, $2
    /* BF4A4 001BF4A4 2D204002 */  daddu      $4, $18, $0
    /* BF4A8 001BF4A8 02000624 */  addiu      $6, $0, 0x2
    /* BF4AC 001BF4AC 60F7060C */  jal        func_001bdd80
    /* BF4B0 001BF4B0 00000000 */   nop
    /* BF4B4 001BF4B4 2D202002 */  daddu      $4, $17, $0
    /* BF4B8 001BF4B8 FCDC060C */  jal        func_001b73f0
    /* BF4BC 001BF4BC 00000000 */   nop
    /* BF4C0 001BF4C0 00608044 */  mtc1       $0, $f12
    /* BF4C4 001BF4C4 E000448E */  lw         $4, 0xE0($18)
    /* BF4C8 001BF4C8 2D280000 */  daddu      $5, $0, $0
    /* BF4CC 001BF4CC 2D300000 */  daddu      $6, $0, $0
    /* BF4D0 001BF4D0 01000724 */  addiu      $7, $0, 0x1
    /* BF4D4 001BF4D4 50F3060C */  jal        func_001bcd40
    /* BF4D8 001BF4D8 00000000 */   nop
    /* BF4DC 001BF4DC 01000324 */  addiu      $3, $0, 0x1
    /* BF4E0 001BF4E0 440143AE */  sw         $3, 0x144($18)
    /* BF4E4 001BF4E4 0B000010 */  b          .L001BF514
    /* BF4E8 001BF4E8 00000000 */   nop
  .L001BF4EC:
    /* BF4EC 001BF4EC 2D204002 */  daddu      $4, $18, $0
    /* BF4F0 001BF4F0 01000524 */  addiu      $5, $0, 0x1
    /* BF4F4 001BF4F4 23000624 */  addiu      $6, $0, 0x23
    /* BF4F8 001BF4F8 3C000724 */  addiu      $7, $0, 0x3C
    /* BF4FC 001BF4FC 64FA060C */  jal        func_001be990
    /* BF500 001BF500 00000000 */   nop
    /* BF504 001BF504 440140AE */  sw         $0, 0x144($18)
    /* BF508 001BF508 02000010 */  b          .L001BF514
    /* BF50C 001BF50C 00000000 */   nop
  .L001BF510:
    /* BF510 001BF510 440140AE */  sw         $0, 0x144($18)
  .L001BF514:
    /* BF514 001BF514 3000BFDF */  ld         $31, 0x30($29)
    /* BF518 001BF518 2000B27B */  lq         $18, 0x20($29)
    /* BF51C 001BF51C 1000B17B */  lq         $17, 0x10($29)
    /* BF520 001BF520 0000B07B */  lq         $16, 0x0($29)
    /* BF524 001BF524 4000BD27 */  addiu      $29, $29, 0x40
    /* BF528 001BF528 0800E003 */  jr         $31
    /* BF52C 001BF52C 00000000 */   nop
.size func_001bf3a0, 0x190
