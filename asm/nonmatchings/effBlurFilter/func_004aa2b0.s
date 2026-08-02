.section .text
.set noat
.set noreorder
glabel func_004aa2b0
    /* 3AA2B0 004AA2B0 90FFBD27 */  addiu      $29, $29, -0x70
    /* 3AA2B4 004AA2B4 5000BFFF */  sd         $31, 0x50($29)
    /* 3AA2B8 004AA2B8 4000B47F */  sq         $20, 0x40($29)
    /* 3AA2BC 004AA2BC 3000B37F */  sq         $19, 0x30($29)
    /* 3AA2C0 004AA2C0 2000B27F */  sq         $18, 0x20($29)
    /* 3AA2C4 004AA2C4 1000B17F */  sq         $17, 0x10($29)
    /* 3AA2C8 004AA2C8 0000B07F */  sq         $16, 0x0($29)
    /* 3AA2CC 004AA2CC 2DA08000 */  daddu      $20, $4, $0
    /* 3AA2D0 004AA2D0 2400938C */  lw         $19, 0x24($4)
    /* 3AA2D4 004AA2D4 C0007026 */  addiu      $16, $19, 0xC0
    /* 3AA2D8 004AA2D8 B800728E */  lw         $18, 0xB8($19)
    /* 3AA2DC 004AA2DC 04004016 */  bnez       $18, .L004AA2F0
    /* 3AA2E0 004AA2E0 00000000 */   nop
    /* 3AA2E4 004AA2E4 2D880000 */  daddu      $17, $0, $0
    /* 3AA2E8 004AA2E8 02000010 */  b          .L004AA2F4
    /* 3AA2EC 004AA2EC 00000000 */   nop
  .L004AA2F0:
    /* 3AA2F0 004AA2F0 1C00918E */  lw         $17, 0x1C($20)
  .L004AA2F4:
    /* 3AA2F4 004AA2F4 0D002016 */  bnez       $17, .L004AA32C
    /* 3AA2F8 004AA2F8 00000000 */   nop
    /* 3AA2FC 004AA2FC A043033C */  lui        $3, (0x43A00000 >> 16)
    /* 3AA300 004AA300 100003AE */  sw         $3, 0x10($16)
    /* 3AA304 004AA304 6043033C */  lui        $3, (0x43600000 >> 16)
    /* 3AA308 004AA308 140003AE */  sw         $3, 0x14($16)
    /* 3AA30C 004AA30C 180000AE */  sw         $0, 0x18($16)
    /* 3AA310 004AA310 1C0000AE */  sw         $0, 0x1C($16)
    /* 3AA314 004AA314 2044033C */  lui        $3, (0x44200000 >> 16)
    /* 3AA318 004AA318 200003AE */  sw         $3, 0x20($16)
    /* 3AA31C 004AA31C E043033C */  lui        $3, (0x43E00000 >> 16)
    /* 3AA320 004AA320 240003AE */  sw         $3, 0x24($16)
    /* 3AA324 004AA324 2800638E */  lw         $3, 0x28($19)
    /* 3AA328 004AA328 040003AE */  sw         $3, 0x4($16)
  .L004AA32C:
    /* 3AA32C 004AA32C 2A185102 */  slt        $3, $18, $17
    /* 3AA330 004AA330 3E006014 */  bnez       $3, .L004AA42C
    /* 3AA334 004AA334 00000000 */   nop
    /* 3AA338 004AA338 2D206002 */  daddu      $4, $19, $0
    /* 3AA33C 004AA33C 24006526 */  addiu      $5, $19, 0x24
    /* 3AA340 004AA340 2D302002 */  daddu      $6, $17, $0
    /* 3AA344 004AA344 2D384002 */  daddu      $7, $18, $0
    /* 3AA348 004AA348 F42A120C */  jal        func_0048abd0
    /* 3AA34C 004AA34C 00000000 */   nop
    /* 3AA350 004AA350 2D184000 */  daddu      $3, $2, $0
    /* 3AA354 004AA354 1000828E */  lw         $2, 0x10($20)
    /* 3AA358 004AA358 6C00A2AF */  sw         $2, 0x6C($29)
    /* 3AA35C 004AA35C 6C00A227 */  addiu      $2, $29, 0x6C
    /* 3AA360 004AA360 448080C7 */  lwc1       $f0, -0x7FBC($28)
    /* 3AA364 004AA364 0000428C */  lw         $2, 0x0($2)
    /* 3AA368 004AA368 88160270 */  pextlb     $2, $0, $2
    /* 3AA36C 004AA36C 88150270 */  pextlh     $2, $0, $2
    /* 3AA370 004AA370 0050A248 */  qmtc2.ni   $2, $vf10
    /* 3AA374 004AA374 3C51EA4B */  vitof0.xyzw $vf10, $vf10
    /* 3AA378 004AA378 00000244 */  mfc1       $2, $f0
    /* 3AA37C 004AA37C 00000000 */  nop
    /* 3AA380 004AA380 0010A248 */  qmtc2.ni   $2, $vf2
    /* 3AA384 004AA384 9852E24B */  vmulx.xyzw $vf10, $vf10, $vf2x
    /* 3AA388 004AA388 3C53EB4B */  vmove.xyzw $vf11, $vf10
    /* 3AA38C 004AA38C 6800A3AF */  sw         $3, 0x68($29)
    /* 3AA390 004AA390 6800A227 */  addiu      $2, $29, 0x68
    /* 3AA394 004AA394 0000428C */  lw         $2, 0x0($2)
    /* 3AA398 004AA398 88160270 */  pextlb     $2, $0, $2
    /* 3AA39C 004AA39C 88150270 */  pextlh     $2, $0, $2
    /* 3AA3A0 004AA3A0 0050A248 */  qmtc2.ni   $2, $vf10
    /* 3AA3A4 004AA3A4 3C51EA4B */  vitof0.xyzw $vf10, $vf10
    /* 3AA3A8 004AA3A8 00000244 */  mfc1       $2, $f0
    /* 3AA3AC 004AA3AC 00000000 */  nop
    /* 3AA3B0 004AA3B0 0010A248 */  qmtc2.ni   $2, $vf2
    /* 3AA3B4 004AA3B4 9852E24B */  vmulx.xyzw $vf10, $vf10, $vf2x
    /* 3AA3B8 004AA3B8 AA52EB4B */  vmul.xyzw  $vf10, $vf10, $vf11
    /* 3AA3BC 004AA3BC 7F43023C */  lui        $2, (0x437F0000 >> 16)
    /* 3AA3C0 004AA3C0 0010A248 */  qmtc2.ni   $2, $vf2
    /* 3AA3C4 004AA3C4 9852E24B */  vmulx.xyzw $vf10, $vf10, $vf2x
    /* 3AA3C8 004AA3C8 7C51EA4B */  vftoi0.xyzw $vf10, $vf10
    /* 3AA3CC 004AA3CC 00502248 */  qmfc2.ni   $2, $vf10
    /* 3AA3D0 004AA3D0 C8150270 */  ppach      $2, $0, $2
    /* 3AA3D4 004AA3D4 C8160270 */  ppacb      $2, $0, $2
    /* 3AA3D8 004AA3D8 6400A2AF */  sw         $2, 0x64($29)
    /* 3AA3DC 004AA3DC 6400A28F */  lw         $2, 0x64($29)
    /* 3AA3E0 004AA3E0 000002AE */  sw         $2, 0x0($16)
    /* 3AA3E4 004AA3E4 34006426 */  addiu      $4, $19, 0x34
    /* 3AA3E8 004AA3E8 2D282002 */  daddu      $5, $17, $0
    /* 3AA3EC 004AA3EC 2D304002 */  daddu      $6, $18, $0
    /* 3AA3F0 004AA3F0 FC2B120C */  jal        func_0048aff0
    /* 3AA3F4 004AA3F4 00000000 */   nop
    /* 3AA3F8 004AA3F8 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 3AA3FC 004AA3FC 00088244 */  mtc1       $2, $f1
    /* 3AA400 004AA400 00000000 */  nop
    /* 3AA404 004AA404 00080046 */  add.s      $f0, $f1, $f0
    /* 3AA408 004AA408 0C0000E6 */  swc1       $f0, 0xC($16)
    /* 3AA40C 004AA40C 60006426 */  addiu      $4, $19, 0x60
    /* 3AA410 004AA410 2D282002 */  daddu      $5, $17, $0
    /* 3AA414 004AA414 2D304002 */  daddu      $6, $18, $0
    /* 3AA418 004AA418 FC2B120C */  jal        func_0048aff0
    /* 3AA41C 004AA41C 00000000 */   nop
    /* 3AA420 004AA420 080000E6 */  swc1       $f0, 0x8($16)
    /* 3AA424 004AA424 02000010 */  b          .L004AA430
    /* 3AA428 004AA428 00000000 */   nop
  .L004AA42C:
    /* 3AA42C 004AA42C 030000A2 */  sb         $0, 0x3($16)
  .L004AA430:
    /* 3AA430 004AA430 5000BFDF */  ld         $31, 0x50($29)
    /* 3AA434 004AA434 4000B47B */  lq         $20, 0x40($29)
    /* 3AA438 004AA438 3000B37B */  lq         $19, 0x30($29)
    /* 3AA43C 004AA43C 2000B27B */  lq         $18, 0x20($29)
    /* 3AA440 004AA440 1000B17B */  lq         $17, 0x10($29)
    /* 3AA444 004AA444 0000B07B */  lq         $16, 0x0($29)
    /* 3AA448 004AA448 7000BD27 */  addiu      $29, $29, 0x70
    /* 3AA44C 004AA44C 0800E003 */  jr         $31
    /* 3AA450 004AA450 00000000 */   nop
    /* 3AA454 004AA454 00000000 */  nop
    /* 3AA458 004AA458 00000000 */  nop
    /* 3AA45C 004AA45C 00000000 */  nop
.size func_004aa2b0, 0x1b0
