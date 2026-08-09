.section .text
.set noat
.set noreorder
glabel func_0050dcd0
    /* 40DCD0 0050DCD0 40FFBD27 */  addiu      $29, $29, -0xC0
    /* 40DCD4 0050DCD4 B000B0FF */  sd         $16, 0xB0($29)
    /* 40DCD8 0050DCD8 B800BFFF */  sd         $31, 0xB8($29)
    /* 40DCDC 0050DCDC 0A35140C */  jal        func_0050d428
    /* 40DCE0 0050DCE0 2D808000 */   daddu     $16, $4, $0
    /* 40DCE4 0050DCE4 01000324 */  addiu      $3, $0, 0x1
    /* 40DCE8 0050DCE8 2D28A003 */  daddu      $5, $29, $0
    /* 40DCEC 0050DCEC 06004310 */  beq        $2, $3, .L0050DD08
    /* 40DCF0 0050DCF0 2D200002 */   daddu     $4, $16, $0
    /* 40DCF4 0050DCF4 7600043C */  lui        $4, %hi(D_0075F518)
    /* 40DCF8 0050DCF8 8844140C */  jal        func_00511220
    /* 40DCFC 0050DCFC 18F58424 */   addiu     $4, $4, %lo(D_0075F518)
    /* 40DD00 0050DD00 04000010 */  b          .L0050DD14
    /* 40DD04 0050DD04 2D100000 */   daddu     $2, $0, $0
  .L0050DD08:
    /* 40DD08 0050DD08 AE34140C */  jal        func_0050d2b8
    /* 40DD0C 0050DD0C 00000000 */   nop
    /* 40DD10 0050DD10 1000A28F */  lw         $2, 0x10($29)
  .L0050DD14:
    /* 40DD14 0050DD14 B000B0DF */  ld         $16, 0xB0($29)
    /* 40DD18 0050DD18 B800BFDF */  ld         $31, 0xB8($29)
    /* 40DD1C 0050DD1C 0800E003 */  jr         $31
    /* 40DD20 0050DD20 C000BD27 */   addiu     $29, $29, 0xC0
    /* 40DD24 0050DD24 00000000 */  nop
.size func_0050dcd0, 0x58
