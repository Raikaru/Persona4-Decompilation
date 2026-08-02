.section .text
.set noat
.set noreorder
glabel func_001dc960
    /* DC960 001DC960 F0FFBD27 */  addiu      $29, $29, -0x10
    /* DC964 001DC964 0000BFFF */  sd         $31, 0x0($29)
    /* DC968 001DC968 2D300000 */  daddu      $6, $0, $0
    /* DC96C 001DC96C 2D380000 */  daddu      $7, $0, $0
    /* DC970 001DC970 01000824 */  addiu      $8, $0, 0x1
    /* DC974 001DC974 1E00093C */  lui        $9, %hi(func_001da2f0)
    /* DC978 001DC978 F0A22925 */  addiu      $9, $9, %lo(func_001da2f0)
    /* DC97C 001DC97C E86E070C */  jal        func_001dbba0
    /* DC980 001DC980 00000000 */   nop
    /* DC984 001DC984 0000BFDF */  ld         $31, 0x0($29)
    /* DC988 001DC988 1000BD27 */  addiu      $29, $29, 0x10
    /* DC98C 001DC98C 0800E003 */  jr         $31
    /* DC990 001DC990 00000000 */   nop
    /* DC994 001DC994 00000000 */  nop
    /* DC998 001DC998 00000000 */  nop
    /* DC99C 001DC99C 00000000 */  nop
.size func_001dc960, 0x40
