.section .text
.set noat
.set noreorder
glabel func_0024bb00
    /* 14BB00 0024BB00 B0FFBD27 */  addiu      $29, $29, -0x50
    /* 14BB04 0024BB04 3000BFFF */  sd         $31, 0x30($29)
    /* 14BB08 0024BB08 2000B27F */  sq         $18, 0x20($29)
    /* 14BB0C 0024BB0C 1000B17F */  sq         $17, 0x10($29)
    /* 14BB10 0024BB10 0000B07F */  sq         $16, 0x0($29)
    /* 14BB14 0024BB14 2D908000 */  daddu      $18, $4, $0
    /* 14BB18 0024BB18 6300043C */  lui        $4, %hi(D_00635A78)
    /* 14BB1C 0024BB1C 785A8424 */  addiu      $4, $4, %lo(D_00635A78)
    /* 14BB20 0024BB20 E048110C */  jal        func_00452380
    /* 14BB24 0024BB24 00000000 */   nop
    /* 14BB28 0024BB28 2D884000 */  daddu      $17, $2, $0
    /* 14BB2C 0024BB2C 6300023C */  lui        $2, %hi(D_00635A88)
    /* 14BB30 0024BB30 885A43DC */  ld         $3, %lo(D_00635A88)($2)
    /* 14BB34 0024BB34 6300023C */  lui        $2, %hi(D_00635A90)
    /* 14BB38 0024BB38 905A40C4 */  lwc1       $f0, %lo(D_00635A90)($2)
    /* 14BB3C 0024BB3C 4000A3FF */  sd         $3, 0x40($29)
    /* 14BB40 0024BB40 4800A0E7 */  swc1       $f0, 0x48($29)
    /* 14BB44 0024BB44 6300043C */  lui        $4, %hi(D_00635A78)
    /* 14BB48 0024BB48 785A8424 */  addiu      $4, $4, %lo(D_00635A78)
    /* 14BB4C 0024BB4C E048110C */  jal        func_00452380
    /* 14BB50 0024BB50 00000000 */   nop
    /* 14BB54 0024BB54 2D804000 */  daddu      $16, $2, $0
    /* 14BB58 0024BB58 06000016 */  bnez       $16, .L0024BB74
    /* 14BB5C 0024BB5C 00000000 */   nop
    /* 14BB60 0024BB60 6300043C */  lui        $4, %hi(D_006359F0)
    /* 14BB64 0024BB64 F0598424 */  addiu      $4, $4, %lo(D_006359F0)
    /* 14BB68 0024BB68 92030524 */  addiu      $5, $0, 0x392
    /* 14BB6C 0024BB6C CCB5110C */  jal        func_0046d730
    /* 14BB70 0024BB70 00000000 */   nop
  .L0024BB74:
    /* 14BB74 0024BB74 2D200002 */  daddu      $4, $16, $0
    /* 14BB78 0024BB78 5849110C */  jal        func_00452560
    /* 14BB7C 0024BB7C 00000000 */   nop
    /* 14BB80 0024BB80 0000428C */  lw         $2, 0x0($2)
    /* 14BB84 0024BB84 01004230 */  andi       $2, $2, 0x1
    /* 14BB88 0024BB88 2B100200 */  sltu       $2, $0, $2
    /* 14BB8C 0024BB8C 06004014 */  bnez       $2, .L0024BBA8
    /* 14BB90 0024BB90 00000000 */   nop
    /* 14BB94 0024BB94 6300043C */  lui        $4, %hi(D_006359F0)
    /* 14BB98 0024BB98 F0598424 */  addiu      $4, $4, %lo(D_006359F0)
    /* 14BB9C 0024BB9C CD030524 */  addiu      $5, $0, 0x3CD
    /* 14BBA0 0024BBA0 CCB5110C */  jal        func_0046d730
    /* 14BBA4 0024BBA4 00000000 */   nop
  .L0024BBA8:
    /* 14BBA8 0024BBA8 2D202002 */  daddu      $4, $17, $0
    /* 14BBAC 0024BBAC 5849110C */  jal        func_00452560
    /* 14BBB0 0024BBB0 00000000 */   nop
    /* 14BBB4 0024BBB4 2D804000 */  daddu      $16, $2, $0
    /* 14BBB8 0024BBB8 04004006 */  bltz       $18, .L0024BBCC
    /* 14BBBC 0024BBBC 00000000 */   nop
    /* 14BBC0 0024BBC0 0500422A */  slti       $2, $18, 0x5
    /* 14BBC4 0024BBC4 06004014 */  bnez       $2, .L0024BBE0
    /* 14BBC8 0024BBC8 00000000 */   nop
  .L0024BBCC:
    /* 14BBCC 0024BBCC 6300043C */  lui        $4, %hi(D_006359F0)
    /* 14BBD0 0024BBD0 F0598424 */  addiu      $4, $4, %lo(D_006359F0)
    /* 14BBD4 0024BBD4 CF030524 */  addiu      $5, $0, 0x3CF
    /* 14BBD8 0024BBD8 CCB5110C */  jal        func_0046d730
    /* 14BBDC 0024BBDC 00000000 */   nop
  .L0024BBE0:
    /* 14BBE0 0024BBE0 80101200 */  sll        $2, $18, 2
    /* 14BBE4 0024BBE4 21105000 */  addu       $2, $2, $16
    /* 14BBE8 0024BBE8 0C005024 */  addiu      $16, $2, 0xC
    /* 14BBEC 0024BBEC 0C00448C */  lw         $4, 0xC($2)
    /* 14BBF0 0024BBF0 03008010 */  beqz       $4, .L0024BC00
    /* 14BBF4 0024BBF4 00000000 */   nop
    /* 14BBF8 0024BBF8 2048110C */  jal        func_00452080
    /* 14BBFC 0024BBFC 00000000 */   nop
  .L0024BC00:
    /* 14BC00 0024BC00 04000224 */  addiu      $2, $0, 0x4
    /* 14BC04 0024BC04 70004212 */  beq        $18, $2, .L0024BDC8
    /* 14BC08 0024BC08 00000000 */   nop
    /* 14BC0C 0024BC0C 03000224 */  addiu      $2, $0, 0x3
    /* 14BC10 0024BC10 50004212 */  beq        $18, $2, .L0024BD54
    /* 14BC14 0024BC14 00000000 */   nop
    /* 14BC18 0024BC18 02000224 */  addiu      $2, $0, 0x2
    /* 14BC1C 0024BC1C 36004212 */  beq        $18, $2, .L0024BCF8
    /* 14BC20 0024BC20 00000000 */   nop
    /* 14BC24 0024BC24 01000224 */  addiu      $2, $0, 0x1
    /* 14BC28 0024BC28 1C004212 */  beq        $18, $2, .L0024BC9C
    /* 14BC2C 0024BC2C 00000000 */   nop
    /* 14BC30 0024BC30 03004012 */  beqz       $18, .L0024BC40
    /* 14BC34 0024BC34 00000000 */   nop
    /* 14BC38 0024BC38 78000010 */  b          .L0024BE1C
    /* 14BC3C 0024BC3C 00000000 */   nop
  .L0024BC40:
    /* 14BC40 0024BC40 6300043C */  lui        $4, %hi(D_00635AA0)
    /* 14BC44 0024BC44 A05A8424 */  addiu      $4, $4, %lo(D_00635AA0)
    /* 14BC48 0024BC48 4C00A527 */  addiu      $5, $29, 0x4C
    /* 14BC4C 0024BC4C DC57110C */  jal        func_00455f70
    /* 14BC50 0024BC50 00000000 */   nop
    /* 14BC54 0024BC54 2D202002 */  daddu      $4, $17, $0
    /* 14BC58 0024BC58 2D284000 */  daddu      $5, $2, $0
    /* 14BC5C 0024BC5C 2D300000 */  daddu      $6, $0, $0
    /* 14BC60 0024BC60 5E00073C */  lui        $7, %hi(D_005DC7D0)
    /* 14BC64 0024BC64 D0C7E724 */  addiu      $7, $7, %lo(D_005DC7D0)
    /* 14BC68 0024BC68 947F090C */  jal        func_0025fe50
    /* 14BC6C 0024BC6C 00000000 */   nop
    /* 14BC70 0024BC70 2D884000 */  daddu      $17, $2, $0
    /* 14BC74 0024BC74 2D202002 */  daddu      $4, $17, $0
    /* 14BC78 0024BC78 D87F090C */  jal        func_0025ff60
    /* 14BC7C 0024BC7C 00000000 */   nop
    /* 14BC80 0024BC80 2D204000 */  daddu      $4, $2, $0
    /* 14BC84 0024BC84 4000A527 */  addiu      $5, $29, 0x40
    /* 14BC88 0024BC88 94C4120C */  jal        func_004b1250
    /* 14BC8C 0024BC8C 00000000 */   nop
    /* 14BC90 0024BC90 000011AE */  sw         $17, 0x0($16)
    /* 14BC94 0024BC94 61000010 */  b          .L0024BE1C
    /* 14BC98 0024BC98 00000000 */   nop
  .L0024BC9C:
    /* 14BC9C 0024BC9C 6300043C */  lui        $4, %hi(D_00635AC0)
    /* 14BCA0 0024BCA0 C05A8424 */  addiu      $4, $4, %lo(D_00635AC0)
    /* 14BCA4 0024BCA4 4C00A527 */  addiu      $5, $29, 0x4C
    /* 14BCA8 0024BCA8 DC57110C */  jal        func_00455f70
    /* 14BCAC 0024BCAC 00000000 */   nop
    /* 14BCB0 0024BCB0 2D202002 */  daddu      $4, $17, $0
    /* 14BCB4 0024BCB4 2D284000 */  daddu      $5, $2, $0
    /* 14BCB8 0024BCB8 2D300000 */  daddu      $6, $0, $0
    /* 14BCBC 0024BCBC 5E00073C */  lui        $7, %hi(D_005DC7D0)
    /* 14BCC0 0024BCC0 D0C7E724 */  addiu      $7, $7, %lo(D_005DC7D0)
    /* 14BCC4 0024BCC4 947F090C */  jal        func_0025fe50
    /* 14BCC8 0024BCC8 00000000 */   nop
    /* 14BCCC 0024BCCC 2D884000 */  daddu      $17, $2, $0
    /* 14BCD0 0024BCD0 2D202002 */  daddu      $4, $17, $0
    /* 14BCD4 0024BCD4 D87F090C */  jal        func_0025ff60
    /* 14BCD8 0024BCD8 00000000 */   nop
    /* 14BCDC 0024BCDC 2D204000 */  daddu      $4, $2, $0
    /* 14BCE0 0024BCE0 4000A527 */  addiu      $5, $29, 0x40
    /* 14BCE4 0024BCE4 94C4120C */  jal        func_004b1250
    /* 14BCE8 0024BCE8 00000000 */   nop
    /* 14BCEC 0024BCEC 000011AE */  sw         $17, 0x0($16)
    /* 14BCF0 0024BCF0 4A000010 */  b          .L0024BE1C
    /* 14BCF4 0024BCF4 00000000 */   nop
  .L0024BCF8:
    /* 14BCF8 0024BCF8 6300043C */  lui        $4, %hi(D_00635AE0)
    /* 14BCFC 0024BCFC E05A8424 */  addiu      $4, $4, %lo(D_00635AE0)
    /* 14BD00 0024BD00 4C00A527 */  addiu      $5, $29, 0x4C
    /* 14BD04 0024BD04 DC57110C */  jal        func_00455f70
    /* 14BD08 0024BD08 00000000 */   nop
    /* 14BD0C 0024BD0C 2D202002 */  daddu      $4, $17, $0
    /* 14BD10 0024BD10 2D284000 */  daddu      $5, $2, $0
    /* 14BD14 0024BD14 2D300000 */  daddu      $6, $0, $0
    /* 14BD18 0024BD18 5E00073C */  lui        $7, %hi(D_005DC7D0)
    /* 14BD1C 0024BD1C D0C7E724 */  addiu      $7, $7, %lo(D_005DC7D0)
    /* 14BD20 0024BD20 947F090C */  jal        func_0025fe50
    /* 14BD24 0024BD24 00000000 */   nop
    /* 14BD28 0024BD28 2D884000 */  daddu      $17, $2, $0
    /* 14BD2C 0024BD2C 2D202002 */  daddu      $4, $17, $0
    /* 14BD30 0024BD30 D87F090C */  jal        func_0025ff60
    /* 14BD34 0024BD34 00000000 */   nop
    /* 14BD38 0024BD38 2D204000 */  daddu      $4, $2, $0
    /* 14BD3C 0024BD3C 4000A527 */  addiu      $5, $29, 0x40
    /* 14BD40 0024BD40 94C4120C */  jal        func_004b1250
    /* 14BD44 0024BD44 00000000 */   nop
    /* 14BD48 0024BD48 000011AE */  sw         $17, 0x0($16)
    /* 14BD4C 0024BD4C 33000010 */  b          .L0024BE1C
    /* 14BD50 0024BD50 00000000 */   nop
  .L0024BD54:
    /* 14BD54 0024BD54 6300043C */  lui        $4, %hi(D_00635B00)
    /* 14BD58 0024BD58 005B8424 */  addiu      $4, $4, %lo(D_00635B00)
    /* 14BD5C 0024BD5C 4C00A527 */  addiu      $5, $29, 0x4C
    /* 14BD60 0024BD60 DC57110C */  jal        func_00455f70
    /* 14BD64 0024BD64 00000000 */   nop
    /* 14BD68 0024BD68 2D202002 */  daddu      $4, $17, $0
    /* 14BD6C 0024BD6C 2D284000 */  daddu      $5, $2, $0
    /* 14BD70 0024BD70 2D300000 */  daddu      $6, $0, $0
    /* 14BD74 0024BD74 5E00073C */  lui        $7, %hi(D_005DC7D0)
    /* 14BD78 0024BD78 D0C7E724 */  addiu      $7, $7, %lo(D_005DC7D0)
    /* 14BD7C 0024BD7C 947F090C */  jal        func_0025fe50
    /* 14BD80 0024BD80 00000000 */   nop
    /* 14BD84 0024BD84 2D884000 */  daddu      $17, $2, $0
    /* 14BD88 0024BD88 2D202002 */  daddu      $4, $17, $0
    /* 14BD8C 0024BD8C D87F090C */  jal        func_0025ff60
    /* 14BD90 0024BD90 00000000 */   nop
    /* 14BD94 0024BD94 4400A1C7 */  lwc1       $f1, 0x44($29)
    /* 14BD98 0024BD98 2041033C */  lui        $3, (0x41200000 >> 16)
    /* 14BD9C 0024BD9C 00008344 */  mtc1       $3, $f0
    /* 14BDA0 0024BDA0 00000000 */  nop
    /* 14BDA4 0024BDA4 01080046 */  sub.s      $f0, $f1, $f0
    /* 14BDA8 0024BDA8 4400A0E7 */  swc1       $f0, 0x44($29)
    /* 14BDAC 0024BDAC 2D204000 */  daddu      $4, $2, $0
    /* 14BDB0 0024BDB0 4000A527 */  addiu      $5, $29, 0x40
    /* 14BDB4 0024BDB4 94C4120C */  jal        func_004b1250
    /* 14BDB8 0024BDB8 00000000 */   nop
    /* 14BDBC 0024BDBC 000011AE */  sw         $17, 0x0($16)
    /* 14BDC0 0024BDC0 16000010 */  b          .L0024BE1C
    /* 14BDC4 0024BDC4 00000000 */   nop
  .L0024BDC8:
    /* 14BDC8 0024BDC8 6300043C */  lui        $4, %hi(D_00635B20)
    /* 14BDCC 0024BDCC 205B8424 */  addiu      $4, $4, %lo(D_00635B20)
    /* 14BDD0 0024BDD0 4C00A527 */  addiu      $5, $29, 0x4C
    /* 14BDD4 0024BDD4 DC57110C */  jal        func_00455f70
    /* 14BDD8 0024BDD8 00000000 */   nop
    /* 14BDDC 0024BDDC 2D202002 */  daddu      $4, $17, $0
    /* 14BDE0 0024BDE0 2D284000 */  daddu      $5, $2, $0
    /* 14BDE4 0024BDE4 2D300000 */  daddu      $6, $0, $0
    /* 14BDE8 0024BDE8 5E00073C */  lui        $7, %hi(D_005DC7D0)
    /* 14BDEC 0024BDEC D0C7E724 */  addiu      $7, $7, %lo(D_005DC7D0)
    /* 14BDF0 0024BDF0 947F090C */  jal        func_0025fe50
    /* 14BDF4 0024BDF4 00000000 */   nop
    /* 14BDF8 0024BDF8 2D884000 */  daddu      $17, $2, $0
    /* 14BDFC 0024BDFC 2D202002 */  daddu      $4, $17, $0
    /* 14BE00 0024BE00 D87F090C */  jal        func_0025ff60
    /* 14BE04 0024BE04 00000000 */   nop
    /* 14BE08 0024BE08 2D204000 */  daddu      $4, $2, $0
    /* 14BE0C 0024BE0C 4000A527 */  addiu      $5, $29, 0x40
    /* 14BE10 0024BE10 94C4120C */  jal        func_004b1250
    /* 14BE14 0024BE14 00000000 */   nop
    /* 14BE18 0024BE18 000011AE */  sw         $17, 0x0($16)
  .L0024BE1C:
    /* 14BE1C 0024BE1C 2D100000 */  daddu      $2, $0, $0
    /* 14BE20 0024BE20 3000BFDF */  ld         $31, 0x30($29)
    /* 14BE24 0024BE24 2000B27B */  lq         $18, 0x20($29)
    /* 14BE28 0024BE28 1000B17B */  lq         $17, 0x10($29)
    /* 14BE2C 0024BE2C 0000B07B */  lq         $16, 0x0($29)
    /* 14BE30 0024BE30 5000BD27 */  addiu      $29, $29, 0x50
    /* 14BE34 0024BE34 0800E003 */  jr         $31
    /* 14BE38 0024BE38 00000000 */   nop
    /* 14BE3C 0024BE3C 00000000 */  nop
.size func_0024bb00, 0x340
