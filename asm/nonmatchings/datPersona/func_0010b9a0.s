.section .text
.set noat
.set noreorder
glabel func_0010b9a0
    /* B9A0 0010B9A0 C0FFBD27 */  addiu      $29, $29, -0x40
    /* B9A4 0010B9A4 3000BFFF */  sd         $31, 0x30($29)
    /* B9A8 0010B9A8 2000B27F */  sq         $18, 0x20($29)
    /* B9AC 0010B9AC 1000B17F */  sq         $17, 0x10($29)
    /* B9B0 0010B9B0 0000B07F */  sq         $16, 0x0($29)
    /* B9B4 0010B9B4 2D88A000 */  daddu      $17, $5, $0
    /* B9B8 0010B9B8 FFFF9030 */  andi       $16, $4, 0xFFFF
    /* B9BC 0010B9BC 01000224 */  addiu      $2, $0, 0x1
    /* B9C0 0010B9C0 AA000216 */  bne        $16, $2, .L0010BC6C
    /* B9C4 0010B9C4 00000000 */   nop
    /* B9C8 0010B9C8 CC2A040C */  jal        func_0010ab30
    /* B9CC 0010B9CC 00000000 */   nop
    /* B9D0 0010B9D0 3C1C0200 */  dsll32     $3, $2, 16
    /* B9D4 0010B9D4 3F1C0300 */  dsra32     $3, $3, 16
    /* B9D8 0010B9D8 FFFF0224 */  addiu      $2, $0, -0x1
    /* B9DC 0010B9DC 04006214 */  bne        $3, $2, .L0010B9F0
    /* B9E0 0010B9E0 00000000 */   nop
    /* B9E4 0010B9E4 2D800000 */  daddu      $16, $0, $0
    /* B9E8 0010B9E8 18000010 */  b          .L0010BA4C
    /* B9EC 0010B9EC 00000000 */   nop
  .L0010B9F0:
    /* B9F0 0010B9F0 40100300 */  sll        $2, $3, 1
    /* B9F4 0010B9F4 21104300 */  addu       $2, $2, $3
    /* B9F8 0010B9F8 00910200 */  sll        $18, $2, 4
    /* B9FC 0010B9FC 7900023C */  lui        $2, %hi(D_007973A0)
    /* BA00 0010BA00 A0734224 */  addiu      $2, $2, %lo(D_007973A0)
    /* BA04 0010BA04 21105200 */  addu       $2, $2, $18
    /* BA08 0010BA08 EC0B5024 */  addiu      $16, $2, 0xBEC
    /* BA0C 0010BA0C 2D200002 */  daddu      $4, $16, $0
    /* BA10 0010BA10 2D282002 */  daddu      $5, $17, $0
    /* BA14 0010BA14 B432040C */  jal        func_0010cad0
    /* BA18 0010BA18 00000000 */   nop
    /* BA1C 0010BA1C 7900023C */  lui        $2, %hi(D_00797F8C)
    /* BA20 0010BA20 8C7F4224 */  addiu      $2, $2, %lo(D_00797F8C)
    /* BA24 0010BA24 21185200 */  addu       $3, $2, $18
    /* BA28 0010BA28 00006294 */  lhu        $2, 0x0($3)
    /* BA2C 0010BA2C 0C004230 */  andi       $2, $2, 0xC
    /* BA30 0010BA30 000062A4 */  sh         $2, 0x0($3)
    /* BA34 0010BA34 00006294 */  lhu        $2, 0x0($3)
    /* BA38 0010BA38 01004234 */  ori        $2, $2, 0x1
    /* BA3C 0010BA3C 000062A4 */  sh         $2, 0x0($3)
    /* BA40 0010BA40 2D200002 */  daddu      $4, $16, $0
    /* BA44 0010BA44 783F040C */  jal        func_0010fde0
    /* BA48 0010BA48 00000000 */   nop
  .L0010BA4C:
    /* BA4C 0010BA4C 06000016 */  bnez       $16, .L0010BA68
    /* BA50 0010BA50 00000000 */   nop
    /* BA54 0010BA54 5E00043C */  lui        $4, %hi(D_005E4318)
    /* BA58 0010BA58 18438424 */  addiu      $4, $4, %lo(D_005E4318)
    /* BA5C 0010BA5C 3A040524 */  addiu      $5, $0, 0x43A
    /* BA60 0010BA60 CCB5110C */  jal        func_0046d730
    /* BA64 0010BA64 00000000 */   nop
  .L0010BA68:
    /* BA68 0010BA68 7A00023C */  lui        $2, %hi(D_0079B40C)
    /* BA6C 0010BA6C 0CB4488C */  lw         $8, %lo(D_0079B40C)($2)
    /* BA70 0010BA70 04000731 */  andi       $7, $8, 0x4
    /* BA74 0010BA74 0400E010 */  beqz       $7, .L0010BA88
    /* BA78 0010BA78 00000000 */   nop
    /* BA7C 0010BA7C 0C000264 */  daddiu     $2, $0, 0xC
    /* BA80 0010BA80 0E000010 */  b          .L0010BABC
    /* BA84 0010BA84 00000000 */   nop
  .L0010BA88:
    /* BA88 0010BA88 02000231 */  andi       $2, $8, 0x2
    /* BA8C 0010BA8C 04004010 */  beqz       $2, .L0010BAA0
    /* BA90 0010BA90 00000000 */   nop
    /* BA94 0010BA94 0A000264 */  daddiu     $2, $0, 0xA
    /* BA98 0010BA98 08000010 */  b          .L0010BABC
    /* BA9C 0010BA9C 00000000 */   nop
  .L0010BAA0:
    /* BAA0 0010BAA0 01000231 */  andi       $2, $8, 0x1
    /* BAA4 0010BAA4 04004010 */  beqz       $2, .L0010BAB8
    /* BAA8 0010BAA8 00000000 */   nop
    /* BAAC 0010BAAC 08000264 */  daddiu     $2, $0, 0x8
    /* BAB0 0010BAB0 02000010 */  b          .L0010BABC
    /* BAB4 0010BAB4 00000000 */   nop
  .L0010BAB8:
    /* BAB8 0010BAB8 06000264 */  daddiu     $2, $0, 0x6
  .L0010BABC:
    /* BABC 0010BABC 2D480000 */  daddu      $9, $0, $0
    /* BAC0 0010BAC0 3C341100 */  dsll32     $6, $17, 16
    /* BAC4 0010BAC4 3F340600 */  dsra32     $6, $6, 16
    /* BAC8 0010BAC8 FFFF4530 */  andi       $5, $2, 0xFFFF
    /* BACC 0010BACC 7900043C */  lui        $4, %hi(D_007973A0)
    /* BAD0 0010BAD0 A0738424 */  addiu      $4, $4, %lo(D_007973A0)
    /* BAD4 0010BAD4 13000010 */  b          .L0010BB24
    /* BAD8 0010BAD8 00000000 */   nop
  .L0010BADC:
    /* BADC 0010BADC FFFF2331 */  andi       $3, $9, 0xFFFF
    /* BAE0 0010BAE0 40100300 */  sll        $2, $3, 1
    /* BAE4 0010BAE4 21104300 */  addu       $2, $2, $3
    /* BAE8 0010BAE8 00110200 */  sll        $2, $2, 4
    /* BAEC 0010BAEC 21188200 */  addu       $3, $4, $2
    /* BAF0 0010BAF0 EC0B6294 */  lhu        $2, 0xBEC($3)
    /* BAF4 0010BAF4 01004230 */  andi       $2, $2, 0x1
    /* BAF8 0010BAF8 08004010 */  beqz       $2, .L0010BB1C
    /* BAFC 0010BAFC 00000000 */   nop
    /* BB00 0010BB00 EE0B6294 */  lhu        $2, 0xBEE($3)
    /* BB04 0010BB04 05004614 */  bne        $2, $6, .L0010BB1C
    /* BB08 0010BB08 00000000 */   nop
    /* BB0C 0010BB0C 3C8C0900 */  dsll32     $17, $9, 16
    /* BB10 0010BB10 3F8C1100 */  dsra32     $17, $17, 16
    /* BB14 0010BB14 08000010 */  b          .L0010BB38
    /* BB18 0010BB18 00000000 */   nop
  .L0010BB1C:
    /* BB1C 0010BB1C 01002225 */  addiu      $2, $9, 0x1
    /* BB20 0010BB20 FFFF4930 */  andi       $9, $2, 0xFFFF
  .L0010BB24:
    /* BB24 0010BB24 FFFF2231 */  andi       $2, $9, 0xFFFF
    /* BB28 0010BB28 2A104500 */  slt        $2, $2, $5
    /* BB2C 0010BB2C EBFF4014 */  bnez       $2, .L0010BADC
    /* BB30 0010BB30 00000000 */   nop
    /* BB34 0010BB34 FFFF1124 */  addiu      $17, $0, -0x1
  .L0010BB38:
    /* BB38 0010BB38 3C841100 */  dsll32     $16, $17, 16
    /* BB3C 0010BB3C 3F841000 */  dsra32     $16, $16, 16
    /* BB40 0010BB40 17000006 */  bltz       $16, .L0010BBA0
    /* BB44 0010BB44 00000000 */   nop
    /* BB48 0010BB48 0400E010 */  beqz       $7, .L0010BB5C
    /* BB4C 0010BB4C 00000000 */   nop
    /* BB50 0010BB50 0C000264 */  daddiu     $2, $0, 0xC
    /* BB54 0010BB54 0E000010 */  b          .L0010BB90
    /* BB58 0010BB58 00000000 */   nop
  .L0010BB5C:
    /* BB5C 0010BB5C 02000231 */  andi       $2, $8, 0x2
    /* BB60 0010BB60 04004010 */  beqz       $2, .L0010BB74
    /* BB64 0010BB64 00000000 */   nop
    /* BB68 0010BB68 0A000264 */  daddiu     $2, $0, 0xA
    /* BB6C 0010BB6C 08000010 */  b          .L0010BB90
    /* BB70 0010BB70 00000000 */   nop
  .L0010BB74:
    /* BB74 0010BB74 01000231 */  andi       $2, $8, 0x1
    /* BB78 0010BB78 04004010 */  beqz       $2, .L0010BB8C
    /* BB7C 0010BB7C 00000000 */   nop
    /* BB80 0010BB80 08000264 */  daddiu     $2, $0, 0x8
    /* BB84 0010BB84 02000010 */  b          .L0010BB90
    /* BB88 0010BB88 00000000 */   nop
  .L0010BB8C:
    /* BB8C 0010BB8C 06000264 */  daddiu     $2, $0, 0x6
  .L0010BB90:
    /* BB90 0010BB90 FFFF4230 */  andi       $2, $2, 0xFFFF
    /* BB94 0010BB94 2A100202 */  slt        $2, $16, $2
    /* BB98 0010BB98 06004014 */  bnez       $2, .L0010BBB4
    /* BB9C 0010BB9C 00000000 */   nop
  .L0010BBA0:
    /* BBA0 0010BBA0 5E00043C */  lui        $4, %hi(D_005E4318)
    /* BBA4 0010BBA4 18438424 */  addiu      $4, $4, %lo(D_005E4318)
    /* BBA8 0010BBA8 2D050524 */  addiu      $5, $0, 0x52D
    /* BBAC 0010BBAC CCB5110C */  jal        func_0046d730
    /* BBB0 0010BBB0 00000000 */   nop
  .L0010BBB4:
    /* BBB4 0010BBB4 1A000006 */  bltz       $16, .L0010BC20
    /* BBB8 0010BBB8 00000000 */   nop
    /* BBBC 0010BBBC 7A00023C */  lui        $2, %hi(D_0079B40C)
    /* BBC0 0010BBC0 0CB4438C */  lw         $3, %lo(D_0079B40C)($2)
    /* BBC4 0010BBC4 04006230 */  andi       $2, $3, 0x4
    /* BBC8 0010BBC8 04004010 */  beqz       $2, .L0010BBDC
    /* BBCC 0010BBCC 00000000 */   nop
    /* BBD0 0010BBD0 0C000264 */  daddiu     $2, $0, 0xC
    /* BBD4 0010BBD4 0E000010 */  b          .L0010BC10
    /* BBD8 0010BBD8 00000000 */   nop
  .L0010BBDC:
    /* BBDC 0010BBDC 02006230 */  andi       $2, $3, 0x2
    /* BBE0 0010BBE0 04004010 */  beqz       $2, .L0010BBF4
    /* BBE4 0010BBE4 00000000 */   nop
    /* BBE8 0010BBE8 0A000264 */  daddiu     $2, $0, 0xA
    /* BBEC 0010BBEC 08000010 */  b          .L0010BC10
    /* BBF0 0010BBF0 00000000 */   nop
  .L0010BBF4:
    /* BBF4 0010BBF4 01006230 */  andi       $2, $3, 0x1
    /* BBF8 0010BBF8 04004010 */  beqz       $2, .L0010BC0C
    /* BBFC 0010BBFC 00000000 */   nop
    /* BC00 0010BC00 08000264 */  daddiu     $2, $0, 0x8
    /* BC04 0010BC04 02000010 */  b          .L0010BC10
    /* BC08 0010BC08 00000000 */   nop
  .L0010BC0C:
    /* BC0C 0010BC0C 06000264 */  daddiu     $2, $0, 0x6
  .L0010BC10:
    /* BC10 0010BC10 FFFF4230 */  andi       $2, $2, 0xFFFF
    /* BC14 0010BC14 2A100202 */  slt        $2, $16, $2
    /* BC18 0010BC18 06004014 */  bnez       $2, .L0010BC34
    /* BC1C 0010BC1C 00000000 */   nop
  .L0010BC20:
    /* BC20 0010BC20 5E00043C */  lui        $4, %hi(D_005E4318)
    /* BC24 0010BC24 18438424 */  addiu      $4, $4, %lo(D_005E4318)
    /* BC28 0010BC28 7E040524 */  addiu      $5, $0, 0x47E
    /* BC2C 0010BC2C CCB5110C */  jal        func_0046d730
    /* BC30 0010BC30 00000000 */   nop
  .L0010BC34:
    /* BC34 0010BC34 40101000 */  sll        $2, $16, 1
    /* BC38 0010BC38 21105000 */  addu       $2, $2, $16
    /* BC3C 0010BC3C 00190200 */  sll        $3, $2, 4
    /* BC40 0010BC40 7900023C */  lui        $2, %hi(D_00797F8C)
    /* BC44 0010BC44 8C7F4224 */  addiu      $2, $2, %lo(D_00797F8C)
    /* BC48 0010BC48 21104300 */  addu       $2, $2, $3
    /* BC4C 0010BC4C 00004294 */  lhu        $2, 0x0($2)
    /* BC50 0010BC50 01004230 */  andi       $2, $2, 0x1
    /* BC54 0010BC54 46004010 */  beqz       $2, .L0010BD70
    /* BC58 0010BC58 00000000 */   nop
    /* BC5C 0010BC5C 7900023C */  lui        $2, %hi(D_00797F88)
    /* BC60 0010BC60 887F51A4 */  sh         $17, %lo(D_00797F88)($2)
    /* BC64 0010BC64 42000010 */  b          .L0010BD70
    /* BC68 0010BC68 00000000 */   nop
  .L0010BC6C:
    /* BC6C 0010BC6C 23000216 */  bne        $16, $2, .L0010BCFC
    /* BC70 0010BC70 00000000 */   nop
    /* BC74 0010BC74 7900023C */  lui        $2, %hi(D_00797F88)
    /* BC78 0010BC78 887F5084 */  lh         $16, %lo(D_00797F88)($2)
    /* BC7C 0010BC7C 07000006 */  bltz       $16, .L0010BC9C
    /* BC80 0010BC80 00000000 */   nop
    /* BC84 0010BC84 6C2D040C */  jal        func_0010b5b0
    /* BC88 0010BC88 00000000 */   nop
    /* BC8C 0010BC8C FFFF4230 */  andi       $2, $2, 0xFFFF
    /* BC90 0010BC90 2A100202 */  slt        $2, $16, $2
    /* BC94 0010BC94 06004014 */  bnez       $2, .L0010BCB0
    /* BC98 0010BC98 00000000 */   nop
  .L0010BC9C:
    /* BC9C 0010BC9C 5E00043C */  lui        $4, %hi(D_005E4318)
    /* BCA0 0010BCA0 18438424 */  addiu      $4, $4, %lo(D_005E4318)
    /* BCA4 0010BCA4 FE030524 */  addiu      $5, $0, 0x3FE
    /* BCA8 0010BCA8 CCB5110C */  jal        func_0046d730
    /* BCAC 0010BCAC 00000000 */   nop
  .L0010BCB0:
    /* BCB0 0010BCB0 40101000 */  sll        $2, $16, 1
    /* BCB4 0010BCB4 21105000 */  addu       $2, $2, $16
    /* BCB8 0010BCB8 00190200 */  sll        $3, $2, 4
    /* BCBC 0010BCBC 7900023C */  lui        $2, %hi(D_00797F8C)
    /* BCC0 0010BCC0 8C7F4224 */  addiu      $2, $2, %lo(D_00797F8C)
    /* BCC4 0010BCC4 21104300 */  addu       $2, $2, $3
    /* BCC8 0010BCC8 00004294 */  lhu        $2, 0x0($2)
    /* BCCC 0010BCCC 01004230 */  andi       $2, $2, 0x1
    /* BCD0 0010BCD0 07004010 */  beqz       $2, .L0010BCF0
    /* BCD4 0010BCD4 00000000 */   nop
    /* BCD8 0010BCD8 7900023C */  lui        $2, %hi(D_007973A0)
    /* BCDC 0010BCDC A0734224 */  addiu      $2, $2, %lo(D_007973A0)
    /* BCE0 0010BCE0 21104300 */  addu       $2, $2, $3
    /* BCE4 0010BCE4 EC0B5024 */  addiu      $16, $2, 0xBEC
    /* BCE8 0010BCE8 02000010 */  b          .L0010BCF4
    /* BCEC 0010BCEC 00000000 */   nop
  .L0010BCF0:
    /* BCF0 0010BCF0 2D800000 */  daddu      $16, $0, $0
  .L0010BCF4:
    /* BCF4 0010BCF4 11000010 */  b          .L0010BD3C
    /* BCF8 0010BCF8 00000000 */   nop
  .L0010BCFC:
    /* BCFC 0010BCFC 0B00022A */  slti       $2, $16, 0xB
    /* BD00 0010BD00 06004014 */  bnez       $2, .L0010BD1C
    /* BD04 0010BD04 00000000 */   nop
    /* BD08 0010BD08 5E00043C */  lui        $4, %hi(D_005E4318)
    /* BD0C 0010BD0C 18438424 */  addiu      $4, $4, %lo(D_005E4318)
    /* BD10 0010BD10 A5030524 */  addiu      $5, $0, 0x3A5
    /* BD14 0010BD14 CCB5110C */  jal        func_0046d730
    /* BD18 0010BD18 00000000 */   nop
  .L0010BD1C:
    /* BD1C 0010BD1C FEFF0326 */  addiu      $3, $16, -0x2
    /* BD20 0010BD20 00110300 */  sll        $2, $3, 4
    /* BD24 0010BD24 21104300 */  addu       $2, $2, $3
    /* BD28 0010BD28 C0180200 */  sll        $3, $2, 3
    /* BD2C 0010BD2C 7900023C */  lui        $2, %hi(D_00796E50)
    /* BD30 0010BD30 506E4224 */  addiu      $2, $2, %lo(D_00796E50)
    /* BD34 0010BD34 21104300 */  addu       $2, $2, $3
    /* BD38 0010BD38 54005024 */  addiu      $16, $2, 0x54
  .L0010BD3C:
    /* BD3C 0010BD3C 06000016 */  bnez       $16, .L0010BD58
    /* BD40 0010BD40 00000000 */   nop
    /* BD44 0010BD44 5E00043C */  lui        $4, %hi(D_005E4318)
    /* BD48 0010BD48 18438424 */  addiu      $4, $4, %lo(D_005E4318)
    /* BD4C 0010BD4C A9030524 */  addiu      $5, $0, 0x3A9
    /* BD50 0010BD50 CCB5110C */  jal        func_0046d730
    /* BD54 0010BD54 00000000 */   nop
  .L0010BD58:
    /* BD58 0010BD58 2D200002 */  daddu      $4, $16, $0
    /* BD5C 0010BD5C 2D282002 */  daddu      $5, $17, $0
    /* BD60 0010BD60 B432040C */  jal        func_0010cad0
    /* BD64 0010BD64 00000000 */   nop
    /* BD68 0010BD68 01000224 */  addiu      $2, $0, 0x1
    /* BD6C 0010BD6C 000002A6 */  sh         $2, 0x0($16)
  .L0010BD70:
    /* BD70 0010BD70 01000224 */  addiu      $2, $0, 0x1
    /* BD74 0010BD74 3000BFDF */  ld         $31, 0x30($29)
    /* BD78 0010BD78 2000B27B */  lq         $18, 0x20($29)
    /* BD7C 0010BD7C 1000B17B */  lq         $17, 0x10($29)
    /* BD80 0010BD80 0000B07B */  lq         $16, 0x0($29)
    /* BD84 0010BD84 4000BD27 */  addiu      $29, $29, 0x40
    /* BD88 0010BD88 0800E003 */  jr         $31
    /* BD8C 0010BD8C 00000000 */   nop
.size func_0010b9a0, 0x3f0
