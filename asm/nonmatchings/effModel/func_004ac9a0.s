.section .text
.set noat
.set noreorder
glabel func_004ac9a0
    /* 3AC9A0 004AC9A0 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 3AC9A4 004AC9A4 2000BFFF */  sd         $31, 0x20($29)
    /* 3AC9A8 004AC9A8 1000B17F */  sq         $17, 0x10($29)
    /* 3AC9AC 004AC9AC 0000B07F */  sq         $16, 0x0($29)
    /* 3AC9B0 004AC9B0 2D808000 */  daddu      $16, $4, $0
    /* 3AC9B4 004AC9B4 2D88A000 */  daddu      $17, $5, $0
    /* 3AC9B8 004AC9B8 B400A28C */  lw         $2, 0xB4($5)
    /* 3AC9BC 004AC9BC 06004014 */  bnez       $2, .L004AC9D8
    /* 3AC9C0 004AC9C0 00000000 */   nop
    /* 3AC9C4 004AC9C4 7100043C */  lui        $4, %hi(D_007144A8)
    /* 3AC9C8 004AC9C8 A8448424 */  addiu      $4, $4, %lo(D_007144A8)
    /* 3AC9CC 004AC9CC D0010524 */  addiu      $5, $0, 0x1D0
    /* 3AC9D0 004AC9D0 CCB5110C */  jal        func_0046d730
    /* 3AC9D4 004AC9D4 00000000 */   nop
  .L004AC9D8:
    /* 3AC9D8 004AC9D8 B400048E */  lw         $4, 0xB4($16)
    /* 3AC9DC 004AC9DC 03008010 */  beqz       $4, .L004AC9EC
    /* 3AC9E0 004AC9E0 00000000 */   nop
    /* 3AC9E4 004AC9E4 F8E1110C */  jal        func_004787e0
    /* 3AC9E8 004AC9E8 00000000 */   nop
  .L004AC9EC:
    /* 3AC9EC 004AC9EC B400228E */  lw         $2, 0xB4($17)
    /* 3AC9F0 004AC9F0 D4004494 */  lhu        $4, 0xD4($2)
    /* 3AC9F4 004AC9F4 D6004594 */  lhu        $5, 0xD6($2)
    /* 3AC9F8 004AC9F8 2D300000 */  daddu      $6, $0, $0
    /* 3AC9FC 004AC9FC 50E0110C */  jal        func_00478140
    /* 3ACA00 004ACA00 00000000 */   nop
    /* 3ACA04 004ACA04 2D884000 */  daddu      $17, $2, $0
    /* 3ACA08 004ACA08 06002016 */  bnez       $17, .L004ACA24
    /* 3ACA0C 004ACA0C 00000000 */   nop
    /* 3ACA10 004ACA10 7100043C */  lui        $4, %hi(D_007144A8)
    /* 3ACA14 004ACA14 A8448424 */  addiu      $4, $4, %lo(D_007144A8)
    /* 3ACA18 004ACA18 DA010524 */  addiu      $5, $0, 0x1DA
    /* 3ACA1C 004ACA1C CCB5110C */  jal        func_0046d730
    /* 3ACA20 004ACA20 00000000 */   nop
  .L004ACA24:
    /* 3ACA24 004ACA24 2D202002 */  daddu      $4, $17, $0
    /* 3ACA28 004ACA28 A8E8110C */  jal        func_0047a2a0
    /* 3ACA2C 004ACA2C 00000000 */   nop
    /* 3ACA30 004ACA30 2D202002 */  daddu      $4, $17, $0
    /* 3ACA34 004ACA34 2D280000 */  daddu      $5, $0, $0
    /* 3ACA38 004ACA38 28E7110C */  jal        func_00479ca0
    /* 3ACA3C 004ACA3C 00000000 */   nop
    /* 3ACA40 004ACA40 0E004010 */  beqz       $2, .L004ACA7C
    /* 3ACA44 004ACA44 00000000 */   nop
    /* 3ACA48 004ACA48 2D202002 */  daddu      $4, $17, $0
    /* 3ACA4C 004ACA4C 2D280000 */  daddu      $5, $0, $0
    /* 3ACA50 004ACA50 2D300000 */  daddu      $6, $0, $0
    /* 3ACA54 004ACA54 2D380000 */  daddu      $7, $0, $0
    /* 3ACA58 004ACA58 2D400000 */  daddu      $8, $0, $0
    /* 3ACA5C 004ACA5C 50E6110C */  jal        func_00479940
    /* 3ACA60 004ACA60 00000000 */   nop
    /* 3ACA64 004ACA64 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 3ACA68 004ACA68 00608244 */  mtc1       $2, $f12
    /* 3ACA6C 004ACA6C 2D202002 */  daddu      $4, $17, $0
    /* 3ACA70 004ACA70 2D280000 */  daddu      $5, $0, $0
    /* 3ACA74 004ACA74 38E8110C */  jal        func_0047a0e0
    /* 3ACA78 004ACA78 00000000 */   nop
  .L004ACA7C:
    /* 3ACA7C 004ACA7C D800238E */  lw         $3, 0xD8($17)
    /* 3ACA80 004ACA80 FDFF0224 */  addiu      $2, $0, -0x3
    /* 3ACA84 004ACA84 24106200 */  and        $2, $3, $2
    /* 3ACA88 004ACA88 D80022AE */  sw         $2, 0xD8($17)
    /* 3ACA8C 004ACA8C 2D202002 */  daddu      $4, $17, $0
    /* 3ACA90 004ACA90 4B00053C */  lui        $5, %hi(func_004abe60)
    /* 3ACA94 004ACA94 60BEA524 */  addiu      $5, $5, %lo(func_004abe60)
    /* 3ACA98 004ACA98 2D302002 */  daddu      $6, $17, $0
    /* 3ACA9C 004ACA9C ACE3110C */  jal        func_00478eb0
    /* 3ACAA0 004ACAA0 00000000 */   nop
    /* 3ACAA4 004ACAA4 B40011AE */  sw         $17, 0xB4($16)
    /* 3ACAA8 004ACAA8 2D202002 */  daddu      $4, $17, $0
    /* 3ACAAC 004ACAAC 4B00053C */  lui        $5, %hi(func_004accc0)
    /* 3ACAB0 004ACAB0 C0CCA524 */  addiu      $5, $5, %lo(func_004accc0)
    /* 3ACAB4 004ACAB4 2D300002 */  daddu      $6, $16, $0
    /* 3ACAB8 004ACAB8 A8E3110C */  jal        func_00478ea0
    /* 3ACABC 004ACABC 00000000 */   nop
    /* 3ACAC0 004ACAC0 A0000392 */  lbu        $3, 0xA0($16)
    /* 3ACAC4 004ACAC4 05006014 */  bnez       $3, .L004ACADC
    /* 3ACAC8 004ACAC8 00000000 */   nop
    /* 3ACACC 004ACACC B400048E */  lw         $4, 0xB4($16)
    /* 3ACAD0 004ACAD0 20000524 */  addiu      $5, $0, 0x20
    /* 3ACAD4 004ACAD4 34E9110C */  jal        func_0047a4d0
    /* 3ACAD8 004ACAD8 00000000 */   nop
  .L004ACADC:
    /* 3ACADC 004ACADC A400038E */  lw         $3, 0xA4($16)
    /* 3ACAE0 004ACAE0 06006010 */  beqz       $3, .L004ACAFC
    /* 3ACAE4 004ACAE4 00000000 */   nop
    /* 3ACAE8 004ACAE8 B400058E */  lw         $5, 0xB4($16)
    /* 3ACAEC 004ACAEC D800A48C */  lw         $4, 0xD8($5)
    /* 3ACAF0 004ACAF0 0400033C */  lui        $3, (0x40000 >> 16)
    /* 3ACAF4 004ACAF4 25188300 */  or         $3, $4, $3
    /* 3ACAF8 004ACAF8 D800A3AC */  sw         $3, 0xD8($5)
  .L004ACAFC:
    /* 3ACAFC 004ACAFC 7000048E */  lw         $4, 0x70($16)
    /* 3ACB00 004ACB00 0B008004 */  bltz       $4, .L004ACB30
    /* 3ACB04 004ACB04 00000000 */   nop
    /* 3ACB08 004ACB08 7400038E */  lw         $3, 0x74($16)
    /* 3ACB0C 004ACB0C 08006004 */  bltz       $3, .L004ACB30
    /* 3ACB10 004ACB10 00000000 */   nop
    /* 3ACB14 004ACB14 2A186400 */  slt        $3, $3, $4
    /* 3ACB18 004ACB18 05006014 */  bnez       $3, .L004ACB30
    /* 3ACB1C 004ACB1C 00000000 */   nop
    /* 3ACB20 004ACB20 01000324 */  addiu      $3, $0, 0x1
    /* 3ACB24 004ACB24 B80003A2 */  sb         $3, 0xB8($16)
    /* 3ACB28 004ACB28 02000010 */  b          .L004ACB34
    /* 3ACB2C 004ACB2C 00000000 */   nop
  .L004ACB30:
    /* 3ACB30 004ACB30 B80000A2 */  sb         $0, 0xB8($16)
  .L004ACB34:
    /* 3ACB34 004ACB34 2000BFDF */  ld         $31, 0x20($29)
    /* 3ACB38 004ACB38 1000B17B */  lq         $17, 0x10($29)
    /* 3ACB3C 004ACB3C 0000B07B */  lq         $16, 0x0($29)
    /* 3ACB40 004ACB40 3000BD27 */  addiu      $29, $29, 0x30
    /* 3ACB44 004ACB44 0800E003 */  jr         $31
    /* 3ACB48 004ACB48 00000000 */   nop
    /* 3ACB4C 004ACB4C 00000000 */  nop
.size func_004ac9a0, 0x1b0
