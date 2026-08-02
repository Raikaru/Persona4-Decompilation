.section .text
.set noat
.set noreorder
glabel func_0038df10
    /* 28DF10 0038DF10 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 28DF14 0038DF14 0000BFFF */  sd         $31, 0x0($29)
    /* 28DF18 0038DF18 B0B5828F */  lw         $2, -0x4A50($28)
    /* 28DF1C 0038DF1C 06004014 */  bnez       $2, .L0038DF38
    /* 28DF20 0038DF20 00000000 */   nop
    /* 28DF24 0038DF24 6500043C */  lui        $4, %hi(D_0064F220)
    /* 28DF28 0038DF28 20F28424 */  addiu      $4, $4, %lo(D_0064F220)
    /* 28DF2C 0038DF2C 6B000524 */  addiu      $5, $0, 0x6B
    /* 28DF30 0038DF30 CCB5110C */  jal        func_0046d730
    /* 28DF34 0038DF34 00000000 */   nop
  .L0038DF38:
    /* 28DF38 0038DF38 B0B5828F */  lw         $2, -0x4A50($28)
    /* 28DF3C 0038DF3C 0000428C */  lw         $2, 0x0($2)
    /* 28DF40 0038DF40 01004230 */  andi       $2, $2, 0x1
    /* 28DF44 0038DF44 0000BFDF */  ld         $31, 0x0($29)
    /* 28DF48 0038DF48 1000BD27 */  addiu      $29, $29, 0x10
    /* 28DF4C 0038DF4C 0800E003 */  jr         $31
    /* 28DF50 0038DF50 00000000 */   nop
    /* 28DF54 0038DF54 00000000 */  nop
    /* 28DF58 0038DF58 00000000 */  nop
    /* 28DF5C 0038DF5C 00000000 */  nop
.size func_0038df10, 0x50
