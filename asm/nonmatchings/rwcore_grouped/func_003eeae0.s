.section .text
.set noat
.set noreorder
glabel func_003eeae0
    /* 2EEAE0 003EEAE0 50FBBD27 */  addiu      $29, $29, -0x4B0
    /* 2EEAE4 003EEAE4 6000BFFF */  sd         $31, 0x60($29)
    /* 2EEAE8 003EEAE8 5000B57F */  sq         $21, 0x50($29)
    /* 2EEAEC 003EEAEC 4000B47F */  sq         $20, 0x40($29)
    /* 2EEAF0 003EEAF0 3000B37F */  sq         $19, 0x30($29)
    /* 2EEAF4 003EEAF4 2000B27F */  sq         $18, 0x20($29)
    /* 2EEAF8 003EEAF8 1000B17F */  sq         $17, 0x10($29)
    /* 2EEAFC 003EEAFC 0000B07F */  sq         $16, 0x0($29)
    /* 2EEB00 003EEB00 2D88A000 */  daddu      $17, $5, $0
    /* 2EEB04 003EEB04 0C00838C */  lw         $3, 0xC($4)
    /* 2EEB08 003EEB08 1000858C */  lw         $5, 0x10($4)
    /* 2EEB0C 003EEB0C 54002012 */  beqz       $17, .L003EEC60
    /* 2EEB10 003EEB10 2D908000 */   daddu     $18, $4, $0
    /* 2EEB14 003EEB14 0C00228E */  lw         $2, 0xC($17)
    /* 2EEB18 003EEB18 20000624 */  addiu      $6, $0, 0x20
    /* 2EEB1C 003EEB1C 60004614 */  bne        $2, $6, .L003EECA0
    /* 2EEB20 003EEB20 00000000 */   nop
    /* 2EEB24 003EEB24 7004B1AF */  sw         $17, 0x470($29)
  .L003EEB28:
    /* 2EEB28 003EEB28 7004A28F */  lw         $2, 0x470($29)
  .L003EEB2C:
    /* 2EEB2C 003EEB2C 6B004010 */  beqz       $2, .L003EECDC
    /* 2EEB30 003EEB30 00000000 */   nop
    /* 2EEB34 003EEB34 23004392 */  lbu        $3, 0x23($18)
    /* 2EEB38 003EEB38 2D204002 */  daddu      $4, $18, $0
    /* 2EEB3C 003EEB3C 10007330 */  andi       $19, $3, 0x10
    /* 2EEB40 003EEB40 27106002 */  not        $2, $19
    /* 2EEB44 003EEB44 FF004230 */  andi       $2, $2, 0xFF
    /* 2EEB48 003EEB48 24106200 */  and        $2, $3, $2
    /* 2EEB4C 003EEB4C 08B10F0C */  jal        func_003ec420
    /* 2EEB50 003EEB50 230042A2 */   sb        $2, 0x23($18)
    /* 2EEB54 003EEB54 2D804000 */  daddu      $16, $2, $0
    /* 2EEB58 003EEB58 0200012A */  slti       $1, $16, 0x2
    /* 2EEB5C 003EEB5C 61002010 */  beqz       $1, .L003EECE4
    /* 2EEB60 003EEB60 01001524 */   addiu     $21, $0, 0x1
    /* 2EEB64 003EEB64 23004292 */  lbu        $2, 0x23($18)
  .L003EEB68:
    /* 2EEB68 003EEB68 001A0200 */  sll        $3, $2, 8
    /* 2EEB6C 003EEB6C 00606230 */  andi       $2, $3, 0x6000
    /* 2EEB70 003EEB70 8D004010 */  beqz       $2, .L003EEDA8
    /* 2EEB74 003EEB74 00000000 */   nop
    /* 2EEB78 003EEB78 00406230 */  andi       $2, $3, 0x4000
    /* 2EEB7C 003EEB7C 17004010 */  beqz       $2, .L003EEBDC
    /* 2EEB80 003EEB80 00000000 */   nop
    /* 2EEB84 003EEB84 7000A427 */  addiu      $4, $29, 0x70
    /* 2EEB88 003EEB88 2D282002 */  daddu      $5, $17, $0
    /* 2EEB8C 003EEB8C 7004A627 */  addiu      $6, $29, 0x470
    /* 2EEB90 003EEB90 2D380002 */  daddu      $7, $16, $0
    /* 2EEB94 003EEB94 0CB70F0C */  jal        func_003edc30
    /* 2EEB98 003EEB98 04000824 */   addiu     $8, $0, 0x4
    /* 2EEB9C 003EEB9C 25004014 */  bnez       $2, .L003EEC34
    /* 2EEBA0 003EEBA0 00000000 */   nop
    /* 2EEBA4 003EEBA4 2A081000 */  slt        $1, $0, $16
    /* 2EEBA8 003EEBA8 22002010 */  beqz       $1, .L003EEC34
    /* 2EEBAC 003EEBAC 00000000 */   nop
    /* 2EEBB0 003EEBB0 7004A48F */  lw         $4, 0x470($29)
    /* 2EEBB4 003EEBB4 03009110 */  beq        $4, $17, .L003EEBC4
    /* 2EEBB8 003EEBB8 00000000 */   nop
    /* 2EEBBC 003EEBBC DCA80F0C */  jal        func_003ea370
    /* 2EEBC0 003EEBC0 00000000 */   nop
  .L003EEBC4:
    /* 2EEBC4 003EEBC4 23004392 */  lbu        $3, 0x23($18)
    /* 2EEBC8 003EEBC8 FF006432 */  andi       $4, $19, 0xFF
    /* 2EEBCC 003EEBCC 2D100000 */  daddu      $2, $0, $0
    /* 2EEBD0 003EEBD0 25186400 */  or         $3, $3, $4
    /* 2EEBD4 003EEBD4 9C000010 */  b          .L003EEE48
    /* 2EEBD8 003EEBD8 230043A2 */   sb        $3, 0x23($18)
  .L003EEBDC:
    /* 2EEBDC 003EEBDC 7000A427 */  addiu      $4, $29, 0x70
    /* 2EEBE0 003EEBE0 2D282002 */  daddu      $5, $17, $0
    /* 2EEBE4 003EEBE4 7004A627 */  addiu      $6, $29, 0x470
    /* 2EEBE8 003EEBE8 2D380002 */  daddu      $7, $16, $0
    /* 2EEBEC 003EEBEC 0CB70F0C */  jal        func_003edc30
    /* 2EEBF0 003EEBF0 08000824 */   addiu     $8, $0, 0x8
    /* 2EEBF4 003EEBF4 0F004014 */  bnez       $2, .L003EEC34
    /* 2EEBF8 003EEBF8 00000000 */   nop
    /* 2EEBFC 003EEBFC 2A081000 */  slt        $1, $0, $16
    /* 2EEC00 003EEC00 0C002010 */  beqz       $1, .L003EEC34
    /* 2EEC04 003EEC04 00000000 */   nop
    /* 2EEC08 003EEC08 7004A48F */  lw         $4, 0x470($29)
    /* 2EEC0C 003EEC0C 03009110 */  beq        $4, $17, .L003EEC1C
    /* 2EEC10 003EEC10 00000000 */   nop
    /* 2EEC14 003EEC14 DCA80F0C */  jal        func_003ea370
    /* 2EEC18 003EEC18 00000000 */   nop
  .L003EEC1C:
    /* 2EEC1C 003EEC1C 23004392 */  lbu        $3, 0x23($18)
    /* 2EEC20 003EEC20 FF006432 */  andi       $4, $19, 0xFF
    /* 2EEC24 003EEC24 2D100000 */  daddu      $2, $0, $0
    /* 2EEC28 003EEC28 25186400 */  or         $3, $3, $4
    /* 2EEC2C 003EEC2C 86000010 */  b          .L003EEE48
    /* 2EEC30 003EEC30 230043A2 */   sb        $3, 0x23($18)
  .L003EEC34:
    /* 2EEC34 003EEC34 78AF0F0C */  jal        func_003ebde0
    /* 2EEC38 003EEC38 7004A48F */   lw        $4, 0x470($29)
  .L003EEC3C:
    /* 2EEC3C 003EEC3C 2A101000 */  slt        $2, $0, $16
  .L003EEC40:
    /* 2EEC40 003EEC40 66004014 */  bnez       $2, .L003EEDDC
    /* 2EEC44 003EEC44 2DA00000 */   daddu     $20, $0, $0
    /* 2EEC48 003EEC48 23004392 */  lbu        $3, 0x23($18)
  .L003EEC4C:
    /* 2EEC4C 003EEC4C FF006432 */  andi       $4, $19, 0xFF
    /* 2EEC50 003EEC50 2D104002 */  daddu      $2, $18, $0
    /* 2EEC54 003EEC54 25186400 */  or         $3, $3, $4
    /* 2EEC58 003EEC58 7B000010 */  b          .L003EEE48
    /* 2EEC5C 003EEC5C 230043A2 */   sb        $3, 0x23($18)
  .L003EEC60:
    /* 2EEC60 003EEC60 2D206000 */  daddu      $4, $3, $0
    /* 2EEC64 003EEC64 B0A80F0C */  jal        func_003ea2c0
    /* 2EEC68 003EEC68 20000624 */   addiu     $6, $0, 0x20
    /* 2EEC6C 003EEC6C AEFF4010 */  beqz       $2, .L003EEB28
    /* 2EEC70 003EEC70 7004A2AF */   sw        $2, 0x470($29)
    /* 2EEC74 003EEC74 F8A80F0C */  jal        func_003ea3e0
    /* 2EEC78 003EEC78 2D204000 */   daddu     $4, $2, $0
    /* 2EEC7C 003EEC7C 06004010 */  beqz       $2, .L003EEC98
    /* 2EEC80 003EEC80 00000000 */   nop
    /* 2EEC84 003EEC84 7004A48F */  lw         $4, 0x470($29)
    /* 2EEC88 003EEC88 44B00F0C */  jal        func_003ec110
    /* 2EEC8C 003EEC8C 2D284002 */   daddu     $5, $18, $0
    /* 2EEC90 003EEC90 A6FF0010 */  b          .L003EEB2C
    /* 2EEC94 003EEC94 7004A28F */   lw        $2, 0x470($29)
  .L003EEC98:
    /* 2EEC98 003EEC98 6B000010 */  b          .L003EEE48
    /* 2EEC9C 003EEC9C 2D100000 */   daddu     $2, $0, $0
  .L003EECA0:
    /* 2EECA0 003EECA0 B0A80F0C */  jal        func_003ea2c0
    /* 2EECA4 003EECA4 2D206000 */   daddu     $4, $3, $0
    /* 2EECA8 003EECA8 9FFF4010 */  beqz       $2, .L003EEB28
    /* 2EECAC 003EECAC 7004A2AF */   sw        $2, 0x470($29)
    /* 2EECB0 003EECB0 F8A80F0C */  jal        func_003ea3e0
    /* 2EECB4 003EECB4 2D204000 */   daddu     $4, $2, $0
    /* 2EECB8 003EECB8 06004010 */  beqz       $2, .L003EECD4
    /* 2EECBC 003EECBC 00000000 */   nop
    /* 2EECC0 003EECC0 7004A48F */  lw         $4, 0x470($29)
    /* 2EECC4 003EECC4 B0AE0F0C */  jal        func_003ebac0
    /* 2EECC8 003EECC8 2D282002 */   daddu     $5, $17, $0
    /* 2EECCC 003EECCC 96FF0010 */  b          .L003EEB28
    /* 2EECD0 003EECD0 00000000 */   nop
  .L003EECD4:
    /* 2EECD4 003EECD4 5C000010 */  b          .L003EEE48
    /* 2EECD8 003EECD8 2D100000 */   daddu     $2, $0, $0
  .L003EECDC:
    /* 2EECDC 003EECDC 5A000010 */  b          .L003EEE48
    /* 2EECE0 003EECE0 2D100000 */   daddu     $2, $0, $0
  .L003EECE4:
    /* 2EECE4 003EECE4 7404B427 */  addiu      $20, $29, 0x474
  .L003EECE8:
    /* 2EECE8 003EECE8 FF00A532 */  andi       $5, $21, 0xFF
    /* 2EECEC 003EECEC 2D204002 */  daddu      $4, $18, $0
    /* 2EECF0 003EECF0 02000624 */  addiu      $6, $0, 0x2
    /* 2EECF4 003EECF4 A8B10F0C */  jal        func_003ec6a0
    /* 2EECF8 003EECF8 000080AE */   sw        $0, 0x0($20)
    /* 2EECFC 003EECFC 0B004014 */  bnez       $2, .L003EED2C
    /* 2EED00 003EED00 00000000 */   nop
    /* 2EED04 003EED04 00000000 */  nop
  .L003EED08:
    /* 2EED08 003EED08 0000828E */  lw         $2, 0x0($20)
    /* 2EED0C 003EED0C 10004010 */  beqz       $2, .L003EED50
    /* 2EED10 003EED10 00000000 */   nop
    /* 2EED14 003EED14 0100B526 */  addiu      $21, $21, 0x1
    /* 2EED18 003EED18 2A10B002 */  slt        $2, $21, $16
    /* 2EED1C 003EED1C F2FF4014 */  bnez       $2, .L003EECE8
    /* 2EED20 003EED20 04009426 */   addiu     $20, $20, 0x4
    /* 2EED24 003EED24 90FF0010 */  b          .L003EEB68
    /* 2EED28 003EED28 23004292 */   lbu       $2, 0x23($18)
  .L003EED2C:
    /* 2EED2C 003EED2C 0C00458E */  lw         $5, 0xC($18)
    /* 2EED30 003EED30 1000468E */  lw         $6, 0x10($18)
    /* 2EED34 003EED34 B4B40F0C */  jal        func_003ed2d0
    /* 2EED38 003EED38 FCFF848E */   lw        $4, -0x4($20)
    /* 2EED3C 003EED3C 000082AE */  sw         $2, 0x0($20)
    /* 2EED40 003EED40 A8B00F0C */  jal        func_003ec2a0
    /* 2EED44 003EED44 2D204002 */   daddu     $4, $18, $0
    /* 2EED48 003EED48 EFFF0010 */  b          .L003EED08
    /* 2EED4C 003EED4C 00000000 */   nop
  .L003EED50:
    /* 2EED50 003EED50 FFFFB526 */  addiu      $21, $21, -0x1
    /* 2EED54 003EED54 0E00A006 */  bltz       $21, .L003EED90
    /* 2EED58 003EED58 00000000 */   nop
    /* 2EED5C 003EED5C 80101500 */  sll        $2, $21, 2
    /* 2EED60 003EED60 21105D00 */  addu       $2, $2, $29
    /* 2EED64 003EED64 70045024 */  addiu      $16, $2, 0x470
  .L003EED68:
    /* 2EED68 003EED68 0000048E */  lw         $4, 0x0($16)
    /* 2EED6C 003EED6C 04009110 */  beq        $4, $17, .L003EED80
    /* 2EED70 003EED70 00000000 */   nop
    /* 2EED74 003EED74 DCA80F0C */  jal        func_003ea370
    /* 2EED78 003EED78 00000000 */   nop
    /* 2EED7C 003EED7C 00000000 */  nop
  .L003EED80:
    /* 2EED80 003EED80 FFFFB526 */  addiu      $21, $21, -0x1
    /* 2EED84 003EED84 F8FFA106 */  bgez       $21, .L003EED68
    /* 2EED88 003EED88 FCFF1026 */   addiu     $16, $16, -0x4
    /* 2EED8C 003EED8C 00000000 */  nop
  .L003EED90:
    /* 2EED90 003EED90 23004392 */  lbu        $3, 0x23($18)
    /* 2EED94 003EED94 FF006432 */  andi       $4, $19, 0xFF
    /* 2EED98 003EED98 2D100000 */  daddu      $2, $0, $0
    /* 2EED9C 003EED9C 25186400 */  or         $3, $3, $4
    /* 2EEDA0 003EEDA0 29000010 */  b          .L003EEE48
    /* 2EEDA4 003EEDA4 230043A2 */   sb        $3, 0x23($18)
  .L003EEDA8:
    /* 2EEDA8 003EEDA8 2A081000 */  slt        $1, $0, $16
    /* 2EEDAC 003EEDAC A3FF2010 */  beqz       $1, .L003EEC3C
    /* 2EEDB0 003EEDB0 2DA00000 */   daddu     $20, $0, $0
    /* 2EEDB4 003EEDB4 7004B527 */  addiu      $21, $29, 0x470
  .L003EEDB8:
    /* 2EEDB8 003EEDB8 78AF0F0C */  jal        func_003ebde0
    /* 2EEDBC 003EEDBC 0000A48E */   lw        $4, 0x0($21)
    /* 2EEDC0 003EEDC0 01009426 */  addiu      $20, $20, 0x1
    /* 2EEDC4 003EEDC4 0400B526 */  addiu      $21, $21, 0x4
    /* 2EEDC8 003EEDC8 2A109002 */  slt        $2, $20, $16
    /* 2EEDCC 003EEDCC FAFF4014 */  bnez       $2, .L003EEDB8
    /* 2EEDD0 003EEDD0 00000000 */   nop
    /* 2EEDD4 003EEDD4 9AFF0010 */  b          .L003EEC40
    /* 2EEDD8 003EEDD8 2A101000 */   slt       $2, $0, $16
  .L003EEDDC:
    /* 2EEDDC 003EEDDC 7004B527 */  addiu      $21, $29, 0x470
  .L003EEDE0:
    /* 2EEDE0 003EEDE0 FF008532 */  andi       $5, $20, 0xFF
    /* 2EEDE4 003EEDE4 2D204002 */  daddu      $4, $18, $0
    /* 2EEDE8 003EEDE8 A8B10F0C */  jal        func_003ec6a0
    /* 2EEDEC 003EEDEC 05000624 */   addiu     $6, $0, 0x5
    /* 2EEDF0 003EEDF0 0D004014 */  bnez       $2, .L003EEE28
    /* 2EEDF4 003EEDF4 00000000 */   nop
  .L003EEDF8:
    /* 2EEDF8 003EEDF8 0000A48E */  lw         $4, 0x0($21)
    /* 2EEDFC 003EEDFC 04009110 */  beq        $4, $17, .L003EEE10
    /* 2EEE00 003EEE00 00000000 */   nop
    /* 2EEE04 003EEE04 DCA80F0C */  jal        func_003ea370
    /* 2EEE08 003EEE08 00000000 */   nop
    /* 2EEE0C 003EEE0C 00000000 */  nop
  .L003EEE10:
    /* 2EEE10 003EEE10 01009426 */  addiu      $20, $20, 0x1
    /* 2EEE14 003EEE14 2A109002 */  slt        $2, $20, $16
    /* 2EEE18 003EEE18 F1FF4014 */  bnez       $2, .L003EEDE0
    /* 2EEE1C 003EEE1C 0400B526 */   addiu     $21, $21, 0x4
    /* 2EEE20 003EEE20 8AFF0010 */  b          .L003EEC4C
    /* 2EEE24 003EEE24 23004392 */   lbu       $3, 0x23($18)
  .L003EEE28:
    /* 2EEE28 003EEE28 0000A58E */  lw         $5, 0x0($21)
    /* 2EEE2C 003EEE2C 60B00F0C */  jal        func_003ec180
    /* 2EEE30 003EEE30 2D204002 */   daddu     $4, $18, $0
    /* 2EEE34 003EEE34 A8B00F0C */  jal        func_003ec2a0
    /* 2EEE38 003EEE38 2D204002 */   daddu     $4, $18, $0
    /* 2EEE3C 003EEE3C EEFF0010 */  b          .L003EEDF8
    /* 2EEE40 003EEE40 00000000 */   nop
    /* 2EEE44 003EEE44 00000000 */  nop
  .L003EEE48:
    /* 2EEE48 003EEE48 6000BFDF */  ld         $31, 0x60($29)
    /* 2EEE4C 003EEE4C 5000B57B */  lq         $21, 0x50($29)
    /* 2EEE50 003EEE50 4000B47B */  lq         $20, 0x40($29)
    /* 2EEE54 003EEE54 3000B37B */  lq         $19, 0x30($29)
    /* 2EEE58 003EEE58 2000B27B */  lq         $18, 0x20($29)
    /* 2EEE5C 003EEE5C 1000B17B */  lq         $17, 0x10($29)
    /* 2EEE60 003EEE60 0000B07B */  lq         $16, 0x0($29)
    /* 2EEE64 003EEE64 0800E003 */  jr         $31
    /* 2EEE68 003EEE68 B004BD27 */   addiu     $29, $29, 0x4B0
    /* 2EEE6C 003EEE6C 00000000 */  nop
.size func_003eeae0, 0x390
