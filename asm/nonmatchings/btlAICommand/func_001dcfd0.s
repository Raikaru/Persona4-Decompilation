.section .text
.set noat
.set noreorder
glabel func_001dcfd0
    /* DCFD0 001DCFD0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* DCFD4 001DCFD4 0000BFFF */  sd         $31, 0x0($29)
    /* DCFD8 001DCFD8 2D300000 */  daddu      $6, $0, $0
    /* DCFDC 001DCFDC 2D380000 */  daddu      $7, $0, $0
    /* DCFE0 001DCFE0 2D400000 */  daddu      $8, $0, $0
    /* DCFE4 001DCFE4 1E00093C */  lui        $9, %hi(func_001db8d0)
    /* DCFE8 001DCFE8 D0B82925 */  addiu      $9, $9, %lo(func_001db8d0)
    /* DCFEC 001DCFEC E86E070C */  jal        func_001dbba0
    /* DCFF0 001DCFF0 00000000 */   nop
    /* DCFF4 001DCFF4 0000BFDF */  ld         $31, 0x0($29)
    /* DCFF8 001DCFF8 1000BD27 */  addiu      $29, $29, 0x10
    /* DCFFC 001DCFFC 0800E003 */  jr         $31
    /* DD000 001DD000 00000000 */   nop
    /* DD004 001DD004 00000000 */  nop
    /* DD008 001DD008 00000000 */  nop
    /* DD00C 001DD00C 00000000 */  nop
.size func_001dcfd0, 0x40
