.section .text
.set noat
.set noreorder
glabel func_0047ae90
    /* 37AE90 0047AE90 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 37AE94 0047AE94 0000BFFF */  sd         $31, 0x0($29)
    /* 37AE98 0047AE98 FFFFA330 */  andi       $3, $5, 0xFFFF
    /* 37AE9C 0047AE9C 40100300 */  sll        $2, $3, 1
    /* 37AEA0 0047AEA0 21104300 */  addu       $2, $2, $3
    /* 37AEA4 0047AEA4 80100200 */  sll        $2, $2, 2
    /* 37AEA8 0047AEA8 21104400 */  addu       $2, $2, $4
    /* 37AEAC 0047AEAC 9002448C */  lw         $4, 0x290($2)
    /* 37AEB0 0047AEB0 04008014 */  bnez       $4, .L0047AEC4
    /* 37AEB4 0047AEB4 00000000 */   nop
    /* 37AEB8 0047AEB8 01000224 */  addiu      $2, $0, 0x1
    /* 37AEBC 0047AEBC 03000010 */  b          .L0047AECC
    /* 37AEC0 0047AEC0 00000000 */   nop
  .L0047AEC4:
    /* 37AEC4 0047AEC4 ACE0110C */  jal        func_004782b0
    /* 37AEC8 0047AEC8 00000000 */   nop
  .L0047AECC:
    /* 37AECC 0047AECC 0000BFDF */  ld         $31, 0x0($29)
    /* 37AED0 0047AED0 1000BD27 */  addiu      $29, $29, 0x10
    /* 37AED4 0047AED4 0800E003 */  jr         $31
    /* 37AED8 0047AED8 00000000 */   nop
    /* 37AEDC 0047AEDC 00000000 */  nop
.size func_0047ae90, 0x50
