.section .text
.set noat
.set noreorder
glabel func_004cfab8
    /* 3CFAB8 004CFAB8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CFABC 004CFABC 07000524 */  addiu      $5, $0, 0x7
    /* 3CFAC0 004CFAC0 0000B0FF */  sd         $16, 0x0($29)
    /* 3CFAC4 004CFAC4 2D808000 */  daddu      $16, $4, $0
    /* 3CFAC8 004CFAC8 0800BFFF */  sd         $31, 0x8($29)
    /* 3CFACC 004CFACC 0100A050 */  beql       $5, $0, .L004CFAD4
    /* 3CFAD0 004CFAD0 CD010000 */   break     0, 7
  .L004CFAD4:
    /* 3CFAD4 004CFAD4 7200043C */  lui        $4, %hi(D_00721D7C)
    /* 3CFAD8 004CFAD8 01000824 */  addiu      $8, $0, 0x1
    /* 3CFADC 004CFADC 7800078E */  lw         $7, 0x78($16)
    /* 3CFAE0 004CFAE0 7C1D838C */  lw         $3, %lo(D_00721D7C)($4)
    /* 3CFAE4 004CFAE4 FFFFE224 */  addiu      $2, $7, -0x1
    /* 3CFAE8 004CFAE8 2D20E000 */  daddu      $4, $7, $0
    /* 3CFAEC 004CFAEC 1A004500 */  div        $0, $2, $5
    /* 3CFAF0 004CFAF0 12100000 */  mflo       $2
    /* 3CFAF4 004CFAF4 01004224 */  addiu      $2, $2, 0x1
    /* 3CFAF8 004CFAF8 2A284300 */  slt        $5, $2, $3
    /* 3CFAFC 004CFAFC 0B184500 */  movn       $3, $2, $5
    /* 3CFB00 004CFB00 01006628 */  slti       $6, $3, 0x1
    /* 3CFB04 004CFB04 0B180601 */  movn       $3, $8, $6
    /* 3CFB08 004CFB08 0500E014 */  bnez       $7, .L004CFB20
    /* 3CFB0C 004CFB0C 7C0003A6 */   sh        $3, 0x7C($16)
    /* 3CFB10 004CFB10 7600013C */  lui        $1, %hi(D_00758AC8)
    /* 3CFB14 004CFB14 08000010 */  b          .L004CFB38
    /* 3CFB18 004CFB18 C88A22DC */   ld        $2, %lo(D_00758AC8)($1)
    /* 3CFB1C 004CFB1C 00000000 */  nop
  .L004CFB20:
    /* 3CFB20 004CFB20 9639110C */  jal        func_0044e658
    /* 3CFB24 004CFB24 00000000 */   nop
    /* 3CFB28 004CFB28 7600013C */  lui        $1, %hi(D_00758AD0)
    /* 3CFB2C 004CFB2C D08A24DC */  ld         $4, %lo(D_00758AD0)($1)
    /* 3CFB30 004CFB30 EE38110C */  jal        func_0044e3b8
    /* 3CFB34 004CFB34 2D284000 */   daddu     $5, $2, $0
  .L004CFB38:
    /* 3CFB38 004CFB38 800002FE */  sd         $2, 0x80($16)
    /* 3CFB3C 004CFB3C 0000B0DF */  ld         $16, 0x0($29)
    /* 3CFB40 004CFB40 0800BFDF */  ld         $31, 0x8($29)
    /* 3CFB44 004CFB44 0800E003 */  jr         $31
    /* 3CFB48 004CFB48 1000BD27 */   addiu     $29, $29, 0x10
    /* 3CFB4C 004CFB4C 00000000 */  nop
.size func_004cfab8, 0x98
