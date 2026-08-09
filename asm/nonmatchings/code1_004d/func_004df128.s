.section .text
.set noat
.set noreorder
glabel func_004df128
    /* 3DF128 004DF128 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3DF12C 004DF12C 0000B0FF */  sd         $16, 0x0($29)
    /* 3DF130 004DF130 2D808000 */  daddu      $16, $4, $0
    /* 3DF134 004DF134 0800B1FF */  sd         $17, 0x8($29)
    /* 3DF138 004DF138 2D88A000 */  daddu      $17, $5, $0
    /* 3DF13C 004DF13C 1000B2FF */  sd         $18, 0x10($29)
    /* 3DF140 004DF140 2D90C000 */  daddu      $18, $6, $0
    /* 3DF144 004DF144 0A000016 */  bnez       $16, .L004DF170
    /* 3DF148 004DF148 1800BFFF */   sd        $31, 0x18($29)
    /* 3DF14C 004DF14C 7600043C */  lui        $4, %hi(D_00759950)
    /* 3DF150 004DF150 0000B0DF */  ld         $16, 0x0($29)
    /* 3DF154 004DF154 0800B1DF */  ld         $17, 0x8($29)
    /* 3DF158 004DF158 50998424 */  addiu      $4, $4, %lo(D_00759950)
    /* 3DF15C 004DF15C 1000B2DF */  ld         $18, 0x10($29)
    /* 3DF160 004DF160 1800BFDF */  ld         $31, 0x18($29)
    /* 3DF164 004DF164 B0781308 */  j          func_004de2c0
    /* 3DF168 004DF168 2000BD27 */   addiu     $29, $29, 0x20
    /* 3DF16C 004DF16C 00000000 */  nop
  .L004DF170:
    /* 3DF170 004DF170 E080130C */  jal        func_004e0380
    /* 3DF174 004DF174 00000000 */   nop
    /* 3DF178 004DF178 C40111AE */  sw         $17, 0x1C4($16)
    /* 3DF17C 004DF17C 21103202 */  addu       $2, $17, $18
    /* 3DF180 004DF180 0800B1DF */  ld         $17, 0x8($29)
    /* 3DF184 004DF184 C80102AE */  sw         $2, 0x1C8($16)
    /* 3DF188 004DF188 1000B2DF */  ld         $18, 0x10($29)
    /* 3DF18C 004DF18C 0000B0DF */  ld         $16, 0x0($29)
    /* 3DF190 004DF190 1800BFDF */  ld         $31, 0x18($29)
    /* 3DF194 004DF194 E6801308 */  j          func_004e0398
    /* 3DF198 004DF198 2000BD27 */   addiu     $29, $29, 0x20
    /* 3DF19C 004DF19C 00000000 */  nop
.size func_004df128, 0x78
