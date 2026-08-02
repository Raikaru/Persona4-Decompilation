.section .text
.set noat
.set noreorder
glabel func_0036dda0
    /* 26DDA0 0036DDA0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 26DDA4 0036DDA4 0000BFFF */  sd         $31, 0x0($29)
    /* 26DDA8 0036DDA8 70AD0D0C */  jal        func_0036b5c0
    /* 26DDAC 0036DDAC 00000000 */   nop
    /* 26DDB0 0036DDB0 0000BFDF */  ld         $31, 0x0($29)
    /* 26DDB4 0036DDB4 1000BD27 */  addiu      $29, $29, 0x10
    /* 26DDB8 0036DDB8 0800E003 */  jr         $31
    /* 26DDBC 0036DDBC 00000000 */   nop
.size func_0036dda0, 0x20
