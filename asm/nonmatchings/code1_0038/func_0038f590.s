.section .text
.set noat
.set noreorder
glabel func_0038f590
    /* 28F590 0038F590 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 28F594 0038F594 0000BFFF */  sd         $31, 0x0($29)
    /* 28F598 0038F598 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 28F59C 0038F59C EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 28F5A0 0038F5A0 09F84000 */  jalr       $2
    /* 28F5A4 0038F5A4 00000000 */   nop
    /* 28F5A8 0038F5A8 0000BFDF */  ld         $31, 0x0($29)
    /* 28F5AC 0038F5AC 1000BD27 */  addiu      $29, $29, 0x10
    /* 28F5B0 0038F5B0 0800E003 */  jr         $31
    /* 28F5B4 0038F5B4 00000000 */   nop
    /* 28F5B8 0038F5B8 00000000 */  nop
    /* 28F5BC 0038F5BC 00000000 */  nop
.size func_0038f590, 0x30
