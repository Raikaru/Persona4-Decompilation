.section .text
.set noat
.set noreorder
glabel func_001dc7a0
    /* DC7A0 001DC7A0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* DC7A4 001DC7A4 0000BFFF */  sd         $31, 0x0($29)
    /* DC7A8 001DC7A8 2D300000 */  daddu      $6, $0, $0
    /* DC7AC 001DC7AC 2D380000 */  daddu      $7, $0, $0
    /* DC7B0 001DC7B0 2D400000 */  daddu      $8, $0, $0
    /* DC7B4 001DC7B4 1E00093C */  lui        $9, %hi(func_001da230)
    /* DC7B8 001DC7B8 30A22925 */  addiu      $9, $9, %lo(func_001da230)
    /* DC7BC 001DC7BC E86E070C */  jal        func_001dbba0
    /* DC7C0 001DC7C0 00000000 */   nop
    /* DC7C4 001DC7C4 0000BFDF */  ld         $31, 0x0($29)
    /* DC7C8 001DC7C8 1000BD27 */  addiu      $29, $29, 0x10
    /* DC7CC 001DC7CC 0800E003 */  jr         $31
    /* DC7D0 001DC7D0 00000000 */   nop
    /* DC7D4 001DC7D4 00000000 */  nop
    /* DC7D8 001DC7D8 00000000 */  nop
    /* DC7DC 001DC7DC 00000000 */  nop
.size func_001dc7a0, 0x40
