.section .text
.set noat
.set noreorder
glabel func_001d9890
    /* D9890 001D9890 F0FFBD27 */  addiu      $29, $29, -0x10
    /* D9894 001D9894 0000BFFF */  sd         $31, 0x0($29)
    /* D9898 001D9898 3000828C */  lw         $2, 0x30($4)
    /* D989C 001D989C A2004390 */  lbu        $3, 0xA2($2)
    /* D98A0 001D98A0 01000224 */  addiu      $2, $0, 0x1
    /* D98A4 001D98A4 04106200 */  sllv       $2, $2, $3
    /* D98A8 001D98A8 FFFF4630 */  andi       $6, $2, 0xFFFF
    /* D98AC 001D98AC 0800073C */  lui        $7, (0x80000 >> 16)
    /* D98B0 001D98B0 2D400000 */  daddu      $8, $0, $0
    /* D98B4 001D98B4 1E00093C */  lui        $9, %hi(func_001d9740)
    /* D98B8 001D98B8 40972925 */  addiu      $9, $9, %lo(func_001d9740)
    /* D98BC 001D98BC 3465070C */  jal        func_001d94d0
    /* D98C0 001D98C0 00000000 */   nop
    /* D98C4 001D98C4 0000BFDF */  ld         $31, 0x0($29)
    /* D98C8 001D98C8 1000BD27 */  addiu      $29, $29, 0x10
    /* D98CC 001D98CC 0800E003 */  jr         $31
    /* D98D0 001D98D0 00000000 */   nop
    /* D98D4 001D98D4 00000000 */  nop
    /* D98D8 001D98D8 00000000 */  nop
    /* D98DC 001D98DC 00000000 */  nop
.size func_001d9890, 0x50
