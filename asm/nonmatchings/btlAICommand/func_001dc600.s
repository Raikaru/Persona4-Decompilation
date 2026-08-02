.section .text
.set noat
.set noreorder
glabel func_001dc600
    /* DC600 001DC600 F0FFBD27 */  addiu      $29, $29, -0x10
    /* DC604 001DC604 0000BFFF */  sd         $31, 0x0($29)
    /* DC608 001DC608 2D300000 */  daddu      $6, $0, $0
    /* DC60C 001DC60C 2D380000 */  daddu      $7, $0, $0
    /* DC610 001DC610 01000824 */  addiu      $8, $0, 0x1
    /* DC614 001DC614 1E00093C */  lui        $9, %hi(func_001d9b60)
    /* DC618 001DC618 609B2925 */  addiu      $9, $9, %lo(func_001d9b60)
    /* DC61C 001DC61C E86E070C */  jal        func_001dbba0
    /* DC620 001DC620 00000000 */   nop
    /* DC624 001DC624 0000BFDF */  ld         $31, 0x0($29)
    /* DC628 001DC628 1000BD27 */  addiu      $29, $29, 0x10
    /* DC62C 001DC62C 0800E003 */  jr         $31
    /* DC630 001DC630 00000000 */   nop
    /* DC634 001DC634 00000000 */  nop
    /* DC638 001DC638 00000000 */  nop
    /* DC63C 001DC63C 00000000 */  nop
.size func_001dc600, 0x40
