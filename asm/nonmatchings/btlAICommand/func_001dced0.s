.section .text
.set noat
.set noreorder
glabel func_001dced0
    /* DCED0 001DCED0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* DCED4 001DCED4 0000BFFF */  sd         $31, 0x0($29)
    /* DCED8 001DCED8 2D300000 */  daddu      $6, $0, $0
    /* DCEDC 001DCEDC 2D380000 */  daddu      $7, $0, $0
    /* DCEE0 001DCEE0 01000824 */  addiu      $8, $0, 0x1
    /* DCEE4 001DCEE4 1E00093C */  lui        $9, %hi(func_001dacc0)
    /* DCEE8 001DCEE8 C0AC2925 */  addiu      $9, $9, %lo(func_001dacc0)
    /* DCEEC 001DCEEC E86E070C */  jal        func_001dbba0
    /* DCEF0 001DCEF0 00000000 */   nop
    /* DCEF4 001DCEF4 0000BFDF */  ld         $31, 0x0($29)
    /* DCEF8 001DCEF8 1000BD27 */  addiu      $29, $29, 0x10
    /* DCEFC 001DCEFC 0800E003 */  jr         $31
    /* DCF00 001DCF00 00000000 */   nop
    /* DCF04 001DCF04 00000000 */  nop
    /* DCF08 001DCF08 00000000 */  nop
    /* DCF0C 001DCF0C 00000000 */  nop
.size func_001dced0, 0x40
