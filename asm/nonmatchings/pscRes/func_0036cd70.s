.section .text
.set noat
.set noreorder
glabel func_0036cd70
    /* 26CD70 0036CD70 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 26CD74 0036CD74 1000BFFF */  sd         $31, 0x10($29)
    /* 26CD78 0036CD78 0000B07F */  sq         $16, 0x0($29)
    /* 26CD7C 0036CD7C 2D808000 */  daddu      $16, $4, $0
    /* 26CD80 0036CD80 ACB5828F */  lw         $2, -0x4A54($28)
    /* 26CD84 0036CD84 06004014 */  bnez       $2, .L0036CDA0
    /* 26CD88 0036CD88 00000000 */   nop
    /* 26CD8C 0036CD8C 6500043C */  lui        $4, %hi(D_0064E4E0)
    /* 26CD90 0036CD90 E0E48424 */  addiu      $4, $4, %lo(D_0064E4E0)
    /* 26CD94 0036CD94 75000524 */  addiu      $5, $0, 0x75
    /* 26CD98 0036CD98 CCB5110C */  jal        func_0046d730
    /* 26CD9C 0036CD9C 00000000 */   nop
  .L0036CDA0:
    /* 26CDA0 0036CDA0 ACB5858F */  lw         $5, -0x4A54($28)
    /* 26CDA4 0036CDA4 2D300000 */  daddu      $6, $0, $0
    /* 26CDA8 0036CDA8 FFFF0432 */  andi       $4, $16, 0xFFFF
    /* 26CDAC 0036CDAC 0C000010 */  b          .L0036CDE0
    /* 26CDB0 0036CDB0 00000000 */   nop
  .L0036CDB4:
    /* 26CDB4 0036CDB4 00110600 */  sll        $2, $6, 4
    /* 26CDB8 0036CDB8 2118A200 */  addu       $3, $5, $2
    /* 26CDBC 0036CDBC 9401628C */  lw         $2, 0x194($3)
    /* 26CDC0 0036CDC0 27104000 */  not        $2, $2
    /* 26CDC4 0036CDC4 01004230 */  andi       $2, $2, 0x1
    /* 26CDC8 0036CDC8 04004014 */  bnez       $2, .L0036CDDC
    /* 26CDCC 0036CDCC 00000000 */   nop
    /* 26CDD0 0036CDD0 98016294 */  lhu        $2, 0x198($3)
    /* 26CDD4 0036CDD4 05004410 */  beq        $2, $4, .L0036CDEC
    /* 26CDD8 0036CDD8 00000000 */   nop
  .L0036CDDC:
    /* 26CDDC 0036CDDC 0100C624 */  addiu      $6, $6, 0x1
  .L0036CDE0:
    /* 26CDE0 0036CDE0 1000C228 */  slti       $2, $6, 0x10
    /* 26CDE4 0036CDE4 F3FF4014 */  bnez       $2, .L0036CDB4
    /* 26CDE8 0036CDE8 00000000 */   nop
  .L0036CDEC:
    /* 26CDEC 0036CDEC 1000C228 */  slti       $2, $6, 0x10
    /* 26CDF0 0036CDF0 1000BFDF */  ld         $31, 0x10($29)
    /* 26CDF4 0036CDF4 0000B07B */  lq         $16, 0x0($29)
    /* 26CDF8 0036CDF8 2000BD27 */  addiu      $29, $29, 0x20
    /* 26CDFC 0036CDFC 0800E003 */  jr         $31
    /* 26CE00 0036CE00 00000000 */   nop
    /* 26CE04 0036CE04 00000000 */  nop
    /* 26CE08 0036CE08 00000000 */  nop
    /* 26CE0C 0036CE0C 00000000 */  nop
.size func_0036cd70, 0xa0
