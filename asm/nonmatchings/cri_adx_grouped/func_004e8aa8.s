.section .text
.set noat
.set noreorder
glabel func_004e8aa8
    /* 3E8AA8 004E8AA8 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 3E8AAC 004E8AAC 2000B4FF */  sd         $20, 0x20($29)
    /* 3E8AB0 004E8AB0 2DA0E000 */  daddu      $20, $7, $0
    /* 3E8AB4 004E8AB4 0000B0FF */  sd         $16, 0x0($29)
    /* 3E8AB8 004E8AB8 2D800000 */  daddu      $16, $0, $0
    /* 3E8ABC 004E8ABC 1000B2FF */  sd         $18, 0x10($29)
    /* 3E8AC0 004E8AC0 2D90C000 */  daddu      $18, $6, $0
    /* 3E8AC4 004E8AC4 1800B3FF */  sd         $19, 0x18($29)
    /* 3E8AC8 004E8AC8 2D988000 */  daddu      $19, $4, $0
    /* 3E8ACC 004E8ACC 3000B6FF */  sd         $22, 0x30($29)
    /* 3E8AD0 004E8AD0 2DB0A000 */  daddu      $22, $5, $0
    /* 3E8AD4 004E8AD4 0800B1FF */  sd         $17, 0x8($29)
    /* 3E8AD8 004E8AD8 2800B5FF */  sd         $21, 0x28($29)
    /* 3E8ADC 004E8ADC 1800801A */  blez       $20, .L004E8B40
    /* 3E8AE0 004E8AE0 3800BFFF */   sd        $31, 0x38($29)
    /* 3E8AE4 004E8AE4 7300023C */  lui        $2, %hi(D_00734370)
    /* 3E8AE8 004E8AE8 2D884002 */  daddu      $17, $18, $0
    /* 3E8AEC 004E8AEC 70435524 */  addiu      $21, $2, %lo(D_00734370)
  .L004E8AF0:
    /* 3E8AF0 004E8AF0 0C00A28E */  lw         $2, 0xC($21)
    /* 3E8AF4 004E8AF4 2D20C002 */  daddu      $4, $22, $0
    /* 3E8AF8 004E8AF8 0800A58E */  lw         $5, 0x8($21)
    /* 3E8AFC 004E8AFC 18185000 */  mult       $3, $2, $16
    /* 3E8B00 004E8B00 C0280500 */  sll        $5, $5, 3
    /* 3E8B04 004E8B04 21107000 */  addu       $2, $3, $16
    /* 3E8B08 004E8B08 01001026 */  addiu      $16, $16, 0x1
    /* 3E8B0C 004E8B0C 2128A200 */  addu       $5, $5, $2
    /* 3E8B10 004E8B10 0AA1130C */  jal        func_004e8428
    /* 3E8B14 004E8B14 21284502 */   addu      $5, $18, $5
    /* 3E8B18 004E8B18 07004014 */  bnez       $2, .L004E8B38
    /* 3E8B1C 004E8B1C 2A181402 */   slt       $3, $16, $20
    /* 3E8B20 004E8B20 0000228E */  lw         $2, 0x0($17)
    /* 3E8B24 004E8B24 000062AE */  sw         $2, 0x0($19)
    /* 3E8B28 004E8B28 0400238E */  lw         $3, 0x4($17)
    /* 3E8B2C 004E8B2C 06000010 */  b          .L004E8B48
    /* 3E8B30 004E8B30 040063AE */   sw        $3, 0x4($19)
    /* 3E8B34 004E8B34 00000000 */  nop
  .L004E8B38:
    /* 3E8B38 004E8B38 EDFF6014 */  bnez       $3, .L004E8AF0
    /* 3E8B3C 004E8B3C 08003126 */   addiu     $17, $17, 0x8
  .L004E8B40:
    /* 3E8B40 004E8B40 040060AE */  sw         $0, 0x4($19)
    /* 3E8B44 004E8B44 000060AE */  sw         $0, 0x0($19)
  .L004E8B48:
    /* 3E8B48 004E8B48 0000B0DF */  ld         $16, 0x0($29)
    /* 3E8B4C 004E8B4C 0800B1DF */  ld         $17, 0x8($29)
    /* 3E8B50 004E8B50 1000B2DF */  ld         $18, 0x10($29)
    /* 3E8B54 004E8B54 1800B3DF */  ld         $19, 0x18($29)
    /* 3E8B58 004E8B58 2000B4DF */  ld         $20, 0x20($29)
    /* 3E8B5C 004E8B5C 2800B5DF */  ld         $21, 0x28($29)
    /* 3E8B60 004E8B60 3000B6DF */  ld         $22, 0x30($29)
    /* 3E8B64 004E8B64 3800BFDF */  ld         $31, 0x38($29)
    /* 3E8B68 004E8B68 0800E003 */  jr         $31
    /* 3E8B6C 004E8B6C 4000BD27 */   addiu     $29, $29, 0x40
.size func_004e8aa8, 0xc8
