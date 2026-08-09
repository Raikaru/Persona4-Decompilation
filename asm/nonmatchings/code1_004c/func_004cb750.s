.section .text
.set noat
.set noreorder
glabel func_004cb750
    /* 3CB750 004CB750 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CB754 004CB754 7200023C */  lui        $2, %hi(D_00719A40)
    /* 3CB758 004CB758 0000BFFF */  sd         $31, 0x0($29)
    /* 3CB75C 004CB75C 7200033C */  lui        $3, %hi(D_007199BC)
    /* 3CB760 004CB760 409A4224 */  addiu      $2, $2, %lo(D_00719A40)
    /* 3CB764 004CB764 BC99658C */  lw         $5, %lo(D_007199BC)($3)
    /* 3CB768 004CB768 0000448C */  lw         $4, 0x0($2)
    /* 3CB76C 004CB76C 0000BFDF */  ld         $31, 0x0($29)
    /* 3CB770 004CB770 902D1308 */  j          func_004cb640
    /* 3CB774 004CB774 1000BD27 */   addiu     $29, $29, 0x10
.size func_004cb750, 0x28
