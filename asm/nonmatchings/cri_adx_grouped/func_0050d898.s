.section .text
.set noat
.set noreorder
glabel func_0050d898
    /* 40D898 0050D898 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 40D89C 0050D89C 2000BFFF */  sd         $31, 0x20($29)
    /* 40D8A0 0050D8A0 2D28A003 */  daddu      $5, $29, $0
    /* 40D8A4 0050D8A4 428D140C */  jal        func_00523508
    /* 40D8A8 0050D8A8 3C00848C */   lw        $4, 0x3C($4)
    /* 40D8AC 0050D8AC 0400A38F */  lw         $3, 0x4($29)
    /* 40D8B0 0050D8B0 0C00A28F */  lw         $2, 0xC($29)
    /* 40D8B4 0050D8B4 2000BFDF */  ld         $31, 0x20($29)
    /* 40D8B8 0050D8B8 21106200 */  addu       $2, $3, $2
    /* 40D8BC 0050D8BC 0800E003 */  jr         $31
    /* 40D8C0 0050D8C0 3000BD27 */   addiu     $29, $29, 0x30
    /* 40D8C4 0050D8C4 00000000 */  nop
.size func_0050d898, 0x30
