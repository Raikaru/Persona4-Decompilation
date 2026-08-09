.section .text
.set noat
.set noreorder
glabel func_001ceff0
    /* CEFF0 001CEFF0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* CEFF4 001CEFF4 0000BFFF */  sd         $31, 0x0($29)
    /* CEFF8 001CEFF8 2D200000 */  daddu      $4, $0, $0
    /* CEFFC 001CEFFC FCDC060C */  jal        func_001b73f0
    /* CF000 001CF000 00000000 */   nop
    /* CF004 001CF004 05000424 */  addiu      $4, $0, 0x5
    /* CF008 001CF008 44CC120C */  jal        func_004b3110
    /* CF00C 001CF00C 00000000 */   nop
    /* CF010 001CF010 0000BFDF */  ld         $31, 0x0($29)
    /* CF014 001CF014 1000BD27 */  addiu      $29, $29, 0x10
    /* CF018 001CF018 0800E003 */  jr         $31
    /* CF01C 001CF01C 00000000 */   nop
.size func_001ceff0, 0x30
