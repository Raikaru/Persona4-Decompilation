.section .text
.set noat
.set noreorder
glabel func_001dc5c0
    /* DC5C0 001DC5C0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* DC5C4 001DC5C4 0000BFFF */  sd         $31, 0x0($29)
    /* DC5C8 001DC5C8 2D300000 */  daddu      $6, $0, $0
    /* DC5CC 001DC5CC 2D380000 */  daddu      $7, $0, $0
    /* DC5D0 001DC5D0 2D400000 */  daddu      $8, $0, $0
    /* DC5D4 001DC5D4 1E00093C */  lui        $9, %hi(func_001d9b60)
    /* DC5D8 001DC5D8 609B2925 */  addiu      $9, $9, %lo(func_001d9b60)
    /* DC5DC 001DC5DC E86E070C */  jal        func_001dbba0
    /* DC5E0 001DC5E0 00000000 */   nop
    /* DC5E4 001DC5E4 0000BFDF */  ld         $31, 0x0($29)
    /* DC5E8 001DC5E8 1000BD27 */  addiu      $29, $29, 0x10
    /* DC5EC 001DC5EC 0800E003 */  jr         $31
    /* DC5F0 001DC5F0 00000000 */   nop
    /* DC5F4 001DC5F4 00000000 */  nop
    /* DC5F8 001DC5F8 00000000 */  nop
    /* DC5FC 001DC5FC 00000000 */  nop
.size func_001dc5c0, 0x40
