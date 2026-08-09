.section .text
.set noat
.set noreorder
glabel func_00509dd8
    /* 409DD8 00509DD8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 409DDC 00509DDC 0000B0FF */  sd         $16, 0x0($29)
    /* 409DE0 00509DE0 0800BFFF */  sd         $31, 0x8($29)
    /* 409DE4 00509DE4 F42C140C */  jal        func_0050b3d0
    /* 409DE8 00509DE8 2D808000 */   daddu     $16, $4, $0
    /* 409DEC 00509DEC 3000448C */  lw         $4, 0x30($2)
    /* 409DF0 00509DF0 2800428C */  lw         $2, 0x28($2)
    /* 409DF4 00509DF4 09F84000 */  jalr       $2
    /* 409DF8 00509DF8 2D280002 */   daddu     $5, $16, $0
    /* 409DFC 00509DFC 0000B0DF */  ld         $16, 0x0($29)
    /* 409E00 00509E00 0800BFDF */  ld         $31, 0x8($29)
    /* 409E04 00509E04 0800E003 */  jr         $31
    /* 409E08 00509E08 1000BD27 */   addiu     $29, $29, 0x10
    /* 409E0C 00509E0C 00000000 */  nop
.size func_00509dd8, 0x38
