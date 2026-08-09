.section .text
.set noat
.set noreorder
glabel func_0027bce0
    /* 17BCE0 0027BCE0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 17BCE4 0027BCE4 1000BFFF */  sd         $31, 0x10($29)
    /* 17BCE8 0027BCE8 0000B07F */  sq         $16, 0x0($29)
    /* 17BCEC 0027BCEC 2D808000 */  daddu      $16, $4, $0
    /* 17BCF0 0027BCF0 10DE090C */  jal        func_00277840
    /* 17BCF4 0027BCF4 00000000 */   nop
    /* 17BCF8 0027BCF8 2D200002 */  daddu      $4, $16, $0
    /* 17BCFC 0027BCFC 10DE090C */  jal        func_00277840
    /* 17BD00 0027BD00 00000000 */   nop
    /* 17BD04 0027BD04 0000428C */  lw         $2, 0x0($2)
    /* 17BD08 0027BD08 07004010 */  beqz       $2, .L0027BD28
    /* 17BD0C 0027BD0C 00000000 */   nop
    /* 17BD10 0027BD10 2D200002 */  daddu      $4, $16, $0
    /* 17BD14 0027BD14 0D000524 */  addiu      $5, $0, 0xD
    /* 17BD18 0027BD18 09F84000 */  jalr       $2
    /* 17BD1C 0027BD1C 00000000 */   nop
    /* 17BD20 0027BD20 02000010 */  b          .L0027BD2C
    /* 17BD24 0027BD24 00000000 */   nop
  .L0027BD28:
    /* 17BD28 0027BD28 01000224 */  addiu      $2, $0, 0x1
  .L0027BD2C:
    /* 17BD2C 0027BD2C 1000BFDF */  ld         $31, 0x10($29)
    /* 17BD30 0027BD30 0000B07B */  lq         $16, 0x0($29)
    /* 17BD34 0027BD34 2000BD27 */  addiu      $29, $29, 0x20
    /* 17BD38 0027BD38 0800E003 */  jr         $31
    /* 17BD3C 0027BD3C 00000000 */   nop
.size func_0027bce0, 0x60
