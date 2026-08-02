.section .text
.set noat
.set noreorder
glabel func_001dc820
    /* DC820 001DC820 F0FFBD27 */  addiu      $29, $29, -0x10
    /* DC824 001DC824 0000BFFF */  sd         $31, 0x0($29)
    /* DC828 001DC828 2D300000 */  daddu      $6, $0, $0
    /* DC82C 001DC82C 2D380000 */  daddu      $7, $0, $0
    /* DC830 001DC830 2D400000 */  daddu      $8, $0, $0
    /* DC834 001DC834 1E00093C */  lui        $9, %hi(func_001da2b0)
    /* DC838 001DC838 B0A22925 */  addiu      $9, $9, %lo(func_001da2b0)
    /* DC83C 001DC83C E86E070C */  jal        func_001dbba0
    /* DC840 001DC840 00000000 */   nop
    /* DC844 001DC844 0000BFDF */  ld         $31, 0x0($29)
    /* DC848 001DC848 1000BD27 */  addiu      $29, $29, 0x10
    /* DC84C 001DC84C 0800E003 */  jr         $31
    /* DC850 001DC850 00000000 */   nop
    /* DC854 001DC854 00000000 */  nop
    /* DC858 001DC858 00000000 */  nop
    /* DC85C 001DC85C 00000000 */  nop
.size func_001dc820, 0x40
