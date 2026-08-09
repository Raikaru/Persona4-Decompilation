.section .text
.set noat
.set noreorder
glabel func_00514d80
    /* 414D80 00514D80 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 414D84 00514D84 01000724 */  addiu      $7, $0, 0x1
    /* 414D88 00514D88 0000BFFF */  sd         $31, 0x0($29)
    /* 414D8C 00514D8C 0000BFDF */  ld         $31, 0x0($29)
    /* 414D90 00514D90 66531408 */  j          func_00514d98
    /* 414D94 00514D94 1000BD27 */   addiu     $29, $29, 0x10
.size func_00514d80, 0x18
