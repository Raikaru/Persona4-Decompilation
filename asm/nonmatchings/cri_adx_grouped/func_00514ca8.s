.section .text
.set noat
.set noreorder
glabel func_00514ca8
    /* 414CA8 00514CA8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 414CAC 00514CAC 01000724 */  addiu      $7, $0, 0x1
    /* 414CB0 00514CB0 0000BFFF */  sd         $31, 0x0($29)
    /* 414CB4 00514CB4 0000BFDF */  ld         $31, 0x0($29)
    /* 414CB8 00514CB8 30531408 */  j          func_00514cc0
    /* 414CBC 00514CBC 1000BD27 */   addiu     $29, $29, 0x10
.size func_00514ca8, 0x18
