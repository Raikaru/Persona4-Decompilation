.section .text
.set noat
.set noreorder
glabel func_001ceba0
    /* CEBA0 001CEBA0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* CEBA4 001CEBA4 1000BFFF */  sd         $31, 0x10($29)
    /* CEBA8 001CEBA8 0000B07F */  sq         $16, 0x0($29)
    /* CEBAC 001CEBAC 2D808000 */  daddu      $16, $4, $0
    /* CEBB0 001CEBB0 90C1023C */  lui        $2, (0xC1900000 >> 16)
    /* CEBB4 001CEBB4 000182AC */  sw         $2, 0x100($4)
    /* CEBB8 001CEBB8 01000224 */  addiu      $2, $0, 0x1
    /* CEBBC 001CEBBC 200182AC */  sw         $2, 0x120($4)
    /* CEBC0 001CEBC0 00608044 */  mtc1       $0, $f12
    /* CEBC4 001CEBC4 E000848C */  lw         $4, 0xE0($4)
    /* CEBC8 001CEBC8 2D280000 */  daddu      $5, $0, $0
    /* CEBCC 001CEBCC 2D300000 */  daddu      $6, $0, $0
    /* CEBD0 001CEBD0 00010724 */  addiu      $7, $0, 0x100
    /* CEBD4 001CEBD4 50F3060C */  jal        func_001bcd40
    /* CEBD8 001CEBD8 00000000 */   nop
    /* CEBDC 001CEBDC D0000496 */  lhu        $4, 0xD0($16)
    /* CEBE0 001CEBE0 07000324 */  addiu      $3, $0, 0x7
    /* CEBE4 001CEBE4 2C008314 */  bne        $4, $3, .L001CEC98
    /* CEBE8 001CEBE8 00000000 */   nop
    /* CEBEC 001CEBEC ACB3838F */  lw         $3, -0x4C54($28)
    /* CEBF0 001CEBF0 7401708C */  lw         $16, 0x174($3)
    /* CEBF4 001CEBF4 26000010 */  b          .L001CEC90
    /* CEBF8 001CEBF8 00000000 */   nop
  .L001CEBFC:
    /* CEBFC 001CEBFC ACB3878F */  lw         $7, -0x4C54($28)
    /* CEC00 001CEC00 7001E38C */  lw         $3, 0x170($7)
    /* CEC04 001CEC04 21007010 */  beq        $3, $16, .L001CEC8C
    /* CEC08 001CEC08 00000000 */   nop
    /* CEC0C 001CEC0C 1A000396 */  lhu        $3, 0x1A($16)
    /* CEC10 001CEC10 01006330 */  andi       $3, $3, 0x1
    /* CEC14 001CEC14 1D006010 */  beqz       $3, .L001CEC8C
    /* CEC18 001CEC18 00000000 */   nop
    /* CEC1C 001CEC1C 3000048E */  lw         $4, 0x30($16)
    /* CEC20 001CEC20 A2008590 */  lbu        $5, 0xA2($4)
    /* CEC24 001CEC24 01000324 */  addiu      $3, $0, 0x1
    /* CEC28 001CEC28 1800A310 */  beq        $5, $3, .L001CEC8C
    /* CEC2C 001CEC2C 00000000 */   nop
    /* CEC30 001CEC30 2D400000 */  daddu      $8, $0, $0
    /* CEC34 001CEC34 580CE694 */  lhu        $6, 0xC58($7)
    /* CEC38 001CEC38 09000010 */  b          .L001CEC60
    /* CEC3C 001CEC3C 00000000 */   nop
  .L001CEC40:
    /* CEC40 001CEC40 FFFF0331 */  andi       $3, $8, 0xFFFF
    /* CEC44 001CEC44 80180300 */  sll        $3, $3, 2
    /* CEC48 001CEC48 2118E300 */  addu       $3, $7, $3
    /* CEC4C 001CEC4C 480C638C */  lw         $3, 0xC48($3)
    /* CEC50 001CEC50 07007010 */  beq        $3, $16, .L001CEC70
    /* CEC54 001CEC54 00000000 */   nop
    /* CEC58 001CEC58 01000325 */  addiu      $3, $8, 0x1
    /* CEC5C 001CEC5C FFFF6830 */  andi       $8, $3, 0xFFFF
  .L001CEC60:
    /* CEC60 001CEC60 FFFF0531 */  andi       $5, $8, 0xFFFF
    /* CEC64 001CEC64 2A18A600 */  slt        $3, $5, $6
    /* CEC68 001CEC68 F5FF6014 */  bnez       $3, .L001CEC40
    /* CEC6C 001CEC6C 00000000 */   nop
  .L001CEC70:
    /* CEC70 001CEC70 0600A614 */  bne        $5, $6, .L001CEC8C
    /* CEC74 001CEC74 00000000 */   nop
    /* CEC78 001CEC78 02000524 */  addiu      $5, $0, 0x2
    /* CEC7C 001CEC7C E853060C */  jal        func_00194fa0
    /* CEC80 001CEC80 00000000 */   nop
    /* CEC84 001CEC84 3000038E */  lw         $3, 0x30($16)
    /* CEC88 001CEC88 370060A0 */  sb         $0, 0x37($3)
  .L001CEC8C:
    /* CEC8C 001CEC8C 5004108E */  lw         $16, 0x450($16)
  .L001CEC90:
    /* CEC90 001CEC90 DAFF0016 */  bnez       $16, .L001CEBFC
    /* CEC94 001CEC94 00000000 */   nop
  .L001CEC98:
    /* CEC98 001CEC98 1000BFDF */  ld         $31, 0x10($29)
    /* CEC9C 001CEC9C 0000B07B */  lq         $16, 0x0($29)
    /* CECA0 001CECA0 2000BD27 */  addiu      $29, $29, 0x20
    /* CECA4 001CECA4 0800E003 */  jr         $31
    /* CECA8 001CECA8 00000000 */   nop
    /* CECAC 001CECAC 00000000 */  nop
.size func_001ceba0, 0x110
