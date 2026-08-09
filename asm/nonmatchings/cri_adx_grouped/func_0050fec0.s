.section .text
.set noat
.set noreorder
glabel func_0050fec0
    /* 40FEC0 0050FEC0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 40FEC4 0050FEC4 0000B0FF */  sd         $16, 0x0($29)
    /* 40FEC8 0050FEC8 2D80A000 */  daddu      $16, $5, $0
    /* 40FECC 0050FECC 0800B1FF */  sd         $17, 0x8($29)
    /* 40FED0 0050FED0 1000BFFF */  sd         $31, 0x10($29)
    /* 40FED4 0050FED4 0A35140C */  jal        func_0050d428
    /* 40FED8 0050FED8 2D888000 */   daddu     $17, $4, $0
    /* 40FEDC 0050FEDC 7600043C */  lui        $4, %hi(D_0075FD40)
    /* 40FEE0 0050FEE0 01000324 */  addiu      $3, $0, 0x1
    /* 40FEE4 0050FEE4 40FD8424 */  addiu      $4, $4, %lo(D_0075FD40)
    /* 40FEE8 0050FEE8 07004310 */  beq        $2, $3, .L0050FF08
    /* 40FEEC 0050FEEC 2D280002 */   daddu     $5, $16, $0
    /* 40FEF0 0050FEF0 0000B0DF */  ld         $16, 0x0($29)
    /* 40FEF4 0050FEF4 0800B1DF */  ld         $17, 0x8($29)
    /* 40FEF8 0050FEF8 1000BFDF */  ld         $31, 0x10($29)
    /* 40FEFC 0050FEFC 88441408 */  j          func_00511220
    /* 40FF00 0050FF00 2000BD27 */   addiu     $29, $29, 0x20
    /* 40FF04 0050FF04 00000000 */  nop
  .L0050FF08:
    /* 40FF08 0050FF08 4800248E */  lw         $4, 0x48($17)
    /* 40FF0C 0050FF0C 0000B0DF */  ld         $16, 0x0($29)
    /* 40FF10 0050FF10 0800B1DF */  ld         $17, 0x8($29)
    /* 40FF14 0050FF14 1000BFDF */  ld         $31, 0x10($29)
    /* 40FF18 0050FF18 FAA51308 */  j          func_004e97e8
    /* 40FF1C 0050FF1C 2000BD27 */   addiu     $29, $29, 0x20
.size func_0050fec0, 0x60
