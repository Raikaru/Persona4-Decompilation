.section .text
.set noat
.set noreorder
glabel func_0029cf90
    /* 19CF90 0029CF90 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 19CF94 0029CF94 1000BFFF */  sd         $31, 0x10($29)
    /* 19CF98 0029CF98 0000B07F */  sq         $16, 0x0($29)
    /* 19CF9C 0029CF9C 2D808000 */  daddu      $16, $4, $0
    /* 19CFA0 0029CFA0 06000106 */  bgez       $16, .L0029CFBC
    /* 19CFA4 0029CFA4 00000000 */   nop
    /* 19CFA8 0029CFA8 6400043C */  lui        $4, %hi(D_0063E068)
    /* 19CFAC 0029CFAC 68E08424 */  addiu      $4, $4, %lo(D_0063E068)
    /* 19CFB0 0029CFB0 8D040524 */  addiu      $5, $0, 0x48D
    /* 19CFB4 0029CFB4 CCB5110C */  jal        func_0046d730
    /* 19CFB8 0029CFB8 00000000 */   nop
  .L0029CFBC:
    /* 19CFBC 0029CFBC 10B5828F */  lw         $2, -0x4AF0($28)
    /* 19CFC0 0029CFC0 1401428C */  lw         $2, 0x114($2)
    /* 19CFC4 0029CFC4 1800428C */  lw         $2, 0x18($2)
    /* 19CFC8 0029CFC8 2A100202 */  slt        $2, $16, $2
    /* 19CFCC 0029CFCC 06004014 */  bnez       $2, .L0029CFE8
    /* 19CFD0 0029CFD0 00000000 */   nop
    /* 19CFD4 0029CFD4 6400043C */  lui        $4, %hi(D_0063E068)
    /* 19CFD8 0029CFD8 68E08424 */  addiu      $4, $4, %lo(D_0063E068)
    /* 19CFDC 0029CFDC 8E040524 */  addiu      $5, $0, 0x48E
    /* 19CFE0 0029CFE0 CCB5110C */  jal        func_0046d730
    /* 19CFE4 0029CFE4 00000000 */   nop
  .L0029CFE8:
    /* 19CFE8 0029CFE8 10B5828F */  lw         $2, -0x4AF0($28)
    /* 19CFEC 0029CFEC 1C01438C */  lw         $3, 0x11C($2)
    /* 19CFF0 0029CFF0 40111000 */  sll        $2, $16, 5
    /* 19CFF4 0029CFF4 21104300 */  addu       $2, $2, $3
    /* 19CFF8 0029CFF8 1800428C */  lw         $2, 0x18($2)
    /* 19CFFC 0029CFFC 1000BFDF */  ld         $31, 0x10($29)
    /* 19D000 0029D000 0000B07B */  lq         $16, 0x0($29)
    /* 19D004 0029D004 2000BD27 */  addiu      $29, $29, 0x20
    /* 19D008 0029D008 0800E003 */  jr         $31
    /* 19D00C 0029D00C 00000000 */   nop
.size func_0029cf90, 0x80
