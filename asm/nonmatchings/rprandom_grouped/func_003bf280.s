.section .text
.set noat
.set noreorder
glabel func_003bf280
    /* 2BF280 003BF280 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 2BF284 003BF284 2000BFFF */  sd         $31, 0x20($29)
    /* 2BF288 003BF288 1000B17F */  sq         $17, 0x10($29)
    /* 2BF28C 003BF28C 0000B07F */  sq         $16, 0x0($29)
    /* 2BF290 003BF290 2D888000 */  daddu      $17, $4, $0
    /* 2BF294 003BF294 0000A28C */  lw         $2, 0x0($5)
    /* 2BF298 003BF298 2D80A000 */  daddu      $16, $5, $0
    /* 2BF29C 003BF29C 10004224 */  addiu      $2, $2, 0x10
    /* 2BF2A0 003BF2A0 600E0F0C */  jal        func_003c3980
    /* 2BF2A4 003BF2A4 0000A2AC */   sw        $2, 0x0($5)
    /* 2BF2A8 003BF2A8 0000038E */  lw         $3, 0x0($16)
    /* 2BF2AC 003BF2AC 0C004424 */  addiu      $4, $2, 0xC
    /* 2BF2B0 003BF2B0 2D102002 */  daddu      $2, $17, $0
    /* 2BF2B4 003BF2B4 21186400 */  addu       $3, $3, $4
    /* 2BF2B8 003BF2B8 000003AE */  sw         $3, 0x0($16)
    /* 2BF2BC 003BF2BC 2000BFDF */  ld         $31, 0x20($29)
    /* 2BF2C0 003BF2C0 1000B17B */  lq         $17, 0x10($29)
    /* 2BF2C4 003BF2C4 0000B07B */  lq         $16, 0x0($29)
    /* 2BF2C8 003BF2C8 0800E003 */  jr         $31
    /* 2BF2CC 003BF2CC 3000BD27 */   addiu     $29, $29, 0x30
.size func_003bf280, 0x50
