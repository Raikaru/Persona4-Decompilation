.section .text
.set noat
.set noreorder
glabel func_004cd2c8
    /* 3CD2C8 004CD2C8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CD2CC 004CD2CC 7200023C */  lui        $2, %hi(D_007212D0)
    /* 3CD2D0 004CD2D0 0000B0FF */  sd         $16, 0x0($29)
    /* 3CD2D4 004CD2D4 2D808000 */  daddu      $16, $4, $0
    /* 3CD2D8 004CD2D8 0800BFFF */  sd         $31, 0x8($29)
    /* 3CD2DC 004CD2DC ACA3130C */  jal        func_004e8eb0
    /* 3CD2E0 004CD2E0 D01250AC */   sw        $16, %lo(D_007212D0)($2)
    /* 3CD2E4 004CD2E4 0800BFDF */  ld         $31, 0x8($29)
    /* 3CD2E8 004CD2E8 2D200002 */  daddu      $4, $16, $0
    /* 3CD2EC 004CD2EC 0000B0DF */  ld         $16, 0x0($29)
    /* 3CD2F0 004CD2F0 10991308 */  j          func_004e6440
    /* 3CD2F4 004CD2F4 1000BD27 */   addiu     $29, $29, 0x10
.size func_004cd2c8, 0x30
