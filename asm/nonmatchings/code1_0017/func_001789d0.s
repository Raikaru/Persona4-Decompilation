.section .text
.set noat
.set noreorder
glabel func_001789d0
    /* 789D0 001789D0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 789D4 001789D4 0000BFFF */  sd         $31, 0x0($29)
    /* 789D8 001789D8 04F50A0C */  jal        func_002bd410
    /* 789DC 001789DC 00000000 */   nop
    /* 789E0 001789E0 F0F40A0C */  jal        func_002bd3c0
    /* 789E4 001789E4 00000000 */   nop
    /* 789E8 001789E8 01000224 */  addiu      $2, $0, 0x1
    /* 789EC 001789EC 0000BFDF */  ld         $31, 0x0($29)
    /* 789F0 001789F0 1000BD27 */  addiu      $29, $29, 0x10
    /* 789F4 001789F4 0800E003 */  jr         $31
    /* 789F8 001789F8 00000000 */   nop
    /* 789FC 001789FC 00000000 */  nop
.size func_001789d0, 0x30
