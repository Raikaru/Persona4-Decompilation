.section .text
.set noat
.set noreorder
glabel func_001e2a80
    /* E2A80 001E2A80 80FFBD27 */  addiu      $29, $29, -0x80
    /* E2A84 001E2A84 7000BFFF */  sd         $31, 0x70($29)
    /* E2A88 001E2A88 6000B67F */  sq         $22, 0x60($29)
    /* E2A8C 001E2A8C 5000B57F */  sq         $21, 0x50($29)
    /* E2A90 001E2A90 4000B47F */  sq         $20, 0x40($29)
    /* E2A94 001E2A94 3000B37F */  sq         $19, 0x30($29)
    /* E2A98 001E2A98 2000B27F */  sq         $18, 0x20($29)
    /* E2A9C 001E2A9C 1000B17F */  sq         $17, 0x10($29)
    /* E2AA0 001E2AA0 0000B07F */  sq         $16, 0x0($29)
    /* E2AA4 001E2AA4 14740A0C */  jal        func_0029d050
    /* E2AA8 001E2AA8 00000000 */   nop
    /* E2AAC 001E2AAC 3000428C */  lw         $2, 0x30($2)
    /* E2AB0 001E2AB0 A2004290 */  lbu        $2, 0xA2($2)
    /* E2AB4 001E2AB4 04004014 */  bnez       $2, .L001E2AC8
    /* E2AB8 001E2AB8 00000000 */   nop
    /* E2ABC 001E2ABC 01000224 */  addiu      $2, $0, 0x1
    /* E2AC0 001E2AC0 02000010 */  b          .L001E2ACC
    /* E2AC4 001E2AC4 00000000 */   nop
  .L001E2AC8:
    /* E2AC8 001E2AC8 2D100000 */  daddu      $2, $0, $0
  .L001E2ACC:
    /* E2ACC 001E2ACC FFFF4330 */  andi       $3, $2, 0xFFFF
    /* E2AD0 001E2AD0 01000224 */  addiu      $2, $0, 0x1
    /* E2AD4 001E2AD4 04106200 */  sllv       $2, $2, $3
    /* E2AD8 001E2AD8 FFFF5430 */  andi       $20, $2, 0xFFFF
    /* E2ADC 001E2ADC 2D200000 */  daddu      $4, $0, $0
    /* E2AE0 001E2AE0 00730A0C */  jal        func_0029cc00
    /* E2AE4 001E2AE4 00000000 */   nop
    /* E2AE8 001E2AE8 FFFF5330 */  andi       $19, $2, 0xFFFF
    /* E2AEC 001E2AEC 01000424 */  addiu      $4, $0, 0x1
    /* E2AF0 001E2AF0 00730A0C */  jal        func_0029cc00
    /* E2AF4 001E2AF4 00000000 */   nop
    /* E2AF8 001E2AF8 2DB04000 */  daddu      $22, $2, $0
    /* E2AFC 001E2AFC 2D880000 */  daddu      $17, $0, $0
    /* E2B00 001E2B00 2D800000 */  daddu      $16, $0, $0
    /* E2B04 001E2B04 ACB3828F */  lw         $2, -0x4C54($28)
    /* E2B08 001E2B08 7401528C */  lw         $18, 0x174($2)
    /* E2B0C 001E2B0C FFFF9532 */  andi       $21, $20, 0xFFFF
    /* E2B10 001E2B10 FFFF7432 */  andi       $20, $19, 0xFFFF
    /* E2B14 001E2B14 23000010 */  b          .L001E2BA4
    /* E2B18 001E2B18 00000000 */   nop
  .L001E2B1C:
    /* E2B1C 001E2B1C 1A004396 */  lhu        $3, 0x1A($18)
    /* E2B20 001E2B20 01006230 */  andi       $2, $3, 0x1
    /* E2B24 001E2B24 1E004010 */  beqz       $2, .L001E2BA0
    /* E2B28 001E2B28 00000000 */   nop
    /* E2B2C 001E2B2C 08006230 */  andi       $2, $3, 0x8
    /* E2B30 001E2B30 1B004010 */  beqz       $2, .L001E2BA0
    /* E2B34 001E2B34 00000000 */   nop
    /* E2B38 001E2B38 3000538E */  lw         $19, 0x30($18)
    /* E2B3C 001E2B3C A2006392 */  lbu        $3, 0xA2($19)
    /* E2B40 001E2B40 01000224 */  addiu      $2, $0, 0x1
    /* E2B44 001E2B44 04106200 */  sllv       $2, $2, $3
    /* E2B48 001E2B48 2410A202 */  and        $2, $21, $2
    /* E2B4C 001E2B4C 14004010 */  beqz       $2, .L001E2BA0
    /* E2B50 001E2B50 00000000 */   nop
    /* E2B54 001E2B54 A4006296 */  lhu        $2, 0xA4($19)
    /* E2B58 001E2B58 11005414 */  bne        $2, $20, .L001E2BA0
    /* E2B5C 001E2B5C 00000000 */   nop
    /* E2B60 001E2B60 640A648E */  lw         $4, 0xA64($19)
    /* E2B64 001E2B64 2D280000 */  daddu      $5, $0, $0
    /* E2B68 001E2B68 3C0A090C */  jal        func_002428f0
    /* E2B6C 001E2B6C 00000000 */   nop
    /* E2B70 001E2B70 0B004014 */  bnez       $2, .L001E2BA0
    /* E2B74 001E2B74 00000000 */   nop
    /* E2B78 001E2B78 01002226 */  addiu      $2, $17, 0x1
    /* E2B7C 001E2B7C FFFF5130 */  andi       $17, $2, 0xFFFF
    /* E2B80 001E2B80 640A648E */  lw         $4, 0xA64($19)
    /* E2B84 001E2B84 2D28C002 */  daddu      $5, $22, $0
    /* E2B88 001E2B88 30D0080C */  jal        func_002340c0
    /* E2B8C 001E2B8C 00000000 */   nop
    /* E2B90 001E2B90 03004010 */  beqz       $2, .L001E2BA0
    /* E2B94 001E2B94 00000000 */   nop
    /* E2B98 001E2B98 01000226 */  addiu      $2, $16, 0x1
    /* E2B9C 001E2B9C FFFF5030 */  andi       $16, $2, 0xFFFF
  .L001E2BA0:
    /* E2BA0 001E2BA0 5004528E */  lw         $18, 0x450($18)
  .L001E2BA4:
    /* E2BA4 001E2BA4 DDFF4016 */  bnez       $18, .L001E2B1C
    /* E2BA8 001E2BA8 00000000 */   nop
    /* E2BAC 001E2BAC 2D200000 */  daddu      $4, $0, $0
    /* E2BB0 001E2BB0 FFFF2332 */  andi       $3, $17, 0xFFFF
    /* E2BB4 001E2BB4 05006018 */  blez       $3, .L001E2BCC
    /* E2BB8 001E2BB8 00000000 */   nop
    /* E2BBC 001E2BBC FFFF0232 */  andi       $2, $16, 0xFFFF
    /* E2BC0 001E2BC0 02006214 */  bne        $3, $2, .L001E2BCC
    /* E2BC4 001E2BC4 00000000 */   nop
    /* E2BC8 001E2BC8 01000424 */  addiu      $4, $0, 0x1
  .L001E2BCC:
    /* E2BCC 001E2BCC 2B200400 */  sltu       $4, $0, $4
    /* E2BD0 001E2BD0 D4730A0C */  jal        func_0029cf50
    /* E2BD4 001E2BD4 00000000 */   nop
    /* E2BD8 001E2BD8 01000224 */  addiu      $2, $0, 0x1
    /* E2BDC 001E2BDC 7000BFDF */  ld         $31, 0x70($29)
    /* E2BE0 001E2BE0 6000B67B */  lq         $22, 0x60($29)
    /* E2BE4 001E2BE4 5000B57B */  lq         $21, 0x50($29)
    /* E2BE8 001E2BE8 4000B47B */  lq         $20, 0x40($29)
    /* E2BEC 001E2BEC 3000B37B */  lq         $19, 0x30($29)
    /* E2BF0 001E2BF0 2000B27B */  lq         $18, 0x20($29)
    /* E2BF4 001E2BF4 1000B17B */  lq         $17, 0x10($29)
    /* E2BF8 001E2BF8 0000B07B */  lq         $16, 0x0($29)
    /* E2BFC 001E2BFC 8000BD27 */  addiu      $29, $29, 0x80
    /* E2C00 001E2C00 0800E003 */  jr         $31
    /* E2C04 001E2C04 00000000 */   nop
    /* E2C08 001E2C08 00000000 */  nop
    /* E2C0C 001E2C0C 00000000 */  nop
.size func_001e2a80, 0x190
