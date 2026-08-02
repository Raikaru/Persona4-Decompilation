.section .text
.set noat
.set noreorder
glabel func_0046af60
    /* 36AF60 0046AF60 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 36AF64 0046AF64 1000BFFF */  sd         $31, 0x10($29)
    /* 36AF68 0046AF68 0000B07F */  sq         $16, 0x0($29)
    /* 36AF6C 0046AF6C 2D808000 */  daddu      $16, $4, $0
    /* 36AF70 0046AF70 7100043C */  lui        $4, %hi(D_007130C8)
    /* 36AF74 0046AF74 C8308424 */  addiu      $4, $4, %lo(D_007130C8)
    /* 36AF78 0046AF78 2D010524 */  addiu      $5, $0, 0x12D
    /* 36AF7C 0046AF7C A43A110C */  jal        func_0044ea90
    /* 36AF80 0046AF80 00000000 */   nop
    /* 36AF84 0046AF84 01000424 */  addiu      $4, $0, 0x1
    /* 36AF88 0046AF88 40020524 */  addiu      $5, $0, 0x240
    /* 36AF8C 0046AF8C 0400063C */  lui        $6, (0x40000 >> 16)
    /* 36AF90 0046AF90 8800023C */  lui        $2, %hi(D_008873F4)
    /* 36AF94 0046AF94 F473428C */  lw         $2, %lo(D_008873F4)($2)
    /* 36AF98 0046AF98 09F84000 */  jalr       $2
    /* 36AF9C 0046AF9C 00000000 */   nop
    /* 36AFA0 0046AFA0 01000324 */  addiu      $3, $0, 0x1
    /* 36AFA4 0046AFA4 000043A4 */  sh         $3, 0x0($2)
    /* 36AFA8 0046AFA8 0C0250AC */  sw         $16, 0x20C($2)
    /* 36AFAC 0046AFAC 18BB848F */  lw         $4, -0x44E8($28)
    /* 36AFB0 0046AFB0 04008014 */  bnez       $4, .L0046AFC4
    /* 36AFB4 0046AFB4 00000000 */   nop
    /* 36AFB8 0046AFB8 18BB82AF */  sw         $2, -0x44E8($28)
    /* 36AFBC 0046AFBC 0B000010 */  b          .L0046AFEC
    /* 36AFC0 0046AFC0 00000000 */   nop
  .L0046AFC4:
    /* 36AFC4 0046AFC4 3802838C */  lw         $3, 0x238($4)
    /* 36AFC8 0046AFC8 05006014 */  bnez       $3, .L0046AFE0
    /* 36AFCC 0046AFCC 00000000 */   nop
    /* 36AFD0 0046AFD0 380282AC */  sw         $2, 0x238($4)
    /* 36AFD4 0046AFD4 3C0244AC */  sw         $4, 0x23C($2)
    /* 36AFD8 0046AFD8 04000010 */  b          .L0046AFEC
    /* 36AFDC 0046AFDC 00000000 */   nop
  .L0046AFE0:
    /* 36AFE0 0046AFE0 2D206000 */  daddu      $4, $3, $0
    /* 36AFE4 0046AFE4 F7FF0010 */  b          .L0046AFC4
    /* 36AFE8 0046AFE8 00000000 */   nop
  .L0046AFEC:
    /* 36AFEC 0046AFEC 1000BFDF */  ld         $31, 0x10($29)
    /* 36AFF0 0046AFF0 0000B07B */  lq         $16, 0x0($29)
    /* 36AFF4 0046AFF4 2000BD27 */  addiu      $29, $29, 0x20
    /* 36AFF8 0046AFF8 0800E003 */  jr         $31
    /* 36AFFC 0046AFFC 00000000 */   nop
.size func_0046af60, 0xa0
