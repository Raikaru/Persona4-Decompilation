.section .text
.set noat
.set noreorder
glabel func_0025e9e0
    /* 15E9E0 0025E9E0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 15E9E4 0025E9E4 0000BFFF */  sd         $31, 0x0($29)
    /* 15E9E8 0025E9E8 00788044 */  mtc1       $0, $f15
    /* 15E9EC 0025E9EC 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 15E9F0 0025E9F0 00808244 */  mtc1       $2, $f16
    /* 15E9F4 0025E9F4 2D480000 */  daddu      $9, $0, $0
    /* 15E9F8 0025E9F8 2D500000 */  daddu      $10, $0, $0
    /* 15E9FC 0025E9FC 46840046 */  mov.s      $f17, $f16
    /* 15EA00 0025EA00 887A090C */  jal        func_0025ea20
    /* 15EA04 0025EA04 00000000 */   nop
    /* 15EA08 0025EA08 0000BFDF */  ld         $31, 0x0($29)
    /* 15EA0C 0025EA0C 1000BD27 */  addiu      $29, $29, 0x10
    /* 15EA10 0025EA10 0800E003 */  jr         $31
    /* 15EA14 0025EA14 00000000 */   nop
    /* 15EA18 0025EA18 00000000 */  nop
    /* 15EA1C 0025EA1C 00000000 */  nop
.size func_0025e9e0, 0x40
