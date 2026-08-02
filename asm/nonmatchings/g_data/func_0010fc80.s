.section .text
.set noat
.set noreorder
glabel func_0010fc80
    /* FC80 0010FC80 F0FFBD27 */  addiu      $29, $29, -0x10
    /* FC84 0010FC84 0000BFFF */  sd         $31, 0x0($29)
    /* FC88 0010FC88 7A00043C */  lui        $4, %hi(D_007981CC)
    /* FC8C 0010FC8C CC818424 */  addiu      $4, $4, %lo(D_007981CC)
    /* FC90 0010FC90 2D280000 */  daddu      $5, $0, $0
    /* FC94 0010FC94 00300624 */  addiu      $6, $0, 0x3000
    /* FC98 0010FC98 72FE100C */  jal        func_0043f9c8
    /* FC9C 0010FC9C 00000000 */   nop
    /* FCA0 0010FCA0 0000BFDF */  ld         $31, 0x0($29)
    /* FCA4 0010FCA4 1000BD27 */  addiu      $29, $29, 0x10
    /* FCA8 0010FCA8 0800E003 */  jr         $31
    /* FCAC 0010FCAC 00000000 */   nop
.size func_0010fc80, 0x30
