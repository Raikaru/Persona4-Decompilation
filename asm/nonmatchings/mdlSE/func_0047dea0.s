.section .text
.set noat
.set noreorder
glabel func_0047dea0
    /* 37DEA0 0047DEA0 B0FFBD27 */  addiu      $29, $29, -0x50
    /* 37DEA4 0047DEA4 4000BFFF */  sd         $31, 0x40($29)
    /* 37DEA8 0047DEA8 3000B37F */  sq         $19, 0x30($29)
    /* 37DEAC 0047DEAC 2000B27F */  sq         $18, 0x20($29)
    /* 37DEB0 0047DEB0 1000B17F */  sq         $17, 0x10($29)
    /* 37DEB4 0047DEB4 0000B07F */  sq         $16, 0x0($29)
    /* 37DEB8 0047DEB8 2D908000 */  daddu      $18, $4, $0
    /* 37DEBC 0047DEBC 2D88A000 */  daddu      $17, $5, $0
    /* 37DEC0 0047DEC0 2D80C000 */  daddu      $16, $6, $0
    /* 37DEC4 0047DEC4 E8B08427 */  addiu      $4, $28, -0x4F18
    /* 37DEC8 0047DEC8 2B000524 */  addiu      $5, $0, 0x2B
    /* 37DECC 0047DECC A43A110C */  jal        func_0044ea90
    /* 37DED0 0047DED0 00000000 */   nop
    /* 37DED4 0047DED4 28000424 */  addiu      $4, $0, 0x28
    /* 37DED8 0047DED8 0400053C */  lui        $5, (0x40000 >> 16)
    /* 37DEDC 0047DEDC 8800023C */  lui        $2, %hi(jtbl_008873E8)
    /* 37DEE0 0047DEE0 E873428C */  lw         $2, %lo(jtbl_008873E8)($2)
    /* 37DEE4 0047DEE4 09F84000 */  jalr       $2
    /* 37DEE8 0047DEE8 00000000 */   nop
    /* 37DEEC 0047DEEC 2D984000 */  daddu      $19, $2, $0
    /* 37DEF0 0047DEF0 2D206002 */  daddu      $4, $19, $0
    /* 37DEF4 0047DEF4 2D280000 */  daddu      $5, $0, $0
    /* 37DEF8 0047DEF8 28000624 */  addiu      $6, $0, 0x28
    /* 37DEFC 0047DEFC 72FE100C */  jal        func_0043f9c8
    /* 37DF00 0047DF00 00000000 */   nop
    /* 37DF04 0047DF04 01000224 */  addiu      $2, $0, 0x1
    /* 37DF08 0047DF08 080062AE */  sw         $2, 0x8($19)
    /* 37DF0C 0047DF0C 0C0072A6 */  sh         $18, 0xC($19)
    /* 37DF10 0047DF10 0E0071A6 */  sh         $17, 0xE($19)
    /* 37DF14 0047DF14 100070A6 */  sh         $16, 0x10($19)
    /* 37DF18 0047DF18 2D106002 */  daddu      $2, $19, $0
    /* 37DF1C 0047DF1C 4000BFDF */  ld         $31, 0x40($29)
    /* 37DF20 0047DF20 3000B37B */  lq         $19, 0x30($29)
    /* 37DF24 0047DF24 2000B27B */  lq         $18, 0x20($29)
    /* 37DF28 0047DF28 1000B17B */  lq         $17, 0x10($29)
    /* 37DF2C 0047DF2C 0000B07B */  lq         $16, 0x0($29)
    /* 37DF30 0047DF30 5000BD27 */  addiu      $29, $29, 0x50
    /* 37DF34 0047DF34 0800E003 */  jr         $31
    /* 37DF38 0047DF38 00000000 */   nop
    /* 37DF3C 0047DF3C 00000000 */  nop
.size func_0047dea0, 0xa0
