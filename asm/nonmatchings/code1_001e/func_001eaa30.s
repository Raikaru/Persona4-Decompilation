.section .text
.set noat
.set noreorder
glabel func_001eaa30
    /* EAA30 001EAA30 E0FFBD27 */  addiu      $29, $29, -0x20
    /* EAA34 001EAA34 1000BFFF */  sd         $31, 0x10($29)
    /* EAA38 001EAA38 0000B07F */  sq         $16, 0x0($29)
    /* EAA3C 001EAA3C 2D200000 */  daddu      $4, $0, $0
    /* EAA40 001EAA40 00730A0C */  jal        func_0029cc00
    /* EAA44 001EAA44 00000000 */   nop
    /* EAA48 001EAA48 2D804000 */  daddu      $16, $2, $0
    /* EAA4C 001EAA4C 30D8070C */  jal        func_001f60c0
    /* EAA50 001EAA50 00000000 */   nop
    /* EAA54 001EAA54 2D204000 */  daddu      $4, $2, $0
    /* EAA58 001EAA58 480050A4 */  sh         $16, 0x48($2)
    /* EAA5C 001EAA5C 01000524 */  addiu      $5, $0, 0x1
    /* EAA60 001EAA60 6451060C */  jal        func_00194590
    /* EAA64 001EAA64 00000000 */   nop
    /* EAA68 001EAA68 01000224 */  addiu      $2, $0, 0x1
    /* EAA6C 001EAA6C 1000BFDF */  ld         $31, 0x10($29)
    /* EAA70 001EAA70 0000B07B */  lq         $16, 0x0($29)
    /* EAA74 001EAA74 2000BD27 */  addiu      $29, $29, 0x20
    /* EAA78 001EAA78 0800E003 */  jr         $31
    /* EAA7C 001EAA7C 00000000 */   nop
.size func_001eaa30, 0x50
