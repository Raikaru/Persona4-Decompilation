.section .text
.set noat
.set noreorder
glabel func_004250c8
    /* 3250C8 004250C8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3250CC 004250CC 0000BFFF */  sd         $31, 0x0($29)
    /* 3250D0 004250D0 9292100C */  jal        func_00424a48
    /* 3250D4 004250D4 00000000 */   nop
    /* 3250D8 004250D8 7100023C */  lui        $2, %hi(D_0070C5F0)
    /* 3250DC 004250DC 0000BFDF */  ld         $31, 0x0($29)
    /* 3250E0 004250E0 F0C540AC */  sw         $0, %lo(D_0070C5F0)($2)
    /* 3250E4 004250E4 0800E003 */  jr         $31
    /* 3250E8 004250E8 1000BD27 */   addiu     $29, $29, 0x10
    /* 3250EC 004250EC 00000000 */  nop
.size func_004250c8, 0x28
