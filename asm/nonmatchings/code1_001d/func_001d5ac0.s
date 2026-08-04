.section .text
.set noat
.set noreorder
glabel func_001d5ac0
    /* D5AC0 001D5AC0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* D5AC4 001D5AC4 0000BFFF */  sd         $31, 0x0($29)
    /* D5AC8 001D5AC8 485C110C */  jal        func_00457120
    /* D5ACC 001D5ACC 00000000 */   nop
    /* D5AD0 001D5AD0 2D204000 */  daddu      $4, $2, $0
    /* D5AD4 001D5AD4 44A00F0C */  jal        func_003e8110
    /* D5AD8 001D5AD8 00000000 */   nop
    /* D5ADC 001D5ADC 485C110C */  jal        func_00457120
    /* D5AE0 001D5AE0 00000000 */   nop
    /* D5AE4 001D5AE4 0400448C */  lw         $4, 0x4($2)
    /* D5AE8 001D5AE8 8800053C */  lui        $5, %hi(D_008813B0)
    /* D5AEC 001D5AEC B013A524 */  addiu      $5, $5, %lo(D_008813B0)
    /* D5AF0 001D5AF0 2D300000 */  daddu      $6, $0, $0
    /* D5AF4 001D5AF4 2CA70F0C */  jal        func_003e9cb0
    /* D5AF8 001D5AF8 00000000 */   nop
    /* D5AFC 001D5AFC 485C110C */  jal        func_00457120
    /* D5B00 001D5B00 00000000 */   nop
    /* D5B04 001D5B04 2D204000 */  daddu      $4, $2, $0
    /* D5B08 001D5B08 48A00F0C */  jal        func_003e8120
    /* D5B0C 001D5B0C 00000000 */   nop
    /* D5B10 001D5B10 0000BFDF */  ld         $31, 0x0($29)
    /* D5B14 001D5B14 1000BD27 */  addiu      $29, $29, 0x10
    /* D5B18 001D5B18 0800E003 */  jr         $31
    /* D5B1C 001D5B1C 00000000 */   nop
.size func_001d5ac0, 0x60
