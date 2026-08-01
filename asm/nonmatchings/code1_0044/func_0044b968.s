.section .text
.set noat
.set noreorder
glabel func_0044b968
    /* 34B968 0044B968 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 34B96C 0044B96C 0000BFFF */  sd         $31, 0x0($29)
    /* 34B970 0044B970 0000BFDF */  ld         $31, 0x0($29)
    /* 34B974 0044B974 A0251108 */  j          func_00449680
    /* 34B978 0044B978 1000BD27 */   addiu     $29, $29, 0x10
    /* 34B97C 0044B97C 00000000 */  nop
.size func_0044b968, 0x18
