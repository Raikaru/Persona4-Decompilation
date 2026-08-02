.section .text
.set noat
.set noreorder
glabel func_0036df90
    /* 26DF90 0036DF90 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 26DF94 0036DF94 2000BFFF */  sd         $31, 0x20($29)
    /* 26DF98 0036DF98 1000B17F */  sq         $17, 0x10($29)
    /* 26DF9C 0036DF9C 0000B07F */  sq         $16, 0x0($29)
    /* 26DFA0 0036DFA0 2D888000 */  daddu      $17, $4, $0
    /* 26DFA4 0036DFA4 2D80A000 */  daddu      $16, $5, $0
    /* 26DFA8 0036DFA8 A80F858C */  lw         $5, 0xFA8($4)
    /* 26DFAC 0036DFAC 0400A010 */  beqz       $5, .L0036DFC0
    /* 26DFB0 0036DFB0 00000000 */   nop
    /* 26DFB4 0036DFB4 00062426 */  addiu      $4, $17, 0x600
    /* 26DFB8 0036DFB8 8CAD0D0C */  jal        func_0036b630
    /* 26DFBC 0036DFBC 00000000 */   nop
  .L0036DFC0:
    /* 26DFC0 0036DFC0 2D202002 */  daddu      $4, $17, $0
    /* 26DFC4 0036DFC4 A0A30D0C */  jal        func_00368e80
    /* 26DFC8 0036DFC8 00000000 */   nop
    /* 26DFCC 0036DFCC 2D202002 */  daddu      $4, $17, $0
    /* 26DFD0 0036DFD0 2D280002 */  daddu      $5, $16, $0
    /* 26DFD4 0036DFD4 1CA50D0C */  jal        func_00369470
    /* 26DFD8 0036DFD8 00000000 */   nop
    /* 26DFDC 0036DFDC 2000BFDF */  ld         $31, 0x20($29)
    /* 26DFE0 0036DFE0 1000B17B */  lq         $17, 0x10($29)
    /* 26DFE4 0036DFE4 0000B07B */  lq         $16, 0x0($29)
    /* 26DFE8 0036DFE8 3000BD27 */  addiu      $29, $29, 0x30
    /* 26DFEC 0036DFEC 0800E003 */  jr         $31
    /* 26DFF0 0036DFF0 00000000 */   nop
    /* 26DFF4 0036DFF4 00000000 */  nop
    /* 26DFF8 0036DFF8 00000000 */  nop
    /* 26DFFC 0036DFFC 00000000 */  nop
.size func_0036df90, 0x70
