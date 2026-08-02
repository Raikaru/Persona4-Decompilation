.section .text
.set noat
.set noreorder
glabel func_0036dee0
    /* 26DEE0 0036DEE0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 26DEE4 0036DEE4 1000BFFF */  sd         $31, 0x10($29)
    /* 26DEE8 0036DEE8 0000B07F */  sq         $16, 0x0($29)
    /* 26DEEC 0036DEEC 2D808000 */  daddu      $16, $4, $0
    /* 26DEF0 0036DEF0 0400828C */  lw         $2, 0x4($4)
    /* 26DEF4 0036DEF4 06004010 */  beqz       $2, .L0036DF10
    /* 26DEF8 0036DEF8 00000000 */   nop
    /* 26DEFC 0036DEFC 6500043C */  lui        $4, %hi(D_0064E5B0)
    /* 26DF00 0036DF00 B0E58424 */  addiu      $4, $4, %lo(D_0064E5B0)
    /* 26DF04 0036DF04 60010524 */  addiu      $5, $0, 0x160
    /* 26DF08 0036DF08 CCB5110C */  jal        func_0046d730
    /* 26DF0C 0036DF0C 00000000 */   nop
  .L0036DF10:
    /* 26DF10 0036DF10 74010296 */  lhu        $2, 0x174($16)
    /* 26DF14 0036DF14 1000BFDF */  ld         $31, 0x10($29)
    /* 26DF18 0036DF18 0000B07B */  lq         $16, 0x0($29)
    /* 26DF1C 0036DF1C 2000BD27 */  addiu      $29, $29, 0x20
    /* 26DF20 0036DF20 0800E003 */  jr         $31
    /* 26DF24 0036DF24 00000000 */   nop
    /* 26DF28 0036DF28 00000000 */  nop
    /* 26DF2C 0036DF2C 00000000 */  nop
.size func_0036dee0, 0x50
