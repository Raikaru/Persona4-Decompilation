.section .text
.set noat
.set noreorder
glabel func_001dc8e0
    /* DC8E0 001DC8E0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* DC8E4 001DC8E4 0000BFFF */  sd         $31, 0x0($29)
    /* DC8E8 001DC8E8 2D300000 */  daddu      $6, $0, $0
    /* DC8EC 001DC8EC 2D380000 */  daddu      $7, $0, $0
    /* DC8F0 001DC8F0 01000824 */  addiu      $8, $0, 0x1
    /* DC8F4 001DC8F4 1E00093C */  lui        $9, %hi(func_001da270)
    /* DC8F8 001DC8F8 70A22925 */  addiu      $9, $9, %lo(func_001da270)
    /* DC8FC 001DC8FC E86E070C */  jal        func_001dbba0
    /* DC900 001DC900 00000000 */   nop
    /* DC904 001DC904 0000BFDF */  ld         $31, 0x0($29)
    /* DC908 001DC908 1000BD27 */  addiu      $29, $29, 0x10
    /* DC90C 001DC90C 0800E003 */  jr         $31
    /* DC910 001DC910 00000000 */   nop
    /* DC914 001DC914 00000000 */  nop
    /* DC918 001DC918 00000000 */  nop
    /* DC91C 001DC91C 00000000 */  nop
.size func_001dc8e0, 0x40
