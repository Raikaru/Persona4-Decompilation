.section .text
.set noat
.set noreorder
glabel func_001debb0
    /* DEBB0 001DEBB0 80FFBD27 */  addiu      $29, $29, -0x80
    /* DEBB4 001DEBB4 5000BFFF */  sd         $31, 0x50($29)
    /* DEBB8 001DEBB8 4000B47F */  sq         $20, 0x40($29)
    /* DEBBC 001DEBBC 3000B37F */  sq         $19, 0x30($29)
    /* DEBC0 001DEBC0 2000B27F */  sq         $18, 0x20($29)
    /* DEBC4 001DEBC4 1000B17F */  sq         $17, 0x10($29)
    /* DEBC8 001DEBC8 0000B07F */  sq         $16, 0x0($29)
    /* DEBCC 001DEBCC 2D888000 */  daddu      $17, $4, $0
    /* DEBD0 001DEBD0 2D80A000 */  daddu      $16, $5, $0
    /* DEBD4 001DEBD4 2D90C000 */  daddu      $18, $6, $0
    /* DEBD8 001DEBD8 3000838C */  lw         $3, 0x30($4)
    /* DEBDC 001DEBDC A2006290 */  lbu        $2, 0xA2($3)
    /* DEBE0 001DEBE0 10004014 */  bnez       $2, .L001DEC24
    /* DEBE4 001DEBE4 00000000 */   nop
    /* DEBE8 001DEBE8 640A628C */  lw         $2, 0xA64($3)
    /* DEBEC 001DEBEC 10004290 */  lbu        $2, 0x10($2)
    /* DEBF0 001DEBF0 6000A427 */  addiu      $4, $29, 0x60
    /* DEBF4 001DEBF4 6100053C */  lui        $5, %hi(D_00609E20)
    /* DEBF8 001DEBF8 209EA524 */  addiu      $5, $5, %lo(D_00609E20)
    /* DEBFC 001DEBFC 2D30E000 */  daddu      $6, $7, $0
    /* DEC00 001DEC00 2D384000 */  daddu      $7, $2, $0
    /* DEC04 001DEC04 2208110C */  jal        func_00442088
    /* DEC08 001DEC08 00000000 */   nop
    /* DEC0C 001DEC0C 2D204002 */  daddu      $4, $18, $0
    /* DEC10 001DEC10 6000A527 */  addiu      $5, $29, 0x60
    /* DEC14 001DEC14 88770A0C */  jal        func_0029de20
    /* DEC18 001DEC18 00000000 */   nop
    /* DEC1C 001DEC1C 02000010 */  b          .L001DEC28
    /* DEC20 001DEC20 00000000 */   nop
  .L001DEC24:
    /* DEC24 001DEC24 2D10E000 */  daddu      $2, $7, $0
  .L001DEC28:
    /* DEC28 001DEC28 ACB3838F */  lw         $3, -0x4C54($28)
    /* DEC2C 001DEC2C C80D638C */  lw         $3, 0xDC8($3)
    /* DEC30 001DEC30 2000638C */  lw         $3, 0x20($3)
    /* DEC34 001DEC34 FFFF6424 */  addiu      $4, $3, -0x1
    /* DEC38 001DEC38 2D284002 */  daddu      $5, $18, $0
    /* DEC3C 001DEC3C 2D304000 */  daddu      $6, $2, $0
    /* DEC40 001DEC40 A4760A0C */  jal        func_0029da90
    /* DEC44 001DEC44 00000000 */   nop
    /* DEC48 001DEC48 2DA04000 */  daddu      $20, $2, $0
    /* DEC4C 001DEC4C 2D208002 */  daddu      $4, $20, $0
    /* DEC50 001DEC50 2D282002 */  daddu      $5, $17, $0
    /* DEC54 001DEC54 F8770A0C */  jal        func_0029dfe0
    /* DEC58 001DEC58 00000000 */   nop
    /* DEC5C 001DEC5C 2D208002 */  daddu      $4, $20, $0
    /* DEC60 001DEC60 5849110C */  jal        func_00452560
    /* DEC64 001DEC64 00000000 */   nop
    /* DEC68 001DEC68 2D904000 */  daddu      $18, $2, $0
    /* DEC6C 001DEC6C 3001428C */  lw         $2, 0x130($2)
    /* DEC70 001DEC70 1C004004 */  bltz       $2, .L001DECE4
    /* DEC74 001DEC74 00000000 */   nop
    /* DEC78 001DEC78 3000248E */  lw         $4, 0x30($17)
    /* DEC7C 001DEC7C A2008390 */  lbu        $3, 0xA2($4)
    /* DEC80 001DEC80 01000224 */  addiu      $2, $0, 0x1
    /* DEC84 001DEC84 0B006210 */  beq        $3, $2, .L001DECB4
    /* DEC88 001DEC88 00000000 */   nop
    /* DEC8C 001DEC8C 03006010 */  beqz       $3, .L001DEC9C
    /* DEC90 001DEC90 00000000 */   nop
    /* DEC94 001DEC94 0E000010 */  b          .L001DECD0
    /* DEC98 001DEC98 00000000 */   nop
  .L001DEC9C:
    /* DEC9C 001DEC9C A4008484 */  lh         $4, 0xA4($4)
    /* DECA0 001DECA0 D035040C */  jal        func_0010d740
    /* DECA4 001DECA4 00000000 */   nop
    /* DECA8 001DECA8 2D984000 */  daddu      $19, $2, $0
    /* DECAC 001DECAC 08000010 */  b          .L001DECD0
    /* DECB0 001DECB0 00000000 */   nop
  .L001DECB4:
    /* DECB4 001DECB4 A4008394 */  lhu        $3, 0xA4($4)
    /* DECB8 001DECB8 C0100300 */  sll        $2, $3, 3
    /* DECBC 001DECBC 23184300 */  subu       $3, $2, $3
    /* DECC0 001DECC0 80100300 */  sll        $2, $3, 2
    /* DECC4 001DECC4 23184300 */  subu       $3, $2, $3
    /* DECC8 001DECC8 44B4828F */  lw         $2, -0x4BBC($28)
    /* DECCC 001DECCC 21984300 */  addu       $19, $2, $3
  .L001DECD0:
    /* DECD0 001DECD0 3001448E */  lw         $4, 0x130($18)
    /* DECD4 001DECD4 2D280000 */  daddu      $5, $0, $0
    /* DECD8 001DECD8 2D306002 */  daddu      $6, $19, $0
    /* DECDC 001DECDC 14E1090C */  jal        func_00278450
    /* DECE0 001DECE0 00000000 */   nop
  .L001DECE4:
    /* DECE4 001DECE4 ACB3828F */  lw         $2, -0x4C54($28)
    /* DECE8 001DECE8 C80D448C */  lw         $4, 0xDC8($2)
    /* DECEC 001DECEC 2D288002 */  daddu      $5, $20, $0
    /* DECF0 001DECF0 5C49110C */  jal        func_00452570
    /* DECF4 001DECF4 00000000 */   nop
    /* DECF8 001DECF8 4C0014AE */  sw         $20, 0x4C($16)
    /* DECFC 001DECFC 01000224 */  addiu      $2, $0, 0x1
    /* DED00 001DED00 5000BFDF */  ld         $31, 0x50($29)
    /* DED04 001DED04 4000B47B */  lq         $20, 0x40($29)
    /* DED08 001DED08 3000B37B */  lq         $19, 0x30($29)
    /* DED0C 001DED0C 2000B27B */  lq         $18, 0x20($29)
    /* DED10 001DED10 1000B17B */  lq         $17, 0x10($29)
    /* DED14 001DED14 0000B07B */  lq         $16, 0x0($29)
    /* DED18 001DED18 8000BD27 */  addiu      $29, $29, 0x80
    /* DED1C 001DED1C 0800E003 */  jr         $31
    /* DED20 001DED20 00000000 */   nop
    /* DED24 001DED24 00000000 */  nop
    /* DED28 001DED28 00000000 */  nop
    /* DED2C 001DED2C 00000000 */  nop
.size func_001debb0, 0x180
