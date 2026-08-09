.section .text
.set noat
.set noreorder
glabel func_003993b0
    /* 2993B0 003993B0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2993B4 003993B4 0000BFFF */  sd         $31, 0x0($29)
    /* 2993B8 003993B8 1C00A527 */  addiu      $5, $29, 0x1C
    /* 2993BC 003993BC E8B5828F */  lw         $2, -0x4A18($28)
    /* 2993C0 003993C0 2110C200 */  addu       $2, $6, $2
    /* 2993C4 003993C4 0000428C */  lw         $2, 0x0($2)
    /* 2993C8 003993C8 04000624 */  addiu      $6, $0, 0x4
    /* 2993CC 003993CC 907C0F0C */  jal        func_003df240
    /* 2993D0 003993D0 1C00A2AF */   sw        $2, 0x1C($29)
    /* 2993D4 003993D4 0000BFDF */  ld         $31, 0x0($29)
    /* 2993D8 003993D8 0800E003 */  jr         $31
    /* 2993DC 003993DC 2000BD27 */   addiu     $29, $29, 0x20
.size func_003993b0, 0x30
