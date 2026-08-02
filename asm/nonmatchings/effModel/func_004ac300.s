.section .text
.set noat
.set noreorder
glabel func_004ac300
    /* 3AC300 004AC300 40FFBD27 */  addiu      $29, $29, -0xC0
    /* 3AC304 004AC304 5000BFFF */  sd         $31, 0x50($29)
    /* 3AC308 004AC308 4000B37F */  sq         $19, 0x40($29)
    /* 3AC30C 004AC30C 3000B27F */  sq         $18, 0x30($29)
    /* 3AC310 004AC310 2000B17F */  sq         $17, 0x20($29)
    /* 3AC314 004AC314 1000B07F */  sq         $16, 0x10($29)
    /* 3AC318 004AC318 0000B4E7 */  swc1       $f20, 0x0($29)
    /* 3AC31C 004AC31C 2D988000 */  daddu      $19, $4, $0
    /* 3AC320 004AC320 2D90A000 */  daddu      $18, $5, $0
    /* 3AC324 004AC324 9800B18C */  lw         $17, 0x98($5)
    /* 3AC328 004AC328 8C00B08C */  lw         $16, 0x8C($5)
    /* 3AC32C 004AC32C 2B081102 */  sltu       $1, $16, $17
    /* 3AC330 004AC330 03002010 */  beqz       $1, .L004AC340
    /* 3AC334 004AC334 00000000 */   nop
    /* 3AC338 004AC338 7C000016 */  bnez       $16, .L004AC52C
    /* 3AC33C 004AC33C 00000000 */   nop
  .L004AC340:
    /* 3AC340 004AC340 C9040224 */  addiu      $2, $0, 0x4C9
    /* 3AC344 004AC344 04000216 */  bne        $16, $2, .L004AC358
    /* 3AC348 004AC348 00000000 */   nop
    /* 3AC34C 004AC34C 9400448E */  lw         $4, 0x94($18)
    /* 3AC350 004AC350 14EA110C */  jal        func_0047a850
    /* 3AC354 004AC354 00000000 */   nop
  .L004AC358:
    /* 3AC358 004AC358 2C004426 */  addiu      $4, $18, 0x2C
    /* 3AC35C 004AC35C 50004526 */  addiu      $5, $18, 0x50
    /* 3AC360 004AC360 2D302002 */  daddu      $6, $17, $0
    /* 3AC364 004AC364 2D380002 */  daddu      $7, $16, $0
    /* 3AC368 004AC368 F42A120C */  jal        func_0048abd0
    /* 3AC36C 004AC36C 00000000 */   nop
    /* 3AC370 004AC370 2D184000 */  daddu      $3, $2, $0
    /* 3AC374 004AC374 2800428E */  lw         $2, 0x28($18)
    /* 3AC378 004AC378 B800A2AF */  sw         $2, 0xB8($29)
    /* 3AC37C 004AC37C B800A227 */  addiu      $2, $29, 0xB8
    /* 3AC380 004AC380 448080C7 */  lwc1       $f0, -0x7FBC($28)
    /* 3AC384 004AC384 0000428C */  lw         $2, 0x0($2)
    /* 3AC388 004AC388 88160270 */  pextlb     $2, $0, $2
    /* 3AC38C 004AC38C 88150270 */  pextlh     $2, $0, $2
    /* 3AC390 004AC390 0050A248 */  qmtc2.ni   $2, $vf10
    /* 3AC394 004AC394 3C51EA4B */  vitof0.xyzw $vf10, $vf10
    /* 3AC398 004AC398 00000244 */  mfc1       $2, $f0
    /* 3AC39C 004AC39C 00000000 */  nop
    /* 3AC3A0 004AC3A0 0010A248 */  qmtc2.ni   $2, $vf2
    /* 3AC3A4 004AC3A4 9852E24B */  vmulx.xyzw $vf10, $vf10, $vf2x
    /* 3AC3A8 004AC3A8 3C53EB4B */  vmove.xyzw $vf11, $vf10
    /* 3AC3AC 004AC3AC B400A3AF */  sw         $3, 0xB4($29)
    /* 3AC3B0 004AC3B0 B400A227 */  addiu      $2, $29, 0xB4
    /* 3AC3B4 004AC3B4 0000428C */  lw         $2, 0x0($2)
    /* 3AC3B8 004AC3B8 88160270 */  pextlb     $2, $0, $2
    /* 3AC3BC 004AC3BC 88150270 */  pextlh     $2, $0, $2
    /* 3AC3C0 004AC3C0 0050A248 */  qmtc2.ni   $2, $vf10
    /* 3AC3C4 004AC3C4 3C51EA4B */  vitof0.xyzw $vf10, $vf10
    /* 3AC3C8 004AC3C8 00000244 */  mfc1       $2, $f0
    /* 3AC3CC 004AC3CC 00000000 */  nop
    /* 3AC3D0 004AC3D0 0010A248 */  qmtc2.ni   $2, $vf2
    /* 3AC3D4 004AC3D4 9852E24B */  vmulx.xyzw $vf10, $vf10, $vf2x
    /* 3AC3D8 004AC3D8 AA52EB4B */  vmul.xyzw  $vf10, $vf10, $vf11
    /* 3AC3DC 004AC3DC 7F43023C */  lui        $2, (0x437F0000 >> 16)
    /* 3AC3E0 004AC3E0 0010A248 */  qmtc2.ni   $2, $vf2
    /* 3AC3E4 004AC3E4 9852E24B */  vmulx.xyzw $vf10, $vf10, $vf2x
    /* 3AC3E8 004AC3E8 7C51EA4B */  vftoi0.xyzw $vf10, $vf10
    /* 3AC3EC 004AC3EC 00502248 */  qmfc2.ni   $2, $vf10
    /* 3AC3F0 004AC3F0 C8150270 */  ppach      $2, $0, $2
    /* 3AC3F4 004AC3F4 C8160270 */  ppacb      $2, $0, $2
    /* 3AC3F8 004AC3F8 B000A2AF */  sw         $2, 0xB0($29)
    /* 3AC3FC 004AC3FC B000A28F */  lw         $2, 0xB0($29)
    /* 3AC400 004AC400 BC00A2AF */  sw         $2, 0xBC($29)
    /* 3AC404 004AC404 9400448E */  lw         $4, 0x94($18)
    /* 3AC408 004AC408 BC00A527 */  addiu      $5, $29, 0xBC
    /* 3AC40C 004AC40C 88E8110C */  jal        func_0047a220
    /* 3AC410 004AC410 00000000 */   nop
    /* 3AC414 004AC414 60004426 */  addiu      $4, $18, 0x60
    /* 3AC418 004AC418 2D282002 */  daddu      $5, $17, $0
    /* 3AC41C 004AC41C 2D300002 */  daddu      $6, $16, $0
    /* 3AC420 004AC420 FC2B120C */  jal        func_0048aff0
    /* 3AC424 004AC424 00000000 */   nop
    /* 3AC428 004AC428 2041023C */  lui        $2, (0x41200000 >> 16)
    /* 3AC42C 004AC42C 00088244 */  mtc1       $2, $f1
    /* 3AC430 004AC430 00000000 */  nop
    /* 3AC434 004AC434 03050146 */  div.s      $f20, $f0, $f1
    /* 3AC438 004AC438 00000000 */  nop
    /* 3AC43C 004AC43C 6000A427 */  addiu      $4, $29, 0x60
    /* 3AC440 004AC440 10004526 */  addiu      $5, $18, 0x10
    /* 3AC444 004AC444 5428120C */  jal        func_0048a150
    /* 3AC448 004AC448 00000000 */   nop
    /* 3AC44C 004AC44C 9400448E */  lw         $4, 0x94($18)
    /* 3AC450 004AC450 6000A527 */  addiu      $5, $29, 0x60
    /* 3AC454 004AC454 2D300000 */  daddu      $6, $0, $0
    /* 3AC458 004AC458 70E8110C */  jal        func_0047a1c0
    /* 3AC45C 004AC45C 00000000 */   nop
    /* 3AC460 004AC460 200040C6 */  lwc1       $f0, 0x20($18)
    /* 3AC464 004AC464 02001446 */  mul.s      $f0, $f0, $f20
    /* 3AC468 004AC468 A800A0E7 */  swc1       $f0, 0xA8($29)
    /* 3AC46C 004AC46C A400A0E7 */  swc1       $f0, 0xA4($29)
    /* 3AC470 004AC470 A000A0E7 */  swc1       $f0, 0xA0($29)
    /* 3AC474 004AC474 9400448E */  lw         $4, 0x94($18)
    /* 3AC478 004AC478 A000A527 */  addiu      $5, $29, 0xA0
    /* 3AC47C 004AC47C 02000624 */  addiu      $6, $0, 0x2
    /* 3AC480 004AC480 78E8110C */  jal        func_0047a1e0
    /* 3AC484 004AC484 00000000 */   nop
    /* 3AC488 004AC488 000040C6 */  lwc1       $f0, 0x0($18)
    /* 3AC48C 004AC48C A000A0E7 */  swc1       $f0, 0xA0($29)
    /* 3AC490 004AC490 040040C6 */  lwc1       $f0, 0x4($18)
    /* 3AC494 004AC494 A400A0E7 */  swc1       $f0, 0xA4($29)
    /* 3AC498 004AC498 080040C6 */  lwc1       $f0, 0x8($18)
    /* 3AC49C 004AC49C A800A0E7 */  swc1       $f0, 0xA8($29)
    /* 3AC4A0 004AC4A0 9400448E */  lw         $4, 0x94($18)
    /* 3AC4A4 004AC4A4 A000A527 */  addiu      $5, $29, 0xA0
    /* 3AC4A8 004AC4A8 02000624 */  addiu      $6, $0, 0x2
    /* 3AC4AC 004AC4AC 60E8110C */  jal        func_0047a180
    /* 3AC4B0 004AC4B0 00000000 */   nop
    /* 3AC4B4 004AC4B4 90004292 */  lbu        $2, 0x90($18)
    /* 3AC4B8 004AC4B8 07004010 */  beqz       $2, .L004AC4D8
    /* 3AC4BC 004AC4BC 00000000 */   nop
    /* 3AC4C0 004AC4C0 9400438E */  lw         $3, 0x94($18)
    /* 3AC4C4 004AC4C4 D800628C */  lw         $2, 0xD8($3)
    /* 3AC4C8 004AC4C8 18004234 */  ori        $2, $2, 0x18
    /* 3AC4CC 004AC4CC D80062AC */  sw         $2, 0xD8($3)
    /* 3AC4D0 004AC4D0 06000010 */  b          .L004AC4EC
    /* 3AC4D4 004AC4D4 00000000 */   nop
  .L004AC4D8:
    /* 3AC4D8 004AC4D8 9400448E */  lw         $4, 0x94($18)
    /* 3AC4DC 004AC4DC D800838C */  lw         $3, 0xD8($4)
    /* 3AC4E0 004AC4E0 E7FF0224 */  addiu      $2, $0, -0x19
    /* 3AC4E4 004AC4E4 24106200 */  and        $2, $3, $2
    /* 3AC4E8 004AC4E8 D80082AC */  sw         $2, 0xD8($4)
  .L004AC4EC:
    /* 3AC4EC 004AC4EC 9400448E */  lw         $4, 0x94($18)
    /* 3AC4F0 004AC4F0 2D280000 */  daddu      $5, $0, $0
    /* 3AC4F4 004AC4F4 24004CC6 */  lwc1       $f12, 0x24($18)
    /* 3AC4F8 004AC4F8 38E8110C */  jal        func_0047a0e0
    /* 3AC4FC 004AC4FC 00000000 */   nop
    /* 3AC500 004AC500 1405120C */  jal        func_00481450
    /* 3AC504 004AC504 00000000 */   nop
    /* 3AC508 004AC508 9400448E */  lw         $4, 0x94($18)
    /* 3AC50C 004AC50C 2D284000 */  daddu      $5, $2, $0
    /* 3AC510 004AC510 8CEA110C */  jal        func_0047aa30
    /* 3AC514 004AC514 00000000 */   nop
    /* 3AC518 004AC518 2D206002 */  daddu      $4, $19, $0
    /* 3AC51C 004AC51C 9400458E */  lw         $5, 0x94($18)
    /* 3AC520 004AC520 40E4110C */  jal        func_00479100
    /* 3AC524 004AC524 00000000 */   nop
    /* 3AC528 004AC528 240040AE */  sw         $0, 0x24($18)
  .L004AC52C:
    /* 3AC52C 004AC52C 5000BFDF */  ld         $31, 0x50($29)
    /* 3AC530 004AC530 4000B37B */  lq         $19, 0x40($29)
    /* 3AC534 004AC534 3000B27B */  lq         $18, 0x30($29)
    /* 3AC538 004AC538 2000B17B */  lq         $17, 0x20($29)
    /* 3AC53C 004AC53C 1000B07B */  lq         $16, 0x10($29)
    /* 3AC540 004AC540 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* 3AC544 004AC544 C000BD27 */  addiu      $29, $29, 0xC0
    /* 3AC548 004AC548 0800E003 */  jr         $31
    /* 3AC54C 004AC54C 00000000 */   nop
.size func_004ac300, 0x250
