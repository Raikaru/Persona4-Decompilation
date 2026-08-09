.section .text
.set noat
.set noreorder
glabel func_0016fe80
    /* 6FE80 0016FE80 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 6FE84 0016FE84 1000BFFF */  sd         $31, 0x10($29)
    /* 6FE88 0016FE88 0000B07F */  sq         $16, 0x0($29)
    /* 6FE8C 0016FE8C 01000224 */  addiu      $2, $0, 0x1
    /* 6FE90 0016FE90 03008210 */  beq        $4, $2, .L0016FEA0
    /* 6FE94 0016FE94 00000000 */   nop
    /* 6FE98 0016FE98 43000010 */  b          .L0016FFA8
    /* 6FE9C 0016FE9C 00000000 */   nop
  .L0016FEA0:
    /* 6FEA0 0016FEA0 B09D828F */  lw         $2, -0x6250($28)
    /* 6FEA4 0016FEA4 00004494 */  lhu        $4, 0x0($2)
    /* 6FEA8 0016FEA8 04004594 */  lhu        $5, 0x4($2)
    /* 6FEAC 0016FEAC 4489050C */  jal        func_00162510
    /* 6FEB0 0016FEB0 00000000 */   nop
    /* 6FEB4 0016FEB4 01000524 */  addiu      $5, $0, 0x1
    /* 6FEB8 0016FEB8 12004514 */  bne        $2, $5, .L0016FF04
    /* 6FEBC 0016FEBC 00000000 */   nop
    /* 6FEC0 0016FEC0 03001024 */  addiu      $16, $0, 0x3
    /* 6FEC4 0016FEC4 FC88050C */  jal        func_001623f0
    /* 6FEC8 0016FEC8 00000000 */   nop
    /* 6FECC 0016FECC 01000324 */  addiu      $3, $0, 0x1
    /* 6FED0 0016FED0 04004314 */  bne        $2, $3, .L0016FEE4
    /* 6FED4 0016FED4 00000000 */   nop
    /* 6FED8 0016FED8 0A001024 */  addiu      $16, $0, 0xA
    /* 6FEDC 0016FEDC 33000010 */  b          .L0016FFAC
    /* 6FEE0 0016FEE0 00000000 */   nop
  .L0016FEE4:
    /* 6FEE4 0016FEE4 010C0424 */  addiu      $4, $0, 0xC01
    /* 6FEE8 0016FEE8 CC18040C */  jal        func_00106330
    /* 6FEEC 0016FEEC 00000000 */   nop
    /* 6FEF0 0016FEF0 2E004010 */  beqz       $2, .L0016FFAC
    /* 6FEF4 0016FEF4 00000000 */   nop
    /* 6FEF8 0016FEF8 FFFF1026 */  addiu      $16, $16, -0x1
    /* 6FEFC 0016FEFC 2B000010 */  b          .L0016FFAC
    /* 6FF00 0016FF00 00000000 */   nop
  .L0016FF04:
    /* 6FF04 0016FF04 B09D848F */  lw         $4, -0x6250($28)
    /* 6FF08 0016FF08 0000838C */  lw         $3, 0x0($4)
    /* 6FF0C 0016FF0C 44000224 */  addiu      $2, $0, 0x44
    /* 6FF10 0016FF10 0D006214 */  bne        $3, $2, .L0016FF48
    /* 6FF14 0016FF14 00000000 */   nop
    /* 6FF18 0016FF18 0400828C */  lw         $2, 0x4($4)
    /* 6FF1C 0016FF1C 0A004514 */  bne        $2, $5, .L0016FF48
    /* 6FF20 0016FF20 00000000 */   nop
    /* 6FF24 0016FF24 03001024 */  addiu      $16, $0, 0x3
    /* 6FF28 0016FF28 010C0424 */  addiu      $4, $0, 0xC01
    /* 6FF2C 0016FF2C CC18040C */  jal        func_00106330
    /* 6FF30 0016FF30 00000000 */   nop
    /* 6FF34 0016FF34 1D004010 */  beqz       $2, .L0016FFAC
    /* 6FF38 0016FF38 00000000 */   nop
    /* 6FF3C 0016FF3C FFFF1026 */  addiu      $16, $16, -0x1
    /* 6FF40 0016FF40 1A000010 */  b          .L0016FFAC
    /* 6FF44 0016FF44 00000000 */   nop
  .L0016FF48:
    /* 6FF48 0016FF48 5868050C */  jal        func_0015a160
    /* 6FF4C 0016FF4C 00000000 */   nop
    /* 6FF50 0016FF50 04004010 */  beqz       $2, .L0016FF64
    /* 6FF54 0016FF54 00000000 */   nop
    /* 6FF58 0016FF58 02001024 */  addiu      $16, $0, 0x2
    /* 6FF5C 0016FF5C 13000010 */  b          .L0016FFAC
    /* 6FF60 0016FF60 00000000 */   nop
  .L0016FF64:
    /* 6FF64 0016FF64 03001024 */  addiu      $16, $0, 0x3
    /* 6FF68 0016FF68 FC88050C */  jal        func_001623f0
    /* 6FF6C 0016FF6C 00000000 */   nop
    /* 6FF70 0016FF70 01000324 */  addiu      $3, $0, 0x1
    /* 6FF74 0016FF74 04004314 */  bne        $2, $3, .L0016FF88
    /* 6FF78 0016FF78 00000000 */   nop
    /* 6FF7C 0016FF7C 0A001024 */  addiu      $16, $0, 0xA
    /* 6FF80 0016FF80 0A000010 */  b          .L0016FFAC
    /* 6FF84 0016FF84 00000000 */   nop
  .L0016FF88:
    /* 6FF88 0016FF88 010C0424 */  addiu      $4, $0, 0xC01
    /* 6FF8C 0016FF8C CC18040C */  jal        func_00106330
    /* 6FF90 0016FF90 00000000 */   nop
    /* 6FF94 0016FF94 05004010 */  beqz       $2, .L0016FFAC
    /* 6FF98 0016FF98 00000000 */   nop
    /* 6FF9C 0016FF9C FFFF1026 */  addiu      $16, $16, -0x1
    /* 6FFA0 0016FFA0 02000010 */  b          .L0016FFAC
    /* 6FFA4 0016FFA4 00000000 */   nop
  .L0016FFA8:
    /* 6FFA8 0016FFA8 02001024 */  addiu      $16, $0, 0x2
  .L0016FFAC:
    /* 6FFAC 0016FFAC 2D100002 */  daddu      $2, $16, $0
    /* 6FFB0 0016FFB0 1000BFDF */  ld         $31, 0x10($29)
    /* 6FFB4 0016FFB4 0000B07B */  lq         $16, 0x0($29)
    /* 6FFB8 0016FFB8 2000BD27 */  addiu      $29, $29, 0x20
    /* 6FFBC 0016FFBC 0800E003 */  jr         $31
    /* 6FFC0 0016FFC0 00000000 */   nop
    /* 6FFC4 0016FFC4 00000000 */  nop
    /* 6FFC8 0016FFC8 00000000 */  nop
    /* 6FFCC 0016FFCC 00000000 */  nop
.size func_0016fe80, 0x150
