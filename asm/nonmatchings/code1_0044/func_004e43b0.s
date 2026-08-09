.section .text
.set noat
.set noreorder
glabel func_004e43b0
    /* 3E43B0 004E43B0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3E43B4 004E43B4 0000B0FF */  sd         $16, 0x0($29)
    /* 3E43B8 004E43B8 0800BFFF */  sd         $31, 0x8($29)
    /* 3E43BC 004E43BC A890130C */  jal        func_004e42a0
    /* 3E43C0 004E43C0 2D808000 */   daddu     $16, $4, $0
    /* 3E43C4 004E43C4 00861000 */  sll        $16, $16, 24
    /* 3E43C8 004E43C8 7300023C */  lui        $2, %hi(D_00731C4C)
    /* 3E43CC 004E43CC 4C1C4224 */  addiu      $2, $2, %lo(D_00731C4C)
    /* 3E43D0 004E43D0 03861000 */  sra        $16, $16, 24
    /* 3E43D4 004E43D4 000050AC */  sw         $16, 0x0($2)
    /* 3E43D8 004E43D8 0800BFDF */  ld         $31, 0x8($29)
    /* 3E43DC 004E43DC 0000B0DF */  ld         $16, 0x0($29)
    /* 3E43E0 004E43E0 0800E003 */  jr         $31
    /* 3E43E4 004E43E4 1000BD27 */   addiu     $29, $29, 0x10
.size func_004e43b0, 0x38
