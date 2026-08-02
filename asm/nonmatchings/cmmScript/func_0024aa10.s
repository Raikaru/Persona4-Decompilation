.section .text
.set noat
.set noreorder
glabel func_0024aa10
    /* 14AA10 0024AA10 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 14AA14 0024AA14 0000BFFF */  sd         $31, 0x0($29)
    /* 14AA18 0024AA18 2D200000 */  daddu      $4, $0, $0
    /* 14AA1C 0024AA1C 00730A0C */  jal        func_0029cc00
    /* 14AA20 0024AA20 00000000 */   nop
    /* 14AA24 0024AA24 04004014 */  bnez       $2, .L0024AA38
    /* 14AA28 0024AA28 00000000 */   nop
    /* 14AA2C 0024AA2C 8423040C */  jal        func_00108e10
    /* 14AA30 0024AA30 00000000 */   nop
    /* 14AA34 0024AA34 FFFF4230 */  andi       $2, $2, 0xFFFF
  .L0024AA38:
    /* 14AA38 0024AA38 FFFF4430 */  andi       $4, $2, 0xFFFF
    /* 14AA3C 0024AA3C BC23040C */  jal        func_00108ef0
    /* 14AA40 0024AA40 00000000 */   nop
    /* 14AA44 0024AA44 01000224 */  addiu      $2, $0, 0x1
    /* 14AA48 0024AA48 0000BFDF */  ld         $31, 0x0($29)
    /* 14AA4C 0024AA4C 1000BD27 */  addiu      $29, $29, 0x10
    /* 14AA50 0024AA50 0800E003 */  jr         $31
    /* 14AA54 0024AA54 00000000 */   nop
    /* 14AA58 0024AA58 00000000 */  nop
    /* 14AA5C 0024AA5C 00000000 */  nop
.size func_0024aa10, 0x50
