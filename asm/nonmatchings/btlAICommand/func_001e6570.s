.section .text
.set noat
.set noreorder
glabel func_001e6570
    /* E6570 001E6570 F0FFBD27 */  addiu      $29, $29, -0x10
    /* E6574 001E6574 0000BFFF */  sd         $31, 0x0($29)
    /* E6578 001E6578 14740A0C */  jal        func_0029d050
    /* E657C 001E657C 00000000 */   nop
    /* E6580 001E6580 02000424 */  addiu      $4, $0, 0x2
    /* E6584 001E6584 2D280000 */  daddu      $5, $0, $0
    /* E6588 001E6588 C8BD070C */  jal        func_001ef720
    /* E658C 001E658C 00000000 */   nop
    /* E6590 001E6590 FFFF4430 */  andi       $4, $2, 0xFFFF
    /* E6594 001E6594 D4730A0C */  jal        func_0029cf50
    /* E6598 001E6598 00000000 */   nop
    /* E659C 001E659C FFFF0224 */  addiu      $2, $0, -0x1
    /* E65A0 001E65A0 0000BFDF */  ld         $31, 0x0($29)
    /* E65A4 001E65A4 1000BD27 */  addiu      $29, $29, 0x10
    /* E65A8 001E65A8 0800E003 */  jr         $31
    /* E65AC 001E65AC 00000000 */   nop
.size func_001e6570, 0x40
