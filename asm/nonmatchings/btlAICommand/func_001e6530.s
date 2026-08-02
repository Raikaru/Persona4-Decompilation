.section .text
.set noat
.set noreorder
glabel func_001e6530
    /* E6530 001E6530 F0FFBD27 */  addiu      $29, $29, -0x10
    /* E6534 001E6534 0000BFFF */  sd         $31, 0x0($29)
    /* E6538 001E6538 14740A0C */  jal        func_0029d050
    /* E653C 001E653C 00000000 */   nop
    /* E6540 001E6540 01000424 */  addiu      $4, $0, 0x1
    /* E6544 001E6544 2D280000 */  daddu      $5, $0, $0
    /* E6548 001E6548 C8BD070C */  jal        func_001ef720
    /* E654C 001E654C 00000000 */   nop
    /* E6550 001E6550 FFFF4430 */  andi       $4, $2, 0xFFFF
    /* E6554 001E6554 D4730A0C */  jal        func_0029cf50
    /* E6558 001E6558 00000000 */   nop
    /* E655C 001E655C 01000224 */  addiu      $2, $0, 0x1
    /* E6560 001E6560 0000BFDF */  ld         $31, 0x0($29)
    /* E6564 001E6564 1000BD27 */  addiu      $29, $29, 0x10
    /* E6568 001E6568 0800E003 */  jr         $31
    /* E656C 001E656C 00000000 */   nop
.size func_001e6530, 0x40
