.section .text
.set noat
.set noreorder
glabel func_001dd010
    /* DD010 001DD010 F0FFBD27 */  addiu      $29, $29, -0x10
    /* DD014 001DD014 0000BFFF */  sd         $31, 0x0($29)
    /* DD018 001DD018 2D300000 */  daddu      $6, $0, $0
    /* DD01C 001DD01C 2D380000 */  daddu      $7, $0, $0
    /* DD020 001DD020 01000824 */  addiu      $8, $0, 0x1
    /* DD024 001DD024 1E00093C */  lui        $9, %hi(func_001db8d0)
    /* DD028 001DD028 D0B82925 */  addiu      $9, $9, %lo(func_001db8d0)
    /* DD02C 001DD02C E86E070C */  jal        func_001dbba0
    /* DD030 001DD030 00000000 */   nop
    /* DD034 001DD034 0000BFDF */  ld         $31, 0x0($29)
    /* DD038 001DD038 1000BD27 */  addiu      $29, $29, 0x10
    /* DD03C 001DD03C 0800E003 */  jr         $31
    /* DD040 001DD040 00000000 */   nop
    /* DD044 001DD044 00000000 */  nop
    /* DD048 001DD048 00000000 */  nop
    /* DD04C 001DD04C 00000000 */  nop
.size func_001dd010, 0x40
