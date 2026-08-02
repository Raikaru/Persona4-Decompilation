.section .text
.set noat
.set noreorder
glabel func_001dc640
    /* DC640 001DC640 F0FFBD27 */  addiu      $29, $29, -0x10
    /* DC644 001DC644 0000BFFF */  sd         $31, 0x0($29)
    /* DC648 001DC648 2D300000 */  daddu      $6, $0, $0
    /* DC64C 001DC64C 2D380000 */  daddu      $7, $0, $0
    /* DC650 001DC650 2D400000 */  daddu      $8, $0, $0
    /* DC654 001DC654 1E00093C */  lui        $9, %hi(func_001dacc0)
    /* DC658 001DC658 C0AC2925 */  addiu      $9, $9, %lo(func_001dacc0)
    /* DC65C 001DC65C E86E070C */  jal        func_001dbba0
    /* DC660 001DC660 00000000 */   nop
    /* DC664 001DC664 0000BFDF */  ld         $31, 0x0($29)
    /* DC668 001DC668 1000BD27 */  addiu      $29, $29, 0x10
    /* DC66C 001DC66C 0800E003 */  jr         $31
    /* DC670 001DC670 00000000 */   nop
    /* DC674 001DC674 00000000 */  nop
    /* DC678 001DC678 00000000 */  nop
    /* DC67C 001DC67C 00000000 */  nop
.size func_001dc640, 0x40
