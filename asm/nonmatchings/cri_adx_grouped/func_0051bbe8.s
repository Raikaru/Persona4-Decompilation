.section .text
.set noat
.set noreorder
glabel func_0051bbe8
    /* 41BBE8 0051BBE8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 41BBEC 0051BBEC 0000BFFF */  sd         $31, 0x0($29)
    /* 41BBF0 0051BBF0 C81F858C */  lw         $5, 0x1FC8($4)
    /* 41BBF4 0051BBF4 0000BFDF */  ld         $31, 0x0($29)
    /* 41BBF8 0051BBF8 68561408 */  j          func_005159a0
    /* 41BBFC 0051BBFC 1000BD27 */   addiu     $29, $29, 0x10
.size func_0051bbe8, 0x18
