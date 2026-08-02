.section .text
.set noat
.set noreorder
glabel func_001dc8a0
    /* DC8A0 001DC8A0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* DC8A4 001DC8A4 0000BFFF */  sd         $31, 0x0($29)
    /* DC8A8 001DC8A8 2D300000 */  daddu      $6, $0, $0
    /* DC8AC 001DC8AC 2D380000 */  daddu      $7, $0, $0
    /* DC8B0 001DC8B0 01000824 */  addiu      $8, $0, 0x1
    /* DC8B4 001DC8B4 1E00093C */  lui        $9, %hi(func_001da230)
    /* DC8B8 001DC8B8 30A22925 */  addiu      $9, $9, %lo(func_001da230)
    /* DC8BC 001DC8BC E86E070C */  jal        func_001dbba0
    /* DC8C0 001DC8C0 00000000 */   nop
    /* DC8C4 001DC8C4 0000BFDF */  ld         $31, 0x0($29)
    /* DC8C8 001DC8C8 1000BD27 */  addiu      $29, $29, 0x10
    /* DC8CC 001DC8CC 0800E003 */  jr         $31
    /* DC8D0 001DC8D0 00000000 */   nop
    /* DC8D4 001DC8D4 00000000 */  nop
    /* DC8D8 001DC8D8 00000000 */  nop
    /* DC8DC 001DC8DC 00000000 */  nop
.size func_001dc8a0, 0x40
