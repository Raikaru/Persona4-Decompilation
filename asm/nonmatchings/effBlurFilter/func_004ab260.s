.section .text
.set noat
.set noreorder
glabel func_004ab260
    /* 3AB260 004AB260 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3AB264 004AB264 1000BFFF */  sd         $31, 0x10($29)
    /* 3AB268 004AB268 0000B07F */  sq         $16, 0x0($29)
    /* 3AB26C 004AB26C 2D808000 */  daddu      $16, $4, $0
    /* 3AB270 004AB270 1800838C */  lw         $3, 0x18($4)
    /* 3AB274 004AB274 40100300 */  sll        $2, $3, 1
    /* 3AB278 004AB278 21104300 */  addu       $2, $2, $3
    /* 3AB27C 004AB27C C0180200 */  sll        $3, $2, 3
    /* 3AB280 004AB280 7100023C */  lui        $2, %hi(D_00714398)
    /* 3AB284 004AB284 98434224 */  addiu      $2, $2, %lo(D_00714398)
    /* 3AB288 004AB288 21104300 */  addu       $2, $2, $3
    /* 3AB28C 004AB28C 0000428C */  lw         $2, 0x0($2)
    /* 3AB290 004AB290 09F84000 */  jalr       $2
    /* 3AB294 004AB294 00000000 */   nop
    /* 3AB298 004AB298 1C00038E */  lw         $3, 0x1C($16)
    /* 3AB29C 004AB29C 01006324 */  addiu      $3, $3, 0x1
    /* 3AB2A0 004AB2A0 1C0003AE */  sw         $3, 0x1C($16)
    /* 3AB2A4 004AB2A4 1000BFDF */  ld         $31, 0x10($29)
    /* 3AB2A8 004AB2A8 0000B07B */  lq         $16, 0x0($29)
    /* 3AB2AC 004AB2AC 2000BD27 */  addiu      $29, $29, 0x20
    /* 3AB2B0 004AB2B0 0800E003 */  jr         $31
    /* 3AB2B4 004AB2B4 00000000 */   nop
    /* 3AB2B8 004AB2B8 00000000 */  nop
    /* 3AB2BC 004AB2BC 00000000 */  nop
.size func_004ab260, 0x60
