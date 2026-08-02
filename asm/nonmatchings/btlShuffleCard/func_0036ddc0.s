.section .text
.set noat
.set noreorder
glabel func_0036ddc0
    /* 26DDC0 0036DDC0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 26DDC4 0036DDC4 0000BFFF */  sd         $31, 0x0($29)
    /* 26DDC8 0036DDC8 68AD0D0C */  jal        func_0036b5a0
    /* 26DDCC 0036DDCC 00000000 */   nop
    /* 26DDD0 0036DDD0 0000BFDF */  ld         $31, 0x0($29)
    /* 26DDD4 0036DDD4 1000BD27 */  addiu      $29, $29, 0x10
    /* 26DDD8 0036DDD8 0800E003 */  jr         $31
    /* 26DDDC 0036DDDC 00000000 */   nop
.size func_0036ddc0, 0x20
