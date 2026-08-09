.section .text
.set noat
.set noreorder
glabel func_002bb9e0
    /* 1BB9E0 002BB9E0 B0FFBD27 */  addiu      $29, $29, -0x50
    /* 1BB9E4 002BB9E4 4000BFFF */  sd         $31, 0x40($29)
    /* 1BB9E8 002BB9E8 3000B37F */  sq         $19, 0x30($29)
    /* 1BB9EC 002BB9EC 2000B27F */  sq         $18, 0x20($29)
    /* 1BB9F0 002BB9F0 1000B17F */  sq         $17, 0x10($29)
    /* 1BB9F4 002BB9F4 0000B07F */  sq         $16, 0x0($29)
    /* 1BB9F8 002BB9F8 2D988000 */  daddu      $19, $4, $0
    /* 1BB9FC 002BB9FC 2D80A000 */  daddu      $16, $5, $0
    /* 1BBA00 002BBA00 3C961300 */  dsll32     $18, $19, 24
    /* 1BBA04 002BBA04 3F961200 */  dsra32     $18, $18, 24
    /* 1BBA08 002BBA08 80201200 */  sll        $4, $18, 2
    /* 1BBA0C 002BBA0C 8800033C */  lui        $3, %hi(D_00882F40)
    /* 1BBA10 002BBA10 402F6324 */  addiu      $3, $3, %lo(D_00882F40)
    /* 1BBA14 002BBA14 21886400 */  addu       $17, $3, $4
    /* 1BBA18 002BBA18 0000268E */  lw         $6, 0x0($17)
    /* 1BBA1C 002BBA1C 9F00C010 */  beqz       $6, .L002BBC9C
    /* 1BBA20 002BBA20 00000000 */   nop
    /* 1BBA24 002BBA24 0000C48C */  lw         $4, 0x0($6)
    /* 1BBA28 002BBA28 9C008004 */  bltz       $4, .L002BBC9C
    /* 1BBA2C 002BBA2C 00000000 */   nop
    /* 1BBA30 002BBA30 0400C580 */  lb         $5, 0x4($6)
    /* 1BBA34 002BBA34 03000324 */  addiu      $3, $0, 0x3
    /* 1BBA38 002BBA38 7A00A310 */  beq        $5, $3, .L002BBC24
    /* 1BBA3C 002BBA3C 00000000 */   nop
    /* 1BBA40 002BBA40 02000324 */  addiu      $3, $0, 0x2
    /* 1BBA44 002BBA44 1300A310 */  beq        $5, $3, .L002BBA94
    /* 1BBA48 002BBA48 00000000 */   nop
    /* 1BBA4C 002BBA4C 01000324 */  addiu      $3, $0, 0x1
    /* 1BBA50 002BBA50 0700A310 */  beq        $5, $3, .L002BBA70
    /* 1BBA54 002BBA54 00000000 */   nop
    /* 1BBA58 002BBA58 0300A010 */  beqz       $5, .L002BBA68
    /* 1BBA5C 002BBA5C 00000000 */   nop
    /* 1BBA60 002BBA60 8E000010 */  b          .L002BBC9C
    /* 1BBA64 002BBA64 00000000 */   nop
  .L002BBA68:
    /* 1BBA68 002BBA68 8C000010 */  b          .L002BBC9C
    /* 1BBA6C 002BBA6C 00000000 */   nop
  .L002BBA70:
    /* 1BBA70 002BBA70 84DB090C */  jal        func_00276e10
    /* 1BBA74 002BBA74 00000000 */   nop
    /* 1BBA78 002BBA78 88004104 */  bgez       $2, .L002BBC9C
    /* 1BBA7C 002BBA7C 00000000 */   nop
    /* 1BBA80 002BBA80 02000424 */  addiu      $4, $0, 0x2
    /* 1BBA84 002BBA84 0000238E */  lw         $3, 0x0($17)
    /* 1BBA88 002BBA88 040064A0 */  sb         $4, 0x4($3)
    /* 1BBA8C 002BBA8C 83000010 */  b          .L002BBC9C
    /* 1BBA90 002BBA90 00000000 */   nop
  .L002BBA94:
    /* 1BBA94 002BBA94 0800C38C */  lw         $3, 0x8($6)
    /* 1BBA98 002BBA98 1B006004 */  bltz       $3, .L002BBB08
    /* 1BBA9C 002BBA9C 00000000 */   nop
    /* 1BBAA0 002BBAA0 78B58283 */  lb         $2, -0x4A88($28)
    /* 1BBAA4 002BBAA4 01000624 */  addiu      $6, $0, 0x1
    /* 1BBAA8 002BBAA8 04004614 */  bne        $2, $6, .L002BBABC
    /* 1BBAAC 002BBAAC 00000000 */   nop
    /* 1BBAB0 002BBAB0 06000524 */  addiu      $5, $0, 0x6
    /* 1BBAB4 002BBAB4 B0E1090C */  jal        func_002786c0
    /* 1BBAB8 002BBAB8 00000000 */   nop
  .L002BBABC:
    /* 1BBABC 002BBABC 3C161300 */  dsll32     $2, $19, 24
    /* 1BBAC0 002BBAC0 3F160200 */  dsra32     $2, $2, 24
    /* 1BBAC4 002BBAC4 80180200 */  sll        $3, $2, 2
    /* 1BBAC8 002BBAC8 8800023C */  lui        $2, %hi(D_00882F40)
    /* 1BBACC 002BBACC 402F4224 */  addiu      $2, $2, %lo(D_00882F40)
    /* 1BBAD0 002BBAD0 21804300 */  addu       $16, $2, $3
    /* 1BBAD4 002BBAD4 0000028E */  lw         $2, 0x0($16)
    /* 1BBAD8 002BBAD8 0C004580 */  lb         $5, 0xC($2)
    /* 1BBADC 002BBADC 0000448C */  lw         $4, 0x0($2)
    /* 1BBAE0 002BBAE0 F4DF090C */  jal        func_00277fd0
    /* 1BBAE4 002BBAE4 00000000 */   nop
    /* 1BBAE8 002BBAE8 0000028E */  lw         $2, 0x0($16)
    /* 1BBAEC 002BBAEC 0000448C */  lw         $4, 0x0($2)
    /* 1BBAF0 002BBAF0 0800458C */  lw         $5, 0x8($2)
    /* 1BBAF4 002BBAF4 F8DE090C */  jal        func_00277be0
    /* 1BBAF8 002BBAF8 00000000 */   nop
    /* 1BBAFC 002BBAFC FFFF0424 */  addiu      $4, $0, -0x1
    /* 1BBB00 002BBB00 0000038E */  lw         $3, 0x0($16)
    /* 1BBB04 002BBB04 080064AC */  sw         $4, 0x8($3)
  .L002BBB08:
    /* 1BBB08 002BBB08 0000248E */  lw         $4, 0x0($17)
    /* 1BBB0C 002BBB0C 05008380 */  lb         $3, 0x5($4)
    /* 1BBB10 002BBB10 62006014 */  bnez       $3, .L002BBC9C
    /* 1BBB14 002BBB14 00000000 */   nop
    /* 1BBB18 002BBB18 04008014 */  bnez       $4, .L002BBB2C
    /* 1BBB1C 002BBB1C 00000000 */   nop
    /* 1BBB20 002BBB20 2D180000 */  daddu      $3, $0, $0
    /* 1BBB24 002BBB24 20000010 */  b          .L002BBBA8
    /* 1BBB28 002BBB28 00000000 */   nop
  .L002BBB2C:
    /* 1BBB2C 002BBB2C 0000848C */  lw         $4, 0x0($4)
    /* 1BBB30 002BBB30 04008104 */  bgez       $4, .L002BBB44
    /* 1BBB34 002BBB34 00000000 */   nop
    /* 1BBB38 002BBB38 2D180000 */  daddu      $3, $0, $0
    /* 1BBB3C 002BBB3C 1A000010 */  b          .L002BBBA8
    /* 1BBB40 002BBB40 00000000 */   nop
  .L002BBB44:
    /* 1BBB44 002BBB44 ECDB090C */  jal        func_00276fb0
    /* 1BBB48 002BBB48 00000000 */   nop
    /* 1BBB4C 002BBB4C 04004104 */  bgez       $2, .L002BBB60
    /* 1BBB50 002BBB50 00000000 */   nop
    /* 1BBB54 002BBB54 2D180000 */  daddu      $3, $0, $0
    /* 1BBB58 002BBB58 13000010 */  b          .L002BBBA8
    /* 1BBB5C 002BBB5C 00000000 */   nop
  .L002BBB60:
    /* 1BBB60 002BBB60 0000238E */  lw         $3, 0x0($17)
    /* 1BBB64 002BBB64 04006014 */  bnez       $3, .L002BBB78
    /* 1BBB68 002BBB68 00000000 */   nop
    /* 1BBB6C 002BBB6C FFFF0424 */  addiu      $4, $0, -0x1
    /* 1BBB70 002BBB70 0A000010 */  b          .L002BBB9C
    /* 1BBB74 002BBB74 00000000 */   nop
  .L002BBB78:
    /* 1BBB78 002BBB78 0000648C */  lw         $4, 0x0($3)
    /* 1BBB7C 002BBB7C 04008104 */  bgez       $4, .L002BBB90
    /* 1BBB80 002BBB80 00000000 */   nop
    /* 1BBB84 002BBB84 FFFF0424 */  addiu      $4, $0, -0x1
    /* 1BBB88 002BBB88 04000010 */  b          .L002BBB9C
    /* 1BBB8C 002BBB8C 00000000 */   nop
  .L002BBB90:
    /* 1BBB90 002BBB90 1CDC090C */  jal        func_00277070
    /* 1BBB94 002BBB94 00000000 */   nop
    /* 1BBB98 002BBB98 2D204000 */  daddu      $4, $2, $0
  .L002BBB9C:
    /* 1BBB9C 002BBB9C 0000238E */  lw         $3, 0x0($17)
    /* 1BBBA0 002BBBA0 0D0064A0 */  sb         $4, 0xD($3)
    /* 1BBBA4 002BBBA4 01000324 */  addiu      $3, $0, 0x1
  .L002BBBA8:
    /* 1BBBA8 002BBBA8 3C006014 */  bnez       $3, .L002BBC9C
    /* 1BBBAC 002BBBAC 00000000 */   nop
    /* 1BBBB0 002BBBB0 3C1E1300 */  dsll32     $3, $19, 24
    /* 1BBBB4 002BBBB4 3F1E0300 */  dsra32     $3, $3, 24
    /* 1BBBB8 002BBBB8 80200300 */  sll        $4, $3, 2
    /* 1BBBBC 002BBBBC 8800033C */  lui        $3, %hi(D_00882F40)
    /* 1BBBC0 002BBBC0 402F6324 */  addiu      $3, $3, %lo(D_00882F40)
    /* 1BBBC4 002BBBC4 21286400 */  addu       $5, $3, $4
    /* 1BBBC8 002BBBC8 03000424 */  addiu      $4, $0, 0x3
    /* 1BBBCC 002BBBCC 0000A38C */  lw         $3, 0x0($5)
    /* 1BBBD0 002BBBD0 040064A0 */  sb         $4, 0x4($3)
    /* 1BBBD4 002BBBD4 0000A38C */  lw         $3, 0x0($5)
    /* 1BBBD8 002BBBD8 04006014 */  bnez       $3, .L002BBBEC
    /* 1BBBDC 002BBBDC 00000000 */   nop
    /* 1BBBE0 002BBBE0 FFFF0424 */  addiu      $4, $0, -0x1
    /* 1BBBE4 002BBBE4 0A000010 */  b          .L002BBC10
    /* 1BBBE8 002BBBE8 00000000 */   nop
  .L002BBBEC:
    /* 1BBBEC 002BBBEC 0000648C */  lw         $4, 0x0($3)
    /* 1BBBF0 002BBBF0 04008104 */  bgez       $4, .L002BBC04
    /* 1BBBF4 002BBBF4 00000000 */   nop
    /* 1BBBF8 002BBBF8 FFFF0424 */  addiu      $4, $0, -0x1
    /* 1BBBFC 002BBBFC 04000010 */  b          .L002BBC10
    /* 1BBC00 002BBC00 00000000 */   nop
  .L002BBC04:
    /* 1BBC04 002BBC04 1CDC090C */  jal        func_00277070
    /* 1BBC08 002BBC08 00000000 */   nop
    /* 1BBC0C 002BBC0C 2D204000 */  daddu      $4, $2, $0
  .L002BBC10:
    /* 1BBC10 002BBC10 80B58327 */  addiu      $3, $28, -0x4A80
    /* 1BBC14 002BBC14 21187200 */  addu       $3, $3, $18
    /* 1BBC18 002BBC18 000064A0 */  sb         $4, 0x0($3)
    /* 1BBC1C 002BBC1C 1F000010 */  b          .L002BBC9C
    /* 1BBC20 002BBC20 00000000 */   nop
  .L002BBC24:
    /* 1BBC24 002BBC24 1D00C010 */  beqz       $6, .L002BBC9C
    /* 1BBC28 002BBC28 00000000 */   nop
    /* 1BBC2C 002BBC2C 1B008004 */  bltz       $4, .L002BBC9C
    /* 1BBC30 002BBC30 00000000 */   nop
    /* 1BBC34 002BBC34 2D280000 */  daddu      $5, $0, $0
    /* 1BBC38 002BBC38 9CDB090C */  jal        func_00276e70
    /* 1BBC3C 002BBC3C 00000000 */   nop
    /* 1BBC40 002BBC40 05000012 */  beqz       $16, .L002BBC58
    /* 1BBC44 002BBC44 00000000 */   nop
    /* 1BBC48 002BBC48 0000228E */  lw         $2, 0x0($17)
    /* 1BBC4C 002BBC4C 0000448C */  lw         $4, 0x0($2)
    /* 1BBC50 002BBC50 94DC090C */  jal        func_00277250
    /* 1BBC54 002BBC54 00000000 */   nop
  .L002BBC58:
    /* 1BBC58 002BBC58 3C161300 */  dsll32     $2, $19, 24
    /* 1BBC5C 002BBC5C 3F160200 */  dsra32     $2, $2, 24
    /* 1BBC60 002BBC60 80180200 */  sll        $3, $2, 2
    /* 1BBC64 002BBC64 8800023C */  lui        $2, %hi(D_00882F40)
    /* 1BBC68 002BBC68 402F4224 */  addiu      $2, $2, %lo(D_00882F40)
    /* 1BBC6C 002BBC6C 21804300 */  addu       $16, $2, $3
    /* 1BBC70 002BBC70 0000028E */  lw         $2, 0x0($16)
    /* 1BBC74 002BBC74 0000448C */  lw         $4, 0x0($2)
    /* 1BBC78 002BBC78 2D280000 */  daddu      $5, $0, $0
    /* 1BBC7C 002BBC7C B4DE090C */  jal        func_00277ad0
    /* 1BBC80 002BBC80 00000000 */   nop
    /* 1BBC84 002BBC84 2D206002 */  daddu      $4, $19, $0
    /* 1BBC88 002BBC88 01000524 */  addiu      $5, $0, 0x1
    /* 1BBC8C 002BBC8C A4EF0A0C */  jal        func_002bbe90
    /* 1BBC90 002BBC90 00000000 */   nop
    /* 1BBC94 002BBC94 0000038E */  lw         $3, 0x0($16)
    /* 1BBC98 002BBC98 040060A0 */  sb         $0, 0x4($3)
  .L002BBC9C:
    /* 1BBC9C 002BBC9C 4000BFDF */  ld         $31, 0x40($29)
    /* 1BBCA0 002BBCA0 3000B37B */  lq         $19, 0x30($29)
    /* 1BBCA4 002BBCA4 2000B27B */  lq         $18, 0x20($29)
    /* 1BBCA8 002BBCA8 1000B17B */  lq         $17, 0x10($29)
    /* 1BBCAC 002BBCAC 0000B07B */  lq         $16, 0x0($29)
    /* 1BBCB0 002BBCB0 5000BD27 */  addiu      $29, $29, 0x50
    /* 1BBCB4 002BBCB4 0800E003 */  jr         $31
    /* 1BBCB8 002BBCB8 00000000 */   nop
    /* 1BBCBC 002BBCBC 00000000 */  nop
.size func_002bb9e0, 0x2e0
