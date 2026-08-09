.section .text
.set noat
.set noreorder
glabel func_00298d70
    /* 198D70 00298D70 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 198D74 00298D74 0000BFFF */  sd         $31, 0x0($29)
    /* 198D78 00298D78 2D200000 */  daddu      $4, $0, $0
    /* 198D7C 00298D7C 00730A0C */  jal        func_0029cc00
    /* 198D80 00298D80 00000000 */   nop
    /* 198D84 00298D84 2D204000 */  daddu      $4, $2, $0
    /* 198D88 00298D88 CC18040C */  jal        func_00106330
    /* 198D8C 00298D8C 00000000 */   nop
    /* 198D90 00298D90 2D204000 */  daddu      $4, $2, $0
    /* 198D94 00298D94 D4730A0C */  jal        func_0029cf50
    /* 198D98 00298D98 00000000 */   nop
    /* 198D9C 00298D9C 01000224 */  addiu      $2, $0, 0x1
    /* 198DA0 00298DA0 0000BFDF */  ld         $31, 0x0($29)
    /* 198DA4 00298DA4 1000BD27 */  addiu      $29, $29, 0x10
    /* 198DA8 00298DA8 0800E003 */  jr         $31
    /* 198DAC 00298DAC 00000000 */   nop
.size func_00298d70, 0x40
