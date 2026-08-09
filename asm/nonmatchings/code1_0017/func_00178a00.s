.section .text
.set noat
.set noreorder
glabel func_00178a00
    /* 78A00 00178A00 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 78A04 00178A04 0000BFFF */  sd         $31, 0x0($29)
    /* 78A08 00178A08 E0B2828F */  lw         $2, -0x4D20($28)
    /* 78A0C 00178A0C 0C004494 */  lhu        $4, 0xC($2)
    /* 78A10 00178A10 D4730A0C */  jal        func_0029cf50
    /* 78A14 00178A14 00000000 */   nop
    /* 78A18 00178A18 01000224 */  addiu      $2, $0, 0x1
    /* 78A1C 00178A1C 0000BFDF */  ld         $31, 0x0($29)
    /* 78A20 00178A20 1000BD27 */  addiu      $29, $29, 0x10
    /* 78A24 00178A24 0800E003 */  jr         $31
    /* 78A28 00178A28 00000000 */   nop
    /* 78A2C 00178A2C 00000000 */  nop
.size func_00178a00, 0x30
