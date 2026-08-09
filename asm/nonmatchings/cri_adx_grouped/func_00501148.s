.section .text
.set noat
.set noreorder
glabel func_00501148
    /* 401148 00501148 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40114C 0050114C 0000BFFF */  sd         $31, 0x0($29)
    /* 401150 00501150 0000BFDF */  ld         $31, 0x0($29)
    /* 401154 00501154 3A041408 */  j          func_005010e8
    /* 401158 00501158 1000BD27 */   addiu     $29, $29, 0x10
    /* 40115C 0050115C 00000000 */  nop
.size func_00501148, 0x18
