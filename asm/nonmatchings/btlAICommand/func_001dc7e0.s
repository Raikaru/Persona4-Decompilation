.section .text
.set noat
.set noreorder
glabel func_001dc7e0
    /* DC7E0 001DC7E0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* DC7E4 001DC7E4 0000BFFF */  sd         $31, 0x0($29)
    /* DC7E8 001DC7E8 2D300000 */  daddu      $6, $0, $0
    /* DC7EC 001DC7EC 2D380000 */  daddu      $7, $0, $0
    /* DC7F0 001DC7F0 2D400000 */  daddu      $8, $0, $0
    /* DC7F4 001DC7F4 1E00093C */  lui        $9, %hi(func_001da270)
    /* DC7F8 001DC7F8 70A22925 */  addiu      $9, $9, %lo(func_001da270)
    /* DC7FC 001DC7FC E86E070C */  jal        func_001dbba0
    /* DC800 001DC800 00000000 */   nop
    /* DC804 001DC804 0000BFDF */  ld         $31, 0x0($29)
    /* DC808 001DC808 1000BD27 */  addiu      $29, $29, 0x10
    /* DC80C 001DC80C 0800E003 */  jr         $31
    /* DC810 001DC810 00000000 */   nop
    /* DC814 001DC814 00000000 */  nop
    /* DC818 001DC818 00000000 */  nop
    /* DC81C 001DC81C 00000000 */  nop
.size func_001dc7e0, 0x40
