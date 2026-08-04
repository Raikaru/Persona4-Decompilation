.section .text
.set noat
.set noreorder
glabel func_001a2ad0
    /* A2AD0 001A2AD0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* A2AD4 001A2AD4 1000BFFF */  sd         $31, 0x10($29)
    /* A2AD8 001A2AD8 0000B07F */  sq         $16, 0x0($29)
    /* A2ADC 001A2ADC 2D808000 */  daddu      $16, $4, $0
    /* A2AE0 001A2AE0 38000426 */  addiu      $4, $16, 0x38
    /* A2AE4 001A2AE4 ECAC070C */  jal        func_001eb3b0
    /* A2AE8 001A2AE8 00000000 */   nop
    /* A2AEC 001A2AEC ACB3838F */  lw         $3, -0x4C54($28)
    /* A2AF0 001A2AF0 0C00638C */  lw         $3, 0xC($3)
    /* A2AF4 001A2AF4 00106330 */  andi       $3, $3, 0x1000
    /* A2AF8 001A2AF8 0D006010 */  beqz       $3, .L001A2B30
    /* A2AFC 001A2AFC 00000000 */   nop
    /* A2B00 001A2B00 1A000396 */  lhu        $3, 0x1A($16)
    /* A2B04 001A2B04 01006330 */  andi       $3, $3, 0x1
    /* A2B08 001A2B08 09006010 */  beqz       $3, .L001A2B30
    /* A2B0C 001A2B0C 00000000 */   nop
    /* A2B10 001A2B10 3000038E */  lw         $3, 0x30($16)
    /* A2B14 001A2B14 A2006390 */  lbu        $3, 0xA2($3)
    /* A2B18 001A2B18 05006014 */  bnez       $3, .L001A2B30
    /* A2B1C 001A2B1C 00000000 */   nop
    /* A2B20 001A2B20 2D200002 */  daddu      $4, $16, $0
    /* A2B24 001A2B24 09000524 */  addiu      $5, $0, 0x9
    /* A2B28 001A2B28 00C2060C */  jal        func_001b0800
    /* A2B2C 001A2B2C 00000000 */   nop
  .L001A2B30:
    /* A2B30 001A2B30 1000BFDF */  ld         $31, 0x10($29)
    /* A2B34 001A2B34 0000B07B */  lq         $16, 0x0($29)
    /* A2B38 001A2B38 2000BD27 */  addiu      $29, $29, 0x20
    /* A2B3C 001A2B3C 0800E003 */  jr         $31
    /* A2B40 001A2B40 00000000 */   nop
    /* A2B44 001A2B44 00000000 */  nop
    /* A2B48 001A2B48 00000000 */  nop
    /* A2B4C 001A2B4C 00000000 */  nop
.size func_001a2ad0, 0x80
