.section .text
.set noat
.set noreorder
glabel func_00512238
    /* 412238 00512238 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 41223C 0051223C 0000BFFF */  sd         $31, 0x0($29)
    /* 412240 00512240 0000BFDF */  ld         $31, 0x0($29)
    /* 412244 00512244 4A481308 */  j          func_004d2128
    /* 412248 00512248 1000BD27 */   addiu     $29, $29, 0x10
    /* 41224C 0051224C 00000000 */  nop
.size func_00512238, 0x18
