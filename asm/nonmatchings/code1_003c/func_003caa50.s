.section .text
.set noat
.set noreorder
glabel func_003caa50
    /* 2CAA50 003CAA50 90FEBD27 */  addiu      $29, $29, -0x170
    /* 2CAA54 003CAA54 4000BFFF */  sd         $31, 0x40($29)
    /* 2CAA58 003CAA58 3000B37F */  sq         $19, 0x30($29)
    /* 2CAA5C 003CAA5C 2000B27F */  sq         $18, 0x20($29)
    /* 2CAA60 003CAA60 2D98A000 */  daddu      $19, $5, $0
    /* 2CAA64 003CAA64 1000B17F */  sq         $17, 0x10($29)
    /* 2CAA68 003CAA68 0000B07F */  sq         $16, 0x0($29)
    /* 2CAA6C 003CAA6C 2D880000 */  daddu      $17, $0, $0
    /* 2CAA70 003CAA70 2D808000 */  daddu      $16, $4, $0
    /* 2CAA74 003CAA74 B8FE0E0C */  jal        func_003bfae0
    /* 2CAA78 003CAA78 2D206002 */   daddu     $4, $19, $0
    /* 2CAA7C 003CAA7C 080040C4 */  lwc1       $f0, 0x8($2)
    /* 2CAA80 003CAA80 1C00128E */  lw         $18, 0x1C($16)
    /* 2CAA84 003CAA84 000044C4 */  lwc1       $f4, 0x0($2)
    /* 2CAA88 003CAA88 6401A627 */  addiu      $6, $29, 0x164
    /* 2CAA8C 003CAA8C 0C0041C4 */  lwc1       $f1, 0xC($2)
    /* 2CAA90 003CAA90 6801A427 */  addiu      $4, $29, 0x168
    /* 2CAA94 003CAA94 040042C4 */  lwc1       $f2, 0x4($2)
    /* 2CAA98 003CAA98 5401A527 */  addiu      $5, $29, 0x154
    /* 2CAA9C 003CAA9C 5801A327 */  addiu      $3, $29, 0x158
    /* 2CAAA0 003CAAA0 6801A0E7 */  swc1       $f0, 0x168($29)
    /* 2CAAA4 003CAAA4 8800103C */  lui        $16, %hi(D_008873F8)
    /* 2CAAA8 003CAAA8 F8731026 */  addiu      $16, $16, %lo(D_008873F8)
    /* 2CAAAC 003CAAAC 01200146 */  sub.s      $f0, $f4, $f1
    /* 2CAAB0 003CAAB0 6401A2E7 */  swc1       $f2, 0x164($29)
    /* 2CAAB4 003CAAB4 6001A0E7 */  swc1       $f0, 0x160($29)
    /* 2CAAB8 003CAAB8 00200146 */  add.s      $f0, $f4, $f1
    /* 2CAABC 003CAABC 0000C3C4 */  lwc1       $f3, 0x0($6)
    /* 2CAAC0 003CAAC0 5001A0E7 */  swc1       $f0, 0x150($29)
    /* 2CAAC4 003CAAC4 000082C4 */  lwc1       $f2, 0x0($4)
    /* 2CAAC8 003CAAC8 01180146 */  sub.s      $f0, $f3, $f1
    /* 2CAACC 003CAACC 0000C0E4 */  swc1       $f0, 0x0($6)
    /* 2CAAD0 003CAAD0 00180146 */  add.s      $f0, $f3, $f1
    /* 2CAAD4 003CAAD4 0000A0E4 */  swc1       $f0, 0x0($5)
    /* 2CAAD8 003CAAD8 01100146 */  sub.s      $f0, $f2, $f1
    /* 2CAADC 003CAADC 000080E4 */  swc1       $f0, 0x0($4)
    /* 2CAAE0 003CAAE0 00100146 */  add.s      $f0, $f2, $f1
    /* 2CAAE4 003CAAE4 000060E4 */  swc1       $f0, 0x0($3)
  .L003CAAE8:
    /* 2CAAE8 003CAAE8 0000438E */  lw         $3, 0x0($18)
    /* 2CAAEC 003CAAEC 20006004 */  bltz       $3, .L003CAB70
    /* 2CAAF0 003CAAF0 00000000 */   nop
    /* 2CAAF4 003CAAF4 21187D00 */  addu       $3, $3, $29
    /* 2CAAF8 003CAAF8 600161C4 */  lwc1       $f1, 0x160($3)
    /* 2CAAFC 003CAAFC 100040C6 */  lwc1       $f0, 0x10($18)
    /* 2CAB00 003CAB00 34080046 */  c.lt.s     $f1, $f0
    /* 2CAB04 003CAB04 0E000045 */  bc1f       .L003CAB40
    /* 2CAB08 003CAB08 2D204002 */   daddu     $4, $18, $0
    /* 2CAB0C 003CAB0C 0000838C */  lw         $3, 0x0($4)
    /* 2CAB10 003CAB10 140080C4 */  lwc1       $f0, 0x14($4)
    /* 2CAB14 003CAB14 21187D00 */  addu       $3, $3, $29
    /* 2CAB18 003CAB18 500161C4 */  lwc1       $f1, 0x150($3)
    /* 2CAB1C 003CAB1C 34000146 */  c.lt.s     $f0, $f1
    /* 2CAB20 003CAB20 0F000045 */  bc1f       .L003CAB60
    /* 2CAB24 003CAB24 0800528E */   lw        $18, 0x8($18)
    /* 2CAB28 003CAB28 0C00848C */  lw         $4, 0xC($4)
    /* 2CAB2C 003CAB2C 01003126 */  addiu      $17, $17, 0x1
    /* 2CAB30 003CAB30 80181100 */  sll        $3, $17, 2
    /* 2CAB34 003CAB34 21187D00 */  addu       $3, $3, $29
    /* 2CAB38 003CAB38 09000010 */  b          .L003CAB60
    /* 2CAB3C 003CAB3C 500064AC */   sw        $4, 0x50($3)
  .L003CAB40:
    /* 2CAB40 003CAB40 0000438E */  lw         $3, 0x0($18)
    /* 2CAB44 003CAB44 140040C6 */  lwc1       $f0, 0x14($18)
    /* 2CAB48 003CAB48 21187D00 */  addu       $3, $3, $29
    /* 2CAB4C 003CAB4C 500161C4 */  lwc1       $f1, 0x150($3)
    /* 2CAB50 003CAB50 34000146 */  c.lt.s     $f0, $f1
    /* 2CAB54 003CAB54 26000045 */  bc1f       .L003CABF0
    /* 2CAB58 003CAB58 00000000 */   nop
    /* 2CAB5C 003CAB5C 0C00528E */  lw         $18, 0xC($18)
  .L003CAB60:
    /* 2CAB60 003CAB60 E1FF2106 */  bgez       $17, .L003CAAE8
    /* 2CAB64 003CAB64 00000000 */   nop
    /* 2CAB68 003CAB68 27000010 */  b          .L003CAC08
    /* 2CAB6C 003CAB6C 00000000 */   nop
  .L003CAB70:
    /* 2CAB70 003CAB70 18B7868F */  lw         $6, -0x48E8($28)
    /* 2CAB74 003CAB74 8800043C */  lui        $4, %hi(D_008872E0)
    /* 2CAB78 003CAB78 0300033C */  lui        $3, (0x30507 >> 16)
    /* 2CAB7C 003CAB7C E0728424 */  addiu      $4, $4, %lo(D_008872E0)
    /* 2CAB80 003CAB80 07056534 */  ori        $5, $3, (0x30507 & 0xFFFF)
    /* 2CAB84 003CAB84 0000028E */  lw         $2, 0x0($16)
    /* 2CAB88 003CAB88 21188600 */  addu       $3, $4, $6
    /* 2CAB8C 003CAB8C 09F84000 */  jalr       $2
    /* 2CAB90 003CAB90 0000648C */   lw        $4, 0x0($3)
    /* 2CAB94 003CAB94 140052AC */  sw         $18, 0x14($2)
    /* 2CAB98 003CAB98 80181100 */  sll        $3, $17, 2
    /* 2CAB9C 003CAB9C 080053AC */  sw         $19, 0x8($2)
    /* 2CABA0 003CABA0 38004726 */  addiu      $7, $18, 0x38
    /* 2CABA4 003CABA4 3800468E */  lw         $6, 0x38($18)
    /* 2CABA8 003CABA8 21187D00 */  addu       $3, $3, $29
    /* 2CABAC 003CABAC 64006526 */  addiu      $5, $19, 0x64
    /* 2CABB0 003CABB0 0C004424 */  addiu      $4, $2, 0xC
    /* 2CABB4 003CABB4 FFFF3126 */  addiu      $17, $17, -0x1
    /* 2CABB8 003CABB8 000046AC */  sw         $6, 0x0($2)
    /* 2CABBC 003CABBC 040047AC */  sw         $7, 0x4($2)
    /* 2CABC0 003CABC0 3800468E */  lw         $6, 0x38($18)
    /* 2CABC4 003CABC4 0400C2AC */  sw         $2, 0x4($6)
    /* 2CABC8 003CABC8 380042AE */  sw         $2, 0x38($18)
    /* 2CABCC 003CABCC 5000728C */  lw         $18, 0x50($3)
    /* 2CABD0 003CABD0 6400638E */  lw         $3, 0x64($19)
    /* 2CABD4 003CABD4 0C0043AC */  sw         $3, 0xC($2)
    /* 2CABD8 003CABD8 100045AC */  sw         $5, 0x10($2)
    /* 2CABDC 003CABDC 6400638E */  lw         $3, 0x64($19)
    /* 2CABE0 003CABE0 040064AC */  sw         $4, 0x4($3)
    /* 2CABE4 003CABE4 DEFF0010 */  b          .L003CAB60
    /* 2CABE8 003CABE8 640064AE */   sw        $4, 0x64($19)
    /* 2CABEC 003CABEC 00000000 */  nop
  .L003CABF0:
    /* 2CABF0 003CABF0 80181100 */  sll        $3, $17, 2
    /* 2CABF4 003CABF4 21187D00 */  addu       $3, $3, $29
    /* 2CABF8 003CABF8 5000728C */  lw         $18, 0x50($3)
    /* 2CABFC 003CABFC D8FF0010 */  b          .L003CAB60
    /* 2CAC00 003CAC00 FFFF3126 */   addiu     $17, $17, -0x1
    /* 2CAC04 003CAC04 00000000 */  nop
  .L003CAC08:
    /* 2CAC08 003CAC08 4000BFDF */  ld         $31, 0x40($29)
    /* 2CAC0C 003CAC0C 3000B37B */  lq         $19, 0x30($29)
    /* 2CAC10 003CAC10 2000B27B */  lq         $18, 0x20($29)
    /* 2CAC14 003CAC14 1000B17B */  lq         $17, 0x10($29)
    /* 2CAC18 003CAC18 0000B07B */  lq         $16, 0x0($29)
    /* 2CAC1C 003CAC1C 0800E003 */  jr         $31
    /* 2CAC20 003CAC20 7001BD27 */   addiu     $29, $29, 0x170
    /* 2CAC24 003CAC24 00000000 */  nop
    /* 2CAC28 003CAC28 00000000 */  nop
    /* 2CAC2C 003CAC2C 00000000 */  nop
.size func_003caa50, 0x1e0
