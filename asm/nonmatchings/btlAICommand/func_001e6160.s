.section .text
.set noat
.set noreorder
glabel func_001e6160
    /* E6160 001E6160 E0FFBD27 */  addiu      $29, $29, -0x20
    /* E6164 001E6164 1000BFFF */  sd         $31, 0x10($29)
    /* E6168 001E6168 0000B07F */  sq         $16, 0x0($29)
    /* E616C 001E616C 14740A0C */  jal        func_0029d050
    /* E6170 001E6170 00000000 */   nop
    /* E6174 001E6174 2D804000 */  daddu      $16, $2, $0
    /* E6178 001E6178 2D200000 */  daddu      $4, $0, $0
    /* E617C 001E617C 00730A0C */  jal        func_0029cc00
    /* E6180 001E6180 00000000 */   nop
    /* E6184 001E6184 2D200002 */  daddu      $4, $16, $0
    /* E6188 001E6188 2D284000 */  daddu      $5, $2, $0
    /* E618C 001E618C 0800063C */  lui        $6, (0x80000 >> 16)
    /* E6190 001E6190 01000724 */  addiu      $7, $0, 0x1
    /* E6194 001E6194 2D40E000 */  daddu      $8, $7, $0
    /* E6198 001E6198 1E00093C */  lui        $9, %hi(func_001db8d0)
    /* E619C 001E619C D0B82925 */  addiu      $9, $9, %lo(func_001db8d0)
    /* E61A0 001E61A0 2D500000 */  daddu      $10, $0, $0
    /* E61A4 001E61A4 E464070C */  jal        func_001d9390
    /* E61A8 001E61A8 00000000 */   nop
    /* E61AC 001E61AC FFFF4430 */  andi       $4, $2, 0xFFFF
    /* E61B0 001E61B0 D4730A0C */  jal        func_0029cf50
    /* E61B4 001E61B4 00000000 */   nop
    /* E61B8 001E61B8 01000224 */  addiu      $2, $0, 0x1
    /* E61BC 001E61BC 1000BFDF */  ld         $31, 0x10($29)
    /* E61C0 001E61C0 0000B07B */  lq         $16, 0x0($29)
    /* E61C4 001E61C4 2000BD27 */  addiu      $29, $29, 0x20
    /* E61C8 001E61C8 0800E003 */  jr         $31
    /* E61CC 001E61CC 00000000 */   nop
.size func_001e6160, 0x70
