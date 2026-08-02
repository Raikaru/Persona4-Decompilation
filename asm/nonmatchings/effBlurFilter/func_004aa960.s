.section .text
.set noat
.set noreorder
glabel func_004aa960
    /* 3AA960 004AA960 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 3AA964 004AA964 2000BFFF */  sd         $31, 0x20($29)
    /* 3AA968 004AA968 1000B17F */  sq         $17, 0x10($29)
    /* 3AA96C 004AA96C 0000B07F */  sq         $16, 0x0($29)
    /* 3AA970 004AA970 2D888000 */  daddu      $17, $4, $0
    /* 3AA974 004AA974 2400848C */  lw         $4, 0x24($4)
    /* 3AA978 004AA978 C0009024 */  addiu      $16, $4, 0xC0
    /* 3AA97C 004AA97C B800878C */  lw         $7, 0xB8($4)
    /* 3AA980 004AA980 0400E014 */  bnez       $7, .L004AA994
    /* 3AA984 004AA984 00000000 */   nop
    /* 3AA988 004AA988 2D300000 */  daddu      $6, $0, $0
    /* 3AA98C 004AA98C 02000010 */  b          .L004AA998
    /* 3AA990 004AA990 00000000 */   nop
  .L004AA994:
    /* 3AA994 004AA994 1C00268E */  lw         $6, 0x1C($17)
  .L004AA998:
    /* 3AA998 004AA998 0900C014 */  bnez       $6, .L004AA9C0
    /* 3AA99C 004AA99C 00000000 */   nop
    /* 3AA9A0 004AA9A0 080000AE */  sw         $0, 0x8($16)
    /* 3AA9A4 004AA9A4 0C0000AE */  sw         $0, 0xC($16)
    /* 3AA9A8 004AA9A8 2044033C */  lui        $3, (0x44200000 >> 16)
    /* 3AA9AC 004AA9AC 100003AE */  sw         $3, 0x10($16)
    /* 3AA9B0 004AA9B0 E043033C */  lui        $3, (0x43E00000 >> 16)
    /* 3AA9B4 004AA9B4 140003AE */  sw         $3, 0x14($16)
    /* 3AA9B8 004AA9B8 2800838C */  lw         $3, 0x28($4)
    /* 3AA9BC 004AA9BC 040003AE */  sw         $3, 0x4($16)
  .L004AA9C0:
    /* 3AA9C0 004AA9C0 2A18E600 */  slt        $3, $7, $6
    /* 3AA9C4 004AA9C4 2B006014 */  bnez       $3, .L004AAA74
    /* 3AA9C8 004AA9C8 00000000 */   nop
    /* 3AA9CC 004AA9CC 24008524 */  addiu      $5, $4, 0x24
    /* 3AA9D0 004AA9D0 F42A120C */  jal        func_0048abd0
    /* 3AA9D4 004AA9D4 00000000 */   nop
    /* 3AA9D8 004AA9D8 2D184000 */  daddu      $3, $2, $0
    /* 3AA9DC 004AA9DC 1000228E */  lw         $2, 0x10($17)
    /* 3AA9E0 004AA9E0 3C00A2AF */  sw         $2, 0x3C($29)
    /* 3AA9E4 004AA9E4 3C00A227 */  addiu      $2, $29, 0x3C
    /* 3AA9E8 004AA9E8 448080C7 */  lwc1       $f0, -0x7FBC($28)
    /* 3AA9EC 004AA9EC 0000428C */  lw         $2, 0x0($2)
    /* 3AA9F0 004AA9F0 88160270 */  pextlb     $2, $0, $2
    /* 3AA9F4 004AA9F4 88150270 */  pextlh     $2, $0, $2
    /* 3AA9F8 004AA9F8 0050A248 */  qmtc2.ni   $2, $vf10
    /* 3AA9FC 004AA9FC 3C51EA4B */  vitof0.xyzw $vf10, $vf10
    /* 3AAA00 004AAA00 00000244 */  mfc1       $2, $f0
    /* 3AAA04 004AAA04 00000000 */  nop
    /* 3AAA08 004AAA08 0010A248 */  qmtc2.ni   $2, $vf2
    /* 3AAA0C 004AAA0C 9852E24B */  vmulx.xyzw $vf10, $vf10, $vf2x
    /* 3AAA10 004AAA10 3C53EB4B */  vmove.xyzw $vf11, $vf10
    /* 3AAA14 004AAA14 3800A3AF */  sw         $3, 0x38($29)
    /* 3AAA18 004AAA18 3800A227 */  addiu      $2, $29, 0x38
    /* 3AAA1C 004AAA1C 0000428C */  lw         $2, 0x0($2)
    /* 3AAA20 004AAA20 88160270 */  pextlb     $2, $0, $2
    /* 3AAA24 004AAA24 88150270 */  pextlh     $2, $0, $2
    /* 3AAA28 004AAA28 0050A248 */  qmtc2.ni   $2, $vf10
    /* 3AAA2C 004AAA2C 3C51EA4B */  vitof0.xyzw $vf10, $vf10
    /* 3AAA30 004AAA30 00000344 */  mfc1       $3, $f0
    /* 3AAA34 004AAA34 00000000 */  nop
    /* 3AAA38 004AAA38 0010A348 */  qmtc2.ni   $3, $vf2
    /* 3AAA3C 004AAA3C 9852E24B */  vmulx.xyzw $vf10, $vf10, $vf2x
    /* 3AAA40 004AAA40 AA52EB4B */  vmul.xyzw  $vf10, $vf10, $vf11
    /* 3AAA44 004AAA44 7F43033C */  lui        $3, (0x437F0000 >> 16)
    /* 3AAA48 004AAA48 0010A348 */  qmtc2.ni   $3, $vf2
    /* 3AAA4C 004AAA4C 9852E24B */  vmulx.xyzw $vf10, $vf10, $vf2x
    /* 3AAA50 004AAA50 7C51EA4B */  vftoi0.xyzw $vf10, $vf10
    /* 3AAA54 004AAA54 00502348 */  qmfc2.ni   $3, $vf10
    /* 3AAA58 004AAA58 C81D0370 */  ppach      $3, $0, $3
    /* 3AAA5C 004AAA5C C81E0370 */  ppacb      $3, $0, $3
    /* 3AAA60 004AAA60 3400A3AF */  sw         $3, 0x34($29)
    /* 3AAA64 004AAA64 3400A38F */  lw         $3, 0x34($29)
    /* 3AAA68 004AAA68 000003AE */  sw         $3, 0x0($16)
    /* 3AAA6C 004AAA6C 02000010 */  b          .L004AAA78
    /* 3AAA70 004AAA70 00000000 */   nop
  .L004AAA74:
    /* 3AAA74 004AAA74 030000A2 */  sb         $0, 0x3($16)
  .L004AAA78:
    /* 3AAA78 004AAA78 2000BFDF */  ld         $31, 0x20($29)
    /* 3AAA7C 004AAA7C 1000B17B */  lq         $17, 0x10($29)
    /* 3AAA80 004AAA80 0000B07B */  lq         $16, 0x0($29)
    /* 3AAA84 004AAA84 4000BD27 */  addiu      $29, $29, 0x40
    /* 3AAA88 004AAA88 0800E003 */  jr         $31
    /* 3AAA8C 004AAA8C 00000000 */   nop
.size func_004aa960, 0x130
