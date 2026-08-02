.section .text
.set noat
.set noreorder
glabel func_0035cab0
    /* 25CAB0 0035CAB0 80100500 */  sll        $2, $5, 2
    /* 25CAB4 0035CAB4 21184400 */  addu       $3, $2, $4
    /* 25CAB8 0035CAB8 3000628C */  lw         $2, 0x30($3)
    /* 25CABC 0035CABC 340062AC */  sw         $2, 0x34($3)
    /* 25CAC0 0035CAC0 300066AC */  sw         $6, 0x30($3)
    /* 25CAC4 0035CAC4 0900A014 */  bnez       $5, .L0035CAEC
    /* 25CAC8 0035CAC8 00000000 */   nop
    /* 25CACC 0035CACC 06000224 */  addiu      $2, $0, 0x6
    /* 25CAD0 0035CAD0 0400C214 */  bne        $6, $2, .L0035CAE4
    /* 25CAD4 0035CAD4 00000000 */   nop
    /* 25CAD8 0035CAD8 380080A4 */  sh         $0, 0x38($4)
    /* 25CADC 0035CADC 03000010 */  b          .L0035CAEC
    /* 25CAE0 0035CAE0 00000000 */   nop
  .L0035CAE4:
    /* 25CAE4 0035CAE4 12000224 */  addiu      $2, $0, 0x12
    /* 25CAE8 0035CAE8 380082A4 */  sh         $2, 0x38($4)
  .L0035CAEC:
    /* 25CAEC 0035CAEC 01000224 */  addiu      $2, $0, 0x1
    /* 25CAF0 0035CAF0 0800E003 */  jr         $31
    /* 25CAF4 0035CAF4 00000000 */   nop
    /* 25CAF8 0035CAF8 00000000 */  nop
    /* 25CAFC 0035CAFC 00000000 */  nop
.size func_0035cab0, 0x50
