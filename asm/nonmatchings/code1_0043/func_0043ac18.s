.section .text
.set noat
.set noreorder
glabel func_0043ac18
    /* 33AC18 0043AC18 7100033C */  lui        $3, %hi(D_0070FC40)
    /* 33AC1C 0043AC1C F0FFBD27 */  addiu      $29, $29, -0x10
    /* 33AC20 0043AC20 40FC628C */  lw         $2, %lo(D_0070FC40)($3)
    /* 33AC24 0043AC24 03004014 */  bnez       $2, .L0043AC34
    /* 33AC28 0043AC28 0000BFFF */   sd        $31, 0x0($29)
    /* 33AC2C 0043AC2C 09000010 */  b          .L0043AC54
    /* 33AC30 0043AC30 2D100000 */   daddu     $2, $0, $0
  .L0043AC34:
    /* 33AC34 0043AC34 8C00023C */  lui        $2, %hi(D_008BE280)
    /* 33AC38 0043AC38 40FC60AC */  sw         $0, %lo(D_0070FC40)($3)
    /* 33AC3C 0043AC3C 80E2448C */  lw         $4, %lo(D_008BE280)($2)
    /* 33AC40 0043AC40 04008004 */  bltz       $4, .L0043AC54
    /* 33AC44 0043AC44 01000224 */   addiu     $2, $0, 0x1
    /* 33AC48 0043AC48 FC85100C */  jal        func_004217f0
    /* 33AC4C 0043AC4C 00000000 */   nop
    /* 33AC50 0043AC50 01000224 */  addiu      $2, $0, 0x1
  .L0043AC54:
    /* 33AC54 0043AC54 0000BFDF */  ld         $31, 0x0($29)
    /* 33AC58 0043AC58 0800E003 */  jr         $31
    /* 33AC5C 0043AC5C 1000BD27 */   addiu     $29, $29, 0x10
.size func_0043ac18, 0x48
