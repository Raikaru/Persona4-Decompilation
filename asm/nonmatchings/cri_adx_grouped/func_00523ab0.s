.section .text
.set noat
.set noreorder
glabel func_00523ab0
    /* 423AB0 00523AB0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 423AB4 00523AB4 0000B0FF */  sd         $16, 0x0($29)
    /* 423AB8 00523AB8 2D808000 */  daddu      $16, $4, $0
    /* 423ABC 00523ABC 0800B1FF */  sd         $17, 0x8($29)
    /* 423AC0 00523AC0 1000BFFF */  sd         $31, 0x10($29)
    /* 423AC4 00523AC4 3C5F140C */  jal        func_00517cf0
    /* 423AC8 00523AC8 2D88A000 */   daddu     $17, $5, $0
    /* 423ACC 00523ACC 00FF053C */  lui        $5, (0xFF000139 >> 16)
    /* 423AD0 00523AD0 07004010 */  beqz       $2, .L00523AF0
    /* 423AD4 00523AD4 2D200000 */   daddu     $4, $0, $0
    /* 423AD8 00523AD8 0000B0DF */  ld         $16, 0x0($29)
    /* 423ADC 00523ADC 3901A534 */  ori        $5, $5, (0xFF000139 & 0xFFFF)
    /* 423AE0 00523AE0 0800B1DF */  ld         $17, 0x8($29)
    /* 423AE4 00523AE4 1000BFDF */  ld         $31, 0x10($29)
    /* 423AE8 00523AE8 B45E1408 */  j          func_00517ad0
    /* 423AEC 00523AEC 2000BD27 */   addiu     $29, $29, 0x20
  .L00523AF0:
    /* 423AF0 00523AF0 2D200002 */  daddu      $4, $16, $0
    /* 423AF4 00523AF4 0000B0DF */  ld         $16, 0x0($29)
    /* 423AF8 00523AF8 2D282002 */  daddu      $5, $17, $0
    /* 423AFC 00523AFC 0800B1DF */  ld         $17, 0x8($29)
    /* 423B00 00523B00 1000BFDF */  ld         $31, 0x10($29)
    /* 423B04 00523B04 72521408 */  j          func_005149c8
    /* 423B08 00523B08 2000BD27 */   addiu     $29, $29, 0x20
    /* 423B0C 00523B0C 00000000 */  nop
.size func_00523ab0, 0x60
