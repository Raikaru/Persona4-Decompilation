.section .text
.set noat
.set noreorder
glabel func_002bdff0
    /* 1BDFF0 002BDFF0 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 1BDFF4 002BDFF4 2000BFFF */  sd         $31, 0x20($29)
    /* 1BDFF8 002BDFF8 1000B17F */  sq         $17, 0x10($29)
    /* 1BDFFC 002BDFFC 0000B07F */  sq         $16, 0x0($29)
    /* 1BE000 002BE000 2D888000 */  daddu      $17, $4, $0
    /* 1BE004 002BE004 141A040C */  jal        func_00106850
    /* 1BE008 002BE008 00000000 */   nop
    /* 1BE00C 002BE00C 03000324 */  addiu      $3, $0, 0x3
    /* 1BE010 002BE010 31004314 */  bne        $2, $3, .L002BE0D8
    /* 1BE014 002BE014 00000000 */   nop
    /* 1BE018 002BE018 2D202002 */  daddu      $4, $17, $0
    /* 1BE01C 002BE01C B01A040C */  jal        func_00106ac0
    /* 1BE020 002BE020 00000000 */   nop
    /* 1BE024 002BE024 FF004430 */  andi       $4, $2, 0xFF
    /* 1BE028 002BE028 40F80A0C */  jal        func_002be100
    /* 1BE02C 002BE02C 00000000 */   nop
    /* 1BE030 002BE030 FF005030 */  andi       $16, $2, 0xFF
    /* 1BE034 002BE034 289E0B0C */  jal        func_002e78a0
    /* 1BE038 002BE038 00000000 */   nop
    /* 1BE03C 002BE03C 2D204000 */  daddu      $4, $2, $0
    /* 1BE040 002BE040 40F80A0C */  jal        func_002be100
    /* 1BE044 002BE044 00000000 */   nop
    /* 1BE048 002BE048 FF004230 */  andi       $2, $2, 0xFF
    /* 1BE04C 002BE04C 2A080202 */  slt        $1, $16, $2
    /* 1BE050 002BE050 04002010 */  beqz       $1, .L002BE064
    /* 1BE054 002BE054 00000000 */   nop
    /* 1BE058 002BE058 01000224 */  addiu      $2, $0, 0x1
    /* 1BE05C 002BE05C 1F000010 */  b          .L002BE0DC
    /* 1BE060 002BE060 00000000 */   nop
  .L002BE064:
    /* 1BE064 002BE064 2D202002 */  daddu      $4, $17, $0
    /* 1BE068 002BE068 B01A040C */  jal        func_00106ac0
    /* 1BE06C 002BE06C 00000000 */   nop
    /* 1BE070 002BE070 FF004430 */  andi       $4, $2, 0xFF
    /* 1BE074 002BE074 40F80A0C */  jal        func_002be100
    /* 1BE078 002BE078 00000000 */   nop
    /* 1BE07C 002BE07C FF005030 */  andi       $16, $2, 0xFF
    /* 1BE080 002BE080 289E0B0C */  jal        func_002e78a0
    /* 1BE084 002BE084 00000000 */   nop
    /* 1BE088 002BE088 2D204000 */  daddu      $4, $2, $0
    /* 1BE08C 002BE08C 40F80A0C */  jal        func_002be100
    /* 1BE090 002BE090 00000000 */   nop
    /* 1BE094 002BE094 FF004230 */  andi       $2, $2, 0xFF
    /* 1BE098 002BE098 0F000216 */  bne        $16, $2, .L002BE0D8
    /* 1BE09C 002BE09C 00000000 */   nop
    /* 1BE0A0 002BE0A0 2D202002 */  daddu      $4, $17, $0
    /* 1BE0A4 002BE0A4 BC1A040C */  jal        func_00106af0
    /* 1BE0A8 002BE0A8 00000000 */   nop
    /* 1BE0AC 002BE0AC 3C860200 */  dsll32     $16, $2, 24
    /* 1BE0B0 002BE0B0 3F861000 */  dsra32     $16, $16, 24
    /* 1BE0B4 002BE0B4 389E0B0C */  jal        func_002e78e0
    /* 1BE0B8 002BE0B8 00000000 */   nop
    /* 1BE0BC 002BE0BC FF004230 */  andi       $2, $2, 0xFF
    /* 1BE0C0 002BE0C0 2A085000 */  slt        $1, $2, $16
    /* 1BE0C4 002BE0C4 04002014 */  bnez       $1, .L002BE0D8
    /* 1BE0C8 002BE0C8 00000000 */   nop
    /* 1BE0CC 002BE0CC 01000224 */  addiu      $2, $0, 0x1
    /* 1BE0D0 002BE0D0 02000010 */  b          .L002BE0DC
    /* 1BE0D4 002BE0D4 00000000 */   nop
  .L002BE0D8:
    /* 1BE0D8 002BE0D8 2D100000 */  daddu      $2, $0, $0
  .L002BE0DC:
    /* 1BE0DC 002BE0DC 2000BFDF */  ld         $31, 0x20($29)
    /* 1BE0E0 002BE0E0 1000B17B */  lq         $17, 0x10($29)
    /* 1BE0E4 002BE0E4 0000B07B */  lq         $16, 0x0($29)
    /* 1BE0E8 002BE0E8 3000BD27 */  addiu      $29, $29, 0x30
    /* 1BE0EC 002BE0EC 0800E003 */  jr         $31
    /* 1BE0F0 002BE0F0 00000000 */   nop
    /* 1BE0F4 002BE0F4 00000000 */  nop
    /* 1BE0F8 002BE0F8 00000000 */  nop
    /* 1BE0FC 002BE0FC 00000000 */  nop
.size func_002bdff0, 0x110
