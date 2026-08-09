.section .text
.set noat
.set noreorder
glabel func_001e8a80
    /* E8A80 001E8A80 A0FFBD27 */  addiu      $29, $29, -0x60
    /* E8A84 001E8A84 5000BFFF */  sd         $31, 0x50($29)
    /* E8A88 001E8A88 4000B47F */  sq         $20, 0x40($29)
    /* E8A8C 001E8A8C 3000B37F */  sq         $19, 0x30($29)
    /* E8A90 001E8A90 2000B27F */  sq         $18, 0x20($29)
    /* E8A94 001E8A94 1000B17F */  sq         $17, 0x10($29)
    /* E8A98 001E8A98 0000B07F */  sq         $16, 0x0($29)
    /* E8A9C 001E8A9C 14740A0C */  jal        func_0029d050
    /* E8AA0 001E8AA0 00000000 */   nop
    /* E8AA4 001E8AA4 2DA04000 */  daddu      $20, $2, $0
    /* E8AA8 001E8AA8 2D200000 */  daddu      $4, $0, $0
    /* E8AAC 001E8AAC 00730A0C */  jal        func_0029cc00
    /* E8AB0 001E8AB0 00000000 */   nop
    /* E8AB4 001E8AB4 2D208002 */  daddu      $4, $20, $0
    /* E8AB8 001E8AB8 2D284000 */  daddu      $5, $2, $0
    /* E8ABC 001E8ABC 2D300000 */  daddu      $6, $0, $0
    /* E8AC0 001E8AC0 2F000724 */  addiu      $7, $0, 0x2F
    /* E8AC4 001E8AC4 2D400000 */  daddu      $8, $0, $0
    /* E8AC8 001E8AC8 1E00093C */  lui        $9, %hi(func_001da2f0)
    /* E8ACC 001E8ACC F0A22925 */  addiu      $9, $9, %lo(func_001da2f0)
    /* E8AD0 001E8AD0 E86E070C */  jal        func_001dbba0
    /* E8AD4 001E8AD4 00000000 */   nop
    /* E8AD8 001E8AD8 01000324 */  addiu      $3, $0, 0x1
    /* E8ADC 001E8ADC 25004314 */  bne        $2, $3, .L001E8B74
    /* E8AE0 001E8AE0 00000000 */   nop
    /* E8AE4 001E8AE4 6A008296 */  lhu        $2, 0x6A($20)
    /* E8AE8 001E8AE8 04004314 */  bne        $2, $3, .L001E8AFC
    /* E8AEC 001E8AEC 00000000 */   nop
    /* E8AF0 001E8AF0 3800938E */  lw         $19, 0x38($20)
    /* E8AF4 001E8AF4 18000010 */  b          .L001E8B58
    /* E8AF8 001E8AF8 00000000 */   nop
  .L001E8AFC:
    /* E8AFC 001E8AFC 2D980000 */  daddu      $19, $0, $0
    /* E8B00 001E8B00 2D800000 */  daddu      $16, $0, $0
    /* E8B04 001E8B04 2D880000 */  daddu      $17, $0, $0
    /* E8B08 001E8B08 0F000010 */  b          .L001E8B48
    /* E8B0C 001E8B0C 00000000 */   nop
  .L001E8B10:
    /* E8B10 001E8B10 80101100 */  sll        $2, $17, 2
    /* E8B14 001E8B14 21108202 */  addu       $2, $20, $2
    /* E8B18 001E8B18 3800528C */  lw         $18, 0x38($2)
    /* E8B1C 001E8B1C 3000428E */  lw         $2, 0x30($18)
    /* E8B20 001E8B20 640A448C */  lw         $4, 0xA64($2)
    /* E8B24 001E8B24 B4C7080C */  jal        func_00231ed0
    /* E8B28 001E8B28 00000000 */   nop
    /* E8B2C 001E8B2C FFFF4330 */  andi       $3, $2, 0xFFFF
    /* E8B30 001E8B30 2B107000 */  sltu       $2, $3, $16
    /* E8B34 001E8B34 03004014 */  bnez       $2, .L001E8B44
    /* E8B38 001E8B38 00000000 */   nop
    /* E8B3C 001E8B3C 2D984002 */  daddu      $19, $18, $0
    /* E8B40 001E8B40 2D806000 */  daddu      $16, $3, $0
  .L001E8B44:
    /* E8B44 001E8B44 01003126 */  addiu      $17, $17, 0x1
  .L001E8B48:
    /* E8B48 001E8B48 6A008296 */  lhu        $2, 0x6A($20)
    /* E8B4C 001E8B4C 2B102202 */  sltu       $2, $17, $2
    /* E8B50 001E8B50 EFFF4014 */  bnez       $2, .L001E8B10
    /* E8B54 001E8B54 00000000 */   nop
  .L001E8B58:
    /* E8B58 001E8B58 0800638E */  lw         $3, 0x8($19)
    /* E8B5C 001E8B5C 0080023C */  lui        $2, (0x80000000 >> 16)
    /* E8B60 001E8B60 25206200 */  or         $4, $3, $2
    /* E8B64 001E8B64 D4730A0C */  jal        func_0029cf50
    /* E8B68 001E8B68 00000000 */   nop
    /* E8B6C 001E8B6C 04000010 */  b          .L001E8B80
    /* E8B70 001E8B70 00000000 */   nop
  .L001E8B74:
    /* E8B74 001E8B74 FFFF0424 */  addiu      $4, $0, -0x1
    /* E8B78 001E8B78 D4730A0C */  jal        func_0029cf50
    /* E8B7C 001E8B7C 00000000 */   nop
  .L001E8B80:
    /* E8B80 001E8B80 01000224 */  addiu      $2, $0, 0x1
    /* E8B84 001E8B84 5000BFDF */  ld         $31, 0x50($29)
    /* E8B88 001E8B88 4000B47B */  lq         $20, 0x40($29)
    /* E8B8C 001E8B8C 3000B37B */  lq         $19, 0x30($29)
    /* E8B90 001E8B90 2000B27B */  lq         $18, 0x20($29)
    /* E8B94 001E8B94 1000B17B */  lq         $17, 0x10($29)
    /* E8B98 001E8B98 0000B07B */  lq         $16, 0x0($29)
    /* E8B9C 001E8B9C 6000BD27 */  addiu      $29, $29, 0x60
    /* E8BA0 001E8BA0 0800E003 */  jr         $31
    /* E8BA4 001E8BA4 00000000 */   nop
    /* E8BA8 001E8BA8 00000000 */  nop
    /* E8BAC 001E8BAC 00000000 */  nop
.size func_001e8a80, 0x130
