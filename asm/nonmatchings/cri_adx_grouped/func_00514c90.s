.section .text
.set noat
.set noreorder
glabel func_00514c90
    /* 414C90 00514C90 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 414C94 00514C94 2D380000 */  daddu      $7, $0, $0
    /* 414C98 00514C98 0000BFFF */  sd         $31, 0x0($29)
    /* 414C9C 00514C9C 0000BFDF */  ld         $31, 0x0($29)
    /* 414CA0 00514CA0 30531408 */  j          func_00514cc0
    /* 414CA4 00514CA4 1000BD27 */   addiu     $29, $29, 0x10
.size func_00514c90, 0x18
