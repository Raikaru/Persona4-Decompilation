.section .text
.set noat
.set noreorder
glabel func_0052bbf0
    /* 42BBF0 0052BBF0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 42BBF4 0052BBF4 0000BFFF */  sd         $31, 0x0($29)
    /* 42BBF8 0052BBF8 2400848C */  lw         $4, 0x24($4)
    /* 42BBFC 0052BBFC 0000BFDF */  ld         $31, 0x0($29)
    /* 42BC00 0052BC00 0AB21408 */  j          func_0052c828
    /* 42BC04 0052BC04 1000BD27 */   addiu     $29, $29, 0x10
.size func_0052bbf0, 0x18
