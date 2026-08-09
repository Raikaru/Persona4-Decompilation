.section .text
.set noat
.set noreorder
glabel func_0050b748
    /* 40B748 0050B748 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40B74C 0050B74C 1B000524 */  addiu      $5, $0, 0x1B
    /* 40B750 0050B750 0000BFFF */  sd         $31, 0x0($29)
    /* 40B754 0050B754 000080C4 */  lwc1       $f0, 0x0($4)
    /* 40B758 0050B758 64000046 */  .word      0x46000064                    # cvt.w.s    $f1, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 40B75C 0050B75C 00080644 */  mfc1       $6, $f1
    /* 40B760 0050B760 C834140C */  jal        func_0050d320
    /* 40B764 0050B764 2D200000 */   daddu     $4, $0, $0
    /* 40B768 0050B768 2D200000 */  daddu      $4, $0, $0
    /* 40B76C 0050B76C 0000BFDF */  ld         $31, 0x0($29)
    /* 40B770 0050B770 07000524 */  addiu      $5, $0, 0x7
    /* 40B774 0050B774 01000624 */  addiu      $6, $0, 0x1
    /* 40B778 0050B778 C8341408 */  j          func_0050d320
    /* 40B77C 0050B77C 1000BD27 */   addiu     $29, $29, 0x10
.size func_0050b748, 0x38
