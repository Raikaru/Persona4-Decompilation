.section .text
.set noat
.set noreorder
glabel func_004be210
    /* 3BE210 004BE210 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3BE214 004BE214 0000B0FF */  sd         $16, 0x0($29)
    /* 3BE218 004BE218 2D808000 */  daddu      $16, $4, $0
    /* 3BE21C 004BE21C 0800BFFF */  sd         $31, 0x8($29)
    /* 3BE220 004BE220 0400028E */  lw         $2, 0x4($16)
    /* 3BE224 004BE224 04004010 */  beqz       $2, .L004BE238
    /* 3BE228 004BE228 2D204000 */   daddu     $4, $2, $0
    /* 3BE22C 004BE22C 187A130C */  jal        func_004de860
    /* 3BE230 004BE230 00000000 */   nop
    /* 3BE234 004BE234 040000AE */  sw         $0, 0x4($16)
  .L004BE238:
    /* 3BE238 004BE238 0000B0DF */  ld         $16, 0x0($29)
    /* 3BE23C 004BE23C 0800BFDF */  ld         $31, 0x8($29)
    /* 3BE240 004BE240 0800E003 */  jr         $31
    /* 3BE244 004BE244 1000BD27 */   addiu     $29, $29, 0x10
.size func_004be210, 0x38
