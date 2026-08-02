.section .text
.set noat
.set noreorder
glabel func_004abd80
    /* 3ABD80 004ABD80 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3ABD84 004ABD84 1000BFFF */  sd         $31, 0x10($29)
    /* 3ABD88 004ABD88 0000B07F */  sq         $16, 0x0($29)
    /* 3ABD8C 004ABD8C 2D108000 */  daddu      $2, $4, $0
    /* 3ABD90 004ABD90 D4008494 */  lhu        $4, 0xD4($4)
    /* 3ABD94 004ABD94 D6004594 */  lhu        $5, 0xD6($2)
    /* 3ABD98 004ABD98 01000624 */  addiu      $6, $0, 0x1
    /* 3ABD9C 004ABD9C 50E0110C */  jal        func_00478140
    /* 3ABDA0 004ABDA0 00000000 */   nop
    /* 3ABDA4 004ABDA4 2D804000 */  daddu      $16, $2, $0
    /* 3ABDA8 004ABDA8 06000016 */  bnez       $16, .L004ABDC4
    /* 3ABDAC 004ABDAC 00000000 */   nop
    /* 3ABDB0 004ABDB0 7100043C */  lui        $4, %hi(D_007144A8)
    /* 3ABDB4 004ABDB4 A8448424 */  addiu      $4, $4, %lo(D_007144A8)
    /* 3ABDB8 004ABDB8 55000524 */  addiu      $5, $0, 0x55
    /* 3ABDBC 004ABDBC CCB5110C */  jal        func_0046d730
    /* 3ABDC0 004ABDC0 00000000 */   nop
  .L004ABDC4:
    /* 3ABDC4 004ABDC4 2D200002 */  daddu      $4, $16, $0
    /* 3ABDC8 004ABDC8 A8E8110C */  jal        func_0047a2a0
    /* 3ABDCC 004ABDCC 00000000 */   nop
    /* 3ABDD0 004ABDD0 2D200002 */  daddu      $4, $16, $0
    /* 3ABDD4 004ABDD4 2D280000 */  daddu      $5, $0, $0
    /* 3ABDD8 004ABDD8 28E7110C */  jal        func_00479ca0
    /* 3ABDDC 004ABDDC 00000000 */   nop
    /* 3ABDE0 004ABDE0 0E004010 */  beqz       $2, .L004ABE1C
    /* 3ABDE4 004ABDE4 00000000 */   nop
    /* 3ABDE8 004ABDE8 2D200002 */  daddu      $4, $16, $0
    /* 3ABDEC 004ABDEC 2D280000 */  daddu      $5, $0, $0
    /* 3ABDF0 004ABDF0 2D300000 */  daddu      $6, $0, $0
    /* 3ABDF4 004ABDF4 2D380000 */  daddu      $7, $0, $0
    /* 3ABDF8 004ABDF8 2D400000 */  daddu      $8, $0, $0
    /* 3ABDFC 004ABDFC 50E6110C */  jal        func_00479940
    /* 3ABE00 004ABE00 00000000 */   nop
    /* 3ABE04 004ABE04 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 3ABE08 004ABE08 00608244 */  mtc1       $2, $f12
    /* 3ABE0C 004ABE0C 2D200002 */  daddu      $4, $16, $0
    /* 3ABE10 004ABE10 2D280000 */  daddu      $5, $0, $0
    /* 3ABE14 004ABE14 38E8110C */  jal        func_0047a0e0
    /* 3ABE18 004ABE18 00000000 */   nop
  .L004ABE1C:
    /* 3ABE1C 004ABE1C D800038E */  lw         $3, 0xD8($16)
    /* 3ABE20 004ABE20 FDFF0224 */  addiu      $2, $0, -0x3
    /* 3ABE24 004ABE24 24106200 */  and        $2, $3, $2
    /* 3ABE28 004ABE28 D80002AE */  sw         $2, 0xD8($16)
    /* 3ABE2C 004ABE2C 2D200002 */  daddu      $4, $16, $0
    /* 3ABE30 004ABE30 4B00053C */  lui        $5, %hi(func_004abe60)
    /* 3ABE34 004ABE34 60BEA524 */  addiu      $5, $5, %lo(func_004abe60)
    /* 3ABE38 004ABE38 2D300002 */  daddu      $6, $16, $0
    /* 3ABE3C 004ABE3C ACE3110C */  jal        func_00478eb0
    /* 3ABE40 004ABE40 00000000 */   nop
    /* 3ABE44 004ABE44 2D100002 */  daddu      $2, $16, $0
    /* 3ABE48 004ABE48 1000BFDF */  ld         $31, 0x10($29)
    /* 3ABE4C 004ABE4C 0000B07B */  lq         $16, 0x0($29)
    /* 3ABE50 004ABE50 2000BD27 */  addiu      $29, $29, 0x20
    /* 3ABE54 004ABE54 0800E003 */  jr         $31
    /* 3ABE58 004ABE58 00000000 */   nop
    /* 3ABE5C 004ABE5C 00000000 */  nop
.size func_004abd80, 0xe0
