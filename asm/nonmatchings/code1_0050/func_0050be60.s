.section .text
.set noat
.set noreorder
glabel func_0050be60
    /* 40BE60 0050BE60 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40BE64 0050BE64 0000BFFF */  sd         $31, 0x0($29)
    /* 40BE68 0050BE68 0500A004 */  bltz       $5, .L0050BE80
    /* 40BE6C 0050BE6C 3C00848C */   lw        $4, 0x3C($4)
    /* 40BE70 0050BE70 0000BFDF */  ld         $31, 0x0($29)
    /* 40BE74 0050BE74 5E8D1408 */  j          func_00523578
    /* 40BE78 0050BE78 1000BD27 */   addiu     $29, $29, 0x10
    /* 40BE7C 0050BE7C 00000000 */  nop
  .L0050BE80:
    /* 40BE80 0050BE80 0000BFDF */  ld         $31, 0x0($29)
    /* 40BE84 0050BE84 0800E003 */  jr         $31
    /* 40BE88 0050BE88 1000BD27 */   addiu     $29, $29, 0x10
    /* 40BE8C 0050BE8C 00000000 */  nop
.size func_0050be60, 0x30
