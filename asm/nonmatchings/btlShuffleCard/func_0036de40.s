.section .text
.set noat
.set noreorder
glabel func_0036de40
    /* 26DE40 0036DE40 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 26DE44 0036DE44 0000BFFF */  sd         $31, 0x0($29)
    /* 26DE48 0036DE48 70AB0D0C */  jal        func_0036adc0
    /* 26DE4C 0036DE4C 00000000 */   nop
    /* 26DE50 0036DE50 0000BFDF */  ld         $31, 0x0($29)
    /* 26DE54 0036DE54 1000BD27 */  addiu      $29, $29, 0x10
    /* 26DE58 0036DE58 0800E003 */  jr         $31
    /* 26DE5C 0036DE5C 00000000 */   nop
.size func_0036de40, 0x20
