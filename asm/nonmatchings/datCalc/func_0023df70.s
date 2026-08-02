.section .text
.set noat
.set noreorder
glabel func_0023df70
    /* 13DF70 0023DF70 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 13DF74 0023DF74 1000BFFF */  sd         $31, 0x10($29)
    /* 13DF78 0023DF78 0000B07F */  sq         $16, 0x0($29)
    /* 13DF7C 0023DF7C 2D808000 */  daddu      $16, $4, $0
    /* 13DF80 0023DF80 FFFF0232 */  andi       $2, $16, 0xFFFF
    /* 13DF84 0023DF84 B8014228 */  slti       $2, $2, 0x1B8
    /* 13DF88 0023DF88 06004014 */  bnez       $2, .L0023DFA4
    /* 13DF8C 0023DF8C 00000000 */   nop
    /* 13DF90 0023DF90 6300043C */  lui        $4, %hi(D_00635938)
    /* 13DF94 0023DF94 38598424 */  addiu      $4, $4, %lo(D_00635938)
    /* 13DF98 0023DF98 5E0F0524 */  addiu      $5, $0, 0xF5E
    /* 13DF9C 0023DF9C CCB5110C */  jal        func_0046d730
    /* 13DFA0 0023DFA0 00000000 */   nop
  .L0023DFA4:
    /* 13DFA4 0023DFA4 FFFF0332 */  andi       $3, $16, 0xFFFF
    /* 13DFA8 0023DFA8 80100300 */  sll        $2, $3, 2
    /* 13DFAC 0023DFAC 21104300 */  addu       $2, $2, $3
    /* 13DFB0 0023DFB0 C0180200 */  sll        $3, $2, 3
    /* 13DFB4 0023DFB4 B8B3828F */  lw         $2, -0x4C48($28)
    /* 13DFB8 0023DFB8 21104300 */  addu       $2, $2, $3
    /* 13DFBC 0023DFBC 00004290 */  lbu        $2, 0x0($2)
    /* 13DFC0 0023DFC0 02004230 */  andi       $2, $2, 0x2
    /* 13DFC4 0023DFC4 2B100200 */  sltu       $2, $0, $2
    /* 13DFC8 0023DFC8 1000BFDF */  ld         $31, 0x10($29)
    /* 13DFCC 0023DFCC 0000B07B */  lq         $16, 0x0($29)
    /* 13DFD0 0023DFD0 2000BD27 */  addiu      $29, $29, 0x20
    /* 13DFD4 0023DFD4 0800E003 */  jr         $31
    /* 13DFD8 0023DFD8 00000000 */   nop
    /* 13DFDC 0023DFDC 00000000 */  nop
.size func_0023df70, 0x70
