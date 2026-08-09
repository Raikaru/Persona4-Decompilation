.section .text
.set noat
.set noreorder
glabel func_00249be0
    /* 149BE0 00249BE0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 149BE4 00249BE4 0000BFFF */  sd         $31, 0x0($29)
    /* 149BE8 00249BE8 2D200000 */  daddu      $4, $0, $0
    /* 149BEC 00249BEC 00730A0C */  jal        func_0029cc00
    /* 149BF0 00249BF0 00000000 */   nop
    /* 149BF4 00249BF4 04004014 */  bnez       $2, .L00249C08
    /* 149BF8 00249BF8 00000000 */   nop
    /* 149BFC 00249BFC 8423040C */  jal        func_00108e10
    /* 149C00 00249C00 00000000 */   nop
    /* 149C04 00249C04 FFFF4230 */  andi       $2, $2, 0xFFFF
  .L00249C08:
    /* 149C08 00249C08 FFFF4430 */  andi       $4, $2, 0xFFFF
    /* 149C0C 00249C0C B01E040C */  jal        func_00107ac0
    /* 149C10 00249C10 00000000 */   nop
    /* 149C14 00249C14 FFFF4430 */  andi       $4, $2, 0xFFFF
    /* 149C18 00249C18 D4730A0C */  jal        func_0029cf50
    /* 149C1C 00249C1C 00000000 */   nop
    /* 149C20 00249C20 01000224 */  addiu      $2, $0, 0x1
    /* 149C24 00249C24 0000BFDF */  ld         $31, 0x0($29)
    /* 149C28 00249C28 1000BD27 */  addiu      $29, $29, 0x10
    /* 149C2C 00249C2C 0800E003 */  jr         $31
    /* 149C30 00249C30 00000000 */   nop
    /* 149C34 00249C34 00000000 */  nop
    /* 149C38 00249C38 00000000 */  nop
    /* 149C3C 00249C3C 00000000 */  nop
.size func_00249be0, 0x60
