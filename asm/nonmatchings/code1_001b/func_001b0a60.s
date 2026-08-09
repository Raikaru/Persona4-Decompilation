.section .text
.set noat
.set noreorder
glabel func_001b0a60
    /* B0A60 001B0A60 C0FFBD27 */  addiu      $29, $29, -0x40
    /* B0A64 001B0A64 3000BFFF */  sd         $31, 0x30($29)
    /* B0A68 001B0A68 2000B27F */  sq         $18, 0x20($29)
    /* B0A6C 001B0A6C 1000B17F */  sq         $17, 0x10($29)
    /* B0A70 001B0A70 0000B07F */  sq         $16, 0x0($29)
    /* B0A74 001B0A74 ACB3838F */  lw         $3, -0x4C54($28)
    /* B0A78 001B0A78 7401728C */  lw         $18, 0x174($3)
    /* B0A7C 001B0A7C 53000010 */  b          .L001B0BCC
    /* B0A80 001B0A80 00000000 */   nop
  .L001B0A84:
    /* B0A84 001B0A84 5004518E */  lw         $17, 0x450($18)
    /* B0A88 001B0A88 01001024 */  addiu      $16, $0, 0x1
    /* B0A8C 001B0A8C 0E004396 */  lhu        $3, 0xE($18)
    /* B0A90 001B0A90 1C006010 */  beqz       $3, .L001B0B04
    /* B0A94 001B0A94 00000000 */   nop
    /* B0A98 001B0A98 12004396 */  lhu        $3, 0x12($18)
    /* B0A9C 001B0A9C 19006018 */  blez       $3, .L001B0B04
    /* B0AA0 001B0AA0 00000000 */   nop
    /* B0AA4 001B0AA4 FFFF6324 */  addiu      $3, $3, -0x1
    /* B0AA8 001B0AA8 120043A6 */  sh         $3, 0x12($18)
    /* B0AAC 001B0AAC FFFF6330 */  andi       $3, $3, 0xFFFF
    /* B0AB0 001B0AB0 13006014 */  bnez       $3, .L001B0B00
    /* B0AB4 001B0AB4 00000000 */   nop
    /* B0AB8 001B0AB8 0E004396 */  lhu        $3, 0xE($18)
    /* B0ABC 001B0ABC 0C004296 */  lhu        $2, 0xC($18)
    /* B0AC0 001B0AC0 100042A6 */  sh         $2, 0x10($18)
    /* B0AC4 001B0AC4 0C0043A6 */  sh         $3, 0xC($18)
    /* B0AC8 001B0AC8 1C0040AE */  sw         $0, 0x1C($18)
    /* B0ACC 001B0ACC 2D204002 */  daddu      $4, $18, $0
    /* B0AD0 001B0AD0 40100300 */  sll        $2, $3, 1
    /* B0AD4 001B0AD4 21104300 */  addu       $2, $2, $3
    /* B0AD8 001B0AD8 80180200 */  sll        $3, $2, 2
    /* B0ADC 001B0ADC 5F00023C */  lui        $2, %hi(D_005F6E20)
    /* B0AE0 001B0AE0 206E4224 */  addiu      $2, $2, %lo(D_005F6E20)
    /* B0AE4 001B0AE4 21104300 */  addu       $2, $2, $3
    /* B0AE8 001B0AE8 0000428C */  lw         $2, 0x0($2)
    /* B0AEC 001B0AEC 09F84000 */  jalr       $2
    /* B0AF0 001B0AF0 00000000 */   nop
    /* B0AF4 001B0AF4 0E0040A6 */  sh         $0, 0xE($18)
    /* B0AF8 001B0AF8 02000010 */  b          .L001B0B04
    /* B0AFC 001B0AFC 00000000 */   nop
  .L001B0B00:
    /* B0B00 001B0B00 2D800000 */  daddu      $16, $0, $0
  .L001B0B04:
    /* B0B04 001B0B04 30000012 */  beqz       $16, .L001B0BC8
    /* B0B08 001B0B08 00000000 */   nop
    /* B0B0C 001B0B0C 1A004496 */  lhu        $4, 0x1A($18)
    /* B0B10 001B0B10 04008330 */  andi       $3, $4, 0x4
    /* B0B14 001B0B14 2C006014 */  bnez       $3, .L001B0BC8
    /* B0B18 001B0B18 00000000 */   nop
    /* B0B1C 001B0B1C 18004396 */  lhu        $3, 0x18($18)
    /* B0B20 001B0B20 01006330 */  andi       $3, $3, 0x1
    /* B0B24 001B0B24 11006010 */  beqz       $3, .L001B0B6C
    /* B0B28 001B0B28 00000000 */   nop
    /* B0B2C 001B0B2C 2D204002 */  daddu      $4, $18, $0
    /* B0B30 001B0B30 0C004396 */  lhu        $3, 0xC($18)
    /* B0B34 001B0B34 40100300 */  sll        $2, $3, 1
    /* B0B38 001B0B38 21104300 */  addu       $2, $2, $3
    /* B0B3C 001B0B3C 80180200 */  sll        $3, $2, 2
    /* B0B40 001B0B40 5F00023C */  lui        $2, %hi(D_005F6E20)
    /* B0B44 001B0B44 206E4224 */  addiu      $2, $2, %lo(D_005F6E20)
    /* B0B48 001B0B48 21104300 */  addu       $2, $2, $3
    /* B0B4C 001B0B4C 0400428C */  lw         $2, 0x4($2)
    /* B0B50 001B0B50 09F84000 */  jalr       $2
    /* B0B54 001B0B54 00000000 */   nop
    /* B0B58 001B0B58 1C00438E */  lw         $3, 0x1C($18)
    /* B0B5C 001B0B5C 02006324 */  addiu      $3, $3, 0x2
    /* B0B60 001B0B60 1C0043AE */  sw         $3, 0x1C($18)
    /* B0B64 001B0B64 18000010 */  b          .L001B0BC8
    /* B0B68 001B0B68 00000000 */   nop
  .L001B0B6C:
    /* B0B6C 001B0B6C 02008330 */  andi       $3, $4, 0x2
    /* B0B70 001B0B70 15006010 */  beqz       $3, .L001B0BC8
    /* B0B74 001B0B74 00000000 */   nop
    /* B0B78 001B0B78 5004438E */  lw         $3, 0x450($18)
    /* B0B7C 001B0B7C 03006010 */  beqz       $3, .L001B0B8C
    /* B0B80 001B0B80 00000000 */   nop
    /* B0B84 001B0B84 4C04428E */  lw         $2, 0x44C($18)
    /* B0B88 001B0B88 4C0462AC */  sw         $2, 0x44C($3)
  .L001B0B8C:
    /* B0B8C 001B0B8C 4C04438E */  lw         $3, 0x44C($18)
    /* B0B90 001B0B90 05006010 */  beqz       $3, .L001B0BA8
    /* B0B94 001B0B94 00000000 */   nop
    /* B0B98 001B0B98 5004428E */  lw         $2, 0x450($18)
    /* B0B9C 001B0B9C 500462AC */  sw         $2, 0x450($3)
    /* B0BA0 001B0BA0 04000010 */  b          .L001B0BB4
    /* B0BA4 001B0BA4 00000000 */   nop
  .L001B0BA8:
    /* B0BA8 001B0BA8 5004438E */  lw         $3, 0x450($18)
    /* B0BAC 001B0BAC ACB3828F */  lw         $2, -0x4C54($28)
    /* B0BB0 001B0BB0 740143AC */  sw         $3, 0x174($2)
  .L001B0BB4:
    /* B0BB4 001B0BB4 2D204002 */  daddu      $4, $18, $0
    /* B0BB8 001B0BB8 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* B0BBC 001B0BBC EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* B0BC0 001B0BC0 09F84000 */  jalr       $2
    /* B0BC4 001B0BC4 00000000 */   nop
  .L001B0BC8:
    /* B0BC8 001B0BC8 2D902002 */  daddu      $18, $17, $0
  .L001B0BCC:
    /* B0BCC 001B0BCC ADFF4016 */  bnez       $18, .L001B0A84
    /* B0BD0 001B0BD0 00000000 */   nop
    /* B0BD4 001B0BD4 3000BFDF */  ld         $31, 0x30($29)
    /* B0BD8 001B0BD8 2000B27B */  lq         $18, 0x20($29)
    /* B0BDC 001B0BDC 1000B17B */  lq         $17, 0x10($29)
    /* B0BE0 001B0BE0 0000B07B */  lq         $16, 0x0($29)
    /* B0BE4 001B0BE4 4000BD27 */  addiu      $29, $29, 0x40
    /* B0BE8 001B0BE8 0800E003 */  jr         $31
    /* B0BEC 001B0BEC 00000000 */   nop
.size func_001b0a60, 0x190
