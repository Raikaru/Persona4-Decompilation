.section .text
.set noat
.set noreorder
glabel func_0050dda8
    /* 40DDA8 0050DDA8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40DDAC 0050DDAC 0000B0FF */  sd         $16, 0x0($29)
    /* 40DDB0 0050DDB0 0800BFFF */  sd         $31, 0x8($29)
    /* 40DDB4 0050DDB4 0A35140C */  jal        func_0050d428
    /* 40DDB8 0050DDB8 2D808000 */   daddu     $16, $4, $0
    /* 40DDBC 0050DDBC 7600043C */  lui        $4, %hi(D_0075F588)
    /* 40DDC0 0050DDC0 01000324 */  addiu      $3, $0, 0x1
    /* 40DDC4 0050DDC4 06004310 */  beq        $2, $3, .L0050DDE0
    /* 40DDC8 0050DDC8 88F58424 */   addiu     $4, $4, %lo(D_0075F588)
    /* 40DDCC 0050DDCC 8844140C */  jal        func_00511220
    /* 40DDD0 0050DDD0 00000000 */   nop
    /* 40DDD4 0050DDD4 03000010 */  b          .L0050DDE4
    /* 40DDD8 0050DDD8 2D100000 */   daddu     $2, $0, $0
    /* 40DDDC 0050DDDC 00000000 */  nop
  .L0050DDE0:
    /* 40DDE0 0050DDE0 C001028E */  lw         $2, 0x1C0($16)
  .L0050DDE4:
    /* 40DDE4 0050DDE4 0000B0DF */  ld         $16, 0x0($29)
    /* 40DDE8 0050DDE8 0800BFDF */  ld         $31, 0x8($29)
    /* 40DDEC 0050DDEC 0800E003 */  jr         $31
    /* 40DDF0 0050DDF0 1000BD27 */   addiu     $29, $29, 0x10
    /* 40DDF4 0050DDF4 00000000 */  nop
.size func_0050dda8, 0x50
