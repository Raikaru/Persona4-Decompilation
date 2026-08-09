.section .text
.set noat
.set noreorder
glabel func_001c6bb0
    /* C6BB0 001C6BB0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* C6BB4 001C6BB4 0000BFFF */  sd         $31, 0x0($29)
    /* C6BB8 001C6BB8 01000524 */  addiu      $5, $0, 0x1
    /* C6BBC 001C6BBC DC07070C */  jal        func_001c1f70
    /* C6BC0 001C6BC0 00000000 */   nop
    /* C6BC4 001C6BC4 0000BFDF */  ld         $31, 0x0($29)
    /* C6BC8 001C6BC8 1000BD27 */  addiu      $29, $29, 0x10
    /* C6BCC 001C6BCC 0800E003 */  jr         $31
    /* C6BD0 001C6BD0 00000000 */   nop
    /* C6BD4 001C6BD4 00000000 */  nop
    /* C6BD8 001C6BD8 00000000 */  nop
    /* C6BDC 001C6BDC 00000000 */  nop
.size func_001c6bb0, 0x30
