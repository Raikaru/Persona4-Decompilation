.section .text
.set noat
.set noreorder
glabel func_0033dc90
    /* 23DC90 0033DC90 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 23DC94 0033DC94 3000BFFF */  sd         $31, 0x30($29)
    /* 23DC98 0033DC98 2000B27F */  sq         $18, 0x20($29)
    /* 23DC9C 0033DC9C 1000B17F */  sq         $17, 0x10($29)
    /* 23DCA0 0033DCA0 0000B07F */  sq         $16, 0x0($29)
    /* 23DCA4 0033DCA4 2D908000 */  daddu      $18, $4, $0
    /* 23DCA8 0033DCA8 2D88A000 */  daddu      $17, $5, $0
    /* 23DCAC 0033DCAC 6500043C */  lui        $4, %hi(D_0064A400)
    /* 23DCB0 0033DCB0 00A48424 */  addiu      $4, $4, %lo(D_0064A400)
    /* 23DCB4 0033DCB4 AF000524 */  addiu      $5, $0, 0xAF
    /* 23DCB8 0033DCB8 A43A110C */  jal        func_0044ea90
    /* 23DCBC 0033DCBC 00000000 */   nop
    /* 23DCC0 0033DCC0 01000424 */  addiu      $4, $0, 0x1
    /* 23DCC4 0033DCC4 14000524 */  addiu      $5, $0, 0x14
    /* 23DCC8 0033DCC8 0400063C */  lui        $6, (0x40000 >> 16)
    /* 23DCCC 0033DCCC 8800023C */  lui        $2, %hi(D_008873F4)
    /* 23DCD0 0033DCD0 F473428C */  lw         $2, %lo(D_008873F4)($2)
    /* 23DCD4 0033DCD4 09F84000 */  jalr       $2
    /* 23DCD8 0033DCD8 00000000 */   nop
    /* 23DCDC 0033DCDC 2D804000 */  daddu      $16, $2, $0
    /* 23DCE0 0033DCE0 2D204002 */  daddu      $4, $18, $0
    /* 23DCE4 0033DCE4 6500053C */  lui        $5, %hi(D_0064A420)
    /* 23DCE8 0033DCE8 20A4A524 */  addiu      $5, $5, %lo(D_0064A420)
    /* 23DCEC 0033DCEC 0F000624 */  addiu      $6, $0, 0xF
    /* 23DCF0 0033DCF0 2D380000 */  daddu      $7, $0, $0
    /* 23DCF4 0033DCF4 2D400000 */  daddu      $8, $0, $0
    /* 23DCF8 0033DCF8 3400093C */  lui        $9, %hi(func_0033d9d0)
    /* 23DCFC 0033DCFC D0D92925 */  addiu      $9, $9, %lo(func_0033d9d0)
    /* 23DD00 0033DD00 34000A3C */  lui        $10, %hi(func_0033dc60)
    /* 23DD04 0033DD04 60DC4A25 */  addiu      $10, $10, %lo(func_0033dc60)
    /* 23DD08 0033DD08 2D580002 */  daddu      $11, $16, $0
    /* 23DD0C 0033DD0C F047110C */  jal        func_00451fc0
    /* 23DD10 0033DD10 00000000 */   nop
    /* 23DD14 0033DD14 000000A2 */  sb         $0, 0x0($16)
    /* 23DD18 0033DD18 100011A2 */  sb         $17, 0x10($16)
    /* 23DD1C 0033DD1C 3000BFDF */  ld         $31, 0x30($29)
    /* 23DD20 0033DD20 2000B27B */  lq         $18, 0x20($29)
    /* 23DD24 0033DD24 1000B17B */  lq         $17, 0x10($29)
    /* 23DD28 0033DD28 0000B07B */  lq         $16, 0x0($29)
    /* 23DD2C 0033DD2C 4000BD27 */  addiu      $29, $29, 0x40
    /* 23DD30 0033DD30 0800E003 */  jr         $31
    /* 23DD34 0033DD34 00000000 */   nop
    /* 23DD38 0033DD38 00000000 */  nop
    /* 23DD3C 0033DD3C 00000000 */  nop
.size func_0033dc90, 0xb0
