.section .text
.set noat
.set noreorder
glabel func_004cdc38
    /* 3CDC38 004CDC38 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CDC3C 004CDC3C 0000B0FF */  sd         $16, 0x0($29)
    /* 3CDC40 004CDC40 2D808000 */  daddu      $16, $4, $0
    /* 3CDC44 004CDC44 10000012 */  beqz       $16, .L004CDC88
    /* 3CDC48 004CDC48 0800BFFF */   sd        $31, 0x8($29)
    /* 3CDC4C 004CDC4C 0400028E */  lw         $2, 0x4($16)
    /* 3CDC50 004CDC50 03004010 */  beqz       $2, .L004CDC60
    /* 3CDC54 004CDC54 2D204000 */   daddu     $4, $2, $0
    /* 3CDC58 004CDC58 900D130C */  jal        func_004c3640
    /* 3CDC5C 004CDC5C 040000AE */   sw        $0, 0x4($16)
  .L004CDC60:
    /* 3CDC60 004CDC60 2A15130C */  jal        func_004c54a8
    /* 3CDC64 004CDC64 00000000 */   nop
    /* 3CDC68 004CDC68 2D200002 */  daddu      $4, $16, $0
    /* 3CDC6C 004CDC6C 2D280000 */  daddu      $5, $0, $0
    /* 3CDC70 004CDC70 72FE100C */  jal        func_0043f9c8
    /* 3CDC74 004CDC74 A8000624 */   addiu     $6, $0, 0xA8
    /* 3CDC78 004CDC78 0000B0DF */  ld         $16, 0x0($29)
    /* 3CDC7C 004CDC7C 0800BFDF */  ld         $31, 0x8($29)
    /* 3CDC80 004CDC80 30151308 */  j          func_004c54c0
    /* 3CDC84 004CDC84 1000BD27 */   addiu     $29, $29, 0x10
  .L004CDC88:
    /* 3CDC88 004CDC88 0000B0DF */  ld         $16, 0x0($29)
    /* 3CDC8C 004CDC8C 0800BFDF */  ld         $31, 0x8($29)
    /* 3CDC90 004CDC90 0800E003 */  jr         $31
    /* 3CDC94 004CDC94 1000BD27 */   addiu     $29, $29, 0x10
.size func_004cdc38, 0x60
