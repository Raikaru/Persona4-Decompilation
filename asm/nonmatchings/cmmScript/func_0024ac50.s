.section .text
.set noat
.set noreorder
glabel func_0024ac50
    /* 14AC50 0024AC50 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 14AC54 0024AC54 0000BFFF */  sd         $31, 0x0($29)
    /* 14AC58 0024AC58 2D200000 */  daddu      $4, $0, $0
    /* 14AC5C 0024AC5C 00730A0C */  jal        func_0029cc00
    /* 14AC60 0024AC60 00000000 */   nop
    /* 14AC64 0024AC64 04004014 */  bnez       $2, .L0024AC78
    /* 14AC68 0024AC68 00000000 */   nop
    /* 14AC6C 0024AC6C 8423040C */  jal        func_00108e10
    /* 14AC70 0024AC70 00000000 */   nop
    /* 14AC74 0024AC74 FFFF4230 */  andi       $2, $2, 0xFFFF
  .L0024AC78:
    /* 14AC78 0024AC78 FFFF4430 */  andi       $4, $2, 0xFFFF
    /* 14AC7C 0024AC7C F41E040C */  jal        func_00107bd0
    /* 14AC80 0024AC80 00000000 */   nop
    /* 14AC84 0024AC84 01000224 */  addiu      $2, $0, 0x1
    /* 14AC88 0024AC88 0000BFDF */  ld         $31, 0x0($29)
    /* 14AC8C 0024AC8C 1000BD27 */  addiu      $29, $29, 0x10
    /* 14AC90 0024AC90 0800E003 */  jr         $31
    /* 14AC94 0024AC94 00000000 */   nop
    /* 14AC98 0024AC98 00000000 */  nop
    /* 14AC9C 0024AC9C 00000000 */  nop
.size func_0024ac50, 0x50
