.section .text
.set noat
.set noreorder
glabel func_0050d2f0
    /* 40D2F0 0050D2F0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40D2F4 0050D2F4 0000BFFF */  sd         $31, 0x0($29)
    /* 40D2F8 0050D2F8 3C00828C */  lw         $2, 0x3C($4)
    /* 40D2FC 0050D2FC 04004010 */  beqz       $2, .L0050D310
    /* 40D300 0050D300 2D204000 */   daddu     $4, $2, $0
    /* 40D304 0050D304 0000BFDF */  ld         $31, 0x0($29)
    /* 40D308 0050D308 2A941408 */  j          func_005250a8
    /* 40D30C 0050D30C 1000BD27 */   addiu     $29, $29, 0x10
  .L0050D310:
    /* 40D310 0050D310 0000BFDF */  ld         $31, 0x0($29)
    /* 40D314 0050D314 0800E003 */  jr         $31
    /* 40D318 0050D318 1000BD27 */   addiu     $29, $29, 0x10
    /* 40D31C 0050D31C 00000000 */  nop
.size func_0050d2f0, 0x30
