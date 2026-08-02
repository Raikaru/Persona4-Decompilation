.section .text
.set noat
.set noreorder
glabel func_0010cc20
    /* CC20 0010CC20 D0FFBD27 */  addiu      $29, $29, -0x30
    /* CC24 0010CC24 2000BFFF */  sd         $31, 0x20($29)
    /* CC28 0010CC28 1000B17F */  sq         $17, 0x10($29)
    /* CC2C 0010CC2C 0000B07F */  sq         $16, 0x0($29)
    /* CC30 0010CC30 2D888000 */  daddu      $17, $4, $0
    /* CC34 0010CC34 2D80A000 */  daddu      $16, $5, $0
    /* CC38 0010CC38 04002012 */  beqz       $17, .L0010CC4C
    /* CC3C 0010CC3C 00000000 */   nop
    /* CC40 0010CC40 FFFF0232 */  andi       $2, $16, 0xFFFF
    /* CC44 0010CC44 06004014 */  bnez       $2, .L0010CC60
    /* CC48 0010CC48 00000000 */   nop
  .L0010CC4C:
    /* CC4C 0010CC4C 5E00043C */  lui        $4, %hi(D_005E4318)
    /* CC50 0010CC50 18438424 */  addiu      $4, $4, %lo(D_005E4318)
    /* CC54 0010CC54 E0060524 */  addiu      $5, $0, 0x6E0
    /* CC58 0010CC58 CCB5110C */  jal        func_0046d730
    /* CC5C 0010CC5C 00000000 */   nop
  .L0010CC60:
    /* CC60 0010CC60 2D200000 */  daddu      $4, $0, $0
    /* CC64 0010CC64 0C000010 */  b          .L0010CC98
    /* CC68 0010CC68 00000000 */   nop
  .L0010CC6C:
    /* CC6C 0010CC6C 40100400 */  sll        $2, $4, 1
    /* CC70 0010CC70 21102202 */  addu       $2, $17, $2
    /* CC74 0010CC74 0C004324 */  addiu      $3, $2, 0xC
    /* CC78 0010CC78 0C004294 */  lhu        $2, 0xC($2)
    /* CC7C 0010CC7C 05004014 */  bnez       $2, .L0010CC94
    /* CC80 0010CC80 00000000 */   nop
    /* CC84 0010CC84 000070A4 */  sh         $16, 0x0($3)
    /* CC88 0010CC88 01000224 */  addiu      $2, $0, 0x1
    /* CC8C 0010CC8C 06000010 */  b          .L0010CCA8
    /* CC90 0010CC90 00000000 */   nop
  .L0010CC94:
    /* CC94 0010CC94 01008424 */  addiu      $4, $4, 0x1
  .L0010CC98:
    /* CC98 0010CC98 08008228 */  slti       $2, $4, 0x8
    /* CC9C 0010CC9C F3FF4014 */  bnez       $2, .L0010CC6C
    /* CCA0 0010CCA0 00000000 */   nop
    /* CCA4 0010CCA4 2D100000 */  daddu      $2, $0, $0
  .L0010CCA8:
    /* CCA8 0010CCA8 2000BFDF */  ld         $31, 0x20($29)
    /* CCAC 0010CCAC 1000B17B */  lq         $17, 0x10($29)
    /* CCB0 0010CCB0 0000B07B */  lq         $16, 0x0($29)
    /* CCB4 0010CCB4 3000BD27 */  addiu      $29, $29, 0x30
    /* CCB8 0010CCB8 0800E003 */  jr         $31
    /* CCBC 0010CCBC 00000000 */   nop
.size func_0010cc20, 0xa0
