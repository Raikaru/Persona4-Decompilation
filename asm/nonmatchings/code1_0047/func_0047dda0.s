.section .text
.set noat
.set noreorder
glabel func_0047dda0
    /* 37DDA0 0047DDA0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 37DDA4 0047DDA4 0000BFFF */  sd         $31, 0x0($29)
    /* 37DDA8 0047DDA8 0400848C */  lw         $4, 0x4($4)
    /* 37DDAC 0047DDAC 03008010 */  beqz       $4, .L0047DDBC
    /* 37DDB0 0047DDB0 00000000 */   nop
    /* 37DDB4 0047DDB4 DCD7120C */  jal        func_004b5f70
    /* 37DDB8 0047DDB8 00000000 */   nop
  .L0047DDBC:
    /* 37DDBC 0047DDBC 0000BFDF */  ld         $31, 0x0($29)
    /* 37DDC0 0047DDC0 1000BD27 */  addiu      $29, $29, 0x10
    /* 37DDC4 0047DDC4 0800E003 */  jr         $31
    /* 37DDC8 0047DDC8 00000000 */   nop
    /* 37DDCC 0047DDCC 00000000 */  nop
.size func_0047dda0, 0x30
