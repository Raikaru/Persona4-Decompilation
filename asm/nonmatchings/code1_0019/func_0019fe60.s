.section .text
.set noat
.set noreorder
glabel func_0019fe60
    /* 9FE60 0019FE60 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 9FE64 0019FE64 2000BFFF */  sd         $31, 0x20($29)
    /* 9FE68 0019FE68 1000B17F */  sq         $17, 0x10($29)
    /* 9FE6C 0019FE6C 0000B07F */  sq         $16, 0x0($29)
    /* 9FE70 0019FE70 2D88A000 */  daddu      $17, $5, $0
    /* 9FE74 0019FE74 2D80C000 */  daddu      $16, $6, $0
    /* 9FE78 0019FE78 3000828C */  lw         $2, 0x30($4)
    /* 9FE7C 0019FE7C 640A448C */  lw         $4, 0xA64($2)
    /* 9FE80 0019FE80 02008694 */  lhu        $6, 0x2($4)
    /* 9FE84 0019FE84 A2004390 */  lbu        $3, 0xA2($2)
    /* 9FE88 0019FE88 01000224 */  addiu      $2, $0, 0x1
    /* 9FE8C 0019FE8C 1E006210 */  beq        $3, $2, .L0019FF08
    /* 9FE90 0019FE90 00000000 */   nop
    /* 9FE94 0019FE94 03006010 */  beqz       $3, .L0019FEA4
    /* 9FE98 0019FE98 00000000 */   nop
    /* 9FE9C 0019FE9C 27000010 */  b          .L0019FF3C
    /* 9FEA0 0019FEA0 00000000 */   nop
  .L0019FEA4:
    /* 9FEA4 0019FEA4 7CF8080C */  jal        func_0023e1f0
    /* 9FEA8 0019FEA8 00000000 */   nop
    /* 9FEAC 0019FEAC FF004330 */  andi       $3, $2, 0xFF
    /* 9FEB0 0019FEB0 05000224 */  addiu      $2, $0, 0x5
    /* 9FEB4 0019FEB4 04006214 */  bne        $3, $2, .L0019FEC8
    /* 9FEB8 0019FEB8 00000000 */   nop
    /* 9FEBC 0019FEBC 01000224 */  addiu      $2, $0, 0x1
    /* 9FEC0 0019FEC0 1F000010 */  b          .L0019FF40
    /* 9FEC4 0019FEC4 00000000 */   nop
  .L0019FEC8:
    /* 9FEC8 0019FEC8 03000224 */  addiu      $2, $0, 0x3
    /* 9FECC 0019FECC 1B006214 */  bne        $3, $2, .L0019FF3C
    /* 9FED0 0019FED0 00000000 */   nop
    /* 9FED4 0019FED4 BCB3838F */  lw         $3, -0x4C44($28)
    /* 9FED8 0019FED8 FFFF2232 */  andi       $2, $17, 0xFFFF
    /* 9FEDC 0019FEDC 80100200 */  sll        $2, $2, 2
    /* 9FEE0 0019FEE0 21104300 */  addu       $2, $2, $3
    /* 9FEE4 0019FEE4 02004294 */  lhu        $2, 0x2($2)
    /* 9FEE8 0019FEE8 00804230 */  andi       $2, $2, 0x8000
    /* 9FEEC 0019FEEC 03004014 */  bnez       $2, .L0019FEFC
    /* 9FEF0 0019FEF0 00000000 */   nop
    /* 9FEF4 0019FEF4 11000016 */  bnez       $16, .L0019FF3C
    /* 9FEF8 0019FEF8 00000000 */   nop
  .L0019FEFC:
    /* 9FEFC 0019FEFC 01000224 */  addiu      $2, $0, 0x1
    /* 9FF00 0019FF00 0F000010 */  b          .L0019FF40
    /* 9FF04 0019FF04 00000000 */   nop
  .L0019FF08:
    /* 9FF08 0019FF08 CCB3858F */  lw         $5, -0x4C34($28)
    /* 9FF0C 0019FF0C FFFFC430 */  andi       $4, $6, 0xFFFF
    /* 9FF10 0019FF10 C0180400 */  sll        $3, $4, 3
    /* 9FF14 0019FF14 23186400 */  subu       $3, $3, $4
    /* 9FF18 0019FF18 80180300 */  sll        $3, $3, 2
    /* 9FF1C 0019FF1C 21186400 */  addu       $3, $3, $4
    /* 9FF20 0019FF20 C0180300 */  sll        $3, $3, 3
    /* 9FF24 0019FF24 21186500 */  addu       $3, $3, $5
    /* 9FF28 0019FF28 22006384 */  lh         $3, 0x22($3)
    /* 9FF2C 0019FF2C 03006214 */  bne        $3, $2, .L0019FF3C
    /* 9FF30 0019FF30 00000000 */   nop
    /* 9FF34 0019FF34 02000010 */  b          .L0019FF40
    /* 9FF38 0019FF38 00000000 */   nop
  .L0019FF3C:
    /* 9FF3C 0019FF3C 2D100000 */  daddu      $2, $0, $0
  .L0019FF40:
    /* 9FF40 0019FF40 2000BFDF */  ld         $31, 0x20($29)
    /* 9FF44 0019FF44 1000B17B */  lq         $17, 0x10($29)
    /* 9FF48 0019FF48 0000B07B */  lq         $16, 0x0($29)
    /* 9FF4C 0019FF4C 3000BD27 */  addiu      $29, $29, 0x30
    /* 9FF50 0019FF50 0800E003 */  jr         $31
    /* 9FF54 0019FF54 00000000 */   nop
    /* 9FF58 0019FF58 00000000 */  nop
    /* 9FF5C 0019FF5C 00000000 */  nop
.size func_0019fe60, 0x100
