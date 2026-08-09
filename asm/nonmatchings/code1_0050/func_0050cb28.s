.section .text
.set noat
.set noreorder
glabel func_0050cb28
    /* 40CB28 0050CB28 7400023C */  lui        $2, %hi(D_00745884)
    /* 40CB2C 0050CB2C F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40CB30 0050CB30 8458438C */  lw         $3, %lo(D_00745884)($2)
    /* 40CB34 0050CB34 06006014 */  bnez       $3, .L0050CB50
    /* 40CB38 0050CB38 0000BFFF */   sd        $31, 0x0($29)
    /* 40CB3C 0050CB3C E832140C */  jal        func_0050cba0
    /* 40CB40 0050CB40 00000000 */   nop
    /* 40CB44 0050CB44 05000010 */  b          .L0050CB5C
    /* 40CB48 0050CB48 0000BFDF */   ld        $31, 0x0($29)
    /* 40CB4C 0050CB4C 00000000 */  nop
  .L0050CB50:
    /* 40CB50 0050CB50 DA32140C */  jal        func_0050cb68
    /* 40CB54 0050CB54 00000000 */   nop
    /* 40CB58 0050CB58 0000BFDF */  ld         $31, 0x0($29)
  .L0050CB5C:
    /* 40CB5C 0050CB5C 0800E003 */  jr         $31
    /* 40CB60 0050CB60 1000BD27 */   addiu     $29, $29, 0x10
    /* 40CB64 0050CB64 00000000 */  nop
.size func_0050cb28, 0x40
