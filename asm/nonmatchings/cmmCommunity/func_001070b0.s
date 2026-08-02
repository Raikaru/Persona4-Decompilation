.section .text
.set noat
.set noreorder
glabel func_001070b0
    /* 70B0 001070B0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 70B4 001070B4 0000BFFF */  sd         $31, 0x0($29)
    /* 70B8 001070B8 7900043C */  lui        $4, %hi(D_0079740C)
    /* 70BC 001070BC 0C748424 */  addiu      $4, $4, %lo(D_0079740C)
    /* 70C0 001070C0 2D280000 */  daddu      $5, $0, $0
    /* 70C4 001070C4 58010624 */  addiu      $6, $0, 0x158
    /* 70C8 001070C8 72FE100C */  jal        func_0043f9c8
    /* 70CC 001070CC 00000000 */   nop
    /* 70D0 001070D0 0000BFDF */  ld         $31, 0x0($29)
    /* 70D4 001070D4 1000BD27 */  addiu      $29, $29, 0x10
    /* 70D8 001070D8 0800E003 */  jr         $31
    /* 70DC 001070DC 00000000 */   nop
.size func_001070b0, 0x30
