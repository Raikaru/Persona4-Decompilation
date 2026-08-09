.section .text
.set noat
.set noreorder
glabel func_00249b80
    /* 149B80 00249B80 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 149B84 00249B84 0000BFFF */  sd         $31, 0x0($29)
    /* 149B88 00249B88 2D200000 */  daddu      $4, $0, $0
    /* 149B8C 00249B8C 00730A0C */  jal        func_0029cc00
    /* 149B90 00249B90 00000000 */   nop
    /* 149B94 00249B94 04004014 */  bnez       $2, .L00249BA8
    /* 149B98 00249B98 00000000 */   nop
    /* 149B9C 00249B9C 8423040C */  jal        func_00108e10
    /* 149BA0 00249BA0 00000000 */   nop
    /* 149BA4 00249BA4 FFFF4230 */  andi       $2, $2, 0xFFFF
  .L00249BA8:
    /* 149BA8 00249BA8 FFFF4430 */  andi       $4, $2, 0xFFFF
    /* 149BAC 00249BAC FC1D040C */  jal        func_001077f0
    /* 149BB0 00249BB0 00000000 */   nop
    /* 149BB4 00249BB4 2D204000 */  daddu      $4, $2, $0
    /* 149BB8 00249BB8 D4730A0C */  jal        func_0029cf50
    /* 149BBC 00249BBC 00000000 */   nop
    /* 149BC0 00249BC0 01000224 */  addiu      $2, $0, 0x1
    /* 149BC4 00249BC4 0000BFDF */  ld         $31, 0x0($29)
    /* 149BC8 00249BC8 1000BD27 */  addiu      $29, $29, 0x10
    /* 149BCC 00249BCC 0800E003 */  jr         $31
    /* 149BD0 00249BD0 00000000 */   nop
    /* 149BD4 00249BD4 00000000 */  nop
    /* 149BD8 00249BD8 00000000 */  nop
    /* 149BDC 00249BDC 00000000 */  nop
.size func_00249b80, 0x60
