.section .text
.set noat
.set noreorder
glabel func_0024aca0
    /* 14ACA0 0024ACA0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 14ACA4 0024ACA4 0000BFFF */  sd         $31, 0x0($29)
    /* 14ACA8 0024ACA8 2D200000 */  daddu      $4, $0, $0
    /* 14ACAC 0024ACAC 00730A0C */  jal        func_0029cc00
    /* 14ACB0 0024ACB0 00000000 */   nop
    /* 14ACB4 0024ACB4 FFFF4230 */  andi       $2, $2, 0xFFFF
    /* 14ACB8 0024ACB8 3C240200 */  dsll32     $4, $2, 16
    /* 14ACBC 0024ACBC 3F240400 */  dsra32     $4, $4, 16
    /* 14ACC0 0024ACC0 6023090C */  jal        func_00248d80
    /* 14ACC4 0024ACC4 00000000 */   nop
    /* 14ACC8 0024ACC8 3C240200 */  dsll32     $4, $2, 16
    /* 14ACCC 0024ACCC 3F240400 */  dsra32     $4, $4, 16
    /* 14ACD0 0024ACD0 D4730A0C */  jal        func_0029cf50
    /* 14ACD4 0024ACD4 00000000 */   nop
    /* 14ACD8 0024ACD8 01000224 */  addiu      $2, $0, 0x1
    /* 14ACDC 0024ACDC 0000BFDF */  ld         $31, 0x0($29)
    /* 14ACE0 0024ACE0 1000BD27 */  addiu      $29, $29, 0x10
    /* 14ACE4 0024ACE4 0800E003 */  jr         $31
    /* 14ACE8 0024ACE8 00000000 */   nop
    /* 14ACEC 0024ACEC 00000000 */  nop
.size func_0024aca0, 0x50
