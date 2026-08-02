.section .text
.set noat
.set noreorder
glabel func_001dc380
    /* DC380 001DC380 E0FFBD27 */  addiu      $29, $29, -0x20
    /* DC384 001DC384 1000BFFF */  sd         $31, 0x10($29)
    /* DC388 001DC388 0000B07F */  sq         $16, 0x0($29)
    /* DC38C 001DC38C 2D808000 */  daddu      $16, $4, $0
    /* DC390 001DC390 98000526 */  addiu      $5, $16, 0x98
    /* DC394 001DC394 6E008694 */  lhu        $6, 0x6E($4)
    /* DC398 001DC398 2D380000 */  daddu      $7, $0, $0
    /* DC39C 001DC39C C45F070C */  jal        func_001d7f10
    /* DC3A0 001DC3A0 00000000 */   nop
    /* DC3A4 001DC3A4 FFFF4230 */  andi       $2, $2, 0xFFFF
    /* DC3A8 001DC3A8 14004010 */  beqz       $2, .L001DC3FC
    /* DC3AC 001DC3AC 00000000 */   nop
    /* DC3B0 001DC3B0 2D200000 */  daddu      $4, $0, $0
    /* DC3B4 001DC3B4 08000010 */  b          .L001DC3D8
    /* DC3B8 001DC3B8 00000000 */   nop
  .L001DC3BC:
    /* DC3BC 001DC3BC FFFF8230 */  andi       $2, $4, 0xFFFF
    /* DC3C0 001DC3C0 80100200 */  sll        $2, $2, 2
    /* DC3C4 001DC3C4 21180202 */  addu       $3, $16, $2
    /* DC3C8 001DC3C8 9800628C */  lw         $2, 0x98($3)
    /* DC3CC 001DC3CC 380062AC */  sw         $2, 0x38($3)
    /* DC3D0 001DC3D0 01008224 */  addiu      $2, $4, 0x1
    /* DC3D4 001DC3D4 FFFF4430 */  andi       $4, $2, 0xFFFF
  .L001DC3D8:
    /* DC3D8 001DC3D8 D0000396 */  lhu        $3, 0xD0($16)
    /* DC3DC 001DC3DC FFFF8230 */  andi       $2, $4, 0xFFFF
    /* DC3E0 001DC3E0 2A104300 */  slt        $2, $2, $3
    /* DC3E4 001DC3E4 F5FF4014 */  bnez       $2, .L001DC3BC
    /* DC3E8 001DC3E8 00000000 */   nop
    /* DC3EC 001DC3EC 6A0003A6 */  sh         $3, 0x6A($16)
    /* DC3F0 001DC3F0 01000224 */  addiu      $2, $0, 0x1
    /* DC3F4 001DC3F4 1A000010 */  b          .L001DC460
    /* DC3F8 001DC3F8 00000000 */   nop
  .L001DC3FC:
    /* DC3FC 001DC3FC 2D380000 */  daddu      $7, $0, $0
    /* DC400 001DC400 FF0F023C */  lui        $2, (0xFFFFFFF >> 16)
    /* DC404 001DC404 FFFF4534 */  ori        $5, $2, (0xFFFFFFF & 0xFFFF)
    /* DC408 001DC408 2D300000 */  daddu      $6, $0, $0
    /* DC40C 001DC40C D0000496 */  lhu        $4, 0xD0($16)
    /* DC410 001DC410 0D000010 */  b          .L001DC448
    /* DC414 001DC414 00000000 */   nop
  .L001DC418:
    /* DC418 001DC418 80100600 */  sll        $2, $6, 2
    /* DC41C 001DC41C 21100202 */  addu       $2, $16, $2
    /* DC420 001DC420 9800438C */  lw         $3, 0x98($2)
    /* DC424 001DC424 3000628C */  lw         $2, 0x30($3)
    /* DC428 001DC428 640A428C */  lw         $2, 0xA64($2)
    /* DC42C 001DC42C 08004294 */  lhu        $2, 0x8($2)
    /* DC430 001DC430 2B084500 */  sltu       $1, $2, $5
    /* DC434 001DC434 03002010 */  beqz       $1, .L001DC444
    /* DC438 001DC438 00000000 */   nop
    /* DC43C 001DC43C 2D386000 */  daddu      $7, $3, $0
    /* DC440 001DC440 2D284000 */  daddu      $5, $2, $0
  .L001DC444:
    /* DC444 001DC444 0100C624 */  addiu      $6, $6, 0x1
  .L001DC448:
    /* DC448 001DC448 2B10C400 */  sltu       $2, $6, $4
    /* DC44C 001DC44C F2FF4014 */  bnez       $2, .L001DC418
    /* DC450 001DC450 00000000 */   nop
    /* DC454 001DC454 380007AE */  sw         $7, 0x38($16)
    /* DC458 001DC458 01000224 */  addiu      $2, $0, 0x1
    /* DC45C 001DC45C 6A0002A6 */  sh         $2, 0x6A($16)
  .L001DC460:
    /* DC460 001DC460 1000BFDF */  ld         $31, 0x10($29)
    /* DC464 001DC464 0000B07B */  lq         $16, 0x0($29)
    /* DC468 001DC468 2000BD27 */  addiu      $29, $29, 0x20
    /* DC46C 001DC46C 0800E003 */  jr         $31
    /* DC470 001DC470 00000000 */   nop
    /* DC474 001DC474 00000000 */  nop
    /* DC478 001DC478 00000000 */  nop
    /* DC47C 001DC47C 00000000 */  nop
.size func_001dc380, 0x100
