.section .text
.set noat
.set noreorder
glabel func_00425ab0
    /* 325AB0 00425AB0 0000858C */  lw         $5, 0x0($4)
    /* 325AB4 00425AB4 0900A010 */  beqz       $5, .L00425ADC
    /* 325AB8 00425AB8 00000000 */   nop
    /* 325ABC 00425ABC 0400838C */  lw         $3, 0x4($4)
    /* 325AC0 00425AC0 1800A28C */  lw         $2, 0x18($5)
    /* 325AC4 00425AC4 05006214 */  bne        $3, $2, .L00425ADC
    /* 325AC8 00425AC8 00000000 */   nop
    /* 325ACC 00425ACC 1000A28C */  lw         $2, 0x10($5)
    /* 325AD0 00425AD0 01004230 */  andi       $2, $2, 0x1
    /* 325AD4 00425AD4 03004014 */  bnez       $2, .L00425AE4
    /* 325AD8 00425AD8 00000000 */   nop
  .L00425ADC:
    /* 325ADC 00425ADC 0800E003 */  jr         $31
    /* 325AE0 00425AE0 2D100000 */   daddu     $2, $0, $0
  .L00425AE4:
    /* 325AE4 00425AE4 0800E003 */  jr         $31
    /* 325AE8 00425AE8 01000224 */   addiu     $2, $0, 0x1
    /* 325AEC 00425AEC 00000000 */  nop
.size func_00425ab0, 0x40
