.section .text
.set noat
.set noreorder
glabel func_001dd050
    /* DD050 001DD050 F0FFBD27 */  addiu      $29, $29, -0x10
    /* DD054 001DD054 0000BFFF */  sd         $31, 0x0($29)
    /* DD058 001DD058 2D300000 */  daddu      $6, $0, $0
    /* DD05C 001DD05C 2D380000 */  daddu      $7, $0, $0
    /* DD060 001DD060 2D400000 */  daddu      $8, $0, $0
    /* DD064 001DD064 1E00093C */  lui        $9, %hi(func_001db9f0)
    /* DD068 001DD068 F0B92925 */  addiu      $9, $9, %lo(func_001db9f0)
    /* DD06C 001DD06C E86E070C */  jal        func_001dbba0
    /* DD070 001DD070 00000000 */   nop
    /* DD074 001DD074 0000BFDF */  ld         $31, 0x0($29)
    /* DD078 001DD078 1000BD27 */  addiu      $29, $29, 0x10
    /* DD07C 001DD07C 0800E003 */  jr         $31
    /* DD080 001DD080 00000000 */   nop
    /* DD084 001DD084 00000000 */  nop
    /* DD088 001DD088 00000000 */  nop
    /* DD08C 001DD08C 00000000 */  nop
.size func_001dd050, 0x40
