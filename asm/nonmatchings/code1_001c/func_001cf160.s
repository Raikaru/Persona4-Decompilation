.section .text
.set noat
.set noreorder
glabel func_001cf160
    /* CF160 001CF160 E0FFBD27 */  addiu      $29, $29, -0x20
    /* CF164 001CF164 1000BFFF */  sd         $31, 0x10($29)
    /* CF168 001CF168 0000B07F */  sq         $16, 0x0($29)
    /* CF16C 001CF16C 2D808000 */  daddu      $16, $4, $0
    /* CF170 001CF170 68010424 */  addiu      $4, $0, 0x168
    /* CF174 001CF174 5CC7080C */  jal        func_00231d70
    /* CF178 001CF178 00000000 */   nop
    /* CF17C 001CF17C 06004004 */  bltz       $2, .L001CF198
    /* CF180 001CF180 00000000 */   nop
    /* CF184 001CF184 00008244 */  mtc1       $2, $f0
    /* CF188 001CF188 00000000 */  nop
    /* CF18C 001CF18C 20008046 */  cvt.s.w    $f0, $f0
    /* CF190 001CF190 08000010 */  b          .L001CF1B4
    /* CF194 001CF194 00000000 */   nop
  .L001CF198:
    /* CF198 001CF198 42180200 */  srl        $3, $2, 1
    /* CF19C 001CF19C 01004230 */  andi       $2, $2, 0x1
    /* CF1A0 001CF1A0 25186200 */  or         $3, $3, $2
    /* CF1A4 001CF1A4 00008344 */  mtc1       $3, $f0
    /* CF1A8 001CF1A8 00000000 */  nop
    /* CF1AC 001CF1AC 20008046 */  cvt.s.w    $f0, $f0
    /* CF1B0 001CF1B0 00000046 */  add.s      $f0, $f0, $f0
  .L001CF1B4:
    /* CF1B4 001CF1B4 000100E6 */  swc1       $f0, 0x100($16)
    /* CF1B8 001CF1B8 00608044 */  mtc1       $0, $f12
    /* CF1BC 001CF1BC E000048E */  lw         $4, 0xE0($16)
    /* CF1C0 001CF1C0 2D280000 */  daddu      $5, $0, $0
    /* CF1C4 001CF1C4 2D300000 */  daddu      $6, $0, $0
    /* CF1C8 001CF1C8 00010724 */  addiu      $7, $0, 0x100
    /* CF1CC 001CF1CC 50F3060C */  jal        func_001bcd40
    /* CF1D0 001CF1D0 00000000 */   nop
    /* CF1D4 001CF1D4 1000BFDF */  ld         $31, 0x10($29)
    /* CF1D8 001CF1D8 0000B07B */  lq         $16, 0x0($29)
    /* CF1DC 001CF1DC 2000BD27 */  addiu      $29, $29, 0x20
    /* CF1E0 001CF1E0 0800E003 */  jr         $31
    /* CF1E4 001CF1E4 00000000 */   nop
    /* CF1E8 001CF1E8 00000000 */  nop
    /* CF1EC 001CF1EC 00000000 */  nop
.size func_001cf160, 0x90
