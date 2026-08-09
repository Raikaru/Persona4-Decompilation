.section .text
.set noat
.set noreorder
glabel func_0013ca60
    /* 3CA60 0013CA60 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3CA64 0013CA64 1000BFFF */  sd         $31, 0x10($29)
    /* 3CA68 0013CA68 0000B07F */  sq         $16, 0x0($29)
    /* 3CA6C 0013CA6C 2D800000 */  daddu      $16, $0, $0
    /* 3CA70 0013CA70 01000724 */  addiu      $7, $0, 0x1
    /* 3CA74 0013CA74 4C3E040C */  jal        func_0010f930
    /* 3CA78 0013CA78 00000000 */   nop
    /* 3CA7C 0013CA7C 02004014 */  bnez       $2, .L0013CA88
    /* 3CA80 0013CA80 00000000 */   nop
    /* 3CA84 0013CA84 01001024 */  addiu      $16, $0, 0x1
  .L0013CA88:
    /* 3CA88 0013CA88 2D100002 */  daddu      $2, $16, $0
    /* 3CA8C 0013CA8C 1000BFDF */  ld         $31, 0x10($29)
    /* 3CA90 0013CA90 0000B07B */  lq         $16, 0x0($29)
    /* 3CA94 0013CA94 2000BD27 */  addiu      $29, $29, 0x20
    /* 3CA98 0013CA98 0800E003 */  jr         $31
    /* 3CA9C 0013CA9C 00000000 */   nop
.size func_0013ca60, 0x40
