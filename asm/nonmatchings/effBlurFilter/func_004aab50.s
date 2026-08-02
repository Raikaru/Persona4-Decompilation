.section .text
.set noat
.set noreorder
glabel func_004aab50
    /* 3AAB50 004AAB50 80FFBD27 */  addiu      $29, $29, -0x80
    /* 3AAB54 004AAB54 5000BFFF */  sd         $31, 0x50($29)
    /* 3AAB58 004AAB58 4000B47F */  sq         $20, 0x40($29)
    /* 3AAB5C 004AAB5C 3000B37F */  sq         $19, 0x30($29)
    /* 3AAB60 004AAB60 2000B27F */  sq         $18, 0x20($29)
    /* 3AAB64 004AAB64 1000B17F */  sq         $17, 0x10($29)
    /* 3AAB68 004AAB68 0000B07F */  sq         $16, 0x0($29)
    /* 3AAB6C 004AAB6C 2DA08000 */  daddu      $20, $4, $0
    /* 3AAB70 004AAB70 2400938C */  lw         $19, 0x24($4)
    /* 3AAB74 004AAB74 C0007026 */  addiu      $16, $19, 0xC0
    /* 3AAB78 004AAB78 B800718E */  lw         $17, 0xB8($19)
    /* 3AAB7C 004AAB7C 04002016 */  bnez       $17, .L004AAB90
    /* 3AAB80 004AAB80 00000000 */   nop
    /* 3AAB84 004AAB84 2D900000 */  daddu      $18, $0, $0
    /* 3AAB88 004AAB88 02000010 */  b          .L004AAB94
    /* 3AAB8C 004AAB8C 00000000 */   nop
  .L004AAB90:
    /* 3AAB90 004AAB90 1C00928E */  lw         $18, 0x1C($20)
  .L004AAB94:
    /* 3AAB94 004AAB94 2A183202 */  slt        $3, $17, $18
    /* 3AAB98 004AAB98 5B006014 */  bnez       $3, .L004AAD08
    /* 3AAB9C 004AAB9C 00000000 */   nop
    /* 3AABA0 004AABA0 8C006426 */  addiu      $4, $19, 0x8C
    /* 3AABA4 004AABA4 2D284002 */  daddu      $5, $18, $0
    /* 3AABA8 004AABA8 2D302002 */  daddu      $6, $17, $0
    /* 3AABAC 004AABAC FC2B120C */  jal        func_0048aff0
    /* 3AABB0 004AABB0 00000000 */   nop
    /* 3AABB4 004AABB4 BC006292 */  lbu        $2, 0xBC($19)
    /* 3AABB8 004AABB8 11004010 */  beqz       $2, .L004AAC00
    /* 3AABBC 004AABBC 00000000 */   nop
    /* 3AABC0 004AABC0 A043023C */  lui        $2, (0x43A00000 >> 16)
    /* 3AABC4 004AABC4 00188244 */  mtc1       $2, $f3
    /* 3AABC8 004AABC8 040002AE */  sw         $2, 0x4($16)
    /* 3AABCC 004AABCC 6043023C */  lui        $2, (0x43600000 >> 16)
    /* 3AABD0 004AABD0 00108244 */  mtc1       $2, $f2
    /* 3AABD4 004AABD4 080002AE */  sw         $2, 0x8($16)
    /* 3AABD8 004AABD8 41180046 */  sub.s      $f1, $f3, $f0
    /* 3AABDC 004AABDC 140001E6 */  swc1       $f1, 0x14($16)
    /* 3AABE0 004AABE0 41100046 */  sub.s      $f1, $f2, $f0
    /* 3AABE4 004AABE4 180001E6 */  swc1       $f1, 0x18($16)
    /* 3AABE8 004AABE8 40180046 */  add.s      $f1, $f3, $f0
    /* 3AABEC 004AABEC 1C0001E6 */  swc1       $f1, 0x1C($16)
    /* 3AABF0 004AABF0 00100046 */  add.s      $f0, $f2, $f0
    /* 3AABF4 004AABF4 200000E6 */  swc1       $f0, 0x20($16)
    /* 3AABF8 004AABF8 14000010 */  b          .L004AAC4C
    /* 3AABFC 004AABFC 00000000 */   nop
  .L004AAC00:
    /* 3AAC00 004AAC00 140081C6 */  lwc1       $f1, 0x14($20)
    /* 3AAC04 004AAC04 02030146 */  mul.s      $f12, $f0, $f1
    /* 3AAC08 004AAC08 00008ADA */  lqc2       $vf10, 0x0($20)
    /* 3AAC0C 004AAC0C 9429120C */  jal        func_0048a650
    /* 3AAC10 004AAC10 00000000 */   nop
    /* 3AAC14 004AAC14 6000A227 */  addiu      $2, $29, 0x60
    /* 3AAC18 004AAC18 00004AF8 */  sqc2       $vf10, 0x0($2)
    /* 3AAC1C 004AAC1C 6000A3C7 */  lwc1       $f3, 0x60($29)
    /* 3AAC20 004AAC20 040003E6 */  swc1       $f3, 0x4($16)
    /* 3AAC24 004AAC24 6400A2C7 */  lwc1       $f2, 0x64($29)
    /* 3AAC28 004AAC28 080002E6 */  swc1       $f2, 0x8($16)
    /* 3AAC2C 004AAC2C 41180046 */  sub.s      $f1, $f3, $f0
    /* 3AAC30 004AAC30 140001E6 */  swc1       $f1, 0x14($16)
    /* 3AAC34 004AAC34 41100046 */  sub.s      $f1, $f2, $f0
    /* 3AAC38 004AAC38 180001E6 */  swc1       $f1, 0x18($16)
    /* 3AAC3C 004AAC3C 40180046 */  add.s      $f1, $f3, $f0
    /* 3AAC40 004AAC40 1C0001E6 */  swc1       $f1, 0x1C($16)
    /* 3AAC44 004AAC44 00100046 */  add.s      $f0, $f2, $f0
    /* 3AAC48 004AAC48 200000E6 */  swc1       $f0, 0x20($16)
  .L004AAC4C:
    /* 3AAC4C 004AAC4C 2D206002 */  daddu      $4, $19, $0
    /* 3AAC50 004AAC50 24006526 */  addiu      $5, $19, 0x24
    /* 3AAC54 004AAC54 2D304002 */  daddu      $6, $18, $0
    /* 3AAC58 004AAC58 2D382002 */  daddu      $7, $17, $0
    /* 3AAC5C 004AAC5C F42A120C */  jal        func_0048abd0
    /* 3AAC60 004AAC60 00000000 */   nop
    /* 3AAC64 004AAC64 2D184000 */  daddu      $3, $2, $0
    /* 3AAC68 004AAC68 1000828E */  lw         $2, 0x10($20)
    /* 3AAC6C 004AAC6C 7C00A2AF */  sw         $2, 0x7C($29)
    /* 3AAC70 004AAC70 7C00A227 */  addiu      $2, $29, 0x7C
    /* 3AAC74 004AAC74 448080C7 */  lwc1       $f0, -0x7FBC($28)
    /* 3AAC78 004AAC78 0000428C */  lw         $2, 0x0($2)
    /* 3AAC7C 004AAC7C 88160270 */  pextlb     $2, $0, $2
    /* 3AAC80 004AAC80 88150270 */  pextlh     $2, $0, $2
    /* 3AAC84 004AAC84 0050A248 */  qmtc2.ni   $2, $vf10
    /* 3AAC88 004AAC88 3C51EA4B */  vitof0.xyzw $vf10, $vf10
    /* 3AAC8C 004AAC8C 00000244 */  mfc1       $2, $f0
    /* 3AAC90 004AAC90 00000000 */  nop
    /* 3AAC94 004AAC94 0010A248 */  qmtc2.ni   $2, $vf2
    /* 3AAC98 004AAC98 9852E24B */  vmulx.xyzw $vf10, $vf10, $vf2x
    /* 3AAC9C 004AAC9C 3C53EB4B */  vmove.xyzw $vf11, $vf10
    /* 3AACA0 004AACA0 7800A3AF */  sw         $3, 0x78($29)
    /* 3AACA4 004AACA4 7800A227 */  addiu      $2, $29, 0x78
    /* 3AACA8 004AACA8 0000428C */  lw         $2, 0x0($2)
    /* 3AACAC 004AACAC 88160270 */  pextlb     $2, $0, $2
    /* 3AACB0 004AACB0 88150270 */  pextlh     $2, $0, $2
    /* 3AACB4 004AACB4 0050A248 */  qmtc2.ni   $2, $vf10
    /* 3AACB8 004AACB8 3C51EA4B */  vitof0.xyzw $vf10, $vf10
    /* 3AACBC 004AACBC 00000344 */  mfc1       $3, $f0
    /* 3AACC0 004AACC0 00000000 */  nop
    /* 3AACC4 004AACC4 0010A348 */  qmtc2.ni   $3, $vf2
    /* 3AACC8 004AACC8 9852E24B */  vmulx.xyzw $vf10, $vf10, $vf2x
    /* 3AACCC 004AACCC AA52EB4B */  vmul.xyzw  $vf10, $vf10, $vf11
    /* 3AACD0 004AACD0 7F43033C */  lui        $3, (0x437F0000 >> 16)
    /* 3AACD4 004AACD4 0010A348 */  qmtc2.ni   $3, $vf2
    /* 3AACD8 004AACD8 9852E24B */  vmulx.xyzw $vf10, $vf10, $vf2x
    /* 3AACDC 004AACDC 7C51EA4B */  vftoi0.xyzw $vf10, $vf10
    /* 3AACE0 004AACE0 00502348 */  qmfc2.ni   $3, $vf10
    /* 3AACE4 004AACE4 C81D0370 */  ppach      $3, $0, $3
    /* 3AACE8 004AACE8 C81E0370 */  ppacb      $3, $0, $3
    /* 3AACEC 004AACEC 7400A3AF */  sw         $3, 0x74($29)
    /* 3AACF0 004AACF0 7400A38F */  lw         $3, 0x74($29)
    /* 3AACF4 004AACF4 0C0003AE */  sw         $3, 0xC($16)
    /* 3AACF8 004AACF8 2800638E */  lw         $3, 0x28($19)
    /* 3AACFC 004AACFC 100003AE */  sw         $3, 0x10($16)
    /* 3AAD00 004AAD00 02000010 */  b          .L004AAD0C
    /* 3AAD04 004AAD04 00000000 */   nop
  .L004AAD08:
    /* 3AAD08 004AAD08 0F0000A2 */  sb         $0, 0xF($16)
  .L004AAD0C:
    /* 3AAD0C 004AAD0C 5000BFDF */  ld         $31, 0x50($29)
    /* 3AAD10 004AAD10 4000B47B */  lq         $20, 0x40($29)
    /* 3AAD14 004AAD14 3000B37B */  lq         $19, 0x30($29)
    /* 3AAD18 004AAD18 2000B27B */  lq         $18, 0x20($29)
    /* 3AAD1C 004AAD1C 1000B17B */  lq         $17, 0x10($29)
    /* 3AAD20 004AAD20 0000B07B */  lq         $16, 0x0($29)
    /* 3AAD24 004AAD24 8000BD27 */  addiu      $29, $29, 0x80
    /* 3AAD28 004AAD28 0800E003 */  jr         $31
    /* 3AAD2C 004AAD2C 00000000 */   nop
.size func_004aab50, 0x1e0
