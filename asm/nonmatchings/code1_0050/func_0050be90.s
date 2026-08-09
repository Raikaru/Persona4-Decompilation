.section .text
.set noat
.set noreorder
glabel func_0050be90
    /* 40BE90 0050BE90 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40BE94 0050BE94 2D100000 */  daddu      $2, $0, $0
    /* 40BE98 0050BE98 0000BFFF */  sd         $31, 0x0($29)
    /* 40BE9C 0050BE9C 3C00838C */  lw         $3, 0x3C($4)
    /* 40BEA0 0050BEA0 0E006010 */  beqz       $3, .L0050BEDC
    /* 40BEA4 0050BEA4 2D206000 */   daddu     $4, $3, $0
    /* 40BEA8 0050BEA8 0685140C */  jal        func_00521418
    /* 40BEAC 0050BEAC 00000000 */   nop
    /* 40BEB0 0050BEB0 01000424 */  addiu      $4, $0, 0x1
    /* 40BEB4 0050BEB4 08004010 */  beqz       $2, .L0050BED8
    /* 40BEB8 0050BEB8 2D180000 */   daddu     $3, $0, $0
    /* 40BEBC 0050BEBC 06004410 */  beq        $2, $4, .L0050BED8
    /* 40BEC0 0050BEC0 01000324 */   addiu     $3, $0, 0x1
    /* 40BEC4 0050BEC4 7600043C */  lui        $4, %hi(D_0075ECF8)
    /* 40BEC8 0050BEC8 2D284000 */  daddu      $5, $2, $0
    /* 40BECC 0050BECC 8844140C */  jal        func_00511220
    /* 40BED0 0050BED0 F8EC8424 */   addiu     $4, $4, %lo(D_0075ECF8)
    /* 40BED4 0050BED4 2D180000 */  daddu      $3, $0, $0
  .L0050BED8:
    /* 40BED8 0050BED8 2D106000 */  daddu      $2, $3, $0
  .L0050BEDC:
    /* 40BEDC 0050BEDC 0000BFDF */  ld         $31, 0x0($29)
    /* 40BEE0 0050BEE0 0800E003 */  jr         $31
    /* 40BEE4 0050BEE4 1000BD27 */   addiu     $29, $29, 0x10
.size func_0050be90, 0x58
