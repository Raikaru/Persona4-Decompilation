.section .text
.set noat
.set noreorder
glabel func_00524aa8
    /* 424AA8 00524AA8 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 424AAC 00524AAC 0000B0FF */  sd         $16, 0x0($29)
    /* 424AB0 00524AB0 2D808000 */  daddu      $16, $4, $0
    /* 424AB4 00524AB4 0800B1FF */  sd         $17, 0x8($29)
    /* 424AB8 00524AB8 1000BFFF */  sd         $31, 0x10($29)
    /* 424ABC 00524ABC 3C5F140C */  jal        func_00517cf0
    /* 424AC0 00524AC0 2D88A000 */   daddu     $17, $5, $0
    /* 424AC4 00524AC4 00FF053C */  lui        $5, (0xFF00015B >> 16)
    /* 424AC8 00524AC8 07004010 */  beqz       $2, .L00524AE8
    /* 424ACC 00524ACC 2D200000 */   daddu     $4, $0, $0
    /* 424AD0 00524AD0 0000B0DF */  ld         $16, 0x0($29)
    /* 424AD4 00524AD4 5B01A534 */  ori        $5, $5, (0xFF00015B & 0xFFFF)
    /* 424AD8 00524AD8 0800B1DF */  ld         $17, 0x8($29)
    /* 424ADC 00524ADC 1000BFDF */  ld         $31, 0x10($29)
    /* 424AE0 00524AE0 B45E1408 */  j          func_00517ad0
    /* 424AE4 00524AE4 2000BD27 */   addiu     $29, $29, 0x20
  .L00524AE8:
    /* 424AE8 00524AE8 B036038E */  lw         $3, 0x36B0($16)
    /* 424AEC 00524AEC 06006050 */  beql       $3, $0, .L00524B08
    /* 424AF0 00524AF0 0000B0DF */   ld        $16, 0x0($29)
    /* 424AF4 00524AF4 D00D71AC */  sw         $17, 0xDD0($3)
    /* 424AF8 00524AF8 2C93140C */  jal        func_00524cb0
    /* 424AFC 00524AFC 2D200002 */   daddu     $4, $16, $0
    /* 424B00 00524B00 2D100000 */  daddu      $2, $0, $0
    /* 424B04 00524B04 0000B0DF */  ld         $16, 0x0($29)
  .L00524B08:
    /* 424B08 00524B08 0800B1DF */  ld         $17, 0x8($29)
    /* 424B0C 00524B0C 1000BFDF */  ld         $31, 0x10($29)
    /* 424B10 00524B10 0800E003 */  jr         $31
    /* 424B14 00524B14 2000BD27 */   addiu     $29, $29, 0x20
.size func_00524aa8, 0x70
