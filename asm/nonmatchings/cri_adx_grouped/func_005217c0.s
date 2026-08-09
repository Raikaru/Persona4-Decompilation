.section .text
.set noat
.set noreorder
glabel func_005217c0
    /* 4217C0 005217C0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 4217C4 005217C4 0000BFFF */  sd         $31, 0x0($29)
    /* 4217C8 005217C8 FA85140C */  jal        func_005217e8
    /* 4217CC 005217CC 00000000 */   nop
    /* 4217D0 005217D0 0000BFDF */  ld         $31, 0x0($29)
    /* 4217D4 005217D4 7400023C */  lui        $2, %hi(D_00745B0C)
    /* 4217D8 005217D8 0C5B40AC */  sw         $0, %lo(D_00745B0C)($2)
    /* 4217DC 005217DC 0800E003 */  jr         $31
    /* 4217E0 005217E0 1000BD27 */   addiu     $29, $29, 0x10
    /* 4217E4 005217E4 00000000 */  nop
.size func_005217c0, 0x28
