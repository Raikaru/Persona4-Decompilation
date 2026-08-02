.section .text
.set noat
.set noreorder
glabel func_001dc920
    /* DC920 001DC920 F0FFBD27 */  addiu      $29, $29, -0x10
    /* DC924 001DC924 0000BFFF */  sd         $31, 0x0($29)
    /* DC928 001DC928 2D300000 */  daddu      $6, $0, $0
    /* DC92C 001DC92C 2D380000 */  daddu      $7, $0, $0
    /* DC930 001DC930 01000824 */  addiu      $8, $0, 0x1
    /* DC934 001DC934 1E00093C */  lui        $9, %hi(func_001da2b0)
    /* DC938 001DC938 B0A22925 */  addiu      $9, $9, %lo(func_001da2b0)
    /* DC93C 001DC93C E86E070C */  jal        func_001dbba0
    /* DC940 001DC940 00000000 */   nop
    /* DC944 001DC944 0000BFDF */  ld         $31, 0x0($29)
    /* DC948 001DC948 1000BD27 */  addiu      $29, $29, 0x10
    /* DC94C 001DC94C 0800E003 */  jr         $31
    /* DC950 001DC950 00000000 */   nop
    /* DC954 001DC954 00000000 */  nop
    /* DC958 001DC958 00000000 */  nop
    /* DC95C 001DC95C 00000000 */  nop
.size func_001dc920, 0x40
