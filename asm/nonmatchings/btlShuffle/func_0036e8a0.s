.section .text
.set noat
.set noreorder
glabel func_0036e8a0
    /* 26E8A0 0036E8A0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 26E8A4 0036E8A4 0000BFFF */  sd         $31, 0x0($29)
    /* 26E8A8 0036E8A8 5849110C */  jal        func_00452560
    /* 26E8AC 0036E8AC 00000000 */   nop
    /* 26E8B0 0036E8B0 00004294 */  lhu        $2, 0x0($2)
    /* 26E8B4 0036E8B4 04004230 */  andi       $2, $2, 0x4
    /* 26E8B8 0036E8B8 2B100200 */  sltu       $2, $0, $2
    /* 26E8BC 0036E8BC 0000BFDF */  ld         $31, 0x0($29)
    /* 26E8C0 0036E8C0 1000BD27 */  addiu      $29, $29, 0x10
    /* 26E8C4 0036E8C4 0800E003 */  jr         $31
    /* 26E8C8 0036E8C8 00000000 */   nop
    /* 26E8CC 0036E8CC 00000000 */  nop
.size func_0036e8a0, 0x30
