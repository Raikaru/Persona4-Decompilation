.section .text
.set noat
.set noreorder
glabel func_004c3dd8
    /* 3C3DD8 004C3DD8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3C3DDC 004C3DDC 0000B0FF */  sd         $16, 0x0($29)
    /* 3C3DE0 004C3DE0 0800BFFF */  sd         $31, 0x8($29)
    /* 3C3DE4 004C3DE4 520A110C */  jal        func_00442948
    /* 3C3DE8 004C3DE8 2D808000 */   daddu     $16, $4, $0
    /* 3C3DEC 004C3DEC 0800BFDF */  ld         $31, 0x8($29)
    /* 3C3DF0 004C3DF0 2D200002 */  daddu      $4, $16, $0
    /* 3C3DF4 004C3DF4 7100063C */  lui        $6, %hi(D_00714C34)
    /* 3C3DF8 004C3DF8 7100073C */  lui        $7, %hi(D_00714C36)
    /* 3C3DFC 004C3DFC 7100083C */  lui        $8, %hi(D_00714C38)
    /* 3C3E00 004C3E00 0000B0DF */  ld         $16, 0x0($29)
    /* 3C3E04 004C3E04 2D284000 */  daddu      $5, $2, $0
    /* 3C3E08 004C3E08 344CC624 */  addiu      $6, $6, %lo(D_00714C34)
    /* 3C3E0C 004C3E0C 364CE724 */  addiu      $7, $7, %lo(D_00714C36)
    /* 3C3E10 004C3E10 384C0825 */  addiu      $8, $8, %lo(D_00714C38)
    /* 3C3E14 004C3E14 6E0C1308 */  j          func_004c31b8
    /* 3C3E18 004C3E18 1000BD27 */   addiu     $29, $29, 0x10
    /* 3C3E1C 004C3E1C 00000000 */  nop
.size func_004c3dd8, 0x48
