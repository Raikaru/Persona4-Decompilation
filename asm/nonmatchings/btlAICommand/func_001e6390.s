.section .text
.set noat
.set noreorder
glabel func_001e6390
    /* E6390 001E6390 E0FFBD27 */  addiu      $29, $29, -0x20
    /* E6394 001E6394 1000BFFF */  sd         $31, 0x10($29)
    /* E6398 001E6398 0000B07F */  sq         $16, 0x0($29)
    /* E639C 001E639C 14740A0C */  jal        func_0029d050
    /* E63A0 001E63A0 00000000 */   nop
    /* E63A4 001E63A4 2D804000 */  daddu      $16, $2, $0
    /* E63A8 001E63A8 2D200000 */  daddu      $4, $0, $0
    /* E63AC 001E63AC 00730A0C */  jal        func_0029cc00
    /* E63B0 001E63B0 00000000 */   nop
    /* E63B4 001E63B4 2D200002 */  daddu      $4, $16, $0
    /* E63B8 001E63B8 2D284000 */  daddu      $5, $2, $0
    /* E63BC 001E63BC 0800063C */  lui        $6, (0x80000 >> 16)
    /* E63C0 001E63C0 01000724 */  addiu      $7, $0, 0x1
    /* E63C4 001E63C4 2D400000 */  daddu      $8, $0, $0
    /* E63C8 001E63C8 1E00093C */  lui        $9, %hi(func_001d9740)
    /* E63CC 001E63CC 40972925 */  addiu      $9, $9, %lo(func_001d9740)
    /* E63D0 001E63D0 2D500000 */  daddu      $10, $0, $0
    /* E63D4 001E63D4 E464070C */  jal        func_001d9390
    /* E63D8 001E63D8 00000000 */   nop
    /* E63DC 001E63DC FFFF4430 */  andi       $4, $2, 0xFFFF
    /* E63E0 001E63E0 D4730A0C */  jal        func_0029cf50
    /* E63E4 001E63E4 00000000 */   nop
    /* E63E8 001E63E8 01000224 */  addiu      $2, $0, 0x1
    /* E63EC 001E63EC 1000BFDF */  ld         $31, 0x10($29)
    /* E63F0 001E63F0 0000B07B */  lq         $16, 0x0($29)
    /* E63F4 001E63F4 2000BD27 */  addiu      $29, $29, 0x20
    /* E63F8 001E63F8 0800E003 */  jr         $31
    /* E63FC 001E63FC 00000000 */   nop
.size func_001e6390, 0x70
