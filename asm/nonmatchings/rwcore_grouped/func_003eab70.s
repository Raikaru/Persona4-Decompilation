.section .text
.set noat
.set noreorder
glabel func_003eab70
    /* 2EAB70 003EAB70 10FFBD27 */  addiu      $29, $29, -0xF0
    /* 2EAB74 003EAB74 8800023C */  lui        $2, %hi(D_008872E0)
    /* 2EAB78 003EAB78 9000BFFF */  sd         $31, 0x90($29)
    /* 2EAB7C 003EAB7C E0724224 */  addiu      $2, $2, %lo(D_008872E0)
    /* 2EAB80 003EAB80 8000BE7F */  sq         $30, 0x80($29)
    /* 2EAB84 003EAB84 7000B77F */  sq         $23, 0x70($29)
    /* 2EAB88 003EAB88 6000B67F */  sq         $22, 0x60($29)
    /* 2EAB8C 003EAB8C 2DB8E000 */  daddu      $23, $7, $0
    /* 2EAB90 003EAB90 5000B57F */  sq         $21, 0x50($29)
    /* 2EAB94 003EAB94 2DB0C000 */  daddu      $22, $6, $0
    /* 2EAB98 003EAB98 4000B47F */  sq         $20, 0x40($29)
    /* 2EAB9C 003EAB9C 2DA8A000 */  daddu      $21, $5, $0
    /* 2EABA0 003EABA0 3000B37F */  sq         $19, 0x30($29)
    /* 2EABA4 003EABA4 2000B27F */  sq         $18, 0x20($29)
    /* 2EABA8 003EABA8 1000B17F */  sq         $17, 0x10($29)
    /* 2EABAC 003EABAC 0000B07F */  sq         $16, 0x0($29)
    /* 2EABB0 003EABB0 C8B7838F */  lw         $3, -0x4838($28)
    /* 2EABB4 003EABB4 21104300 */  addu       $2, $2, $3
    /* 2EABB8 003EABB8 0400528C */  lw         $18, 0x4($2)
    /* 2EABBC 003EABBC 28940F0C */  jal        func_003e50a0
    /* 2EABC0 003EABC0 2D988000 */   daddu     $19, $4, $0
    /* 2EABC4 003EABC4 1D004014 */  bnez       $2, .L003EAC3C
    /* 2EABC8 003EABC8 00000000 */   nop
    /* 2EABCC 003EABCC 1B004012 */  beqz       $18, .L003EAC3C
    /* 2EABD0 003EABD0 00000000 */   nop
    /* 2EABD4 003EABD4 00004282 */  lb         $2, 0x0($18)
    /* 2EABD8 003EABD8 18004010 */  beqz       $2, .L003EAC3C
    /* 2EABDC 003EABDC 00000000 */   nop
    /* 2EABE0 003EABE0 8800023C */  lui        $2, %hi(D_008873D4)
    /* 2EABE4 003EABE4 88001E3C */  lui        $30, %hi(D_008873C0)
    /* 2EABE8 003EABE8 D4734224 */  addiu      $2, $2, %lo(D_008873D4)
    /* 2EABEC 003EABEC C073DE27 */  addiu      $30, $30, %lo(D_008873C0)
    /* 2EABF0 003EABF0 D000A27F */  sq         $2, 0xD0($29)
    /* 2EABF4 003EABF4 8800023C */  lui        $2, %hi(D_008873F0)
    /* 2EABF8 003EABF8 F0734224 */  addiu      $2, $2, %lo(D_008873F0)
    /* 2EABFC 003EABFC C000A27F */  sq         $2, 0xC0($29)
    /* 2EAC00 003EAC00 8800023C */  lui        $2, %hi(jtbl_008873E8)
    /* 2EAC04 003EAC04 E8734224 */  addiu      $2, $2, %lo(jtbl_008873E8)
    /* 2EAC08 003EAC08 B000A27F */  sq         $2, 0xB0($29)
    /* 2EAC0C 003EAC0C 8800023C */  lui        $2, %hi(D_008873AC)
    /* 2EAC10 003EAC10 AC734224 */  addiu      $2, $2, %lo(D_008873AC)
    /* 2EAC14 003EAC14 A000A27F */  sq         $2, 0xA0($29)
  .L003EAC18:
    /* 2EAC18 003EAC18 2B101200 */  sltu       $2, $0, $18
    /* 2EAC1C 003EAC1C 01004238 */  xori       $2, $2, 0x1
    /* 2EAC20 003EAC20 04004014 */  bnez       $2, .L003EAC34
    /* 2EAC24 003EAC24 00000000 */   nop
    /* 2EAC28 003EAC28 00004282 */  lb         $2, 0x0($18)
    /* 2EAC2C 003EAC2C 47004014 */  bnez       $2, .L003EAD4C
    /* 2EAC30 003EAC30 00000000 */   nop
  .L003EAC34:
    /* 2EAC34 003EAC34 A5000010 */  b          .L003EAECC
    /* 2EAC38 003EAC38 2D106002 */   daddu     $2, $19, $0
  .L003EAC3C:
    /* 2EAC3C 003EAC3C 8800023C */  lui        $2, %hi(D_008873D4)
    /* 2EAC40 003EAC40 D473428C */  lw         $2, %lo(D_008873D4)($2)
    /* 2EAC44 003EAC44 09F84000 */  jalr       $2
    /* 2EAC48 003EAC48 2D206002 */   daddu     $4, $19, $0
    /* 2EAC4C 003EAC4C C8B7838F */  lw         $3, -0x4838($28)
    /* 2EAC50 003EAC50 2180A202 */  addu       $16, $21, $2
    /* 2EAC54 003EAC54 8800023C */  lui        $2, %hi(D_008872E0)
    /* 2EAC58 003EAC58 E0724224 */  addiu      $2, $2, %lo(D_008872E0)
    /* 2EAC5C 003EAC5C 21184300 */  addu       $3, $2, $3
    /* 2EAC60 003EAC60 1402628C */  lw         $2, 0x214($3)
    /* 2EAC64 003EAC64 2A085000 */  slt        $1, $2, $16
    /* 2EAC68 003EAC68 1A002010 */  beqz       $1, .L003EACD4
    /* 2EAC6C 003EAC6C 00000000 */   nop
    /* 2EAC70 003EAC70 1002648C */  lw         $4, 0x210($3)
    /* 2EAC74 003EAC74 09008010 */  beqz       $4, .L003EAC9C
    /* 2EAC78 003EAC78 00000000 */   nop
    /* 2EAC7C 003EAC7C 0401023C */  lui        $2, (0x1040018 >> 16)
    /* 2EAC80 003EAC80 18004634 */  ori        $6, $2, (0x1040018 & 0xFFFF)
    /* 2EAC84 003EAC84 8800023C */  lui        $2, %hi(D_008873F0)
    /* 2EAC88 003EAC88 F073428C */  lw         $2, %lo(D_008873F0)($2)
    /* 2EAC8C 003EAC8C 09F84000 */  jalr       $2
    /* 2EAC90 003EAC90 2D280002 */   daddu     $5, $16, $0
    /* 2EAC94 003EAC94 07000010 */  b          .L003EACB4
    /* 2EAC98 003EAC98 00000000 */   nop
  .L003EAC9C:
    /* 2EAC9C 003EAC9C 0401023C */  lui        $2, (0x1040018 >> 16)
    /* 2EACA0 003EACA0 18004534 */  ori        $5, $2, (0x1040018 & 0xFFFF)
    /* 2EACA4 003EACA4 8800023C */  lui        $2, %hi(jtbl_008873E8)
    /* 2EACA8 003EACA8 E873428C */  lw         $2, %lo(jtbl_008873E8)($2)
    /* 2EACAC 003EACAC 09F84000 */  jalr       $2
    /* 2EACB0 003EACB0 2D200002 */   daddu     $4, $16, $0
  .L003EACB4:
    /* 2EACB4 003EACB4 18004010 */  beqz       $2, .L003EAD18
    /* 2EACB8 003EACB8 00000000 */   nop
    /* 2EACBC 003EACBC C8B7848F */  lw         $4, -0x4838($28)
    /* 2EACC0 003EACC0 8800033C */  lui        $3, %hi(D_008872E0)
    /* 2EACC4 003EACC4 E0726324 */  addiu      $3, $3, %lo(D_008872E0)
    /* 2EACC8 003EACC8 21186400 */  addu       $3, $3, $4
    /* 2EACCC 003EACCC 100262AC */  sw         $2, 0x210($3)
    /* 2EACD0 003EACD0 140270AC */  sw         $16, 0x214($3)
  .L003EACD4:
    /* 2EACD4 003EACD4 C8B7838F */  lw         $3, -0x4838($28)
    /* 2EACD8 003EACD8 8800023C */  lui        $2, %hi(D_008872E0)
    /* 2EACDC 003EACDC E0724224 */  addiu      $2, $2, %lo(D_008872E0)
    /* 2EACE0 003EACE0 21104300 */  addu       $2, $2, $3
    /* 2EACE4 003EACE4 1002508C */  lw         $16, 0x210($2)
  .L003EACE8:
    /* 2EACE8 003EACE8 16000012 */  beqz       $16, .L003EAD44
    /* 2EACEC 003EACEC 00000000 */   nop
    /* 2EACF0 003EACF0 8800023C */  lui        $2, %hi(D_008873AC)
    /* 2EACF4 003EACF4 2D200002 */  daddu      $4, $16, $0
    /* 2EACF8 003EACF8 AC73428C */  lw         $2, %lo(D_008873AC)($2)
    /* 2EACFC 003EACFC 09F84000 */  jalr       $2
    /* 2EAD00 003EAD00 2D286002 */   daddu     $5, $19, $0
    /* 2EAD04 003EAD04 2D200002 */  daddu      $4, $16, $0
    /* 2EAD08 003EAD08 09F8C002 */  jalr       $22
    /* 2EAD0C 003EAD0C 2D28E002 */   daddu     $5, $23, $0
    /* 2EAD10 003EAD10 C8FF0010 */  b          .L003EAC34
    /* 2EAD14 003EAD14 00000000 */   nop
  .L003EAD18:
    /* 2EAD18 003EAD18 01000224 */  addiu      $2, $0, 0x1
    /* 2EAD1C 003EAD1C 2D280002 */  daddu      $5, $16, $0
    /* 2EAD20 003EAD20 E800A2AF */  sw         $2, 0xE8($29)
    /* 2EAD24 003EAD24 0080023C */  lui        $2, (0x80000013 >> 16)
    /* 2EAD28 003EAD28 647D0F0C */  jal        func_003df590
    /* 2EAD2C 003EAD2C 13004434 */   ori       $4, $2, (0x80000013 & 0xFFFF)
    /* 2EAD30 003EAD30 EC00A2AF */  sw         $2, 0xEC($29)
    /* 2EAD34 003EAD34 347D0F0C */  jal        func_003df4d0
    /* 2EAD38 003EAD38 E800A427 */   addiu     $4, $29, 0xE8
    /* 2EAD3C 003EAD3C EAFF0010 */  b          .L003EACE8
    /* 2EAD40 003EAD40 2D800000 */   daddu     $16, $0, $0
  .L003EAD44:
    /* 2EAD44 003EAD44 61000010 */  b          .L003EAECC
    /* 2EAD48 003EAD48 2D100000 */   daddu     $2, $0, $0
  .L003EAD4C:
    /* 2EAD4C 003EAD4C 0000C28F */  lw         $2, 0x0($30)
    /* 2EAD50 003EAD50 2D204002 */  daddu      $4, $18, $0
    /* 2EAD54 003EAD54 09F84000 */  jalr       $2
    /* 2EAD58 003EAD58 3B000524 */   addiu     $5, $0, 0x3B
    /* 2EAD5C 003EAD5C 0000C28F */  lw         $2, 0x0($30)
    /* 2EAD60 003EAD60 2D204002 */  daddu      $4, $18, $0
    /* 2EAD64 003EAD64 09F84000 */  jalr       $2
    /* 2EAD68 003EAD68 3B000524 */   addiu     $5, $0, 0x3B
    /* 2EAD6C 003EAD6C 2D884000 */  daddu      $17, $2, $0
    /* 2EAD70 003EAD70 41002012 */  beqz       $17, .L003EAE78
    /* 2EAD74 003EAD74 00000000 */   nop
    /* 2EAD78 003EAD78 23803202 */  subu       $16, $17, $18
    /* 2EAD7C 003EAD7C 01003126 */  addiu      $17, $17, 0x1
  .L003EAD80:
    /* 2EAD80 003EAD80 D000A27B */  lq         $2, 0xD0($29)
    /* 2EAD84 003EAD84 0000428C */  lw         $2, 0x0($2)
    /* 2EAD88 003EAD88 09F84000 */  jalr       $2
    /* 2EAD8C 003EAD8C 2D206002 */   daddu     $4, $19, $0
    /* 2EAD90 003EAD90 C8B7838F */  lw         $3, -0x4838($28)
    /* 2EAD94 003EAD94 21100202 */  addu       $2, $16, $2
    /* 2EAD98 003EAD98 21A0A202 */  addu       $20, $21, $2
    /* 2EAD9C 003EAD9C 8800023C */  lui        $2, %hi(D_008872E0)
    /* 2EADA0 003EADA0 E0724224 */  addiu      $2, $2, %lo(D_008872E0)
    /* 2EADA4 003EADA4 21184300 */  addu       $3, $2, $3
    /* 2EADA8 003EADA8 1402628C */  lw         $2, 0x214($3)
    /* 2EADAC 003EADAC 2A085400 */  slt        $1, $2, $20
    /* 2EADB0 003EADB0 1A002010 */  beqz       $1, .L003EAE1C
    /* 2EADB4 003EADB4 00000000 */   nop
    /* 2EADB8 003EADB8 1002648C */  lw         $4, 0x210($3)
    /* 2EADBC 003EADBC 09008010 */  beqz       $4, .L003EADE4
    /* 2EADC0 003EADC0 00000000 */   nop
    /* 2EADC4 003EADC4 0401023C */  lui        $2, (0x1040018 >> 16)
    /* 2EADC8 003EADC8 18004634 */  ori        $6, $2, (0x1040018 & 0xFFFF)
    /* 2EADCC 003EADCC C000A27B */  lq         $2, 0xC0($29)
    /* 2EADD0 003EADD0 0000428C */  lw         $2, 0x0($2)
    /* 2EADD4 003EADD4 09F84000 */  jalr       $2
    /* 2EADD8 003EADD8 2D288002 */   daddu     $5, $20, $0
    /* 2EADDC 003EADDC 07000010 */  b          .L003EADFC
    /* 2EADE0 003EADE0 00000000 */   nop
  .L003EADE4:
    /* 2EADE4 003EADE4 0401023C */  lui        $2, (0x1040018 >> 16)
    /* 2EADE8 003EADE8 18004534 */  ori        $5, $2, (0x1040018 & 0xFFFF)
    /* 2EADEC 003EADEC B000A27B */  lq         $2, 0xB0($29)
    /* 2EADF0 003EADF0 0000428C */  lw         $2, 0x0($2)
    /* 2EADF4 003EADF4 09F84000 */  jalr       $2
    /* 2EADF8 003EADF8 2D208002 */   daddu     $4, $20, $0
  .L003EADFC:
    /* 2EADFC 003EADFC 24004010 */  beqz       $2, .L003EAE90
    /* 2EAE00 003EAE00 00000000 */   nop
    /* 2EAE04 003EAE04 C8B7848F */  lw         $4, -0x4838($28)
    /* 2EAE08 003EAE08 8800033C */  lui        $3, %hi(D_008872E0)
    /* 2EAE0C 003EAE0C E0726324 */  addiu      $3, $3, %lo(D_008872E0)
    /* 2EAE10 003EAE10 21186400 */  addu       $3, $3, $4
    /* 2EAE14 003EAE14 100262AC */  sw         $2, 0x210($3)
    /* 2EAE18 003EAE18 140274AC */  sw         $20, 0x214($3)
  .L003EAE1C:
    /* 2EAE1C 003EAE1C C8B7838F */  lw         $3, -0x4838($28)
    /* 2EAE20 003EAE20 8800023C */  lui        $2, %hi(D_008872E0)
    /* 2EAE24 003EAE24 E0724224 */  addiu      $2, $2, %lo(D_008872E0)
    /* 2EAE28 003EAE28 21104300 */  addu       $2, $2, $3
    /* 2EAE2C 003EAE2C 1002548C */  lw         $20, 0x210($2)
  .L003EAE30:
    /* 2EAE30 003EAE30 23008012 */  beqz       $20, .L003EAEC0
    /* 2EAE34 003EAE34 00000000 */   nop
    /* 2EAE38 003EAE38 2D284002 */  daddu      $5, $18, $0
    /* 2EAE3C 003EAE3C 2D208002 */  daddu      $4, $20, $0
    /* 2EAE40 003EAE40 04FE100C */  jal        func_0043f810
    /* 2EAE44 003EAE44 2D300002 */   daddu     $6, $16, $0
    /* 2EAE48 003EAE48 A000A27B */  lq         $2, 0xA0($29)
    /* 2EAE4C 003EAE4C 21209002 */  addu       $4, $20, $16
    /* 2EAE50 003EAE50 0000428C */  lw         $2, 0x0($2)
    /* 2EAE54 003EAE54 09F84000 */  jalr       $2
    /* 2EAE58 003EAE58 2D286002 */   daddu     $5, $19, $0
    /* 2EAE5C 003EAE5C 2D208002 */  daddu      $4, $20, $0
    /* 2EAE60 003EAE60 09F8C002 */  jalr       $22
    /* 2EAE64 003EAE64 2D28E002 */   daddu     $5, $23, $0
    /* 2EAE68 003EAE68 17004010 */  beqz       $2, .L003EAEC8
    /* 2EAE6C 003EAE6C 00000000 */   nop
    /* 2EAE70 003EAE70 69FF0010 */  b          .L003EAC18
    /* 2EAE74 003EAE74 2D902002 */   daddu     $18, $17, $0
  .L003EAE78:
    /* 2EAE78 003EAE78 D000A27B */  lq         $2, 0xD0($29)
    /* 2EAE7C 003EAE7C 0000428C */  lw         $2, 0x0($2)
    /* 2EAE80 003EAE80 09F84000 */  jalr       $2
    /* 2EAE84 003EAE84 2D204002 */   daddu     $4, $18, $0
    /* 2EAE88 003EAE88 BDFF0010 */  b          .L003EAD80
    /* 2EAE8C 003EAE8C 2D804000 */   daddu     $16, $2, $0
  .L003EAE90:
    /* 2EAE90 003EAE90 01000224 */  addiu      $2, $0, 0x1
    /* 2EAE94 003EAE94 2D288002 */  daddu      $5, $20, $0
    /* 2EAE98 003EAE98 E000A2AF */  sw         $2, 0xE0($29)
    /* 2EAE9C 003EAE9C 0080023C */  lui        $2, (0x80000013 >> 16)
    /* 2EAEA0 003EAEA0 647D0F0C */  jal        func_003df590
    /* 2EAEA4 003EAEA4 13004434 */   ori       $4, $2, (0x80000013 & 0xFFFF)
    /* 2EAEA8 003EAEA8 E400A327 */  addiu      $3, $29, 0xE4
    /* 2EAEAC 003EAEAC E000A427 */  addiu      $4, $29, 0xE0
    /* 2EAEB0 003EAEB0 347D0F0C */  jal        func_003df4d0
    /* 2EAEB4 003EAEB4 000062AC */   sw        $2, 0x0($3)
    /* 2EAEB8 003EAEB8 DDFF0010 */  b          .L003EAE30
    /* 2EAEBC 003EAEBC 2DA00000 */   daddu     $20, $0, $0
  .L003EAEC0:
    /* 2EAEC0 003EAEC0 02000010 */  b          .L003EAECC
    /* 2EAEC4 003EAEC4 2D100000 */   daddu     $2, $0, $0
  .L003EAEC8:
    /* 2EAEC8 003EAEC8 2D106002 */  daddu      $2, $19, $0
  .L003EAECC:
    /* 2EAECC 003EAECC 9000BFDF */  ld         $31, 0x90($29)
    /* 2EAED0 003EAED0 8000BE7B */  lq         $30, 0x80($29)
    /* 2EAED4 003EAED4 7000B77B */  lq         $23, 0x70($29)
    /* 2EAED8 003EAED8 6000B67B */  lq         $22, 0x60($29)
    /* 2EAEDC 003EAEDC 5000B57B */  lq         $21, 0x50($29)
    /* 2EAEE0 003EAEE0 4000B47B */  lq         $20, 0x40($29)
    /* 2EAEE4 003EAEE4 3000B37B */  lq         $19, 0x30($29)
    /* 2EAEE8 003EAEE8 2000B27B */  lq         $18, 0x20($29)
    /* 2EAEEC 003EAEEC 1000B17B */  lq         $17, 0x10($29)
    /* 2EAEF0 003EAEF0 0000B07B */  lq         $16, 0x0($29)
    /* 2EAEF4 003EAEF4 0800E003 */  jr         $31
    /* 2EAEF8 003EAEF8 F000BD27 */   addiu     $29, $29, 0xF0
    /* 2EAEFC 003EAEFC 00000000 */  nop
.size func_003eab70, 0x390
