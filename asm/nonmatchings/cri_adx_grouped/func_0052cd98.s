.section .text
.set noat
.set noreorder
glabel func_0052cd98
    /* 42CD98 0052CD98 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 42CD9C 0052CD9C 7400023C */  lui        $2, %hi(D_007463A8)
    /* 42CDA0 0052CDA0 0000B0FF */  sd         $16, 0x0($29)
    /* 42CDA4 0052CDA4 A8635024 */  addiu      $16, $2, %lo(D_007463A8)
    /* 42CDA8 0052CDA8 0000038E */  lw         $3, 0x0($16)
    /* 42CDAC 0052CDAC 0900601C */  bgtz       $3, .L0052CDD4
    /* 42CDB0 0052CDB0 0800BFFF */   sd        $31, 0x8($29)
    /* 42CDB4 0052CDB4 7AB3140C */  jal        func_0052cde8
    /* 42CDB8 0052CDB8 00000000 */   nop
    /* 42CDBC 0052CDBC 9400033C */  lui        $3, %hi(D_009389B0)
    /* 42CDC0 0052CDC0 0000048E */  lw         $4, 0x0($16)
    /* 42CDC4 0052CDC4 B0896324 */  addiu      $3, $3, %lo(D_009389B0)
    /* 42CDC8 0052CDC8 000062AC */  sw         $2, 0x0($3)
    /* 42CDCC 0052CDCC 01008424 */  addiu      $4, $4, 0x1
    /* 42CDD0 0052CDD0 000004AE */  sw         $4, 0x0($16)
  .L0052CDD4:
    /* 42CDD4 0052CDD4 0000B0DF */  ld         $16, 0x0($29)
    /* 42CDD8 0052CDD8 0800BFDF */  ld         $31, 0x8($29)
    /* 42CDDC 0052CDDC 0800E003 */  jr         $31
    /* 42CDE0 0052CDE0 1000BD27 */   addiu     $29, $29, 0x10
    /* 42CDE4 0052CDE4 00000000 */  nop
.size func_0052cd98, 0x50
