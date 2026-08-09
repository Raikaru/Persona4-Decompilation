.section .text
.set noat
.set noreorder
glabel func_001fb360
    /* FB360 001FB360 C0FFBD27 */  addiu      $29, $29, -0x40
    /* FB364 001FB364 3000BFFF */  sd         $31, 0x30($29)
    /* FB368 001FB368 2000B27F */  sq         $18, 0x20($29)
    /* FB36C 001FB36C 1000B17F */  sq         $17, 0x10($29)
    /* FB370 001FB370 0000B07F */  sq         $16, 0x0($29)
    /* FB374 001FB374 2D908000 */  daddu      $18, $4, $0
    /* FB378 001FB378 0400A01C */  bgtz       $5, .L001FB38C
    /* FB37C 001FB37C 00000000 */   nop
    /* FB380 001FB380 2D100000 */  daddu      $2, $0, $0
    /* FB384 001FB384 36000010 */  b          .L001FB460
    /* FB388 001FB388 00000000 */   nop
  .L001FB38C:
    /* FB38C 001FB38C 80100500 */  sll        $2, $5, 2
    /* FB390 001FB390 21104500 */  addu       $2, $2, $5
    /* FB394 001FB394 C0180200 */  sll        $3, $2, 3
    /* FB398 001FB398 B8B3828F */  lw         $2, -0x4C48($28)
    /* FB39C 001FB39C 21184300 */  addu       $3, $2, $3
    /* FB3A0 001FB3A0 00006290 */  lbu        $2, 0x0($3)
    /* FB3A4 001FB3A4 08004230 */  andi       $2, $2, 0x8
    /* FB3A8 001FB3A8 04004014 */  bnez       $2, .L001FB3BC
    /* FB3AC 001FB3AC 00000000 */   nop
    /* FB3B0 001FB3B0 2D100000 */  daddu      $2, $0, $0
    /* FB3B4 001FB3B4 2A000010 */  b          .L001FB460
    /* FB3B8 001FB3B8 00000000 */   nop
  .L001FB3BC:
    /* FB3BC 001FB3BC 2000708C */  lw         $16, 0x20($3)
    /* FB3C0 001FB3C0 7F7C023C */  lui        $2, (0x7C7FFFFF >> 16)
    /* FB3C4 001FB3C4 FFFF4234 */  ori        $2, $2, (0x7C7FFFFF & 0xFFFF)
    /* FB3C8 001FB3C8 24100202 */  and        $2, $16, $2
    /* FB3CC 001FB3CC 23004010 */  beqz       $2, .L001FB45C
    /* FB3D0 001FB3D0 00000000 */   nop
    /* FB3D4 001FB3D4 8083023C */  lui        $2, (0x83800000 >> 16)
    /* FB3D8 001FB3D8 24100202 */  and        $2, $16, $2
    /* FB3DC 001FB3DC 1F004014 */  bnez       $2, .L001FB45C
    /* FB3E0 001FB3E0 00000000 */   nop
    /* FB3E4 001FB3E4 2D880000 */  daddu      $17, $0, $0
    /* FB3E8 001FB3E8 0D000010 */  b          .L001FB420
    /* FB3EC 001FB3EC 00000000 */   nop
  .L001FB3F0:
    /* FB3F0 001FB3F0 01000224 */  addiu      $2, $0, 0x1
    /* FB3F4 001FB3F4 04282202 */  sllv       $5, $2, $17
    /* FB3F8 001FB3F8 24100502 */  and        $2, $16, $5
    /* FB3FC 001FB3FC 07004010 */  beqz       $2, .L001FB41C
    /* FB400 001FB400 00000000 */   nop
    /* FB404 001FB404 3000428E */  lw         $2, 0x30($18)
    /* FB408 001FB408 640A448C */  lw         $4, 0xA64($2)
    /* FB40C 001FB40C 30D0080C */  jal        func_002340c0
    /* FB410 001FB410 00000000 */   nop
    /* FB414 001FB414 05004010 */  beqz       $2, .L001FB42C
    /* FB418 001FB418 00000000 */   nop
  .L001FB41C:
    /* FB41C 001FB41C 01003126 */  addiu      $17, $17, 0x1
  .L001FB420:
    /* FB420 001FB420 2000222E */  sltiu      $2, $17, 0x20
    /* FB424 001FB424 F2FF4014 */  bnez       $2, .L001FB3F0
    /* FB428 001FB428 00000000 */   nop
  .L001FB42C:
    /* FB42C 001FB42C 20000224 */  addiu      $2, $0, 0x20
    /* FB430 001FB430 0A002216 */  bne        $17, $2, .L001FB45C
    /* FB434 001FB434 00000000 */   nop
    /* FB438 001FB438 00300232 */  andi       $2, $16, 0x3000
    /* FB43C 001FB43C 04004010 */  beqz       $2, .L001FB450
    /* FB440 001FB440 00000000 */   nop
    /* FB444 001FB444 07000224 */  addiu      $2, $0, 0x7
    /* FB448 001FB448 02000010 */  b          .L001FB454
    /* FB44C 001FB44C 00000000 */   nop
  .L001FB450:
    /* FB450 001FB450 03000224 */  addiu      $2, $0, 0x3
  .L001FB454:
    /* FB454 001FB454 02000010 */  b          .L001FB460
    /* FB458 001FB458 00000000 */   nop
  .L001FB45C:
    /* FB45C 001FB45C 2D100000 */  daddu      $2, $0, $0
  .L001FB460:
    /* FB460 001FB460 3000BFDF */  ld         $31, 0x30($29)
    /* FB464 001FB464 2000B27B */  lq         $18, 0x20($29)
    /* FB468 001FB468 1000B17B */  lq         $17, 0x10($29)
    /* FB46C 001FB46C 0000B07B */  lq         $16, 0x0($29)
    /* FB470 001FB470 4000BD27 */  addiu      $29, $29, 0x40
    /* FB474 001FB474 0800E003 */  jr         $31
    /* FB478 001FB478 00000000 */   nop
    /* FB47C 001FB47C 00000000 */  nop
.size func_001fb360, 0x120
