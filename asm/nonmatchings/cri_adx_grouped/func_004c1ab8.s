.section .text
.set noat
.set noreorder
glabel func_004c1ab8
    /* 3C1AB8 004C1AB8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3C1ABC 004C1ABC 0000BFFF */  sd         $31, 0x0($29)
    /* 3C1AC0 004C1AC0 C000828C */  lw         $2, 0xC0($4)
    /* 3C1AC4 004C1AC4 05004010 */  beqz       $2, .L004C1ADC
    /* 3C1AC8 004C1AC8 2D204000 */   daddu     $4, $2, $0
    /* 3C1ACC 004C1ACC 7100023C */  lui        $2, %hi(D_007149FC)
    /* 3C1AD0 004C1AD0 FC49438C */  lw         $3, %lo(D_007149FC)($2)
    /* 3C1AD4 004C1AD4 09F86000 */  jalr       $3
    /* 3C1AD8 004C1AD8 00000000 */   nop
  .L004C1ADC:
    /* 3C1ADC 004C1ADC 0000BFDF */  ld         $31, 0x0($29)
    /* 3C1AE0 004C1AE0 0800E003 */  jr         $31
    /* 3C1AE4 004C1AE4 1000BD27 */   addiu     $29, $29, 0x10
.size func_004c1ab8, 0x30
