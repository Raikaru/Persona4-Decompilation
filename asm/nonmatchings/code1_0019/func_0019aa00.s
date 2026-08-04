.section .text
.set noat
.set noreorder
glabel func_0019aa00
    /* 9AA00 0019AA00 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 9AA04 0019AA04 0000BFFF */  sd         $31, 0x0($29)
    /* 9AA08 0019AA08 04008584 */  lh         $5, 0x4($4)
    /* 9AA0C 0019AA0C 0000838C */  lw         $3, 0x0($4)
    /* 9AA10 0019AA10 9800628C */  lw         $2, 0x98($3)
    /* 9AA14 0019AA14 02004230 */  andi       $2, $2, 0x2
    /* 9AA18 0019AA18 08004010 */  beqz       $2, .L0019AA3C
    /* 9AA1C 0019AA1C 00000000 */   nop
    /* 9AA20 0019AA20 00008544 */  mtc1       $5, $f0
    /* 9AA24 0019AA24 00000000 */  nop
    /* 9AA28 0019AA28 20038046 */  cvt.s.w    $f12, $f0
    /* 9AA2C 0019AA2C 000A648C */  lw         $4, 0xA00($3)
    /* 9AA30 0019AA30 2D280000 */  daddu      $5, $0, $0
    /* 9AA34 0019AA34 98E7110C */  jal        func_00479e60
    /* 9AA38 0019AA38 00000000 */   nop
  .L0019AA3C:
    /* 9AA3C 0019AA3C 01000224 */  addiu      $2, $0, 0x1
    /* 9AA40 0019AA40 0000BFDF */  ld         $31, 0x0($29)
    /* 9AA44 0019AA44 1000BD27 */  addiu      $29, $29, 0x10
    /* 9AA48 0019AA48 0800E003 */  jr         $31
    /* 9AA4C 0019AA4C 00000000 */   nop
.size func_0019aa00, 0x50
