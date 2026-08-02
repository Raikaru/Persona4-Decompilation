.section .text
.set noat
.set noreorder
glabel func_001dce90
    /* DCE90 001DCE90 F0FFBD27 */  addiu      $29, $29, -0x10
    /* DCE94 001DCE94 0000BFFF */  sd         $31, 0x0($29)
    /* DCE98 001DCE98 2D300000 */  daddu      $6, $0, $0
    /* DCE9C 001DCE9C 01000724 */  addiu      $7, $0, 0x1
    /* DCEA0 001DCEA0 2D400000 */  daddu      $8, $0, $0
    /* DCEA4 001DCEA4 1E00093C */  lui        $9, %hi(func_001da2f0)
    /* DCEA8 001DCEA8 F0A22925 */  addiu      $9, $9, %lo(func_001da2f0)
    /* DCEAC 001DCEAC E86E070C */  jal        func_001dbba0
    /* DCEB0 001DCEB0 00000000 */   nop
    /* DCEB4 001DCEB4 0000BFDF */  ld         $31, 0x0($29)
    /* DCEB8 001DCEB8 1000BD27 */  addiu      $29, $29, 0x10
    /* DCEBC 001DCEBC 0800E003 */  jr         $31
    /* DCEC0 001DCEC0 00000000 */   nop
    /* DCEC4 001DCEC4 00000000 */  nop
    /* DCEC8 001DCEC8 00000000 */  nop
    /* DCECC 001DCECC 00000000 */  nop
.size func_001dce90, 0x40
