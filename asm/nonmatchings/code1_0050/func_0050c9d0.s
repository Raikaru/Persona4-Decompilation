.section .text
.set noat
.set noreorder
glabel func_0050c9d0
    /* 40C9D0 0050C9D0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40C9D4 0050C9D4 0000B0FF */  sd         $16, 0x0($29)
    /* 40C9D8 0050C9D8 0800BFFF */  sd         $31, 0x8($29)
    /* 40C9DC 0050C9DC A032140C */  jal        func_0050ca80
    /* 40C9E0 0050C9E0 00000000 */   nop
    /* 40C9E4 0050C9E4 7400033C */  lui        $3, %hi(D_00745880)
    /* 40C9E8 0050C9E8 01000424 */  addiu      $4, $0, 0x1
    /* 40C9EC 0050C9EC 15004414 */  bne        $2, $4, .L0050CA44
    /* 40C9F0 0050C9F0 80587024 */   addiu     $16, $3, %lo(D_00745880)
    /* 40C9F4 0050C9F4 0000028E */  lw         $2, 0x0($16)
    /* 40C9F8 0050C9F8 13004050 */  beql       $2, $0, .L0050CA48
    /* 40C9FC 0050C9FC 0000B0DF */   ld        $16, 0x0($29)
    /* 40CA00 0050CA00 C232140C */  jal        func_0050cb08
    /* 40CA04 0050CA04 00000000 */   nop
    /* 40CA08 0050CA08 9300063C */  lui        $6, %hi(D_0092EB80)
    /* 40CA0C 0050CA0C 80EBC624 */  addiu      $6, $6, %lo(D_0092EB80)
    /* 40CA10 0050CA10 00400524 */  addiu      $5, $0, 0x4000
    /* 40CA14 0050CA14 CA32140C */  jal        func_0050cb28
    /* 40CA18 0050CA18 2D200000 */   daddu     $4, $0, $0
    /* 40CA1C 0050CA1C 4033140C */  jal        func_0050cd00
    /* 40CA20 0050CA20 08000424 */   addiu     $4, $0, 0x8
    /* 40CA24 0050CA24 9300043C */  lui        $4, %hi(D_0092AB80)
    /* 40CA28 0050CA28 80AB8424 */  addiu      $4, $4, %lo(D_0092AB80)
    /* 40CA2C 0050CA2C 00400524 */  addiu      $5, $0, 0x4000
    /* 40CA30 0050CA30 0233140C */  jal        func_0050cc08
    /* 40CA34 0050CA34 2D300000 */   daddu     $6, $0, $0
    /* 40CA38 0050CA38 4033140C */  jal        func_0050cd00
    /* 40CA3C 0050CA3C 09000424 */   addiu     $4, $0, 0x9
    /* 40CA40 0050CA40 000000AE */  sw         $0, 0x0($16)
  .L0050CA44:
    /* 40CA44 0050CA44 0000B0DF */  ld         $16, 0x0($29)
  .L0050CA48:
    /* 40CA48 0050CA48 0800BFDF */  ld         $31, 0x8($29)
    /* 40CA4C 0050CA4C 0800E003 */  jr         $31
    /* 40CA50 0050CA50 1000BD27 */   addiu     $29, $29, 0x10
    /* 40CA54 0050CA54 00000000 */  nop
.size func_0050c9d0, 0x88
