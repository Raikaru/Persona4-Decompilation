.section .text
.set noat
.set noreorder
glabel func_0027ba40
    /* 17BA40 0027BA40 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 17BA44 0027BA44 1000BFFF */  sd         $31, 0x10($29)
    /* 17BA48 0027BA48 0000B07F */  sq         $16, 0x0($29)
    /* 17BA4C 0027BA4C 2D808000 */  daddu      $16, $4, $0
    /* 17BA50 0027BA50 10DE090C */  jal        func_00277840
    /* 17BA54 0027BA54 00000000 */   nop
    /* 17BA58 0027BA58 2D200002 */  daddu      $4, $16, $0
    /* 17BA5C 0027BA5C 10DE090C */  jal        func_00277840
    /* 17BA60 0027BA60 00000000 */   nop
    /* 17BA64 0027BA64 0000428C */  lw         $2, 0x0($2)
    /* 17BA68 0027BA68 07004010 */  beqz       $2, .L0027BA88
    /* 17BA6C 0027BA6C 00000000 */   nop
    /* 17BA70 0027BA70 2D200002 */  daddu      $4, $16, $0
    /* 17BA74 0027BA74 06000524 */  addiu      $5, $0, 0x6
    /* 17BA78 0027BA78 09F84000 */  jalr       $2
    /* 17BA7C 0027BA7C 00000000 */   nop
    /* 17BA80 0027BA80 02000010 */  b          .L0027BA8C
    /* 17BA84 0027BA84 00000000 */   nop
  .L0027BA88:
    /* 17BA88 0027BA88 01000224 */  addiu      $2, $0, 0x1
  .L0027BA8C:
    /* 17BA8C 0027BA8C 1000BFDF */  ld         $31, 0x10($29)
    /* 17BA90 0027BA90 0000B07B */  lq         $16, 0x0($29)
    /* 17BA94 0027BA94 2000BD27 */  addiu      $29, $29, 0x20
    /* 17BA98 0027BA98 0800E003 */  jr         $31
    /* 17BA9C 0027BA9C 00000000 */   nop
.size func_0027ba40, 0x60
