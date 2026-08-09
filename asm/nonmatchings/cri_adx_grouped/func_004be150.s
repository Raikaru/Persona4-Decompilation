.section .text
.set noat
.set noreorder
glabel func_004be150
    /* 3BE150 004BE150 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3BE154 004BE154 04008010 */  beqz       $4, .L004BE168
    /* 3BE158 004BE158 0000BFFF */   sd        $31, 0x0($29)
    /* 3BE15C 004BE15C 0000BFDF */  ld         $31, 0x0($29)
    /* 3BE160 004BE160 FEF81208 */  j          func_004be3f8
    /* 3BE164 004BE164 1000BD27 */   addiu     $29, $29, 0x10
  .L004BE168:
    /* 3BE168 004BE168 0000BFDF */  ld         $31, 0x0($29)
    /* 3BE16C 004BE16C 0800E003 */  jr         $31
    /* 3BE170 004BE170 1000BD27 */   addiu     $29, $29, 0x10
    /* 3BE174 004BE174 00000000 */  nop
.size func_004be150, 0x28
