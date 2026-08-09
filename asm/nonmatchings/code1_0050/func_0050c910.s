.section .text
.set noat
.set noreorder
glabel func_0050c910
    /* 40C910 0050C910 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40C914 0050C914 0000BFFF */  sd         $31, 0x0($29)
    /* 40C918 0050C918 0000BFDF */  ld         $31, 0x0($29)
    /* 40C91C 0050C91C B8321408 */  j          func_0050cae0
    /* 40C920 0050C920 1000BD27 */   addiu     $29, $29, 0x10
    /* 40C924 0050C924 00000000 */  nop
.size func_0050c910, 0x18
