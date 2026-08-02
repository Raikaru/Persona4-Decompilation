.section .text
.set noat
.set noreorder
glabel func_001e45d0
    /* E45D0 001E45D0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* E45D4 001E45D4 0000BFFF */  sd         $31, 0x0($29)
    /* E45D8 001E45D8 2D200000 */  daddu      $4, $0, $0
    /* E45DC 001E45DC D4730A0C */  jal        func_0029cf50
    /* E45E0 001E45E0 00000000 */   nop
    /* E45E4 001E45E4 01000224 */  addiu      $2, $0, 0x1
    /* E45E8 001E45E8 0000BFDF */  ld         $31, 0x0($29)
    /* E45EC 001E45EC 1000BD27 */  addiu      $29, $29, 0x10
    /* E45F0 001E45F0 0800E003 */  jr         $31
    /* E45F4 001E45F4 00000000 */   nop
    /* E45F8 001E45F8 00000000 */  nop
    /* E45FC 001E45FC 00000000 */  nop
.size func_001e45d0, 0x30
