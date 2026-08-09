.section .text
.set noat
.set noreorder
glabel func_002bbcc0
    /* 1BBCC0 002BBCC0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 1BBCC4 002BBCC4 0000BFFF */  sd         $31, 0x0($29)
    /* 1BBCC8 002BBCC8 01000424 */  addiu      $4, $0, 0x1
    /* 1BBCCC 002BBCCC F0ED0A0C */  jal        func_002bb7c0
    /* 1BBCD0 002BBCD0 00000000 */   nop
    /* 1BBCD4 002BBCD4 0000BFDF */  ld         $31, 0x0($29)
    /* 1BBCD8 002BBCD8 1000BD27 */  addiu      $29, $29, 0x10
    /* 1BBCDC 002BBCDC 0800E003 */  jr         $31
    /* 1BBCE0 002BBCE0 00000000 */   nop
    /* 1BBCE4 002BBCE4 00000000 */  nop
    /* 1BBCE8 002BBCE8 00000000 */  nop
    /* 1BBCEC 002BBCEC 00000000 */  nop
.size func_002bbcc0, 0x30
