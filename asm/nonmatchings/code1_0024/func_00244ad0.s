.section .text
.set noat
.set noreorder
glabel func_00244ad0
    /* 144AD0 00244AD0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 144AD4 00244AD4 0000BFFF */  sd         $31, 0x0($29)
    /* 144AD8 00244AD8 2019090C */  jal        func_00246480
    /* 144ADC 00244ADC 00000000 */   nop
    /* 144AE0 00244AE0 15000424 */  addiu      $4, $0, 0x15
    /* 144AE4 00244AE4 2D280000 */  daddu      $5, $0, $0
    /* 144AE8 00244AE8 0C14090C */  jal        func_00245030
    /* 144AEC 00244AEC 00000000 */   nop
    /* 144AF0 00244AF0 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 144AF4 00244AF4 00000444 */  mfc1       $4, $f0
    /* 144AF8 00244AF8 1419090C */  jal        func_00246450
    /* 144AFC 00244AFC 00000000 */   nop
    /* 144B00 00244B00 0000BFDF */  ld         $31, 0x0($29)
    /* 144B04 00244B04 1000BD27 */  addiu      $29, $29, 0x10
    /* 144B08 00244B08 0800E003 */  jr         $31
    /* 144B0C 00244B0C 00000000 */   nop
.size func_00244ad0, 0x40
