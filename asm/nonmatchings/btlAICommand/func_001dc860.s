.section .text
.set noat
.set noreorder
glabel func_001dc860
    /* DC860 001DC860 F0FFBD27 */  addiu      $29, $29, -0x10
    /* DC864 001DC864 0000BFFF */  sd         $31, 0x0($29)
    /* DC868 001DC868 2D300000 */  daddu      $6, $0, $0
    /* DC86C 001DC86C 2D380000 */  daddu      $7, $0, $0
    /* DC870 001DC870 2D400000 */  daddu      $8, $0, $0
    /* DC874 001DC874 1E00093C */  lui        $9, %hi(func_001da2f0)
    /* DC878 001DC878 F0A22925 */  addiu      $9, $9, %lo(func_001da2f0)
    /* DC87C 001DC87C E86E070C */  jal        func_001dbba0
    /* DC880 001DC880 00000000 */   nop
    /* DC884 001DC884 0000BFDF */  ld         $31, 0x0($29)
    /* DC888 001DC888 1000BD27 */  addiu      $29, $29, 0x10
    /* DC88C 001DC88C 0800E003 */  jr         $31
    /* DC890 001DC890 00000000 */   nop
    /* DC894 001DC894 00000000 */  nop
    /* DC898 001DC898 00000000 */  nop
    /* DC89C 001DC89C 00000000 */  nop
.size func_001dc860, 0x40
