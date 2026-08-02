.section .text
.set noat
.set noreorder
glabel func_001dd090
    /* DD090 001DD090 F0FFBD27 */  addiu      $29, $29, -0x10
    /* DD094 001DD094 0000BFFF */  sd         $31, 0x0($29)
    /* DD098 001DD098 2D300000 */  daddu      $6, $0, $0
    /* DD09C 001DD09C 2D380000 */  daddu      $7, $0, $0
    /* DD0A0 001DD0A0 2D400000 */  daddu      $8, $0, $0
    /* DD0A4 001DD0A4 1E00093C */  lui        $9, %hi(func_001db580)
    /* DD0A8 001DD0A8 80B52925 */  addiu      $9, $9, %lo(func_001db580)
    /* DD0AC 001DD0AC E86E070C */  jal        func_001dbba0
    /* DD0B0 001DD0B0 00000000 */   nop
    /* DD0B4 001DD0B4 0000BFDF */  ld         $31, 0x0($29)
    /* DD0B8 001DD0B8 1000BD27 */  addiu      $29, $29, 0x10
    /* DD0BC 001DD0BC 0800E003 */  jr         $31
    /* DD0C0 001DD0C0 00000000 */   nop
    /* DD0C4 001DD0C4 00000000 */  nop
    /* DD0C8 001DD0C8 00000000 */  nop
    /* DD0CC 001DD0CC 00000000 */  nop
.size func_001dd090, 0x40
