.section .text
.set noat
.set noreorder
glabel func_0033de90
    /* 23DE90 0033DE90 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 23DE94 0033DE94 3000BFFF */  sd         $31, 0x30($29)
    /* 23DE98 0033DE98 2000B27F */  sq         $18, 0x20($29)
    /* 23DE9C 0033DE9C 1000B17F */  sq         $17, 0x10($29)
    /* 23DEA0 0033DEA0 0000B07F */  sq         $16, 0x0($29)
    /* 23DEA4 0033DEA4 2D908000 */  daddu      $18, $4, $0
    /* 23DEA8 0033DEA8 2D88A000 */  daddu      $17, $5, $0
    /* 23DEAC 0033DEAC 6500043C */  lui        $4, %hi(D_0064A400)
    /* 23DEB0 0033DEB0 00A48424 */  addiu      $4, $4, %lo(D_0064A400)
    /* 23DEB4 0033DEB4 0A010524 */  addiu      $5, $0, 0x10A
    /* 23DEB8 0033DEB8 A43A110C */  jal        func_0044ea90
    /* 23DEBC 0033DEBC 00000000 */   nop
    /* 23DEC0 0033DEC0 01000424 */  addiu      $4, $0, 0x1
    /* 23DEC4 0033DEC4 04000524 */  addiu      $5, $0, 0x4
    /* 23DEC8 0033DEC8 0400063C */  lui        $6, (0x40000 >> 16)
    /* 23DECC 0033DECC 8800023C */  lui        $2, %hi(D_008873F4)
    /* 23DED0 0033DED0 F473428C */  lw         $2, %lo(D_008873F4)($2)
    /* 23DED4 0033DED4 09F84000 */  jalr       $2
    /* 23DED8 0033DED8 00000000 */   nop
    /* 23DEDC 0033DEDC 2D804000 */  daddu      $16, $2, $0
    /* 23DEE0 0033DEE0 2D204002 */  daddu      $4, $18, $0
    /* 23DEE4 0033DEE4 6500053C */  lui        $5, %hi(D_0064A440)
    /* 23DEE8 0033DEE8 40A4A524 */  addiu      $5, $5, %lo(D_0064A440)
    /* 23DEEC 0033DEEC 0F000624 */  addiu      $6, $0, 0xF
    /* 23DEF0 0033DEF0 2D380000 */  daddu      $7, $0, $0
    /* 23DEF4 0033DEF4 2D400000 */  daddu      $8, $0, $0
    /* 23DEF8 0033DEF8 3400093C */  lui        $9, %hi(func_0033dd40)
    /* 23DEFC 0033DEFC 40DD2925 */  addiu      $9, $9, %lo(func_0033dd40)
    /* 23DF00 0033DF00 34000A3C */  lui        $10, %hi(func_0033de40)
    /* 23DF04 0033DF04 40DE4A25 */  addiu      $10, $10, %lo(func_0033de40)
    /* 23DF08 0033DF08 2D580002 */  daddu      $11, $16, $0
    /* 23DF0C 0033DF0C F047110C */  jal        func_00451fc0
    /* 23DF10 0033DF10 00000000 */   nop
    /* 23DF14 0033DF14 000011AE */  sw         $17, 0x0($16)
    /* 23DF18 0033DF18 3000BFDF */  ld         $31, 0x30($29)
    /* 23DF1C 0033DF1C 2000B27B */  lq         $18, 0x20($29)
    /* 23DF20 0033DF20 1000B17B */  lq         $17, 0x10($29)
    /* 23DF24 0033DF24 0000B07B */  lq         $16, 0x0($29)
    /* 23DF28 0033DF28 4000BD27 */  addiu      $29, $29, 0x40
    /* 23DF2C 0033DF2C 0800E003 */  jr         $31
    /* 23DF30 0033DF30 00000000 */   nop
    /* 23DF34 0033DF34 00000000 */  nop
    /* 23DF38 0033DF38 00000000 */  nop
    /* 23DF3C 0033DF3C 00000000 */  nop
.size func_0033de90, 0xb0
