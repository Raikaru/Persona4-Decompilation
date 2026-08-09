.section .text
.set noat
.set noreorder
glabel func_0042bf00
    /* 32BF00 0042BF00 80FFBD27 */  addiu      $29, $29, -0x80
    /* 32BF04 0042BF04 7100023C */  lui        $2, %hi(D_0070CA20)
    /* 32BF08 0042BF08 4000B3FF */  sd         $19, 0x40($29)
    /* 32BF0C 0042BF0C 7100033C */  lui        $3, %hi(D_0070D4D8)
    /* 32BF10 0042BF10 20CA538C */  lw         $19, %lo(D_0070CA20)($2)
    /* 32BF14 0042BF14 D8D46724 */  addiu      $7, $3, %lo(D_0070D4D8)
    /* 32BF18 0042BF18 6000B5FF */  sd         $21, 0x60($29)
    /* 32BF1C 0042BF1C 5000B4FF */  sd         $20, 0x50($29)
    /* 32BF20 0042BF20 40006226 */  addiu      $2, $19, 0x40
    /* 32BF24 0042BF24 3000B2FF */  sd         $18, 0x30($29)
    /* 32BF28 0042BF28 2DA84000 */  daddu      $21, $2, $0
    /* 32BF2C 0042BF2C 2000B1FF */  sd         $17, 0x20($29)
    /* 32BF30 0042BF30 2D90A000 */  daddu      $18, $5, $0
    /* 32BF34 0042BF34 1000B0FF */  sd         $16, 0x10($29)
    /* 32BF38 0042BF38 2DA0C000 */  daddu      $20, $6, $0
    /* 32BF3C 0042BF3C 7000BFFF */  sd         $31, 0x70($29)
    /* 32BF40 0042BF40 2D808000 */  daddu      $16, $4, $0
    /* 32BF44 0042BF44 D8D4648C */  lw         $4, %lo(D_0070D4D8)($3)
    /* 32BF48 0042BF48 0400E58C */  lw         $5, 0x4($7)
    /* 32BF4C 0042BF4C BCAF100C */  jal        func_0042bef0
    /* 32BF50 0042BF50 0000A2AF */   sw        $2, 0x0($29)
    /* 32BF54 0042BF54 1000432A */  slti       $3, $18, 0x10
    /* 32BF58 0042BF58 0F000224 */  addiu      $2, $0, 0xF
    /* 32BF5C 0042BF5C 2D206002 */  daddu      $4, $19, $0
    /* 32BF60 0042BF60 0A904300 */  movz       $18, $2, $3
    /* 32BF64 0042BF64 2D28A003 */  daddu      $5, $29, $0
    /* 32BF68 0042BF68 ACAF100C */  jal        func_0042beb0
    /* 32BF6C 0042BF6C 04000624 */   addiu     $6, $0, 0x4
    /* 32BF70 0042BF70 04007326 */  addiu      $19, $19, 0x4
    /* 32BF74 0042BF74 520A110C */  jal        func_00442948
    /* 32BF78 0042BF78 2D200002 */   daddu     $4, $16, $0
    /* 32BF7C 0042BF7C 01005124 */  addiu      $17, $2, 0x1
    /* 32BF80 0042BF80 0000A48F */  lw         $4, 0x0($29)
    /* 32BF84 0042BF84 2D280002 */  daddu      $5, $16, $0
    /* 32BF88 0042BF88 ACAF100C */  jal        func_0042beb0
    /* 32BF8C 0042BF8C 2D302002 */   daddu     $6, $17, $0
    /* 32BF90 0042BF90 0000A38F */  lw         $3, 0x0($29)
    /* 32BF94 0042BF94 21187100 */  addu       $3, $3, $17
    /* 32BF98 0042BF98 1500401A */  blez       $18, .L0042BFF0
    /* 32BF9C 0042BF9C 0000A3AF */   sw        $3, 0x0($29)
    /* 32BFA0 0042BFA0 2D808002 */  daddu      $16, $20, $0
    /* 32BFA4 0042BFA4 00000000 */  nop
  .L0042BFA8:
    /* 32BFA8 0042BFA8 2D206002 */  daddu      $4, $19, $0
    /* 32BFAC 0042BFAC 2D28A003 */  daddu      $5, $29, $0
    /* 32BFB0 0042BFB0 04000624 */  addiu      $6, $0, 0x4
    /* 32BFB4 0042BFB4 ACAF100C */  jal        func_0042beb0
    /* 32BFB8 0042BFB8 04007326 */   addiu     $19, $19, 0x4
    /* 32BFBC 0042BFBC FFFF5226 */  addiu      $18, $18, -0x1
    /* 32BFC0 0042BFC0 520A110C */  jal        func_00442948
    /* 32BFC4 0042BFC4 0000048E */   lw        $4, 0x0($16)
    /* 32BFC8 0042BFC8 01005124 */  addiu      $17, $2, 0x1
    /* 32BFCC 0042BFCC 0000058E */  lw         $5, 0x0($16)
    /* 32BFD0 0042BFD0 0000A48F */  lw         $4, 0x0($29)
    /* 32BFD4 0042BFD4 2D302002 */  daddu      $6, $17, $0
    /* 32BFD8 0042BFD8 ACAF100C */  jal        func_0042beb0
    /* 32BFDC 0042BFDC 04001026 */   addiu     $16, $16, 0x4
    /* 32BFE0 0042BFE0 0000A38F */  lw         $3, 0x0($29)
    /* 32BFE4 0042BFE4 21187100 */  addu       $3, $3, $17
    /* 32BFE8 0042BFE8 EFFF4016 */  bnez       $18, .L0042BFA8
    /* 32BFEC 0042BFEC 0000A3AF */   sw        $3, 0x0($29)
  .L0042BFF0:
    /* 32BFF0 0042BFF0 2D10A002 */  daddu      $2, $21, $0
    /* 32BFF4 0042BFF4 7000BFDF */  ld         $31, 0x70($29)
    /* 32BFF8 0042BFF8 6000B5DF */  ld         $21, 0x60($29)
    /* 32BFFC 0042BFFC 5000B4DF */  ld         $20, 0x50($29)
    /* 32C000 0042C000 4000B3DF */  ld         $19, 0x40($29)
    /* 32C004 0042C004 3000B2DF */  ld         $18, 0x30($29)
    /* 32C008 0042C008 2000B1DF */  ld         $17, 0x20($29)
    /* 32C00C 0042C00C 1000B0DF */  ld         $16, 0x10($29)
    /* 32C010 0042C010 0800E003 */  jr         $31
    /* 32C014 0042C014 8000BD27 */   addiu     $29, $29, 0x80
.size func_0042bf00, 0x118
