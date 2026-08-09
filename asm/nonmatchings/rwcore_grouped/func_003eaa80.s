.section .text
.set noat
.set noreorder
glabel func_003eaa80
    /* 2EAA80 003EAA80 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 2EAA84 003EAA84 8800023C */  lui        $2, %hi(D_008873D4)
    /* 2EAA88 003EAA88 2000BFFF */  sd         $31, 0x20($29)
    /* 2EAA8C 003EAA8C 1000B17F */  sq         $17, 0x10($29)
    /* 2EAA90 003EAA90 0000B07F */  sq         $16, 0x0($29)
    /* 2EAA94 003EAA94 D473428C */  lw         $2, %lo(D_008873D4)($2)
    /* 2EAA98 003EAA98 09F84000 */  jalr       $2
    /* 2EAA9C 003EAA9C 2D888000 */   daddu     $17, $4, $0
    /* 2EAAA0 003EAAA0 C8B7838F */  lw         $3, -0x4838($28)
    /* 2EAAA4 003EAAA4 01005024 */  addiu      $16, $2, 0x1
    /* 2EAAA8 003EAAA8 8800023C */  lui        $2, %hi(D_008872E0)
    /* 2EAAAC 003EAAAC E0724224 */  addiu      $2, $2, %lo(D_008872E0)
    /* 2EAAB0 003EAAB0 21184300 */  addu       $3, $2, $3
    /* 2EAAB4 003EAAB4 0800628C */  lw         $2, 0x8($3)
    /* 2EAAB8 003EAAB8 2A085000 */  slt        $1, $2, $16
    /* 2EAABC 003EAABC 10002010 */  beqz       $1, .L003EAB00
    /* 2EAAC0 003EAAC0 00000000 */   nop
    /* 2EAAC4 003EAAC4 0400648C */  lw         $4, 0x4($3)
    /* 2EAAC8 003EAAC8 8800023C */  lui        $2, %hi(D_008873F0)
    /* 2EAACC 003EAACC F073428C */  lw         $2, %lo(D_008873F0)($2)
    /* 2EAAD0 003EAAD0 2D280002 */  daddu      $5, $16, $0
    /* 2EAAD4 003EAAD4 0401033C */  lui        $3, (0x1040406 >> 16)
    /* 2EAAD8 003EAAD8 09F84000 */  jalr       $2
    /* 2EAADC 003EAADC 06046634 */   ori       $6, $3, (0x1040406 & 0xFFFF)
    /* 2EAAE0 003EAAE0 11004010 */  beqz       $2, .L003EAB28
    /* 2EAAE4 003EAAE4 00000000 */   nop
    /* 2EAAE8 003EAAE8 C8B7848F */  lw         $4, -0x4838($28)
    /* 2EAAEC 003EAAEC 8800033C */  lui        $3, %hi(D_008872E0)
    /* 2EAAF0 003EAAF0 E0726324 */  addiu      $3, $3, %lo(D_008872E0)
    /* 2EAAF4 003EAAF4 21186400 */  addu       $3, $3, $4
    /* 2EAAF8 003EAAF8 040062AC */  sw         $2, 0x4($3)
    /* 2EAAFC 003EAAFC 080070AC */  sw         $16, 0x8($3)
  .L003EAB00:
    /* 2EAB00 003EAB00 C8B7838F */  lw         $3, -0x4838($28)
    /* 2EAB04 003EAB04 8800023C */  lui        $2, %hi(D_008872E0)
    /* 2EAB08 003EAB08 E0724224 */  addiu      $2, $2, %lo(D_008872E0)
    /* 2EAB0C 003EAB0C 2D300002 */  daddu      $6, $16, $0
    /* 2EAB10 003EAB10 21104300 */  addu       $2, $2, $3
    /* 2EAB14 003EAB14 0400448C */  lw         $4, 0x4($2)
    /* 2EAB18 003EAB18 04FE100C */  jal        func_0043f810
    /* 2EAB1C 003EAB1C 2D282002 */   daddu     $5, $17, $0
    /* 2EAB20 003EAB20 0B000010 */  b          .L003EAB50
    /* 2EAB24 003EAB24 2D102002 */   daddu     $2, $17, $0
  .L003EAB28:
    /* 2EAB28 003EAB28 01000224 */  addiu      $2, $0, 0x1
    /* 2EAB2C 003EAB2C 2D280002 */  daddu      $5, $16, $0
    /* 2EAB30 003EAB30 3800A2AF */  sw         $2, 0x38($29)
    /* 2EAB34 003EAB34 0080023C */  lui        $2, (0x80000013 >> 16)
    /* 2EAB38 003EAB38 647D0F0C */  jal        func_003df590
    /* 2EAB3C 003EAB3C 13004434 */   ori       $4, $2, (0x80000013 & 0xFFFF)
    /* 2EAB40 003EAB40 3C00A2AF */  sw         $2, 0x3C($29)
    /* 2EAB44 003EAB44 347D0F0C */  jal        func_003df4d0
    /* 2EAB48 003EAB48 3800A427 */   addiu     $4, $29, 0x38
    /* 2EAB4C 003EAB4C 2D100000 */  daddu      $2, $0, $0
  .L003EAB50:
    /* 2EAB50 003EAB50 2000BFDF */  ld         $31, 0x20($29)
    /* 2EAB54 003EAB54 1000B17B */  lq         $17, 0x10($29)
    /* 2EAB58 003EAB58 0000B07B */  lq         $16, 0x0($29)
    /* 2EAB5C 003EAB5C 0800E003 */  jr         $31
    /* 2EAB60 003EAB60 4000BD27 */   addiu     $29, $29, 0x40
    /* 2EAB64 003EAB64 00000000 */  nop
    /* 2EAB68 003EAB68 00000000 */  nop
    /* 2EAB6C 003EAB6C 00000000 */  nop
.size func_003eaa80, 0xf0
