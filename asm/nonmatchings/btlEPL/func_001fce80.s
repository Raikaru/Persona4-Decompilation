.section .text
.set noat
.set noreorder
glabel func_001fce80
    /* FCE80 001FCE80 F0FFBD27 */  addiu      $29, $29, -0x10
    /* FCE84 001FCE84 0000BFFF */  sd         $31, 0x0($29)
    /* FCE88 001FCE88 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* FCE8C 001FCE8C EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* FCE90 001FCE90 09F84000 */  jalr       $2
    /* FCE94 001FCE94 00000000 */   nop
    /* FCE98 001FCE98 0000BFDF */  ld         $31, 0x0($29)
    /* FCE9C 001FCE9C 1000BD27 */  addiu      $29, $29, 0x10
    /* FCEA0 001FCEA0 0800E003 */  jr         $31
    /* FCEA4 001FCEA4 00000000 */   nop
    /* FCEA8 001FCEA8 00000000 */  nop
    /* FCEAC 001FCEAC 00000000 */  nop
.size func_001fce80, 0x30
