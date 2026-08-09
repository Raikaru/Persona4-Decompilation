.section .text
.set noat
.set noreorder
glabel func_003bba90
    /* 2BBA90 003BBA90 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 2BBA94 003BBA94 2D308000 */  daddu      $6, $4, $0
    /* 2BBA98 003BBA98 2000BFFF */  sd         $31, 0x20($29)
    /* 2BBA9C 003BBA9C 02000424 */  addiu      $4, $0, 0x2
    /* 2BBAA0 003BBAA0 1000B17F */  sq         $17, 0x10($29)
    /* 2BBAA4 003BBAA4 01000524 */  addiu      $5, $0, 0x1
    /* 2BBAA8 003BBAA8 0000B07F */  sq         $16, 0x0($29)
    /* 2BBAAC 003BBAAC D88B0F0C */  jal        func_003e2f60
    /* 2BBAB0 003BBAB0 2D800000 */   daddu     $16, $0, $0
    /* 2BBAB4 003BBAB4 2D884000 */  daddu      $17, $2, $0
    /* 2BBAB8 003BBAB8 22002012 */  beqz       $17, .L003BBB44
    /* 2BBABC 003BBABC 00000000 */   nop
    /* 2BBAC0 003BBAC0 2D202002 */  daddu      $4, $17, $0
    /* 2BBAC4 003BBAC4 0C000524 */  addiu      $5, $0, 0xC
    /* 2BBAC8 003BBAC8 2D300000 */  daddu      $6, $0, $0
    /* 2BBACC 003BBACC 147C0F0C */  jal        func_003df050
    /* 2BBAD0 003BBAD0 3C00A727 */   addiu     $7, $29, 0x3C
    /* 2BBAD4 003BBAD4 18004010 */  beqz       $2, .L003BBB38
    /* 2BBAD8 003BBAD8 00000000 */   nop
    /* 2BBADC 003BBADC 3C00A38F */  lw         $3, 0x3C($29)
    /* 2BBAE0 003BBAE0 0300023C */  lui        $2, (0x35000 >> 16)
    /* 2BBAE4 003BBAE4 00504234 */  ori        $2, $2, (0x35000 & 0xFFFF)
    /* 2BBAE8 003BBAE8 2B106200 */  sltu       $2, $3, $2
    /* 2BBAEC 003BBAEC 0A004014 */  bnez       $2, .L003BBB18
    /* 2BBAF0 003BBAF0 00000000 */   nop
    /* 2BBAF4 003BBAF4 0300013C */  lui        $1, (0x37003 >> 16)
    /* 2BBAF8 003BBAF8 03702134 */  ori        $1, $1, (0x37003 & 0xFFFF)
    /* 2BBAFC 003BBAFC 2B086100 */  sltu       $1, $3, $1
    /* 2BBB00 003BBB00 05002010 */  beqz       $1, .L003BBB18
    /* 2BBB04 003BBB04 00000000 */   nop
    /* 2BBB08 003BBB08 84EC0E0C */  jal        func_003bb210
    /* 2BBB0C 003BBB0C 2D202002 */   daddu     $4, $17, $0
    /* 2BBB10 003BBB10 09000010 */  b          .L003BBB38
    /* 2BBB14 003BBB14 2D804000 */   daddu     $16, $2, $0
  .L003BBB18:
    /* 2BBB18 003BBB18 02010324 */  addiu      $3, $0, 0x102
    /* 2BBB1C 003BBB1C 0080023C */  lui        $2, (0x80000004 >> 16)
    /* 2BBB20 003BBB20 3000A3AF */  sw         $3, 0x30($29)
    /* 2BBB24 003BBB24 647D0F0C */  jal        func_003df590
    /* 2BBB28 003BBB28 04004434 */   ori       $4, $2, (0x80000004 & 0xFFFF)
    /* 2BBB2C 003BBB2C 3400A2AF */  sw         $2, 0x34($29)
    /* 2BBB30 003BBB30 347D0F0C */  jal        func_003df4d0
    /* 2BBB34 003BBB34 3000A427 */   addiu     $4, $29, 0x30
  .L003BBB38:
    /* 2BBB38 003BBB38 2D202002 */  daddu      $4, $17, $0
    /* 2BBB3C 003BBB3C 908B0F0C */  jal        func_003e2e40
    /* 2BBB40 003BBB40 2D280000 */   daddu     $5, $0, $0
  .L003BBB44:
    /* 2BBB44 003BBB44 2D100002 */  daddu      $2, $16, $0
    /* 2BBB48 003BBB48 2000BFDF */  ld         $31, 0x20($29)
    /* 2BBB4C 003BBB4C 1000B17B */  lq         $17, 0x10($29)
    /* 2BBB50 003BBB50 0000B07B */  lq         $16, 0x0($29)
    /* 2BBB54 003BBB54 0800E003 */  jr         $31
    /* 2BBB58 003BBB58 4000BD27 */   addiu     $29, $29, 0x40
    /* 2BBB5C 003BBB5C 00000000 */  nop
.size func_003bba90, 0xd0
