.section .text
.set noat
.set noreorder
glabel func_001df3c0
    /* DF3C0 001DF3C0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* DF3C4 001DF3C4 1000BFFF */  sd         $31, 0x10($29)
    /* DF3C8 001DF3C8 0000B07F */  sq         $16, 0x0($29)
    /* DF3CC 001DF3CC 2D200000 */  daddu      $4, $0, $0
    /* DF3D0 001DF3D0 00730A0C */  jal        func_0029cc00
    /* DF3D4 001DF3D4 00000000 */   nop
    /* DF3D8 001DF3D8 3C1A0200 */  dsll32     $3, $2, 8
    /* DF3DC 001DF3DC 3E1A0300 */  dsrl32     $3, $3, 8
    /* DF3E0 001DF3E0 0002023C */  lui        $2, (0x2000000 >> 16)
    /* DF3E4 001DF3E4 25806200 */  or         $16, $3, $2
    /* DF3E8 001DF3E8 14740A0C */  jal        func_0029d050
    /* DF3EC 001DF3EC 00000000 */   nop
    /* DF3F0 001DF3F0 00FF033C */  lui        $3, (0xFF000000 >> 16)
    /* DF3F4 001DF3F4 24180302 */  and        $3, $16, $3
    /* DF3F8 001DF3F8 021E0300 */  srl        $3, $3, 24
    /* DF3FC 001DF3FC 3C2A1000 */  dsll32     $5, $16, 8
    /* DF400 001DF400 3E2A0500 */  dsrl32     $5, $5, 8
    /* DF404 001DF404 04006014 */  bnez       $3, .L001DF418
    /* DF408 001DF408 00000000 */   nop
    /* DF40C 001DF40C 2D100000 */  daddu      $2, $0, $0
    /* DF410 001DF410 0B000010 */  b          .L001DF440
    /* DF414 001DF414 00000000 */   nop
  .L001DF418:
    /* DF418 001DF418 2D204000 */  daddu      $4, $2, $0
    /* DF41C 001DF41C 40100300 */  sll        $2, $3, 1
    /* DF420 001DF420 21104300 */  addu       $2, $2, $3
    /* DF424 001DF424 80180200 */  sll        $3, $2, 2
    /* DF428 001DF428 6100023C */  lui        $2, %hi(D_00609850)
    /* DF42C 001DF42C 50984224 */  addiu      $2, $2, %lo(D_00609850)
    /* DF430 001DF430 21104300 */  addu       $2, $2, $3
    /* DF434 001DF434 0000428C */  lw         $2, 0x0($2)
    /* DF438 001DF438 09F84000 */  jalr       $2
    /* DF43C 001DF43C 00000000 */   nop
  .L001DF440:
    /* DF440 001DF440 2B200200 */  sltu       $4, $0, $2
    /* DF444 001DF444 D4730A0C */  jal        func_0029cf50
    /* DF448 001DF448 00000000 */   nop
    /* DF44C 001DF44C 01000224 */  addiu      $2, $0, 0x1
    /* DF450 001DF450 1000BFDF */  ld         $31, 0x10($29)
    /* DF454 001DF454 0000B07B */  lq         $16, 0x0($29)
    /* DF458 001DF458 2000BD27 */  addiu      $29, $29, 0x20
    /* DF45C 001DF45C 0800E003 */  jr         $31
    /* DF460 001DF460 00000000 */   nop
    /* DF464 001DF464 00000000 */  nop
    /* DF468 001DF468 00000000 */  nop
    /* DF46C 001DF46C 00000000 */  nop
.size func_001df3c0, 0xb0
