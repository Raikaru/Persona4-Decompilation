.section .text
.set noat
.set noreorder
glabel func_0052d898
    /* 42D898 0052D898 7400023C */  lui        $2, %hi(D_007463B0)
    /* 42D89C 0052D89C F0FFBD27 */  addiu      $29, $29, -0x10
    /* 42D8A0 0052D8A0 B06345DC */  ld         $5, %lo(D_007463B0)($2)
    /* 42D8A4 0052D8A4 0000BFFF */  sd         $31, 0x0($29)
    /* 42D8A8 0052D8A8 7A2F110C */  jal        func_0044bde8
    /* 42D8AC 0052D8AC 00000000 */   nop
    /* 42D8B0 0052D8B0 0000BFDF */  ld         $31, 0x0($29)
    /* 42D8B4 0052D8B4 0800E003 */  jr         $31
    /* 42D8B8 0052D8B8 1000BD27 */   addiu     $29, $29, 0x10
    /* 42D8BC 0052D8BC 00000000 */  nop
.size func_0052d898, 0x28
