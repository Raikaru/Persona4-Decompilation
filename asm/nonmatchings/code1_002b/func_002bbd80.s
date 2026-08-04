.section .text
.set noat
.set noreorder
glabel func_002bbd80
    /* 1BBD80 002BBD80 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 1BBD84 002BBD84 0000BFFF */  sd         $31, 0x0($29)
    /* 1BBD88 002BBD88 3C1E0400 */  dsll32     $3, $4, 24
    /* 1BBD8C 002BBD8C 3F1E0300 */  dsra32     $3, $3, 24
    /* 1BBD90 002BBD90 80200300 */  sll        $4, $3, 2
    /* 1BBD94 002BBD94 8800033C */  lui        $3, %hi(D_00882F40)
    /* 1BBD98 002BBD98 402F6324 */  addiu      $3, $3, %lo(D_00882F40)
    /* 1BBD9C 002BBD9C 21186400 */  addu       $3, $3, $4
    /* 1BBDA0 002BBDA0 0000638C */  lw         $3, 0x0($3)
    /* 1BBDA4 002BBDA4 04006010 */  beqz       $3, .L002BBDB8
    /* 1BBDA8 002BBDA8 00000000 */   nop
    /* 1BBDAC 002BBDAC 0000648C */  lw         $4, 0x0($3)
    /* 1BBDB0 002BBDB0 14E1090C */  jal        func_00278450
    /* 1BBDB4 002BBDB4 00000000 */   nop
  .L002BBDB8:
    /* 1BBDB8 002BBDB8 0000BFDF */  ld         $31, 0x0($29)
    /* 1BBDBC 002BBDBC 1000BD27 */  addiu      $29, $29, 0x10
    /* 1BBDC0 002BBDC0 0800E003 */  jr         $31
    /* 1BBDC4 002BBDC4 00000000 */   nop
    /* 1BBDC8 002BBDC8 00000000 */  nop
    /* 1BBDCC 002BBDCC 00000000 */  nop
.size func_002bbd80, 0x50
