.section .text
.set noat
.set noreorder
glabel func_00514d68
    /* 414D68 00514D68 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 414D6C 00514D6C 2D380000 */  daddu      $7, $0, $0
    /* 414D70 00514D70 0000BFFF */  sd         $31, 0x0($29)
    /* 414D74 00514D74 0000BFDF */  ld         $31, 0x0($29)
    /* 414D78 00514D78 66531408 */  j          func_00514d98
    /* 414D7C 00514D7C 1000BD27 */   addiu     $29, $29, 0x10
.size func_00514d68, 0x18
