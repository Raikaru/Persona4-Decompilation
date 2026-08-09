.section .text
.set noat
.set noreorder
glabel func_004def18
    /* 3DEF18 004DEF18 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3DEF1C 004DEF1C 00088044 */  mtc1       $0, $f1
    /* 3DEF20 004DEF20 0000B0FF */  sd         $16, 0x0($29)
    /* 3DEF24 004DEF24 2D808000 */  daddu      $16, $4, $0
    /* 3DEF28 004DEF28 0800BFFF */  sd         $31, 0x8($29)
    /* 3DEF2C 004DEF2C E00100C6 */  lwc1       $f0, 0x1E0($16)
    /* 3DEF30 004DEF30 32000146 */  c.eq.s     $f0, $f1
    /* 3DEF34 004DEF34 10000345 */  bc1tl      .L004DEF78
    /* 3DEF38 004DEF38 1801058E */   lw        $5, 0x118($16)
    /* 3DEF3C 004DEF3C 327D130C */  jal        func_004df4c8
    /* 3DEF40 004DEF40 00000000 */   nop
    /* 3DEF44 004DEF44 E00101C6 */  lwc1       $f1, 0x1E0($16)
    /* 3DEF48 004DEF48 00008244 */  mtc1       $2, $f0
    /* 3DEF4C 004DEF4C 20008046 */  cvt.s.w    $f0, $f0
    /* 3DEF50 004DEF50 1801068E */  lw         $6, 0x118($16)
    /* 3DEF54 004DEF54 0800048E */  lw         $4, 0x8($16)
    /* 3DEF58 004DEF58 0800BFDF */  ld         $31, 0x8($29)
    /* 3DEF5C 004DEF5C 0000B0DF */  ld         $16, 0x0($29)
    /* 3DEF60 004DEF60 02000146 */  mul.s      $f0, $f0, $f1
    /* 3DEF64 004DEF64 64000046 */  .word      0x46000064                    # cvt.w.s    $f1, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 3DEF68 004DEF68 00080544 */  mfc1       $5, $f1
    /* 3DEF6C 004DEF6C 0C4B1308 */  j          func_004d2c30
    /* 3DEF70 004DEF70 1000BD27 */   addiu     $29, $29, 0x10
    /* 3DEF74 004DEF74 00000000 */  nop
  .L004DEF78:
    /* 3DEF78 004DEF78 0800048E */  lw         $4, 0x8($16)
    /* 3DEF7C 004DEF7C C2170500 */  srl        $2, $5, 31
    /* 3DEF80 004DEF80 2D30A000 */  daddu      $6, $5, $0
    /* 3DEF84 004DEF84 0000B0DF */  ld         $16, 0x0($29)
    /* 3DEF88 004DEF88 2128A200 */  addu       $5, $5, $2
    /* 3DEF8C 004DEF8C 0800BFDF */  ld         $31, 0x8($29)
    /* 3DEF90 004DEF90 43280500 */  sra        $5, $5, 1
    /* 3DEF94 004DEF94 0C4B1308 */  j          func_004d2c30
    /* 3DEF98 004DEF98 1000BD27 */   addiu     $29, $29, 0x10
    /* 3DEF9C 004DEF9C 00000000 */  nop
.size func_004def18, 0x88
