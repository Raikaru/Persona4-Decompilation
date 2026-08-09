.section .text
.set noat
.set noreorder
glabel func_0052a6e0
    /* 42A6E0 0052A6E0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 42A6E4 0052A6E4 2D10A000 */  daddu      $2, $5, $0
    /* 42A6E8 0052A6E8 0000BFFF */  sd         $31, 0x0($29)
    /* 42A6EC 0052A6EC 2D204000 */  daddu      $4, $2, $0
    /* 42A6F0 0052A6F0 2D28C000 */  daddu      $5, $6, $0
    /* 42A6F4 0052A6F4 2D30E000 */  daddu      $6, $7, $0
    /* 42A6F8 0052A6F8 0000BFDF */  ld         $31, 0x0($29)
    /* 42A6FC 0052A6FC 440048AC */  sw         $8, 0x44($2)
    /* 42A700 0052A700 480049AC */  sw         $9, 0x48($2)
    /* 42A704 0052A704 64AF1408 */  j          func_0052bd90
    /* 42A708 0052A708 1000BD27 */   addiu     $29, $29, 0x10
    /* 42A70C 0052A70C 00000000 */  nop
.size func_0052a6e0, 0x30
