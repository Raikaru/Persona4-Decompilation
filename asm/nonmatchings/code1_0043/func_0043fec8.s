.section .text
.set noat
.set noreorder
glabel func_0043fec8
    /* 33FEC8 0043FEC8 00008E8C */  lw         $14, 0x0($4)
    /* 33FECC 0043FECC 0700CF31 */  andi       $15, $14, 0x7
    /* 33FED0 0043FED0 0E00E011 */  beqz       $15, .L0043FF0C
    /* 33FED4 0043FED4 0100CF31 */   andi      $15, $14, 0x1
    /* 33FED8 0043FED8 0A00E015 */  bnez       $15, .L0043FF04
    /* 33FEDC 0043FEDC 2D100000 */   daddu     $2, $0, $0
    /* 33FEE0 0043FEE0 0200CF31 */  andi       $15, $14, 0x2
    /* 33FEE4 0043FEE4 0500E011 */  beqz       $15, .L0043FEFC
    /* 33FEE8 0043FEE8 82780E00 */   srl       $15, $14, 2
    /* 33FEEC 0043FEEC 42780E00 */  srl        $15, $14, 1
    /* 33FEF0 0043FEF0 01000224 */  addiu      $2, $0, 0x1
  .L0043FEF4:
    /* 33FEF4 0043FEF4 0800E003 */  jr         $31
    /* 33FEF8 0043FEF8 00008FAC */   sw        $15, 0x0($4)
  .L0043FEFC:
    /* 33FEFC 0043FEFC FDFF0010 */  b          .L0043FEF4
    /* 33FF00 0043FF00 02000224 */   addiu     $2, $0, 0x2
  .L0043FF04:
    /* 33FF04 0043FF04 0800E003 */  jr         $31
    /* 33FF08 0043FF08 00000000 */   nop
  .L0043FF0C:
    /* 33FF0C 0043FF0C FFFFCF31 */  andi       $15, $14, 0xFFFF
    /* 33FF10 0043FF10 0300E015 */  bnez       $15, .L0043FF20
    /* 33FF14 0043FF14 2D680000 */   daddu     $13, $0, $0
    /* 33FF18 0043FF18 10000D24 */  addiu      $13, $0, 0x10
    /* 33FF1C 0043FF1C 02740E00 */  srl        $14, $14, 16
  .L0043FF20:
    /* 33FF20 0043FF20 FF00CF31 */  andi       $15, $14, 0xFF
    /* 33FF24 0043FF24 0400E015 */  bnez       $15, .L0043FF38
    /* 33FF28 0043FF28 0F00CF31 */   andi      $15, $14, 0xF
    /* 33FF2C 0043FF2C 0800AD25 */  addiu      $13, $13, 0x8
    /* 33FF30 0043FF30 02720E00 */  srl        $14, $14, 8
    /* 33FF34 0043FF34 0F00CF31 */  andi       $15, $14, 0xF
  .L0043FF38:
    /* 33FF38 0043FF38 0400E015 */  bnez       $15, .L0043FF4C
    /* 33FF3C 0043FF3C 0300CF31 */   andi      $15, $14, 0x3
    /* 33FF40 0043FF40 0400AD25 */  addiu      $13, $13, 0x4
    /* 33FF44 0043FF44 02710E00 */  srl        $14, $14, 4
    /* 33FF48 0043FF48 0300CF31 */  andi       $15, $14, 0x3
  .L0043FF4C:
    /* 33FF4C 0043FF4C 0400E015 */  bnez       $15, .L0043FF60
    /* 33FF50 0043FF50 0100CF31 */   andi      $15, $14, 0x1
    /* 33FF54 0043FF54 0200AD25 */  addiu      $13, $13, 0x2
    /* 33FF58 0043FF58 82700E00 */  srl        $14, $14, 2
    /* 33FF5C 0043FF5C 0100CF31 */  andi       $15, $14, 0x1
  .L0043FF60:
    /* 33FF60 0043FF60 0600E055 */  bnel       $15, $0, .L0043FF7C
    /* 33FF64 0043FF64 00008EAC */   sw        $14, 0x0($4)
    /* 33FF68 0043FF68 0100AD25 */  addiu      $13, $13, 0x1
    /* 33FF6C 0043FF6C 42700E00 */  srl        $14, $14, 1
    /* 33FF70 0043FF70 E4FFC011 */  beqz       $14, .L0043FF04
    /* 33FF74 0043FF74 20000224 */   addiu     $2, $0, 0x20
    /* 33FF78 0043FF78 00008EAC */  sw         $14, 0x0($4)
  .L0043FF7C:
    /* 33FF7C 0043FF7C 0800E003 */  jr         $31
    /* 33FF80 0043FF80 2D10A001 */   daddu     $2, $13, $0
    /* 33FF84 0043FF84 00000000 */  nop
.size func_0043fec8, 0xc0
