.section .text
.set noat
.set noreorder
glabel func_001dcdd0
    /* DCDD0 001DCDD0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* DCDD4 001DCDD4 0000BFFF */  sd         $31, 0x0($29)
    /* DCDD8 001DCDD8 2D300000 */  daddu      $6, $0, $0
    /* DCDDC 001DCDDC 01000724 */  addiu      $7, $0, 0x1
    /* DCDE0 001DCDE0 2D400000 */  daddu      $8, $0, $0
    /* DCDE4 001DCDE4 1E00093C */  lui        $9, %hi(func_001da230)
    /* DCDE8 001DCDE8 30A22925 */  addiu      $9, $9, %lo(func_001da230)
    /* DCDEC 001DCDEC E86E070C */  jal        func_001dbba0
    /* DCDF0 001DCDF0 00000000 */   nop
    /* DCDF4 001DCDF4 0000BFDF */  ld         $31, 0x0($29)
    /* DCDF8 001DCDF8 1000BD27 */  addiu      $29, $29, 0x10
    /* DCDFC 001DCDFC 0800E003 */  jr         $31
    /* DCE00 001DCE00 00000000 */   nop
    /* DCE04 001DCE04 00000000 */  nop
    /* DCE08 001DCE08 00000000 */  nop
    /* DCE0C 001DCE0C 00000000 */  nop
.size func_001dcdd0, 0x40
