.section .text
.set noat
.set noreorder
glabel func_00100e30
    /* E30 00100E30 F0FFBD27 */  addiu      $29, $29, -0x10
    /* E34 00100E34 0000BFFF */  sd         $31, 0x0($29)
    /* E38 00100E38 2D200000 */  daddu      $4, $0, $0
    /* E3C 00100E3C CE32130C */  jal        func_004ccb38
    /* E40 00100E40 00000000 */   nop
    /* E44 00100E44 0F000000 */  sync
    /* E48 00100E48 38000042 */  ei /* handwritten instruction */
    /* E4C 00100E4C 2D100000 */  daddu      $2, $0, $0
    /* E50 00100E50 0000BFDF */  ld         $31, 0x0($29)
    /* E54 00100E54 1000BD27 */  addiu      $29, $29, 0x10
    /* E58 00100E58 0800E003 */  jr         $31
    /* E5C 00100E5C 00000000 */   nop
.size func_00100e30, 0x30
