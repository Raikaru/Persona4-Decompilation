.section .text
.set noat
.set noreorder
glabel func_003cc250
    /* 2CC250 003CC250 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 2CC254 003CC254 0000A38C */  lw         $3, 0x0($5)
    /* 2CC258 003CC258 0000BFFF */  sd         $31, 0x0($29)
    /* 2CC25C 003CC25C 00006294 */  lhu        $2, 0x0($3)
    /* 2CC260 003CC260 09004018 */  blez       $2, .L003CC288
    /* 2CC264 003CC264 00000000 */   nop
    /* 2CC268 003CC268 0400628C */  lw         $2, 0x4($3)
    /* 2CC26C 003CC26C 180062AC */  sw         $2, 0x18($3)
    /* 2CC270 003CC270 0C00628C */  lw         $2, 0xC($3)
    /* 2CC274 003CC274 01004230 */  andi       $2, $2, 0x1
    /* 2CC278 003CC278 05004010 */  beqz       $2, .L003CC290
    /* 2CC27C 003CC27C 00000000 */   nop
  .L003CC280:
    /* 2CC280 003CC280 0A000010 */  b          .L003CC2AC
    /* 2CC284 003CC284 01000224 */   addiu     $2, $0, 0x1
  .L003CC288:
    /* 2CC288 003CC288 08000010 */  b          .L003CC2AC
    /* 2CC28C 003CC28C 2D100000 */   daddu     $2, $0, $0
  .L003CC290:
    /* 2CC290 003CC290 8800023C */  lui        $2, %hi(D_00887300)
    /* 2CC294 003CC294 01000424 */  addiu      $4, $0, 0x1
    /* 2CC298 003CC298 0073428C */  lw         $2, %lo(D_00887300)($2)
    /* 2CC29C 003CC29C 09F84000 */  jalr       $2
    /* 2CC2A0 003CC2A0 2D280000 */   daddu     $5, $0, $0
    /* 2CC2A4 003CC2A4 F6FF0010 */  b          .L003CC280
    /* 2CC2A8 003CC2A8 00000000 */   nop
  .L003CC2AC:
    /* 2CC2AC 003CC2AC 0000BFDF */  ld         $31, 0x0($29)
    /* 2CC2B0 003CC2B0 0800E003 */  jr         $31
    /* 2CC2B4 003CC2B4 1000BD27 */   addiu     $29, $29, 0x10
    /* 2CC2B8 003CC2B8 00000000 */  nop
    /* 2CC2BC 003CC2BC 00000000 */  nop
.size func_003cc250, 0x70
