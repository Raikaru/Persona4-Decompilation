.section .text
.set noat
.set noreorder
glabel func_0025c420
    /* 15C420 0025C420 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 15C424 0025C424 0000BFFF */  sd         $31, 0x0($29)
    /* 15C428 0025C428 3018040C */  jal        func_001060c0
    /* 15C42C 0025C42C 00000000 */   nop
    /* 15C430 0025C430 FF004430 */  andi       $4, $2, 0xFF
    /* 15C434 0025C434 D4730A0C */  jal        func_0029cf50
    /* 15C438 0025C438 00000000 */   nop
    /* 15C43C 0025C43C 01000224 */  addiu      $2, $0, 0x1
    /* 15C440 0025C440 0000BFDF */  ld         $31, 0x0($29)
    /* 15C444 0025C444 1000BD27 */  addiu      $29, $29, 0x10
    /* 15C448 0025C448 0800E003 */  jr         $31
    /* 15C44C 0025C44C 00000000 */   nop
.size func_0025c420, 0x30
