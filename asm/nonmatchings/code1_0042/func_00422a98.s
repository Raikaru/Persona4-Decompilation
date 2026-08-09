.section .text
.set noat
.set noreorder
glabel func_00422a98
    /* 322A98 00422A98 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 322A9C 00422A9C 0000BFFF */  sd         $31, 0x0($29)
    /* 322AA0 00422AA0 0486100C */  jal        func_00421810
    /* 322AA4 00422AA4 2D20E000 */   daddu     $4, $7, $0
    /* 322AA8 00422AA8 0F000000 */  sync
    /* 322AAC 00422AAC 38000042 */  ei /* handwritten instruction */
    /* 322AB0 00422AB0 0000BFDF */  ld         $31, 0x0($29)
    /* 322AB4 00422AB4 2D100000 */  daddu      $2, $0, $0
    /* 322AB8 00422AB8 0800E003 */  jr         $31
    /* 322ABC 00422ABC 1000BD27 */   addiu     $29, $29, 0x10
.size func_00422a98, 0x28
