.section .text
.set noat
.set noreorder
glabel func_0050d348
    /* 40D348 0050D348 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40D34C 0050D34C 2D100000 */  daddu      $2, $0, $0
    /* 40D350 0050D350 02008010 */  beqz       $4, .L0050D35C
    /* 40D354 0050D354 0000BFFF */   sd        $31, 0x0($29)
    /* 40D358 0050D358 3C00828C */  lw         $2, 0x3C($4)
  .L0050D35C:
    /* 40D35C 0050D35C 0000BFDF */  ld         $31, 0x0($29)
    /* 40D360 0050D360 2D204000 */  daddu      $4, $2, $0
    /* 40D364 0050D364 FE931408 */  j          func_00524ff8
    /* 40D368 0050D368 1000BD27 */   addiu     $29, $29, 0x10
    /* 40D36C 0050D36C 00000000 */  nop
.size func_0050d348, 0x28
