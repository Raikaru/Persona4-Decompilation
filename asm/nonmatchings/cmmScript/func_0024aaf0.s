.section .text
.set noat
.set noreorder
glabel func_0024aaf0
    /* 14AAF0 0024AAF0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 14AAF4 0024AAF4 0000BFFF */  sd         $31, 0x0($29)
    /* 14AAF8 0024AAF8 2D200000 */  daddu      $4, $0, $0
    /* 14AAFC 0024AAFC 00730A0C */  jal        func_0029cc00
    /* 14AB00 0024AB00 00000000 */   nop
    /* 14AB04 0024AB04 05004014 */  bnez       $2, .L0024AB1C
    /* 14AB08 0024AB08 00000000 */   nop
    /* 14AB0C 0024AB0C 6023040C */  jal        func_00108d80
    /* 14AB10 0024AB10 00000000 */   nop
    /* 14AB14 0024AB14 04000010 */  b          .L0024AB28
    /* 14AB18 0024AB18 00000000 */   nop
  .L0024AB1C:
    /* 14AB1C 0024AB1C FFFF4430 */  andi       $4, $2, 0xFFFF
    /* 14AB20 0024AB20 3C23040C */  jal        func_00108cf0
    /* 14AB24 0024AB24 00000000 */   nop
  .L0024AB28:
    /* 14AB28 0024AB28 01000224 */  addiu      $2, $0, 0x1
    /* 14AB2C 0024AB2C 0000BFDF */  ld         $31, 0x0($29)
    /* 14AB30 0024AB30 1000BD27 */  addiu      $29, $29, 0x10
    /* 14AB34 0024AB34 0800E003 */  jr         $31
    /* 14AB38 0024AB38 00000000 */   nop
    /* 14AB3C 0024AB3C 00000000 */  nop
.size func_0024aaf0, 0x50
