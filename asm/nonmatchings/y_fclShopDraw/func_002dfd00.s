.section .text
.set noat
.set noreorder
glabel func_002dfd00
    /* 1DFD00 002DFD00 FFFF8330 */  andi       $3, $4, 0xFFFF
    /* 1DFD04 002DFD04 40050224 */  addiu      $2, $0, 0x540
    /* 1DFD08 002DFD08 34006210 */  beq        $3, $2, .L002DFDDC
    /* 1DFD0C 002DFD0C 00000000 */   nop
    /* 1DFD10 002DFD10 03050224 */  addiu      $2, $0, 0x503
    /* 1DFD14 002DFD14 31006210 */  beq        $3, $2, .L002DFDDC
    /* 1DFD18 002DFD18 00000000 */   nop
    /* 1DFD1C 002DFD1C 96050224 */  addiu      $2, $0, 0x596
    /* 1DFD20 002DFD20 2E006210 */  beq        $3, $2, .L002DFDDC
    /* 1DFD24 002DFD24 00000000 */   nop
    /* 1DFD28 002DFD28 17050224 */  addiu      $2, $0, 0x517
    /* 1DFD2C 002DFD2C 2B006210 */  beq        $3, $2, .L002DFDDC
    /* 1DFD30 002DFD30 00000000 */   nop
    /* 1DFD34 002DFD34 2C050224 */  addiu      $2, $0, 0x52C
    /* 1DFD38 002DFD38 28006210 */  beq        $3, $2, .L002DFDDC
    /* 1DFD3C 002DFD3C 00000000 */   nop
    /* 1DFD40 002DFD40 55050224 */  addiu      $2, $0, 0x555
    /* 1DFD44 002DFD44 25006210 */  beq        $3, $2, .L002DFDDC
    /* 1DFD48 002DFD48 00000000 */   nop
    /* 1DFD4C 002DFD4C 4D050224 */  addiu      $2, $0, 0x54D
    /* 1DFD50 002DFD50 22006210 */  beq        $3, $2, .L002DFDDC
    /* 1DFD54 002DFD54 00000000 */   nop
    /* 1DFD58 002DFD58 4B050224 */  addiu      $2, $0, 0x54B
    /* 1DFD5C 002DFD5C 1F006210 */  beq        $3, $2, .L002DFDDC
    /* 1DFD60 002DFD60 00000000 */   nop
    /* 1DFD64 002DFD64 6A050224 */  addiu      $2, $0, 0x56A
    /* 1DFD68 002DFD68 1C006210 */  beq        $3, $2, .L002DFDDC
    /* 1DFD6C 002DFD6C 00000000 */   nop
    /* 1DFD70 002DFD70 19050224 */  addiu      $2, $0, 0x519
    /* 1DFD74 002DFD74 19006210 */  beq        $3, $2, .L002DFDDC
    /* 1DFD78 002DFD78 00000000 */   nop
    /* 1DFD7C 002DFD7C 98050224 */  addiu      $2, $0, 0x598
    /* 1DFD80 002DFD80 16006210 */  beq        $3, $2, .L002DFDDC
    /* 1DFD84 002DFD84 00000000 */   nop
    /* 1DFD88 002DFD88 82050224 */  addiu      $2, $0, 0x582
    /* 1DFD8C 002DFD8C 13006210 */  beq        $3, $2, .L002DFDDC
    /* 1DFD90 002DFD90 00000000 */   nop
    /* 1DFD94 002DFD94 99050224 */  addiu      $2, $0, 0x599
    /* 1DFD98 002DFD98 10006210 */  beq        $3, $2, .L002DFDDC
    /* 1DFD9C 002DFD9C 00000000 */   nop
    /* 1DFDA0 002DFDA0 1A050224 */  addiu      $2, $0, 0x51A
    /* 1DFDA4 002DFDA4 0D006210 */  beq        $3, $2, .L002DFDDC
    /* 1DFDA8 002DFDA8 00000000 */   nop
    /* 1DFDAC 002DFDAC 9A050224 */  addiu      $2, $0, 0x59A
    /* 1DFDB0 002DFDB0 0A006210 */  beq        $3, $2, .L002DFDDC
    /* 1DFDB4 002DFDB4 00000000 */   nop
    /* 1DFDB8 002DFDB8 80050224 */  addiu      $2, $0, 0x580
    /* 1DFDBC 002DFDBC 07006210 */  beq        $3, $2, .L002DFDDC
    /* 1DFDC0 002DFDC0 00000000 */   nop
    /* 1DFDC4 002DFDC4 59050224 */  addiu      $2, $0, 0x559
    /* 1DFDC8 002DFDC8 04006210 */  beq        $3, $2, .L002DFDDC
    /* 1DFDCC 002DFDCC 00000000 */   nop
    /* 1DFDD0 002DFDD0 9B050224 */  addiu      $2, $0, 0x59B
    /* 1DFDD4 002DFDD4 04006214 */  bne        $3, $2, .L002DFDE8
    /* 1DFDD8 002DFDD8 00000000 */   nop
  .L002DFDDC:
    /* 1DFDDC 002DFDDC 01000224 */  addiu      $2, $0, 0x1
    /* 1DFDE0 002DFDE0 02000010 */  b          .L002DFDEC
    /* 1DFDE4 002DFDE4 00000000 */   nop
  .L002DFDE8:
    /* 1DFDE8 002DFDE8 2D100000 */  daddu      $2, $0, $0
  .L002DFDEC:
    /* 1DFDEC 002DFDEC 0800E003 */  jr         $31
    /* 1DFDF0 002DFDF0 00000000 */   nop
    /* 1DFDF4 002DFDF4 00000000 */  nop
    /* 1DFDF8 002DFDF8 00000000 */  nop
    /* 1DFDFC 002DFDFC 00000000 */  nop
.size func_002dfd00, 0x100
