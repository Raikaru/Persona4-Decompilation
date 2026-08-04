.section .text
.set noat
.set noreorder
glabel func_0019dea0
    /* 9DEA0 0019DEA0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 9DEA4 0019DEA4 1000BFFF */  sd         $31, 0x10($29)
    /* 9DEA8 0019DEA8 0000B07F */  sq         $16, 0x0($29)
    /* 9DEAC 0019DEAC 2D808000 */  daddu      $16, $4, $0
    /* 9DEB0 0019DEB0 9800838C */  lw         $3, 0x98($4)
    /* 9DEB4 0019DEB4 02006330 */  andi       $3, $3, 0x2
    /* 9DEB8 0019DEB8 0C006010 */  beqz       $3, .L0019DEEC
    /* 9DEBC 0019DEBC 00000000 */   nop
    /* 9DEC0 0019DEC0 000A048E */  lw         $4, 0xA00($16)
    /* 9DEC4 0019DEC4 74EA110C */  jal        func_0047a9d0
    /* 9DEC8 0019DEC8 00000000 */   nop
    /* 9DECC 0019DECC 07004010 */  beqz       $2, .L0019DEEC
    /* 9DED0 0019DED0 00000000 */   nop
    /* 9DED4 0019DED4 000A048E */  lw         $4, 0xA00($16)
    /* 9DED8 0019DED8 6CEA110C */  jal        func_0047a9b0
    /* 9DEDC 0019DEDC 00000000 */   nop
    /* 9DEE0 0019DEE0 000A048E */  lw         $4, 0xA00($16)
    /* 9DEE4 0019DEE4 64EA110C */  jal        func_0047a990
    /* 9DEE8 0019DEE8 00000000 */   nop
  .L0019DEEC:
    /* 9DEEC 0019DEEC 1000BFDF */  ld         $31, 0x10($29)
    /* 9DEF0 0019DEF0 0000B07B */  lq         $16, 0x0($29)
    /* 9DEF4 0019DEF4 2000BD27 */  addiu      $29, $29, 0x20
    /* 9DEF8 0019DEF8 0800E003 */  jr         $31
    /* 9DEFC 0019DEFC 00000000 */   nop
.size func_0019dea0, 0x60
