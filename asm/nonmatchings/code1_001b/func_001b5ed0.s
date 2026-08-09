.section .text
.set noat
.set noreorder
glabel func_001b5ed0
    /* B5ED0 001B5ED0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* B5ED4 001B5ED4 0000BFFF */  sd         $31, 0x0($29)
    /* B5ED8 001B5ED8 2D200000 */  daddu      $4, $0, $0
    /* B5EDC 001B5EDC 6CF0070C */  jal        func_001fc1b0
    /* B5EE0 001B5EE0 00000000 */   nop
    /* B5EE4 001B5EE4 02000224 */  addiu      $2, $0, 0x2
    /* B5EE8 001B5EE8 0000BFDF */  ld         $31, 0x0($29)
    /* B5EEC 001B5EEC 1000BD27 */  addiu      $29, $29, 0x10
    /* B5EF0 001B5EF0 0800E003 */  jr         $31
    /* B5EF4 001B5EF4 00000000 */   nop
    /* B5EF8 001B5EF8 00000000 */  nop
    /* B5EFC 001B5EFC 00000000 */  nop
.size func_001b5ed0, 0x30
