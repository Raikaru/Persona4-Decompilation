.section .text
.set noat
.set noreorder
glabel func_0050bd48
    /* 40BD48 0050BD48 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40BD4C 0050BD4C 08008010 */  beqz       $4, .L0050BD70
    /* 40BD50 0050BD50 0000BFFF */   sd        $31, 0x0($29)
    /* 40BD54 0050BD54 9833140C */  jal        func_0050ce60
    /* 40BD58 0050BD58 00000000 */   nop
    /* 40BD5C 0050BD5C 0000BFDF */  ld         $31, 0x0($29)
    /* 40BD60 0050BD60 2D204000 */  daddu      $4, $2, $0
    /* 40BD64 0050BD64 E0981408 */  j          func_00526380
    /* 40BD68 0050BD68 1000BD27 */   addiu     $29, $29, 0x10
    /* 40BD6C 0050BD6C 00000000 */  nop
  .L0050BD70:
    /* 40BD70 0050BD70 0000BFDF */  ld         $31, 0x0($29)
    /* 40BD74 0050BD74 E0981408 */  j          func_00526380
    /* 40BD78 0050BD78 1000BD27 */   addiu     $29, $29, 0x10
    /* 40BD7C 0050BD7C 00000000 */  nop
.size func_0050bd48, 0x38
