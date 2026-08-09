.section .text
.set noat
.set noreorder
glabel func_0050dfe0
    /* 40DFE0 0050DFE0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40DFE4 0050DFE4 2D188000 */  daddu      $3, $4, $0
    /* 40DFE8 0050DFE8 0000BFFF */  sd         $31, 0x0($29)
    /* 40DFEC 0050DFEC 0C00628C */  lw         $2, 0xC($3)
    /* 40DFF0 0050DFF0 C801678C */  lw         $7, 0x1C8($3)
    /* 40DFF4 0050DFF4 FF3F4524 */  addiu      $5, $2, 0x3FFF
    /* 40DFF8 0050DFF8 00004328 */  slti       $3, $2, 0x0
    /* 40DFFC 0050DFFC 0B10A300 */  movn       $2, $5, $3
    /* 40E000 0050E000 0000BFDF */  ld         $31, 0x0($29)
    /* 40E004 0050E004 83130200 */  sra        $2, $2, 14
    /* 40E008 0050E008 2D30E000 */  daddu      $6, $7, $0
    /* 40E00C 0050E00C C0120200 */  sll        $2, $2, 11
    /* 40E010 0050E010 00008244 */  mtc1       $2, $f0
    /* 40E014 0050E014 20008046 */  cvt.s.w    $f0, $f0
    /* 40E018 0050E018 02000C46 */  mul.s      $f0, $f0, $f12
    /* 40E01C 0050E01C 64000046 */  .word      0x46000064                    # cvt.w.s    $f1, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 40E020 0050E020 00080544 */  mfc1       $5, $f1
    /* 40E024 0050E024 2A10E500 */  slt        $2, $7, $5
    /* 40E028 0050E028 0B28E200 */  movn       $5, $7, $2
    /* 40E02C 0050E02C E0341408 */  j          func_0050d380
    /* 40E030 0050E030 1000BD27 */   addiu     $29, $29, 0x10
    /* 40E034 0050E034 00000000 */  nop
.size func_0050dfe0, 0x58
