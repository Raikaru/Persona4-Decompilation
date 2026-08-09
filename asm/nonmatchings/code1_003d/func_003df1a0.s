.section .text
.set noat
.set noreorder
glabel func_003df1a0
    /* 2DF1A0 003DF1A0 B0FEBD27 */  addiu      $29, $29, -0x150
    /* 2DF1A4 003DF1A4 4000BFFF */  sd         $31, 0x40($29)
    /* 2DF1A8 003DF1A8 3000B37F */  sq         $19, 0x30($29)
    /* 2DF1AC 003DF1AC 2000B27F */  sq         $18, 0x20($29)
    /* 2DF1B0 003DF1B0 2D988000 */  daddu      $19, $4, $0
    /* 2DF1B4 003DF1B4 1000B17F */  sq         $17, 0x10($29)
    /* 2DF1B8 003DF1B8 2D90A000 */  daddu      $18, $5, $0
    /* 2DF1BC 003DF1BC 2D88C000 */  daddu      $17, $6, $0
    /* 2DF1C0 003DF1C0 13002012 */  beqz       $17, .L003DF210
    /* 2DF1C4 003DF1C4 0000B07F */   sq        $16, 0x0($29)
  .L003DF1C8:
    /* 2DF1C8 003DF1C8 0001212E */  sltiu      $1, $17, 0x100
    /* 2DF1CC 003DF1CC 12002010 */  beqz       $1, .L003DF218
    /* 2DF1D0 003DF1D0 00000000 */   nop
    /* 2DF1D4 003DF1D4 2D802002 */  daddu      $16, $17, $0
  .L003DF1D8:
    /* 2DF1D8 003DF1D8 5000A427 */  addiu      $4, $29, 0x50
    /* 2DF1DC 003DF1DC 2D284002 */  daddu      $5, $18, $0
    /* 2DF1E0 003DF1E0 04FE100C */  jal        func_0043f810
    /* 2DF1E4 003DF1E4 2D300002 */   daddu     $6, $16, $0
    /* 2DF1E8 003DF1E8 2D206002 */  daddu      $4, $19, $0
    /* 2DF1EC 003DF1EC 5000A527 */  addiu      $5, $29, 0x50
    /* 2DF1F0 003DF1F0 AC8A0F0C */  jal        func_003e2ab0
    /* 2DF1F4 003DF1F4 2D300002 */   daddu     $6, $16, $0
    /* 2DF1F8 003DF1F8 09004010 */  beqz       $2, .L003DF220
    /* 2DF1FC 003DF1FC 00000000 */   nop
    /* 2DF200 003DF200 23883002 */  subu       $17, $17, $16
    /* 2DF204 003DF204 F0FF2016 */  bnez       $17, .L003DF1C8
    /* 2DF208 003DF208 21905002 */   addu      $18, $18, $16
    /* 2DF20C 003DF20C 00000000 */  nop
  .L003DF210:
    /* 2DF210 003DF210 04000010 */  b          .L003DF224
    /* 2DF214 003DF214 2D106002 */   daddu     $2, $19, $0
  .L003DF218:
    /* 2DF218 003DF218 EFFF0010 */  b          .L003DF1D8
    /* 2DF21C 003DF21C 00011024 */   addiu     $16, $0, 0x100
  .L003DF220:
    /* 2DF220 003DF220 2D100000 */  daddu      $2, $0, $0
  .L003DF224:
    /* 2DF224 003DF224 4000BFDF */  ld         $31, 0x40($29)
    /* 2DF228 003DF228 3000B37B */  lq         $19, 0x30($29)
    /* 2DF22C 003DF22C 2000B27B */  lq         $18, 0x20($29)
    /* 2DF230 003DF230 1000B17B */  lq         $17, 0x10($29)
    /* 2DF234 003DF234 0000B07B */  lq         $16, 0x0($29)
    /* 2DF238 003DF238 0800E003 */  jr         $31
    /* 2DF23C 003DF23C 5001BD27 */   addiu     $29, $29, 0x150
.size func_003df1a0, 0xa0
