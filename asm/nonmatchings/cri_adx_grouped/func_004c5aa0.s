.section .text
.set noat
.set noreorder
glabel func_004c5aa0
    /* 3C5AA0 004C5AA0 B0FFBD27 */  addiu      $29, $29, -0x50
    /* 3C5AA4 004C5AA4 3000B0FF */  sd         $16, 0x30($29)
    /* 3C5AA8 004C5AA8 2D80C000 */  daddu      $16, $6, $0
    /* 3C5AAC 004C5AAC 3800B1FF */  sd         $17, 0x38($29)
    /* 3C5AB0 004C5AB0 2D880001 */  daddu      $17, $8, $0
    /* 3C5AB4 004C5AB4 4000B2FF */  sd         $18, 0x40($29)
    /* 3C5AB8 004C5AB8 2D90E000 */  daddu      $18, $7, $0
    /* 3C5ABC 004C5ABC 1400A227 */  addiu      $2, $29, 0x14
    /* 3C5AC0 004C5AC0 1200A827 */  addiu      $8, $29, 0x12
    /* 3C5AC4 004C5AC4 1000A727 */  addiu      $7, $29, 0x10
    /* 3C5AC8 004C5AC8 1800A627 */  addiu      $6, $29, 0x18
    /* 3C5ACC 004C5ACC 1C00A927 */  addiu      $9, $29, 0x1C
    /* 3C5AD0 004C5AD0 2000AA27 */  addiu      $10, $29, 0x20
    /* 3C5AD4 004C5AD4 2400AB27 */  addiu      $11, $29, 0x24
    /* 3C5AD8 004C5AD8 4800BFFF */  sd         $31, 0x48($29)
    /* 3C5ADC 004C5ADC DA16130C */  jal        func_004c5b68
    /* 3C5AE0 004C5AE0 0000A2AF */   sw        $2, 0x0($29)
    /* 3C5AE4 004C5AE4 1000A487 */  lh         $4, 0x10($29)
    /* 3C5AE8 004C5AE8 01000324 */  addiu      $3, $0, 0x1
    /* 3C5AEC 004C5AEC 2D100000 */  daddu      $2, $0, $0
    /* 3C5AF0 004C5AF0 03008310 */  beq        $4, $3, .L004C5B00
    /* 3C5AF4 004C5AF4 1000A597 */   lhu       $5, 0x10($29)
    /* 3C5AF8 004C5AF8 1000A0A7 */  sh         $0, 0x10($29)
    /* 3C5AFC 004C5AFC 2D280000 */  daddu      $5, $0, $0
  .L004C5B00:
    /* 3C5B00 004C5B00 1100A010 */  beqz       $5, .L004C5B48
    /* 3C5B04 004C5B04 000005A6 */   sh        $5, 0x0($16)
    /* 3C5B08 004C5B08 1800A58F */  lw         $5, 0x18($29)
    /* 3C5B0C 004C5B0C 1C00A68F */  lw         $6, 0x1C($29)
    /* 3C5B10 004C5B10 0000A428 */  slti       $4, $5, 0x0
    /* 3C5B14 004C5B14 FF07A824 */  addiu      $8, $5, 0x7FF
    /* 3C5B18 004C5B18 2D18A000 */  daddu      $3, $5, $0
    /* 3C5B1C 004C5B1C 2400A78F */  lw         $7, 0x24($29)
    /* 3C5B20 004C5B20 0B180401 */  movn       $3, $8, $4
    /* 3C5B24 004C5B24 C31A0300 */  sra        $3, $3, 11
    /* 3C5B28 004C5B28 C0220300 */  sll        $4, $3, 11
    /* 3C5B2C 004C5B2C 2318A400 */  subu       $3, $5, $4
    /* 3C5B30 004C5B30 2338E300 */  subu       $7, $7, $3
    /* 3C5B34 004C5B34 2330C300 */  subu       $6, $6, $3
    /* 3C5B38 004C5B38 000046AE */  sw         $6, 0x0($18)
    /* 3C5B3C 004C5B3C 04000010 */  b          .L004C5B50
    /* 3C5B40 004C5B40 000027AE */   sw        $7, 0x0($17)
    /* 3C5B44 004C5B44 00000000 */  nop
  .L004C5B48:
    /* 3C5B48 004C5B48 000020AE */  sw         $0, 0x0($17)
    /* 3C5B4C 004C5B4C 000040AE */  sw         $0, 0x0($18)
  .L004C5B50:
    /* 3C5B50 004C5B50 3000B0DF */  ld         $16, 0x30($29)
    /* 3C5B54 004C5B54 3800B1DF */  ld         $17, 0x38($29)
    /* 3C5B58 004C5B58 4000B2DF */  ld         $18, 0x40($29)
    /* 3C5B5C 004C5B5C 4800BFDF */  ld         $31, 0x48($29)
    /* 3C5B60 004C5B60 0800E003 */  jr         $31
    /* 3C5B64 004C5B64 5000BD27 */   addiu     $29, $29, 0x50
.size func_004c5aa0, 0xc8
