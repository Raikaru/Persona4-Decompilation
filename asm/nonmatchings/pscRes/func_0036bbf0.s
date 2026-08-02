.section .text
.set noat
.set noreorder
glabel func_0036bbf0
    /* 26BBF0 0036BBF0 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 26BBF4 0036BBF4 3000BFFF */  sd         $31, 0x30($29)
    /* 26BBF8 0036BBF8 2000B27F */  sq         $18, 0x20($29)
    /* 26BBFC 0036BBFC 1000B17F */  sq         $17, 0x10($29)
    /* 26BC00 0036BC00 0000B07F */  sq         $16, 0x0($29)
    /* 26BC04 0036BC04 ACB5838F */  lw         $3, -0x4A54($28)
    /* 26BC08 0036BC08 06006014 */  bnez       $3, .L0036BC24
    /* 26BC0C 0036BC0C 00000000 */   nop
    /* 26BC10 0036BC10 6500043C */  lui        $4, %hi(D_0064E4E0)
    /* 26BC14 0036BC14 E0E48424 */  addiu      $4, $4, %lo(D_0064E4E0)
    /* 26BC18 0036BC18 75000524 */  addiu      $5, $0, 0x75
    /* 26BC1C 0036BC1C CCB5110C */  jal        func_0046d730
    /* 26BC20 0036BC20 00000000 */   nop
  .L0036BC24:
    /* 26BC24 0036BC24 ACB5918F */  lw         $17, -0x4A54($28)
    /* 26BC28 0036BC28 1000238E */  lw         $3, 0x10($17)
    /* 26BC2C 0036BC2C 10006330 */  andi       $3, $3, 0x10
    /* 26BC30 0036BC30 04006010 */  beqz       $3, .L0036BC44
    /* 26BC34 0036BC34 00000000 */   nop
    /* 26BC38 0036BC38 0C00248E */  lw         $4, 0xC($17)
    /* 26BC3C 0036BC3C CCB00F0C */  jal        func_003ec330
    /* 26BC40 0036BC40 00000000 */   nop
  .L0036BC44:
    /* 26BC44 0036BC44 1000238E */  lw         $3, 0x10($17)
    /* 26BC48 0036BC48 01006330 */  andi       $3, $3, 0x1
    /* 26BC4C 0036BC4C 04006010 */  beqz       $3, .L0036BC60
    /* 26BC50 0036BC50 00000000 */   nop
    /* 26BC54 0036BC54 0400248E */  lw         $4, 0x4($17)
    /* 26BC58 0036BC58 CCB00F0C */  jal        func_003ec330
    /* 26BC5C 0036BC5C 00000000 */   nop
  .L0036BC60:
    /* 26BC60 0036BC60 1000238E */  lw         $3, 0x10($17)
    /* 26BC64 0036BC64 02006330 */  andi       $3, $3, 0x2
    /* 26BC68 0036BC68 04006010 */  beqz       $3, .L0036BC7C
    /* 26BC6C 0036BC6C 00000000 */   nop
    /* 26BC70 0036BC70 0800248E */  lw         $4, 0x8($17)
    /* 26BC74 0036BC74 CCB00F0C */  jal        func_003ec330
    /* 26BC78 0036BC78 00000000 */   nop
  .L0036BC7C:
    /* 26BC7C 0036BC7C 1000238E */  lw         $3, 0x10($17)
    /* 26BC80 0036BC80 04006330 */  andi       $3, $3, 0x4
    /* 26BC84 0036BC84 0D006010 */  beqz       $3, .L0036BCBC
    /* 26BC88 0036BC88 00000000 */   nop
    /* 26BC8C 0036BC8C 2D800000 */  daddu      $16, $0, $0
    /* 26BC90 0036BC90 07000010 */  b          .L0036BCB0
    /* 26BC94 0036BC94 00000000 */   nop
  .L0036BC98:
    /* 26BC98 0036BC98 80101000 */  sll        $2, $16, 2
    /* 26BC9C 0036BC9C 21102202 */  addu       $2, $17, $2
    /* 26BCA0 0036BCA0 2400448C */  lw         $4, 0x24($2)
    /* 26BCA4 0036BCA4 CCB00F0C */  jal        func_003ec330
    /* 26BCA8 0036BCA8 00000000 */   nop
    /* 26BCAC 0036BCAC 01001026 */  addiu      $16, $16, 0x1
  .L0036BCB0:
    /* 26BCB0 0036BCB0 0700032A */  slti       $3, $16, 0x7
    /* 26BCB4 0036BCB4 F8FF6014 */  bnez       $3, .L0036BC98
    /* 26BCB8 0036BCB8 00000000 */   nop
  .L0036BCBC:
    /* 26BCBC 0036BCBC 1000238E */  lw         $3, 0x10($17)
    /* 26BCC0 0036BCC0 08006330 */  andi       $3, $3, 0x8
    /* 26BCC4 0036BCC4 0D006010 */  beqz       $3, .L0036BCFC
    /* 26BCC8 0036BCC8 00000000 */   nop
    /* 26BCCC 0036BCCC 2D800000 */  daddu      $16, $0, $0
    /* 26BCD0 0036BCD0 07000010 */  b          .L0036BCF0
    /* 26BCD4 0036BCD4 00000000 */   nop
  .L0036BCD8:
    /* 26BCD8 0036BCD8 80101000 */  sll        $2, $16, 2
    /* 26BCDC 0036BCDC 21102202 */  addu       $2, $17, $2
    /* 26BCE0 0036BCE0 4000448C */  lw         $4, 0x40($2)
    /* 26BCE4 0036BCE4 CCB00F0C */  jal        func_003ec330
    /* 26BCE8 0036BCE8 00000000 */   nop
    /* 26BCEC 0036BCEC 01001026 */  addiu      $16, $16, 0x1
  .L0036BCF0:
    /* 26BCF0 0036BCF0 0200032A */  slti       $3, $16, 0x2
    /* 26BCF4 0036BCF4 F8FF6014 */  bnez       $3, .L0036BCD8
    /* 26BCF8 0036BCF8 00000000 */   nop
  .L0036BCFC:
    /* 26BCFC 0036BCFC 2D900000 */  daddu      $18, $0, $0
    /* 26BD00 0036BD00 17000010 */  b          .L0036BD60
    /* 26BD04 0036BD04 00000000 */   nop
  .L0036BD08:
    /* 26BD08 0036BD08 80181200 */  sll        $3, $18, 2
    /* 26BD0C 0036BD0C 21187200 */  addu       $3, $3, $18
    /* 26BD10 0036BD10 80180300 */  sll        $3, $3, 2
    /* 26BD14 0036BD14 21182302 */  addu       $3, $17, $3
    /* 26BD18 0036BD18 54007024 */  addiu      $16, $3, 0x54
    /* 26BD1C 0036BD1C 5400648C */  lw         $4, 0x54($3)
    /* 26BD20 0036BD20 27188000 */  not        $3, $4
    /* 26BD24 0036BD24 01006330 */  andi       $3, $3, 0x1
    /* 26BD28 0036BD28 0C006014 */  bnez       $3, .L0036BD5C
    /* 26BD2C 0036BD2C 00000000 */   nop
    /* 26BD30 0036BD30 02008230 */  andi       $2, $4, 0x2
    /* 26BD34 0036BD34 06004014 */  bnez       $2, .L0036BD50
    /* 26BD38 0036BD38 00000000 */   nop
    /* 26BD3C 0036BD3C 6500043C */  lui        $4, %hi(D_0064E4E0)
    /* 26BD40 0036BD40 E0E48424 */  addiu      $4, $4, %lo(D_0064E4E0)
    /* 26BD44 0036BD44 3F010524 */  addiu      $5, $0, 0x13F
    /* 26BD48 0036BD48 CCB5110C */  jal        func_0046d730
    /* 26BD4C 0036BD4C 00000000 */   nop
  .L0036BD50:
    /* 26BD50 0036BD50 0C00048E */  lw         $4, 0xC($16)
    /* 26BD54 0036BD54 CCB00F0C */  jal        func_003ec330
    /* 26BD58 0036BD58 00000000 */   nop
  .L0036BD5C:
    /* 26BD5C 0036BD5C 01005226 */  addiu      $18, $18, 0x1
  .L0036BD60:
    /* 26BD60 0036BD60 1000432A */  slti       $3, $18, 0x10
    /* 26BD64 0036BD64 E8FF6014 */  bnez       $3, .L0036BD08
    /* 26BD68 0036BD68 00000000 */   nop
    /* 26BD6C 0036BD6C 2D900000 */  daddu      $18, $0, $0
    /* 26BD70 0036BD70 15000010 */  b          .L0036BDC8
    /* 26BD74 0036BD74 00000000 */   nop
  .L0036BD78:
    /* 26BD78 0036BD78 00191200 */  sll        $3, $18, 4
    /* 26BD7C 0036BD7C 21182302 */  addu       $3, $17, $3
    /* 26BD80 0036BD80 94017024 */  addiu      $16, $3, 0x194
    /* 26BD84 0036BD84 9401648C */  lw         $4, 0x194($3)
    /* 26BD88 0036BD88 27188000 */  not        $3, $4
    /* 26BD8C 0036BD8C 01006330 */  andi       $3, $3, 0x1
    /* 26BD90 0036BD90 0C006014 */  bnez       $3, .L0036BDC4
    /* 26BD94 0036BD94 00000000 */   nop
    /* 26BD98 0036BD98 02008230 */  andi       $2, $4, 0x2
    /* 26BD9C 0036BD9C 06004014 */  bnez       $2, .L0036BDB8
    /* 26BDA0 0036BDA0 00000000 */   nop
    /* 26BDA4 0036BDA4 6500043C */  lui        $4, %hi(D_0064E4E0)
    /* 26BDA8 0036BDA8 E0E48424 */  addiu      $4, $4, %lo(D_0064E4E0)
    /* 26BDAC 0036BDAC 48010524 */  addiu      $5, $0, 0x148
    /* 26BDB0 0036BDB0 CCB5110C */  jal        func_0046d730
    /* 26BDB4 0036BDB4 00000000 */   nop
  .L0036BDB8:
    /* 26BDB8 0036BDB8 0800048E */  lw         $4, 0x8($16)
    /* 26BDBC 0036BDBC CCB00F0C */  jal        func_003ec330
    /* 26BDC0 0036BDC0 00000000 */   nop
  .L0036BDC4:
    /* 26BDC4 0036BDC4 01005226 */  addiu      $18, $18, 0x1
  .L0036BDC8:
    /* 26BDC8 0036BDC8 1000432A */  slti       $3, $18, 0x10
    /* 26BDCC 0036BDCC EAFF6014 */  bnez       $3, .L0036BD78
    /* 26BDD0 0036BDD0 00000000 */   nop
    /* 26BDD4 0036BDD4 ACB580AF */  sw         $0, -0x4A54($28)
    /* 26BDD8 0036BDD8 3000BFDF */  ld         $31, 0x30($29)
    /* 26BDDC 0036BDDC 2000B27B */  lq         $18, 0x20($29)
    /* 26BDE0 0036BDE0 1000B17B */  lq         $17, 0x10($29)
    /* 26BDE4 0036BDE4 0000B07B */  lq         $16, 0x0($29)
    /* 26BDE8 0036BDE8 4000BD27 */  addiu      $29, $29, 0x40
    /* 26BDEC 0036BDEC 0800E003 */  jr         $31
    /* 26BDF0 0036BDF0 00000000 */   nop
    /* 26BDF4 0036BDF4 00000000 */  nop
    /* 26BDF8 0036BDF8 00000000 */  nop
    /* 26BDFC 0036BDFC 00000000 */  nop
.size func_0036bbf0, 0x210
