.section .text
.set noat
.set noreorder
glabel func_001e7ab0
    /* E7AB0 001E7AB0 70FFBD27 */  addiu      $29, $29, -0x90
    /* E7AB4 001E7AB4 5000BFFF */  sd         $31, 0x50($29)
    /* E7AB8 001E7AB8 4000B47F */  sq         $20, 0x40($29)
    /* E7ABC 001E7ABC 3000B37F */  sq         $19, 0x30($29)
    /* E7AC0 001E7AC0 2000B27F */  sq         $18, 0x20($29)
    /* E7AC4 001E7AC4 1000B17F */  sq         $17, 0x10($29)
    /* E7AC8 001E7AC8 0000B07F */  sq         $16, 0x0($29)
    /* E7ACC 001E7ACC 14740A0C */  jal        func_0029d050
    /* E7AD0 001E7AD0 00000000 */   nop
    /* E7AD4 001E7AD4 2DA04000 */  daddu      $20, $2, $0
    /* E7AD8 001E7AD8 2D200000 */  daddu      $4, $0, $0
    /* E7ADC 001E7ADC 00730A0C */  jal        func_0029cc00
    /* E7AE0 001E7AE0 00000000 */   nop
    /* E7AE4 001E7AE4 2D208002 */  daddu      $4, $20, $0
    /* E7AE8 001E7AE8 2D284000 */  daddu      $5, $2, $0
    /* E7AEC 001E7AEC 2D300000 */  daddu      $6, $0, $0
    /* E7AF0 001E7AF0 2C000724 */  addiu      $7, $0, 0x2C
    /* E7AF4 001E7AF4 01000824 */  addiu      $8, $0, 0x1
    /* E7AF8 001E7AF8 1E00093C */  lui        $9, %hi(func_001db5b0)
    /* E7AFC 001E7AFC B0B52925 */  addiu      $9, $9, %lo(func_001db5b0)
    /* E7B00 001E7B00 E86E070C */  jal        func_001dbba0
    /* E7B04 001E7B04 00000000 */   nop
    /* E7B08 001E7B08 01000324 */  addiu      $3, $0, 0x1
    /* E7B0C 001E7B0C 36004314 */  bne        $2, $3, .L001E7BE8
    /* E7B10 001E7B10 00000000 */   nop
    /* E7B14 001E7B14 6A008296 */  lhu        $2, 0x6A($20)
    /* E7B18 001E7B18 04004314 */  bne        $2, $3, .L001E7B2C
    /* E7B1C 001E7B1C 00000000 */   nop
    /* E7B20 001E7B20 3800828E */  lw         $2, 0x38($20)
    /* E7B24 001E7B24 29000010 */  b          .L001E7BCC
    /* E7B28 001E7B28 00000000 */   nop
  .L001E7B2C:
    /* E7B2C 001E7B2C 2D880000 */  daddu      $17, $0, $0
    /* E7B30 001E7B30 2D900000 */  daddu      $18, $0, $0
    /* E7B34 001E7B34 2D980000 */  daddu      $19, $0, $0
    /* E7B38 001E7B38 1A000010 */  b          .L001E7BA4
    /* E7B3C 001E7B3C 00000000 */   nop
  .L001E7B40:
    /* E7B40 001E7B40 80101300 */  sll        $2, $19, 2
    /* E7B44 001E7B44 21108202 */  addu       $2, $20, $2
    /* E7B48 001E7B48 3800508C */  lw         $16, 0x38($2)
    /* E7B4C 001E7B4C 3000028E */  lw         $2, 0x30($16)
    /* E7B50 001E7B50 640A448C */  lw         $4, 0xA64($2)
    /* E7B54 001E7B54 88C7080C */  jal        func_00231e20
    /* E7B58 001E7B58 00000000 */   nop
    /* E7B5C 001E7B5C FF004330 */  andi       $3, $2, 0xFF
    /* E7B60 001E7B60 2B107200 */  sltu       $2, $3, $18
    /* E7B64 001E7B64 0E004014 */  bnez       $2, .L001E7BA0
    /* E7B68 001E7B68 00000000 */   nop
    /* E7B6C 001E7B6C 09007214 */  bne        $3, $18, .L001E7B94
    /* E7B70 001E7B70 00000000 */   nop
    /* E7B74 001E7B74 FFFF2232 */  andi       $2, $17, 0xFFFF
    /* E7B78 001E7B78 80100200 */  sll        $2, $2, 2
    /* E7B7C 001E7B7C 21105D00 */  addu       $2, $2, $29
    /* E7B80 001E7B80 600050AC */  sw         $16, 0x60($2)
    /* E7B84 001E7B84 01002226 */  addiu      $2, $17, 0x1
    /* E7B88 001E7B88 FFFF5130 */  andi       $17, $2, 0xFFFF
    /* E7B8C 001E7B8C 04000010 */  b          .L001E7BA0
    /* E7B90 001E7B90 00000000 */   nop
  .L001E7B94:
    /* E7B94 001E7B94 2D906000 */  daddu      $18, $3, $0
    /* E7B98 001E7B98 6000B0AF */  sw         $16, 0x60($29)
    /* E7B9C 001E7B9C 01001164 */  daddiu     $17, $0, 0x1
  .L001E7BA0:
    /* E7BA0 001E7BA0 01007326 */  addiu      $19, $19, 0x1
  .L001E7BA4:
    /* E7BA4 001E7BA4 6A008296 */  lhu        $2, 0x6A($20)
    /* E7BA8 001E7BA8 2B106202 */  sltu       $2, $19, $2
    /* E7BAC 001E7BAC E4FF4014 */  bnez       $2, .L001E7B40
    /* E7BB0 001E7BB0 00000000 */   nop
    /* E7BB4 001E7BB4 FFFF2432 */  andi       $4, $17, 0xFFFF
    /* E7BB8 001E7BB8 5CC7080C */  jal        func_00231d70
    /* E7BBC 001E7BBC 00000000 */   nop
    /* E7BC0 001E7BC0 80100200 */  sll        $2, $2, 2
    /* E7BC4 001E7BC4 21105D00 */  addu       $2, $2, $29
    /* E7BC8 001E7BC8 6000428C */  lw         $2, 0x60($2)
  .L001E7BCC:
    /* E7BCC 001E7BCC 0800438C */  lw         $3, 0x8($2)
    /* E7BD0 001E7BD0 0080023C */  lui        $2, (0x80000000 >> 16)
    /* E7BD4 001E7BD4 25206200 */  or         $4, $3, $2
    /* E7BD8 001E7BD8 D4730A0C */  jal        func_0029cf50
    /* E7BDC 001E7BDC 00000000 */   nop
    /* E7BE0 001E7BE0 04000010 */  b          .L001E7BF4
    /* E7BE4 001E7BE4 00000000 */   nop
  .L001E7BE8:
    /* E7BE8 001E7BE8 FFFF0424 */  addiu      $4, $0, -0x1
    /* E7BEC 001E7BEC D4730A0C */  jal        func_0029cf50
    /* E7BF0 001E7BF0 00000000 */   nop
  .L001E7BF4:
    /* E7BF4 001E7BF4 FFFF0224 */  addiu      $2, $0, -0x1
    /* E7BF8 001E7BF8 5000BFDF */  ld         $31, 0x50($29)
    /* E7BFC 001E7BFC 4000B47B */  lq         $20, 0x40($29)
    /* E7C00 001E7C00 3000B37B */  lq         $19, 0x30($29)
    /* E7C04 001E7C04 2000B27B */  lq         $18, 0x20($29)
    /* E7C08 001E7C08 1000B17B */  lq         $17, 0x10($29)
    /* E7C0C 001E7C0C 0000B07B */  lq         $16, 0x0($29)
    /* E7C10 001E7C10 9000BD27 */  addiu      $29, $29, 0x90
    /* E7C14 001E7C14 0800E003 */  jr         $31
    /* E7C18 001E7C18 00000000 */   nop
    /* E7C1C 001E7C1C 00000000 */  nop
.size func_001e7ab0, 0x170
