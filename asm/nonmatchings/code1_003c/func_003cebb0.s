.section .text
.set noat
.set noreorder
glabel func_003cebb0
    /* 2CEBB0 003CEBB0 40FFBD27 */  addiu      $29, $29, -0xC0
    /* 2CEBB4 003CEBB4 9000BFFF */  sd         $31, 0x90($29)
    /* 2CEBB8 003CEBB8 8000BE7F */  sq         $30, 0x80($29)
    /* 2CEBBC 003CEBBC 7000B77F */  sq         $23, 0x70($29)
    /* 2CEBC0 003CEBC0 6000B67F */  sq         $22, 0x60($29)
    /* 2CEBC4 003CEBC4 5000B57F */  sq         $21, 0x50($29)
    /* 2CEBC8 003CEBC8 2DB0A000 */  daddu      $22, $5, $0
    /* 2CEBCC 003CEBCC 4000B47F */  sq         $20, 0x40($29)
    /* 2CEBD0 003CEBD0 3000B37F */  sq         $19, 0x30($29)
    /* 2CEBD4 003CEBD4 2000B27F */  sq         $18, 0x20($29)
    /* 2CEBD8 003CEBD8 1000B17F */  sq         $17, 0x10($29)
    /* 2CEBDC 003CEBDC 0000B07F */  sq         $16, 0x0($29)
    /* 2CEBE0 003CEBE0 2D808000 */  daddu      $16, $4, $0
    /* 2CEBE4 003CEBE4 08270F0C */  jal        func_003c9c20
    /* 2CEBE8 003CEBE8 2D20C002 */   daddu     $4, $22, $0
    /* 2CEBEC 003CEBEC 2D200002 */  daddu      $4, $16, $0
    /* 2CEBF0 003CEBF0 01000524 */  addiu      $5, $0, 0x1
    /* 2CEBF4 003CEBF4 2D300000 */  daddu      $6, $0, $0
    /* 2CEBF8 003CEBF8 147C0F0C */  jal        func_003df050
    /* 2CEBFC 003CEBFC BC00A727 */   addiu     $7, $29, 0xBC
    /* 2CEC00 003CEC00 16004010 */  beqz       $2, .L003CEC5C
    /* 2CEC04 003CEC04 00000000 */   nop
    /* 2CEC08 003CEC08 BC00A38F */  lw         $3, 0xBC($29)
    /* 2CEC0C 003CEC0C 0300023C */  lui        $2, (0x35000 >> 16)
    /* 2CEC10 003CEC10 00504234 */  ori        $2, $2, (0x35000 & 0xFFFF)
    /* 2CEC14 003CEC14 2B106200 */  sltu       $2, $3, $2
    /* 2CEC18 003CEC18 06004014 */  bnez       $2, .L003CEC34
    /* 2CEC1C 003CEC1C 00000000 */   nop
    /* 2CEC20 003CEC20 0300013C */  lui        $1, (0x37003 >> 16)
    /* 2CEC24 003CEC24 03702134 */  ori        $1, $1, (0x37003 & 0xFFFF)
    /* 2CEC28 003CEC28 2B086100 */  sltu       $1, $3, $1
    /* 2CEC2C 003CEC2C 0D002014 */  bnez       $1, .L003CEC64
    /* 2CEC30 003CEC30 00000000 */   nop
  .L003CEC34:
    /* 2CEC34 003CEC34 02000324 */  addiu      $3, $0, 0x2
    /* 2CEC38 003CEC38 0080023C */  lui        $2, (0x80000004 >> 16)
    /* 2CEC3C 003CEC3C A800A3AF */  sw         $3, 0xA8($29)
    /* 2CEC40 003CEC40 647D0F0C */  jal        func_003df590
    /* 2CEC44 003CEC44 04004434 */   ori       $4, $2, (0x80000004 & 0xFFFF)
    /* 2CEC48 003CEC48 AC00A2AF */  sw         $2, 0xAC($29)
    /* 2CEC4C 003CEC4C 347D0F0C */  jal        func_003df4d0
    /* 2CEC50 003CEC50 A800A427 */   addiu     $4, $29, 0xA8
    /* 2CEC54 003CEC54 87000010 */  b          .L003CEE74
    /* 2CEC58 003CEC58 2D100000 */   daddu     $2, $0, $0
  .L003CEC5C:
    /* 2CEC5C 003CEC5C 85000010 */  b          .L003CEE74
    /* 2CEC60 003CEC60 2D100000 */   daddu     $2, $0, $0
  .L003CEC64:
    /* 2CEC64 003CEC64 2D200002 */  daddu      $4, $16, $0
    /* 2CEC68 003CEC68 B800A527 */  addiu      $5, $29, 0xB8
    /* 2CEC6C 003CEC6C 448A0F0C */  jal        func_003e2910
    /* 2CEC70 003CEC70 04000624 */   addiu     $6, $0, 0x4
    /* 2CEC74 003CEC74 04000324 */  addiu      $3, $0, 0x4
    /* 2CEC78 003CEC78 1E004314 */  bne        $2, $3, .L003CECF4
    /* 2CEC7C 003CEC7C 00000000 */   nop
    /* 2CEC80 003CEC80 B800A28F */  lw         $2, 0xB8($29)
    /* 2CEC84 003CEC84 1D004314 */  bne        $2, $3, .L003CECFC
    /* 2CEC88 003CEC88 00000000 */   nop
    /* 2CEC8C 003CEC8C 28B7828F */  lw         $2, -0x48D8($28)
    /* 2CEC90 003CEC90 2120C202 */  addu       $4, $22, $2
    /* 2CEC94 003CEC94 0000828C */  lw         $2, 0x0($4)
    /* 2CEC98 003CEC98 07004010 */  beqz       $2, .L003CECB8
    /* 2CEC9C 003CEC9C 2D280000 */   daddu     $5, $0, $0
    /* 2CECA0 003CECA0 7800C38E */  lw         $3, 0x78($22)
    /* 2CECA4 003CECA4 0000428C */  lw         $2, 0x0($2)
    /* 2CECA8 003CECA8 04006394 */  lhu        $3, 0x4($3)
    /* 2CECAC 003CECAC 02006214 */  bne        $3, $2, .L003CECB8
    /* 2CECB0 003CECB0 00000000 */   nop
    /* 2CECB4 003CECB4 01000524 */  addiu      $5, $0, 0x1
  .L003CECB8:
    /* 2CECB8 003CECB8 0300A010 */  beqz       $5, .L003CECC8
    /* 2CECBC 003CECBC 00000000 */   nop
    /* 2CECC0 003CECC0 06000010 */  b          .L003CECDC
    /* 2CECC4 003CECC4 0000928C */   lw        $18, 0x0($4)
  .L003CECC8:
    /* 2CECC8 003CECC8 7800C28E */  lw         $2, 0x78($22)
    /* 2CECCC 003CECCC 14380F0C */  jal        func_003ce050
    /* 2CECD0 003CECD0 04004594 */   lhu       $5, 0x4($2)
    /* 2CECD4 003CECD4 2D204000 */  daddu      $4, $2, $0
    /* 2CECD8 003CECD8 0000928C */  lw         $18, 0x0($4)
  .L003CECDC:
    /* 2CECDC 003CECDC 0000578E */  lw         $23, 0x0($18)
    /* 2CECE0 003CECE0 2A101700 */  slt        $2, $0, $23
    /* 2CECE4 003CECE4 07004014 */  bnez       $2, .L003CED04
    /* 2CECE8 003CECE8 2DA80000 */   daddu     $21, $0, $0
  .L003CECEC:
    /* 2CECEC 003CECEC 61000010 */  b          .L003CEE74
    /* 2CECF0 003CECF0 2D10C002 */   daddu     $2, $22, $0
  .L003CECF4:
    /* 2CECF4 003CECF4 5F000010 */  b          .L003CEE74
    /* 2CECF8 003CECF8 2D100000 */   daddu     $2, $0, $0
  .L003CECFC:
    /* 2CECFC 003CECFC 5D000010 */  b          .L003CEE74
    /* 2CED00 003CED00 2D100000 */   daddu     $2, $0, $0
  .L003CED04:
    /* 2CED04 003CED04 88001E3C */  lui        $30, %hi(jtbl_008873E8)
    /* 2CED08 003CED08 E873DE27 */  addiu      $30, $30, %lo(jtbl_008873E8)
  .L003CED0C:
    /* 2CED0C 003CED0C 2D200002 */  daddu      $4, $16, $0
    /* 2CED10 003CED10 B400A527 */  addiu      $5, $29, 0xB4
    /* 2CED14 003CED14 448A0F0C */  jal        func_003e2910
    /* 2CED18 003CED18 04000624 */   addiu     $6, $0, 0x4
    /* 2CED1C 003CED1C 04000324 */  addiu      $3, $0, 0x4
    /* 2CED20 003CED20 03004310 */  beq        $2, $3, .L003CED30
    /* 2CED24 003CED24 00000000 */   nop
    /* 2CED28 003CED28 52000010 */  b          .L003CEE74
    /* 2CED2C 003CED2C 2D100000 */   daddu     $2, $0, $0
  .L003CED30:
    /* 2CED30 003CED30 B400A48F */  lw         $4, 0xB4($29)
    /* 2CED34 003CED34 0300033C */  lui        $3, (0x3050D >> 16)
    /* 2CED38 003CED38 0000C28F */  lw         $2, 0x0($30)
    /* 2CED3C 003CED3C 0D056534 */  ori        $5, $3, (0x3050D & 0xFFFF)
    /* 2CED40 003CED40 04005426 */  addiu      $20, $18, 0x4
    /* 2CED44 003CED44 09F84000 */  jalr       $2
    /* 2CED48 003CED48 47028424 */   addiu     $4, $4, 0x247
    /* 2CED4C 003CED4C 000082AE */  sw         $2, 0x0($20)
    /* 2CED50 003CED50 0000828E */  lw         $2, 0x0($20)
    /* 2CED54 003CED54 3C004010 */  beqz       $2, .L003CEE48
    /* 2CED58 003CED58 00000000 */   nop
    /* 2CED5C 003CED5C 000040AC */  sw         $0, 0x0($2)
    /* 2CED60 003CED60 3D00033C */  lui        $3, %hi(func_003cc6e0)
    /* 2CED64 003CED64 0000828E */  lw         $2, 0x0($20)
    /* 2CED68 003CED68 E0C66324 */  addiu      $3, $3, %lo(func_003cc6e0)
    /* 2CED6C 003CED6C 2D200002 */  daddu      $4, $16, $0
    /* 2CED70 003CED70 B000A527 */  addiu      $5, $29, 0xB0
    /* 2CED74 003CED74 04000624 */  addiu      $6, $0, 0x4
    /* 2CED78 003CED78 040040AC */  sw         $0, 0x4($2)
    /* 2CED7C 003CED7C 0000828E */  lw         $2, 0x0($20)
    /* 2CED80 003CED80 0C0056AC */  sw         $22, 0xC($2)
    /* 2CED84 003CED84 B400A78F */  lw         $7, 0xB4($29)
    /* 2CED88 003CED88 0000828E */  lw         $2, 0x0($20)
    /* 2CED8C 003CED8C 2F02E724 */  addiu      $7, $7, 0x22F
    /* 2CED90 003CED90 080047AC */  sw         $7, 0x8($2)
    /* 2CED94 003CED94 0000828E */  lw         $2, 0x0($20)
    /* 2CED98 003CED98 100054AC */  sw         $20, 0x10($2)
    /* 2CED9C 003CED9C 0000828E */  lw         $2, 0x0($20)
    /* 2CEDA0 003CEDA0 140043AC */  sw         $3, 0x14($2)
    /* 2CEDA4 003CEDA4 0000828E */  lw         $2, 0x0($20)
    /* 2CEDA8 003CEDA8 448A0F0C */  jal        func_003e2910
    /* 2CEDAC 003CEDAC 18005324 */   addiu     $19, $2, 0x18
    /* 2CEDB0 003CEDB0 04000324 */  addiu      $3, $0, 0x4
    /* 2CEDB4 003CEDB4 26004314 */  bne        $2, $3, .L003CEE50
    /* 2CEDB8 003CEDB8 00000000 */   nop
    /* 2CEDBC 003CEDBC 000060AE */  sw         $0, 0x0($19)
    /* 2CEDC0 003CEDC0 2D206002 */  daddu      $4, $19, $0
    /* 2CEDC4 003CEDC4 2D280000 */  daddu      $5, $0, $0
    /* 2CEDC8 003CEDC8 B0010624 */  addiu      $6, $0, 0x1B0
    /* 2CEDCC 003CEDCC 72FE100C */  jal        func_0043f9c8
    /* 2CEDD0 003CEDD0 040060AE */   sw        $0, 0x4($19)
    /* 2CEDD4 003CEDD4 B0016326 */  addiu      $3, $19, 0x1B0
    /* 2CEDD8 003CEDD8 C0FF0224 */  addiu      $2, $0, -0x40
    /* 2CEDDC 003CEDDC 3F006324 */  addiu      $3, $3, 0x3F
    /* 2CEDE0 003CEDE0 24106200 */  and        $2, $3, $2
    /* 2CEDE4 003CEDE4 080062AE */  sw         $2, 0x8($19)
    /* 2CEDE8 003CEDE8 B000A28F */  lw         $2, 0xB0($29)
    /* 2CEDEC 003CEDEC 1A004014 */  bnez       $2, .L003CEE58
    /* 2CEDF0 003CEDF0 00000000 */   nop
    /* 2CEDF4 003CEDF4 00000000 */  nop
  .L003CEDF8:
    /* 2CEDF8 003CEDF8 B400B18F */  lw         $17, 0xB4($29)
    /* 2CEDFC 003CEDFC 0800658E */  lw         $5, 0x8($19)
    /* 2CEE00 003CEE00 2D200002 */  daddu      $4, $16, $0
    /* 2CEE04 003CEE04 448A0F0C */  jal        func_003e2910
    /* 2CEE08 003CEE08 2D302002 */   daddu     $6, $17, $0
    /* 2CEE0C 003CEE0C 18002216 */  bne        $17, $2, .L003CEE70
    /* 2CEE10 003CEE10 00000000 */   nop
    /* 2CEE14 003CEE14 8C380F0C */  jal        func_003ce230
    /* 2CEE18 003CEE18 2D206002 */   daddu     $4, $19, $0
    /* 2CEE1C 003CEE1C 0000848E */  lw         $4, 0x0($20)
    /* 2CEE20 003CEE20 0800828C */  lw         $2, 0x8($4)
    /* 2CEE24 003CEE24 21108200 */  addu       $2, $4, $2
    /* 2CEE28 003CEE28 3688100C */  jal        func_004220d8
    /* 2CEE2C 003CEE2C 18004524 */   addiu     $5, $2, 0x18
    /* 2CEE30 003CEE30 0100B526 */  addiu      $21, $21, 0x1
    /* 2CEE34 003CEE34 2A10B702 */  slt        $2, $21, $23
    /* 2CEE38 003CEE38 B4FF4014 */  bnez       $2, .L003CED0C
    /* 2CEE3C 003CEE3C 04005226 */   addiu     $18, $18, 0x4
    /* 2CEE40 003CEE40 AAFF0010 */  b          .L003CECEC
    /* 2CEE44 003CEE44 00000000 */   nop
  .L003CEE48:
    /* 2CEE48 003CEE48 0A000010 */  b          .L003CEE74
    /* 2CEE4C 003CEE4C 2D100000 */   daddu     $2, $0, $0
  .L003CEE50:
    /* 2CEE50 003CEE50 08000010 */  b          .L003CEE74
    /* 2CEE54 003CEE54 2D100000 */   daddu     $2, $0, $0
  .L003CEE58:
    /* 2CEE58 003CEE58 0800638E */  lw         $3, 0x8($19)
    /* 2CEE5C 003CEE5C 80FF0224 */  addiu      $2, $0, -0x80
    /* 2CEE60 003CEE60 7F006324 */  addiu      $3, $3, 0x7F
    /* 2CEE64 003CEE64 24106200 */  and        $2, $3, $2
    /* 2CEE68 003CEE68 E3FF0010 */  b          .L003CEDF8
    /* 2CEE6C 003CEE6C 080062AE */   sw        $2, 0x8($19)
  .L003CEE70:
    /* 2CEE70 003CEE70 2D100000 */  daddu      $2, $0, $0
  .L003CEE74:
    /* 2CEE74 003CEE74 9000BFDF */  ld         $31, 0x90($29)
    /* 2CEE78 003CEE78 8000BE7B */  lq         $30, 0x80($29)
    /* 2CEE7C 003CEE7C 7000B77B */  lq         $23, 0x70($29)
    /* 2CEE80 003CEE80 6000B67B */  lq         $22, 0x60($29)
    /* 2CEE84 003CEE84 5000B57B */  lq         $21, 0x50($29)
    /* 2CEE88 003CEE88 4000B47B */  lq         $20, 0x40($29)
    /* 2CEE8C 003CEE8C 3000B37B */  lq         $19, 0x30($29)
    /* 2CEE90 003CEE90 2000B27B */  lq         $18, 0x20($29)
    /* 2CEE94 003CEE94 1000B17B */  lq         $17, 0x10($29)
    /* 2CEE98 003CEE98 0000B07B */  lq         $16, 0x0($29)
    /* 2CEE9C 003CEE9C 0800E003 */  jr         $31
    /* 2CEEA0 003CEEA0 C000BD27 */   addiu     $29, $29, 0xC0
    /* 2CEEA4 003CEEA4 00000000 */  nop
    /* 2CEEA8 003CEEA8 00000000 */  nop
    /* 2CEEAC 003CEEAC 00000000 */  nop
.size func_003cebb0, 0x300
