.section .text
.set noat
.set noreorder
glabel func_004be480
    /* 3BE480 004BE480 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3BE484 004BE484 04008010 */  beqz       $4, .L004BE498
    /* 3BE488 004BE488 0000BFFF */   sd        $31, 0x0($29)
    /* 3BE48C 004BE48C 0000BFDF */  ld         $31, 0x0($29)
    /* 3BE490 004BE490 E8FE1208 */  j          func_004bfba0
    /* 3BE494 004BE494 1000BD27 */   addiu     $29, $29, 0x10
  .L004BE498:
    /* 3BE498 004BE498 0000BFDF */  ld         $31, 0x0($29)
    /* 3BE49C 004BE49C 0800E003 */  jr         $31
    /* 3BE4A0 004BE4A0 1000BD27 */   addiu     $29, $29, 0x10
    /* 3BE4A4 004BE4A4 00000000 */  nop
.size func_004be480, 0x28
