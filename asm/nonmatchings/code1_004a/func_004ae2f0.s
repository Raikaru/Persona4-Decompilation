.section .text
.set noat
.set noreorder
glabel func_004ae2f0
    /* 3AE2F0 004AE2F0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3AE2F4 004AE2F4 3800828C */  lw         $2, 0x38($4)
    /* 3AE2F8 004AE2F8 06000824 */  addiu      $8, $0, 0x6
    /* 3AE2FC 004AE2FC 1A004800 */  div        $0, $2, $8
    /* 3AE300 004AE300 12380000 */  mflo       $7
    /* 3AE304 004AE304 4200E018 */  blez       $7, .L004AE410
    /* 3AE308 004AE308 00000000 */   nop
    /* 3AE30C 004AE30C 3C53EC4B */  vmove.xyzw $vf12, $vf10
    /* 3AE310 004AE310 1A00C700 */  div        $0, $6, $7
    /* 3AE314 004AE314 12180000 */  mflo       $3
    /* 3AE318 004AE318 1A00C700 */  div        $0, $6, $7
    /* 3AE31C 004AE31C 10100000 */  mfhi       $2
    /* 3AE320 004AE320 00008244 */  mtc1       $2, $f0
    /* 3AE324 004AE324 00000000 */  nop
    /* 3AE328 004AE328 60008046 */  cvt.s.w    $f1, $f0
    /* 3AE32C 004AE32C 00008744 */  mtc1       $7, $f0
    /* 3AE330 004AE330 00000000 */  nop
    /* 3AE334 004AE334 20008046 */  cvt.s.w    $f0, $f0
    /* 3AE338 004AE338 43080046 */  div.s      $f1, $f1, $f0
    /* 3AE33C 004AE33C 1400A280 */  lb         $2, 0x14($5)
    /* 3AE340 004AE340 21104300 */  addu       $2, $2, $3
    /* 3AE344 004AE344 1A004800 */  div        $0, $2, $8
    /* 3AE348 004AE348 10180000 */  mfhi       $3
    /* 3AE34C 004AE34C 01006224 */  addiu      $2, $3, 0x1
    /* 3AE350 004AE350 1A004800 */  div        $0, $2, $8
    /* 3AE354 004AE354 10100000 */  mfhi       $2
    /* 3AE358 004AE358 80100200 */  sll        $2, $2, 2
    /* 3AE35C 004AE35C 21104400 */  addu       $2, $2, $4
    /* 3AE360 004AE360 3C00428C */  lw         $2, 0x3C($2)
    /* 3AE364 004AE364 0C00A2AF */  sw         $2, 0xC($29)
    /* 3AE368 004AE368 0C00A227 */  addiu      $2, $29, 0xC
    /* 3AE36C 004AE36C F48180C7 */  lwc1       $f0, -0x7E0C($28)
    /* 3AE370 004AE370 0000428C */  lw         $2, 0x0($2)
    /* 3AE374 004AE374 88160270 */  pextlb     $2, $0, $2
    /* 3AE378 004AE378 88150270 */  pextlh     $2, $0, $2
    /* 3AE37C 004AE37C 0058A248 */  qmtc2.ni   $2, $vf11
    /* 3AE380 004AE380 3C59EB4B */  vitof0.xyzw $vf11, $vf11
    /* 3AE384 004AE384 00000244 */  mfc1       $2, $f0
    /* 3AE388 004AE388 00000000 */  nop
    /* 3AE38C 004AE38C 0010A248 */  qmtc2.ni   $2, $vf2
    /* 3AE390 004AE390 D85AE24B */  vmulx.xyzw $vf11, $vf11, $vf2x
    /* 3AE394 004AE394 80100300 */  sll        $2, $3, 2
    /* 3AE398 004AE398 21104400 */  addu       $2, $2, $4
    /* 3AE39C 004AE39C 3C00428C */  lw         $2, 0x3C($2)
    /* 3AE3A0 004AE3A0 0800A2AF */  sw         $2, 0x8($29)
    /* 3AE3A4 004AE3A4 0800A227 */  addiu      $2, $29, 0x8
    /* 3AE3A8 004AE3A8 0000428C */  lw         $2, 0x0($2)
    /* 3AE3AC 004AE3AC 88160270 */  pextlb     $2, $0, $2
    /* 3AE3B0 004AE3B0 88150270 */  pextlh     $2, $0, $2
    /* 3AE3B4 004AE3B4 0050A248 */  qmtc2.ni   $2, $vf10
    /* 3AE3B8 004AE3B8 3C51EA4B */  vitof0.xyzw $vf10, $vf10
    /* 3AE3BC 004AE3BC 00000344 */  mfc1       $3, $f0
    /* 3AE3C0 004AE3C0 00000000 */  nop
    /* 3AE3C4 004AE3C4 0010A348 */  qmtc2.ni   $3, $vf2
    /* 3AE3C8 004AE3C8 9852E24B */  vmulx.xyzw $vf10, $vf10, $vf2x
    /* 3AE3CC 004AE3CC 803F033C */  lui        $3, (0x3F800000 >> 16)
    /* 3AE3D0 004AE3D0 00008344 */  mtc1       $3, $f0
    /* 3AE3D4 004AE3D4 00000000 */  nop
    /* 3AE3D8 004AE3D8 01000146 */  sub.s      $f0, $f0, $f1
    /* 3AE3DC 004AE3DC 00000344 */  mfc1       $3, $f0
    /* 3AE3E0 004AE3E0 00000000 */  nop
    /* 3AE3E4 004AE3E4 0010A348 */  qmtc2.ni   $3, $vf2
    /* 3AE3E8 004AE3E8 9852E24B */  vmulx.xyzw $vf10, $vf10, $vf2x
    /* 3AE3EC 004AE3EC 00080344 */  mfc1       $3, $f1
    /* 3AE3F0 004AE3F0 00000000 */  nop
    /* 3AE3F4 004AE3F4 0010A348 */  qmtc2.ni   $3, $vf2
    /* 3AE3F8 004AE3F8 D85AE24B */  vmulx.xyzw $vf11, $vf11, $vf2x
    /* 3AE3FC 004AE3FC A852EB4B */  vadd.xyzw  $vf10, $vf10, $vf11
    /* 3AE400 004AE400 3C63EB4B */  vmove.xyzw $vf11, $vf12
    /* 3AE404 004AE404 AA52EB4B */  vmul.xyzw  $vf10, $vf10, $vf11
    /* 3AE408 004AE408 11000010 */  b          .L004AE450
    /* 3AE40C 004AE40C 00000000 */   nop
  .L004AE410:
    /* 3AE410 004AE410 1400A280 */  lb         $2, 0x14($5)
    /* 3AE414 004AE414 80100200 */  sll        $2, $2, 2
    /* 3AE418 004AE418 21104400 */  addu       $2, $2, $4
    /* 3AE41C 004AE41C 3C00428C */  lw         $2, 0x3C($2)
    /* 3AE420 004AE420 0400A2AF */  sw         $2, 0x4($29)
    /* 3AE424 004AE424 0400A227 */  addiu      $2, $29, 0x4
    /* 3AE428 004AE428 F481838F */  lw         $3, -0x7E0C($28)
    /* 3AE42C 004AE42C 0000428C */  lw         $2, 0x0($2)
    /* 3AE430 004AE430 88160270 */  pextlb     $2, $0, $2
    /* 3AE434 004AE434 88150270 */  pextlh     $2, $0, $2
    /* 3AE438 004AE438 0058A248 */  qmtc2.ni   $2, $vf11
    /* 3AE43C 004AE43C 3C59EB4B */  vitof0.xyzw $vf11, $vf11
    /* 3AE440 004AE440 00000000 */  nop
    /* 3AE444 004AE444 0010A348 */  qmtc2.ni   $3, $vf2
    /* 3AE448 004AE448 D85AE24B */  vmulx.xyzw $vf11, $vf11, $vf2x
    /* 3AE44C 004AE44C AA52EB4B */  vmul.xyzw  $vf10, $vf10, $vf11
  .L004AE450:
    /* 3AE450 004AE450 1000BD27 */  addiu      $29, $29, 0x10
    /* 3AE454 004AE454 0800E003 */  jr         $31
    /* 3AE458 004AE458 00000000 */   nop
    /* 3AE45C 004AE45C 00000000 */  nop
.size func_004ae2f0, 0x170
