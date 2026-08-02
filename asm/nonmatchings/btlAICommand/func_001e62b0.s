.section .text
.set noat
.set noreorder
glabel func_001e62b0
    /* E62B0 001E62B0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* E62B4 001E62B4 1000BFFF */  sd         $31, 0x10($29)
    /* E62B8 001E62B8 0000B07F */  sq         $16, 0x0($29)
    /* E62BC 001E62BC 14740A0C */  jal        func_0029d050
    /* E62C0 001E62C0 00000000 */   nop
    /* E62C4 001E62C4 2D804000 */  daddu      $16, $2, $0
    /* E62C8 001E62C8 2D200000 */  daddu      $4, $0, $0
    /* E62CC 001E62CC 00730A0C */  jal        func_0029cc00
    /* E62D0 001E62D0 00000000 */   nop
    /* E62D4 001E62D4 2D200002 */  daddu      $4, $16, $0
    /* E62D8 001E62D8 2D284000 */  daddu      $5, $2, $0
    /* E62DC 001E62DC 0800063C */  lui        $6, (0x80000 >> 16)
    /* E62E0 001E62E0 02000724 */  addiu      $7, $0, 0x2
    /* E62E4 001E62E4 2D400000 */  daddu      $8, $0, $0
    /* E62E8 001E62E8 1E00093C */  lui        $9, %hi(func_001db8d0)
    /* E62EC 001E62EC D0B82925 */  addiu      $9, $9, %lo(func_001db8d0)
    /* E62F0 001E62F0 2D500000 */  daddu      $10, $0, $0
    /* E62F4 001E62F4 E464070C */  jal        func_001d9390
    /* E62F8 001E62F8 00000000 */   nop
    /* E62FC 001E62FC FFFF4430 */  andi       $4, $2, 0xFFFF
    /* E6300 001E6300 D4730A0C */  jal        func_0029cf50
    /* E6304 001E6304 00000000 */   nop
    /* E6308 001E6308 01000224 */  addiu      $2, $0, 0x1
    /* E630C 001E630C 1000BFDF */  ld         $31, 0x10($29)
    /* E6310 001E6310 0000B07B */  lq         $16, 0x0($29)
    /* E6314 001E6314 2000BD27 */  addiu      $29, $29, 0x20
    /* E6318 001E6318 0800E003 */  jr         $31
    /* E631C 001E631C 00000000 */   nop
.size func_001e62b0, 0x70
