.section .text
.set noat
.set noreorder
glabel func_003bf2d0
    /* 2BF2D0 003BF2D0 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 2BF2D4 003BF2D4 2000BFFF */  sd         $31, 0x20($29)
    /* 2BF2D8 003BF2D8 1000B17F */  sq         $17, 0x10($29)
    /* 2BF2DC 003BF2DC 0000B07F */  sq         $16, 0x0($29)
    /* 2BF2E0 003BF2E0 2D888000 */  daddu      $17, $4, $0
    /* 2BF2E4 003BF2E4 0000A28C */  lw         $2, 0x0($5)
    /* 2BF2E8 003BF2E8 2D80A000 */  daddu      $16, $5, $0
    /* 2BF2EC 003BF2EC 10004224 */  addiu      $2, $2, 0x10
    /* 2BF2F0 003BF2F0 94940F0C */  jal        func_003e5250
    /* 2BF2F4 003BF2F4 0000A2AC */   sw        $2, 0x0($5)
    /* 2BF2F8 003BF2F8 0000038E */  lw         $3, 0x0($16)
    /* 2BF2FC 003BF2FC 0C004424 */  addiu      $4, $2, 0xC
    /* 2BF300 003BF300 2D102002 */  daddu      $2, $17, $0
    /* 2BF304 003BF304 21186400 */  addu       $3, $3, $4
    /* 2BF308 003BF308 000003AE */  sw         $3, 0x0($16)
    /* 2BF30C 003BF30C 2000BFDF */  ld         $31, 0x20($29)
    /* 2BF310 003BF310 1000B17B */  lq         $17, 0x10($29)
    /* 2BF314 003BF314 0000B07B */  lq         $16, 0x0($29)
    /* 2BF318 003BF318 0800E003 */  jr         $31
    /* 2BF31C 003BF31C 3000BD27 */   addiu     $29, $29, 0x30
.size func_003bf2d0, 0x50
