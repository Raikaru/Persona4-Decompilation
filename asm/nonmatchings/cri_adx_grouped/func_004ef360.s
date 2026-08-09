.section .text
.set noat
.set noreorder
glabel func_004ef360
    /* 3EF360 004EF360 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3EF364 004EF364 08008014 */  bnez       $4, .L004EF388
    /* 3EF368 004EF368 0000BFFF */   sd        $31, 0x0($29)
    /* 3EF36C 004EF36C 7600043C */  lui        $4, %hi(D_0075CFE8)
    /* 3EF370 004EF370 7600053C */  lui        $5, %hi(D_0075CEF8)
    /* 3EF374 004EF374 0000BFDF */  ld         $31, 0x0($29)
    /* 3EF378 004EF378 E8CF8424 */  addiu      $4, $4, %lo(D_0075CFE8)
    /* 3EF37C 004EF37C F8CEA524 */  addiu      $5, $5, %lo(D_0075CEF8)
    /* 3EF380 004EF380 B6BA1308 */  j          func_004eead8
    /* 3EF384 004EF384 1000BD27 */   addiu     $29, $29, 0x10
  .L004EF388:
    /* 3EF388 004EF388 04008280 */  lb         $2, 0x4($4)
    /* 3EF38C 004EF38C 08004014 */  bnez       $2, .L004EF3B0
    /* 3EF390 004EF390 0400A22C */   sltiu     $2, $5, 0x4
    /* 3EF394 004EF394 7600043C */  lui        $4, %hi(D_0075CFF8)
    /* 3EF398 004EF398 7600053C */  lui        $5, %hi(D_0075CF28)
    /* 3EF39C 004EF39C 0000BFDF */  ld         $31, 0x0($29)
    /* 3EF3A0 004EF3A0 F8CF8424 */  addiu      $4, $4, %lo(D_0075CFF8)
    /* 3EF3A4 004EF3A4 28CFA524 */  addiu      $5, $5, %lo(D_0075CF28)
    /* 3EF3A8 004EF3A8 B6BA1308 */  j          func_004eead8
    /* 3EF3AC 004EF3AC 1000BD27 */   addiu     $29, $29, 0x10
  .L004EF3B0:
    /* 3EF3B0 004EF3B0 24004050 */  beql       $2, $0, .L004EF444
    /* 3EF3B4 004EF3B4 2800828C */   lw        $2, 0x28($4)
    /* 3EF3B8 004EF3B8 0400C98C */  lw         $9, 0x4($6)
    /* 3EF3BC 004EF3BC 30002019 */  blez       $9, .L004EF480
    /* 3EF3C0 004EF3C0 0000BFDF */   ld        $31, 0x0($29)
    /* 3EF3C4 004EF3C4 0000C88C */  lw         $8, 0x0($6)
    /* 3EF3C8 004EF3C8 2D000011 */  beqz       $8, .L004EF480
    /* 3EF3CC 004EF3CC 80100500 */   sll       $2, $5, 2
    /* 3EF3D0 004EF3D0 21108200 */  addu       $2, $4, $2
    /* 3EF3D4 004EF3D4 18004524 */  addiu      $5, $2, 0x18
    /* 3EF3D8 004EF3D8 0000A28C */  lw         $2, 0x0($5)
    /* 3EF3DC 004EF3DC 08004010 */  beqz       $2, .L004EF400
    /* 3EF3E0 004EF3E0 2D380000 */   daddu     $7, $0, $0
  .L004EF3E4:
    /* 3EF3E4 004EF3E4 2D384000 */  daddu      $7, $2, $0
    /* 3EF3E8 004EF3E8 0000E28C */  lw         $2, 0x0($7)
    /* 3EF3EC 004EF3EC 00000000 */  nop
    /* 3EF3F0 004EF3F0 00000000 */  nop
    /* 3EF3F4 004EF3F4 00000000 */  nop
    /* 3EF3F8 004EF3F8 FAFF4014 */  bnez       $2, .L004EF3E4
    /* 3EF3FC 004EF3FC 2D28E000 */   daddu     $5, $7, $0
  .L004EF400:
    /* 3EF400 004EF400 05008380 */  lb         $3, 0x5($4)
    /* 3EF404 004EF404 01000224 */  addiu      $2, $0, 0x1
    /* 3EF408 004EF408 0B006254 */  bnel       $3, $2, .L004EF438
    /* 3EF40C 004EF40C 1400878C */   lw        $7, 0x14($4)
    /* 3EF410 004EF410 0900E050 */  beql       $7, $0, .L004EF438
    /* 3EF414 004EF414 1400878C */   lw        $7, 0x14($4)
    /* 3EF418 004EF418 0800E28C */  lw         $2, 0x8($7)
    /* 3EF41C 004EF41C 0C00E38C */  lw         $3, 0xC($7)
    /* 3EF420 004EF420 21104300 */  addu       $2, $2, $3
    /* 3EF424 004EF424 04004854 */  bnel       $2, $8, .L004EF438
    /* 3EF428 004EF428 1400878C */   lw        $7, 0x14($4)
    /* 3EF42C 004EF42C 21106900 */  addu       $2, $3, $9
    /* 3EF430 004EF430 12000010 */  b          .L004EF47C
    /* 3EF434 004EF434 0C00E2AC */   sw        $2, 0xC($7)
  .L004EF438:
    /* 3EF438 004EF438 0900E054 */  bnel       $7, $0, .L004EF460
    /* 3EF43C 004EF43C 0000E28C */   lw        $2, 0x0($7)
    /* 3EF440 004EF440 2800828C */  lw         $2, 0x28($4)
  .L004EF444:
    /* 3EF444 004EF444 0E004010 */  beqz       $2, .L004EF480
    /* 3EF448 004EF448 0000BFDF */   ld        $31, 0x0($29)
    /* 3EF44C 004EF44C 2C00848C */  lw         $4, 0x2C($4)
    /* 3EF450 004EF450 09F84000 */  jalr       $2
    /* 3EF454 004EF454 FDFF0524 */   addiu     $5, $0, -0x3
    /* 3EF458 004EF458 09000010 */  b          .L004EF480
    /* 3EF45C 004EF45C 0000BFDF */   ld        $31, 0x0($29)
  .L004EF460:
    /* 3EF460 004EF460 0700C368 */  ldl        $3, 0x7($6)
    /* 3EF464 004EF464 0000C36C */  ldr        $3, 0x0($6)
    /* 3EF468 004EF468 0F00E3B0 */  sdl        $3, 0xF($7)
    /* 3EF46C 004EF46C 0800E3B4 */  sdr        $3, 0x8($7)
    /* 3EF470 004EF470 140082AC */  sw         $2, 0x14($4)
    /* 3EF474 004EF474 0000E0AC */  sw         $0, 0x0($7)
    /* 3EF478 004EF478 0000A7AC */  sw         $7, 0x0($5)
  .L004EF47C:
    /* 3EF47C 004EF47C 0000BFDF */  ld         $31, 0x0($29)
  .L004EF480:
    /* 3EF480 004EF480 0800E003 */  jr         $31
    /* 3EF484 004EF484 1000BD27 */   addiu     $29, $29, 0x10
.size func_004ef360, 0x128
