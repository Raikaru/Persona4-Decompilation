.section .text
.set noat
.set noreorder
glabel func_005120b8
    /* 4120B8 005120B8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 4120BC 005120BC 04008010 */  beqz       $4, .L005120D0
    /* 4120C0 005120C0 0000BFFF */   sd        $31, 0x0($29)
    /* 4120C4 005120C4 0000BFDF */  ld         $31, 0x0($29)
    /* 4120C8 005120C8 0C4B1308 */  j          func_004d2c30
    /* 4120CC 005120CC 1000BD27 */   addiu     $29, $29, 0x10
  .L005120D0:
    /* 4120D0 005120D0 0000BFDF */  ld         $31, 0x0($29)
    /* 4120D4 005120D4 0800E003 */  jr         $31
    /* 4120D8 005120D8 1000BD27 */   addiu     $29, $29, 0x10
    /* 4120DC 005120DC 00000000 */  nop
.size func_005120b8, 0x28
