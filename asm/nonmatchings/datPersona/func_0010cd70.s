.section .text
.set noat
.set noreorder
glabel func_0010cd70
    /* CD70 0010CD70 C0FFBD27 */  addiu      $29, $29, -0x40
    /* CD74 0010CD74 3000BFFF */  sd         $31, 0x30($29)
    /* CD78 0010CD78 2000B27F */  sq         $18, 0x20($29)
    /* CD7C 0010CD7C 1000B17F */  sq         $17, 0x10($29)
    /* CD80 0010CD80 0000B07F */  sq         $16, 0x0($29)
    /* CD84 0010CD84 2D888000 */  daddu      $17, $4, $0
    /* CD88 0010CD88 2D90A000 */  daddu      $18, $5, $0
    /* CD8C 0010CD8C 2D80C000 */  daddu      $16, $6, $0
    /* CD90 0010CD90 08002012 */  beqz       $17, .L0010CDB4
    /* CD94 0010CD94 00000000 */   nop
    /* CD98 0010CD98 3C141200 */  dsll32     $2, $18, 16
    /* CD9C 0010CD9C 3F140200 */  dsra32     $2, $2, 16
    /* CDA0 0010CDA0 04004010 */  beqz       $2, .L0010CDB4
    /* CDA4 0010CDA4 00000000 */   nop
    /* CDA8 0010CDA8 FFFF0232 */  andi       $2, $16, 0xFFFF
    /* CDAC 0010CDAC 06004014 */  bnez       $2, .L0010CDC8
    /* CDB0 0010CDB0 00000000 */   nop
  .L0010CDB4:
    /* CDB4 0010CDB4 5E00043C */  lui        $4, %hi(D_005E4318)
    /* CDB8 0010CDB8 18438424 */  addiu      $4, $4, %lo(D_005E4318)
    /* CDBC 0010CDBC FE060524 */  addiu      $5, $0, 0x6FE
    /* CDC0 0010CDC0 CCB5110C */  jal        func_0046d730
    /* CDC4 0010CDC4 00000000 */   nop
  .L0010CDC8:
    /* CDC8 0010CDC8 FFFF4532 */  andi       $5, $18, 0xFFFF
    /* CDCC 0010CDCC 2D202002 */  daddu      $4, $17, $0
    /* CDD0 0010CDD0 8433040C */  jal        func_0010ce10
    /* CDD4 0010CDD4 00000000 */   nop
    /* CDD8 0010CDD8 FFFF0324 */  addiu      $3, $0, -0x1
    /* CDDC 0010CDDC 04004310 */  beq        $2, $3, .L0010CDF0
    /* CDE0 0010CDE0 00000000 */   nop
    /* CDE4 0010CDE4 40180200 */  sll        $3, $2, 1
    /* CDE8 0010CDE8 21187100 */  addu       $3, $3, $17
    /* CDEC 0010CDEC 0C0070A4 */  sh         $16, 0xC($3)
  .L0010CDF0:
    /* CDF0 0010CDF0 3000BFDF */  ld         $31, 0x30($29)
    /* CDF4 0010CDF4 2000B27B */  lq         $18, 0x20($29)
    /* CDF8 0010CDF8 1000B17B */  lq         $17, 0x10($29)
    /* CDFC 0010CDFC 0000B07B */  lq         $16, 0x0($29)
    /* CE00 0010CE00 4000BD27 */  addiu      $29, $29, 0x40
    /* CE04 0010CE04 0800E003 */  jr         $31
    /* CE08 0010CE08 00000000 */   nop
    /* CE0C 0010CE0C 00000000 */  nop
.size func_0010cd70, 0xa0
