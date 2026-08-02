.section .text
.set noat
.set noreorder
glabel func_0045af60
    /* 35AF60 0045AF60 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 35AF64 0045AF64 0000BFFF */  sd         $31, 0x0($29)
    /* 35AF68 0045AF68 9071110C */  jal        func_0045c640
    /* 35AF6C 0045AF6C 00000000 */   nop
    /* 35AF70 0045AF70 01000224 */  addiu      $2, $0, 0x1
    /* 35AF74 0045AF74 0000BFDF */  ld         $31, 0x0($29)
    /* 35AF78 0045AF78 1000BD27 */  addiu      $29, $29, 0x10
    /* 35AF7C 0045AF7C 0800E003 */  jr         $31
    /* 35AF80 0045AF80 00000000 */   nop
    /* 35AF84 0045AF84 00000000 */  nop
    /* 35AF88 0045AF88 00000000 */  nop
    /* 35AF8C 0045AF8C 00000000 */  nop
.size func_0045af60, 0x30
