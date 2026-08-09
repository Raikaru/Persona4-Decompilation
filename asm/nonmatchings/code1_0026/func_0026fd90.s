.section .text
.set noat
.set noreorder
glabel func_0026fd90
    /* 16FD90 0026FD90 90FFBD27 */  addiu      $29, $29, -0x70
    /* 16FD94 0026FD94 5000BFFF */  sd         $31, 0x50($29)
    /* 16FD98 0026FD98 4000B47F */  sq         $20, 0x40($29)
    /* 16FD9C 0026FD9C 3000B37F */  sq         $19, 0x30($29)
    /* 16FDA0 0026FDA0 2000B27F */  sq         $18, 0x20($29)
    /* 16FDA4 0026FDA4 1000B17F */  sq         $17, 0x10($29)
    /* 16FDA8 0026FDA8 0000B07F */  sq         $16, 0x0($29)
    /* 16FDAC 0026FDAC 2D88A000 */  daddu      $17, $5, $0
    /* 16FDB0 0026FDB0 1800A38C */  lw         $3, 0x18($5)
    /* 16FDB4 0026FDB4 1000A28C */  lw         $2, 0x10($5)
    /* 16FDB8 0026FDB8 21184300 */  addu       $3, $2, $3
    /* 16FDBC 0026FDBC 00006290 */  lbu        $2, 0x0($3)
    /* 16FDC0 0026FDC0 FFFF4224 */  addiu      $2, $2, -0x1
    /* 16FDC4 0026FDC4 FF004430 */  andi       $4, $2, 0xFF
    /* 16FDC8 0026FDC8 01006390 */  lbu        $3, 0x1($3)
    /* 16FDCC 0026FDCC FF000224 */  addiu      $2, $0, 0xFF
    /* 16FDD0 0026FDD0 04006214 */  bne        $3, $2, .L0026FDE4
    /* 16FDD4 0026FDD4 00000000 */   nop
    /* 16FDD8 0026FDD8 2D100000 */  daddu      $2, $0, $0
    /* 16FDDC 0026FDDC 03000010 */  b          .L0026FDEC
    /* 16FDE0 0026FDE0 00000000 */   nop
  .L0026FDE4:
    /* 16FDE4 0026FDE4 FFFF6224 */  addiu      $2, $3, -0x1
    /* 16FDE8 0026FDE8 FF004230 */  andi       $2, $2, 0xFF
  .L0026FDEC:
    /* 16FDEC 0026FDEC FF004230 */  andi       $2, $2, 0xFF
    /* 16FDF0 0026FDF0 001A0200 */  sll        $3, $2, 8
    /* 16FDF4 0026FDF4 FF008230 */  andi       $2, $4, 0xFF
    /* 16FDF8 0026FDF8 25106200 */  or         $2, $3, $2
    /* 16FDFC 0026FDFC 3C140200 */  dsll32     $2, $2, 16
    /* 16FE00 0026FE00 3F140200 */  dsra32     $2, $2, 16
    /* 16FE04 0026FE04 FFFF5430 */  andi       $20, $2, 0xFFFF
    /* 16FE08 0026FE08 1800238E */  lw         $3, 0x18($17)
    /* 16FE0C 0026FE0C 1000228E */  lw         $2, 0x10($17)
    /* 16FE10 0026FE10 21186200 */  addu       $3, $3, $2
    /* 16FE14 0026FE14 02006290 */  lbu        $2, 0x2($3)
    /* 16FE18 0026FE18 FFFF4224 */  addiu      $2, $2, -0x1
    /* 16FE1C 0026FE1C FF004430 */  andi       $4, $2, 0xFF
    /* 16FE20 0026FE20 03006390 */  lbu        $3, 0x3($3)
    /* 16FE24 0026FE24 FF000224 */  addiu      $2, $0, 0xFF
    /* 16FE28 0026FE28 04006214 */  bne        $3, $2, .L0026FE3C
    /* 16FE2C 0026FE2C 00000000 */   nop
    /* 16FE30 0026FE30 2D100000 */  daddu      $2, $0, $0
    /* 16FE34 0026FE34 03000010 */  b          .L0026FE44
    /* 16FE38 0026FE38 00000000 */   nop
  .L0026FE3C:
    /* 16FE3C 0026FE3C FFFF6224 */  addiu      $2, $3, -0x1
    /* 16FE40 0026FE40 FF004230 */  andi       $2, $2, 0xFF
  .L0026FE44:
    /* 16FE44 0026FE44 FF004230 */  andi       $2, $2, 0xFF
    /* 16FE48 0026FE48 001A0200 */  sll        $3, $2, 8
    /* 16FE4C 0026FE4C FF008230 */  andi       $2, $4, 0xFF
    /* 16FE50 0026FE50 25106200 */  or         $2, $3, $2
    /* 16FE54 0026FE54 3C140200 */  dsll32     $2, $2, 16
    /* 16FE58 0026FE58 3F140200 */  dsra32     $2, $2, 16
    /* 16FE5C 0026FE5C FFFF5330 */  andi       $19, $2, 0xFFFF
    /* 16FE60 0026FE60 1800238E */  lw         $3, 0x18($17)
    /* 16FE64 0026FE64 1000228E */  lw         $2, 0x10($17)
    /* 16FE68 0026FE68 21186200 */  addu       $3, $3, $2
    /* 16FE6C 0026FE6C 04006290 */  lbu        $2, 0x4($3)
    /* 16FE70 0026FE70 FFFF4224 */  addiu      $2, $2, -0x1
    /* 16FE74 0026FE74 FF004430 */  andi       $4, $2, 0xFF
    /* 16FE78 0026FE78 05006390 */  lbu        $3, 0x5($3)
    /* 16FE7C 0026FE7C FF000224 */  addiu      $2, $0, 0xFF
    /* 16FE80 0026FE80 04006214 */  bne        $3, $2, .L0026FE94
    /* 16FE84 0026FE84 00000000 */   nop
    /* 16FE88 0026FE88 2D100000 */  daddu      $2, $0, $0
    /* 16FE8C 0026FE8C 03000010 */  b          .L0026FE9C
    /* 16FE90 0026FE90 00000000 */   nop
  .L0026FE94:
    /* 16FE94 0026FE94 FFFF6224 */  addiu      $2, $3, -0x1
    /* 16FE98 0026FE98 FF004230 */  andi       $2, $2, 0xFF
  .L0026FE9C:
    /* 16FE9C 0026FE9C FF004230 */  andi       $2, $2, 0xFF
    /* 16FEA0 0026FEA0 001A0200 */  sll        $3, $2, 8
    /* 16FEA4 0026FEA4 FF008230 */  andi       $2, $4, 0xFF
    /* 16FEA8 0026FEA8 25106200 */  or         $2, $3, $2
    /* 16FEAC 0026FEAC 3C140200 */  dsll32     $2, $2, 16
    /* 16FEB0 0026FEB0 3F140200 */  dsra32     $2, $2, 16
    /* 16FEB4 0026FEB4 FFFF5230 */  andi       $18, $2, 0xFFFF
    /* 16FEB8 0026FEB8 A8D1090C */  jal        func_002746a0
    /* 16FEBC 0026FEBC 00000000 */   nop
    /* 16FEC0 0026FEC0 04004010 */  beqz       $2, .L0026FED4
    /* 16FEC4 0026FEC4 00000000 */   nop
    /* 16FEC8 0026FEC8 2D100000 */  daddu      $2, $0, $0
    /* 16FECC 0026FECC 3C000010 */  b          .L0026FFC0
    /* 16FED0 0026FED0 00000000 */   nop
  .L0026FED4:
    /* 16FED4 0026FED4 FFFF8332 */  andi       $3, $20, 0xFFFF
    /* 16FED8 0026FED8 FFFF0224 */  addiu      $2, $0, -0x1
    /* 16FEDC 0026FEDC 03006210 */  beq        $3, $2, .L0026FEEC
    /* 16FEE0 0026FEE0 00000000 */   nop
    /* 16FEE4 0026FEE4 0D003092 */  lbu        $16, 0xD($17)
    /* 16FEE8 0026FEE8 0D0034A2 */  sb         $20, 0xD($17)
  .L0026FEEC:
    /* 16FEEC 0026FEEC FFFF6232 */  andi       $2, $19, 0xFFFF
    /* 16FEF0 0026FEF0 26004010 */  beqz       $2, .L0026FF8C
    /* 16FEF4 0026FEF4 00000000 */   nop
    /* 16FEF8 0026FEF8 FFFF5332 */  andi       $19, $18, 0xFFFF
    /* 16FEFC 0026FEFC 2D206002 */  daddu      $4, $19, $0
    /* 16FF00 0026FF00 D8B8090C */  jal        func_0026e360
    /* 16FF04 0026FF04 00000000 */   nop
    /* 16FF08 0026FF08 0C00412C */  sltiu      $1, $2, 0xC
    /* 16FF0C 0026FF0C 0B002010 */  beqz       $1, .L0026FF3C
    /* 16FF10 0026FF10 00000000 */   nop
    /* 16FF14 0026FF14 7500033C */  lui        $3, %hi(jtbl_007480D0)
    /* 16FF18 0026FF18 D0806324 */  addiu      $3, $3, %lo(jtbl_007480D0)
    /* 16FF1C 0026FF1C 80100200 */  sll        $2, $2, 2
    /* 16FF20 0026FF20 21104300 */  addu       $2, $2, $3
    /* 16FF24 0026FF24 0000428C */  lw         $2, 0x0($2)
    /* 16FF28 0026FF28 08004000 */  jr         $2
    /* 16FF2C 0026FF2C 00000000 */   nop
    /* 16FF30 0026FF30 01000224 */  addiu      $2, $0, 0x1
    /* 16FF34 0026FF34 02000010 */  b          .L0026FF40
    /* 16FF38 0026FF38 00000000 */   nop
  .L0026FF3C:
    /* 16FF3C 0026FF3C 2D100000 */  daddu      $2, $0, $0
  .L0026FF40:
    /* 16FF40 0026FF40 03004010 */  beqz       $2, .L0026FF50
    /* 16FF44 0026FF44 00000000 */   nop
    /* 16FF48 0026FF48 04000224 */  addiu      $2, $0, 0x4
    /* 16FF4C 0026FF4C 0D0022A2 */  sb         $2, 0xD($17)
  .L0026FF50:
    /* 16FF50 0026FF50 83FF0224 */  addiu      $2, $0, -0x7D
    /* 16FF54 0026FF54 6800A2A3 */  sb         $2, 0x68($29)
    /* 16FF58 0026FF58 2D206002 */  daddu      $4, $19, $0
    /* 16FF5C 0026FF5C D8B8090C */  jal        func_0026e360
    /* 16FF60 0026FF60 00000000 */   nop
    /* 16FF64 0026FF64 C7004224 */  addiu      $2, $2, 0xC7
    /* 16FF68 0026FF68 6900A2A3 */  sb         $2, 0x69($29)
    /* 16FF6C 0026FF6C 6A00A0A3 */  sb         $0, 0x6A($29)
    /* 16FF70 0026FF70 2D202002 */  daddu      $4, $17, $0
    /* 16FF74 0026FF74 DCCF090C */  jal        func_00273f70
    /* 16FF78 0026FF78 00000000 */   nop
    /* 16FF7C 0026FF7C 6800A427 */  addiu      $4, $29, 0x68
    /* 16FF80 0026FF80 2D282002 */  daddu      $5, $17, $0
    /* 16FF84 0026FF84 30CF090C */  jal        func_00273cc0
    /* 16FF88 0026FF88 00000000 */   nop
  .L0026FF8C:
    /* 16FF8C 0026FF8C 2D202002 */  daddu      $4, $17, $0
    /* 16FF90 0026FF90 DCCF090C */  jal        func_00273f70
    /* 16FF94 0026FF94 00000000 */   nop
    /* 16FF98 0026FF98 3C241200 */  dsll32     $4, $18, 16
    /* 16FF9C 0026FF9C 3F240400 */  dsra32     $4, $4, 16
    /* 16FFA0 0026FFA0 FC19040C */  jal        func_001067f0
    /* 16FFA4 0026FFA4 00000000 */   nop
    /* 16FFA8 0026FFA8 2D204000 */  daddu      $4, $2, $0
    /* 16FFAC 0026FFAC 2D282002 */  daddu      $5, $17, $0
    /* 16FFB0 0026FFB0 30CF090C */  jal        func_00273cc0
    /* 16FFB4 0026FFB4 00000000 */   nop
    /* 16FFB8 0026FFB8 0D0030A2 */  sb         $16, 0xD($17)
    /* 16FFBC 0026FFBC 2D100000 */  daddu      $2, $0, $0
  .L0026FFC0:
    /* 16FFC0 0026FFC0 5000BFDF */  ld         $31, 0x50($29)
    /* 16FFC4 0026FFC4 4000B47B */  lq         $20, 0x40($29)
    /* 16FFC8 0026FFC8 3000B37B */  lq         $19, 0x30($29)
    /* 16FFCC 0026FFCC 2000B27B */  lq         $18, 0x20($29)
    /* 16FFD0 0026FFD0 1000B17B */  lq         $17, 0x10($29)
    /* 16FFD4 0026FFD4 0000B07B */  lq         $16, 0x0($29)
    /* 16FFD8 0026FFD8 7000BD27 */  addiu      $29, $29, 0x70
    /* 16FFDC 0026FFDC 0800E003 */  jr         $31
    /* 16FFE0 0026FFE0 00000000 */   nop
    /* 16FFE4 0026FFE4 00000000 */  nop
    /* 16FFE8 0026FFE8 00000000 */  nop
    /* 16FFEC 0026FFEC 00000000 */  nop
.size func_0026fd90, 0x260
