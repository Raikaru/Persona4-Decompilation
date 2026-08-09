.section .text
.set noat
.set noreorder
glabel func_0050dc98
    /* 40DC98 0050DC98 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40DC9C 0050DC9C 2D30A000 */  daddu      $6, $5, $0
    /* 40DCA0 0050DCA0 0000BFFF */  sd         $31, 0x0($29)
    /* 40DCA4 0050DCA4 25000524 */  addiu      $5, $0, 0x25
    /* 40DCA8 0050DCA8 05008010 */  beqz       $4, .L0050DCC0
    /* 40DCAC 0050DCAC 3C00828C */   lw        $2, 0x3C($4)
    /* 40DCB0 0050DCB0 0000BFDF */  ld         $31, 0x0($29)
    /* 40DCB4 0050DCB4 2D204000 */  daddu      $4, $2, $0
    /* 40DCB8 0050DCB8 64931408 */  j          func_00524d90
    /* 40DCBC 0050DCBC 1000BD27 */   addiu     $29, $29, 0x10
  .L0050DCC0:
    /* 40DCC0 0050DCC0 0000BFDF */  ld         $31, 0x0($29)
    /* 40DCC4 0050DCC4 0800E003 */  jr         $31
    /* 40DCC8 0050DCC8 1000BD27 */   addiu     $29, $29, 0x10
    /* 40DCCC 0050DCCC 00000000 */  nop
.size func_0050dc98, 0x38
