.section .text
.set noat
.set noreorder
glabel func_001cc9e0
    /* CC9E0 001CC9E0 A0FFBD27 */  addiu      $29, $29, -0x60
    /* CC9E4 001CC9E4 1000BFFF */  sd         $31, 0x10($29)
    /* CC9E8 001CC9E8 0000B07F */  sq         $16, 0x0($29)
    /* CC9EC 001CC9EC 2D808000 */  daddu      $16, $4, $0
    /* CC9F0 001CC9F0 2000A427 */  addiu      $4, $29, 0x20
    /* CC9F4 001CC9F4 9C000526 */  addiu      $5, $16, 0x9C
    /* CC9F8 001CC9F8 58F5060C */  jal        func_001bd560
    /* CC9FC 001CC9FC 00000000 */   nop
    /* CCA00 001CCA00 2D200002 */  daddu      $4, $16, $0
    /* CCA04 001CCA04 3C00A527 */  addiu      $5, $29, 0x3C
    /* CCA08 001CCA08 7431070C */  jal        func_001cc5d0
    /* CCA0C 001CCA0C 00000000 */   nop
    /* CCA10 001CCA10 2D200002 */  daddu      $4, $16, $0
    /* CCA14 001CCA14 2000A527 */  addiu      $5, $29, 0x20
    /* CCA18 001CCA18 3C00A627 */  addiu      $6, $29, 0x3C
    /* CCA1C 001CCA1C 01000724 */  addiu      $7, $0, 0x1
    /* CCA20 001CCA20 08EB060C */  jal        func_001bac20
    /* CCA24 001CCA24 00000000 */   nop
    /* CCA28 001CCA28 2041023C */  lui        $2, (0x41200000 >> 16)
    /* CCA2C 001CCA2C 00608244 */  mtc1       $2, $f12
    /* CCA30 001CCA30 2D200002 */  daddu      $4, $16, $0
    /* CCA34 001CCA34 BCEF060C */  jal        func_001bbef0
    /* CCA38 001CCA38 00000000 */   nop
    /* CCA3C 001CCA3C 1000BFDF */  ld         $31, 0x10($29)
    /* CCA40 001CCA40 0000B07B */  lq         $16, 0x0($29)
    /* CCA44 001CCA44 6000BD27 */  addiu      $29, $29, 0x60
    /* CCA48 001CCA48 0800E003 */  jr         $31
    /* CCA4C 001CCA4C 00000000 */   nop
    /* CCA50 001CCA50 0800E003 */  jr         $31
    /* CCA54 001CCA54 00000000 */   nop
    /* CCA58 001CCA58 00000000 */  nop
    /* CCA5C 001CCA5C 00000000 */  nop
.size func_001cc9e0, 0x80
