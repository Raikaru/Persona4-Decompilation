.section .text
.set noat
.set noreorder
glabel func_003aa9f0
    /* 2AA9F0 003AA9F0 90FFBD27 */  addiu      $29, $29, -0x70
    /* 2AA9F4 003AA9F4 003F033C */  lui        $3, (0x3F000000 >> 16)
    /* 2AA9F8 003AA9F8 3000BFFF */  sd         $31, 0x30($29)
    /* 2AA9FC 003AA9FC 00108344 */  mtc1       $3, $f2
    /* 2AAA00 003AAA00 2000B27F */  sq         $18, 0x20($29)
    /* 2AAA04 003AAA04 1000B17F */  sq         $17, 0x10($29)
    /* 2AAA08 003AAA08 2D90E000 */  daddu      $18, $7, $0
    /* 2AAA0C 003AAA0C 0000B07F */  sq         $16, 0x0($29)
    /* 2AAA10 003AAA10 700001C5 */  lwc1       $f1, 0x70($8)
    /* 2AAA14 003AAA14 0800098D */  lw         $9, 0x8($8)
    /* 2AAA18 003AAA18 740000C5 */  lwc1       $f0, 0x74($8)
    /* 2AAA1C 003AAA1C 0400838C */  lw         $3, 0x4($4)
    /* 2AAA20 003AAA20 0000A9C4 */  lwc1       $f9, 0x0($5)
    /* 2AAA24 003AAA24 0400118D */  lw         $17, 0x4($8)
    /* 2AAA28 003AAA28 0400A8C4 */  lwc1       $f8, 0x4($5)
    /* 2AAA2C 003AAA2C 0000908C */  lw         $16, 0x0($4)
    /* 2AAA30 003AAA30 0800A7C4 */  lwc1       $f7, 0x8($5)
    /* 2AAA34 003AAA34 0000C5C4 */  lwc1       $f5, 0x0($6)
    /* 2AAA38 003AAA38 42100146 */  mul.s      $f1, $f2, $f1
    /* 2AAA3C 003AAA3C 82110046 */  mul.s      $f6, $f2, $f0
    /* 2AAA40 003AAA40 02480146 */  mul.s      $f0, $f9, $f1
    /* 2AAA44 003AAA44 6000A0E7 */  swc1       $f0, 0x60($29)
    /* 2AAA48 003AAA48 02400146 */  mul.s      $f0, $f8, $f1
    /* 2AAA4C 003AAA4C 6400A0E7 */  swc1       $f0, 0x64($29)
    /* 2AAA50 003AAA50 02380146 */  mul.s      $f0, $f7, $f1
    /* 2AAA54 003AAA54 6800A0E7 */  swc1       $f0, 0x68($29)
    /* 2AAA58 003AAA58 02280646 */  mul.s      $f0, $f5, $f6
    /* 2AAA5C 003AAA5C 0400C4C4 */  lwc1       $f4, 0x4($6)
    /* 2AAA60 003AAA60 5000A0E7 */  swc1       $f0, 0x50($29)
    /* 2AAA64 003AAA64 6C0001C5 */  lwc1       $f1, 0x6C($8)
    /* 2AAA68 003AAA68 0800C3C4 */  lwc1       $f3, 0x8($6)
    /* 2AAA6C 003AAA6C 680002C5 */  lwc1       $f2, 0x68($8)
    /* 2AAA70 003AAA70 02200646 */  mul.s      $f0, $f4, $f6
    /* 2AAA74 003AAA74 5400A0E7 */  swc1       $f0, 0x54($29)
    /* 2AAA78 003AAA78 02180646 */  mul.s      $f0, $f3, $f6
    /* 2AAA7C 003AAA7C 1A080546 */  mula.s     $f1, $f5
    /* 2AAA80 003AAA80 5800A0E7 */  swc1       $f0, 0x58($29)
    /* 2AAA84 003AAA84 1C100946 */  madd.s     $f0, $f2, $f9
    /* 2AAA88 003AAA88 4000A0E7 */  swc1       $f0, 0x40($29)
    /* 2AAA8C 003AAA8C 1A080446 */  mula.s     $f1, $f4
    /* 2AAA90 003AAA90 1C100846 */  madd.s     $f0, $f2, $f8
    /* 2AAA94 003AAA94 1A080346 */  mula.s     $f1, $f3
    /* 2AAA98 003AAA98 4400A0E7 */  swc1       $f0, 0x44($29)
    /* 2AAA9C 003AAA9C 1C100746 */  madd.s     $f0, $f2, $f7
    /* 2AAAA0 003AAAA0 70012315 */  bne        $9, $3, .L003AB064
    /* 2AAAA4 003AAAA4 4800A0E7 */   swc1      $f0, 0x48($29)
    /* 2AAAA8 003AAAA8 9886100C */  jal        func_00421a60
    /* 2AAAAC 003AAAAC 2D200000 */   daddu     $4, $0, $0
    /* 2AAAB0 003AAAB0 0110033C */  lui        $3, (0x10010000 >> 16)
    /* 2AAAB4 003AAAB4 00D0648C */  lw         $4, -0x3000($3)
    /* 2AAAB8 003AAAB8 00018430 */  andi       $4, $4, 0x100
    /* 2AAABC 003AAABC 0C008010 */  beqz       $4, .L003AAAF0
    /* 2AAAC0 003AAAC0 00000000 */   nop
    /* 2AAAC4 003AAAC4 00010424 */  addiu      $4, $0, 0x100
    /* 2AAAC8 003AAAC8 20E064AC */  sw         $4, -0x1FE0($3)
    /* 2AAACC 003AAACC 0F000000 */  sync
    /* 2AAAD0 003AAAD0 0F040000 */  sync.p
  .L003AAAD4:
    /* 2AAAD4 003AAAD4 00000000 */  nop
    /* 2AAAD8 003AAAD8 00000000 */  nop
    /* 2AAADC 003AAADC 00000000 */  nop
    /* 2AAAE0 003AAAE0 00000000 */  nop
    /* 2AAAE4 003AAAE4 00000000 */  nop
    /* 2AAAE8 003AAAE8 FAFF0041 */  bc0f       .L003AAAD4 /* handwritten instruction */
    /* 2AAAEC 003AAAEC 00000000 */   nop
  .L003AAAF0:
    /* 2AAAF0 003AAAF0 0110033C */  lui        $3, (0x10010000 >> 16)
    /* 2AAAF4 003AAAF4 00D4648C */  lw         $4, -0x2C00($3)
    /* 2AAAF8 003AAAF8 00018430 */  andi       $4, $4, 0x100
    /* 2AAAFC 003AAAFC 14008010 */  beqz       $4, .L003AAB50
    /* 2AAB00 003AAB00 00000000 */   nop
    /* 2AAB04 003AAB04 00020424 */  addiu      $4, $0, 0x200
    /* 2AAB08 003AAB08 20E064AC */  sw         $4, -0x1FE0($3)
    /* 2AAB0C 003AAB0C 0F000000 */  sync
    /* 2AAB10 003AAB10 0F040000 */  sync.p
  .L003AAB14:
    /* 2AAB14 003AAB14 00000000 */  nop
    /* 2AAB18 003AAB18 00000000 */  nop
    /* 2AAB1C 003AAB1C 00000000 */  nop
    /* 2AAB20 003AAB20 00000000 */  nop
    /* 2AAB24 003AAB24 00000000 */  nop
    /* 2AAB28 003AAB28 FAFF0041 */  bc0f       .L003AAB14 /* handwritten instruction */
    /* 2AAB2C 003AAB2C 00000000 */   nop
    /* 2AAB30 003AAB30 0110033C */  lui        $3, (0x10010000 >> 16)
  .L003AAB34:
    /* 2AAB34 003AAB34 00D4648C */  lw         $4, -0x2C00($3)
    /* 2AAB38 003AAB38 00018430 */  andi       $4, $4, 0x100
    /* 2AAB3C 003AAB3C 00000000 */  nop
    /* 2AAB40 003AAB40 00000000 */  nop
    /* 2AAB44 003AAB44 00000000 */  nop
    /* 2AAB48 003AAB48 FAFF8014 */  bnez       $4, .L003AAB34
    /* 2AAB4C 003AAB4C 00000000 */   nop
  .L003AAB50:
    /* 2AAB50 003AAB50 CD00412A */  slti       $1, $18, 0xCD
    /* 2AAB54 003AAB54 A2002014 */  bnez       $1, .L003AADE0
    /* 2AAB58 003AAB58 00000000 */   nop
    /* 2AAB5C 003AAB5C 00700E3C */  lui        $14, (0x70000CC0 >> 16)
    /* 2AAB60 003AAB60 0110063C */  lui        $6, (0x10010000 >> 16)
    /* 2AAB64 003AAB64 6000AC27 */  addiu      $12, $29, 0x60
    /* 2AAB68 003AAB68 5000AB27 */  addiu      $11, $29, 0x50
    /* 2AAB6C 003AAB6C 4000AA27 */  addiu      $10, $29, 0x40
    /* 2AAB70 003AAB70 00010524 */  addiu      $5, $0, 0x100
    /* 2AAB74 003AAB74 00020424 */  addiu      $4, $0, 0x200
    /* 2AAB78 003AAB78 CC000324 */  addiu      $3, $0, 0xCC
    /* 2AAB7C 003AAB7C C00CCD35 */  ori        $13, $14, (0x70000CC0 & 0xFFFF)
    /* 2AAB80 003AAB80 C00C0824 */  addiu      $8, $0, 0xCC0
    /* 2AAB84 003AAB84 30030724 */  addiu      $7, $0, 0x330
  .L003AAB88:
    /* 2AAB88 003AAB88 00D0C98C */  lw         $9, -0x3000($6)
    /* 2AAB8C 003AAB8C 00012931 */  andi       $9, $9, 0x100
    /* 2AAB90 003AAB90 0D002011 */  beqz       $9, .L003AABC8
    /* 2AAB94 003AAB94 00000000 */   nop
    /* 2AAB98 003AAB98 20E0C5AC */  sw         $5, -0x1FE0($6)
    /* 2AAB9C 003AAB9C 0F000000 */  sync
    /* 2AABA0 003AABA0 0F040000 */  sync.p
    /* 2AABA4 003AABA4 00000000 */  nop
  .L003AABA8:
    /* 2AABA8 003AABA8 00000000 */  nop
    /* 2AABAC 003AABAC 00000000 */  nop
    /* 2AABB0 003AABB0 00000000 */  nop
    /* 2AABB4 003AABB4 00000000 */  nop
    /* 2AABB8 003AABB8 00000000 */  nop
    /* 2AABBC 003AABBC FAFF0041 */  bc0f       .L003AABA8 /* handwritten instruction */
    /* 2AABC0 003AABC0 00000000 */   nop
    /* 2AABC4 003AABC4 00000000 */  nop
  .L003AABC8:
    /* 2AABC8 003AABC8 00D4C98C */  lw         $9, -0x2C00($6)
    /* 2AABCC 003AABCC 00012931 */  andi       $9, $9, 0x100
    /* 2AABD0 003AABD0 15002011 */  beqz       $9, .L003AAC28
    /* 2AABD4 003AABD4 00000000 */   nop
    /* 2AABD8 003AABD8 20E0C4AC */  sw         $4, -0x1FE0($6)
    /* 2AABDC 003AABDC 0F000000 */  sync
    /* 2AABE0 003AABE0 0F040000 */  sync.p
    /* 2AABE4 003AABE4 00000000 */  nop
  .L003AABE8:
    /* 2AABE8 003AABE8 00000000 */  nop
    /* 2AABEC 003AABEC 00000000 */  nop
    /* 2AABF0 003AABF0 00000000 */  nop
    /* 2AABF4 003AABF4 00000000 */  nop
    /* 2AABF8 003AABF8 00000000 */  nop
    /* 2AABFC 003AABFC FAFF0041 */  bc0f       .L003AABE8 /* handwritten instruction */
    /* 2AAC00 003AAC00 00000000 */   nop
    /* 2AAC04 003AAC04 00000000 */  nop
  .L003AAC08:
    /* 2AAC08 003AAC08 00D4C98C */  lw         $9, -0x2C00($6)
    /* 2AAC0C 003AAC0C 00012931 */  andi       $9, $9, 0x100
    /* 2AAC10 003AAC10 00000000 */  nop
    /* 2AAC14 003AAC14 00000000 */  nop
    /* 2AAC18 003AAC18 00000000 */  nop
    /* 2AAC1C 003AAC1C FAFF2015 */  bnez       $9, .L003AAC08
    /* 2AAC20 003AAC20 00000000 */   nop
    /* 2AAC24 003AAC24 00000000 */  nop
  .L003AAC28:
    /* 2AAC28 003AAC28 10E0C4AC */  sw         $4, -0x1FF0($6)
    /* 2AAC2C 003AAC2C 80D4C0AC */  sw         $0, -0x2B80($6)
    /* 2AAC30 003AAC30 10D4D1AC */  sw         $17, -0x2BF0($6)
    /* 2AAC34 003AAC34 20D4C3AC */  sw         $3, -0x2BE0($6)
    /* 2AAC38 003AAC38 00D4C5AC */  sw         $5, -0x2C00($6)
    /* 2AAC3C 003AAC3C 0F000000 */  sync
    /* 2AAC40 003AAC40 0F040000 */  sync.p
    /* 2AAC44 003AAC44 00D4C98C */  lw         $9, -0x2C00($6)
    /* 2AAC48 003AAC48 00012931 */  andi       $9, $9, 0x100
    /* 2AAC4C 003AAC4C 14002011 */  beqz       $9, .L003AACA0
    /* 2AAC50 003AAC50 00000000 */   nop
    /* 2AAC54 003AAC54 20E0C4AC */  sw         $4, -0x1FE0($6)
    /* 2AAC58 003AAC58 0F000000 */  sync
    /* 2AAC5C 003AAC5C 0F040000 */  sync.p
  .L003AAC60:
    /* 2AAC60 003AAC60 00000000 */  nop
    /* 2AAC64 003AAC64 00000000 */  nop
    /* 2AAC68 003AAC68 00000000 */  nop
    /* 2AAC6C 003AAC6C 00000000 */  nop
    /* 2AAC70 003AAC70 00000000 */  nop
    /* 2AAC74 003AAC74 FAFF0041 */  bc0f       .L003AAC60 /* handwritten instruction */
    /* 2AAC78 003AAC78 00000000 */   nop
    /* 2AAC7C 003AAC7C 00000000 */  nop
  .L003AAC80:
    /* 2AAC80 003AAC80 00D4C98C */  lw         $9, -0x2C00($6)
    /* 2AAC84 003AAC84 00012931 */  andi       $9, $9, 0x100
    /* 2AAC88 003AAC88 00000000 */  nop
    /* 2AAC8C 003AAC8C 00000000 */  nop
    /* 2AAC90 003AAC90 00000000 */  nop
    /* 2AAC94 003AAC94 FAFF2015 */  bnez       $9, .L003AAC80
    /* 2AAC98 003AAC98 00000000 */   nop
    /* 2AAC9C 003AAC9C 00000000 */  nop
  .L003AACA0:
    /* 2AACA0 003AACA0 2DC0C001 */  daddu      $24, $14, $0
    /* 2AACA4 003AACA4 2D78A001 */  daddu      $15, $13, $0
    /* 2AACA8 003AACA8 2DC80000 */  daddu      $25, $0, $0
    /* 2AACAC 003AACAC 00000000 */  nop
  .L003AACB0:
    /* 2AACB0 003AACB0 000001DB */  lqc2       $vf1, (0x70000000 & 0xFFFF)($24)
    /* 2AACB4 003AACB4 000082D9 */  lqc2       $vf2, 0x0($12)
    /* 2AACB8 003AACB8 000063D9 */  lqc2       $vf3, 0x0($11)
    /* 2AACBC 003AACBC 000048D9 */  lqc2       $vf8, 0x0($10)
    /* 2AACC0 003AACC0 2C09C24B */  vsub.xyz   $vf4, $vf1, $vf2
    /* 2AACC4 003AACC4 6809C24B */  vadd.xyz   $vf5, $vf1, $vf2
    /* 2AACC8 003AACC8 A809C24B */  vadd.xyz   $vf6, $vf1, $vf2
    /* 2AACCC 003AACCC EC09C24B */  vsub.xyz   $vf7, $vf1, $vf2
    /* 2AACD0 003AACD0 2C21C34B */  vsub.xyz   $vf4, $vf4, $vf3
    /* 2AACD4 003AACD4 6C29C34B */  vsub.xyz   $vf5, $vf5, $vf3
    /* 2AACD8 003AACD8 A831C34B */  vadd.xyz   $vf6, $vf6, $vf3
    /* 2AACDC 003AACDC E839C34B */  vadd.xyz   $vf7, $vf7, $vf3
    /* 2AACE0 003AACE0 2821C84B */  vadd.xyz   $vf4, $vf4, $vf8
    /* 2AACE4 003AACE4 6829C84B */  vadd.xyz   $vf5, $vf5, $vf8
    /* 2AACE8 003AACE8 A831C84B */  vadd.xyz   $vf6, $vf6, $vf8
    /* 2AACEC 003AACEC E839C84B */  vadd.xyz   $vf7, $vf7, $vf8
    /* 2AACF0 003AACF0 0000E4F9 */  sqc2       $vf4, 0x0($15)
    /* 2AACF4 003AACF4 1000E5F9 */  sqc2       $vf5, 0x10($15)
    /* 2AACF8 003AACF8 2000E6F9 */  sqc2       $vf6, 0x20($15)
    /* 2AACFC 003AACFC 3000E7F9 */  sqc2       $vf7, 0x30($15)
    /* 2AAD00 003AAD00 01003927 */  addiu      $25, $25, 0x1
    /* 2AAD04 003AAD04 4000EF25 */  addiu      $15, $15, 0x40
    /* 2AAD08 003AAD08 CC00292B */  slti       $9, $25, 0xCC
    /* 2AAD0C 003AAD0C E8FF2015 */  bnez       $9, .L003AACB0
    /* 2AAD10 003AAD10 10001827 */   addiu     $24, $24, %lo(D_70000010)
    /* 2AAD14 003AAD14 00D0C98C */  lw         $9, -0x3000($6)
    /* 2AAD18 003AAD18 00012931 */  andi       $9, $9, 0x100
    /* 2AAD1C 003AAD1C 0C002011 */  beqz       $9, .L003AAD50
    /* 2AAD20 003AAD20 00000000 */   nop
    /* 2AAD24 003AAD24 20E0C5AC */  sw         $5, -0x1FE0($6)
    /* 2AAD28 003AAD28 0F000000 */  sync
    /* 2AAD2C 003AAD2C 0F040000 */  sync.p
  .L003AAD30:
    /* 2AAD30 003AAD30 00000000 */  nop
    /* 2AAD34 003AAD34 00000000 */  nop
    /* 2AAD38 003AAD38 00000000 */  nop
    /* 2AAD3C 003AAD3C 00000000 */  nop
    /* 2AAD40 003AAD40 00000000 */  nop
    /* 2AAD44 003AAD44 FAFF0041 */  bc0f       .L003AAD30 /* handwritten instruction */
    /* 2AAD48 003AAD48 00000000 */   nop
    /* 2AAD4C 003AAD4C 00000000 */  nop
  .L003AAD50:
    /* 2AAD50 003AAD50 00D4C98C */  lw         $9, -0x2C00($6)
    /* 2AAD54 003AAD54 00012931 */  andi       $9, $9, 0x100
    /* 2AAD58 003AAD58 15002011 */  beqz       $9, .L003AADB0
    /* 2AAD5C 003AAD5C 00000000 */   nop
    /* 2AAD60 003AAD60 20E0C4AC */  sw         $4, -0x1FE0($6)
    /* 2AAD64 003AAD64 0F000000 */  sync
    /* 2AAD68 003AAD68 0F040000 */  sync.p
    /* 2AAD6C 003AAD6C 00000000 */  nop
  .L003AAD70:
    /* 2AAD70 003AAD70 00000000 */  nop
    /* 2AAD74 003AAD74 00000000 */  nop
    /* 2AAD78 003AAD78 00000000 */  nop
    /* 2AAD7C 003AAD7C 00000000 */  nop
    /* 2AAD80 003AAD80 00000000 */  nop
    /* 2AAD84 003AAD84 FAFF0041 */  bc0f       .L003AAD70 /* handwritten instruction */
    /* 2AAD88 003AAD88 00000000 */   nop
    /* 2AAD8C 003AAD8C 00000000 */  nop
  .L003AAD90:
    /* 2AAD90 003AAD90 00D4C98C */  lw         $9, -0x2C00($6)
    /* 2AAD94 003AAD94 00012931 */  andi       $9, $9, 0x100
    /* 2AAD98 003AAD98 00000000 */  nop
    /* 2AAD9C 003AAD9C 00000000 */  nop
    /* 2AADA0 003AADA0 00000000 */  nop
    /* 2AADA4 003AADA4 FAFF2015 */  bnez       $9, .L003AAD90
    /* 2AADA8 003AADA8 00000000 */   nop
    /* 2AADAC 003AADAC 00000000 */  nop
  .L003AADB0:
    /* 2AADB0 003AADB0 10E0C5AC */  sw         $5, -0x1FF0($6)
    /* 2AADB4 003AADB4 80D0C8AC */  sw         $8, -0x2F80($6)
    /* 2AADB8 003AADB8 10D0D0AC */  sw         $16, -0x2FF0($6)
    /* 2AADBC 003AADBC 20D0C7AC */  sw         $7, -0x2FE0($6)
    /* 2AADC0 003AADC0 00D0C5AC */  sw         $5, -0x3000($6)
    /* 2AADC4 003AADC4 0F000000 */  sync
    /* 2AADC8 003AADC8 0F040000 */  sync.p
    /* 2AADCC 003AADCC 34FF5226 */  addiu      $18, $18, -0xCC
    /* 2AADD0 003AADD0 C00C3126 */  addiu      $17, $17, 0xCC0
    /* 2AADD4 003AADD4 CD00412A */  slti       $1, $18, 0xCD
    /* 2AADD8 003AADD8 6BFF2010 */  beqz       $1, .L003AAB88
    /* 2AADDC 003AADDC 00331026 */   addiu     $16, $16, 0x3300
  .L003AADE0:
    /* 2AADE0 003AADE0 C1004012 */  beqz       $18, .L003AB0E8
    /* 2AADE4 003AADE4 00000000 */   nop
    /* 2AADE8 003AADE8 0110033C */  lui        $3, (0x10010000 >> 16)
    /* 2AADEC 003AADEC 00D0648C */  lw         $4, -0x3000($3)
    /* 2AADF0 003AADF0 00018430 */  andi       $4, $4, 0x100
    /* 2AADF4 003AADF4 0C008010 */  beqz       $4, .L003AAE28
    /* 2AADF8 003AADF8 00000000 */   nop
    /* 2AADFC 003AADFC 00010424 */  addiu      $4, $0, 0x100
    /* 2AAE00 003AAE00 20E064AC */  sw         $4, -0x1FE0($3)
    /* 2AAE04 003AAE04 0F000000 */  sync
    /* 2AAE08 003AAE08 0F040000 */  sync.p
  .L003AAE0C:
    /* 2AAE0C 003AAE0C 00000000 */  nop
    /* 2AAE10 003AAE10 00000000 */  nop
    /* 2AAE14 003AAE14 00000000 */  nop
    /* 2AAE18 003AAE18 00000000 */  nop
    /* 2AAE1C 003AAE1C 00000000 */  nop
    /* 2AAE20 003AAE20 FAFF0041 */  bc0f       .L003AAE0C /* handwritten instruction */
    /* 2AAE24 003AAE24 00000000 */   nop
  .L003AAE28:
    /* 2AAE28 003AAE28 0110033C */  lui        $3, (0x10010000 >> 16)
    /* 2AAE2C 003AAE2C 00D4648C */  lw         $4, -0x2C00($3)
    /* 2AAE30 003AAE30 00018430 */  andi       $4, $4, 0x100
    /* 2AAE34 003AAE34 14008010 */  beqz       $4, .L003AAE88
    /* 2AAE38 003AAE38 00000000 */   nop
    /* 2AAE3C 003AAE3C 00020424 */  addiu      $4, $0, 0x200
    /* 2AAE40 003AAE40 20E064AC */  sw         $4, -0x1FE0($3)
    /* 2AAE44 003AAE44 0F000000 */  sync
    /* 2AAE48 003AAE48 0F040000 */  sync.p
  .L003AAE4C:
    /* 2AAE4C 003AAE4C 00000000 */  nop
    /* 2AAE50 003AAE50 00000000 */  nop
    /* 2AAE54 003AAE54 00000000 */  nop
    /* 2AAE58 003AAE58 00000000 */  nop
    /* 2AAE5C 003AAE5C 00000000 */  nop
    /* 2AAE60 003AAE60 FAFF0041 */  bc0f       .L003AAE4C /* handwritten instruction */
    /* 2AAE64 003AAE64 00000000 */   nop
    /* 2AAE68 003AAE68 0110033C */  lui        $3, (0x10010000 >> 16)
  .L003AAE6C:
    /* 2AAE6C 003AAE6C 00D4648C */  lw         $4, -0x2C00($3)
    /* 2AAE70 003AAE70 00018430 */  andi       $4, $4, 0x100
    /* 2AAE74 003AAE74 00000000 */  nop
    /* 2AAE78 003AAE78 00000000 */  nop
    /* 2AAE7C 003AAE7C 00000000 */  nop
    /* 2AAE80 003AAE80 FAFF8014 */  bnez       $4, .L003AAE6C
    /* 2AAE84 003AAE84 00000000 */   nop
  .L003AAE88:
    /* 2AAE88 003AAE88 00020524 */  addiu      $5, $0, 0x200
    /* 2AAE8C 003AAE8C 0110033C */  lui        $3, (0x10010000 >> 16)
    /* 2AAE90 003AAE90 00010424 */  addiu      $4, $0, 0x100
    /* 2AAE94 003AAE94 10E065AC */  sw         $5, -0x1FF0($3)
    /* 2AAE98 003AAE98 80D460AC */  sw         $0, -0x2B80($3)
    /* 2AAE9C 003AAE9C 10D471AC */  sw         $17, -0x2BF0($3)
    /* 2AAEA0 003AAEA0 20D472AC */  sw         $18, -0x2BE0($3)
    /* 2AAEA4 003AAEA4 00D464AC */  sw         $4, -0x2C00($3)
    /* 2AAEA8 003AAEA8 0F000000 */  sync
    /* 2AAEAC 003AAEAC 0F040000 */  sync.p
    /* 2AAEB0 003AAEB0 00D4648C */  lw         $4, -0x2C00($3)
    /* 2AAEB4 003AAEB4 00018430 */  andi       $4, $4, 0x100
    /* 2AAEB8 003AAEB8 13008010 */  beqz       $4, .L003AAF08
    /* 2AAEBC 003AAEBC 00000000 */   nop
    /* 2AAEC0 003AAEC0 20E065AC */  sw         $5, -0x1FE0($3)
    /* 2AAEC4 003AAEC4 0F000000 */  sync
    /* 2AAEC8 003AAEC8 0F040000 */  sync.p
  .L003AAECC:
    /* 2AAECC 003AAECC 00000000 */  nop
    /* 2AAED0 003AAED0 00000000 */  nop
    /* 2AAED4 003AAED4 00000000 */  nop
    /* 2AAED8 003AAED8 00000000 */  nop
    /* 2AAEDC 003AAEDC 00000000 */  nop
    /* 2AAEE0 003AAEE0 FAFF0041 */  bc0f       .L003AAECC /* handwritten instruction */
    /* 2AAEE4 003AAEE4 00000000 */   nop
    /* 2AAEE8 003AAEE8 0110033C */  lui        $3, (0x10010000 >> 16)
  .L003AAEEC:
    /* 2AAEEC 003AAEEC 00D4648C */  lw         $4, -0x2C00($3)
    /* 2AAEF0 003AAEF0 00018430 */  andi       $4, $4, 0x100
    /* 2AAEF4 003AAEF4 00000000 */  nop
    /* 2AAEF8 003AAEF8 00000000 */  nop
    /* 2AAEFC 003AAEFC 00000000 */  nop
    /* 2AAF00 003AAF00 FAFF8014 */  bnez       $4, .L003AAEEC
    /* 2AAF04 003AAF04 00000000 */   nop
  .L003AAF08:
    /* 2AAF08 003AAF08 0070183C */  lui        $24, (0x70000CC0 >> 16)
    /* 2AAF0C 003AAF0C 2A081200 */  slt        $1, $0, $18
    /* 2AAF10 003AAF10 C00C0F37 */  ori        $15, $24, (0x70000CC0 & 0xFFFF)
    /* 2AAF14 003AAF14 1E002010 */  beqz       $1, .L003AAF90
    /* 2AAF18 003AAF18 2D380000 */   daddu     $7, $0, $0
    /* 2AAF1C 003AAF1C 6000A627 */  addiu      $6, $29, 0x60
    /* 2AAF20 003AAF20 5000A527 */  addiu      $5, $29, 0x50
    /* 2AAF24 003AAF24 4000A427 */  addiu      $4, $29, 0x40
  .L003AAF28:
    /* 2AAF28 003AAF28 000001DB */  lqc2       $vf1, (0x70000000 & 0xFFFF)($24)
    /* 2AAF2C 003AAF2C 0000C2D8 */  lqc2       $vf2, 0x0($6)
    /* 2AAF30 003AAF30 0000A3D8 */  lqc2       $vf3, 0x0($5)
    /* 2AAF34 003AAF34 000088D8 */  lqc2       $vf8, 0x0($4)
    /* 2AAF38 003AAF38 2C09C24B */  vsub.xyz   $vf4, $vf1, $vf2
    /* 2AAF3C 003AAF3C 6809C24B */  vadd.xyz   $vf5, $vf1, $vf2
    /* 2AAF40 003AAF40 A809C24B */  vadd.xyz   $vf6, $vf1, $vf2
    /* 2AAF44 003AAF44 EC09C24B */  vsub.xyz   $vf7, $vf1, $vf2
    /* 2AAF48 003AAF48 2C21C34B */  vsub.xyz   $vf4, $vf4, $vf3
    /* 2AAF4C 003AAF4C 6C29C34B */  vsub.xyz   $vf5, $vf5, $vf3
    /* 2AAF50 003AAF50 A831C34B */  vadd.xyz   $vf6, $vf6, $vf3
    /* 2AAF54 003AAF54 E839C34B */  vadd.xyz   $vf7, $vf7, $vf3
    /* 2AAF58 003AAF58 2821C84B */  vadd.xyz   $vf4, $vf4, $vf8
    /* 2AAF5C 003AAF5C 6829C84B */  vadd.xyz   $vf5, $vf5, $vf8
    /* 2AAF60 003AAF60 A831C84B */  vadd.xyz   $vf6, $vf6, $vf8
    /* 2AAF64 003AAF64 E839C84B */  vadd.xyz   $vf7, $vf7, $vf8
    /* 2AAF68 003AAF68 0000E4F9 */  sqc2       $vf4, 0x0($15)
    /* 2AAF6C 003AAF6C 1000E5F9 */  sqc2       $vf5, 0x10($15)
    /* 2AAF70 003AAF70 2000E6F9 */  sqc2       $vf6, 0x20($15)
    /* 2AAF74 003AAF74 3000E7F9 */  sqc2       $vf7, 0x30($15)
    /* 2AAF78 003AAF78 0100E724 */  addiu      $7, $7, 0x1
    /* 2AAF7C 003AAF7C 4000EF25 */  addiu      $15, $15, 0x40
    /* 2AAF80 003AAF80 2A18F200 */  slt        $3, $7, $18
    /* 2AAF84 003AAF84 E8FF6014 */  bnez       $3, .L003AAF28
    /* 2AAF88 003AAF88 10001827 */   addiu     $24, $24, %lo(D_70000010)
    /* 2AAF8C 003AAF8C 00000000 */  nop
  .L003AAF90:
    /* 2AAF90 003AAF90 0110033C */  lui        $3, (0x10010000 >> 16)
    /* 2AAF94 003AAF94 00D0648C */  lw         $4, -0x3000($3)
    /* 2AAF98 003AAF98 00018430 */  andi       $4, $4, 0x100
    /* 2AAF9C 003AAF9C 0C008010 */  beqz       $4, .L003AAFD0
    /* 2AAFA0 003AAFA0 00000000 */   nop
    /* 2AAFA4 003AAFA4 00010424 */  addiu      $4, $0, 0x100
    /* 2AAFA8 003AAFA8 20E064AC */  sw         $4, -0x1FE0($3)
    /* 2AAFAC 003AAFAC 0F000000 */  sync
    /* 2AAFB0 003AAFB0 0F040000 */  sync.p
  .L003AAFB4:
    /* 2AAFB4 003AAFB4 00000000 */  nop
    /* 2AAFB8 003AAFB8 00000000 */  nop
    /* 2AAFBC 003AAFBC 00000000 */  nop
    /* 2AAFC0 003AAFC0 00000000 */  nop
    /* 2AAFC4 003AAFC4 00000000 */  nop
    /* 2AAFC8 003AAFC8 FAFF0041 */  bc0f       .L003AAFB4 /* handwritten instruction */
    /* 2AAFCC 003AAFCC 00000000 */   nop
  .L003AAFD0:
    /* 2AAFD0 003AAFD0 0110033C */  lui        $3, (0x10010000 >> 16)
    /* 2AAFD4 003AAFD4 00D4648C */  lw         $4, -0x2C00($3)
    /* 2AAFD8 003AAFD8 00018430 */  andi       $4, $4, 0x100
    /* 2AAFDC 003AAFDC 14008010 */  beqz       $4, .L003AB030
    /* 2AAFE0 003AAFE0 00000000 */   nop
    /* 2AAFE4 003AAFE4 00020424 */  addiu      $4, $0, 0x200
    /* 2AAFE8 003AAFE8 20E064AC */  sw         $4, -0x1FE0($3)
    /* 2AAFEC 003AAFEC 0F000000 */  sync
    /* 2AAFF0 003AAFF0 0F040000 */  sync.p
  .L003AAFF4:
    /* 2AAFF4 003AAFF4 00000000 */  nop
    /* 2AAFF8 003AAFF8 00000000 */  nop
    /* 2AAFFC 003AAFFC 00000000 */  nop
    /* 2AB000 003AB000 00000000 */  nop
    /* 2AB004 003AB004 00000000 */  nop
    /* 2AB008 003AB008 FAFF0041 */  bc0f       .L003AAFF4 /* handwritten instruction */
    /* 2AB00C 003AB00C 00000000 */   nop
    /* 2AB010 003AB010 0110033C */  lui        $3, (0x10010000 >> 16)
  .L003AB014:
    /* 2AB014 003AB014 00D4648C */  lw         $4, -0x2C00($3)
    /* 2AB018 003AB018 00018430 */  andi       $4, $4, 0x100
    /* 2AB01C 003AB01C 00000000 */  nop
    /* 2AB020 003AB020 00000000 */  nop
    /* 2AB024 003AB024 00000000 */  nop
    /* 2AB028 003AB028 FAFF8014 */  bnez       $4, .L003AB014
    /* 2AB02C 003AB02C 00000000 */   nop
  .L003AB030:
    /* 2AB030 003AB030 00010624 */  addiu      $6, $0, 0x100
    /* 2AB034 003AB034 0110033C */  lui        $3, (0x10010000 >> 16)
    /* 2AB038 003AB038 C00C0524 */  addiu      $5, $0, 0xCC0
    /* 2AB03C 003AB03C 10E066AC */  sw         $6, -0x1FF0($3)
    /* 2AB040 003AB040 80201200 */  sll        $4, $18, 2
    /* 2AB044 003AB044 80D065AC */  sw         $5, -0x2F80($3)
    /* 2AB048 003AB048 10D070AC */  sw         $16, -0x2FF0($3)
    /* 2AB04C 003AB04C 20D064AC */  sw         $4, -0x2FE0($3)
    /* 2AB050 003AB050 00D066AC */  sw         $6, -0x3000($3)
    /* 2AB054 003AB054 0F000000 */  sync
    /* 2AB058 003AB058 0F040000 */  sync.p
    /* 2AB05C 003AB05C 22000010 */  b          .L003AB0E8
    /* 2AB060 003AB060 00000000 */   nop
  .L003AB064:
    /* 2AB064 003AB064 2A081200 */  slt        $1, $0, $18
    /* 2AB068 003AB068 1F002010 */  beqz       $1, .L003AB0E8
    /* 2AB06C 003AB06C 2D400000 */   daddu     $8, $0, $0
    /* 2AB070 003AB070 80200300 */  sll        $4, $3, 2
    /* 2AB074 003AB074 6000A727 */  addiu      $7, $29, 0x60
    /* 2AB078 003AB078 5000A627 */  addiu      $6, $29, 0x50
    /* 2AB07C 003AB07C 4000A527 */  addiu      $5, $29, 0x40
  .L003AB080:
    /* 2AB080 003AB080 000021DA */  lqc2       $vf1, 0x0($17)
    /* 2AB084 003AB084 0000E2D8 */  lqc2       $vf2, 0x0($7)
    /* 2AB088 003AB088 0000C3D8 */  lqc2       $vf3, 0x0($6)
    /* 2AB08C 003AB08C 0000A8D8 */  lqc2       $vf8, 0x0($5)
    /* 2AB090 003AB090 2C09C24B */  vsub.xyz   $vf4, $vf1, $vf2
    /* 2AB094 003AB094 6809C24B */  vadd.xyz   $vf5, $vf1, $vf2
    /* 2AB098 003AB098 A809C24B */  vadd.xyz   $vf6, $vf1, $vf2
    /* 2AB09C 003AB09C EC09C24B */  vsub.xyz   $vf7, $vf1, $vf2
    /* 2AB0A0 003AB0A0 2C21C34B */  vsub.xyz   $vf4, $vf4, $vf3
    /* 2AB0A4 003AB0A4 6C29C34B */  vsub.xyz   $vf5, $vf5, $vf3
    /* 2AB0A8 003AB0A8 A831C34B */  vadd.xyz   $vf6, $vf6, $vf3
    /* 2AB0AC 003AB0AC E839C34B */  vadd.xyz   $vf7, $vf7, $vf3
    /* 2AB0B0 003AB0B0 2821C84B */  vadd.xyz   $vf4, $vf4, $vf8
    /* 2AB0B4 003AB0B4 6829C84B */  vadd.xyz   $vf5, $vf5, $vf8
    /* 2AB0B8 003AB0B8 A831C84B */  vadd.xyz   $vf6, $vf6, $vf8
    /* 2AB0BC 003AB0BC E839C84B */  vadd.xyz   $vf7, $vf7, $vf8
    /* 2AB0C0 003AB0C0 000004FA */  sqc2       $vf4, 0x0($16)
    /* 2AB0C4 003AB0C4 100005FA */  sqc2       $vf5, 0x10($16)
    /* 2AB0C8 003AB0C8 200006FA */  sqc2       $vf6, 0x20($16)
    /* 2AB0CC 003AB0CC 300007FA */  sqc2       $vf7, 0x30($16)
    /* 2AB0D0 003AB0D0 01000825 */  addiu      $8, $8, 0x1
    /* 2AB0D4 003AB0D4 21800402 */  addu       $16, $16, $4
    /* 2AB0D8 003AB0D8 2A181201 */  slt        $3, $8, $18
    /* 2AB0DC 003AB0DC E8FF6014 */  bnez       $3, .L003AB080
    /* 2AB0E0 003AB0E0 21882902 */   addu      $17, $17, $9
    /* 2AB0E4 003AB0E4 00000000 */  nop
  .L003AB0E8:
    /* 2AB0E8 003AB0E8 3000BFDF */  ld         $31, 0x30($29)
    /* 2AB0EC 003AB0EC 2000B27B */  lq         $18, 0x20($29)
    /* 2AB0F0 003AB0F0 1000B17B */  lq         $17, 0x10($29)
    /* 2AB0F4 003AB0F4 0000B07B */  lq         $16, 0x0($29)
    /* 2AB0F8 003AB0F8 0800E003 */  jr         $31
    /* 2AB0FC 003AB0FC 7000BD27 */   addiu     $29, $29, 0x70
.size func_003aa9f0, 0x710
