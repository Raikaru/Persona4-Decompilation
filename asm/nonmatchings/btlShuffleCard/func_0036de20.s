.section .text
.set noat
.set noreorder
glabel func_0036de20
    /* 26DE20 0036DE20 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 26DE24 0036DE24 0000BFFF */  sd         $31, 0x0($29)
    /* 26DE28 0036DE28 80AD0D0C */  jal        func_0036b600
    /* 26DE2C 0036DE2C 00000000 */   nop
    /* 26DE30 0036DE30 0000BFDF */  ld         $31, 0x0($29)
    /* 26DE34 0036DE34 1000BD27 */  addiu      $29, $29, 0x10
    /* 26DE38 0036DE38 0800E003 */  jr         $31
    /* 26DE3C 0036DE3C 00000000 */   nop
.size func_0036de20, 0x20
